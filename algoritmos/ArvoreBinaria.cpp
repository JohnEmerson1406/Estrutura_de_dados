#include <bits/stdc++.h>

using namespace std;

class No{
  public:
    int valor;
    No *left;
    No *right;

    No(int v) {
      valor = v;
      left = NULL;
      right = NULL;
    }
};

class Arvore{
  public:
    No *raiz;

    Arvore() {
      raiz = NULL;
    }

    bool isEmpty() {
      return raiz == NULL;
    }

    void insere(No *arv, No *novo) {
      if(isEmpty()) {
        raiz = novo;
      }
      else {
        No *percorre = raiz;
        while(percorre != NULL) {
          if(novo->valor > percorre->valor) {
            if(percorre->right == NULL) {
              percorre->right = novo;
              break;
            }
            else {
              percorre = percorre->right;
            }
          }

          if(novo->valor < percorre->valor) {
            if(percorre->left == NULL) {
              percorre->left = novo;
              break;
            }
            else {
              percorre = percorre->left;
            }
          }
        }
      }
    }

    void imprime(No *arv) {
      if(isEmpty()) {
        cout << "<vazio>";
      }
      else {
        if(arv != NULL) {
          cout << "<" << arv->valor;
          imprime(arv->left);
          imprime(arv->right);
          cout << ">";
        }
        else {
          cout << "<>";
        }
      }
    }

    void liberaFilho(int procurado, No *n) {
      No *aux = NULL;

      if(raiz->valor == procurado) {
        aux = raiz;
        raiz = NULL;
        libera(aux);
      }
      else {
        if(n->right != NULL) {
          if(n->right->valor == procurado) {
            No *prox = n->right;
            n->right = NULL;
            libera(prox);
          }
          else {
            liberaFilho(procurado, n->right);
          }
        }
        if(n->left != NULL) {
          if(n->left->valor == procurado) {
            No *prox = n->left;
            n->left = NULL;
            libera(prox);
          }
          else {
            liberaFilho(procurado, n->left);
          }
        }
      }
    }

    void libera(No *pai) {
      if(pai != NULL) {
        if(pai->left != NULL) {
          libera(pai->left);
        }
        if(pai->right != NULL) {
          libera(pai->right);
        }
        free(pai);
      }
    }
};

int main() {
  Arvore *arv = new Arvore();

  No *n1 = new No(10);
  arv->insere(arv->raiz, n1);
  No *n2 = new No(15);
  arv->insere(arv->raiz, n2);
  No *n3 = new No(5);
  arv->insere(arv->raiz, n3);
  No *n4 = new No(7);
  arv->insere(arv->raiz, n4);

  arv->liberaFilho(5, arv->raiz);

  arv->imprime(arv->raiz);

  return 0;
}
