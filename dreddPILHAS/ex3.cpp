#include <iostream>
using namespace std;

typedef int Dados;

class Pilhas{

    private:
    int tamanho;
    int topo;
    int capacidade;
    Dados* dados;

    public:
    //construtor
    Pilhas(int cap){
        capacidade=cap;
        tamanho=0;
        topo=-1;
        dados=new Dados[capacidade];
    }

    //destrutor
    ~Pilhas(){
        delete[]dados;
    }

    //verificar se está vazia
    bool vazia(){
        return tamanho==0;
    }

    //empilhar
    void push(int valor){
        topo++;
        dados[topo]=valor;
        tamanho++;
    }

    //desempilhar
    Dados pop(){
        if(vazia()){
            return -1;
        }
        tamanho--;
        return dados[topo--];
    }

    //ver topo
    Dados top(){
        return dados[topo];
    }

};

    int main(){
    
    char texto[255];
    cin.getline(texto,255);

    Pilhas pilha(255);

    int i=0;
    while(texto[i]!='\0'){
        if(texto[i]=='('){
            pilha.push(i);
        }

        else if(texto[i]==')'){
            if(pilha.vazia()){
                cout << i << endl;
                return 0;
            }
            else{
            pilha.pop();
            }
        }
        i++;
    }

    if(pilha.vazia()){
        cout << "correto" << endl;
    }

    else{
        cout << pilha.top() << endl;
    }

    





















        return 0;
    }