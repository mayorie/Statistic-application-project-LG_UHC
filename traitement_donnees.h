#pragma once
#include "data_game.h"
#include "recup_donnee_brut.h"
#include "sqlite3.h"
#include <array>
#include <regex>

//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'à 45min, traitant des events suivants : 
//couple
//protégé
//events selon le role attribué : cupidon, voleur, enfant sauvage, chien-loup, renégat, trublion, voleur
//attribué le camp selon le role sinon
data_game init_treatement_lguhc(data_game& result, log_brut& data_brut, std::string& str_actual, bool disconnected);

std::string init_camp_lguhc(int role);

//recherche de quelle type de game on fait, LGUHC, CHAINSAWMANUHC, AOTUHC
data_game main_treatement(log_brut& data_brut);

