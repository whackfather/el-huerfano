#ifndef UTILS_H
#define UTILS_H

#pragma once
#include <string>
#include <vector>
#include "xlsxdocument.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxworkbook.h"

QXlsx::Document* checkAPIandWrite(QXlsx::Document&, QXlsx::Document&, std::vector<int>, std::vector<int>);
std::vector<int> getTargetCountyRows(QXlsx::Document&, const std::vector<std::string>);

#endif // UTILS_H
