#include "Buffer.hpp"

// Constructeur par défaut
Buffer::Buffer() : data(nullptr), taille(0) {}

// Constructeur paramétré
Buffer::Buffer(std::size_t t) : data(new char[t]), taille(t) {
    std::fill_n(data, taille, 0);
    std::cout << "Buffer de " << taille << " octets créé" << std::endl;
}

// Constructeur de copie
Buffer::Buffer(const Buffer& other) : data(new char[other.taille]), taille(other.taille) {
    std::copy(other.data, other.data + taille, data);
    std::cout << "Constructeur de copie du buffer" << std::endl;
}

// Constructeur de déplacement
Buffer::Buffer(Buffer&& other) noexcept : data(other.data), taille(other.taille) {
    other.data = nullptr;
    other.taille = 0;
    std::cout << "Constructeur de déplacement du buffer" << std::endl;
}

// Opérateur d'assignation de copie
Buffer& Buffer::operator=(const Buffer& other) {
    if (this != &other) {
        delete[] data;
        taille = other.taille;
        data = new char[taille];
        std::copy(other.data, other.data + taille, data);
    }
    return *this;
}

// Opérateur d'assignation de déplacement
Buffer& Buffer::operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        taille = other.taille;
        other.data = nullptr;
        other.taille = 0;
    }
    return *this;
}

// Destructeur
Buffer::~Buffer() {
    delete[] data;
    std::cout << "Destruction du buffer" << std::endl;
}

// Méthodes d'accès simple
char* Buffer::getData() const {
    return data;
}

std::size_t Buffer::getTaille() const {
    return taille;
}
