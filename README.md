# Proyecto 3
Programación estructurada

Este proyecto consiste en dos etapas: una primera de compilación de código preexistente y la segunda de modificación de funcionalidades.

## Etapa 1: Proyceto base
La primera etapa del proyecto consiste en configurar y construir el proyecto base, para posteriormente trabajar sobre él y agregar funcionalidades.

El proyecto base da lo necesario para leer y escribir archivos de manera simple, por líneas.
Se incluyen dos archivos de cabecera sin implementar, que serán parte de su trabajo en el proyecto.

También provee una organización de partida para crecer el proyecto con más archivos de cabecera (.h) y de implementación (.c).

### Estructura de carpetas
Los archivos base que se proveen están acomodados en la siguiente estructura. Revisa cada archivo y comprende qué es lo que hace, para luego pasar a compilar.
```txt
   code/                 
├── includes/            
│ ├── FileInfo.h         # declara funciones de información del archivo
│ ├── FileReader.h       # declara funciones para manejo de archivos
│ └── FileProcessing.h │ # declara funciones para procesamiento de archivos
│                        
├── src/                 # contiene todos los archivos de implementación para las cabeceras;
| |                        aquí colocarás tus propios archivos de implementación
│ └── FileReader.c │       
│                        
├── analyzer.c │         # archivo principal, contiene la función main()
│                        
├── instructions.txt │         # archivo con instrucciones
├── sortme.txt │         # archivo para comprobar que el sort funciona
└── test.txt             # archivo de prueba, para comprobar la base que funciona.
```
 
### Compilación inicial
Comprueba que todo funciona compilando los archivos desde la línea de comandos y ejecutándolo.

Asegúrate de que la línea de comandos está colocada en el directorio `code/`; de otra forma no encontrará los archivos para compilarlos. Puedes navegar con el comando `cd`

Compila el proyecto base con el siguiente comando:
```shell
gcc analyzer.c -o analyzer.exe -Iincludes ./src/FileReader.c
```
El comando tiene las siguientes partes:
- `gcc`: ejecutar el compilador
- `analizer.c`: archivo fuente a compilar
- `-o analizer.exe`: nombre del archivo ejecutable de salida
- `-Iincludes`: con la bandera `-I` se indica al compilador que la carpeta llamada `includes` contiene archivos de cabecera que deben ser incluidos en la compilacion
- `./src/FileReader.c`: otro archivo fuente, correspondiente al encabezado FileReader.h

> 💡 **Tip**
>
> Tendrás que modificar este comando luego, para poder compilar con tu código fuente. Recuerda que al final debes incluir tu instrucción de compilación en el archivo `instructions.txt`

Luego de compilar, deberá generarse un archivo ejecutable de salida llamado `analyzer.exe`. Ahora, ejecuta el programa:
```shell
./analyzer.exe
```

Se imprimirá en la consola las primeras 100 líneas, y se creará un archivo dentro de `code/` llamado `copia.txt`, que tiene solamente las primeras 100 líneas de test.txt. Esto significa que todo ha funcionado.
>💡 **Tip**
>
>Puedes modificar los #defines FILELINES_MAX_LINES en el archivo `FileReader.h` para leer todo el archivo.