#pragma once
#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <string>


//initialise la base de donnée
int create_stats_lguhc();

//ajoute les datas d'une game dans la table game
int insert_game(int id_role, int camp, std::string start_game, std::string event_ingame, bool win, std::string comment);

//suprime l'une des games via l'id dans la table game
int delete_game(int id_game);

//permet de selct et d'afficher toutes les données d'une table
int select_all_from_table(const std::string& tableName);//"game", "role", "role_camp", "gameplay"
