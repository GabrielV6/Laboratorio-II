#pragma once
#include <fstream>
#include "Direccion.h"
#include "Fecha.h"

class InterlocutorComercial
{
private:
	int id_ic;
	char nombre[30];
	char apellido[30];
	int dni;
	char email[50];
	Fecha fechaIngresoID;
	Direccion direccionID;
	int numPosicionArch;
	bool activo;
public:
	InterlocutorComercial();
	~InterlocutorComercial();
	void setId_ic(int id_ic);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setDni(int dni);
	void setEmail(string email);
	void setFechaIngresoId(Fecha fechaIn);
	void setDireccionId(Direccion& direccionId);
	void setNumPosicionArchivo(int numPosArch);
	void setActivo(bool activo);
	int getId_ic();
	string getNombre();
	string getApellido();
	int getDni();
	string getEmail();
	Fecha getFechaIngresoId();
	Direccion& getDireccionId();
	int getNumPosicionArhivo();
	bool getActivo();
	string toStringInterlocutor(bool verId = false, bool verDir = false);
};
