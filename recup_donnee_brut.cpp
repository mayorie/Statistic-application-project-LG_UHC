#include "recup_donnee_brut.h"

log_brut::log_brut(std::string chemin)
{
    fs_log_brut.open(chemin);

    if (!fs_log_brut.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier des logs." << std::endl;
        return;
    }
    else {
<<<<<<< Updated upstream
        std::cout << "Fichier ouvert avec succ�s.\n";
=======
        std::cout << "\033[33m" << "[recup_donnee_brut]" << "\033[32m" << " Fichier ouvert avec succès.\n" << "\033[37m";
>>>>>>> Stashed changes
    }
    std::getline(fs_log_brut, str_actual);
}


bool log_brut::kill(std::string chemin) {
    if (fs_log_brut.is_open()) {
        fs_log_brut.close();
    }

    if (std::remove(chemin.c_str()) == 0) {
<<<<<<< Updated upstream
        std::cout << "Fichier supprim� avec succ�s." << std::endl;
=======
        std::cout << "\033[33m" << "[recup_donnee_brut]" << "\033[32m" << " Fichier supprimé avec succès." << "\033[37m" << std::endl;
>>>>>>> Stashed changes
        return true;
    }
    else {
        std::cerr << "Erreur : impossible de supprimer le fichier." << std::endl;
        return false;
    }
}

std::string& log_brut::get_ref_str_actual()
{
    return str_actual;
}

void log_brut::next_line() {
    if (!fs_log_brut) {
<<<<<<< Updated upstream
        std::cerr << "Erreur : ifstream invalide." << std::endl;
        return "";
=======
        std::cerr << "\033[33m" << "[recup_donnee_brut]"
            << "\033[31m" << " Erreur : ifstream invalide."
            << "\033[37m" << std::endl;
        str_actual = "";
        return;
>>>>>>> Stashed changes
    }

    std::string ligne;
    if (std::getline(fs_log_brut, ligne)) {
        str_actual = ligne;   // ✔ met à jour la ligne actuelle
    }
    else {
        if (fs_log_brut.eof()) {
            // Fin normale
            str_actual = "";  // ✔ plus de ligne
        }
        else {
<<<<<<< Updated upstream
            std::cerr << "Erreur : impossible de lire la ligne du ifstream des logs." << std::endl;
            return "";
=======
            std::cerr << "\033[33m" << "[recup_donnee_brut]"
                << "\033[31m" << " Erreur : impossible de lire la ligne du ifstream."
                << "\033[37m" << std::endl;
            str_actual = "";
>>>>>>> Stashed changes
        }
    }
}

bool log_brut::empty() {
    if (!fs_log_brut.is_open()) return true;

    // Sauvegarde la position actuelle
    std::streampos current_pos = fs_log_brut.tellg();

    if (current_pos == -1) {
        // Le flux est peut-être en EOF ou invalide
        fs_log_brut.clear(); // réinitialise les flags
        return true;
    }

    // Vérifie si on est à la fin du fichier
    fs_log_brut.seekg(0, std::ios::end);
    std::streampos end_pos = fs_log_brut.tellg();

    // Reviens à la position initiale
    fs_log_brut.seekg(current_pos);

    return current_pos >= end_pos;
}





