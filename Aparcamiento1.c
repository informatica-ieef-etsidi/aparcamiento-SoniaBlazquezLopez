#include <stdio.h>

void main() {
	int i, eleccion, plaza1=0, plaza2=0;
	char opcion, matricula1[8], matricula2[8];

	while (1) {
		system("cls");
		printf("Seleccione una de estas opciones:\n");
		printf("R - Reservar una plaza\n");
		printf("A - Abandornar la plaza\n");
		printf("E - Estado del aparcamiento\n");
		scanf_s("%c", &opcion, 1);
		getchar();

		switch (opcion) {
		case 'R':
		case 'r': printf("Seleccione la plaza que desea reservar:\n");
			printf("1 - Plaza numero 1\n");
			printf("2 - Plaza numero 2\n");
			scanf_s("%d", &eleccion);
			getchar();
			switch (eleccion)
			{
			case 1: printf("Ha elegido la plaza numero 1; cuyo estado es:  ");
				if (plaza1 == 0) {
					printf("Libre\n");
					printf("Introduzca la matricula: \n");
					scanf_s("%s", matricula1, 8);
					getchar();
					printf("La matricula introducida es: %s\n", matricula1);
					plaza1 = 1;
				}
				else {
					printf("Ocupada\n");
				}
				break;
			case 2: printf("Ha elegido la plaza numero 2; cyuo estado es: ");
				if (plaza2 == 0) {
					printf("Libre\n");
					printf("Introduzca la matricula: \n");
					scanf_s("%s", matricula2, 8);
					getchar();
					printf("La matricula introducida es: %s\n", matricula2);
					plaza2 = 1;
				}
				else {
					printf("Ocupada\n");
				}
				break;

			default: printf("No disponemos todavia de esa plaza\n");
				break;
			}

			break;
		case 'A': 
		case 'a': printf("Elija la plaza que desea abandonar:\n");
			printf("1 - Plaza 1\n2 - Plaza 2\n");
			scanf_s("%d", &eleccion);
			getchar();
			switch (eleccion){

			case 1: printf("Has elegido la plaza 1\n");
				if (plaza1 == 0) {
					printf("La plaza ya esta libre\n");
				}
				else {
					printf("La plaza ha sido abandonada\n");
					plaza1 = 0;
				}
				break;
			case 2: printf("Has elegido la plaza 2\n");
				if (plaza2 == 0) {
					printf("La plaza ya esta libre\n");
				}
				else {
					printf("La plaza ha sido abandonada\n");
					plaza2 = 0;
				}
				break;
			default: printf("No disponemos de esta plaza todavia\n");
				break;
			}


			break;
		case 'E': 
		case 'e': printf("El estado del aparcamiento es: \n");

			printf("Plaza 1: ");
			if (plaza1==0){
				printf("Ocupada - Matricula: %c\n", matricula1);
			}
			else{
				printf("Libre\n");
			}

			printf("Plaza 2: ");
			if (plaza2 == 0) {
				printf("Ocupada - Matricula: %c\n", matricula2);
			}
			else {
				printf("Linre\n");
			}
			break;

		default: printf("La opcion es incorrecta\n");
			break;
		}


		system("pause");
	}

}