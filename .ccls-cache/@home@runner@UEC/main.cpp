#include <iostream>
#include <vector>
#include "classes.hpp"
using namespace std;
int main() {
  //Lutador* lu = (Lutador*) malloc(4 * sizeof(Lutador));
  
   //instanciando os objetos
 /* Lutador um("Pretty Boy","França",31,1.75,68.9,11,3,1);
  Lutador dois("Putscript","Brasil",29,1.68,57.8,14,2,3);
  Lutador tres("Snap Shadow","EUA",35,1.65,80.9,12,2,1);
  Lutador quatro("Dead Code","Austrália",28,1.93,81.6,13,0,2); */
  //um.apresentar();

  //instanciando em um vetor
  Lutador *lu = new Lutador[4]; 
  lu[0] = Lutador("Pretty Boy","França",31,1.75,68.9,11,3,1);
  lu[1] = Lutador("Putscript","Brasil",29,1.68,57.8,14,2,3);
  lu[2] = Lutador("Snap Shadow","EUA",35,1.65,80.9,12,2,1);
  lu[3] = Lutador("Dead Code","Austrália",28,1.93,81.6,13,0,2); 
  Luta luta1;
  luta1.marcarluta(lu[0],lu[1]);
  luta1.lutar();
}