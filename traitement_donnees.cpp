#include "traitement_donnees.h"

//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'à 45min, traitant des events suivants : 
//couple
//protégé
//events selon le role attribué : cupidon, voleur, enfant sauvage, chien-loup, renégat, trublion, voleur
//attribué le camp selon le role sinon
std::array<std::string, 4> init_treatement_lguhc(std::array<std::string, 4> &result,log_brut &data_brut, std::string &str_actual, bool disconnected)
{
    std::smatch matches;

    //liste des regex nécéssaires pour l'init des camp et roles seulement
    std::array<std::regex, 1> liste_reg{
   std::regex(R"(\[(\d{2}:\d{2}:\d{2})\].*?<span style="color: #555;">• <\/span>.*?<span style="color: #AAA;">Vous êtes <\/span>.*?<span[^>]*>([^<]+)<\/span>)")
    }; //0 = reg_role

    std::cout << "entré traitement de donnée lguhc\n\n";
    while (!data_brut.empty() && !disconnected)
    {
        bool role_pris = false;
        while (std::regex_search(str_actual, matches, liste_reg[0]))
        {

        }
    }
    return result;
}



//recherche de quelle type de game on fait, LGUHC, CHAINSAWMANUHC, AOTUHC
data_game main_treatement(log_brut &data_brut)
{
    //initialisation des variables
    //init pour le regex
    static std::regex reg_start(R"(\[(\d{2}:\d{2}:\d{2})\].*?Bienvenue dans cette partie de.*?(LG UHC S\d+\.\d+))");//regex pour voir quelle type de game c'est
    std::string str_actual = data_brut.give_line_kill_line();//init de la string de la data_brut
    std::array<std::string, 4> result;//0 = start_game, 1 = role, 2 = winning_camp, 3 = event_game //une manière de stocker temporèrement les données //à changer pour un txt qui se modifie au fur et à mesure
    bool disconnected = false;
    
    while (!data_brut.empty() && !disconnected) {
        auto words_begin = std::sregex_iterator(str_actual.begin(), str_actual.end(), reg_start);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::cout << "regex iterator\n";
            if (match.str(2) == "LG UHC") {
                result[0] = match.str(1);
                //init_treatement_lguhc(result, data_brut, str_actual, disconnected);
            }
        }
        str_actual = data_brut.give_line_kill_line();
    }
    std::cout << "fin de fichier\n";
    return data_game();
}
