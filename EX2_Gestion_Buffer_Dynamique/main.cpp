#include <iostream>
#include <utility> // Nécessaire pour std::move
#include "Buffer.hpp"
#include "BufferRAII.hpp"

int main() {
    std::cout << "<<< 1. Test de la classe Buffer >>>" << std::endl;
    Buffer b1(128);               // allocation
    Buffer b2 = b1;               // copie
    Buffer b3 = std::move(b1);    // déplacement
    b2 = b3;                      // assignation copie
    b3 = Buffer(64);              // assignation déplacement via rvalue

    std::cout << "\n<<< 2. Test de la classe BufferRAII  >>> " << std::endl;
    BufferRAII b(256);
    std::cout << "Buffer de " << b.size() << " octets alloué" << std::endl;

    std::cout << "\nFin du programme." << std::endl;

    return 0;
}
