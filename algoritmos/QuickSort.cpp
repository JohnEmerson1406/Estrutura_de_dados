#include <bits/stdc++.h>

using namespace std;

void quick(vector<int> &vetor, int inicio, int fim) {
  int pivo, aux, i, j, meio;
  i = inicio;
  j = fim;
  meio = (int) ((i+j)/2);
  pivo = vetor[meio];

  do{
    while(vetor[i] < pivo) i++;
    while(vetor[j] > pivo) j--;

    if (i <= j) {
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
      i++;
      j--;
    }
  }while(j > i);

  if (inicio < j) {
    quick(vetor, inicio, j);
  }
  if (i < fim) {
    quick(vetor, i, fim);
  }
}

int main(){
  vector<int> vetor;

  vetor.push_back(5);
  vetor.push_back(8);
  vetor.push_back(2);
  vetor.push_back(3);
  vetor.push_back(1);

  for (int i=0; i < vetor.size(); i++) {
    cout << vetor[i] << endl;
  }
  cout << endl;

  quick(vetor, 0, 4);

  for (int i=0; i < vetor.size(); i++) {
    cout << vetor[i] << endl;
  }
  cout << endl;

  return 0;
}
