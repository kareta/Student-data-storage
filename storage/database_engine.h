#ifndef DATABASE_ENGINE_H
#define DATABASE_ENGINE_H

#include <vector>
#include <memory>
#include <fstream>

namespace storage 
{

    class DatabaseEngine 
    {
        std::unique_ptr<std::ofstream> unsafeWriter;
    public:
        void createIfNotExists(
            const std::string& tableName, 
            const std::vector<std::pair<std::string, std::string>>& columns
        ) const;
        void insert(const std::string& tableName, const std::string& row) const;

        std::vector< std::string> selectAll(const std::string& tableFile) const;

        std::vector<std::string> selectWhere(
            const std::string& tableFile, const std::string& column, const std::string& value
        ) const;

        void insertUnsafe(const std::string& tableName, const std::string& row);
        void closeUnsafe();

    };

}


#endif
