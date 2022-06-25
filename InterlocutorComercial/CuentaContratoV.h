#pragma once
#include "CuentaContratoRN.h"

class CuentaContratoV
{   
private:
    CuentaContrato cuentaContrato;
    CuentaContratoRN cuentaContratoRN;
    string nombreArchivo;
    string separador = "-------------------------------------------------------------------------------------------------------------";
public:
    CuentaContratoV(string nombreArchivo);
    ~CuentaContratoV();

    void setCuentaContrato(CuentaContrato& cuentaContrato);
    void setNombreArchivo(string nombreArchivo);

    string getNombreArchivo();
    CuentaContrato getCuentaContrato();

    void MenuCuentaContrato();
    void NuevaCuentaContrato();
    void ListarCuentaContrato(bool activo);
    void ModificarCuentaContrato();
      
};