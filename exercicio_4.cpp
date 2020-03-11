#include <iostream>
#include <vector>

using namespace std;

void listaInvertida(vector<char> &lista1, vector<char> &lista2){
    int contador = 1;
    unsigned int i;
    for (i=0; i < lista1.size(); i++){
        lista2.push_back(lista1.at(lista1.size() - contador));
        contador++;
    }
}

void listaInvertida(vector<char> &lista1){
    int ultimo = lista1.size();

    unsigned int i;
    for (i=0; i < lista1.size() / 2; i++){
        char auxiliar = lista1.at(i);
        lista1.at(i) = lista1.at(ultimo - 1);
        lista1.at(ultimo - 1) = auxiliar;
        ultimo--;
    }
}

void imprimirVector(vector<char> &lista){
    unsigned int i;
    for(i=0; i<lista.size(); i++){
        cout << lista.at(i);
    }
    cout << endl;
}

int main()
{
    cout << "\n--- Questao 2 usando vector ---" << endl;

    vector<char> lista1;

    lista1.push_back('A');
    lista1.push_back('M');
    lista1.push_back('O');
    lista1.push_back('R');

    vector<char> lista2;

    listaInvertida(lista1, lista2);

    cout << "\nLista1:" << endl;
    imprimirVector(lista1);

    cout << "\nLista2:" << endl;
    imprimirVector(lista2);



    cout << "\n\n--- Questao 3 usando vector ---" << endl;
    cout << "\nLista1 antes de inverter:" << endl;
    imprimirVector(lista1);

    listaInvertida(lista1);

    cout << "\nLista1 depois de inverter:" << endl;
    imprimirVector(lista1);

    return 0;
}
