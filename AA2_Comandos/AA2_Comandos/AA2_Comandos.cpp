#include <stdio.h>

//Macro definida para insertar saltos de línea durante el codigo para mejorar el aspecto visual de la impresión de los printf por pantalla.
#define println() printf("\n")

//Declaración funciones

void leerArchivo();
void guardarComoArchivo();
void chequearArchivo();

int main()
{
	//Definición de variables
    int opcion; //Variable que almacenará la opción del menú escogida por el usuario.

	do
	{
		//Menú que permite seleccionar a cuál de las diferentes funcionalidades implementadas accede el usuario.
		println();
		printf("\n   1. Mostrar el contenido de un archivo.");
		printf("\n   2. Implementar guardar como para un archivo.");
		printf("\n   3. Chequear el contenido de un archivo.");
		printf("\n   4. Salir.");
		
		do
		{
			//Filtramos la opción elegida por el usuario (con scanf).
			println();
			printf("\n   Introduzca opcion (1-4): ");
			scanf("%d", &opcion);

		} while (opcion < 1 || opcion > 4); //Con este bucle nos aseguramos que la opción escogida por el usuario sólo puede ser 1, 2, 3 o 4. El bucle se repite en caso de que se introduzca un número más pequeño que el 1 y más grande que el 4.

		switch (opcion) 
		{
		case 1: leerArchivo(); //En caso de seleccionar la primera opción (opcion = 1), se invoca la función leerArchivo(), que mostrará el contenido del archivo introducido por el usuario.
			break;

		case 2: guardarComoArchivo(); //En caso de seleccionar la segunda opción (opcion = 2), se invoca la función guardarComoArchivo(), que implementa el "guardar como" del archivo introducido por el usuario.
			break;

		case 3: chequearArchivo(); //En caso de seleccionar la tercera opción (opcion = 3), se invoca la función chequearArchivo(), que informará si la palabra introducida por el usuario forma parte del contenido del archivo introducido por el usuario.
			break;
		}

	} while (opcion != 4); //Finaliza el bucle while cuando la variable opcion = 4 (la opción de salir del programa en el menú). Cuando el usuario escoge la opción 4, se acaba el bucle y el código deja paso a return 0 (finalización del programa).

	return 0; //Finalización del programa.
}