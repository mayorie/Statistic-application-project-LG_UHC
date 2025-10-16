#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "creation_bd.h" // pour insert_game()

class data_game {
private:
    struct GameEntry {
        std::string start_game;
        int id_role;
        int id_camp;
        bool win;
        std::vector<int> event_game = {};
    };
    GameEntry entry;

public:

    data_game(std::string& date,
        int& id_role,
        int& id_camp,
        bool& win)
        : entry{ date, id_role, id_camp, win} {
    }
    data_game()
        : entry{ "", -1, -1, false} {
    }

    const std::string& get_start_game() const { return entry.start_game; }
    const int& get_id_role() const { return entry.id_role; }
    const int& get_id_camp() const { return entry.id_camp; }
    const bool& get_win() const { return entry.win; }
    const std::vector<int>& get_event_game() const { return entry.event_game; }

    void set_start_game(std::string start_game) { entry.start_game = start_game; }
    void set_id_role(int id_role) { entry.id_role = id_role; }
    void set_id_camp(int id_camp) { entry.id_camp = id_camp; }
    void set_win(bool win) { entry.win = win; }
    void clear_event_game(int event) { entry.event_game.clear(); }

    void add_event_game(int& entry_event_game) { entry.event_game.push_back(entry_event_game); }

    bool merge_into_data_base() {

        // Insertion dans la base de données
        int rc = insert_game(entry.id_role, entry.id_camp, entry.start_game, entry.win);

        // Vérification du succès
        if (rc == SQLITE_DONE) {
            std::cout << "[merge_into_data_base] Insertion réussie pour le jeu : "
                << entry.start_game << std::endl;
            return true;
        }
        else {
            std::cerr << "[merge_into_data_base] Échec de l'insertion (code SQLite : " << rc << ")" << std::endl;
            return false;
        }
    }
};