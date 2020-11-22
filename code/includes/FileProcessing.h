#include <FileReader.h>

/**
 * Esta librería define funciones que procesan un archivo y modifican sus líneas.
 *
 * Nota: Estas funciones reciben un APUNTADOR a FileLines, para poder modificarlo.
 * Para acceder a los campos del struct, debes usar alguna de las siguientes estrategias:
 * 
 * 1) usando la notación de flecha:
 *  file->lineCount
 *  file->lines[i]
 * 
 * 2) "derreferenciando" antes de usar el punto:
 *  (*file).lineCount
 *  (*file).lines[i]
 */

/**
 * Ordena alfabéticamente las líneas de <file>
 * 
 * @params:
 * - file: apuntador al struct fileLines.
 * 
 * @usage:
 * FileLines file;
 * readFileToLines("test.txt", &file);
 * sortLines(&file); // <-- se tiene que pasar la dirección de la variable, como scanf()
 * saveLinesToFile(&file, "sortedTest.txt");
 */
void sortLines(FileLines *file);