/**
 *  @file    sqlite.h
 *
 *  @author  Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright MIT License
 *
 *  @brief simple class for easier handling of sqlite-database
 *
 *  @detail This class provides only three abilities: open and close sqlite databases and
 *          execute sql-commands. The results of the database request are converted into
 *          table-itmes of libKitsunemimiCommon.
 *
 *          This class was created with the help of:
 *              https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 */

#ifndef SQLITE_H
#define SQLITE_H

#include <iostream>
#include <utility>
#include <vector>
#include <sqlite3.h>
#include <libKitsunemimiCommon/logger.h>

namespace Kitsunemimi
{
class TableItem;
namespace Sqlite
{

class Sqlite
{
public:
    Sqlite();
    ~Sqlite();

    bool initDB(const std::string &path,
                ErrorContainer &error);

    bool execSqlCommand(TableItem* resultTable,
                        const std::string &command,
                        ErrorContainer &error);

    bool closeDB();

private:
    sqlite3* m_db = nullptr;
    int m_rc = 0;
};

} // namespace Sqlite
} // namespace Kitsunemimi

#endif // SQLITE_H
