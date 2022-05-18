#pragma once
#include "CuentaContratoRN.h"

class CuentaContratoV
{   
    private:
    CuentaContrato cuentaContrato;
    string nombreArchivo;
    CuentaContratoRN cuentaContratoRN;
    public:
    CuentaContratoV(string nombreArchivo);
    ~CuentaContratoV();
    void NuevaCuentaContrato();
    void ListarCuentaContrato();
    void ModificarCuentaContrato();
    void MenuModificarCuentaContrato();
    void MenuCuentaContrato();
    void setNombreArchivo(string nombreArchivo);
    string getNombreArchivo();
    void setCuentaContrato(CuentaContrato& cuentaContrato);
};