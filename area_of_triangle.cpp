// 03/01/2022 meta challenge for meta hack 
/*
área do triângulo calculada usando conceitos de geometria analítica e cálculo de determinante com a 
fórmula de menor complementar
*/
#include <bits/stdc++.h>
 
using namespace std;
 
 
/*
* Complete the 'getTriangleArea' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
*  1. INTEGER_ARRAY x
*  2. INTEGER_ARRAY y
*/

int determinante(vector<int> AB, vector<int> AC)
{
    // Menor complementar Dij | somatorio  (-1)^(linha+coluna)*matriz 2x2
    /*
    i      j    k
    AB[0] AB[1] 0
    AC[0] AC[1] 0

    1*(AB[1]*0 - AC[1]*0) -1*(AB[0]*0 - AC[0]*0) + 1*(AB[0]*AC[1]-AB[1]*AC[0])
    */

    int resultado = 1*(AB[1]*0 - AC[1]*0) - 1*(AB[0]*0 - AC[0]*0) + 1*(AB[0]*AC[1]-AB[1]*AC[0]);

    return abs(resultado);
}
int getTriangleArea(vector<int> x, vector<int> y) {
   
   // A = x0,y0
   // B = x1,v1
   // C = x2,y2
   // AB = B - A
   vector<int> AB = {x[1]-x[0],y[1]-y[0]};
   // AC = C - A
   vector<int> AC = {x[2]-x[1],y[2]-y[1]};
   // Area = 1/2 ||AB*AC||
   int resultado = determinante(AB,AC);

   return resultado/2;
}
 
int main()
{

vector<int> x = {0,4,7};
vector<int> y = {0,8,6};

int resultado = getTriangleArea(x,y);

cout<<resultado;

}
