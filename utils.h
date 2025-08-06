#ifndef UTILS_H
#define UTILS_H

#pragma once
#include <string>
#include <vector>
#include "xlsxdocument.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxworkbook.h"

struct FileInfo {
    QXlsx::Document* document;
    std::vector<int> targetRows;
    int apiCol;
    bool usesHeaders;
};

QXlsx::Document* checkAPIandWrite(FileInfo& srcFile, FileInfo& refFile);
std::vector<int> getTargetCountyRows(QXlsx::Document&, const std::vector<std::string>);

#endif // UTILS_H
