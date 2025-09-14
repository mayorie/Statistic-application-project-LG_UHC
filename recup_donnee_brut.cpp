#include "recup_donnee_brut.h"

log_brut::log_brut(std::string chemin)
{
    fs_log_brut.open(chemin);

    if (!fs_log_brut.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier des logs." << std::endl;
        return;
    }
}


bool log_brut::kill(std::string chemin) {
    if (fs_log_brut.is_open()) {
        fs_log_brut.close();
    }

    if (std::remove(chemin.c_str()) == 0) {
        std::cout << "Fichier supprimé avec succès." << std::endl;
        return true;
    }
    else {
        std::cerr << "Erreur : impossible de supprimer le fichier." << std::endl;
        return false;
    }
}

std::string log_brut::give_line_kill_line() {
    if (!fs_log_brut) {
        std::cerr << "Erreur : ifstream invalide." << std::endl;
        return "";
    }

    std::string ligne;
    if (std::getline(fs_log_brut, ligne)) {
        return ligne;
    }
    else {
        if (fs_log_brut.eof()) {
            // Fin normale, pas une erreur
            return "";
        }
        else {
            std::cerr << "Erreur : impossible de lire la ligne du ifstream des logs." << std::endl;
            return "";
        }
    }
}

bool log_brut::empty() {
    if (!fs_log_brut) return true; // fichier pas ouvert ou invalide

    // Sauvegarder la position actuelle
    std::streampos current_pos = fs_log_brut.tellg();

    // Aller à la fin pour voir si on y est déjà
    fs_log_brut.seekg(0, std::ios::end);
    bool is_empty = (fs_log_brut.tellg() == 0);

    // Revenir à la position initiale
    fs_log_brut.seekg(current_pos);

    return is_empty;
}




