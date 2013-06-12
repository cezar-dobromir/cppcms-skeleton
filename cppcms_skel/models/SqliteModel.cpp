/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Models
 *
 */

#include <fstream>

#include <booster/log.h>

#include "SqliteModel.h"
#include "cppcms_skel/generics/Config.h"


namespace cppcmsskel {
namespace models {

/**
 *
 */
SqliteModel::SqliteModel() {
    create_session(
        Config::get_instance()->sqlite3Path
    );
}


/**
 *
 */
SqliteModel::SqliteModel(cppdb::session sqliteDbParam) : sqliteDb(sqliteDbParam) {

}

/**
 *
 */
SqliteModel::SqliteModel(const std::string &databasePath) {
    create_session(databasePath);
}

/**
 *
 */
void SqliteModel::create_session(
    const std::string &databasePath
) {
    try {

        sqliteDb = cppdb::session(
            "sqlite3:db=" + databasePath
        );
        // We need this to have triggers call even in some tricky case 
        // (for example "update or replace" that cause a deletion, will not call
        // the delete trigger otherwise)
        sqliteDb.create_statement("PRAGMA recursive_triggers = 1 ;").exec();
    } catch (cppdb::cppdb_error const &e) {

        BOOSTER_ERROR("cppcms") << e.what();
    }

}

/**
 *
 */
bool SqliteModel::import_sql_file(
    const std::string &sqlFilePath
) {

    try {
        std::ifstream f(sqlFilePath.c_str());
        std::string fileStr(
            (std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>()
        );
        size_t current = 0;
        size_t next = fileStr.find_first_of( ";", current );
        
        // TODO we will ignore what's after the last ;  ,  or everything
        // if there's no  ;  that's a workaround because for the moment 
        // create_statement ... << exec will launch a "no error" exception
        // if you give it a string
        // 
        while (next != std::string::npos) {
            // we split the string 
            std::string tmpRequest =  fileStr.substr(
                current,
                next - current
            );

            sqliteDb.create_statement(tmpRequest)  << cppdb::exec; 

            // we set the cursor just after the last found ;
            current = next + 1;
            // and we look for the position of the next ;
            next = fileStr.find_first_of( ";", current );
        } 


    } catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
        BOOSTER_ERROR("cppcms") << e.what();
        return false;
    }
    return true;
}

/**
 *
 */
bool SqliteModel::execute_simple(
    cppdb::statement &statement
) {
    try {
        statement.exec();
    } catch (cppdb::cppdb_error const& e) {
        BOOSTER_ERROR("cppcms") << e.what();
        statement.reset();
        return false;
    }
    statement.reset();
    return true;
}


/**
 *
 */
bool SqliteModel::check_existence(
    cppdb::statement &statement
) {
    cppdb::result res = statement.row();
    int checkresult = 0;
    res.fetch(0,checkresult);

    // Don't forget to reset statement
    statement.reset();

    if (checkresult == 1 ) {
        return true;
    }
    return false;
}

} // end of namespace models
} // end namespace cppcmsskel
