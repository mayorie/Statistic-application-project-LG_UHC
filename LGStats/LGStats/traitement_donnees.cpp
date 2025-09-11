#include "traitement_donnees.h"

data_game traitement(log_brut log, std::string str_log_actuelle)
{
	std::smatch matches;
	//recherche du start de la game
	static std::regex reg_start(R"(\[(\d{2}:\d{2}:\d{2})\].*?UHC.*?Bienvenue dans cette partie de.*?(LG UHC S\d+\.\d+))");
	while (std::regex_search(str_log_actuelle, matches, reg_start))
	{
		std::cout << "Heure : " << matches.str(1) << "\n";
		std::cout << "Modèle : " << matches.str(2) << "\n\n";
		str_log_actuelle = matches.suffix().str();
	}
}


std::cout << "start game : \n";
std::string str7 = "<code><span>[14:27:08] </span><span></span><span style=\"color: #555;\">[</span><span></span><span style=\"color: #FF5;\">UHC</span><span></span><span style=\"color: #555;\">]</span><span></span><span style=\"color: #000;\"> </span><span></span><span style=\"color: #000;\">Bienvenue dans cette partie de </span><span></span><span style=\"color: #55F;\">LG UHC S10.5  </span><span></span></code><br>";
std::regex reg7(R"(\[(\d{2}:\d{2}:\d{2})\].*?UHC.*?Bienvenue dans cette partie de.*?(LG UHC S\d+\.\d+))");
print_start(str7, reg7);

std::cout << "le role : \n";
std::string str8 = "<code><span>[14:47:08] </span><span> </span><span></span><span style=\"color: #555;\">• </span><span></span><span style=\"color: #AAA;\">Vous êtes </span><span></span><span style=\"color: #5F5;\">Soeur</span><span></span></code><br>";
std::regex reg8(R"(\[(\d{2}:\d{2}:\d{2})\].*?<span style="color: #555;">• <\/span>.*?<span style="color: #AAA;">Vous êtes <\/span>.*?<span[^>]*>([^<]+)<\/span>)");
print_start(str8, reg8);