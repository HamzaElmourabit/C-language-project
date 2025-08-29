#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("gestion_paie.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS Employes("
                      "Id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Nom TEXT,"
                      "Heures FLOAT,"
                      "Taux FLOAT,"
                      "SalaireNet FLOAT);";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Table Employes prête.\n");
    }

    sqlite3_close(db);
    return 0;
}