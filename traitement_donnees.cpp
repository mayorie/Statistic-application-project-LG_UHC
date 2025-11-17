#include "traitement_donnees.h"

//std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " text" << "\033[37m" << "\n";


data_game event_ingame_LGUHC(data_game& result, log_brut& data_brut, std::string& str_actual, bool disconnected)
{

    // Énumération pour indexer les regex d'init
    static enum regex_ingame_LGUHC {
        REG_VAINQUEUR,
        REG_ZIZANIE,
        REG_INFECTE,
        REG_LOUP_SOLITAIRE,
        REG_VOLEUR,
        REG_ES_MODEL_MORT,//ES = enfant sauvage
        REG_RENEGAT,
        REG_CUPI_COUPLE_MORT,
        REG_CUPI_RANCUNIER,
        REG_VACCINATION,
        REG_INIT_COUNT
    };

    // Liste des regex nécessaires pour l'init des camps et rôles
    static std::array<std::regex, REG_INIT_COUNT> const liste_reg_ingame_LGUHC{
        std::regex(R"(\[LG UHC\]\s+(.*?)\s+remportent la partie !)"),
        std::regex(R"(azertyuiop)"),
        std::regex(R"(poiuytreza)"),
        std::regex(R"(qsdfghjklm)"),
        std::regex(R"(mlkjhgfdsq)"),
        std::regex(R"(wxcvbnazertyuiop)"),
        std::regex(R"(nbvcxwpoiuytreza)"),
        std::regex(R"(azertyuioppoiuytreza)"),
        std::regex(R"(poiuytrezaazertyuiop)"),
        std::regex(R"(qsdfghjklmmlkjhgfdsq)")
    };

    //déclaration des flags : 
    bool flag_joueur_loup = false;
    if (result.get_id_camp() == 2)//ne peut être loup solitaire si il  n'est pas loup
        flag_joueur_loup = true;

    bool flag_voleur = false;
    if (result.get_id_role() == 73)
        flag_voleur = true;

    bool flag_ES = false;
    if (result.get_id_role() == 70)//ES = enfant sauvage
        flag_ES = true;

    bool flag_renegat = false;
    if (result.get_id_role() == 71)
        flag_renegat = true;

    bool flag_cupi_rancunier = false;
    if (result.get_id_role() == 69)//69 = id du role cupidon
        flag_cupi_rancunier = true;

    static std::unordered_map<std::string, int> const camps = {
        {"Les Villageois", 1},
        {"Les Loups-garous", 2},
        {"Un Solitaire", 3},
        {"Les Amoureux", 4}
    };

    std::smatch matches;
    while (!data_brut.empty() && !disconnected)
    {
        if(std::regex_search(str_actual, matches, liste_reg_ingame_LGUHC[REG_VAINQUEUR]))
        {
            const std::string& gagnant = matches.str(1);
            std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : vainqueur : " << gagnant << "\033[37m" << '\n';

            auto it = camps.find(gagnant);
            if (it != camps.end() && result.get_id_camp() == it->second)
            {
                result.set_win(true);
                std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : tu as win." << "\033[37m" << "\n";
            }
            else
            {
                std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : tu es nul, tu as perdu." << "\033[37m" << "\n";
            }

            str_actual = matches.suffix().str();
            return result;

        }
        else if (std::regex_search(str_actual, matches, liste_reg_ingame_LGUHC[REG_ZIZANIE]))
        {
            std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : tu t'es fais zizanié." << "\033[37m" << "\n";
            if (result.get_id_camp() == 1)
                result.set_id_camp(2);
            else if (result.get_id_camp() == 2)
                result.set_id_camp(3);
            else
                result.set_id_camp(1);
        }


        str_actual = data_brut.give_line_kill_line();
    }
    return result;

}


//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'à 45min, traitant des events suivants : 
//couple
//protégé
//events selon le role attribué : cupidon, voleur, enfant sauvage, chien-loup, renégat, trublion, voleur
//attribué le camp selon le role sinon
data_game init_treatement_lguhc(data_game &result,log_brut &data_brut, std::string &str_actual, bool disconnected)
{

    std::smatch matches;

    // Énumération pour indexer les regex d'init
    static enum RegexInitLGUHC {
        REG_ROLE,   // Vous êtes ...
        REG_CAMP,   // Objectif : Vous devez gagner ...
        REG_45MIN,  // PvP activé !
        REG_TRUBLIONNAGE,
        REG_COUPLE,
        REG_PROTEGE,
        REG_INIT_COUNT
    };
    //TO DO : couple, protégé ange, trublionnage

    // Liste des regex nécessaires pour l'init des camps et rôles
    static std::array<std::regex, REG_INIT_COUNT> const liste_reg_init_LGUHC{
        std::regex(R"(Vous êtes\s+([A-Za-zÀ-ÿ\- ]+))"),
        std::regex(R"(Objectif\s*:\s*Vous devez gagner\s+([A-Za-zÀ-ÿ\-]+))"),
        std::regex(R"(\[\d{2}:\d{2}:\d{2}\] \[Client thread\/INFO\]: \[CHAT\] \[UHC\] PvP activé !$)"),
        std::regex(R"(azertyuiopmlkjhgfdsqwxcvbn)"),
        std::regex(R"(azertyuiopmlkjhgfdsqwxcvbn)"),
        std::regex(R"(azertyuiopmlkjhgfdsqwxcvbn)")
    };
    RegexInitLGUHC iterator_regex = REG_ROLE;

    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " entré init_treatement_lguhc" << "\033[37m" << "\n";
    while (!data_brut.empty() && !disconnected)
    {
        if (std::regex_search(str_actual, matches, liste_reg_init_LGUHC[REG_45MIN]))
        {
            return event_ingame_LGUHC(result, data_brut, str_actual, disconnected);
        }
        else if(iterator_regex <= 1 && std::regex_search(str_actual, matches, liste_reg_init_LGUHC[iterator_regex]))
        {
            switch (iterator_regex)
            {
            case REG_ROLE:
            {
                std::string role_name = matches.str(1);
                std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : role trouvé : " << role_name << "\033[37m" << "\n";
                int id_role = search_id_role_by_name(role_name); // utilise ta fonction qui retourne -1 si non trouvé
                if (id_role == -1) {
                    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[31m" << " Traitement LGUHC : Le rôle '" + role_name + "' n'existe pas dans la base !" << "\033[37m" << "\n";
                    break;
                }
                else
                {
                    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : id_role : " << id_role << "\033[37m" << "\n";
                    result.set_id_role(id_role);
                }
                iterator_regex = static_cast<RegexInitLGUHC>(iterator_regex + 1);
                break;
            }
            case REG_CAMP:
            {
                std::string camp_name = matches.str(1);
                std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : camp trouvé : " << camp_name << "\033[37m" << "\n";
                int id_camp = search_id_camp_by_name(camp_name); // utilise ta fonction qui retourne -1 si non trouvé
                if (id_camp == -1) {
                    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[31m" << " Traitement LGUHC : Le camp '" + camp_name + "' n'existe pas dans la base !" << "\033[37m" << "\n";
                }
                else if (result.get_id_camp() != 4)
                {
                    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : Le camp ne change pas car tu es en couple !" << "\033[37m" << "\n";
                }
                else
                {
                    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : id_camp : " << id_camp << "\033[37m" << "\n";
                    if (result.get_id_camp() > 4)
                    {
                        result.set_id_camp(id_camp + 4);
                    }
                    else
                    {
                        result.set_id_camp(id_camp);
                    }
                }
                iterator_regex = static_cast<RegexInitLGUHC>(iterator_regex + 1);
                break;
            }
            default:
                std::cout << "\033[33m" << "[traitement_donnees]" << "\033[31m" << " Traitement LGUHC : erreur, le switch n'est pas bon." << "\033[37m" << "\n";
            }
            str_actual = matches.suffix().str();   //suprime le résultat trouvé pour npasser aux prochain 
        }
        else if (std::regex_search(str_actual, matches, liste_reg_init_LGUHC[REG_TRUBLIONNAGE]))
        {
            RegexInitLGUHC iterator_regex = REG_ROLE;
        }
        else if (std::regex_search(str_actual, matches, liste_reg_init_LGUHC[REG_COUPLE]))
        {
            result.set_id_camp(4);
        }
        else if (std::regex_search(str_actual, matches, liste_reg_init_LGUHC[REG_PROTEGE]))
        {
            if(result.get_id_camp()!=4)
            {
                result.set_id_camp(result.get_id_camp() + 4);
                //1 : villageois, 2 : loup-garous, 3 : solos, 4 : couple, 5 : protégé, villageois, 6 : protégé, loups, 7 : protégé, solo
                //je mets l'id camp à l'id camp de base plus 4 pour skip les quatres premiers cas
            }
        }
        str_actual = data_brut.give_line_kill_line();
    }
    return result;
}





//recherche de quelle type de game on fait, LGUHC, CHAINSAWMANUHC, AOTUHC
data_game main_treatement(log_brut &data_brut)
{
    //initialisation des variables
    //init pour le regex
    int iterator_regex = 0;

    std::array<std::regex, 1> liste_reg_main_traitement{
        std::regex(R"(\[(\d{2}):(\d{2}):(\d{2})\].*\[CHAT\].*\[UHC\].*Bienvenue dans cette partie de (.+?UHC))")
    }; //0 = reg_start
    std::string str_actual = data_brut.give_line_kill_line();//init de la string de la data_brut
    bool disconnected = false;
    std::smatch matches;

    while (!data_brut.empty() && !disconnected) {
        if(std::regex_search(str_actual, matches, liste_reg_main_traitement[iterator_regex]))
        {
            switch (iterator_regex)
            {
            case 0:
                std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement général : Nom de mode de jeu : " << matches.str(4) << "\033[37m" << "\n";
                if (matches.str(4) == "LG UHC") {
                    data_game result;
                    result.set_start_game("h : " + matches.str(1) + " min : " + matches.str(2) + " sec : " + matches.str(3));
                    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Traitement LGUHC : Début de game LG UHC." << "\033[37m" << "\n";
                    init_treatement_lguhc(result, data_brut, str_actual, disconnected);
                    result.merge_into_data_base();
                }
            }
            str_actual = matches.suffix().str();   //suprime le résultat trouvé pour npasser aux prochain 
        }
        str_actual = data_brut.give_line_kill_line();
    }
    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " Fin de fichier" << "\033[37m" << "\n";
    return data_game();
}
