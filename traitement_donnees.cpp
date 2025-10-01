#include "traitement_donnees.h"

//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'� 45min, traitant des events suivants : 
//couple
//prot�g�
//events selon le role attribu� : cupidon, voleur, enfant sauvage, chien-loup, ren�gat, trublion, voleur
//attribu� le camp selon le role sinon
std::array<std::string, 4> init_treatement_lguhc(std::array<std::string, 4> &result,log_brut &data_brut, std::string &str_actual, bool disconnected)
{
    std::smatch matches;

    //liste des regex n�c�ssaires pour l'init des camp et roles seulement
    std::array<std::regex, 1> liste_reg{
   std::regex(R"(\[(\d{2}:\d{2}:\d{2})\].*?<span style="color: #555;">� <\/span>.*?<span style="color: #AAA;">Vous �tes <\/span>.*?<span[^>]*>([^<]+)<\/span>)")
    }; //0 = reg_role

    std::cout << "entr� traitement de donn�e lguhc";
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
    static std::regex reg_start(R"(\[(\d{2}:\d{2}:\d{2})\].*?UHC.*?Bienvenue dans cette partie de.*?(LG UHC S\d+\.\d+))");//regex pour voir quelle type de game c'est
    std::smatch matches;
    std::string str_actual = data_brut.give_line_kill_line();//init de la string de la data_brut

    std::array<std::string, 4> result;//0 = start_game, 1 = role, 2 = winning_camp, 3 = event_game //une mani�re de stocker tempor�rement les donn�es //� changer pour un txt qui se modifie au fur et � mesure
    bool disconnected = false;//futur mani�re de savoir si le joueur s'est d�connect�, et voir si il s'est reconnect�

    std::cout << "entr� main_treatement";

    while (!data_brut.empty() && !disconnected)//boucle pour chaque ligne str_actual du data_brut
    {
        while(std::regex_search(str_actual, matches, reg_start))//v�rif que dans str_actual il y a le regex ou non
        {
            if (matches.str(2) == "LG UHC")
            {
                std::cout << "entr� if pour regex start game";

                // -> premi�re d�tection : partie commence
                result[0] = matches.str(1);
                if (matches.str(2) == "LG UHC")//pas sure du "lg" peut etre lguhc
                    init_treatement_lguhc(result, data_brut, str_actual, disconnected);
            }
        }
        str_actual = data_brut.give_line_kill_line();
    }
    return data_game();
}
