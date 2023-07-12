#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    int longitud = 0;
    while (s != '\0'){
        longitud++;
        s++;
    }
    return longitud;
}

bool fstring_eq(fixstring s1, fixstring s2) {
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

bool fstring_less_eq(fixstring s1, fixstring s2) {
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

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(s2, aux);
    fstring_set(s1, s2);
    fstring_set(aux, s1);
}


