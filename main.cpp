#include "recup_donnee_brut.h"
#include "doc_regex.h"
#include "creation_bd.h"
#include "traitement_donnees.h"
#include <iostream>
#include <fstream>
#include <string>


int main() {

	//r�cup�ration des donn�es
	std::string chemin = "C:/Users/mayorie/Desktop/chatogs/2025-07-27.htm";

	//initialisation
	// cr�ation base de donn�e.
	create_stats_lguhc();

	//insert une game
	//insert_game(
	//	1,                                  // id_role
	//	1,                                  // camp
	//	"2025-10-05 21:00:00",              // start_game
	//	"Le village a d�couvert un loup",   // event_ingame
	//	1,
	//	"Victoire du village !"             // comment
	//);

	//suprime le contenu de la table game
	//delete_all_games();

	//select all sur une table
	//select_all_from_table("game"); //"game", "role", "role_camp", "gameplay"

	//delete
	//delete_game(int id_game)

	//cr�ation du fichier des log bruts et r�cup�ration de ces donn�es
	log_brut fichier_log(chemin);

	main_treatement(fichier_log);


	return 0;
}
