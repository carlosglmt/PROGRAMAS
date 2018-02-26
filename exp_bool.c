#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int parentesis_evaluador(char[]);

int main(){
	
	char cadena_booleana[100];

	puts("Ingresa una expresion booleana: ");
	scanf("%[^\n]%*c", &cadena_booleana);

	int contador = 0; 

	while(cadena_booleana[contador] != '\0')
		contador++;

	char expresion_booleana[contador]; 
	
	int contador2 = 0;

	while(contador2 < contador){
		expresion_booleana[contador2] = cadena_booleana[contador2];
		contador2++; 
	} 

	puts(""); 

	int elementos = 0 ;

	for(int i = 0; i < contador2; i++){
		if(expresion_booleana[i] == '('){
			elementos += 1;
			i += 4;
		}else if(expresion_booleana[i] == 'V' || expresion_booleana[i] == 'F')
			elementos += 1;

	}

	int valores[elementos];
	int j = 0;

	puts("");

	for (int i = 0; i < contador2; i++){

		if(expresion_booleana[i] == '('){
			char parentesis[3];
			parentesis[0] = expresion_booleana[i + 1];
			parentesis[1] = expresion_booleana[i + 2];
			parentesis[2] = expresion_booleana[i + 3];
			valores[j] = parentesis_evaluador(parentesis);
			j++;
			i += 5;	
		}else if(expresion_booleana[i] == 'V'){
			valores[j] = 1;
			j ++;
		}else if(expresion_booleana[i] == 'F'){
			valores[j] = 0;
			j++;
		}	

	}


	char operadores[elementos - 1];

	int contador_operadores = 0;

	for(int i = 0; i < contador2; i++){

		if (expresion_booleana[i] == '(')
			i += 4;
		else if(expresion_booleana[i] == '&' || expresion_booleana[i] == '|'){
			operadores[contador_operadores] = expresion_booleana[i];
			contador_operadores++;
		}
	}

	int bandera = 0, c_valores = 0, c_operadores = 0;

	bool v_final = valores[c_valores];
	c_valores++;

	while(bandera < elementos){

		if(operadores[c_operadores] == '&'){
			v_final  &= valores[c_valores];
			c_valores += 1;
			c_operadores += 1;
		}else if(operadores[c_operadores] == '|'){
			v_final |= valores[c_valores]; 
			c_valores += 1; 
			c_operadores += 1;
		}

		bandera++;
	}
	

	if(v_final == 0){
		printf("F\n");
	}else if(v_final == 1){
		printf("V\n");
	}else{
		printf("Hubo un error, no se ovtubo un valor booleano\n");
	}
	
	puts("");

	return EXIT_SUCCESS;
}


int parentesis_evaluador(char parentesis[]){

	if(parentesis[1] == '|'){

		if((parentesis[0] == 'V' )|| (parentesis[2] == 'V'))
			return 1;
		else
			return 0;
					
	}else if(parentesis[1] == '&'){
		if((parentesis[0] == 'V') && (parentesis[2] == 'V'))
			return 1;
		else
			return 0;
	}	
			
}




