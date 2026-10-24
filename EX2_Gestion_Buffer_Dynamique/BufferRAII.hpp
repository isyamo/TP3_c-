#ifndef BUFFER_RAII_HPP
#define BUFFER_RAII_HPP

#include <memory>
#include <iostream>
#include <algorithm>

class BufferRAII {
private:
    std::unique_ptr<char[]> data;
    std::size_t taille;

public:
    explicit BufferRAII(std::size_t t) : data(new char[t]), taille(t) {
        std::fill_n(data.get(), taille, 0);
    }

    // Aucun destructeur nécessaire : unique_ptr se charge de la libération
    char* get() const { return data.get(); }
    std::size_t size() const { return taille; }
};

#endif
