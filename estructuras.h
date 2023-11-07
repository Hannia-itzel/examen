#pragma once

// Estructura para la dirección del paciente
typedef struct {
    char calle[50];
    int numero;
    char colonia[50];
    int codigo_postal;
    char ciudad[50];
} Direccion;

// Estructura para la información del paciente
typedef struct {
    char nombre[50];
    char apellido[50];
    int edad;
    char sexo;
    int condicion;
    Direccion domicilio;
    char telefono[15];
} Paciente;