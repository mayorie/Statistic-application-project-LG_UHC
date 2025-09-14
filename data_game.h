#pragma once
#include <string>
#include <ctime>

class data_game {
private : 
    struct GameEntry {
        std::time_t start_game;
        std::string role;
        std::string winning_camp;
        std::string event_game;
    };
    GameEntry entry;

public : 

    data_game(std::time_t timestamp, std::string& role, std::string& winning_camp)
        : entry{timestamp,role,winning_camp} { }
    data_game() {}

    const std::time_t& get_start_game() const { return entry.start_game; }
    const std::string& get_role() const { return entry.role; }
    const std::string& get_winning_camp() const { return entry.winning_camp; }
    const std::string& get_event_game() const { return entry.event_game; }
};