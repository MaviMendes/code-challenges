/*
2021

Durante a code interview da Amaro, um dos problemas era encontrar o tamanho do vetor sem usar funções built-in
Em C++ isso se relevou um problema
Dentro da main e usando aritmética de ponteiros, foi possível obter o tamanho certo, mas via função, não
Eis os testes:

*/
#include <iostream>
using namespace std;

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int sizeOfArray(int *array)
{
    
    int arraySize = 0;
    arraySize = sizeof(array);

    return arraySize;
}

int sizeOfArray2(float *array2)
{
    int arraySize2 = sizeof(array2);

    return arraySize2;
}

int main()
{
    int array[] = {12,34,53,2,0,12,45};
  
    float array2[]={1.5,3.4,5.6,7.1,4.567,3.795,5.66,1.34,12.34,5.67};

    int n =  *(&array+1) - array; 
    int n2 = *(&array2+1) - array2;
    cout<<"Tamanho do array 1: "<<n<<endl;
    cout<<"Tamanho do array 2: "<<n2<<endl;

    // O nome de um vetor é um ponteiro para o endereço de memória de seu primeiro elemento
    // &array+1 aponta para o endereço de memória logo após o fim do array
    // subtraindo o endereço inicial do endereço final obtem-se o tamanho do array

    n = sizeOfArray(array);
    n2 = sizeOfArray2(array2);

    cout<<"Tamanho do array 1: "<<n<<endl;
    cout<<"Tamanho do array 2: "<<n2<<endl;

    return 0;
}