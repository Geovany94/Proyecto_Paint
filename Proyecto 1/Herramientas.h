#pragma once
#include "SFML/Graphics.hpp"
#include <string>

using namespace std;
using namespace sf;

class Herramientas
{
public:
	Herramientas(int alto, int ancho, string titulo);
	void GameLoop();
	//void ProcesarEventos();
	//void ProcesarMouse();
	void Dibujar();

private:
	RenderWindow* ventana2;
	int fps;
	//Font* fuente1;
	//Text* txt_mensaje;
	//Vector2i posicionMouse;
	//Event* evento1;
	//RectangleShape* cuadrado;
};

