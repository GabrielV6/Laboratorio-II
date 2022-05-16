/*
implementación de todos los métodos de la clase ContratoV.h
*/
#include "ContratoV.h"
ContratoV::ContratoV()
{
}
void ContratoV::setInterlocutorComercial(InterlocutorComercial interCom)
{
    this->InterlocutorComercial = interCom;
}
InterlocutorComercial ContratoV::getInterlocutorComercial()
{
    return this->InterlocutorComercial;
}
void ContratoV::setContrato(Contrato contrato)
{
    this->Contrato = contrato;
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
    InterlocutorComercial interCom;
    Contrato contrato;
    bool cargado = false;
    int opcion;
    do
    {
        cout << "1. Cargar Interlocutor Comercial" << endl;
        cout << "2. Cargar Contrato" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            if (interCom.NuevoInterlocutorComercial())
            {
                cout << "Interlocutor Comercial cargado correctamente" << endl;
            }
            else
            {
                cout << "Error al cargar el Interlocutor Comercial" << endl;
            }
            break;
        case 2:
            if (contrato.NuevoContrato())
            {
                cout << "Contrato cargado correctamente" << endl;
            }
            else
            {
                cout << "Error al cargar el contrato" << endl;
            }
            break;
        case 3:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 3);
    if (interCom.getIdInterlocutorComercial() != 0 && contrato.getIdContrato() != 0)
    {
        this->setInterlocutorComercial(interCom);
        this->setContrato(contrato);
        cargado = true;
    }
    return cargado;
}
bool ContratoV::ModificarContrato()
{
    InterlocutorComercial interCom;
    Contrato contrato;
    bool modificado = false;
    int opcion;
    do
    {
        cout << "1. Modificar Interlocutor Comercial" << endl;
        cout << "2. Modificar Contrato" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            if (interCom.ModificarInterlocutorComercial())
            {
                cout << "Interlocutor Comercial modificado correctamente" << endl;
            }
            else
            {
                cout << "Error al modificar el Interlocutor Comercial" << endl;
            }
            break;
        case 2:
            if (contrato.ModificarContrato())
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
    if (interCom.getIdInterlocutorComercial() != 0 && contrato.getIdContrato() != 0)
    {
        this->setInterlocutorComercial(interCom);
        this->setContrato(contrato);
        modificado = true;
    }
    return modificado;
}
ContratoV::~ContratoV()
{
}
