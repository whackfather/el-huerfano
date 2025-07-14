#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void filterCSVs(const std::string&, const std::string&);
void deleteExcessCounties(std::vector<std::vector<std::string>>&, const std::vector<std::string>);
void deleteRows(std::vector<std::vector<std::string>>&, const std::vector<int>);
std::vector<std::vector<std::string>> readData(std::string);
void writeCSV(const std::vector<std::vector<std::string>>&, const std::string&);

#endif // UTILS_H
