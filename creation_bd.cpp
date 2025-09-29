#include "creation_bd.h"

int create_stats_lguhc() {
    sqlite3* db;
    char* errMsg = nullptr;

    // Créer la base de données
    int rc = sqlite3_open("stats_lguhc.db", &db);
    if (rc) {
        std::cerr << "Impossible d'ouvrir/creer la base: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }
    std::cout << "Base de données ouverte/créée avec succès !" << std::endl;

    // Activation des clés étrangères
    rc = sqlite3_exec(db, "PRAGMA foreign_keys = ON;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur activation FOREIGN KEY: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // 3. Création table
    const char* sqlCreate =
        // Table gameplay
        "CREATE TABLE IF NOT EXISTS gameplay ("
        " id_gameplay INTEGER PRIMARY KEY AUTOINCREMENT, "
        " name_gameplay TEXT NOT NULL"
        ");"

        // Table role_camp
        "CREATE TABLE IF NOT EXISTS role_camp ("
        " id_camp INTEGER PRIMARY KEY AUTOINCREMENT, "
        " name_camp TEXT NOT NULL"
        ");"

        // Table role
        "CREATE TABLE IF NOT EXISTS role ("
        " id_role INTEGER PRIMARY KEY AUTOINCREMENT, "
        " name_role TEXT NOT NULL, "
        " id_gameplay INTEGER NOT NULL, "
        " id_camp INTEGER NOT NULL, "
        " FOREIGN KEY (id_gameplay) REFERENCES gameplay(id_gameplay) ON DELETE CASCADE ON UPDATE CASCADE, "
        " FOREIGN KEY (id_camp) REFERENCES role_camp(id_camp) ON DELETE CASCADE ON UPDATE CASCADE"
        ");"
        
        // Table game
        "CREATE TABLE IF NOT EXISTS game ("
        " id_game INTEGER PRIMARY KEY AUTOINCREMENT, "
        " id_role INTEGER NOT NULL, "
        " winning_camp INTEGER NOT NULL, "
        " start_game TEXT, "
        " event_ingame TEXT, "
        " comment TEXT, "
        " FOREIGN KEY (id_role) REFERENCES role(id_role) ON DELETE CASCADE ON UPDATE CASCADE, "
        " FOREIGN KEY (winning_camp) REFERENCES role_camp(id_camp) ON DELETE CASCADE ON UPDATE CASCADE"
        ");";

    rc = sqlite3_exec(db, sqlCreate, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur création tables: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else {
        std::cout << "Tables créées ou déjà existantes." << std::endl;
    }

}