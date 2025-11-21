#include "traitement_LG.h"


// Liste des regex nécessaires pour l'init des camps et rôles
std::array<std::regex, REG_INIT_COUNT> liste_reg_LGUHC = {
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

int LG_traitement_regex_data_game::set_str_actual(std::string str)
{
    str_actual = str;
    return 1;
}

LG_traitement_regex_data_game::LG_traitement_regex_data_game(log_brut& log_str_actual)
    : str_actual(log_str_actual.get_ref_str_actual()),
    game()
{
    //rien
}

data_game& const LG_traitement_regex_data_game::get_game()
{
    return this->game;
}

int LG_traitement_regex_data_game::role_LG()
{
    std::smatch matches;
    if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_ROLE]))
    {
        std::string role_name = matches.str(1);
        std::cout << "\x1B[38;2;0;150;150m" << "[LG_traitement]" << "\033[32m" << " Role trouvé : " << role_name << "\033[37m" << "\n";
        int id_role = search_id_role_by_name(role_name); // utilise ta fonction qui retourne -1 si non trouvé
        if (id_role == -1) {
            std::cout << "\x1B[38;2;0;150;150m" << "[LG_traitement]" << "\033[31m" << " Le rôle '" + role_name + "' n'existe pas dans la base !" << "\033[37m" << "\n";
            return -1;
        }
        else
        {
            std::cout << "\x1B[38;2;0;150;150m" << "[LG_traitement]" << "\033[32m" << " Id_role : " << id_role << "\033[37m" << "\n";
            this->game.set_id_role(id_role);
            return 1;
        }
    }
    return 0;    
}

int LG_traitement_regex_data_game::camp_LG()
{
    std::smatch matches;
    if (std::regex_search(str_actual, matches, liste_reg_LGUHC[REG_CAMP]))
    {

        std::string camp_name = matches.str(1);
        std::cout << "\x1B[38;2;0;150;150m" << "[LG_traitement]" << "\033[32m" << " Traitement LGUHC : camp trouvé : " << camp_name << "\033[37m" << "\n";
        int id_camp = search_id_camp_by_name(camp_name); // utilise ta fonction qui retourne -1 si non trouvé
        if (id_camp == -1) {
            std::cout << "\x1B[38;2;0;150;150m" << "[LG_traitement]" << "\033[31m" << " Traitement LGUHC : Le camp '" + camp_name + "' n'existe pas dans la base !" << "\033[37m" << "\n";
            return -1;
        }
        else if (this->game.get_id_camp() == 4)
        {
            std::cout << "\x1B[38;2;0;150;150m" << "[LG_traitement]" << "\033[32m" << " Traitement LGUHC : Le camp ne change pas car tu es en couple !" << "\033[37m" << "\n";
            return 0;
        }
        else
        {
            std::cout << "\x1B[38;2;0;150;150m" << "[LG_traitement]" << "\033[32m" << " Traitement LGUHC : id_camp : " << id_camp << "\033[37m" << "\n";
            if (this->game.get_id_camp() > 4)
            {
                this->game.set_id_camp(id_camp + 4);
            }
            else
            {
                this->game.set_id_camp(id_camp);
            }
            return 1;
        }
    }
    return 0;
}
