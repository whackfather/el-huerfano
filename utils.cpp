#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "utils.h"

QXlsx::Document* checkAPIandWrite(QXlsx::Document& sourceList, QXlsx::Document& referenceList, std::vector<int> sourceTargetRows, std::vector<int> referenceTargetRows, int apiColSrc, int apiColRef, bool usesHeaders) {
    QXlsx::Document* output = new QXlsx::Document;
    int recordCount = 1;

    if (usesHeaders) {
        for (int cell = 1; cell <= sourceList.dimension().columnCount(); cell++) {
            output->write(1, cell, sourceList.read(1, cell));
        }
    }

    for (unsigned int rowIdxTable1 = 0; rowIdxTable1 < sourceTargetRows.size(); rowIdxTable1++) {
        bool record = false;
        for (unsigned int rowIdxTable2 = 0; rowIdxTable2 < referenceTargetRows.size(); rowIdxTable2++) {
            bool matchingAPIs = sourceList.read(sourceTargetRows[rowIdxTable1], apiColSrc) == referenceList.read(referenceTargetRows[rowIdxTable2], apiColRef);
            if (matchingAPIs) {
                break;
            } else if (rowIdxTable2 == referenceTargetRows.size() - 1 && !matchingAPIs) {
                record = true;
                recordCount += 1;
            }
        }

        if (record) {
            for (int cell = 1; cell <= sourceList.dimension().columnCount(); cell++) {
                output->write(recordCount, cell, sourceList.read(sourceTargetRows[rowIdxTable1], cell));
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
