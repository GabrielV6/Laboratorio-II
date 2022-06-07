#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Medidor {
private:
    int _id;
    bool _estado;
    float _erc;
    float _eri;
    float _eat;
    float _ert;
    float _erp;
public:
    Medidor(int id, bool estado, float erc, float eri, float eat, float ert, float erp);
    Medidor();
    ~Medidor();
    void setId(int id);
    void setEstado(bool estado);
    void setErc(float erc);
    void setEri(float eri);
    void setEat(float eat);
    void setErt(float ert);
    void setErp(float erp);
    int getId();
    bool getEstado();
    float getErc();
    float getEri();
    float getEat();
    float getErt();
    float getErp();


};