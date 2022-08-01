#ifndef CLASSES_HPP_INCLUDED
#define CLASSES_HPP_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class Lutador{
  private:
    string nome;
    string nacionalidade;
    int idade;
    float altura;
    float peso;
    string categoria;
    int vitorias;
    int derrotas;
    int empates;
    void setnome(string nome);
    string getnacionalidade();
    void setnacionalidade(string nacionalidade);
    int getidade();
    void setidade(int idade);
    float getaltura();
    void setaltura(float altura);
    float getpeso();
    void setpeso(float peso);
    void setcategoria(float peso); //a categoria é setada pelo peso
    int getvitorias();
    void setvitorias(int vitorias);
    int getderrotas();
    void setderrotas(int derrotas);
    int getempates();
    void setempates(int empates);

  public:
    Lutador() = default; // serve para instaciar em um vetor, ja inicializando
    Lutador(string no, string na, int id, float al, float pe, int vi, int de, int em);
    string getcategoria();
    string getnome();
    void apresentar();
    void status();
    void ganharLuta();
    void perderLuta();
    void empatarLuta();
};

class Luta{
  private:
    Lutador desafiado; //classe desafiante é um obj da classe lutador
    Lutador desafiante;
    int round;
    bool aprovada;
    Lutador getdesafiado();
    void setdesafiado(Lutador dd);
    Lutador getdesafiante();
    void setdesafiante(Lutador df);
    int getround();
    void setround(int r);
    bool getaprovada();
    void setaprovada(bool ap);
    
  public:
   // Luta();
    void marcarluta(Lutador l1, Lutador l2);
    void lutar();
};

#endif // CLASSES_HPP_INCLUDED
