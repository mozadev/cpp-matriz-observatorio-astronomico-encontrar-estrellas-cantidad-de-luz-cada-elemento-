// ConsoleApplication2.cpp : main project file.
#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;
using namespace System;


int ingresapositivo()
{
	int n;
	do
	{
		cout << "ingresa positivo"; cin >> n;
	} while (n < 0 && n > 50);
	return n;

}


void ingresodatos(int *n, int *m, int **matriz, char **matriz2)

{
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *m; j++)
		{
			cout << "ingreso de la cantidad de luz [" << i + 1 << "],[" << j + 1 << "]: ";
			cin >> matriz[i][j];
		}

	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *m; j++)
			matriz2[i][j] = ' ';
		

}




void salidadatos(int *n, int *m, int **matriz,char **matriz2)

{
	cout << "matriz 1" << endl;
	
	for (int i = 0; i < *n; i++)
	{

		for (int j = 0; j < *m; j++)
			cout << matriz[i][j] << "\t";
		cout << endl;
	}

	cout << "matriz 2" << endl;
	
	for (int i = 0; i < *n; i++)
	{

		for (int j = 0; j < *m; j++)
			cout << matriz2[i][j] << "\t";
		cout << endl;
	}


}

void buscarestrellas(int *n, int *m, int **matriz, char **matriz2)
{

	for (int i = 1; i < *n - 1; i++)
		for (int j = 1; j < *m - 1; j++)
			if (matriz[i][j] + matriz[i - 1][j] + matriz[i + 1][j] + matriz[i][j - 1] + matriz[i][j + 1] > 30)
				matriz2[i][j] = '*';
			else
				matriz2[i][j] = '-';
}




int main()
{
	int n = ingresapositivo();
	int m = ingresapositivo();
	int **matriz;
	matriz = new int*[n];
	for (int i = 0; i < n; i++)
		matriz[i] = new int[m];
	
	char **matriz2;
	matriz2 = new char*[n];
	for (int i = 0; i < n; i++)
		matriz2[i] = new char[m];

	ingresodatos(&n, &m, matriz,matriz2);
	
	buscarestrellas(&n, &m, matriz, matriz2);
	salidadatos(&n, &m, matriz, matriz2);


	for (int i = 0; i < n; i++)
		delete[]matriz[i];
	delete matriz;

	for (int i = 0; i < n; i++)
		delete[]matriz2[i];
	delete matriz2;

	_getch();



}




