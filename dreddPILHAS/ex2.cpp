#include <iostream>
using namespace std;

typedef int Dados;

class Pilhas{

    private:
    int capacidade;
    int tamanho;
    int topo;
    Dados* dados;

    public:
    //construtor
    Pilhas(int cap){
        capacidade = cap;
        tamanho=0;
        topo=-1;
        dados= new Dados[capacidade];
    }

    //destrutor
    ~Pilhas(){
        delete[] dados;
    }
    
    //empilhar
    void push(Dados valor){
        topo++;
        dados[topo] = valor;
        tamanho++;
    }

    //desempilhar
    Dados pop(){
        tamanho--;
        return dados[topo--];
    }

    //verificar se está vazia
    bool vazia(){
        return tamanho==0;
    }

    //ESPIAR O TOPO
    Dados top(){
        return dados[topo];
    }

    //ver o tamanho
    int size(){
        return tamanho;
    }

    //METODO PARA ORDENAR A PILHA USANDO PILHA AUXILIAR
    void ordenar(){
        Pilhas aux(capacidade);
        while(!vazia()){
            Dados temp = pop();

            while(!aux.vazia() and aux.top()<temp){
                push(aux.pop());
            }
            aux.push(temp);
        }

        while(!aux.vazia()){
            push(aux.pop());
        }
    }

    //Mostrar a pilha sem destruir
    void print(){
        for(int i=0; i<=topo; i++){
            cout << dados[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int n;
    cin >> n;

    Pilhas pilhas(n);

    //Recebendo os n valores da pilha e empilhando-as
    for(int i=0; i<n; i++){
        int valor;
        cin >> valor;
        pilhas.push(valor);
    }

    //oredenando
    pilhas.ordenar();

    //mostrando a pilha
    pilhas.print();

    return 0;
}