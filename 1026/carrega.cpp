#include <iostream>
#include <strings.h>
#include <cstring>

#define MAX_NAME_SZ 400

using namespace std;
 
int main() {
    char entrada[251];
    char eof[1] = {EOF};
    char * pch;
    int a,b,soma;
    fgets (entrada, MAX_NAME_SZ, stdin);
    printf("\tEntrada = %s\n",entrada);
    while(strcasecmp(entrada,eof) != 0){
        pch = strtok(entrada," ");
        a = (int)strtol(pch,NULL,10);
        pch = strtok (NULL, " ");
        b = (int)strtol(pch,NULL,10);
        printf("\ta = %d b = %d\n",a,b);
        soma = (~a & b) | (a & ~b);
        printf("%d\n",soma);
        fgets (entrada, MAX_NAME_SZ, stdin);
    }
    return 0;
}