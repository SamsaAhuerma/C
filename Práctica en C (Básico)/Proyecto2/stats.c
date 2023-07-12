#include <stdio.h>

struct datos_t {
    float maximo;
    float minimo;
    float promedio;
};

struct datos_t stats(float a[], int tam)
{
    int i;
    i = 0;
    float min = a[0];
    float max = a[0];
    float prom;
    float sum = 0.0;

    struct datos_t rtn;

    while (i < tam){

    sum = sum + a[i];

    if (a[i] <= min){
    min = a[i];
    i = i+1;
    }
    else if (a[i] >= max) {
        max = a[i];
        i = i + 1;
    }
    else {
    i = i+1;
    }


    }

    prom = (sum / tam);

    rtn.maximo = max;
    rtn.minimo = min;
    rtn.promedio = prom;

    return rtn;
}

float pedirFloat(void){
    float x;
    printf("escriba un entero \n");
    scanf("%f", &x);
    return x;
}

void pedirArreglo(float a[], int n_max)
{
    int i = 0;
    while (i < n_max){
    a[i] = pedirFloat();
    i++;
    }
}

int main(){
    int n;
    struct datos_t stu;
    printf("Por favor introduzca el largo de la array: ");
    scanf("%d", &n);

    float a[n];
    pedirArreglo(a, n);

    stu = stats (a, n);
    printf("minimo = %f\nmaximo = %f\npromedio = %f\n", stu.minimo, stu.maximo, stu.promedio);
    return 0;

}
