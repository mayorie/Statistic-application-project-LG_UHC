#include "traitement_donnees.h"

//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'à 45min, traitant des events suivants : 
//couple
//protégé
//events selon le role attribué : cupidon, voleur, enfant sauvage, chien-loup, renégat, trublion, voleur
//attribué le camp selon le role sinon
data_game init_treatement_lguhc(data_game &result,log_brut &data_brut, std::string &str_actual, bool disconnected)
{
    int iterator_regex = 0;

    std::smatch matches;

    //liste des regex nécéssaires pour l'init des camp et roles seulement
    std::array<std::regex, 3> liste_reg{
    std::regex (R"(Vous êtes\s+([A-Za-zÀ-ÿ\- ]+))"),
    std::regex (R"(Objectif\s*:\s*Vous devez gagner\s+([A-Za-zÀ-ÿ\-]+))"),
    std::regex(R"(azertyuiopmlkjhgfdsqwxcvbn)")
    }; //0 = reg_role

    std::cout << "\n\n\n\nentré init_treatement_lguhc\n\n";
    while (!data_brut.empty() && !disconnected)
    {
        bool role_pris = false;
        while (std::regex_search(str_actual, matches, liste_reg[iterator_regex]))
        {
            switch (iterator_regex)
            {
            case 0:
            {
                std::string role_name = matches.str(1);
                std::cout << "Traitement LGUHC : role trouvé : " << role_name << "\n";
                try {
                    int id_role = search_id_role_by_name(role_name); // utilise ta fonction qui retourne -1 si non trouvé
                    if (id_role == -1) {
                        throw std::runtime_error("Traitement LGUHC : Le rôle '" + role_name + "' n'existe pas dans la base !\n\n\n");
                    }

                    std::cout << "Traitement LGUHC : id_role : " << id_role << "\n\n";

                    result.set_id_role(id_role);
                }
                catch (const std::exception& e) {
                    std::cerr << "Erreur : " << e.what() << std::endl;
                }
                iterator_regex++;
                break;
            }
            case 1:
            {
                std::string camp_name = matches.str(1);
                std::cout << "Traitement LGUHC : camp trouvé : " << camp_name << "\n";
                try {
                    int id_camp = search_id_camp_by_name(camp_name); // utilise ta fonction qui retourne -1 si non trouvé
                    if (id_camp == -1) {
                        throw std::runtime_error("Traitement LGUHC : Le camp '" + camp_name + "' n'existe pas dans la base !\n\n\n");
                    }

                    std::cout << "Traitement LGUHC : id_camp : " << id_camp << "\n\n";

                    result.set_id_camp(id_camp);
                }
                catch (const std::exception& e) {
                    std::cerr << "Erreur : " << e.what() << std::endl;
                }
                iterator_regex++;
                break;
            }
            default:
                return result;
            }
            str_actual = matches.suffix().str();   //suprime le résultat trouvé pour npasser aux prochain 
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
    static std::regex reg_start(R"(\[(\d{2}):(\d{2}):(\d{2})\].*\[CHAT\].*\[UHC\].*Bienvenue dans cette partie de (.+?UHC))");
    std::string str_actual = data_brut.give_line_kill_line();//init de la string de la data_brut
    data_game result;
    bool disconnected = false;
    std::smatch matches;

    while (!data_brut.empty() && !disconnected) {
        while (std::regex_search(str_actual, matches, reg_start))
        {
            std::cout << "Inregex, nom de mode de jeu : " << matches.str(4) << "\n";
            if (matches.str(4) == "LG UHC") {
                result.set_start_game("h : " + matches.str(1) + " min : " + matches.str(2) + " sec : " + matches.str(3));
                std::cout << "Début de game LG UHC.\n";
                init_treatement_lguhc(result, data_brut, str_actual, disconnected);
            }
            str_actual = matches.suffix().str();   //suprime le résultat trouvé pour npasser aux prochain 
        }
        str_actual = data_brut.give_line_kill_line();
    }
    std::cout << "fin de fichier\n";
    return data_game();
}
