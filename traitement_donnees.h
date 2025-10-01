#pragma once
#include "data_game.h"
#include "recup_donnee_brut.h"
#include <array>
#include <regex>

//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'à 45min, traitant des events suivants : 
//couple
//protégé
//events selon le role attribué : cupidon, voleur, enfant sauvage, chien-loup, renégat, trublion, voleur
//attribué le camp selon le role sinon
std::array<std::string, 4> init_treatement_lguhc(std::array<std::string, 4>& result, log_brut& data_brut, std::string& str_actual, bool disconnected);

//recherche de quelle type de game on fait, LGUHC, CHAINSAWMANUHC, AOTUHC
data_game main_treatement(log_brut& data_brut);

