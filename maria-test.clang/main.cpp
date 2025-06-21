#include <iostream>
#include <mysql.h>

int main() {
    MYSQL *connection = mysql_init(NULL);
    
    if (connection == NULL) {
        std::cerr << "mysql_init() failed" << std::endl;
        return 1;
    }
    
    if (mysql_real_connect(connection, "mariadb", "test", "test", "test", 0, NULL, 0) == NULL) {
        std::cerr << "Connection failed: " << mysql_error(connection) << std::endl;
        mysql_close(connection);
        return 1;
    }
    
    if (mysql_query(connection, "SHOW DATABASES")) {
        std::cerr << "Query failed: " << mysql_error(connection) << std::endl;
        mysql_close(connection);
        return 1;
    }
    
    MYSQL_RES *result = mysql_store_result(connection);
    if (result == NULL) {
        std::cerr << "mysql_store_result() failed" << std::endl;
        mysql_close(connection);
        return 1;
    }
    
    MYSQL_ROW row;
    std::cout << "DATABASES:" << std::endl;
    while ((row = mysql_fetch_row(result))) {
        std::cout << "  " << row[0] << std::endl;
    }
    
    mysql_free_result(result);
    mysql_close(connection);
    
    return 0;
}