#pragma once
#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <string>


//initialise la base de donn�e
int create_stats_lguhc();

//ajoute les datas d'une game dans la table game
int insert_game(int id_role, int camp, std::string start_game, std::string event_ingame, bool win, std::string comment);

//suprime l'une des games via l'id dans la table game
int delete_game(int id_game);

//permet de selct et d'afficher toutes les donn�es d'une table
int select_all_from_table(const std::string& tableName);//"game", "role", "role_camp", "gameplay"

//supr�tion du contenu de la table game et reset des ids
int delete_all_games();
