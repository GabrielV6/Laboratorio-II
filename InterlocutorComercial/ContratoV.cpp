/*
implementación de todos los métodos de la clase ContratoV.h
*/
#include "ContratoV.h"

ContratoV::ContratoV()
{
    this->nombreArchivo = "";
    this->InterlocutorComercial =(InterlocutorComercial)InterlocutorComercial();
    this->Contrato = Contrato();
}

ContratoV::ContratoV(string nombreArchivo, InterlocutorComercial& interCom, Contrato contrato)
{
    this->nombreArchivo = nombreArchivo;
    this->InterlocutorComercial = interCom;
    this->Contrato = contrato;
}

void ContratoV::setNombreArchivo(string nombreArchivo)
{
    this->nombreArchivo = nombreArchivo;
}

void ContratoV::setInterlocutorComercial(InterlocutorComercial& interCom)
{
    this->InterlocutorComercial = interCom;
}
void ContratoV::setInterlocutorComercial(InterlocutorComercial interCom)
{
    this->InterlocutorComercial = interCom;
}

void ContratoV::setContrato(Contrato contrato)
{
    this->Contrato = contrato;
}

InterlocutorComercial ContratoV::getInterlocutorComercial()
{
    return this->InterlocutorComercial;
}

Contrato ContratoV::getContrato()
{
    return this->Contrato;
}

void ContratoV::MenuContrato()
{
    int opcion;
    do
    {
        cout << "1. Nuevo Contrato" << endl;
        cout << "2. Modificar Contrato" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            if (NuevoContrato())
            {
                cout << "Contrato cargado correctamente" << endl;
            }
            else
            {
                cout << "Error al cargar el contrato" << endl;
            }
            break;
        case 2:
            if (ModificarContrato())
            {
                cout << "Contrato modificado correctamente" << endl;
            }
            else
            {
                cout << "Error al modificar el contrato" << endl;
            }
            break;
        case 3:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 3);
}

bool ContratoV::NuevoContrato()
{
    Contrato contratoNuevo;
    bool cargado = false;
    int opcion;
    do
    {        
        cout << "1. Cargar Contrato" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            if (contratoNuevo.NuevoContrato())
            {
                cout << "Contrato cargado correctamente" << endl;
            }
            else
            {
                cout << "Error al cargar el contrato" << endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 0);
    if (contratoNuevo.getIdContrato() != 0)
    {
        this->setContrato(contratoNuevo);
        cargado = true;
    }
    return cargado;
}
bool ContratoV::ModificarContrato()
{
    Contrato contratoModif;
    bool modificado = false;
    int opcion;
    do
    {
        cout << "1. Modificar Contrato" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            if (contratoModif.ModificarContrato())
            {
                cout << "Contrato modificado correctamente" << endl;
            }
            else
            {
                cout << "Error al modificar el contrato" << endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 3);
    if (contratoModif.getIdContrato() != 0)
    {
        this->setContrato(contratoModif);
        modificado = true;
    }
    return modificado;
}
ContratoV::~ContratoV()
{
}
