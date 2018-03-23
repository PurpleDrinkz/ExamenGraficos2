#pragma once
#include "Modelo.h"

class Pajaro : public Modelo
{
public:
	Pajaro();
	float anguloPajaro;
	vec3 coordenadasPajaro;
	float velocidadAngularPajaro = 0.001f;
	void moverPajaro();
	float velocidad = 0.0005f;
};