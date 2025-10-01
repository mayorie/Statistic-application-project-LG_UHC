#pragma once
#include "data_game.h"
#include "recup_donnee_brut.h"
#include <array>
#include <regex>

//init du traitement lguhc, je trouve le camp et le role de ta game jusqu'� 45min, traitant des events suivants : 
//couple
//prot�g�
//events selon le role attribu� : cupidon, voleur, enfant sauvage, chien-loup, ren�gat, trublion, voleur
//attribu� le camp selon le role sinon
std::array<std::string, 4> init_treatement_lguhc(std::array<std::string, 4>& result, log_brut& data_brut, std::string& str_actual, bool disconnected);

//recherche de quelle type de game on fait, LGUHC, CHAINSAWMANUHC, AOTUHC
data_game main_treatement(log_brut& data_brut);

