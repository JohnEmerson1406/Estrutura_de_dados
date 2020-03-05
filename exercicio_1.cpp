#include <iostream>
#include <string.h>

using namespace std;

int strpos(char *s1, char *s2){
    int contador = 0; // conta as posições da string s1
    while (*s1){ // percorre s1
        if (*s1 == *s2){
            char *x1 = s1;
            char *x2 = s2;
            int x = 0; // variável de controle de sequencia
            while (*x2){ // percorre s2
                if (*x2 == *x1){
                    x++;
                }
                x1++;
                x2++;
            }
            int tamanho = strlen(s2);
            if (x >= tamanho){ //verifica se sequencia de s2 foi encontrada em s1
                return contador; // retorna a posicao inicial da primeira ocorrencia de s2 dentro de s1
            }
        }
        ++contador;
        s1++;
    }
    return -1; // retorna -1 caso não ache s2 em s1
}

void strcat(char *s1, char *s2){
    while (*s1){ // percorre s1
        cout << *s1; //imprime os elementos de s1
        s1++; // adiciona ao ponteiro de s1
    }
    while (*s2){ // percorre s2
        cout << *s2; // imprime os elementos de s2
        s2++; // adiciona ao ponteiro de s2
    }
}

void substr(char *s1, int i, int j, char *s2){
    int contador = 0; // inicia um contador
    while(*s1 != '\0'){ // percorre s1 até seu caractere final
        if (contador >= i && contador <= j){
            *s2 = *s1; // caso o elemento esteja entre i e j, então é adicionado a s2
            ++s2;
        }
        contador++; // adiciona 1 ao contador
        ++s1;
    }
    *s2 = '\0'; // adiciona-se o caractere final a s2
}

int main()
{
    // Exemplo de uso da função strpos:
    char string1[] = "Deus acima de todos";
    char string2[] = "acima";
    cout << strpos(string1, string2) << endl; // imprime a posição da primeira ocorrencia da string2 na string1

    cout << "\n";

    // Exemplo de uso da função strcat:
    char s1[] = "bolo de ";
    char s2[] = "chocolate";
    strcat(s1, s2); // imprime as duas strings concatenadas

    cout << "\n\n";

    // Exemplo de uso da função substr:
    char str1[] = "Insista, persista e nunca desista";
    char str2[100];
    substr(str1, 9, 16, str2); // executa a funcao, colocando em str2 os valores de 9 a 16 de str1
    cout << str2 << endl; // imprime a str2

    return 0;
}
