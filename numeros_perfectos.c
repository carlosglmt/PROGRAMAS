#include<stdio.h>
#include<stdlib.h>

int main(){

    int e;
    scanf("%d", &e);

    int contador = 0;
    int valor_inicial[e], valores_siguientes[e];

    while(contador < e){

        scanf("%d%d", &valor_inicial[contador], &valores_siguientes[contador]);
        contador++;

    }

    for(int x = 0; x < e; x++)
        for(int y = 0; y < valores_siguientes[x] + 1; y++){
            int suma = 0;
            for(int z = 1; z < valor_inicial[x] + y; z++){
                if((valor_inicial[x] + y) % z == 0)
                    suma += z;
            }
            if(suma == (valor_inicial[x] + y))
                printf("%d es perfecto\n", valor_inicial[x] + y);
            else
               printf("%d no es perfecto\n", valor_inicial[x] + y);
            
        }
    
    return EXIT_SUCCESS;
}
