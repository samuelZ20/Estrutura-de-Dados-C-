#include <iostream>
using namespace std;

typedef int Dado;

class Pilha{

    private:
    int capacidade;
    Dado* dados;
    int tamanho;
    int topo;


    public:
    //construtor
    Pilha(int cap=20){
        capacidade = cap;
        tamanho=0;
        topo = -1;
        dados = new Dado[capacidade];
    }

    //destrutor
    ~Pilha(){
        delete[] dados;
    }

    //empilha NAO ENTENDI
    void empilha(Dado valor){
        dados[++topo] = valor;
        tamanho++;
    }

    //desempilha NAO ENTENDI
    Dado desempilha(){
        tamanho--;
        return dados[topo--];
    }

    //espiar o topo
    Dado espia(){
        return dados[topo];
    }

    //imprime toda a empilha (do fundo ao topo)
    void depura(){
        for(int i=0; i<tamanho; i++){
        cout << dados[i] << " ";

        if(i<tamanho-1){
            cout << " ";
        }
        }
        cout << endl;
    }

    //imprime tamanho e posicao do topo
    void info(){
        cout << tamanho << " " << topo << endl;
    }

};

int main(){
    Pilha pilha(20);

    //ENTRADA DOS 5 VALORES INICIAIS
    for(int i=0; i<5; i++){
        int valor;
        cin >> valor;
        pilha.empilha(valor);
    }

    //DESEMPILHAR 3 ELEMENTOS
    for(int i=0; i<3; i++){
        cout << pilha.desempilha() << " ";
    }
    cout << endl;

    //EMPILHAR MAIS 4 ELEMENTOS
    for(int i=0; i<4;i++){
        int valor;
        cin >> valor;
        pilha.empilha(valor);
    }

    //DESEMPILHAR 3 ELEMENTOS
    for(int i=0; i<3; i++){
        cout << pilha.desempilha()<< " ";
    }
    cout << endl;

    //IMPRIME O TOPO
    cout << pilha.espia() << endl;

    //IMPRIME OS ELEMENTOS RESTANTES
    pilha.depura();

    //IMPRIME TAMANHO E POSIÇAO DO TOPO
    pilha.info();

    return 0;

}