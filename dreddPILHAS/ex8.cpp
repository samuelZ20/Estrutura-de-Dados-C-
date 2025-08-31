#include <iostream>
using namespace std;

typedef int Dados;

class Pilhas{

    private:
    int tamanho;
    int topo;
    int capacidade;
    Dados* dados;

    void redimensionar(){
        int novaCapacidade = 2*capacidade;
        Dados* novo = new Dados[novaCapacidade];

        for(int i=0; i<tamanho; i++){
            novo[i] = dados[i];
        }

        delete[] dados;
        dados = novo;
        capacidade = novaCapacidade;
    }

    public:
    //construtor
    Pilhas(int cap=10){
        capacidade = cap;
        tamanho=0;
        topo=-1;
        dados = new Dados[capacidade];
    }

    //destrutor
    ~Pilhas(){
        delete[] dados;
    }

    //empilhar
    void push(int valor){
        if(tamanho==capacidade){
            redimensionar();
        }
        topo++;
        dados[topo] = valor;
        tamanho++;
    }

    //desempilhar
    Dados pop(){
        if(vazia()){
            cout << "VAZIA" << endl;
            return -1;
        }
        
        tamanho--;
        return dados[topo--];
    }

    //verificar se a pilha está vazia
    bool vazia(){
        return tamanho==0;
    }


    //imprimir todos os valores armazenados na pilha
    void info(){
        for(int i=0; i<=topo; i++){
            cout << dados[i] << " ";
        }
        cout << endl;
    }

    //comsultar o topo sem remove lo 
    int peek(){
        if(vazia()) return -1;
        return dados[topo];
    }
};


    int main(){

        Pilhas pilha(10); //pilha principal
        Pilhas menores(10); //pilha auxiliar para o menor valor
        char letra;
        
        while(cin >> letra){
            if(letra == 'e'){
                int valor;
                cin >> valor;
                pilha.push(valor);

                //atualiza pilha de menores
                if(menores.vazia() or valor<=menores.peek()){
                    menores.push(valor);
                }
            }


            else if(letra=='d'){
                if(pilha.vazia()){
                    cout << "VAZIA"<< endl;
                }

                else{
                    int removido = pilha.pop();
                    cout << removido << endl;
                

                //se era o menor, remove tambem da pilha auxiliar
                if(!menores.vazia() and removido == menores.peek()){
                    menores.pop();
                }
            }
            }

            else if(letra=='m'){
                if(pilha.vazia()){
                    cout << "VAZIA" << endl;
                }
                else{
                    cout << menores.peek() << endl;
                }
            }

            else if(letra == 's'){

            }
        }











        return 0;
    }