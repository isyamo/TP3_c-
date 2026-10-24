#include <iostream>
#include <utility> // Nécessaire pour std::move
#include "CompteBancaire.hpp"
#include "CompteSecure.hpp"

int main() {
    std::cout << "<<< 1. Test de la classe CompteBancaire >>>" << std::endl;
    CompteBancaire c1("FR123456", 500.0);
    c1.deposer(200);
    c1.retirer(150);

    std::cout << "<<< Affichage de c1 >>>" << std::endl;
    c1.afficher();

    // Test du constructeur de copie
    std::cout << "\n<<< Test de copie (c2 = c1) >>>" << std::endl;
    CompteBancaire c2 = c1;
    c2.afficher();

    // Test du déplacement
    std::cout << "\n<<< Test de déplacement (c3 = std::move(c1)) >>>" << std::endl;
    CompteBancaire c3 = std::move(c1);
    c3.afficher();


    std::cout << "\n\n<<< 2. Test de la classe CompteSecure (Gestion des exceptions) >>>" << std::endl;
    try {
        // Test avec un solde valide
        CompteSecure monCompte(1000.0);
        std::cout << "Compte créé avec succès. Solde : " << monCompte.getSolde() << std::endl;

        // Test avec un solde invalide (provoquera une exception)
        std::cout << "Tentative de création d'un compte avec solde négatif (-50.0)..." << std::endl;
        CompteSecure compteInvalide(-50.0);

    } catch (const std::exception& e) {
        std::cerr << "Erreur attrapée : " << e.what() << std::endl;
    }

    return 0;
}
