#pragma once
#include <string>
#include <ctime>

class data_game {
private:
    struct GameEntry {
        std::string start_game;
        std::string role;
        std::string winning_camp;
        std::string event_game;
    };
    GameEntry entry;

public:

    data_game(const std::string& date,
        const std::string& role,
        const std::string& winning_camp,
        const std::string& event_game = "")
        : entry{ date, role, winning_camp, event_game } {
    }
    data_game() {}

    const std::string& get_start_game() const { return entry.start_game; }
    const std::string& get_role() const { return entry.role; }
    const std::string& get_winning_camp() const { return entry.winning_camp; }
    const std::string& get_event_game() const { return entry.event_game; }

    void set_event_game(std::string entry_event_game) { entry.event_game = entry_event_game; }
    void add_event_game(std::string entry_event_game) { entry.event_game += entry_event_game; }

};