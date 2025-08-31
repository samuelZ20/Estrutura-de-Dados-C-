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
        delete[]dados;
    }

    //verificar está cheia
    bool cheia(){
        return tamanho==capacidade;
    }

    //verificar está vazia
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

    // remove uma da outra
    void remover(Filas &F2){
        
        int tamanhoOriginal = tamanho;

        //percorre todos os elementos originais de F1
        for(int i=0; i<tamanhoOriginal; i++){
            int valor = pop();

            bool estaEmF2 = false;

        //percorre F2 inteiro para verificar se "valor" está nela
        int tamanhoF2 = F2.tamanho;
        for(int j=0;j<tamanhoF2;j++){
            int v=F2.pop(); // remove do inicio de F2

        //achou em F2, precisa remover
            if(v==valor){
                estaEmF2 = true;
            }
        
        //Devolve o elemento ao final de F2 para manter ela intacta
            F2.push(v);
        }

        //Se o valor nao estava em F2, volta para o fim de F1
        if(!estaEmF2){
            
            push(valor);
        }
    }
}

    void imprimir(){
        for(int i=0; i<tamanho; i++){
            int pos = (inicio+i)%capacidade;
            cout << dados[pos] << " ";
        }
        cout << endl;
    }
};

int main(){
    //ut << "Entre com o numero de elementos de F1: ";
    int n;
    cin >> n;

    Filas f1(n);
    //Lendo os valores de f1
    for(int i=0; i<n; i++){
        int valor;
        cin >> valor;
        f1.push(valor);
    }

    //ut << "Entre com o numero de elementos de F2: ";
    int k;
    cin >> k;

    Filas f2(k);
    //Lendo os valores de f2
    for(int i=0; i<k; i++){
        int valor;
        cin >> valor;
        f2.push(valor);
    }

    //remover de f1 os elementos que estao em f2
    f1.remover(f2);

    //imprimir o final
    f1.imprimir();

    return 0;
}