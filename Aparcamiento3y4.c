#include <stdio.h>
#include <string.h>
#define NPLAZAS 50

struct aparcamiento {
	int estado;
	char matricula[8], vehiculo;
};

void main() {
	int i = 1, j, a = 1, eleccion, numplazas = 0, b = 1, comparacion1, comparacion2;
	char opcion, vehiculo, matricula[8], usuario[20] = "admin", usuarioaux[20], contraseña[20] = "1234", contraseñaaux[20];
	struct aparcamiento plaza[NPLAZAS];

	while (i <= 3) {

		printf("Introduce el nombre de usuario: ");
		gets(usuarioaux);
		printf("Introduce la contraseña: ");
		gets(contraseñaaux);
		comparacion1 = strcmp(usuarioaux, usuario);
		comparacion2 = strcmp(contraseñaaux, contraseña);

		if (comparacion1 == 0 && comparacion2 == 0) {

			for (i = 0; i < NPLAZAS; i++) {
				plaza[i].estado = 0;
			}
			while (a == 1) {
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
				case 'r':
					if (numplazas >= NPLAZAS) {
						printf("El aparcamiento se encuentra lleno en estos momentos, lo sentimos\n");
						break;
					}
					printf("Introduce las caracteristicas del vehiculo: \n");
					printf("seleccione el tipo de vehiculo: \nC - Coche \nM - Moto\n");
					scanf_s("%c", &plaza[numplazas].vehiculo);
					getchar();
					while (plaza[numplazas].vehiculo != 'c' && plaza[numplazas].vehiculo != 'C' && plaza[numplazas].vehiculo != 'm' && plaza[numplazas].vehiculo != 'M') {
						printf("seleccione el tipo de vehiculo: \nC - Coche \nM - Moto\n");
						scanf_s("%c", &plaza[numplazas].vehiculo);
						getchar();
					}

					printf("Introduzca la matricula: ");
					scanf_s("%s", &plaza[numplazas].matricula, 8);
					getchar();
					for (i = 0; i < numplazas; i++) {

						if (strcmp(plaza[i].matricula, plaza[numplazas].matricula) == 0) {
							printf("Ya hay un vehiculo con esta matricula en el aparcamiento\n");
							numplazas--;
							break;
						}
						else {
							printf("Su vehiculo se encuentra en la plaza numero %d\n", numplazas + 1);
						}
					}
					plaza[numplazas].estado = 1;
					numplazas++;
					break;

				case 'A': // ABANDONAR LA PLAZA														ABANDONAR
				case 'a':
					if (plaza[0].estado == 0) {
						printf("El aparcamiento se encuentra vacio en estos momentos, lo sentimos\n");
						break;
					}

					printf("\nIntroduzca las caracteristicas del vehiculo que desea sacar:\n");

					printf("seleccione el tipo de vehiculo: \nC - Coche \nM - Moto\n");
					scanf_s("%c", &vehiculo);
					getchar();
					while (vehiculo != 'c' && vehiculo != 'C' && vehiculo != 'm' && vehiculo != 'M') {
						printf("Opcion incorrecta, pulse C si es coche, o M si es moto: ");
						scanf_s("%c", &vehiculo);
						getchar();
					}

					printf("Introduzca la matricula: \n");
					scanf_s("%s", &matricula, 8);
					getchar();

					for (i = 0; i < numplazas; i++) {

						if (strcmp(plaza[i].matricula, matricula) == 0) {
							printf("Su vehichulo ha abandonado el aparcamiento\n");

							for (j = i; j < numplazas; j++) {
								plaza[j] = plaza[j + 1];
							}
							numplazas--;
							b = 3;
							break;
						}
					}
					if (b != 3) {
						printf("No disponemos de ningun vehiculo con estas caracteristicas, lo sentimos\n");
					}
					break;


				case 'E': //OBSERVAR EL ESTADO DEL APARCAMIENTO											ESTADO
				case 'e': printf("El estado del aparcamiento es: \n");

					if (plaza[0].estado == 0) {
						printf("EL aparcamiento esta vacio\n");
						break;
					}
					for (i = 0; i < numplazas; i++) {

						printf("***Plaza numero %d***:\n", i + 1);
						printf("Tipo de vehiculo: ");
						switch (plaza[i].vehiculo) {
						case 'c':
						case 'C':
							printf("Coche     ");
							break;
						case 'm':
						case 'M':
							printf("Moto     ");
							break;
						default: printf("Error\n");
							break;
						}
						printf("Matricula: %s\n\n", plaza[i].matricula);

					}

					break;

				case 'b':// BUSCAR UN COCHE POR LA MATRICULA												BUSCAR
				case 'B':
					if (plaza[0].estado == 0) {
						printf("El aparcamiento se encuentra vacio en estos momentos, lo sentimos\n");
						break;
					}
					printf("Introduzca la matricula del vehiculo que desea buscar:");
					scanf_s("%s", matricula, 8);
					getchar();



					for (i = 0; i < numplazas; i++) {

						if (strcmp(plaza[i].matricula, matricula) == 0) {
							printf("Su vehichulo se encuentra en la plaza numero %d\n", i + 1);
							b = 4;
							break;
						}
					}
					if (b != 4) {
						printf("No disponemos de ningun vehiculo con estas caracteristicas, lo sentimos\n");
					}

					break;

				case 's': //SALIR																			SALIR
				case 'S': printf("Ha elegido salir del programa\n");
					a = 0;
					return;
					break;

				default: printf("La opcion es incorrecta\n");
					break;
				}
				system("pause");
			}
		}
		else {
			if (i == 3) {
				printf("Has agotado el numero de intentos\n");
				i++;
				system("pause");
				system("cls");
			}
			else {
				printf("Usuario o contraseña incorrectos, quedan %d intentos\n", 3 - i);
				i++;
				system("pause");
				system("cls");
			}
		}
	}
}