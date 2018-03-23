// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"


#include <iostream>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "Nave.h"

using namespace std;

GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint transformacionesID;

Nave *nave;
Modelo *cuadrado;
Modelo * techo;
Modelo * ventana;
Modelo * ventana2;
Modelo * puerta;
Modelo * concreto;

Shader *shader;
//Declaración de ventana
GLFWwindow *window;

void actualizar() { 
	
		nave->rotarNave(1);

	

	
		nave->rotarNave(0);
	

	
		nave->moverNave();
	

}

void dibujar() {
	concreto->dibujar(GL_POLYGON);
	cuadrado->dibujar(GL_POLYGON);
	
	techo->dibujar(GL_POLYGON);
	ventana->dibujar(GL_POLYGON);
	ventana2->dibujar(GL_POLYGON);
	puerta->dibujar(GL_POLYGON);
	
	nave->dibujar(GL_POLYGON);
}

void inicializarFigura() {
	nave = new Nave();
	Vertice v1 =
	{ vec4(-0.1f,-0.1f,0.0f,1.0f), vec4(90.0f / 255.0f,56.0f / 255.0f,37.0f / 255.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.0f,0.1f,0.0f,1.0f), vec4(90.0f / 255.0f,56.0f / 255.0f,37.0f / 255.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.1f,-0.1f,0.0f,1.0f), vec4(90.0f/255.0f,56.0f/255.0f,37.0f/255.0f,1.0f) };
	nave->vertices.push_back(v1);
	nave->vertices.push_back(v2);
	nave->vertices.push_back(v3);
}

void inicializarCuadrado() {
	cuadrado = new Modelo();
	Vertice v1 =
	{ vec4(-0.5f,0.5f,0.0f,1.0f), vec4(128.0f / 255.0f,128.0f / 255.0f,255.0f / 255.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.5f,0.5f,0.0f,1.0f), vec4(128.0f / 255.0f,128.0f / 255.0f,255.0f / 255.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.5f,-0.5f,0.0f,1.0f), vec4(128.0f / 255.0f,128.0f / 255.0f,255.0f / 255.0f,1.0f) };
	Vertice v4 =
	{ vec4(-0.5f,-0.5f,0.0f,1.0f), vec4(128.0f / 255.0f,128.0f / 255.0f,255.0f / 255.0f,1.0f) };
	cuadrado->vertices.push_back(v1);
	cuadrado->vertices.push_back(v2);
	cuadrado->vertices.push_back(v3);
	cuadrado->vertices.push_back(v4);
}

void inicializarTecho()
{
	techo = new Modelo();
	Vertice v1 =
	{ vec4(-0.5f,0.5f,0.0f,1.0f), vec4(64.0f / 255.0f,0.0f / 255.0f,0.0f / 255.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.5f,0.5f,0.0f,1.0f), vec4(64.0f / 255.0f,0.0f / 255.0f,0.0f / 255.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.0f, 0.7f,0.0f,1.0f), vec4(64.0f / 255.0f,0.0f / 255.0f,0.0f / 255.0f,1.0f) };
	techo->vertices.push_back(v1);
	techo->vertices.push_back(v2);
	techo->vertices.push_back(v3);


}

