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
        capacidade = cap;
        tamanho=0;
        topo=-1;
        dados=new Dados[capacidade];
    }

    //destrutor
    ~Pilhas(){
        delete[] dados;
    }

    //empilhar
    void push(int valor){
        topo++;
        dados[topo] = valor;
        tamanho++;
    }

    //desempilhar
    Dados pop(){
        tamanho--;
        return dados[topo--];
    }

    //verificar se está vazia;
    bool vazia(){
        return tamanho==0;
    }

    //inverter a pilha para a original
    void inverter(){
        Pilhas p2(capacidade);
        Pilhas p3(capacidade);

        //Desempilhar da atual e empilhar em P2
        while(!vazia()){
            p2.push(pop());
        }

        //Desempilhar de p2 e passar para p3
        while(!p2.vazia()){
            p3.push(p2.pop());
        }

        //Desempilhar de p3 e passar para a original
        while(!p3.vazia()){
            push(p3.pop());
        }
    }

};

int main(){
    int n;
    cin>>n;

    Pilhas p1(n);

    //lendo os elementos
    for(int i=0; i<n; i++){
        int valor;
        cin >> valor;
        p1.push(valor);
    }

    //inverter a pilha
    p1.inverter();

    //imprime desempilhando
    while(!p1.vazia()){
        cout << p1.pop() << " ";
    }
    cout << endl;

    return 0;
}