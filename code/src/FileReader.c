#include <FileReader.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Archivo de implementación para FileReader.h
 * 
 * @author: Javier de la Mora (japy@iteso.mx)
 */

void readAllLinesAndStoreToFileLines(FILE *filePtr, FileLines *fileLinesPtr);
void removeTrailingNewLine(char *str);

void readFileToLines(const char *filename, FileLines *fileLinesPtr)
{
    if (fileLinesPtr == NULL)
        return;

    // Usamos la estructura FILE definida en stdio, que describe un archivo.
    FILE *filePointer;

    // la función fopen nos permite abrir un archivo en algun modo: "r" significa solo lectura.
    // obtenemos un apuntador a archivo (*FILE), que nos permite acceder a este archivo
    // con otras funciones del sistema.
    filePointer = fopen(filename, "r");

    // verificamos que el apuntador no haya resultado en NULL, lo que significaría un error al abrir el archivo.
    // puede ser que no exista o que no tengamos permiso, entre otras cosas.
    if (filePointer == NULL)
        exit(EXIT_FAILURE);

    readAllLinesAndStoreToFileLines(filePointer, fileLinesPtr);

    // con esta llamada cerramos el archivo de manera correcta, "desocupándolo".
    fclose(filePointer);
}

void saveLinesToFile(FileLines *fileLines, const char *filename)
{
    // misma estructura que readlines
    FILE *filePointer;

    // ahora el modo es w+: write and create if not found.
    filePointer = fopen(filename, "w+");
    if (filePointer == NULL)
        return;

    // escribimos cada línea, agregando al final un salto de línea (\n)
    for (int i = 0; i < (*fileLines).lineCount; i++)
    {
        // nótese que es fprintf y no printf: el primer argumento es el *FILE
        fprintf(filePointer, "%s\n", (*fileLines).lines[i]);
    }

    // siempre cerramos nuestro archivo, para desocuparlo.
    fclose(filePointer);
}

/* --------- FUNCIONES AUXILIARES --------- */

// Lee las lineas de un archivo y las guarda, una a una, en una estructura de tipo FileLines.
void readAllLinesAndStoreToFileLines(FILE *filePtr, FileLines *fileLinesPtr)
{
    // esta variable nos sirve para guardar temporalmente lo leído por getline().
    char *line = NULL;
    size_t lineLen = FILELINES_MAX_LENGTH;
    int totalLines = 0;

    // esta variable es para guardar la cantidad de caracteres que fueron leidos con cada getline().
    // no cuenta el caracter nulo.
    int readChars;

    // vamos a leer mientras que no hayamos leído ya FILELINES_MAX_LINES y mientras que el resultado de la función
    // getline(), que nos dice cuántos caracteres se han leido, sea distinto a –1.
    // Un valor de –1 en esa función indica que no se ha leído nada, normalmente porque se ha alcanzado el final del archivo.
    do
    {
        readChars = getline(&line, &lineLen, filePtr);
        if (readChars > 0)
        {
            removeTrailingNewLine(line);

            // se usa la notación de flecha "->" porque fileLines es un apuntador. Es algo que verán más a profundidad
            // en la materia "Memoria Dinámica"
            strcpy(fileLinesPtr->lines[totalLines], line);
            totalLines++;
        }
    } while (totalLines < FILELINES_MAX_LINES && readChars != -1);

    // Actualizamos la cantidad de lineas que tiene fileLines.
    fileLinesPtr->lineCount = totalLines;

    // cuando usamos memoria dinámica, es indispensable "liberarla" con free()
    if (line != NULL)
        free(line);
}

// Revisa el ultimo caracter y lo cambia por NULL si es newline.
void removeTrailingNewLine(char *str)
{
    size_t len = strlen(str);
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}
