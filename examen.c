#include "estructuras.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;

    printf("Ingrese la cantidad de pacientes a registrar: ");
    scanf("%d", &n);

    Paciente *pacientes = (Paciente *)malloc(n * sizeof(Paciente));

    registrarPaciente(pacientes, n);
    reportePorCondicion(pacientes, n);
    reporteCondicionMaxima(pacientes, n);
    reportePorcentajeSexo(pacientes, n);
    reporteCondicionesPorSexo(pacientes, n);

    free(pacientes);

    return 0;
}