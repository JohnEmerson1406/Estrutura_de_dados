#include <string>
#include <iostream>

using namespace std;

class TProduto{
    private:
        int cod;
        string descricao;
        float unidade;
        int quant;
    public:
        TProduto(int c,string d,float u,int q);
        int getCod();
        string getDesc();
        float getUnid();
        int getQuant();
};

class TLista{
	  private:
	  	TProduto *l[30];
		int quant = 0;
	  public:
	  	TLista();
	  	void getLista();
        void addProduto(TProduto *produto);
	  	void getElemento(int cod);
};

TProduto:: TProduto(int c,string d,float u,int q){
    cod=c;
    descricao=d;
    unidade=u;
    quant=q;
}

int TProduto::getCod(){
    return cod;
}

string TProduto::getDesc(){
    return descricao;
}

TLista::TLista(){
    quant = 0;
}

float TProduto::getUnid(){
    return unidade;
}

int TProduto::getQuant(){
    return quant;
}

void TLista::getLista(){
    if (quant == 0){
        cout << "\nLista de compras vazia!" << "\n\n";
    }
    else{
        cout << "\n--- Produtos (ordenados por codigo) " << " ---" << "\n\n";
        for (int i=0; i < quant; i++){
            cout << "   Codigo: " << l[i]->getCod() << endl;
            cout << "   Descricao: " << l[i]->getDesc() << endl;
            cout << "   Valor unitario: " << l[i]->getUnid() << endl;
            cout << "   Quantidade: " << l[i]->getQuant() << endl;
            cout << "\n";
        }
    }
}

void TLista::addProduto(TProduto *produto){
    if (quant < 30){
        int p = -1;
        if (quant == 0){
            l[0] = produto;
            quant++;
        }
        else{
            for (int i=0; i < quant; i++){
                if (produto->getCod() < l[i]->getCod()){
                    p = i;
                    break;
                }
            }
            if (p == -1){
                l[quant] = produto;
                quant++;
            }
            else{
                for (int i=quant; i > p; i--){
                    l[i] = l[i - 1];
                }
                l[p] = produto;
                quant++;
            }
        }
    }
    else{
        cout << "\nLista de compras lotada!" << endl;
    }
}

void TLista::getElemento(int cod){
    cout << "\n";
    bool achou = false;
    for (int i=0; i < quant; i++){
        if (l[i]->getCod() == cod){
            achou = true;
            cout << "   Codigo: " << l[i]->getCod() << endl;
            cout << "   Descricao: " << l[i]->getDesc() << endl;
            cout << "   Valor unitario: " << l[i]->getUnid() << endl;
            cout << "   Quantidade: " << l[i]->getQuant() << endl;
        }
    }
    if (achou == false){
        cout << "Produto nao encontrado!" << endl;
    }
    cout << "\n";
}

int main()
{
    TLista *lista = new TLista();

    int opcao;
    int cod;
    string descricao;
    float valor_unidade;
    int quantidade;
    TProduto *produto;

    do{
        cout << endl;
        cout << "*** MENU ***\n";
        cout << "1 - Insercao de elemento\n";
        cout << "2 - Consulta de elemento (consultar pelo codigo do produto)\n";
        cout << "3 - Mostrar lista de compras (imprimir todos os produtos)\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao){
        case 1:
            cout << "\nCodigo do produto: ";
            cin >> cod;
            cout << "\nDescricao do produto: ";
            cin.ignore();
            getline(cin, descricao);
            cout << "\nValor unitario: ";
            cin >> valor_unidade;
            cout << "\nQuantidade: ";
            cin >> quantidade;

            produto = new TProduto(cod, descricao, valor_unidade, quantidade);

            lista->addProduto(produto);

            break;
        case 2:
            cout << "\nDigite o codigo do produto: ";
            cin >> cod;
            lista->getElemento(cod);
            break;
        case 3:
            lista->getLista();
            break;
        case 0:
            break;
        default:
            cout << "\nOpcao invalida!\n";
            break;
        }
    }while (opcao != 0);

    return 0;
}
