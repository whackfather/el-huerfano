#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void filter(std::string&, std::string&);
void deleteExcessCounties(std::vector<std::vector<std::string>>&, std::vector<std::string>);
std::vector<std::vector<std::string>> readData(std::string);
void writeCSV(const std::vector<std::vector<std::string>>&, const std::string&);

#endif // UTILS_H
