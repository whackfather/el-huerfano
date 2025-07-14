#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "utils.h"

//--------------------------------------------------------------------------------------//
void filterCSVs(const std::string& oldListFilepath, const std::string& newListFilepath) {
    std::vector<std::vector<std::string>> table1 = readData(oldListFilepath);
    std::vector<std::vector<std::string>> table2 = readData(newListFilepath);

    const int tbl1APIcol = 1;
    const int tbl2APIcol = 1;
    std::vector<int> tbl1RowsToRemove;
    std::vector<int> tbl2RowsToRemove;
    const std::vector<std::string> targetCounties = {
        "BEE",
        "BROOKS",
        "DE WITT",
        "DUVAL",
        "FORT BEND",
        "GOLIAD",
        "HIDALGO",
        "JACKSON",
        "JIM HOGG",
        "JIM WELLS",
        "KARNES",
        "LIVE OAK",
        "MCMULLEN",
        "STARR",
        "VICTORIA",
        "WEBB",
        "WHARTON",
        "ZAPATA"
    };

    // Rewrite these functions to work with qxlsx
    deleteExcessCounties(table1, targetCounties);
    deleteExcessCounties(table2, targetCounties);

    // Identify rows with duplicate APIs
    for (unsigned int row1 = 1; row1 < table1.size(); row1++) {
        std::string apiCur1 = table1[row1][tbl1APIcol];

        for (unsigned int row2 = 1; row2 < table2.size(); row2++) {
            std::string apiCur2 = table2[row2][tbl2APIcol];

            if (apiCur1 == apiCur2) {
                tbl1RowsToRemove.push_back(row1);
                tbl2RowsToRemove.push_back(row2);
            }
        }
    }

    deleteRows(table1, tbl1RowsToRemove);
    deleteRows(table2, tbl2RowsToRemove);

    writeCSV(table1, oldListFilepath);
    writeCSV(table2, newListFilepath);
}

//--------------------------------------------------------------------------------------//
void deleteExcessCounties(std::vector<std::vector<std::string>>& table, const std::vector<std::string> counties) {
    std::vector<int> countyDelList;

    for (unsigned int row = 1; row < table.size(); row++) {
        int countyCol = table[row].size() - 4;
        std::string countyCur = table[row][countyCol];

        if (std::find(counties.begin(), counties.end(), countyCur) == counties.end()) {
            countyDelList.push_back(row);
        }
    }

    deleteRows(table, countyDelList);
}

//--------------------------------------------------------------------------------------//
void deleteRows(std::vector<std::vector<std::string>>& table, const std::vector<int> rowsToRemove) {
    int bound = table.size() - 1;

    for (int row = bound; row >= 1; row--) {
        if (std::find(rowsToRemove.begin(), rowsToRemove.end(), row) != rowsToRemove.end()) {
            table.erase(table.begin() + row);
        }
    }
}

//--------------------------------------------------------------------------------------//
std::vector<std::vector<std::string>> readData(std::string filePath) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filePath);
    std::string line;

    while (getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

        if (!line.empty() && line.back() == ',') {
            row.push_back("");
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

//--------------------------------------------------------------------------------------//
void writeCSV(const std::vector<std::vector<std::string>>& data, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];

            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
}
