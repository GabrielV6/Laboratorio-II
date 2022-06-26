#pragma once
#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>

using namespace std;

const string NOMBRE_ARCH_IC = "interlocutores.dat";
const string NOMBRE_ARCH_MED = "medidores.dat";
const string NOMBRE_ARCH_DOC = "documentos.dat";
const string NOMBRE_ARCH_TAR = "tarifas.dat";
const string NOMBRE_ARCH_CC = "cuentasContrato.dat";

class Validaciones
{
public:
	static char DatoObligarorioChar(string nombreDato);
	static string DatoObligarorioCad(string nombreDato);
	static int DatoObligarorioNum(string nombreDato);
	static float DatoObligarorioDecimal(string nombreDato);

};
