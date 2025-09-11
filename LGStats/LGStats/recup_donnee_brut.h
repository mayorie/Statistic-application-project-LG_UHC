#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

class log_brut {
private : 
	std::ifstream fs_log_brut;
public : 
	log_brut(std::string chemin); //constructeur
	bool kill(std::string chemin); //destructeur (détruit le ifstream et le fichier)

	std::string give_line_kill_line(); //vide la line et passe à la prochaine
	bool empty(); //regarde si il reste des lignes plein dans le ifstream si oui ==> False
};
