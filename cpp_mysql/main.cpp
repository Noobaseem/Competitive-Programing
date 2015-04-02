/* 
 * File:   main.cpp
 * Author: aseem
 *
 * Created on 2 April, 2015, 11:21 AM
 */

/* Standard C++ headers */
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

/* MySQL Connector/C++ specific headers */
#include "usr/include/cppconn/connection.h"
#include "usr/include/cppconn/statement.h"
#include "usr/include/cppconn/driver.h"
#include "usr/include/cppconn/prepared_statement.h"
#include "usr/include/cppconn/resultset.h"
#include "usr/include/cppconn/metadata.h"
#include "usr/include/cppconn/resultset_metadata.h"
#include "usr/include/cppconn/exception.h"
#include "usr/include/cppconn/warning.h"


#define SERVER "127.0.0.1"
#define USER "root"
#define PASSWORD "root"
#define DATABASE "pro_man_sys"

using namespace std;

int main(){
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        /* Connect to the MySQL test database */
        con->setSchema("pro_man_sys");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM projects");
        while (res->next()) {
          cout << "\t... MySQL replies: ";
          /* Access column data by alias or column name */
          cout << res->getString("project_title") << endl;
          string myTitle =  res->getString("project_title");
          cout<<myTitle<<endl;
          cout << "\t... MySQL says it again: ";
          /* Access column data by numeric offset, 1 is the first column */
          cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;
	return 0;
}

