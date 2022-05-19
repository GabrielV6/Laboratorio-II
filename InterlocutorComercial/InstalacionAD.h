#pragma once

#include "Instalacion.h"

class InstalacionAD {
public:
    InstalacionAD(string nombreArchivo = "");
    ~InstalacionAD();
    void setNombreArchivo(string nombreArchivo);
    string getNombreArchivo();
    long TotalInstalacionesEnArchivo();
    bool GuardarEnArchivoInstalacion(Instalacion& instalacion);
    bool ActualizarEnArchivoInstalacion(Instalacion& instalacion);
    Instalacion getInstalacionArchivo(long dni);
    vector<Instalacion> getInstalacionesArchivo();
private:
    string _nombreArchivo;
    vector<Instalacion> _instalaciones;
};