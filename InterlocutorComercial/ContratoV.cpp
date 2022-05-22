/*
implementación de todos los métodos de la clase ContratoV.h
*/
#include "ContratoV.h"

ContratoV::ContratoV()
{
    this->nombreArchivo = "";
    this->interlocutorComercial = InterlocutorComercial();
    this->contrato = Contrato();
}

ContratoV::ContratoV(string nombreArchivo)
{
    this->nombreArchivo = nombreArchivo;
    this->interlocutorComercial = InterlocutorComercial();
    this->contrato = Contrato();
}

void ContratoV::setNombreArchivo(string nombreArchivo)
{
    this->nombreArchivo = nombreArchivo;
}

void ContratoV::setContrato(Contrato &contrato)
{
    this->contrato = contrato;
}

string ContratoV::getNombreArchivo()
{
    return this->nombreArchivo;
}

Contrato ContratoV::getContrato()
{
    return this->contrato;
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
    ContratoRN contratoRN(this->nombreArchivo);
    InterlocutorComercial interComContrato = BuscarInterlocutorComercialPorID();
    bool cargado = false;
    long datoId, opcion;

    contratoNuevo.setIdInterlocutorComercial(interComContrato.getId_ic());
    //Buscar cuenta contrato
    datoId = contratoRN.IdContratoNuevo();
    contratoNuevo.setIdCuentaContrato(datoId);
    //Buscar medidior
    contratoNuevo.setIdMedidor(datoId);
    //Crear fecha alta contrato 
    contratoNuevo.setFechaAltaContrato(Fecha());
    //Poner una fecha estimativa de terminacion
    contratoNuevo.setFechaBajaContrato(Fecha());
    //Busacar id de instalacion
    contratoNuevo.setIdInstalacion(datoId);

    //contratoNuevo.setTarifas(Tarifas());

    if (contratoRN.AltaContrato(contratoNuevo))
    {
        cout << "Contrato cargado correctamente" << endl;
    }
    else
    {
        cout << "Error al cargar el contrato" << endl;
    }
    if (contratoNuevo.getIdContrato() != 0)
    {
        this->setContrato(contratoNuevo);
        cargado = true;
    }
    return cargado;
}

InterlocutorComercial ContratoV::BuscarInterlocutorComercialPorID()
{
    InterlocutorComercialRN interComRN(this->nombreArchivo);
    InterlocutorComercial interCom;
    unsigned int datoId;
    int opcion;
    string dato;
    do
    {
        cout << "Ingrese el Id del interlocutor comercial: ";
        cin >> dato;
        datoId = stoi(dato);
        interCom = interComRN.BuscarInterlocutorComercial(datoId);
        if (!interCom.getActivo())
        {
            cout << "El interlocutor comercial no existe" << endl;
            cout << "Desea ingresar unevamente el Id del interlocutor comercial? (1. Si, 2. No): ";
            cin >> opcion;
        }
        else
            break;

    } while (opcion != 2);
    return interCom;
}

bool ContratoV::ModificarContrato()
{
    ContratoRN contratoRN(this->nombreArchivo);
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
            contratoModif = BuscarContrato();
            if (contratoModif.getActivo())
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

Contrato ContratoV::BuscarContrato()
{
    InterlocutorComercialRN interComRN(this->nombreArchivo);
    ContratoRN contratRN(this->nombreArchivo);
    Contrato contrato;
    int datoId, opcion;
    do
    {
        cout << "Ingrese el Id del contrato: ";
        cin >> datoId;
        contrato = contratRN.BuscarContrato(datoId);
        if (!contrato.getActivo())
        {
            cout << "El contrato no existe" << endl;
            cout << "Desea ingresar unevamente el Id del contrato? (1. Si, 2. No): ";
            cin >> opcion;
        }
        else
            break;

    } while (opcion != 2);
    return contrato;
}

ContratoV::~ContratoV()
{
}
