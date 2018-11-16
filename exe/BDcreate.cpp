#include <iostream>
#include "./sqlite3.h"
  
using namespace std;
 
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char **argv)
{
  sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("projeto.db", &db);
   
   if( rc ) {
      cout << "Can't open database" << endl;
      return(0);
   } else {
      cout << "Opened database successfully" << endl;;
   }

  /* Create SQL statement */
  sql = "CREATE TABLE users("  \
      "identifier VARCHAR(50) PRIMARY KEY," \
      "name           TEXT    NOT NULL," \
      "password        VARCHAR(50));";
	
	
	/* Create SQL statement */
  // sql = "INSERT INTO users(name,identifier,password) "  \
  //        "VALUES ('Otho T. Komatsu', 'ahyef', '123Abc!&'); ";
	
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}
