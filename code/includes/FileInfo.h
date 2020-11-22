#include <FileReader.h>

/**
 * Esta librería define funciones para obtener o visualizar información del archivo.
 * Estas funciones no modifican el archivo original.
 */

/**
 * Imprime todas las líneas del archivo
 * 
 * Esta función ha sido implementada para mostrar el uso de la estructura.
 * 
 * @params:
 * - file: struct FileLines que contiene las líneas a imprimir
 */
void printLines(FileLines file)
{
    printf("En total hay %d lineas:\n", file.lineCount);
    for (int i = 0; i < file.lineCount; i++)
    {
        // se agrega \n para separar, ya que en el proceso de lectura se quitaron.
        printf("%s\n", file.lines[i]);
    }
}


/**
 * Cuenta las veces que aparece un caracter en el archivo.
 * Considera distintas las minusculas y mayusculas (i.e. a != A)
 * 
 * @params:
 * - file: struct FileLines que contiene las líneas a analizar
 * - c: caracter a buscar
 * 
 * @return:
 * - unsigned int, que indica la cantidad de veces que se encontró.
 * 
 * @usage:
 * FileLines file;
 * unsigned int count;
 * readFileToLines("test.txt", &file);
 * count = findChar(file, 'a');
 * printf("a aparece %u veces en el archivo.\n", count);
 */
unsigned int findChar(FileLines file, const char c);


/**
 * Regresa la cantidad de palabras que aparecen en todas las líneas del struct indicado.
 * NOTA:
 * Debes considerar separadores de palabras:
 * – espacios (puede que sea más de 1)
 * – tabuladores (\t, también puede ser más de 1)
 * 
 * – La línea nueva (\n) no se considera como separador, porque estamos leyendo el archivo POR LINEAS
 *   y removiendo ese caracter del final.
 * 
 * @params:
 * - file: struct FileLines que contiene las líneas a analizar
 * 
 * @return:
 * - unsigned int, que indica la cantidad de palabras en el archivo.
 * 
 * @usage:
 * FileLines file;
 * unsigned int count;
 * readFileToLines("test.txt", &file)
 * count = countWords(file);
 * printf("test.txt tiene %u palabras.\n", count);
 */
unsigned int countWords(FileLines file);