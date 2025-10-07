#include "traitement_donnees.h"


//fait une requete SQL qui récupère le camp du role selon son role
std::string init_camp_lguhc(int id_role) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    std::string camp_name = "Inconnu";

    // Ouverture de la base
    int rc = sqlite3_open("bd_stats.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Impossible d'ouvrir la base: " << sqlite3_errmsg(db) << std::endl;
        return camp_name;
    }

    const char* sql =
        "SELECT rc.name_camp "
        "FROM role r "
        "JOIN role_camp rc ON r.id_camp = rc.id_camp "
        "WHERE r.id_role = ?;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erreur préparation requête: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return camp_name;
    }

    sqlite3_bind_int(stmt, 1, id_role);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        const unsigned char* text = sqlite3_column_text(stmt, 0);
        if (text) {
            camp_name = reinterpret_cast<const char*>(text);
        }
    }
    else if (rc != SQLITE_DONE) {
        std::cerr << "Erreur lors de la lecture du camp: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return camp_name;
}





//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'à 45min, traitant des events suivants : 
//couple
//protégé
//events selon le role attribué : cupidon, voleur, enfant sauvage, chien-loup, renégat, trublion, voleur
//attribué le camp selon le role sinon
std::array<std::string, 4> init_treatement_lguhc(data_game &result,log_brut &data_brut, std::string &str_actual, bool disconnected)
{
    std::smatch matches;

    //liste des regex nécéssaires pour l'init des camp et roles seulement
    std::array<std::regex, 1> liste_reg{
   std::regex(R"(\[(\d{2}:\d{2}:\d{2})\].*?<span style="color: #555;">• <\/span>.*?<span style="color: #AAA;">Vous êtes <\/span>.*?<span[^>]*>([^<]+)<\/span>)")
    }; //0 = reg_role

    std::cout << "entré traitement de donnée lguhc\n\n";
    while (!data_brut.empty() && !disconnected)
    {
        bool role_pris = false;
        while (std::regex_search(str_actual, matches, liste_reg[0]))
        {
            if (matches.ready())
            {
                std::cout << "role trouvé : " << matches.str(2);
                //trouver un moyen de trouver l'id du role
                init_camp_lguhc(result.get_id_role());
                break;
            }
        }
    }
    return ;
}





//recherche de quelle type de game on fait, LGUHC, CHAINSAWMANUHC, AOTUHC
data_game main_treatement(log_brut &data_brut)
{
    //initialisation des variables
    //init pour le regex
    static std::regex reg_start(R"(\[(\d{2}:\d{2}:\d{2})\].*?Bienvenue dans cette partie de.*?(LG UHC S\d+\.\d+))");//regex pour voir quelle type de game c'est
    std::string str_actual = data_brut.give_line_kill_line();//init de la string de la data_brut
    data_game result;
    bool disconnected = false;
    std::smatch matches;

    while (!data_brut.empty() && !disconnected) {
        while (std::regex_search(str_actual, matches, reg_start))
        {
            if (matches.str(2) == "LG UHC") {
                result.set_start_game(matches.str(1));
                //init_treatement_lguhc(result, data_brut, str_actual, disconnected);
                std::cout << "regex iterator\n";
            }
            str_actual = matches.suffix().str();   //suprime le résultat trouvé pour npasser aux prochain 
        }
        str_actual = data_brut.give_line_kill_line();
    }
    std::cout << "fin de fichier\n";
    return data_game();
}
