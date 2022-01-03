/*
Maria Vitoria - 4/09/2021
Questao da OBI
2a fase

O que fazer:
ordenar a struct consulta em ordem crescente com base no horario de fim
consulta 1 é o elemento zero do vetor
qntConsultas = 1
depois, de 1 ate n
nextMin guarda o horario de fim da consulta
consulta[i].inicio >= nextMin
por ai vai
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct horario{
    
    int inicio;
    int fim;
} horario;

int solucao(horario *hr, int n)
{
    int count = 1;
    int minInicio;
    minInicio = hr[0].fim;
    for(int i=1;i<n;i++)
    {
        if(hr[i].inicio >= minInicio)
        {
            //cout<<"hr inicio: "<<hr[i].inicio<<" para i = "<<i<<endl;
            count++;
            minInicio = hr[i].fim;
        }
    }

    return count;
}

bool ordenarFim(horario h1, horario h2)
{
    return h1.fim<h2.fim;
}

int main()
{
	
    int n;
    cin>>n;
    
    horario horarios[10100]; // horario horarios = new horarios[n];

    for(int i=1;i<=n;i++)
    {
        cin>>horarios[i].inicio;
        cin>>horarios[i].fim;
    }
    
    sort(horarios+1,horarios+n+1,ordenarFim); // so assim que a plataforma aceitou
    // sort(horarios, horarios+n, ordenarFim);
    int qntConsultas = solucao(horarios,n);

    cout<<qntConsultas<<endl;
    
    return 0;
}