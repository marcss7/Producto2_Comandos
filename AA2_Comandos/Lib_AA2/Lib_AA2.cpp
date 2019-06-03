#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Macro definida para insertar saltos de l�nea durante el c�digo para mejorar el aspecto visual de la impresi�n de los printf por pantalla.
#define println() printf("\n")

//Funciones:

//Funci�n que muestra por pantalla el contenido del archivo cuya ruta ha introducido el usuario cuando se le ha requerido.
void leerArchivo() {

	//Declaraci�n de puntero tipo FILE
	FILE *f;
	//Declaraci�n de variables locales
	char archivo[80]; //La variable archivo es la ruta asignada a la variable f de tipo fichero.

	printf("\n Introduce la ruta del archivo a leer: \n");
	println();
	scanf("%s", &archivo); //Lectura de la cadena introducida por el usuario mediante scanf, los datos introducidos pasan a corresponder a la variable archivo.
	println();
	//Asignamos al puntero f la apertura del archivo cuya ruta est� almacenada en la variable "archivo", utilizamos el modo de apertura de lectura ("r").
	f = fopen(archivo, "r");

	if (f == NULL) {
		printf("Problemas de apertura del archivo\n"); //Si la variable f de tipo fichero tiene valor NULL, es decir, no ha logrado abrir el archivo, se imprime por pantalla un mensaje de error.
	}
	//En los otros casos, es decir, si se ha conseguido la apertura correcta del archivo de la ruta introducida...
	else {
		while (!feof(f)) { //Mientras no se ha llegado al final del fichero "f"...
			printf("%c", getc(f)); //Imprime por pantalla el car�cter que est� leyendo el fichero en ese mismo instante, de esta forma, imprime todos los car�cteres, mostrando por pantalla todos los car�cteres que contiene el archivo de texto.
		}

		fclose(f); //Cerramos el archivo para liberar recursos.
	}
}

//Funci�n que implementa la opci�n de "guardar como" del archivo introducido por el usuario, copiando su contenido y creando un nuevo archivo con el nombre y la ruta que asigne el usuario, con el contenido copiado del otro archivo.
void guardarComoArchivo() {

	//Declaraci�n de punteros tipo FILE
	FILE *forigen, *fdestino; //Esta vez hay dos ficheros, el primero representa el archivo de origen el cu�l va a ser copiado y el segundo representa el archivo de destino.
	//Declaraci�n variables locales
	char archivo_destino[80], c, respuesta, archivo_original[80]; //La variable "archivo_original" es la ruta que se asigna a la variable de tipo fichero (forigen) y la variable "archivo_destino" es la ruta que se asigna a la variable de tipo fichero (fdestino). La variable "c" sirve para almacenar car�cteres. La variable "respuesta" corresponde a la opci�n del usuario sobre si quiere eliminar el archivo de origen.

	printf("\n Introduce la ruta del archivo a guardar como (archivo origen): \n");
	println();
	scanf("%s", archivo_original); //Lectura de la cadena introducida por el usuario mediante scanf, los datos introducidos pasan a corresponder a la variable archivo_original (es decir, el archivo fuente sobre el que se "guardar como").
	println();
	//Asignamos al puntero forigen la apertura del archivo cuya ruta est� almacenada en la variable "archivo_original" (el archivo de origen), utilizamos el modo de apertura de lectura ("r").
	forigen = fopen(archivo_original, "r");

	if (forigen == NULL) {
		printf("Problemas de apertura del archivo\n"); //Si la variable forigen de tipo fichero tiene valor NULL, es decir, no ha logrado abrir el archivo, se imprime por pantalla un mensaje de error.
	}

	printf("\n Introduce la nueva ruta del archivo a guardar como (archivo destino): \n");
	println();
	scanf("%s", archivo_destino); //Lectura de la cadena introducida por el usuario mediante scanf, los datos introducidos pasan a corresponder a la variable archivo_destino (es decir, el archivo destino resultado del "guardar como").
	println();
	//Asignamos al puntero fdestino la apertura del archivo cuya ruta est� almacenada en la variable "archivo_destino" (el archivo de destino), utilizamos el modo de apertura de escritura ("w").
	fdestino = fopen(archivo_destino, "w");

	if (fdestino == NULL) {
		printf("Problemas de apertura del archivo\n"); //Si la variable fdestino de tipo fichero tiene valor NULL, es decir, no ha logrado abrir el archivo, se imprime por pantalla un mensaje de error.
	}

	//Lee el contenido de un fichero, car�cter por car�cter y ese mismo car�cter lo escribe en otro fichero creado por la ruta introducida por el usuario (ruta del archivo de destino). 
	c = fgetc(forigen); //Se almacena en la variable "c", el car�cter se�alado en ese instante por el indicador de posici�n interno del archivo "forigen", seguidamente, el indicador de posici�n interno del archivo avanzar� al siguiente car�cter.
	while (c != EOF) //Mientras el valor del car�cter "c" no sea EOF (final del fichero), realizar...
	{
		fputc(c, fdestino); //Utilizamos fputc para escribir el car�cter almacenado en la variable "c" en el fichero almacenado en "fdestino". Escribe el car�cter en la posici�n indicada por el puntero del archivo y luego avanza el puntero del archivo.
		c = fgetc(forigen); //Como antes, sirve para leer y almacenar cada car�cter que contiene el fichero especificado (en este caso, el de la ruta forigen). Esta sentencia sirve para proseguir el bucle hasta con la acci�n hasta que se cumpla la condici�n del while (que se llegue al final del fichero).
	}

	printf("\n Contenido del archivo de origen copiado a la siguiente ruta: %s", archivo_destino); //Aqu�, la variable "archivo_destino" mostrar� la ruta d�nde se ha creado el archivo de destino.
	fclose(forigen); //Cerramos el archivo para liberar recursos.
	fclose(fdestino); //Cerramos el archivo para liberar recursos.

	printf("\n %Quieres eliminar el archivo de origen? Respuesta: S/N \n", 168); //El programa nos pregunta si queremos eliminar el archivo original (una vez realizada la copia, podemos escoger si mantener o borrar el archivo de origen). La respuesta ha de ser un car�cter, si el usuario introduce 'S' o 's' (de s�), se produce a eliminar el archivo, se introduce 'N', 'n' o cualquier otro car�cter, mantiene ambos archivos.
	scanf(" %c", &respuesta); //La variable "respuesta" es donde se almacenar� la respuesta introducida por el usuario, que debe ser un car�cter.

	if (respuesta == 'S' || respuesta == 's') { //Si la respuesta introducida por el usuario son los car�cteres 's' o 'S' (hace falta diferenciarlos, pues cada car�cter tiene una codificaci�n propia y diferente al otro)...
		remove(archivo_original); //Utilizamos remove con argumento de la variable "archivo_original" que tiene como valor la ruta que introdujo el usuario que hac�a referencia al archivo original sobre el que se utiliza "guardar como".
		printf("\n Archivo original eliminado de forma correcta.\n");
	}
	else { //Si la respuesta introducida por el usuario es cualquier otro car�cter, se interpreta como un No y por tanto, no se realiza la eliminaci�n del archivo original.
		printf("\n Se ha escogido no eliminar el archivo original.\n");
	}
}

