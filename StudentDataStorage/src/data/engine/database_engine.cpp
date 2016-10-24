#include "database_engine.h"

#include <string>
#include <iostream>

namespace data { namespace engine {

    void DatabaseEngine::createIfNotExists(
        const std::string& tableFile, const std::vector<std::pair<std::string, std::string>>& columns
    ) {

        std::ifstream checkedFile(tableFile.c_str());
        auto fileExists = checkedFile.good();

        if (!fileExists) {
            std::ofstream writer(tableFile, std::ios::out);
            std::string columnNames;
            std::string columnTypes;
            for (auto it = columns.begin(); it != columns.end(); ++it)
            {
                columnNames.append(it->first + " ");
                columnTypes.append(it->second + " ");
            }

            writer << columns.size() << "\n" << columnNames.substr(0, columnNames.size() - 1) << "\n" << columnTypes << "\n";
            writer.close();
        }
    }

    void DatabaseEngine::insert(const std::string& tableFile, const std::string& row) {
        std::ofstream writer(tableFile, std::ios::app);
        writer << row << "\n";
        writer.close();
    }

    void DatabaseEngine::insertUnsafe(const std::string& tableFile, const std::string& row) {
        if (!unsafeWriter) {
            unsafeWriter.reset(new std::ofstream(tableFile, std::ios::app));
        }

        *unsafeWriter << row + "\n";
    }

    void DatabaseEngine::closeUnsafe() {
        if (unsafeWriter) {
            unsafeWriter->close();
            unsafeWriter.reset(nullptr);
        }
    }

    std::vector<std::string> DatabaseEngine::selectAll(const std::string& tableFile) const {
        std::ifstream reader(tableFile, std::ios::in);
        std::string currentRow;
        std::vector<std::string> rows;

        //skip number of columns
        getline(reader, currentRow);
        //skip column names
        getline(reader, currentRow);
        //skip column types
        getline(reader, currentRow);

        while (getline(reader, currentRow)) {
            rows.push_back(currentRow);
        }
        reader.close();
        return rows;
    }

    std::vector<std::string> DatabaseEngine::selectWhere(
        const std::string& tableFile, const std::string& column, const std::string& value
    ) const {

        std::ifstream reader(tableFile, std::ios::in);
        std::string currentData;
        std::vector<std::string> columnNames;
        std::vector<std::string> rows;

        getline(reader, currentData);
        auto columnsAmount = stoi(currentData);

        for (auto i = 0; i < columnsAmount; i++) {
            std::string columnName;
            reader >> columnName;
            columnNames.push_back(columnName);
        }
        //skip column types
        getline(reader, currentData);

        while (!reader.eof()) {
            std::streamoff rowStart = reader.tellg();
            for (auto columnIndex = 0; columnIndex < columnsAmount; columnIndex++) {
                reader >> currentData;
                if (columnNames[columnIndex] == column && currentData == value) {
                    reader.seekg(rowStart, reader.beg);
                    std::string row;
                    getline(reader, row);
                    rows.push_back(row);
                }
            }
        }

        reader.close();
        return rows;
    }
    
}}

