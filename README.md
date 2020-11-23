# Proyecto 3
Programación estructurada

Este proyecto consiste en dos etapas: una primera de compilación de código preexistente y la segunda de modificación de funcionalidades.

## Etapa 1: Proyecto base
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
├── instructions.txt │   # archivo con instrucciones
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

## Parte 2: Mejoras del proyecto
A continuación, se describen los cambios que se deben efectuar sobre el programa base. Básicamente habrá dos cosas que tendrán que implementar:

1. Implementar las funciones que están definidas en los archivos `FileInfo.h` y `FileProcessing.h`. Estas funciones utilizan la estructura FileLines definida en `FileReader.h` y generan algunos resultados o modifican el struct. Usarán estas funciones en el siguiente paso.
2. Que el usuario pueda especificar, desde la ejecución del programa:
    1. Qué archivo quiere leer
    2. Qué operación desea realizar
3. El argumento que requiera la operación a realizar.

### Implementación de FileInfo.h y FileProcessing.h
En la carpeta `includes/` podrán encontrar los archivos de cabecera, con las funciones que deben implementar.

Cada implementación debe tener su propio archivo; en total, crearás `FileInfo.c` y `FileProcessing.c`. Estos archivos deben ser colocados en la carpeta`src/` y, para compilarlos, se necesitará que los incluyas en la instrucción de compilación.

### Argumentos de programa
El proyecto base siempre lee el mismo archivo (`test.txt`) y no realiza ninguna operación sobre él. El comportamiento deseado es que el usuario pueda especificar, al ejecutar el programa, qué archivo desea analizar y qué operación realizar.

En caso de un error, el programa debe mostrar un mensaje y salir.

>💡**Tip**:
>
>Recuerden que la función main puede recibir argumentos, que se indican desde la ejecución del programa, y son recibidos como una lista de strings.
>
>Ustedes pueden tomar esa lista de strings e identificar qué operación se quiere realizar (¿alguien dijo `strcmp`?) y, dependiendo de esto, interpretar el tercer argumento. Al final, es muy parecido a los menús, pero se leen todos los argumentos al arrancar el programa y luego se evalúan.

Este es el formato de ejecución del programa:
```shell
./analyzer <filename> <operation> <argument>
```
- `filename`: nombre del archivo que se quiere analizar, por ejemplo `prueba.txt`
- `operation`: una palabra con la operacion a ejecutar, por ejemplo `countChar`
- `argument`: una palabra o una letra con el argumento que usará operation, por ejemplo `a` para que la operacion `countChar` cuente las letras `a`.

#### Algunos ejemplos de uso

**Contar las veces que aparece la letra `a` en el archivo `test.txt`**
```shell
> ./analyzer test.txt findChar a
La letra a aparece 35 veces en test.txt.
```

**Contar las palabras en el archivo `test.txt`**
```shell
> ./analyzer test.txt countWords
Hay 322 palabras en test.txt.
```

**Leer el archivo `test.txt`, ordenarlo y guardarlo en `sorted.txt`**
```shell
> ./analyzer test.txt sort sorted.txt
Se ha guardado sorted.txt
```

### Operaciones soportadas
El programa tendrá dos tipos de operaciones: de información y de procesamiento. Las de información sólo muestran un resultado en la pantalla, mientras que las de procesamiento generarán un archivo nuevo de salida.

#### Operaciones de información
Estas operaciones se definen en el archivo de cabecera `FileInfo.h`, y son las siguientes:

1. **FindChar**: Lee el archivo `filename` y cuenta la cantidad de veces que aparece el caracter indicado en `argument`

**Ejemplo:**
```shell
> ./analyzer test.txt findChar a
La letra a aparece 35 veces en test.txt.
```

2. **countWords**: lee el archivo `filename` y cuenta las palabras que contiene. En este caso no se necesita el tercer argumento.

**Ejemplo**
```shell
> ./analyzer test.txt countWords
Hay 322 palabras en test.txt.
```

>💡 **Tip**:
>
>Esta función es muy parecida a la de su examen, pero debe considerar también que puede haber palabras separadas por más de un espacio.

#### Operacions de procesamiento
Las operaciones de procesamiento modifican el struct FileLines y usan la función `saveLinesToFile()` para crear un archivo, especificado por el usuario.

Para estas operaciones, el argumento `argument` siempre debe ser el nombre de un archivo a donde se guardarán los resultados, por ejemplo `sorted.txt`.

Estas operaciones están descritas en el archivo `FileProcessing.h` y son las siguientes:

1. **sort**: lee el archivo `filename`, ordena las líneas del struct FileLines en orden alfabético y guarda en el archivo indicado por el usuario en `argument`

**Ejemplo**
```shell
> ./analyzer test.txt sort sorted.txt
Se ha guardado sorted.txt
```

>💡 **Tip**:
>
>Puedes usar el algoritmo que ya trabajamos de bubblesort pero que en lugar de intercambiar dos numeros, que intercambie dos strings usando `strcpy`.