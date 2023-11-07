#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para registrar pacientes en el hospital
void registrarPaciente(Paciente *pacientes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese nombre y apellido del paciente %d: ", i + 1);
        scanf(" %49[^ \n]s", pacientes[i].nombre); // Leer nombre
        scanf(" %49[^\n]s", pacientes[i].apellido); // Leer apellido

        printf("Ingrese la edad: ");
        scanf("%d", &pacientes[i].edad);
        printf("Ingrese el sexo (M/F): ");
        scanf(" %c", &pacientes[i].sexo);
        printf("Ingrese la condición del paciente (1 al 5): ");
        scanf("%d", &pacientes[i].condicion);
        printf("Ingrese la calle: ");
        scanf(" %49[^\n]s", pacientes[i].domicilio.calle);
        printf("Ingrese el numero: ");
        scanf("%d", &pacientes[i].domicilio.numero);
        printf("Ingrese la colonia: ");
        scanf(" %49[^\n]s", pacientes[i].domicilio.colonia);
        printf("Ingrese el código postal: ");
        scanf("%d", &pacientes[i].domicilio.codigo_postal);
        printf("Ingrese la ciudad: ");
        scanf(" %49[^\n]s", pacientes[i].domicilio.ciudad);
        printf("Ingrese el teléfono: ");
        scanf(" %14[^\n]s", pacientes[i].telefono);
    }
}

// Función para mostrar el número de pacientes por cada condición
void reportePorCondicion(Paciente *pacientes, int n) {
    int contador[5] = {0};

    for (int i = 0; i < n; i++) {
        contador[pacientes[i].condicion - 1]++;
    }

    for (int i = 0; i < 5; i++) {
        printf("Numero de pacientes con condicion %d: %d\n", i + 1, contador[i]);
    }
}

// Función para mostrar el nombre y teléfono de los pacientes con la condición más grave
void reporteCondicionMaxima(Paciente *pacientes, int n) {
    int maxCondicion = 5;

    printf("Pacientes con la condicion mas grave (%d):\n", maxCondicion);
    for (int i = 0; i < n; i++) {
        if (pacientes[i].condicion == maxCondicion) {
            printf("Nombre: %s %s - Telefono: %s\n", pacientes[i].nombre, pacientes[i].apellido, pacientes[i].telefono);
        }
    }
}

// Función para calcular el porcentaje de pacientes hombres y mujeres
void reportePorcentajeSexo(Paciente *pacientes, int n) {
    int contadorHombres = 0, contadorMujeres = 0;

    for (int i = 0; i < n; i++) {
        if (pacientes[i].sexo == 'M') {
            contadorHombres++;
        } else if (pacientes[i].sexo == 'F') {
            contadorMujeres++;
        }
    }

    float porcentajeHombres = (float)contadorHombres / n * 100;
    float porcentajeMujeres = (float)contadorMujeres / n * 100;

    printf("Porcentaje de pacientes hombres: %.2f%%\n", porcentajeHombres);
    printf("Porcentaje de pacientes mujeres: %.2f%%\n", porcentajeMujeres);
}

// Función para mostrar las condiciones separadas por pacientes hombres y mujeres
void reporteCondicionesPorSexo(Paciente *pacientes, int n) {
    int contadorCondicionesHombres[5] = {0};
    int contadorCondicionesMujeres[5] = {0};

    for (int i = 0; i < n; i++) {
        if (pacientes[i].sexo == 'M') {
            contadorCondicionesHombres[pacientes[i].condicion - 1]++;
        } else if (pacientes[i].sexo == 'F') {
            contadorCondicionesMujeres[pacientes[i].condicion - 1]++;
        }
    }

    printf("Condiciones separadas por pacientes hombres:\n");
    for (int i = 0; i < 5; i++) {
        printf("Condicion %d: %d\n", i + 1, contadorCondicionesHombres[i]);
    }

    printf("Condiciones separadas por pacientes mujeres:\n");
    for (int i = 0; i < 5; i++) {
        printf("Condicion %d: %d\n", i + 1, contadorCondicionesMujeres[i]);
    }
}
