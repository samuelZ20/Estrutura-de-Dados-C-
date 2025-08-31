#include <iostream>
using namespace std;

typedef int Dado;

class Pilha {
private:
    int capacidade;
    int tamanho;
    int topo;
    Dado* dados;

    void redimensionar(){
        int novaCapacidade = 2 * capacidade;
        Dado* novo = new Dado[novaCapacidade];
        for(int i=0; i<tamanho; i++){
            novo[i] = dados[i];
            }
        delete[] dados;
        dados=novo;
        capacidade = novaCapacidade;
    }

public:
    // construtor
    Pilha(int cap = 10) {
        capacidade = cap;
        tamanho = 0;
        topo = -1;
        dados = new Dado[capacidade];
    }

    // destrutor
    ~Pilha() {
        delete[] dados;
    }

    // empilhar
    void push(Dado valor) {
        if (tamanho == capacidade) {
            redimensionar();
        }
        topo++;
        dados[topo] = valor;
        tamanho++;
    }

    // desempilhar
    Dado pop() {
        if (vazia()) {
            cerr << "erro" << endl; // saída de erro mínima
            return -1;
        }
        tamanho--;
        return dados[topo--];
    }

    // olhar topo
    Dado topValor() {
        if (vazia()) {
            cerr << "erro" << endl;
            return -1;
        }
        return dados[topo];
    }

    // verificar se está vazia
    bool vazia() {
        return tamanho == 0;
    }

    // obter tamanho
    int size() {
        return tamanho;
    }

    // limpar
    void limpar() {
        while (!vazia()) {
            pop();
        }
    }
};

int main() {
    Pilha pilha(10);
    char letra;

    while (cin >> letra) {
        if (letra == 'i') {
            int valor;
            cin >> valor;
            pilha.push(valor);
        } 
        else if (letra == 'r') {
            int removido = pilha.pop();
            if (removido != -1) cout << removido << endl;
        } 
        else if (letra == 'l') {
            pilha.limpar();
        } 
        else if (letra == 't') {
            cout << pilha.size() << endl;
        } 
        else if (letra == 'e') {
            int topo = pilha.topValor();
            if (topo != -1) cout << topo << endl;
        } 
        else if (letra == 'f') {
            bool primeiro = true;
            while (!pilha.vazia()) {
                if (!primeiro) cout << " ";
                cout << pilha.pop();
                primeiro = false;
            }
            cout << endl;
            break;
        }
    }

    return 0;
}
