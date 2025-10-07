#include "recup_donnee_brut.h"
#include "doc_regex.h"
#include "creation_bd.h"
#include "traitement_donnees.h"
#include <iostream>
#include <fstream>
#include <string>


int main() {
	//récupération des données
	std::string chemin = "C:/Users/mayorie/Documents/GitHub/Statistic-application-project-LG_UHC/logs/2025-09-06-1.log/2025-09-06-1.log";

	//initialisation
	// création base de donnée.
	create_bd_stats();

	//insert une game
	//insert_game(
	//	1,                                  // id_role
	//	1,                                  // camp
	//	"2025-10-05 21:00:00",              // start_game
	//	"Le village a découvert un loup",   // event_ingame
	//	1,
	//	"Victoire du village !"             // comment
	//);

	//suprime le contenu de la table game
	//delete_all_games();

	//select all sur une table
	//select_all_from_table("game"); //"game", "role", "role_camp", "gameplay"

	//delete
	//delete_game(int id_game)

	//création du fichier des log bruts et récupération de ces données
	log_brut fichier_log(chemin);

	main_treatement(fichier_log);


	return 0;
}
