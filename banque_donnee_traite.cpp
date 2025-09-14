#include "banque_donnee_traite.h"
#include <vector>

banque_donnee_traite::banque_donnee_traite()
{
    std::vector<std::string> list_roles = { "Analyste","Astronome","Aubergiste","Bohémienne","Chaman",
                                            "Conteuse","Détective","Druide","Espion","Fossoyeur",
                                            "Interprète","Jumeaux","Montreur d'Ours","Oracle","Prêtresse",
                                            "Prophétesse","Renard","Vaudouiste","Vieux Sage","Voyante",
                                            "Ancien","Avocat","Bienfaiteur","Bouc Émissaire","Braconnier",
                                            "Chasseur","Citoyen","Corbeau","Ermite","Garde",
                                            "Idiot du Village","Lapin","Mire","Petite Fille","Rebouteux",
                                            "Salvateur","Serviteur","Simple Villageois","Soeurs","Sorcière",
                                            "Loup - Garou","Grand Méchant Loup","Infect Père des Loups","Loup - Garou Amnésique","Loup - Garou Craintif",
                                            "Loup - Garou Déloyal","Loup - Garou Faussaire","Loup - Garou Feutré","Loup - Garou Grimeur","Loup - Garou Hurleur",
                                            "Loup - Garou Mystique","Loup - Garou Perfide","Loup - Garou Sanguinaire","Loup - Garou Ténébreux","Loup - Garou Vengeur",
                                            "Vilain Petit Loup","Loup - Garou Blanc","Ange","Assassin","Feu Follet",
                                            "Imitateur","Joueur de Flûte","Nécromancien","Pyromane","Rival",
                                            "Ronin","Voyou","Chien - Loup","Cupidon","Enfant Sauvage",
                                            "Renégat","Trublion","Voleur"};
    for(auto& role : list_roles)
    {
        game_data_list.emplace_back(role, std::vector<std::shared_ptr<data_game>>{});
    }
}

void banque_donnee_traite::add(std::shared_ptr<data_game> game){
    for (int i = 0;i < game_data_list.size();++i)
        if (game_data_list[i].first == game->get_role())
            game_data_list[i].second.push_back(game);
}

std::shared_ptr<data_game> banque_donnee_traite::erase(std::time_t start_game)
{
    for (auto role_it = game_data_list.begin(); role_it != game_data_list.end(); ++role_it) {
        auto& games = role_it->second;
        for (auto game_it = games.begin(); game_it != games.end(); ++game_it) {
            if ((*game_it)->get_start_game() == start_game)
            {
                std::shared_ptr<data_game> result = *game_it;
                games.erase(game_it);
                return result;
            }
        }
    }
    return NULL;
}
