#include "recup_donnee_brut.h"
#include "banque_donnee_traite.h"
#include "doc_regex.h"
#include <iostream>
#include <fstream>
#include <string>


int main() {
	
	//récupération des données
	std::string chemin = "C:\\Users\\matts\\AppData\\Roaming\\.minecraft\\versions\\TEST chatlog\\chatlogs\\2025-07-27.htm";

	//initialisation
	//banque de donnee a faire selement si elle n'est pas déjà créé
	banque_donnee_traite banque_donnees;

	//création du fichier des log bruts et récupération de ces données
	log_brut fichier_log(chemin);

	//teste du fichier de récupération des données brut
	std::string ligne = fichier_log.give_line_kill_line();
	while (!ligne.empty()) {
		std::cout << ligne << std::endl; // Affiche chaque ligne lue
		ligne = fichier_log.give_line_kill_line();
	}
	
	traitement_test(); //compréhention des regex

	return 0;
}
