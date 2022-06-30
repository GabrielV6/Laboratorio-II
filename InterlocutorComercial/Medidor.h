#pragma once
#include <vector>
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

class Medidor {
private:
    int _id;
    int _idCuentaContrato;
    bool _estado;
    int _lectura;
    int _numPosicionArch;
public:
    Medidor(int id, int idCuentaContrato, bool estado, int lectura, int nPosicion);
    Medidor();
    ~Medidor();
    void setId(int id);
    void setIdCuentaContrato(int idCuentaContrato);
    void setEstado(bool estado);
    void setLectura(int lectura);
    void setNumPosicionArchivo(int numPosArch);

    int getId();
    int getIdCuentaContrato();
    bool getEstado();
    int getLectura();
    int getNumPosicionArhivo();

    string toStringMedidor();

};