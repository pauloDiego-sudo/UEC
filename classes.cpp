#include "classes.hpp"

    std::string Lutador::getnome(){
      return this->nome;
    }
    void Lutador::setnome(string nome){
      this->nome = nome;
    }
    std::string Lutador::getnacionalidade(){
      return this->nacionalidade;
    }
    void Lutador::setnacionalidade(string nacionalidade){
      this->nacionalidade = nacionalidade;
    }
    int Lutador::getidade(){
      return this->idade;
    }
    void Lutador:: setidade(int idade){
      this->idade = idade;
    }
    float Lutador:: getaltura(){
      return this->altura;
    }
    void Lutador:: setaltura(float altura){
      this->altura = altura;
    }
    float Lutador::getpeso(){
      return this->peso;
    }
    void Lutador:: setpeso(float peso){
      this->peso = peso;
      this->setcategoria(peso);
    }
    std::string Lutador:: getcategoria(){
      return this->categoria;
    }
    void Lutador:: setcategoria(float peso){
      if(peso<52.2){
        this->categoria = "Invalido";
      }
      else if(peso<= 70.3){
        this->categoria = "Leve";
      }
      else if(peso <= 83.9){
        this->categoria = "Médio";
      }
      else if(peso <= 120.2){
        this->categoria = "Pesado";
      }
      else{
        this->categoria = "Invalido";
      }
    }
    int Lutador:: getvitorias(){
      return this->vitorias;
    }
    void Lutador:: setvitorias(int vitorias){
      this->vitorias = vitorias;
    }
    int Lutador:: getderrotas(){
      return this->derrotas;
    }
    void Lutador:: setderrotas(int derrotas){
      this->derrotas = derrotas;
    }
    int Lutador:: getempates(){
      return this->empates;
    }
    void Lutador::setempates(int empates){
      this->empates = empates;
    }

  // INTERFACE
    Lutador::Lutador(string no, string na, int id, float al, float pe, int vi, int de, int em){
      this->setnome(no);
      this->setnacionalidade(na);
      this->setidade(id);
      this->setaltura(al);
      this->setpeso(pe);
      this->setvitorias(vi);
      this->setderrotas(de);
      this->setempates(em);
    }
    void Lutador:: ganharLuta(){
      this->setvitorias(getvitorias()+1);
    }
    void Lutador:: perderLuta(){
      this->setderrotas(getderrotas()+1);
    }
    void Lutador:: empatarLuta(){
      this->setempates(getempates()+1);
    }
    void Lutador:: apresentar(){
      cout << "-----------------------------" << endl;
      cout<<"Lutador: " << getnome() << "," << getidade()<<" anos ," << getaltura() <<" m de altura" << endl;
      cout<<"Origem: " << getnacionalidade() << endl;
      cout<<"Pesando: " << getpeso() << endl;
      cout<<"Categoria: " << getcategoria() << endl;
      cout<<"Ganhou: " << getvitorias() << endl;
      cout<<"Perdeu: " << getderrotas() << endl;
      cout<<"Empatou: " << getempates() << endl;
    }
    void Lutador:: status(){
      cout<<"Nome: " << getnome() << endl;
      cout << getidade()<<" anos " << endl;
      cout <<  getaltura() <<" m de altura" <<endl;
      cout<<"Origem: " << getnacionalidade() << endl;
      cout<<"Pesando: " << getpeso() << endl;
      cout<<"Ganhou: " << getvitorias() << endl;
      cout<<"Perdeu: " << getderrotas() << endl;
      cout<<"Empatou: " << getempates() << endl;
    }

    //métodos da luta
    Lutador Luta:: getdesafiado(){
      return this->desafiado;
    }
    void Luta::setdesafiado(Lutador dd){
      this->desafiado = dd;
    }
    Lutador Luta:: getdesafiante(){
      return this->desafiante;
    }
    void Luta:: setdesafiante(Lutador df){
      this->desafiante=df;
    }
    int Luta:: getround(){
      return this->round;
    }
    void Luta:: setround(int r){
      this->round=r;
    }
    bool Luta:: getaprovada(){
      return this->aprovada;
    }
    void Luta:: setaprovada(bool ap){
      this->aprovada=ap;
    }
    void Luta:: marcarluta(Lutador l1, Lutador l2){
      if(l1.getcategoria()==l2.getcategoria() && l1.getnome()!=l2.getnome()){
        this->setaprovada(true);
        this->setdesafiante(l1);
        this->setdesafiado(l2);
      }
      else{
        this->setaprovada(false);
      }
    }
    void Luta:: lutar(){
      if(this->getaprovada()==true){
        cout<<"####DESAFIADO####"<<endl;
        this->desafiado.apresentar();
        cout<<"####DESAFIANTE####"<<endl;
        this->desafiante.apresentar();
        time_t t;
        srand((unsigned) time(&t)); //iniciando o gerador de numeros randomicos
        int vencedor=rand()%3; //inteiro randomico entre 0 e 2
        cout<<"==========RESULTADO DA LUTA=========="<<endl;        
        switch(vencedor){
          case 0: //empate
            cout<<"Empatou"<<endl;
            this->desafiado.empatarLuta();
            this->desafiante.empatarLuta();
          break;
          case 1: //ganhou desafiante
            cout<<"VENCEDOR: "<< this->desafiante.getnome()<<endl;
            this->desafiante.ganharLuta();
            this->desafiado.perderLuta();
          break;
          case 2: //ganhou desafiado
            cout<<"VENCEDOR: "<< this->desafiado.getnome()<<endl;
            this->desafiado.ganharLuta();
            this->desafiante.perderLuta();
          break;
        }
      cout<<"==========================="<<endl;   
        this->desafiante.status();
        this->desafiado.status();
      }
      else{
        cout<<"Luta não pode acontecer"<<endl;
      }
    }