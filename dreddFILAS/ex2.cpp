#include <iostream>
using namespace std;

typedef int Dados;

class Filas{

    private:
    int tamanho;
    int capacidade;
    int inicio;
    int fim;
    Dados* dados;

    public:

    //construtor
    Filas(int cap){
        capacidade = cap;
        tamanho=0;
        inicio=0;
        fim=-1;
        dados = new Dados[capacidade];
    }

    //destrutor
    ~Filas(){
        delete[] dados;
    }

    //verificar se está cheia
    bool cheia(){
        return tamanho==capacidade;
    }

    //verificar se está vazia 
    bool vazia(){
        return tamanho==0;
    }

    //enfileirar/push
    void push(int valor){
        if(cheia()){
            return;
        }

        fim = (fim+1)%capacidade;
        dados[fim] = valor;
        tamanho++;
    }

    //desinfileirar/pop
    int pop(){
        if(vazia()){
            return -1;
        }
        int removido = dados[inicio];
        inicio = (inicio+1)%capacidade;
        tamanho--;
        return removido;
    }

    //atributos
    void atributos(){
        cout << "tamanho=" << tamanho << " " << "capacidade=" << capacidade << " " << "inicio=" << inicio << " " << "fim=" << fim << endl;
        for(int i=0; i<tamanho; i++){
            int pos=(inicio+i)%capacidade;
            cout << dados[pos] << " ";
        }
        cout << endl;
    }

};

int main(){
int n;
cin >> n;
Filas f(n);
char letra;


do{
    //cout << "t - terminar a execucao" << endl;
    //cout << "e - enfileirar um valor" << endl;
    //cout << "d - desinfileirar um valor" << endl;
    //cout << "i - atributos da fila" << endl;

    cin >> letra;

    if(letra == 'e'){
        int valor;
        cin >> valor;
        f.push(valor);
    }

    else if(letra == 'd'){
        int removido = f.pop();
        if(removido!=-1){
            cout << removido << endl;
        }
    }

    else if(letra == 'i'){
        f.atributos();
    }

}while(letra!='t');

    return 0;
}