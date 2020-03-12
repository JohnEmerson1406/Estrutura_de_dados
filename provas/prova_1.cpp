#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX 10
#define tam 100

class Pilha{
    public:
      char pilha[MAX];
      int topo;
      Pilha(){
        topo = 0;
      }

      bool push(char n){
        if (esgotada()) return false;
        else
        {
          pilha[topo++] = n;
          return true;
        }

      }

      char nomeTopo(){
        int t;
        if (!vazia()){
          t=topo-1;
          return pilha[t];
        }
        else return '0';
      }

      char pop(){
        if (vazia()) return -1;
        else
        {
          char valor = pilha[--topo];
          return valor;
        }
      }

      bool esgotada()
      {
        return topo == MAX;
      }

      bool vazia()
      {
        return topo == 0;
      }

      bool listar()
      {
        if (vazia()) return false;
        else
        {
          putchar('\n');
          while (topo > 0)
          {
            topo--;
            printf("%03d [%6c]\n", topo, pilha[topo]);
          }
          return true;
        }
      }

      bool entrada(char c){
        return c == '{' || c == '[' || c == '(' ;
      }

      bool saida(char c){
        return c == '}' || c == ']' || c == ')' ;
      }

      bool bate(char c1,char c2){
        return (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']') || (c1 == '(' && c2 == ')');
      }

};


bool verify(char *frase){

	Pilha pilha;

  while (*frase){
    if (pilha.entrada(*frase)){
      pilha.push(*frase);
    } else if (pilha.saida(*frase)){
        if (!(pilha.bate(pilha.pop(), *frase))){
          return false;
        }
    }
    frase++;
  }

  if (pilha.topo == 0){
    return true;
  } else {
    return false;
  }
}

void mostrarVerify(char *expressao, bool verify){
  if (verify){
    cout << "A expressao " << expressao << " esta correta!" << endl;
  }
  else{
    cout << "A expressao " << expressao << " esta errada!" << endl;
  }
}

int main(){
  /*
  char str[tam];
  cout << "Digite uma expressao: " << endl;
  cin >> str;
  mostrarVerify(str, verify(str));
  */

  char *str = "a + [b + (2*c*d + 2)]";
  mostrarVerify(str, verify(str));

  char *str2 = "a + b + (2*c*d + 2)]";
  mostrarVerify(str2, verify(str2));

  char *str3 = "a +( b + 2*c*d + 2)]";
  mostrarVerify(str3, verify(str3));

  return 0;
}
