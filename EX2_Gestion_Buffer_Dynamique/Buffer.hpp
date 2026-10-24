#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include <algorithm>

class Buffer {
private:
    char* data;
    std::size_t taille;

public:
    // Constructeur par défaut (buffer vide)
    Buffer();

    // Constructeur paramétré
    explicit Buffer(std::size_t t);

    // Constructeur de copie
    Buffer(const Buffer& other);

    // Constructeur de déplacement
    Buffer(Buffer&& other) noexcept;

    // Opérateur d'assignation de copie
    Buffer& operator=(const Buffer& other);

    // Opérateur d'assignation de déplacement
    Buffer& operator=(Buffer&& other) noexcept;

    // Destructeur
    ~Buffer();

    // Méthodes d'accès simple
    char* getData() const;
    std::size_t getTaille() const;
};

#endif
