#pragma once

#include <vector>
#include "Fecha.h"
#include "Direccion.h"

class Instalacion {

private:
    int _idMedidor;
    int _idInstalacion;
    Direccion _direccionServicio;
    Fecha _fechaInstalacion;

public:
    Instalacion(int idInstalacion, int idInterlocutorComercial, int idCuentaContrato, int idContrato, Direccion direccionServicio, string nombreApellido, int idMedidor);
    Instalacion();
    ~Instalacion();
    void setIdInstalacion(int idInstalacion);
    void setDireccionServicio(Direccion direccionServicio);
    void setIdMedidor(int idMedidor);
    int getIdInstalacion();
    Direccion getDireccionServicio();
    string getNombreApellido();
    int getIdMedidor();

};