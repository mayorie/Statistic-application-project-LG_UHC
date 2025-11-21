#include "recup_donnee_brut.h"
#include "doc_regex.h"
#include "creation_bd.h"
#include "traitement_donnees.h"
#include <iostream>
#include <fstream>
#include <string>
<<<<<<< Updated upstream


int main() {
	//récupération des données
=======
//	std::cout << "\033[31m" << "Texte rouge" << "\033[0m\n";
//	std::cout << "\033[32m" << "Texte vert" << "\033[0m\n";

/*
data_game = cyan => \033[36m
creation_bd = magenta => \033[35m
recup_donnee_brut = yellow => \033[33m
main_traitement = blue => \033[34m
LG_traitement = darkcyan => \x1B[38;2;0;150;150m
*/


int main() {

	//rÃ©cupÃ©ration des donnÃ©es
>>>>>>> Stashed changes
	std::string chemin = "logs/2025-09-06-1.log/2025-09-06-1.log";

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

<<<<<<< Updated upstream
	//création du fichier des log bruts et récupération de ces données
=======


	//crÃ©ation du fichier des log bruts et rÃ©cupÃ©ration de ces donnÃ©es
>>>>>>> Stashed changes
	log_brut fichier_log(chemin);

	//main_treatement(fichier_log);
	LG_traitement_regex_data_game traitement = LG_traitement_regex_data_game(fichier_log);

	traitement.set_str_actual("[17:59:44] [Client thread/INFO]: [CHAT]  â€¢ Vous Ãªtes Loup-Garou Blanc");
	traitement.role_LG();

	traitement.set_str_actual("[17:59:44] [Client thread/INFO]: [CHAT]  â€¢ Objectif : Vous devez gagner Seul.");
	traitement.camp_LG();

	select_all_from_table("game"); //"game", "role", "role_camp", "gameplay"

	delete_all_games();

	return 0;
}
