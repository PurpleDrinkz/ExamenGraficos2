#include "stdafx.h"
#include "Pajaro.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"



Pajaro::Pajaro()
{
	anguloPajaro = 90;
	coordenadasPajaro = vec3(0.0f, 0.3f, 0.0f);
	transformaciones = mat4(1.0f);

}

void Pajaro::moverPajaro()
{

	float rotacion = velocidadAngularPajaro;

		
}
