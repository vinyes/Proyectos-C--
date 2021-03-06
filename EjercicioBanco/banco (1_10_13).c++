#include <stdio.h>
#define limpia_pantalla(X) for(i = 0; i < 40; i++) printf("\n");
#define NUM_CUENTAS 10

//clase Cuenta
class Cuenta
{
	public: 

	int numCuenta;
	float saldo;
	char titular[20];

	Cuenta(){}
	
	Cuenta(int num, float cantidad, char *tit) 
	{
		numCuenta = num;
		saldo = cantidad;
		sprintf(titular,tit);
	}

	void ingresar(float cantidad)
	{
		saldo += cantidad;
	}

	bool extraer(float cantidad)
	{
		if(saldo >= cantidad)
		{	
			saldo -= cantidad;
			return true;
		}
		return false;
	}

	float verSaldo()
	{
		return saldo;
	}

	void inicializar(int num, float cantidad, char *tit)
	{
		numCuenta = num;
		saldo = cantidad;
		sprintf(titular,tit);
	}
};

Cuenta *punteroCuentaSel; //creamos un puntero de tipo cuenta

Cuenta vectorCuenta[NUM_CUENTAS];//vectorCuenta es un puntero que apunta a la primera posición del vector

void muestraMenu()
{
	int i;
	limpia_pantalla();
	for(i = 0; i < 40; i++) printf("_ ");

	printf("\n");
	printf("\n");
	printf("1- Elegir cuenta \n");
	printf("2- Ingresar \n");
	printf("3- Retirar \n");
	printf("4- Ver saldo \n");
	printf("5- Ver todas las cuentas \n");
	printf("q- Salir del programa\n");
	for(i = 0; i++ < 10; printf("\n"));
}

void llenarVector()
{
	vectorCuenta[0].inicializar(10,1000,"Juan");
	vectorCuenta[1].inicializar(20,2000,"Pepe");
	vectorCuenta[2].inicializar(30,3000,"Miguel");
	vectorCuenta[3].inicializar(40,4000,"Ramon");
}

void mostrarVector()//para ver todas las cuentas que tenemos creadas
{
	int i;
	for(i = 0;i < NUM_CUENTAS;i++)
	{
		if(vectorCuenta[i].titular != 0 && vectorCuenta[i].numCuenta)
		{
			printf("Titular: %s \n",vectorCuenta[i].titular);
			printf("Número de cuenta: %i \n",vectorCuenta[i].numCuenta);
			printf("Saldo: %f \n",vectorCuenta[i].saldo);
			printf("----------------------------------------- \n");	
		}
	}
}

void limpiar()
{
	int i;
	for(i=0;i<10;i++) printf("\n");
}

Cuenta * encontrarCuenta(int numeroCuenta)
{
	Cuenta *p;
	
	for(p = vectorCuenta; p < &vectorCuenta[NUM_CUENTAS];p++)
	{
		if(p->numCuenta == numeroCuenta)
		{
			return p;
		}
	}
	return NULL;
}

void mostrarCuentas()
{
	Cuenta *p;

	for(p = vectorCuenta; p < &vectorCuenta[NUM_CUENTAS];p++)
	{
		if(p->numCuenta != 0)
		{
			printf("Números de cuentas disponibles: %i \n", p->numCuenta);
			printf("Nombre del titular de la cuenta: %s \n",p->titular);
			printf("---------------------------------------------------- \n");
		}	
	}
}


//MAIN
int main(int argc, char *argv[])
{
	char c;
	int cuentaSeleccionada = 0;
	int *puntero;

	llenarVector();
	punteroCuentaSel = NULL;

	while (c!='q')
	{
		muestraMenu();
		printf("Elige un opción: ");
		c=getchar();
		getchar();

		switch(c)
		{
			case '1': 
				printf("Has seleccionado la opción de Seleccionar cuenta \n");
				limpiar();
				mostrarCuentas();
				
				while(punteroCuentaSel == NULL) 
				{
					printf("¿Qué cuenta desea? ");
					scanf("%i",&cuentaSeleccionada);

					punteroCuentaSel = encontrarCuenta(cuentaSeleccionada);
					if(punteroCuentaSel == NULL)
					{
						printf("No se ha encontrado la cuenta \n");
					}
				}
			break;

			case '2': 
				float cantidadIngresar;
				
				if(punteroCuentaSel == NULL)
				{
					printf("Debes seleccionar una cuenta \n");
					break;
				}

				printf("Has seleccionado la opción de Ingresar cuenta y estas ingresando saldo en la cuenta %i \n" ,punteroCuentaSel->numCuenta);
				printf("¿Qué cantidad quiere ingresar? ");
				scanf("%f",&cantidadIngresar);
				punteroCuentaSel->ingresar(cantidadIngresar);
			break;

			case '3':
				float cantidadExtraer;
				printf("Has seleccionado la opción de Extraer de la cuenta %i \n" ,punteroCuentaSel->numCuenta);
				printf("¿Qué cantidad quiere extraer? ");
				scanf("%f",&cantidadExtraer);

				if(!punteroCuentaSel->extraer(cantidadExtraer))
				{
					printf("Saldo en la cuenta insuficiente \n");	
					getchar();			
				}
			break;
			
			case '4': 
				printf("Has seleccionado la opción de Ver saldo cuenta %i \n" ,punteroCuentaSel->numCuenta);
				printf("El titular de la cuenta %s cuyo numero de cuenta es %i tiene %f de saldo\n"
				,punteroCuentaSel->titular
				,punteroCuentaSel->numCuenta
				,punteroCuentaSel->verSaldo());
			break;

			case '5':
				limpiar();
				mostrarVector();
			break;

			case 'q':
				printf("Gracias por utilizar el programa de gestión de cuentas bancarias"); 
			break;
			default	: printf("Opción incorrecta \n");
		}	
		printf("Pulse cualquier tecla para seguir con el programa");
		getchar();
	}
}

