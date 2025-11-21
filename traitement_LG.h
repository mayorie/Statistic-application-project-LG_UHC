#pragma once
#include "data_game.h"
#include "recup_donnee_brut.h"
#include <regex>
#include <array>

enum RegexInitLGUHC {
    REG_ROLE,
    REG_CAMP,
    REG_45MIN,
    REG_TRUBLIONNAGE,
    REG_COUPLE,
    REG_PROTEGE,
    REG_VAINQUEUR,
    REG_ZIZANIE,
    REG_INFECTE,
    REG_LOUP_SOLITAIRE,
    REG_VOLEUR,
    REG_ES_MODEL_MORT,
    REG_RENEGAT,
    REG_CUPI_COUPLE_MORT,
    REG_CUPI_RANCUNIER,
    REG_VACCINATION,
    REG_INIT_COUNT
};

// Liste des regex nécessaires pour l'init des camps et rôles
extern std::array<std::regex, REG_INIT_COUNT> liste_reg_LGUHC;


class LG_traitement_regex_data_game
{
private:
    std::string& str_actual;
    data_game game = data_game();

public:
    int set_str_actual(std::string str);




    LG_traitement_regex_data_game(log_brut& log_str_actual);
    data_game& const get_game();
    int role_LG();
    int camp_LG();

};