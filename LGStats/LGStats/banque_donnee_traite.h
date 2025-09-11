#pragma once
#include <vector>
#include <memory>
#include "data_game.h"

class banque_donnee_traite {
private :
    std::vector<std::pair<std::string, std::vector<std::shared_ptr<data_game>>>> game_data_list;


public : 
    banque_donnee_traite();

    void add(std::shared_ptr<data_game> game);
    std::shared_ptr<data_game> erase(std::time_t start_game);
};