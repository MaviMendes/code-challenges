/*
2021

code interview da vtex

Buscar um item por meio de sua chave

*/
#include <iostream>
using namespace std;

struct estrutura{

    string chave;
    string valor;
};

struct estrutura e1[100];
int count = 0;

int main()
{
    
    string chaveUsuario;
    cout<<"Chave: "<<endl;
    cin>>chaveUsuario;
    buscaUsuario(chaveUsuario);
}

void inserir(string c, string v)
{
    // caso o elemento exista, atualizar o valor
    int p = busca(c); 
    if(p != -1) // encontrou, ja existe
    {
        e1[p].valor = v;
    }
    else if(count +1 <= 100) 
    {
        e1[count].chave = c;
        e1[count].valor = v;
        count++;
    }
}

int busca(string c)
{
    if(count == 0)
    {
        cout<<"Estrutura vazia."<<endl;
        abort();
    }
    
    int i;
    for(i = 0; i<count;i++)
    {
        if(e1[i].chave == c)
        {
            return i;
        }
    }
    
    if(i == count)
        return -1;
}

string buscaUsuario(string c)
{
    int p = busca(c);
    if(p == -1)
         return "Chave inexistente.";
    else 
        return e1[p].valor;
}
  