#include <stdio.h>
#include <stdlib.h>
#include <FileReader.h>
#include <FileProcessing.h>
#include <FileInfo.h>

int main()
{
    FileLines file;
    readFileToLines("test.txt", &file);
    printLines(file);
    saveLinesToFile(&file, "./copia.txt");
}