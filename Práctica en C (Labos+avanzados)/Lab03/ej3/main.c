#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    unsigned int i = 0u;

    FILE *archivo;
    archivo=fopen(path, "r");

    if(archivo == NULL){
    printf("No se pudo abrir el archivo.\n");
    return 0;
    }

    while (i < max_size && !feof(archivo)){
          if(fscanf(archivo, "%u 'c'", &indexes[i], &letters[i])){
        i++;
    }
    }
    fclose(archivo);
    return i;
}

char *parse_filepath(int argc, char *argv[]) { 
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        //print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[]){
    FILE *file;
    unsigned int i = 0u;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
   char *filepath = NULL;
   filepath = parse_filepath(argc,argv);
   length = data_from_file(filepath,indexes,letters,MAX_SIZE);

    while (i < length){//aqui se ordenan los datos en el arreglo usando los indices dados en indexes.
        sorted[indexes[i]] = letters[i];
        i++;
    }
    
    dump(sorted, length);//se imprime el contenido ordenado

    return EXIT_SUCCESS;
}

