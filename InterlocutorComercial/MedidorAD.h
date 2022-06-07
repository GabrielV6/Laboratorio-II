#pragma once

#include "Medidor.h"

using namespace std;

class MedidorAD {
public:
    MedidorAD(string nombreArchivo = "");
    ~MedidorAD();
    void setNombreArchivo(string nombreArchivo);
    string getNombreArchivo();
    long TotalMedidoresEnArchivo();
    bool GuardarEnArchivoMedidor(Medidor& medidor);
    bool ActualizarEnArchivoMedidor(Medidor& medidor);
    Medidor getMedidorArchivo(long dni);
    vector<Medidor> getMedidoresArchivo();
private:
    string _nombreArchivo;
    vector<Medidor> _medidores;
};


