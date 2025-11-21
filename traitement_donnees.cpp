#include "traitement_donnees.h"

<<<<<<< Updated upstream
data_game event_ingame_LGUHC(data_game& result, log_brut& data_brut, std::string& str_actual, bool disconnected)
{
    static const std::regex reg_vainqueur(R"(\[LG UHC\]\s+(.*?)\s+remportent la partie !)");
    static const std::unordered_map<std::string, int> camps = {
=======
//std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " text" << "\033[37m" << "\n";

/*
data_game event_ingame_LGUHC(data_game& result, log_brut& data_brut, std::string& str_actual, bool disconnected, static std::array<std::regex, REG_INIT_COUNT> liste_reg_LGUHC)
{

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
>>>>>>> Stashed changes
        {"Les Villageois", 1},
        {"Les Loups-garous", 2},
        {"Un Solitaire", 3},
        {"Les Amoureux", 4}
    };

    std::smatch matches;
    std::string remaining = str_actual;

    while (std::regex_search(remaining, matches, reg_vainqueur))
    {
<<<<<<< Updated upstream
        const std::string& gagnant = matches[1];
        std::cout << "Traitement LGUHC : vainqueur : " << gagnant << '\n';

        auto it = camps.find(gagnant);
        if (it != camps.end() && result.get_id_camp() == it->second)
=======
        if(std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_VAINQUEUR]))
>>>>>>> Stashed changes
        {
            result.set_win(true);
            std::cout << "Traitement LGUHC : tu as win.\n";
        }
<<<<<<< Updated upstream
        else
=======
        else if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_ZIZANIE]))
>>>>>>> Stashed changes
        {
            std::cout << "Traitement LGUHC : tu es nul, tu as perdu.\n";
        }
<<<<<<< Updated upstream
=======
        else if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_INFECTE]))
        {
            if(result.get_id_role()!=57 /* && loup solitaire, faut regarder les events*//*) // ni le loup blanc ni le lup solitaire gagne pas avec les loups
            {
                result.set_id_camp(2);
                flag_joueur_loup = true;
            }
        }
            
>>>>>>> Stashed changes

        remaining = matches.suffix().str();
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

<<<<<<< Updated upstream
    // Énumération pour indexer les regex d'init
    enum RegexInitLGUHC {
        REG_ROLE,   // Vous êtes ...
        REG_CAMP,   // Objectif : Vous devez gagner ...
        REG_45MIN,  // PvP activé !
        REG_INIT_COUNT
    };

    // Liste des regex nécessaires pour l'init des camps et rôles
    std::array<std::regex, REG_INIT_COUNT> liste_reg_init_LGUHC{
        std::regex(R"(Vous êtes\s+([A-Za-zÀ-ÿ\- ]+))"),
        std::regex(R"(Objectif\s*:\s*Vous devez gagner\s+([A-Za-zÀ-ÿ\-]+))"),
        std::regex(R"(\[\d{2}:\d{2}:\d{2}\] \[Client thread\/INFO\]: \[CHAT\] \[UHC\] PvP activé !$)")
    };
    RegexInitLGUHC iterator_regex = REG_ROLE;

    std::cout << "\n\n\n\nentré init_treatement_lguhc\n\n";
    while (!data_brut.empty() && !disconnected)
    {
        while (iterator_regex <= 1 && std::regex_search(str_actual, matches, liste_reg_init_LGUHC[iterator_regex]))
=======
    // Liste des regex nécessaires pour l'init des camps et rôles
    static std::array<std::regex, REG_INIT_COUNT> const liste_reg_LGUHC{
        std::regex(R"(Vous êtes\s+([A-Za-zÀ-ÿ\- ]+))"),
        std::regex(R"(Objectif\s*:\s*Vous devez gagner\s+([A-Za-zÀ-ÿ\-]+))"),
        std::regex(R"(\[\d{2}:\d{2}:\d{2}\] \[Client thread\/INFO\]: \[CHAT\] \[UHC\] PvP activé !$)"),
        std::regex(R"(azertyuiopmlkjhgfdsqwxcvbn)"),
        std::regex(R"(azertyuiopmlkjhgfdsqwxcvbn)"),
        std::regex(R"(azertyuiopmlkjhgfdsqwxcvbn)"),
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
    RegexInitLGUHC iterator_regex = REG_ROLE;

    std::vector<int> list_event_if_role_change;
    bool flag_joueur_role_change = false;//à mettre à true si le joueur est trublionné ou il est voleur et qu'il a volé un role.
                                         //Jusqu'à ce qu'il regarde son nouveau role.

    std::cout << "\033[33m" << "[traitement_donnees]" << "\033[32m" << " entré init_treatement_lguhc" << "\033[37m" << "\n";
    while (!data_brut.empty() && !disconnected)
    {
        if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_45MIN]))
        {
            return event_ingame_LGUHC(result, data_brut, str_actual, disconnected, liste_reg_LGUHC);
        }
        else if(iterator_regex <= 1 && std::regex_search(str_actual, matches, liste_reg_LGUHC[iterator_regex]))
>>>>>>> Stashed changes
        {
            switch (iterator_regex)
            {
            case REG_ROLE:
            {
<<<<<<< Updated upstream
                std::string role_name = matches.str(1);
                std::cout << "Traitement LGUHC : role trouvé : " << role_name << "\n";
                int id_role = search_id_role_by_name(role_name); // utilise ta fonction qui retourne -1 si non trouvé
                if (id_role == -1) {
                    std::cout << "Traitement LGUHC : Le rôle '" + role_name + "' n'existe pas dans la base !\n\n\n";
                }
                else
                {
                    std::cout << "Traitement LGUHC : id_role : " << id_role << "\n\n";
                    result.set_id_role(id_role);
                }
=======
                role_LG()
>>>>>>> Stashed changes
                iterator_regex = static_cast<RegexInitLGUHC>(iterator_regex + 1);
                break;
            }
            case REG_CAMP:
            {
                std::string camp_name = matches.str(1);
                std::cout << "Traitement LGUHC : camp trouvé : " << camp_name << "\n";
                int id_camp = search_id_camp_by_name(camp_name); // utilise ta fonction qui retourne -1 si non trouvé
                if (id_camp == -1) {
                    std::cout << "Traitement LGUHC : Le camp '" + camp_name + "' n'existe pas dans la base !\n\n\n";
                }
                else
                {
                    std::cout << "Traitement LGUHC : id_camp : " << id_camp << "\n\n";
                    result.set_id_camp(id_camp);
                }
                iterator_regex = static_cast<RegexInitLGUHC>(iterator_regex + 1);
                break;
            }
            default:
                std::cout << "Traitement LGUHC : erreur, le switch n'est pas bon.";
            }
            str_actual = matches.suffix().str();   //suprime le résultat trouvé pour npasser aux prochain 
        }
<<<<<<< Updated upstream
        if (std::regex_search(str_actual, matches, liste_reg_init_LGUHC[2]))
            return event_ingame_LGUHC(result, data_brut, str_actual, disconnected);
=======
        else if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_TRUBLIONNAGE]))
        {
            RegexInitLGUHC iterator_regex = REG_ROLE;
        }
        else if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_COUPLE]))
        {
            result.set_id_camp(4);
        }
        else if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_PROTEGE]))
        {
            if(result.get_id_camp()!=4)
            {
                result.set_id_camp(result.get_id_camp() + 4);
                //1 : villageois, 2 : loup-garous, 3 : solos, 4 : couple, 5 : protégé, villageois, 6 : protégé, loups, 7 : protégé, solo
                //je mets l'id camp à l'id camp de base plus 4 pour skip les quatres premiers cas
            }
        }
>>>>>>> Stashed changes
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

    std::array<std::regex, 3> liste_reg_main_traitement{
        std::regex(R"(\[(\d{2}):(\d{2}):(\d{2})\].*\[CHAT\].*\[UHC\].*Bienvenue dans cette partie de (.+?UHC))")
    }; //0 = reg_start
    std::string str_actual = data_brut.give_line_kill_line();//init de la string de la data_brut
    bool disconnected = false;
    std::smatch matches;

    while (!data_brut.empty() && !disconnected) {
        while (std::regex_search(str_actual, matches, liste_reg_main_traitement[iterator_regex]))
        {
            switch (iterator_regex)
            {
            case 0:
                std::cout << "Inregex, nom de mode de jeu : " << matches.str(4) << "\n";
                if (matches.str(4) == "LG UHC") {
                    data_game result;
                    result.set_start_game("h : " + matches.str(1) + " min : " + matches.str(2) + " sec : " + matches.str(3));
                    std::cout << "Début de game LG UHC.\n";
                    init_treatement_lguhc(result, data_brut, str_actual, disconnected);
                    result.merge_into_data_base();
                }
                str_actual = matches.suffix().str();   //suprime le résultat trouvé pour npasser aux prochain 
            }
        }
        str_actual = data_brut.give_line_kill_line();
    }
    std::cout << "fin de fichier\n";
    return data_game();
}
*/