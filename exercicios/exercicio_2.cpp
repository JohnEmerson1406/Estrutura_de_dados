#include <iostream>

using namespace std;

void furaFila(char lista[], int tamanho, char elemento, int posicao){
    char anterior;
    char aux;
    for (int i=0; i <= tamanho; i++){
        if (posicao == i){
            anterior = lista[i];
            lista[i] = elemento;
        }
        if (posicao < i){
            aux = anterior;
            anterior = lista[i];
            lista[i] = aux;
        }
    }
}


void retirarElemento(char lista[], int tamanho, char elemento){
    char novaLista[tamanho];
    int contador = 0;
    int posicao = 0;
    bool achou = false;

    while (posicao < tamanho){
        if (lista[posicao] == elemento){
            achou = true;
            break;
        }
        else{
            posicao++;
        }
    }
    if (achou){
        for (int i=0; i < tamanho; i++){
        if (lista[i] != elemento){
            novaLista[contador] = lista[i];
            contador++;
            }
        }
        for (int j=0; j < tamanho; j++){
            lista[j] = novaLista[j];
        }
    }
    else{
        cout << "O elemento nao existe!" << endl;
    }
}


void inserirOrdenado(char lista[], int tamanho, char elemento){
    int posicao;
    char anterior;
    char aux;
    for (int i=0; i < tamanho; i++){
        if (elemento < lista[i]){
            posicao = i;
            anterior = lista[i];
            lista[i] = elemento;
            break;
        }
    }
    for (int j=0; j < tamanho; j++){
        if (posicao < j){
            aux = anterior;
            anterior = lista[j];
            lista[j] = aux;
        }
    }
}


void novaListaInvertida(char lista[], int tamanho, char novaLista[]){
    char invertida[tamanho];
    int contador = tamanho-1;
    for (int i=0; i < tamanho; i++){
        invertida[i] = lista[contador];
        contador--;
    }
    for (int j=0; j < tamanho; j++){
        novaLista[j] = invertida[j];
    }
}


void listaInvertida(char lista[], int tamanho){
    char invertida[tamanho];
    int contador = tamanho-1;
    for (int i=0; i < tamanho; i++){
        invertida[i] = lista[contador];
        contador--;
    }
    for (int j=0; j < tamanho; j++){
        lista[j] = invertida[j];
    }
}


void imprimirLista(char lista[], int tamanho){ // funcao para imprimir os elementos da lista
    for (int i=0; i < tamanho; i++){
        cout << lista[i];
    }
    cout << endl;
}

int main()
{
    cout << "\nQuestao 1, letra A:" << endl;
    char lista[] = {'M', 'A', 'I', 'O'};
    imprimirLista(lista, 4);
    furaFila(lista, 4, 'R', 2); // insere o elemento 'R' na posicao 2
    imprimirLista(lista, 5);


    cout << "\n\nQuestao 1, letra B:" << endl;
    char lista2[] = {'M', 'A', 'R', 'I', 'O'};
    imprimirLista(lista2, 5);
    retirarElemento(lista2, 5, 'B'); // vai imprimir a mensagem de erro pois 'B' não existe na lista
    retirarElemento(lista2, 5, 'R'); // retira o elemento 'R' da lista
    imprimirLista(lista2, 4); // imprime a lista após remover o elemento 'R'


    cout << "\n\nQuestao 1, letra C:" << endl;
    char lista3[] = {'A', 'E', 'I', 'O', 'U'};
    imprimirLista(lista3, 5); // imprime a lista antes de inserir
    inserirOrdenado(lista3, 6, 'G'); // insere o elemento 'G' na lista de forma ordenada
    imprimirLista(lista3, 6); // imprime a lista depois de inserir


    cout << "\n\nQuestao 2:" << endl;
    char lista4[] = {'J', 'O', 'H', 'N'};
    char novaLista[4]; // cria uma novaLista vazia
    novaListaInvertida(lista4, 4, novaLista); // novaLista se torna o inverso de lista4
    imprimirLista(lista4, 4);
    imprimirLista(novaLista, 4);


    cout << "\n\nQuestao 3:" << endl;
    char lista5[] = {'A', 'M', 'O', 'R'};
    imprimirLista(lista5, 4); // imprime a lista5 antes de modifica-la
    listaInvertida(lista5, 4); // inverte a posicao dos elementos da lista5
    imprimirLista(lista5, 4); // imprime a lista5 invertida

    return 0;
}
