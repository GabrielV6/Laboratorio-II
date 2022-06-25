#pragma once

#include "TarifaRN.h"

class TarifaV {
private:
    Tarifa tarifa;
    TarifaRN tarifaRN;
    string nombreArchivo;
    string separador = "-------------------------------------------------------------------------------------------------------------";
public:
    TarifaV(string nombreArchivo = "");
    ~TarifaV();

    void setTarifa(Tarifa& tarifa);
    void setNombreArchivo(string nombreArchivo);

    string getNombreArchivo();
    Tarifa getTarifa();

    void MenuTarifa();
    void NuevaTarifa();
    void ListarTarifa();
    void ModificarTarifa();

};