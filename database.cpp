/*
 * ===================================================================
 *
 *       Filename:  database.cc
 *
 *    Description:  Definition of MySQL Class for accessing database
 *
 *        Created:  Friday 22 February 2013 02:07:49  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include mysql.h file local header file(declaration of class)
 *------------------------------------------------------------------*/
#include <iostream>
#include "database.h"

using namespace std;
/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: MySQL()
 * Description:  Constructor to initialize database conectivity
 *--------------------------------------------------------------------
 */

MySQL :: MySQL()
{
    connect = mysql_init(NULL);
    if ( !connect )
    {
        cout << "MySQL Initialization Failed";
    }   

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);
    
    if ( connect )
    {
        cout << "Connection Succeeded\n";
    }
    
    else
    {
        cout << "Connection Failed\n";
    }
}

/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: ShowTables()
 * Description:  Show tables in database
 *--------------------------------------------------------------------
 */
void MySQL :: ShowTables(const char* query)
{
    /** Add MySQL Query */
    mysql_query (connect,query);                              
                                                                          
    int j = 0;
                                                                         
    res_set = mysql_store_result(connect);                              
                                                                          
    unsigned int numrows = mysql_num_rows(res_set);                   
    unsigned int numcols = mysql_num_fields(res_set);                                                                  
    cout << "Resualt:" << endl;
    for (int i = 0; i < numcols; i++) {
        cout << "\t";
        if (i + 1 == numcols)
            cout << res_set->fields[i].name;
        else {
            cout << res_set->fields[i].name << " | ";
        }
    }
    cout<<endl;
    while (((row = mysql_fetch_row(res_set)) != NULL))
    {
        for (int i = 0; i < numcols; i++) {
            cout << "\t";
            if (i + 1 == numcols) {
                if (row[i] != NULL)
                    cout << row[i];
                else cout << "NULL";
            }
            else {
                if (row[i] != NULL)
                    cout << row[i] << " | ";
                else cout << "NULL" << "|";
            }
        }
        cout << endl;
    }
    system("pause");
}

/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: ~MySQL()
 * Description:  Destructor of MySQL class for closing mysql
 *               connection
 *--------------------------------------------------------------------
 */

MySQL :: ~MySQL()
{
    mysql_close (connect);
}
