#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

int main(){
  sqlite3 *db;
  sqlite3_stmt *res;
  char sql[256];
  char username[50], password[50], database[50];
  
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';


    sqlite3_open("users.db", &db);
    sprintf(sql, "SELECT * FROM users WHERE username = '%s' AND password = '%s'", username, password);

     if (sqlite3_prepare_v2(db, sql, -1, &res, 0) == SQLITE_OK) {
        if (sqlite3_step(res) == SQLITE_ROW) {
            printf("✅ Login réussi\n");
        } else {
            printf("❌ Login échoué\n");
        }
    }

    sqlite3_finalize(res);
    sqlite3_close(db);
    return 0;

}