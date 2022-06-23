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
    float _lectura; 
    int _numPosicionArch;
public:
    Medidor(int id,int idCuentaContrato, bool estado, float lectura,int nPosicion);
    Medidor();
    ~Medidor();
    void setId(int id);
    void setIdCuentaContrato(int idCuentaContrato);
    void setEstado(bool estado);
    void setLectura(float lectura);
    long getId();
    int getIdCuentaContrato();
    bool getEstado();
    float getLectura();

    string toStringMedidor();

    void setNumPosicionArchivo(int numPosArch);
    int getNumPosicionArhivo();

};