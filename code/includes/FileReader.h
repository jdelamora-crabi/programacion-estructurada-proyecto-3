#ifndef FILELINES_H
#define FILELINES_H

/**
 * Pequeña librería de manejo de archivos por líneas.
 * 
 * Pretende abstraer algunos conceptos del manejo de archivos
 * para que sea fácil al alumno ejercitar los temas de listas y strings, usando
 * archivos para trabajar y probar. 
 * 
 * @author: Javier de la Mora (japy@iteso.mx)
 */

/**
 * Cantidad máxima de líneas que leerá la función readFileToLines().
 */
#ifndef FILELINES_MAX_LINES
#define FILELINES_MAX_LINES 100
#endif /* FILELINES_MAX_LINES */

/**
 * Longitud máxima de caracteres por línea.
 */
#ifndef FILELINES_MAX_LENGTH
#define FILELINES_MAX_LENGTH 100
#endif /* FILELINES_MAX_LENGTH */

/**
 * Estructura que guarda las líneas leídas de un archivo con la función readFileLines().
 */
typedef struct struct_fileLines
{
    // Arreglo de máximo FILELINES_MAX_LINES líneas, cada una de FILELINES_MAX_LENGTH caracteres.
    // que guarda las líenas como cadenas de texto terminadas en NULL.
    // Al leer del archivo SE REMUEVE EL CARACTER DE NEWLINE (\n)
    char lines[FILELINES_MAX_LINES][FILELINES_MAX_LENGTH];

    // Cantidad de líneas que se leyeron de este archivo.
    unsigned int lineCount;
} FileLines;

/**
 * Lee el archivo especificado en filename y guarda todas sus líneas, con un máximo de FILELINES_MAX_LINES,
 * en la estructura apuntada por fileLines.
 * 
 * @params:
 * - filename: string terminado en null con el nombre del archivo a abrir.
 * - fileLines: apuntador a la estructura FileLines para guardar las líneas.
 */
void readFileToLines(const char *filename, FileLines *fileLines);

/**
 * Guarda todas las líneas de una estructura FileLines a un archivo con nombre filename.
 * Se sobreescribirá todo el contenido de filename y en caso de no existir se creará el archivo.
 * 
 * @params:
 * - fileLines: apuntador a la estructura FileLines que se desea guardar
 * - filename: nombre del archivo al que se desea guardar. Se sobreescribirá cualquier contenido.
 */
void saveLinesToFile(FileLines *fileLines, const char *filename);

#endif /* FILELINES_H */