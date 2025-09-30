#pragma once
#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <string>

int create_stats_lguhc();
int insert_game(int id_role, int camp, std::string start_game, std::string event_ingame, bool win, std::string comment);
int select_all_from_table(const std::string& tableName);
