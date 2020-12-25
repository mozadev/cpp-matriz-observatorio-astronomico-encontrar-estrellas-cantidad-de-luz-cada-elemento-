ejercicio 7 hoja 1 bidimensionales
*/
#include<iostream>
#include<conio.h>
using namespace std;
int IngresaPositivo()
{
int Num;
do
{
cout << "numero positivo:"; cin >> Num;
} while (Num <= 1 || Num > 50);
return Num;
}
void IngresaDatos(int N, int M, int **Matriz1, char **Matriz2)
{
for (int i = 0; i < N; i++)
for (int j = 0; j< M; j++)
{
cout << "Ingrese dato " << i + 1 << "," << j + 1 << ":";
cin >> Matriz1[i][j];
}
for (int i = 0; i < N; i++)
for (int j = 0; j< M; j++)
Matriz2[i][j] = '-';
}
void ImprimirDatos(int N, int M, int **Matriz1, char **Matriz2)
{
cout << endl << " DATOS DE LA MATRIZ1" << endl;
for (int i = 0; i < N; i++)
{
for (int j = 0; j< M; j++)
cout << Matriz1[i][j] << " ";
cout << endl;
}
cout << endl << " DATOS DE LA MATRIZ2" << endl;
for (int i = 0; i < N; i++)
{
for (int j = 0; j< M; j++)
cout << Matriz2[i][j] << " ";
cout << endl;
}
}
void BuscaEstrellas(int N, int M, int **Matriz1, char **Matriz2)
{
for (int i = 0; i < N; i++)
for (int j = 0; j< M; j++)
if (i != 0 && j != 0 && i != N - 1 && j != M - 1)
if (Matriz1[i][j] + Matriz1[i - 1][j] + Matriz1[i + 1][j] + Matriz1[i][j - 1] + Matriz1[i][j + 1]>30)
Matriz2[i][j] = '*';
}
int main()
{
int N, M;
cout << "Ingrese N ";
N = IngresaPositivo();
cout << "Ingrese M ";
M = IngresaPositivo();
int **Matriz1;
char **Matriz2;
Matriz1 = new int *[N];
Matriz2 = new char *[N];
for (int i = 0; i<N; i++)
Matriz1[i] = new int[M];
for (int i = 0; i<N; i++)
Matriz2[i] = new char[M];
IngresaDatos(N, M, Matriz1, Matriz2);
BuscaEstrellas(N, M, Matriz1, Matriz2);
ImprimirDatos(N, M, Matriz1, Matriz2);
for (int i = 0; i<N; i++)
delete[] Matriz1[i];
delete[] Matriz1;
for (int i = 0; i<N; i++)
delete[] Matriz2[i];
delete[] Matriz2;
_getch();
}