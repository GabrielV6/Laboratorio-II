#pragma once
#include "TarifaRN.h"

class TarifaV
{
    private:
    Tarifa tarifa;
    string nombreArchivo;
    TarifaRN tarifaRN;
    public:
    TarifaV(string nombreArchivo);
    TarifaV();
    ~TarifaV();
    void NuevaTarifa();
    void ListarTarifa();
    void ModificarTarifa();
    void MenuModificarTarifa();
    void MenuTarifa();
    void setNombreArchivo(string nombreArchivo);
    string getNombreArchivo();
    void setTarifa(Tarifa& tarifa);
};
