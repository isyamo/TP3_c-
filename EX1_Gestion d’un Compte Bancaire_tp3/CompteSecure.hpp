#ifndef COMPTE_SECURE_HPP
#define COMPTE_SECURE_HPP

#include <stdexcept>

class CompteSecure {
private:
    double solde;

public:
    explicit CompteSecure(double soldeInitial) {
        if (soldeInitial < 0) {
            throw std::invalid_argument("Solde initial négatif");
        }
        solde = soldeInitial;
    }

    double getSolde() const {
        return solde;
    }
};

#endif
