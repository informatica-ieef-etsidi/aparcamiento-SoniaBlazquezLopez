#include <stdio.h>

void main() {
	int i, a = 1, eleccion, plaza1c = 0, plaza2c = 0, plaza1m = 0, plaza2m = 0;
	char opcion, matricula1m[8], matricula2m[8], matricula1c[8], matricula2c[8], matricula[8], vehiculo;
	
	while (a==1) {
		system("cls");
		printf("Seleccione una de estas opciones:\n");
		printf("R - Reservar una plaza\n");
		printf("A - Abandornar la plaza\n");
		printf("E - Estado del aparcamiento\n");
		printf("B - Buscar un vehiculo por matricula\n");
		printf("S - Salir del programa\n");
		scanf_s("%c", &opcion, 1);
		getchar();

		switch (opcion) {
		case 'R':// RESERVAR LA PLAZA															RESERVAR
		case 'r': printf("seleccione el tipo de vehiculo: \nC - Coche \nM - Moto\n");
			scanf_s("%c", &vehiculo);
			switch (vehiculo) {
			case 'c':
			case 'C': 
				printf("Seleccione la plaza que desea reservar:\n");
				printf("1 - Plaza numero 1\n");
				printf("2 - Plaza numero 2\n");
				scanf_s("%d", &eleccion);
				getchar();
				switch (eleccion)
				{
				case 1: printf("Ha elegido la plaza numero 1; cuyo estado es:  ");
					if (plaza1c == 0) {
						printf("Libre\n");
						printf("Introduzca la matricula: \n");
						scanf_s("%s", matricula1c, 8);
						getchar();
						plaza1c = 1;
						printf("Plaza reservada\n");
					}
					else {
						printf("Ocupada\n");
					}
					break;
				case 2: printf("Ha elegido la plaza numero 2; cyuo estado es: ");
					if (plaza2c == 0) {
						printf("Libre\n");
						printf("Introduzca la matricula: \n");
						scanf_s("%s", matricula2c, 8);
						getchar();
						plaza2c = 1;
						printf("Plaza reservada\n");
					}
					else {
						printf("Ocupada\n");
					}
					break;

				default: printf("No disponemos todavia de esa plaza\n");
					break;
				}
				break;

			case 'm':
			case 'M':
				printf("Seleccione la plaza que desea reservar:\n");
				printf("1 - Plaza numero 1\n");
				printf("2 - Plaza numero 2\n");
				scanf_s("%d", &eleccion);
				getchar();
				switch (eleccion)
				{
				case 1: printf("Ha elegido la plaza numero 1; cuyo estado es:  ");
					if (plaza1m == 0) {
						printf("Libre\n");
						printf("Introduzca la matricula: \n");
						scanf_s("%s", matricula1m, 8);
						getchar();
						plaza1m = 1;
						printf("Plaza reservada\n");
					}
					else {
						printf("Ocupada\n");
					}
					break;
				case 2: printf("Ha elegido la plaza numero 2; cyuo estado es: ");
					if (plaza2m == 0) {
						printf("Libre\n");
						printf("Introduzca la matricula: \n");
						scanf_s("%s", matricula2m, 8);
						getchar();
						plaza2m = 1;
						printf("Plaza reservada\n");
					}
					else {
						printf("Ocupada\n");
					}
					break;

				default: printf("No disponemos todavia de esa plaza\n");
					break;
				}
				break;
			default: printf("La opcion es incorrecta\n");
				break;
			}

			break;

		case 'A': // ABANDONAR LA PLAZA														ABANDONAR
		case 'a': printf("Seleccione el tipo de vehiculo:\nC - coche\nM - Moto\n");
			scanf_s("%c", &vehiculo);
			switch (vehiculo) {

			case 'c':
			case 'C':
				printf("Elija la plaza que desea abandonar:\n");
				printf("1 - Plaza 1\n2 - Plaza 2\n");
				scanf_s("%d", &eleccion);
				getchar();
				switch (eleccion) {

				case 1: printf("Has elegido la plaza 1 de coche\n");
					if (plaza1c == 0) {
						printf("La plaza ya estaba libre\n");
						plaza1c = 0;
					}
					else {
						printf("Acaba de abandonar la plaza\n");
						plaza1c = 0;
					}
					break;
				case 2: printf("Has elegido la plaza 2 de coche\n");
					if (plaza2c == 0) {
						printf("La plaza ya estaba libre\n");
						plaza2c = 0;
					}
					else {
						printf("Acaba de abandonar la plaza\n");
						plaza2c = 0;
					}
					break;
				default: printf("No disponemos de esta plaza todavia\n");
					break;
				}
				break;

			case 'm':
			case 'M':
				printf("Elija la plaza que desea abandonar:\n");
				printf("1 - Plaza 1\n2 - Plaza 2\n");
				scanf_s("%d", &eleccion);
				getchar();
				switch (eleccion) {

				case 1: printf("Has elegido la plaza 1 de moto\n");
					if (plaza1m == 0) {
						printf("La plaza ya estaba libre\n");
						plaza1m = 0;
					}
					else {
						printf("Acaba de abandonar la plaza\n");
						plaza1m = 0;
					}
					break;
				case 2: printf("Has elegido la plaza 2 de moto\n");
					if (plaza2m == 0) {
						printf("La plaza ya estaba libre\n");
						plaza2m = 0;
					}
					else {
						printf("Acaba de abandonar la plaza\n");
						plaza2m = 0;
					}
					break;
				default: printf("No disponemos de esta plaza todavia\n");
					break;
				}
				break;
			default:
				break;
			}

			break;
		case 'E': //OBSERVAR EL ESTADO DEL APARCAMIENTO											ESTADO
		case 'e': printf("El estado del aparcamiento es: \n");

			printf("Plaza 1 de coche: ");
			if (plaza1c != 0) {
				printf("Ocupada - Matricula: %s\n", matricula1c);					
			}
			else{
				printf("Libre\n");
			}

			printf("Plaza 2 de coche: ");
			if (plaza2c != 0) {
				printf("Ocupada - Matricula: %s\n", matricula2c);
			}
			else {
				printf("Libre\n");
			}

			printf("Plaza 1 de moto: ");
			if (plaza1m != 0) {
				printf("Ocupada - Matricula: %s\n", matricula1m);
			}
			else {
				printf("Libre\n");
			}

			printf("Plaza 2 de moto: ");
			if (plaza2m != 0) {
				printf("Ocupada - Matricula: %s\n", matricula2m);
			}
			else {
				printf("Libre\n");
			}
			break;

		case 'b':// BUSCAR UN COCHE POR LA MATRICULA												BUSCAR
		case 'B': printf("Introduzca la matricula del vehiculo que desea buscar:");
			scanf_s("%s", matricula, 8);
			getchar();

			if (strcmp(matricula, matricula1c) == 0) {
				printf("Su vehiculo se encuentra en la plaza 1 de coche\n");
			}
			else if (strcmp(matricula, matricula2c) == 0) {
				printf("Su vehicuo se encuentra en la plaza 2 de coche\n");
			}
			
			else if (strcmp(matricula, matricula1m) == 0) {
				printf("Su vehiculo se encuentra en la plaza 1 de moto\n");
			}
			else if (strcmp(matricula, matricula2m) == 0) {
				printf("Su vehicuo se encuentra en la plaza 2 de moto\n");
			}
	
			else {
				printf("Su vehiculo no se encuentra en el aparcamiento\n");
			}
			break;

		case 's': //SALIR																			SALIR
		case 'S': printf("Ha elegido salir del programa\n");
			a = 0;
			break;

		default: printf("La opcion es incorrecta\n");
			break;
		}
		system("pause");
	}

}