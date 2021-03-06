#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> vectorNumeros;

void mostrarVector(const vector<int> & vectorNumeros)
{
	for (int i = 0; i < vectorNumeros.size(); i++)
	{
		cout << vectorNumeros[i] << " ";
	}
	cout << endl;
}

void inicializar()
{
	for (int i =0; i < 15; i++)
	{
		vectorNumeros.push_back(random() % 100);
	}
}




void OrdenarBurbuja(vector<int> & vectorNumeros)
{
	int aux;
	for(int i = 0;i < vectorNumeros.size(); i++)
	{
		for(int j = 0;j < vectorNumeros.size() - 1; j++)
		{
			if(vectorNumeros[j] > vectorNumeros[j +1])
			{
				aux = vectorNumeros[j];
				vectorNumeros[j] = vectorNumeros[j + 1];
				vectorNumeros[j + 1] = aux;
			}
		}
	}
	cout << "Ordenar Burbuja" << endl;
	mostrarVector(vectorNumeros);
}

void OrdenarSeleccion(vector<int> & vectorNumeros)
{
	int pos,aux;
	for(int i = 0;i < vectorNumeros.size(); i++)
	{
		pos = i;
		for(int j = i;j < vectorNumeros.size(); j++)
		{
			if(vectorNumeros[pos] > vectorNumeros[j])
			{
				pos = j;
			}
		}
		aux = vectorNumeros[i];
		vectorNumeros[i] = vectorNumeros[pos];
		vectorNumeros[pos] = aux;
	}
	cout << "Ordenar Selección" << endl;
	mostrarVector(vectorNumeros);
}

void OrdenarInsercion(vector<int> & vectorNumeros)
{
	int primero,j;
	for(int i = 1;i < vectorNumeros.size(); i++)
	{
		primero = vectorNumeros[i];
		j = i - 1;

		while(j >= 0 && vectorNumeros[j] > primero)	
		{
			vectorNumeros[j + 1] = vectorNumeros[j];
			j--;
		}
		vectorNumeros[j + 1] = primero;
	}
	cout << "Ordenar Inserción" << endl;
	mostrarVector(vectorNumeros);
}

int main()
{
	inicializar();
	cout << "Vector Desordenado" << endl;
 	mostrarVector(vectorNumeros);
	cout << "" << endl;
	//OrdenarBurbuja(vectorNumeros);
	//OrdenarSeleccion(vectorNumeros);
	OrdenarInsercion(vectorNumeros);
}





































/*void crearHeap(int desde)
{
        for (int i=desde; i < vectorNumeros.size(); i++)
        {
                int padre = ((i - desde - 1)/2) + desde;
                int j = i;
                while (padre >= desde && vectorNumeros[padre] > vectorNumeros[j] )
                {
                        int aux = vectorNumeros[padre];
                        vectorNumeros[padre] = vectorNumeros[j];
                        vectorNumeros[j] = aux;
 
                        j = padre;
                        padre = ((padre - desde - 1)/2) + desde;
                }
        }
	cout << "Vector: " << endl;
	mostrarVector(vectorNumeros);
}

void heapsort()
{
        for (int i=0; i < vectorNumeros.size(); i++)
        {
                crearHeap( i );
        }
}*/
 

