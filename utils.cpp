#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "utils.h"

QXlsx::Document* checkAPIandWrite(FileInfo& srcFile, FileInfo& refFile) {
    QXlsx::Document* output = new QXlsx::Document;
    int recordCount = 1;

    if (srcFile.usesHeaders) {
        for (int cell = 1; cell <= srcFile.document->dimension().columnCount(); cell++) {
            output->write(1, cell, srcFile.document->read(1, cell));
        }
    }

    for (unsigned int rowIdxTable1 = 0; rowIdxTable1 < srcFile.targetRows.size(); rowIdxTable1++) {
        bool record = false;
        for (unsigned int rowIdxTable2 = 0; rowIdxTable2 < refFile.targetRows.size(); rowIdxTable2++) {
            QVariant sourceAPI = srcFile.document->read(srcFile.targetRows[rowIdxTable1], srcFile.apiCol);
            QVariant referAPI = refFile.document->read(refFile.targetRows[rowIdxTable2], refFile.apiCol);
            if (sourceAPI == referAPI) {
                break;
            } else if (rowIdxTable2 == refFile.targetRows.size() - 1 && sourceAPI != referAPI) {
                record = true;
                recordCount += 1;
            }
        }

        if (record) {
            for (int cell = 1; cell <= srcFile.document->dimension().columnCount(); cell++) {
                output->write(recordCount, cell, srcFile.document->read(srcFile.targetRows[rowIdxTable1], cell));
            }
        }
    }

    return output;
}

std::vector<int> getTargetCountyRows(QXlsx::Document& list, const std::vector<std::string> targetCounties) {
    std::vector<int> rowsWithTargetCounties = {1};
    int countyCol = 9;

    for (int row = 1; row <= list.dimension().rowCount(); row++) {
        std::string countyCur = list.read(row, countyCol).toString().toStdString();
        if (std::find(targetCounties.begin(), targetCounties.end(), countyCur) != targetCounties.end()) {
            rowsWithTargetCounties.push_back(row);
        }
    }

    return rowsWithTargetCounties;
}
