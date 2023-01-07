# libKitsunemimiSqlite

![Github workfloat status](https://img.shields.io/github/actions/workflow/status/kitsudaiki/libKitsunemimiSqlite/build_test.yml?branch=develop&style=flat-square&label=build%20and%20test)
![GitHub tag (latest SemVer)](https://img.shields.io/github/v/tag/kitsudaiki/libKitsunemimiSqlite?label=version&style=flat-square)
![GitHub](https://img.shields.io/github/license/kitsudaiki/libKitsunemimiSqlite?style=flat-square)
![C++Version](https://img.shields.io/badge/c%2B%2B-17-blue?style=flat-square)
![Platform](https://img.shields.io/badge/platform-Linux--x64-lightgrey?style=flat-square)

## Description

Simple wrapper for Sqlite3-database. Primary for easier handling the output of SELECT-queries.

## Build

### Requirements

name | repository | version | task
--- | --- | --- | ---
g++ | g++ | >= 8.0 | Compiler for the C++ code.
make | make | >= 4.0 | process the make-file, which is created by qmake to build the programm with g++
qmake | qt5-qmake | >= 5.0 | This package provides the tool qmake, which is similar to cmake and create the make-file for compilation.
sqlite3 library | libsqlite3-dev | >= 3.0 | handling of sqlite databases

Installation on Ubuntu/Debian:

```bash
sudo apt-get install g++ make qt5-qmake libsqlite3-dev
```

IMPORTANT: All my projects are only tested on Linux.

### Kitsunemimi-repositories

Repository-Name | Version-Tag | Download-Path
--- | --- | ---
libKitsunemimiCommon | develop |  https://github.com/kitsudaiki/libKitsunemimiCommon.git
libKitsunemimiJson| delelop |  https://github.com/kitsudaiki/libKitsunemimiJson.git

HINT: These Kitsunemimi-Libraries will be downloaded and build automatically with the build-script below.

### build library

In all of my repositories you will find a `build.sh`. You only have to run this script. It doesn't required sudo, because you have to install required tool via apt, for example, by yourself. But if other projects from me are required, it download them from github and build them in the correct version too. This script is also use by the ci-pipeline, so its tested with every commit.


Run the following commands:

```
git clone https://github.com/kitsudaiki/libKitsunemimiSqlite.git
cd libKitsunemimiSqlite
./build.sh
cd ../result
```

It create automatic a `build` and `result` directory in the directory, where you have cloned the project. At first it build all into the `build`-directory and after all build-steps are finished, it copy the include directory from the cloned repository and the build library into the `result`-directory. So you have all in one single place.

Tested on Debian and Ubuntu. If you use Centos, Arch, etc and the build-script fails on your machine, then please write me a mail and I will try to fix the script.

## Usage by example

```cpp
#include <libKitsunemimiSqlite/sqlite.h>
#include <libKitsunemimiCommon/items/table_item.h>


Kitsunemimi::Sqlite::Sqlite testDB;
Kitsunemimi::ErrorContainer error;
bool ret = false;
std::string query = "";

ret = testDB.initDB("/tmp/testdb.db", error);
// if ret is false, then the error-message can be printed with:
//     std::cout<<error.toString()<<std::endl;
// this is also the case of the other cases in this example here


// CREATE-TABLE-query

query = "CREATE TABLE COMPANY("
        "ID INT PRIMARY KEY     NOT NULL,"
        "NAME           TEXT    NOT NULL,"
        "AGE            INT     NOT NULL,"
        "ADDRESS        CHAR(50),"
        "SALARY         REAL );";

ret = testDB.execSqlCommand(nullptr, query, error);

// INSERT-query

query = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
        "VALUES (1, 'Paul', 32, '{country: \"California\"}', 20000.00 ); "
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
        "VALUES (2, 'Allen', 25, '{country: \"Texas\"}', 15000.00 ); "
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
        "VALUES (3, 'Teddy', 23, '{country: \"Norway\"}', 20000.00 );"
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
        "VALUES (4, 'Mark', 25, '{country: \"Rich-Mond\"}', 65000.00 );";

ret = testDB.execSqlCommand(nullptr, query, error);

// SELECT-query

query = "SELECT * from COMPANY";

Kitsunemimi::TableItem resultItem;
ret = testDB.execSqlCommand(&resultItem, sql, error);
// for the SELECT-qurey a TableItem has to be given as reference. The result of the query will be written into this object

// the table-item can be printed for example like this
std::cout<<resultItem.toString()<<std::endl;
/*
The output then would look like this:

"+----+-------+-----+--------------------------+--------------+\n"
"| ID | NAME  | AGE | ADDRESS                  | SALARY       |\n"
"+====+=======+=====+==========================+==============+\n"
"| 1  | Paul  | 32  | {\"country\":\"California\"} | 20000.000000 |\n"
"+----+-------+-----+--------------------------+--------------+\n"
"| 2  | Allen | 25  | {\"country\":\"Texas\"}      | 15000.000000 |\n"
"+----+-------+-----+--------------------------+--------------+\n"
"| 3  | Teddy | 23  | {\"country\":\"Norway\"}     | 20000.000000 |\n"
"+----+-------+-----+--------------------------+--------------+\n"
"| 4  | Mark  | 25  | {\"country\":\"Rich-Mond\"}  | 65000.000000 |\n"
"+----+-------+-----+--------------------------+--------------+\n";
*/


ret = testDB.closeDB();

```

## Contributing

Please give me as many inputs as possible: Bugs, bad code style, bad documentation and so on.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
