#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s){//devuelve la longitud de la cadena guardada en el parametro s
    int longitud = 0;
    while (s != '\0'){
        longitud++;
        s++;
    }
    return longitud;
} 
/*unsigned int fstring_length(fixstring s){//devuelve la longitud de la cadena guardada en el parametro s
    int longitud = 0;
    unsigned int i = 0;
    while (i = 0, i < s){
        longitud++;
        i++;
    }
    return longitud;
} */

/*bool fstring_eq(fixstring s1, fixstring s2) {//indica si las cadenas s1 y s2 son iguales(contienen la misma cadena)
    unsigned int i = 0;
    while (s1 != '\0' && s2 != '\0'){
        if (s1 != s2){//las cadenas tienen longitudes distintas
            return false;
        } 
        i++;
    }
    return true;
} */

bool fstring_eq(fixstring s1, fixstring s2) {//indica si las cadenas s1 y s2 son iguales(contienen la misma cadena)
    unsigned int i = 0;
    unsigned int j = 0;
    while (s1 != '\0' && s2 != '\0'){
        if (s1[i] != s2[j]){//las cadenas son distintas
            return false;
        }
        i++;
    }
    return true;
}


bool fstring_less_eq(fixstring s1, fixstring s2) {// indica si la cadena guardada en s1 es menor o igual que la guardada en s2
    unsigned int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] < s2[i]){
            return true;  
        } else if(s1[i] > s2[i]){
            return false;
        }
        i++;
    }
    if (s2[i] == '\0'){//si S2 es igual al \0 llegamos a su final entonces quiere decir que es mas corto
        return true; //s1 seria mas chica que s2
    }else{
        return false;
    }   
}