void inicializarVentana1()
{
	ventana = new Modelo();
	Vertice v1 =
	{ vec4(-0.4f,0.2f,0.0f,1.0f), vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	Vertice v2 =
	{ vec4(-0.2f,0.2f,0.0f,1.0f), vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	Vertice v3 =
	{ vec4(-0.2f,0.0f,0.0f,1.0f), vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	Vertice v4 =
	{ vec4(-0.4f,-0.0f,0.0f,1.0f),vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	ventana->vertices.push_back(v1);
	ventana->vertices.push_back(v2);
	ventana->vertices.push_back(v3);
	ventana->vertices.push_back(v4);


}

void inicializarVentana2()
{
	ventana2 = new Modelo();
	Vertice v1 =
	{ vec4(0.4f,0.2f,0.0f,1.0f), vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.2f,0.2f,0.0f,1.0f), vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.2f,0.0f,0.0f,1.0f), vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	Vertice v4 =
	{ vec4(0.4f,-0.0f,0.0f,1.0f),vec4(27.0f / 255.0f,224.0f / 255.0f,219.0f / 255.0f,1.0f) };
	ventana2->vertices.push_back(v1);
	ventana2->vertices.push_back(v2);
	ventana2->vertices.push_back(v3);
	ventana2->vertices.push_back(v4);


}

void inicializarPuerta()
{
	puerta = new Modelo();
	Vertice v1 =
	{ vec4(-0.1f,-0.1f,0.0f,1.0f), vec4(185.0f / 255.0f,122.0f / 255.0f,87.0f / 255.0f,1.0f) };
	Vertice v2 =
	{ vec4(0.1f,-0.1f,0.0f,1.0f), vec4(185.0f / 255.0f,122.0f / 255.0f,87.0f / 255.0f,1.0f) };
	Vertice v3 =
	{ vec4(0.1f,-0.5f,0.0f,1.0f), vec4(185.0f / 255.0f,122.0f / 255.0f,87.0f / 255.0f,1.0f) };
	Vertice v4 =
	{ vec4(-0.1f,-0.5f,0.0f,1.0f),vec4(185.0f / 255.0f,122.0f / 255.0f,87.0f / 255.0f,1.0f) };
	puerta->vertices.push_back(v1);
	puerta->vertices.push_back(v2);
	puerta->vertices.push_back(v3);
	puerta->vertices.push_back(v4);



}

void inicializarConcreto()
{

	concreto = new Modelo();
	Vertice v1 =
	{ vec4(-1.0f,-0.4f,0.0f,1.0f),vec4(127.0f / 255.0f,127.0f / 255.0f, 127.0f / 255.0f,1.0f) };
	Vertice v2 =
	{ vec4(1.0f,-0.4f,0.0f,1.0f), vec4(127.0f / 255.0f,127.0f / 255.0f, 127.0f / 255.0f,1.0f) };
	Vertice v3 =
	{ vec4(1.0f,-1.0f,0.0f,1.0f), vec4(127.0f / 255.0f,127.0f / 255.0f, 127.0f / 255.0f,1.0f) };
	Vertice v4 =
	{ vec4(-1.0f,-1.0f,0.0f,1.0f),vec4(127.0f / 255.0f,127.0f / 255.0f, 127.0f / 255.0f,1.0f) };
	concreto->vertices.push_back(v1);
	concreto->vertices.push_back(v2);
	concreto->vertices.push_back(v3);
	concreto->vertices.push_back(v4);



}

int main()
{
	
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}



	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;


	red = 157.0f/255.0f;
	green = 217.0f/255.0f;
	blue = 234.0f/255.0f;
	inicializarCuadrado();
	inicializarFigura();
	inicializarTecho();
	inicializarVentana1();
	inicializarVentana2();
	inicializarPuerta();
	inicializarConcreto();

	//Crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");
	transformacionesID =
		glGetUniformLocation(shader->getID(), "transformaciones");

	//Desenlazar shader
	shader->desenlazarShader();

	nave->shader = shader;
	nave->inicializarVertexArray(posicionID, colorID, transformacionesID);

	cuadrado->shader = shader;
	cuadrado->inicializarVertexArray(posicionID, colorID, transformacionesID);

	techo->shader = shader;
	techo->inicializarVertexArray(posicionID, colorID, transformacionesID);

	ventana->shader = shader;
	ventana->inicializarVertexArray(posicionID, colorID, transformacionesID);

	ventana2->shader = shader;
	ventana2->inicializarVertexArray(posicionID, colorID, transformacionesID);

	puerta->shader = shader;
	puerta->inicializarVertexArray(posicionID, colorID, transformacionesID);

	concreto->shader = shader;
	concreto->inicializarVertexArray(posicionID, colorID, transformacionesID);
	
	
	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

