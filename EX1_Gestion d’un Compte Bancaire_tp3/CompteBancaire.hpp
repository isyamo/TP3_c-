#ifndef COMPTE_BANCAIRE_HPP
#define COMPTE_BANCAIRE_HPP

#include <string>
#include <iostream>
#include <algorithm>

class CompteBancaire {
private:
    std::string numero;
    double solde;
    std::string* historique;
    std::size_t capacite;
    std::size_t nbOps;

    void agrandirHistorique();
    void ajouterOperation(const std::string& op);

public:
    // Constructeurs et Destructeur
    CompteBancaire();
    CompteBancaire(const std::string& num, double s);
    CompteBancaire(const CompteBancaire& other); // Constructeur de copie
    CompteBancaire(CompteBancaire&& other) noexcept; // Constructeur de déplacement
    ~CompteBancaire();

    // Méthodes de gestion
    void deposer(double montant);
    void retirer(double montant);
    void afficher() const;
};

#endif
