#include <stdio.h>
#define TAM 100

int main(){
  int a[TAM][TAM], b[TAM][TAM], c[TAM][TAM];
  int m, n, p, q;
  int i, j;

  do{
    printf("Ingresa las dimensiones de la primer matriz\n");
    scanf("%d %d", &m, &n);
    printf("Ingresa las dimensiones de la segunda matriz\n");
    scanf("%d %d", &p, &q);
  }while(m!=p || n!=q || m <=0 || n<=0 || p <= 0 ||  q <=0);


  for(i =0; i <m; i++){
    for(j=0; j <n ; j++){
      scanf("%d", &a[i][j]);
    }
  }

  //TODO(1): Colocar el código para leer la segunda matriz

  //TODO(2): Colocar el código para sumar las matrices

  //TODO(3): Colocar el código para mostrar la matriz C

  return 0;
}
