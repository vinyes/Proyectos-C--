#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> vectorNum;

void limpiar()
{
	for(int i = 0; i < 20; i++)
	{
		cout << "" << endl;
	}
}

void inicializar()
{
	for (int i =0; i < 15; i++)
	{
		vectorNum.push_back(random() % 100);
	}
}

void mostrarVector(const vector<int> & vectorNum)
{
	for (int i = 0; i < vectorNum.size(); i++)
	{
		cout << vectorNum[i] << " ";
	}
	cout << endl;
}

/*Este método consiste en acomodar el vector moviendo el mayor hasta la última casilla comenzando desde la casilla cero del 
vector hasta haber acomodado el número más grande el la última posición, una vez acomodado el más grande, prosigue a encontrar
y acomodar el siguiente más grande comparando de nuevo los numeros desde el inicio del vector, y así sigue hasta ordenar todo los elementos el arreglo.*/

void ordenarBurbuja(vector<int> * puntero)
{
	int aux;

	vector<int> &vector = *puntero;

	for (int i = 0; i < vector.size(); i++)
	{
		for (int j = 0; j < vector.size() - 1; j++)
		{
			if(vector[j] > vector[j + 1])
			{
				aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;	
			}	
		}
	}

	cout << "Ordenar Burbuja: " << endl;
	mostrarVector(vector);
}

void intercambio(vector<int> & vectorNum, int i, int posicion)
{
	int aux;

	aux = vectorNum[i];
	vectorNum[i] = vectorNum[posicion];
	vectorNum[posicion] = aux;	
}

/*Algoritmo de ordenamiento por Selección: Consiste en encontrar el menor de todos los elementos del arreglo o vector 
e intercambiarlo con el que está en la primera posición. Luego el segundo mas pequeño, y así sucesivamente hasta ordenarlo todo*/

void ordenarSeleccion(vector<int> & vector)
{ 
	int posicion;

	for (int i = 0; i < vector.size(); i++)	
	{
		posicion = i;

		for (int j = i; j < vector.size() ; j++)
		{
			if(vector[j] < vector[posicion])
			{
				posicion = j;
			}		
		}	

		intercambio(vector,i,posicion);
	}
	
	cout << "Ordenar Selección: " << endl;
	mostrarVector(vector);
}

/*Consiste en insertar un elemento del arreglo en la parte izquierda del mismo que ya se encuentra ordenada. 
Este proceso se repite desde el segundo hasta el n-esimo elemento.*/

void ordenarInsercion(vector<int> & vector)
{
	int aux,primerElemento,j;

	for(int i = 1; i < vector.size(); i++)
	{
		primerElemento = vector[i];
		
		j = i - 1;

		while(j >= 0 && vector[j] > primerElemento)
		{
			vector[j + 1] = vector[j];
			j--;
		}
		
		vector[j + 1] = primerElemento;
	}
	
	cout << "Ordenar Inserción: " << endl;
	mostrarVector(vector);
}

/*El algoritmo de ordenación por combinación o Merge Sort, basado en la técnica Divide y Vencerás, 
ordena recursivamente un conjunto de elementos dividiéndolo en dos, ordenando cada una de estas partes en 
forma independiente y combinando los dos resultados.*/

vector<int> merge(const vector<int> vectorUno,const vector<int> vectorDos)
{
	vector<int> auxiliar;

	int i = 0;
	int j = 0;

	while( i < vectorUno.size() && j < vectorDos.size())
	{	
		
		if(vectorUno[i] < vectorDos[j])
		{
			auxiliar.push_back(vectorUno[i]);
			i++;
		}
		else
		{
			auxiliar.push_back(vectorDos[j]);
			j++;
		}
	}

	while(i < vectorUno.size())
	{
		auxiliar.push_back(vectorUno[i]);
		i++;
	}
	
	while(j < vectorDos.size())
	{
		auxiliar.push_back(vectorDos[j]);
		j++;
	}	

	return auxiliar;
}

vector<int> mergeSort(vector<int> & pasado)
{
	vector<int> vectorUno;
	vector<int> vectorDos;

	if(pasado.size() < 2)
	{
		return pasado;
	}

	int mitad = pasado.size() / 2;

	for(int i = 0; i < mitad; i++)
	{
		vectorUno.push_back(pasado[i]);
	}

	for(int i = mitad; i < pasado.size(); i++)
	{
		vectorDos.push_back(pasado[i]);
	}

	/*cout << "Uno" << endl;
	mostrarVector(vectorUno);
	cout << "Dos" << endl;
	mostrarVector(vectorDos);*/

	vectorUno = mergeSort(vectorUno);
	vectorDos = mergeSort(vectorDos);
	
	vector<int> resultado = merge(vectorUno,vectorDos);
	/*cout << "-----------------------------------------------" << endl;
	mostrarVector(resultado);*/
	return resultado;
}

void reheapificar(vector<int> & vector, int nodoIni, int posicion)
{
	int hijoDerecha, hijoIzquierda,max,numNodo;
	numNodo = nodoIni;
	//para cada nodo bajare hasta las hojas si hace falta
	while(numNodo <= posicion)
	{
		hijoIzquierda = 2 * numNodo + 1;
		hijoDerecha = 2 * numNodo + 2;
		int indiceMayor;

		indiceMayor = numNodo;

		if(hijoIzquierda <= posicion && vector[hijoIzquierda] > vector[indiceMayor])
		{
			indiceMayor = hijoIzquierda;
		}

		if(hijoDerecha <= posicion && vector[hijoDerecha] > vector[indiceMayor])
		{
			indiceMayor = hijoDerecha;
		}
			
		if(indiceMayor == numNodo)
		{
			break;
		}		
		else
		{
			intercambio(vector,numNodo,indiceMayor);
			numNodo = indiceMayor;
		}
	}
}
 
void heapificar(vector<int> & vector, int posicion)
{
	int numNodo;
	int mitad = (posicion / 2);
	
	for(int i = mitad; i >= 0; i--)
	{
		numNodo = i;
		reheapificar(vector,i,vector.size() - 1);
	}
	cout << "------------------------------------------------" << endl;
	mostrarVector(vector);
}

void ordenarHeapSort(vector<int> & vector)
{
	int posFin;
	posFin = vector.size();
	heapificar(vector,posFin);

	while(posFin > 0)	
	{
		intercambio(vector,posFin,0);
		posFin--;
		reheapificar(vector,0,posFin);		
	}
	cout << "Vector Ordenado: " << endl;
	mostrarVector(vector);
}

int main(int argc, char **argv)
{
	limpiar();
	inicializar();
	cout << "Vector desordenado: " << endl;
	mostrarVector(vectorNum);	

	//ordenarBurbuja(&vector);
	//ordenarSeleccion(vector);
	//ordenarInsercion(vectorNum);

	/*vector<int> auxiliar;

	auxiliar = merge(vector,vector);

	mostrarVector(auxiliar);*/

	cout << "Merge sort" << endl;
	mostrarVector(mergeSort(vectorNum));

	//ordenarHeapSort(vectorNum);
	
	limpiar();
}

