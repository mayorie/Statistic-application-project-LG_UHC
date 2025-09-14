#include "traitement_donnees.h"

data_game main_traitement(log_brut data_brut)
{
    std::regex reg_start_game(R"(\[(\d{2}:\d{2}:\d{2})\].*?UHC.*?Bienvenue dans cette partie de.*?(LG UHC S\d+\.\d+))");
    std::regex reg_role(R"(\[(\d{2}:\d{2}:\d{2})\].*?<span style="color: #555;">• <\/span>.*?<span style="color: #AAA;">Vous êtes <\/span>.*?<span[^>]*>([^<]+)<\/span>)");

    std::array<std::string, 4> result;//0 = start_game, 1 = role, 2 = winning_camp, 3 = event_game

    std::time_t start_game;
    std::string role;
    std::string winning_camp;
    std::string event_game;

    std::smatch matches;

    bool game_started = false; // état pour savoir quel regex utiliser

    while (!data_brut.empty())
    {
        std::string str_actual = data_brut.give_line_kill_line();

        if (!game_started) // tant que la partie n’a pas commencé
        {
            if (std::regex_search(str_actual, matches, reg_start_game))
            {
                // -> première détection : partie commence
                result[0] = matches.str(1);
                game_started = true;
            }
        }
        else // une fois que le premier regex a matche
        {
            if (std::regex_search(str_actual, matches, reg_role))
            {
                // -> Ici tu fais ton traitement spécial avec le 2e regex
                result[1] = matches.str(2);
            }
        }
    }










    return data_game();
}
