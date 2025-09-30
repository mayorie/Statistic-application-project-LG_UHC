#include "recup_donnee_brut.h"
#include "doc_regex.h"
#include "creation_bd.h"
#include <iostream>
#include <fstream>
#include <string>


int main() {

	//récupération des données
	std::string chemin = "C:\\Users\\matts\\AppData\\Roaming\\.minecraft\\versions\\TEST chatlog\\chatlogs\\2025-07-27.htm";

	//initialisation
	// création base de donnée.
	create_stats_lguhc();

	//insert une game
	insert_game(
		1,                                  // id_role
		1,                                  // camp
		"2025-10-05 21:00:00",              // start_game
		"Le village a découvert un loup",   // event_ingame
		1,
		"Victoire du village !"             // comment
	);

	//select all sur une table
	select_all_from_table("game"); //"game", "role", "role_camp", "gameplay"

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
