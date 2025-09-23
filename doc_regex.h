#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "recup_donnee_brut.h"
#include "data_game.h"

int traitement_test();
void print_matches(std::string str, std::regex reg);
void print_matches2(std::string str, std::regex reg);
void print_start(std::string str, std::regex reg);
void traitement(log_brut log, std::string str_log_actuelle);