//Funci�n que informar� si la palabra introducida por el usuario forma parte del contenido del archivo cuya ruta ha introducido el usuario cuando se le ha requerido.
void chequearArchivo() {

	//Declaraci�n de puntero tipo FILE
	FILE *f;
	//Declaraci�n de variables locales
	int i = 0; //La variable "i" almacena el n�mero de ocurrencias de "needle" dentro de "haystack".
	char haystack[80], archivo[80], needle[80]; //La variable archivo es la ruta asignada a la variable f de tipo fichero. Las variables "needle" y "haystack" son los argumentos de la funci�n strstr(), mientras que "haystack" es la cadena principal a ser escaneada por la funci�n, "needle" es la subcadena a ser buscada dentro de la cadena principal (haystack).

	printf("\n Introduce la ruta del archivo donde se buscara la palabra: \n");
	println();
	scanf("%s", &archivo); //Lectura de la cadena introducida por el usuario mediante scanf, los datos introducidos pasan a corresponder a la variable "archivo" (la ruta del archivo).
	println();
	//Asignamos al puntero f la apertura del archivo cuya ruta est� almacenada en la variable "archivo", utilizamos el modo de apertura de lectura ("r").
	f = fopen(archivo, "r");

	if (f == NULL) {
		printf("Problemas de apertura del archivo\n"); //Si la variable f de tipo fichero tiene valor NULL, es decir, no ha logrado abrir el archivo, se imprime por pantalla un mensaje de error.
	}
	printf("\n Introduce la palabra a buscar: \n");
	println();
	scanf("%s", &needle); //Lectura de la cadena introducida por el usuario mediante scanf, los datos introducidos pasan a corresponder a la variable "needle" (la cadena de car�cteres que se buscar� en el archivo).
	println();

	while (fscanf(f, "%s", haystack) == 1) //La funci�n fscanf devuelve el n�mero de objetos de entrada que ha tenido alguna coincidencia exitosa, si no se encuentra ning�n "match", el resultado ser� 0. Mientras (while) haya alguna concurrencia exitosa (la funci�n fscanf retorna 1)...
	{
		if (strstr(haystack, needle) != 0) { //Si se encuentra coincidencia (hay m�s de 0 apariciones de la subcadena "needle" dentro de la cadena "haystack")...
			i++; //Se incrementa el �ndice, la variable "i" almacena el n�mero de ocurrencias de "needle" dentro de "haystack".
		}
	}
	printf("Se ha encontrado la palabra \"%s\" en el archivo este numero de veces: %d \n", needle, i); //Se imprime el n�mero de veces en las que la cadena introducida por el usuario est� presente en el archivo designado tambi�n por el usuario.
	fclose(f); //Cerramos el archivo para liberar recursos.
}