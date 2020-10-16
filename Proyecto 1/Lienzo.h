#pragma once
#include "SFML/Graphics.hpp"
#include <string>

using namespace sf;
using namespace std;

class Lienzo
{
public:
	Lienzo(int ancho, int alto, string titulo);
	void GameLoop();
	void Dibujar();
	void ProcesarEventos();
	void ProcesarMouse();

private:
	RenderWindow* ventana1;
	int fps;
	Font * fuente1;
	Text* txt_mensaje;
	Text* txt_dibujos;
	Vector2i posicionMouse;
	Event* evento1, * evento2;
	RectangleShape* cuadrado, *linea, *borrador, *c1, *c2, *c3, *c4, *c5, *c6, *cuadrado2;
	CircleShape* circulo, *triangulo;
};

