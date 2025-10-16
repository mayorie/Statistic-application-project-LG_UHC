#include "creation_bd.h"

int create_bd_stats() {
    sqlite3* db;
    char* errMsg = nullptr;

    // Créer la base de données
    int rc = sqlite3_open("bd_stats.db", &db);
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
    static const char* sqlCreate =
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
        " id_camp INTEGER NOT NULL, "
        " start_game TEXT, "
        " win bool, "
        " FOREIGN KEY (id_role) REFERENCES role(id_role) ON DELETE CASCADE ON UPDATE CASCADE, "
        " FOREIGN KEY (id_camp) REFERENCES role_camp(id_camp) ON DELETE CASCADE ON UPDATE CASCADE"
        ");"

        // Table type_event
        "CREATE TABLE IF NOT EXISTS type_event ("
        " id_type_event INTEGER PRIMARY KEY AUTOINCREMENT, "
        " id_gameplay INTEGER NOT NULL, "
        " description TEXT NOT NULL,"
        " FOREIGN KEY (id_gameplay) REFERENCES gameplay(id_gameplay) ON DELETE CASCADE ON UPDATE CASCADE "
        ");"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //pas fais d'insert

        //Table event
        " CREATE TABLE IF NOT EXISTS event ("
        " id_type_event INTEGER NOT NULL, "
        " id_game INTEGER NOT NULL,"
        " date TEXT,"
        " FOREIGN KEY (id_type_event) REFERENCES type_event(id_type_event) ON DELETE CASCADE ON UPDATE CASCADE, "
        " FOREIGN KEY (id_game) REFERENCES game(id_game) ON DELETE CASCADE ON UPDATE CASCADE "
        ");"

        // insertion : 
        // insert gamemode
        "INSERT INTO gameplay(name_gameplay) VALUES"
        "('LG UHC');"

        // insert role_camp
        "INSERT INTO role_camp(name_camp) VALUES"
        "('Village'),"
        "('Loups-Garous'),"
        "('Seul')," //le protégé est une victoire en solo
        "('Couple'),"
        "('Special');"

        // insert role
        "INSERT INTO role (name_role, id_gameplay, id_camp) VALUES"
        "('Analiste', 1, 1),"
        "('Astronome', 1, 1),"
        "('Aubergiste', 1, 1),"
        "('Bohémienne', 1, 1),"
        "('Chaman', 1, 1),"
        "('Conteuse', 1, 1),"
        "('Détective', 1, 1),"
        "('Druide', 1, 1),"
        "('Espion', 1, 1),"
        "('Fossoyeur', 1, 1),"
        "('Interprète', 1, 1),"
        "('Jumeaux', 1, 1),"
        "('Montreur d ours', 1, 1),"
        "('Oracle', 1, 1),"
        "('Prêtresse', 1, 1),"
        "('Prophétesse', 1, 1),"
        "('Renard', 1, 1),"
        "('Vaudouiste', 1, 1),"
        "('Vieux Sage', 1, 1),"
        "('Voyante', 1, 1),"
        "('Ancien', 1, 1),"
        "('Avocat', 1, 1),"
        "('Bienfaiteur', 1, 1),"
        "('Bouc émissaire', 1, 1),"
        "('Braconnier', 1, 1),"
        "('Chasseur', 1, 1),"
        "('Citoyen', 1, 1),"
        "('Corbeau', 1, 1),"
        "('Ermite', 1, 1),"
        "('Garde', 1, 1),"
        "('Idiot du village', 1, 1),"
        "('Lapin', 1, 1),"
        "('Mire', 1, 1),"
        "('Petite fille', 1, 1),"
        "('Rebouteux', 1, 1),"
        "('Salvateur', 1, 1),"
        "('Serviteur', 1, 1),"
        "('Simple villageois', 1, 1),"
        "('Soeurs', 1, 1),"
        "('Sorcière', 1, 1),"
        "('Loup-garou', 1, 2),"//loups-garous
        "('Grand méchant loup', 1, 2),"
        "('Infect père des loups', 1, 2),"
        "('Loup-garou amnésique', 1, 2),"
        "('Loup-garou craintif', 1, 2),"
        "('Loup-garou déloyal', 1, 2),"
        "('Loup-garou faussaire', 1, 2),"
        "('Loup-garou feutré', 1, 2),"
        "('Loup-garou grimeur', 1, 2),"
        "('Loup-garou hurleur', 1, 2),"
        "('Loup-garou mystique', 1, 2),"
        "('Loup-garou perfide', 1, 2),"
        "('Loup-garou sanguinaire', 1, 2),"
        "('Loup-garou ténébreux', 1, 2),"
        "('Loup-garou vengeur', 1, 2),"
        "('Vilain petit loup', 1, 2),"
        "('Loup-garou blanc', 1, 3),"//solitaire
        "('Ange', 1, 3),"
        "('Assassin', 1, 3),"
        "('Feu follet', 1, 3),"
        "('Imitateur', 1, 3),"
        "('Joueur de flûte', 1, 3),"
        "('Nécromancien', 1, 3),"
        "('Pyromane', 1, 3),"
        "('Rival', 1, 3),"
        "('Ronin', 1, 3),"
        "('Voyou', 1, 3),"
        "('Chien-loup', 1, 4),"//spécial
        "('Cupidon', 1, 4),"
        "('Enfant sauvage', 1, 4),"
        "('Renégat', 1, 4),"
        "('Trublion', 1, 4),"
        "('Voleur', 1, 4);";

    rc = sqlite3_exec(db, sqlCreate, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur création tables: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else {
        std::cout << "Base de données YES." << std::endl;
    }
    return rc;
}




int insert_game(int id_role, int id_camp, std::string start_game, bool win)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("bd_stats.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Impossible d'ouvrir la base: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    const char* sqlInsert =
        "INSERT INTO game (id_role, id_camp, start_game, win) "
        "VALUES (?, ?, ?, ?);";

    rc = sqlite3_prepare_v2(db, sqlInsert, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur préparation requête: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // Bind des paramètres
    sqlite3_bind_int(stmt, 1, id_role);
    sqlite3_bind_int(stmt, 2, id_camp);
    sqlite3_bind_text(stmt, 3, start_game.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, win ? 1 : 0); // bool → int

    // Exécution
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur insertion d'une game: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        std::cout << "Insertion d'une game réussie !" << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return rc;
}

int delete_game(int id_game)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("bd_stats.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Impossible d'ouvrir la base: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    const char* sqlDelete = "DELETE FROM game WHERE id_game = ? ;";

    rc = sqlite3_prepare_v2(db, sqlDelete, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur préparation requête: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // Bind du paramètre (id_game)
    sqlite3_bind_int(stmt, 1, id_game);

    // Exécution
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur suppression de la game: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        std::cout << "Game avec id " << id_game << " supprimée avec succès !" << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return rc;
}


// Sélectionne et affiche toutes les lignes d'une table donnée
int select_all_from_table(const std::string& tableName)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    // Tables autorisées (whitelist)
    std::vector<std::string> allowed = { "game", "role", "role_camp", "gameplay" };

    // Vérification de la table choisie
    bool valid = false;
    for (auto& t : allowed) {
        if (tableName == t)
        {
            valid = true;
            break;
        }
    }
    if (!valid) {
        std::cerr << "Nom de table non autorisé : " << tableName << std::endl;
        return SQLITE_ERROR;
    }

    // Ouverture de la base
    int rc = sqlite3_open("bd_stats.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Impossible d'ouvrir la base: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    // Construction de la requête (attention : pas de bind possible sur un nom de table)
    std::string sql = "SELECT * FROM " + tableName + ";";

    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur préparation requête: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // Affichage des colonnes
    int cols = sqlite3_column_count(stmt);
    std::cout << "----- Contenu de la table " << tableName << " -----\n";
    for (int i = 0; i < cols; i++) {
        std::cout << sqlite3_column_name(stmt, i) << "\t";
    }
    std::cout << "\n--------------------------------------------\n";

    // Lecture ligne par ligne
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        for (int i = 0; i < cols; i++) {
            const unsigned char* text = sqlite3_column_text(stmt, i);
            std::cout << (text ? reinterpret_cast<const char*>(text) : "NULL") << "\t";
        }
        std::cout << "\n";
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur lecture données: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return SQLITE_OK;
}


int delete_all_games()
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("bd_stats.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Impossible d'ouvrir la base: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    const char* sqlDelete = "DELETE FROM game;"
        "DELETE FROM sqlite_sequence WHERE name='game';";

    rc = sqlite3_prepare_v2(db, sqlDelete, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur préparation requête: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur suppression de toutes les games: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        std::cout << "Toutes les games ont été supprimées avec succès !" << std::endl;
    }

    sqlite3_finalize(stmt);

    sqlite3_close(db);
    return rc;
}

int search_id_role_by_name(const std::string& role_name)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int role_id = -1; // valeur par défaut si non trouvé

    // Ouverture de la base
    int rc = sqlite3_open("bd_stats.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Impossible d'ouvrir la base: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }

    const char* sql = "SELECT id_role FROM role WHERE LOWER(name_role) LIKE LOWER(?) LIMIT 1;";

    // Préparation de la requête
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur préparation requête: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return -1;
    }

    // Bind du paramètre : le nom du rôle
    sqlite3_bind_text(stmt, 1, role_name.c_str(), -1, SQLITE_STATIC);

    // Exécution
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        role_id = sqlite3_column_int(stmt, 0);
        std::cout << "SQL : Role '" << role_name << "' trouvé avec ID = " << role_id << std::endl;
    }
    else {
        std::cout << "Aucun rôle trouvé pour le nom '" << role_name << "'." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return role_id;
}


int search_id_camp_by_name(const std::string& camp_name)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int camp_id = -1; // valeur par défaut si non trouvé

    // Ouverture de la base
    int rc = sqlite3_open("bd_stats.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Impossible d'ouvrir la base: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }

    const char* sql = "SELECT id_camp FROM role_camp WHERE LOWER(name_camp) LIKE LOWER(?) LIMIT 1;";

    // Préparation de la requête
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur préparation requête: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return -1;
    }

    // Bind du paramètre : le nom du camp
    sqlite3_bind_text(stmt, 1, camp_name.c_str(), -1, SQLITE_STATIC);

    // Exécution
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        camp_id = sqlite3_column_int(stmt, 0);
        std::cout << "SQL : Camp '" << camp_name << "' trouvé avec ID = " << camp_id << std::endl;
    }
    else {
        std::cout << "Aucun camp trouvé pour le nom '" << camp_name << "'." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return camp_id;
}
