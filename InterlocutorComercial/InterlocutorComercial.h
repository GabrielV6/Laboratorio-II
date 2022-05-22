#pragma once
#include <fstream>
#include "Direccion.h"
#include "Fecha.h"

class InterlocutorComercial
{
private:
	unsigned int id_ic;
	char nombre[30];
	char apellido[30];
	unsigned int dni;
	char email[50];
	Fecha fechaIngresoID;
	Direccion direccionID;
	unsigned int numPosicionArch;
	char nombreArchivo[30];
	bool activo;
public:
	InterlocutorComercial();
	InterlocutorComercial(string nombreArchivo);
	~InterlocutorComercial();
	void setId_ic(unsigned int id_ic);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setDni(unsigned int dni);
	void setEmail(string email);
	void setFechaIngresoId(Fecha fechaIn);
	void setDireccionId(Direccion direccionId);
	void setNumPosicionArchivo(unsigned int numPosArch);
	void setNombreArchivo(string nomArch);
	void setActivo(bool activo);
	unsigned int getId_ic();
	string getNombre();
	string getApellido();
	unsigned int getDni();
	string getEmail();
	Fecha getFechaIngresoId();
	Direccion getDireccionId();
	unsigned int getNumPosicionArhivo();
	string getNombreArchivo();
	bool getActivo();
	string toStringInterlocutor();	
};
