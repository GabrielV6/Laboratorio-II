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
    float _consumo; 
    int _numPosicionArch;
public:
    Medidor(int id,int idCuentaContrato, bool estado, float consumo,int nPosicion);
    Medidor();
    ~Medidor();
    void setId(int id);
    void setIdCuentaContrato(int idCuentaContrato);
    void setEstado(bool estado);
    void setConsumo(float consumo);
    int getId();
    int getIdCuentaContrato();
    bool getEstado();
    float getConsumo();

    string toStringMedidor();

    void setNumPosicionArchivo(int numPosArch);
    int getNumPosicionArhivo();

};