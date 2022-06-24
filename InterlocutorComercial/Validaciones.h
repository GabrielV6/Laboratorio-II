#pragma once
#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
using namespace std;

class Validaciones
{
public:
	static char DatoObligarorioChar(string nombreDato);
	static string DatoObligarorioCad(string nombreDato);
	static int DatoObligarorioNum(string nombreDato);

};
