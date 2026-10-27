//
//  Pilha.h
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef __Pilha__
#define __Pilha__

#include <stdexcept>
#include <optional>
#include <sstream>
#include <string>
template <typename T>
class Pilha
{
private:
    T* elementos;
    int capacidade;
    int quantidade;
    
public:
    Pilha(int cap)
    {
        this->quantidade = 0;
        this->capacidade = cap;
        elementos = new T[this->capacidade];
    }
    
    ~Pilha()
    {
        delete [] elementos;
    }
    
    int tamanho() const
    {
        return this->quantidade;
    }

    bool vazia() const
    {
        return this->quantidade == 0;
    }

    bool cheia() const
    {
        return this->quantidade == this->capacidade;
    }

    std::optional<T> topo() const
    {
        if (this->quantidade == 0)
        {
            return std::nullopt;
        }

        return elementos[this->quantidade - 1];
    }

    void empilhar(T elemento)
    {
        
        if (this->quantidade == this->capacidade)
        {
            throw std::runtime_error("Pilha cheia.");
        }

        elementos[this->quantidade] = elemento;
        this->quantidade++;
    }

    void desempilhar()
    {
        if (this->quantidade == 0)
        {
            throw std::runtime_error("Pilha vazia.");
        }

        this->quantidade--;
    }

    std::string imprimir() const
    {
        std::stringstream resultado;
        resultado << "{ ";
        for (int i = 0; i < tamanho(); ++i) 
        {
            resultado << elementos[i] << " ";
        }
        resultado << "}";
        return resultado.str();
    }
        
};
#endif
