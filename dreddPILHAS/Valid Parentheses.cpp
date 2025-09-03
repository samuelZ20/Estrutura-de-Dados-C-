#include <iostream>
using namespace std;

typedef int Dados;

class Pilhas{

    private:
    int tamanho;
    int capacidade;
    int topo;
    Dados* dados;

    public:

    //construtor
    Pilhas(int cap){
        capacidade = cap;
        topo=-1;
        tamanho=0;
        dados = new Dados[capacidade];
    }

    //destrutor
    ~Pilhas(){
        delete[]dados;
    }

    //empilhar//push
    void push(int valor){
        topo++;
        dados[topo]= valor;
        tamanho++;
    }

    //desempilhar
    Dados pop(){
        if(vazia()){
            cout << "Pilha vazia" << endl;
            return -1;
        }
        tamanho--;
        return dados[topo--];
    }

    //verficar se está vazia
    bool vazia(){
        return tamanho==0;
    }

    //verificar topo
    Dados top(){
        return dados[topo];
    }
};

    int main(){
    cout << "Insira o texto: ";
    char texto[255];
    cin.getline(texto,255);

    Pilhas p1(255);

    int i=0;
    while(texto[i]!='\0'){
    //se o caracter for '(', empilhar
        if(texto[i]=='('){
            p1.push(texto[i]);
        }

        else if(texto[i]==')'){
            p1.pop();
        }

        else if(texto[i]=='['){
            p1.push(texto[i]);
        }

        else if(texto[i]==']'){
            p1.pop();
        }

        else if(texto[i]=='{'){
            p1.push(texto[i]);
        }

        else if(texto[i]=='}'){
            p1.pop();
        }
        i++;
    }

    //se a pilha estiver vazia, quer dizer que tem os seus correspondentes

    if(p1.vazia()){
        cout << "true" << endl;
    }

    else{
        cout << "false" << endl;
    }
    
    return 0;
    }