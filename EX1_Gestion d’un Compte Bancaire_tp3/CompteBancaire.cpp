#include "CompteBancaire.hpp"

// Méthodes privées utilitaires
void CompteBancaire::agrandirHistorique() {
    std::size_t nouvelleCap = capacite * 2;
    std::string* nouveau = new std::string[nouvelleCap];
    std::copy(historique, historique + nbOps, nouveau);
    delete[] historique;
    historique = nouveau;
    capacite = nouvelleCap;
}

void CompteBancaire::ajouterOperation(const std::string& op) {
    if (nbOps == capacite) agrandirHistorique();
    historique[nbOps++] = op;
}

// Constructeur par défaut
CompteBancaire::CompteBancaire() : numero("NON_DEFINI"), solde(0.0), capacite(10), nbOps(0) {
    historique = new std::string[capacite];
}

// Constructeur paramétré
CompteBancaire::CompteBancaire(const std::string& num, double s) : numero(num), solde(s), capacite(10), nbOps(0) {
    historique = new std::string[capacite];
    ajouterOperation("Création du compte avec solde " + std::to_string(s));
}

// Constructeur de copie (Copie profonde)
CompteBancaire::CompteBancaire(const CompteBancaire& other) : numero(other.numero), solde(other.solde), capacite(other.capacite), nbOps(other.nbOps) {
    historique = new std::string[capacite];
    std::copy(other.historique, other.historique + nbOps, historique);
}

// Constructeur de déplacement
CompteBancaire::CompteBancaire(CompteBancaire&& other) noexcept
    : numero(std::move(other.numero)), solde(other.solde), historique(other.historique), capacite(other.capacite), nbOps(other.nbOps) {
    other.historique = nullptr;
    other.nbOps = other.capacite = 0;
    other.solde = 0.0;
}

// Destructeur
CompteBancaire::~CompteBancaire() {
    delete[] historique;
}

// Méthodes de gestion du compte
void CompteBancaire::deposer(double montant) {
    if (montant <= 0) {
        std::cerr << "Montant de dépôt invalide" << std::endl;
        return;
    }
    solde += montant;
    ajouterOperation("Dépot de " + std::to_string(montant));
}

void CompteBancaire::retirer(double montant) {
    if (montant <= 0 || montant > solde) {
        std::cerr << "Retrait impossible" << std::endl;
        return;
    }
    solde -= montant;
    ajouterOperation("Retrait de " + std::to_string(montant));
}

void CompteBancaire::afficher() const {
    std::cout << "Compte " << numero << " - Solde : " << solde << std::endl;
    std::cout << "Historique des opérations :" << std::endl;
    for (std::size_t i = 0; i < nbOps; ++i) {
        std::cout << "  - " << historique[i] << std::endl;
    }
}
