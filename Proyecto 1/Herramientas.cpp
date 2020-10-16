#include "Herramientas.h"
#include <string>

using namespace std;

Herramientas::Herramientas(int alto, int ancho, string titulo) {
	fps = 60;
	ventana2 = new RenderWindow(VideoMode(ancho, alto), titulo);
	ventana2->setFramerateLimit(fps);

	GameLoop();
}

void Herramientas::GameLoop() {
	while (ventana2->isOpen()) {
		//ProcesarMouse();
		//ProcesarEventos();
		Dibujar();
	}
}

void Herramientas::Dibujar() {
	ventana2->clear(Color::White);

	//ventana1->draw(*cuadrado);

	ventana2->display();
}
