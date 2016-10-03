#ifndef DATABASE_ENGINE_H
#define DATABASE_ENGINE_H

#include <vector>
#include <memory>
#include <fstream>

class DatabaseEngine {
    std::unique_ptr<std::ofstream> unsafeWriter;
public:
    static void createIfNotExists(const std::string&, const std::vector<std::pair<std::string, std::string>>&);
    static void insert(const std::string&, const std::string& row);	

    std::vector<std::string> selectAll(const std::string& tableFile) const;

    std::vector<std::string> selectWhere(
        const std::string& tableFile, const std::string& column, const std::string& value
    ) const;

    void insertUnsafe(const std::string&, const std::string& row);
    void closeUnsafe();

    virtual ~DatabaseEngine() {}
};

#endif
