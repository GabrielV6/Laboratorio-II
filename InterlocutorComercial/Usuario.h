#pragma once
#include <fstream>
#include "Direccion.h"
#include "Fecha.h"

class Usuario
{
private:
	long id_us;
	char nombre[30];
	char apellido[30];
	long dni;
	char email[50];
	Fecha fechaIngresoID;
	Direccion direccionID;
	long numPosicionArch;
	char nombreArchivo[30];
	bool activo;
public:
	Usuario();
	Usuario(string nombreArchivo);
	~Usuario();
	void setId_us(long id_us);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setDni(long dni);
	void setEmail(string email);
	void setFechaIngresoId(Fecha fechaIn);
	void setDireccionId(Direccion direccionId);
	void setNumPosicionArchivo(long numPosArch);
	void setNombreArchivo(string nomArch);
	void setActivo(bool activo);
	long getId_us();
	string getNombre();
	string getApellido();
	long getDni();
	string getEmail();
	Fecha getFechaIngresoId();
	Direccion getDireccionId();
	long getNumPosicionArhivo();
	string getNombreArchivo();
	bool getActivo();
	string toStringUsuario();	
};
