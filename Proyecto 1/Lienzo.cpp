#include "Lienzo.h"
#include <string>

using namespace std;

Lienzo::Lienzo(int ancho, int alto, string titulo) {
	//VENTANA
	fps = 60;
	ventana1 = new RenderWindow(VideoMode(ancho, alto), titulo);
	//a cuantos frames irá
	ventana1->setFramerateLimit(fps);
	//ESCRITO EN PANTALLA
	fuente1 = new Font();
	//carga la fuente desde el archivo
	fuente1->loadFromFile("Stay Girly.ttf");
	//textos en pantalla
	txt_mensaje = new Text();
	txt_mensaje->setFont(*fuente1);
	txt_mensaje->setString("Herramientas:");
	txt_mensaje->setPosition(5, 5);
	txt_mensaje->setCharacterSize(16);
	txt_mensaje->setFillColor(Color::Black);

	txt_dibujos = new Text();
	txt_dibujos->setFont(*fuente1);
	txt_dibujos->setString("Rectangulo  -  Circulo  -  Triangulo  -  Linea  -  Borrador  -  Color");
	txt_dibujos->setPosition(80, 5);
	txt_dibujos->setCharacterSize(16);
	txt_dibujos->setFillColor(Color::Black);
	//EVENTOS
	evento1 = new Event;
	evento2 = new Event;

	cuadrado = new RectangleShape({ 30,23 });
	cuadrado->setFillColor(Color::White);
	cuadrado->setOutlineColor(Color::Black);
	cuadrado->setOutlineThickness(2);
	cuadrado->setPosition(90,30);

	circulo = new CircleShape({ 12 });
	circulo->setFillColor(Color::White);
	circulo->setOutlineColor(Color::Black);
	circulo->setOutlineThickness(2);
	circulo->setPosition(155, 30);

	triangulo = new CircleShape({ 15 });
	triangulo->setPointCount(3);
	triangulo->setFillColor(Color::White);
	triangulo->setOutlineColor(Color::Black);
	triangulo->setOutlineThickness(2);
	triangulo->setPosition(215, 30);

	linea = new RectangleShape({ 30,5 });
	linea->rotate(45);
	linea->setFillColor(Color::Black);
	linea->setPosition(270, 30);

	borrador = new RectangleShape({ 20,20 });
	borrador->setFillColor(Color::White);
	borrador->setOutlineColor(Color::Black);
	borrador->setOutlineThickness(1);
	borrador->setPosition(327, 32);

	c1 = new RectangleShape({ 25,10 });
	c1->rotate(90);
	c1->setFillColor(Color::Red);
	c1->setPosition(390, 30);

	c2 = new RectangleShape({ 25,10 });
	c2->rotate(90);
	c2->setFillColor(Color::Blue);
	c2->setPosition(400, 30);

	c3 = new RectangleShape({ 25,10 });
	c3->rotate(90);
	c3->setFillColor(Color::Yellow);
	c3->setPosition(410, 30);

	c4 = new RectangleShape({ 25,10 });
	c4->rotate(90);
	c4->setFillColor(Color::Green);
	c4->setPosition(420, 30);

	c5 = new RectangleShape({ 25,10 });
	c5->rotate(90);
	c5->setFillColor(Color::Cyan);
	c5->setPosition(430, 30);

	c6 = new RectangleShape({ 25,10 });
	c6->rotate(90);
	c6->setFillColor(Color::Magenta);
	c6->setPosition(440, 30);

	GameLoop();
	
}

void Lienzo::GameLoop() {
	//mientras la ventana esté abierta:
	while (ventana1->isOpen()) {
		ProcesarMouse();
		ProcesarEventos();
		Dibujar();
	}
}

void Lienzo::Dibujar() {
	ventana1->clear(Color::White);

	ventana1->draw(*txt_mensaje);
	ventana1->draw(*txt_dibujos);
	ventana1->draw(*cuadrado);
	ventana1->draw(*circulo);
	ventana1->draw(*triangulo);
	ventana1->draw(*linea);
	ventana1->draw(*borrador);
	ventana1->draw(*c1);
	ventana1->draw(*c2);
	ventana1->draw(*c3);
	ventana1->draw(*c4);
	ventana1->draw(*c5);
	ventana1->draw(*c6);

	ventana1->display();
}

void Lienzo::ProcesarEventos() {
	//pollevent - escuhar evento
		while (ventana1->pollEvent(*evento1)) {
			switch (evento1->type) {
			case Event::Closed:
				ventana1->close();
				exit(1);
				break;

			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					FloatRect posicion_mouse(Vector2f(posicionMouse), { 32,32 });
					if (cuadrado->getGlobalBounds().intersects(posicion_mouse)) {
						while (ventana1->isOpen()) {
							cuadrado = new RectangleShape({ 30,23 });
							cuadrado->setFillColor(Color::White);
							cuadrado->setOutlineColor(Color::Black);
							cuadrado->setOutlineThickness(2);
							cuadrado->setPosition(100, 100);
							ventana1->draw(*cuadrado);
							ventana1->display();
							GameLoop();
							Dibujar();
							ProcesarEventos();
						}
					}
					else {
						if (circulo->getGlobalBounds().intersects(posicion_mouse)) {
							while (ventana1->isOpen()) {
								circulo = new CircleShape({ 12 });
								circulo->setFillColor(Color::White);
								circulo->setOutlineColor(Color::Black);
								circulo->setOutlineThickness(2);
								circulo->setPosition(155, 150);
								ventana1->draw(*circulo);
								ventana1->display();
								GameLoop();
								Dibujar();
								ProcesarEventos();
							}
							ProcesarEventos();
						}
						else {
							if (triangulo->getGlobalBounds().intersects(posicion_mouse)) {
								while (ventana1->isOpen()) {
									triangulo = new CircleShape({ 15 });
									triangulo->setPointCount(3);
									triangulo->setFillColor(Color::White);
									triangulo->setOutlineColor(Color::Black);
									triangulo->setOutlineThickness(2);
									triangulo->setPosition(215, 200);
									ventana1->draw(*triangulo);
									ventana1->display();
									GameLoop();
									Dibujar();
									ProcesarEventos();
								}
								ProcesarEventos();
							}
							else {
								if (linea->getGlobalBounds().intersects(posicion_mouse)) {
									while (ventana1->isOpen()) {
										linea = new RectangleShape({ 30,5 });
										linea->rotate(45);
										linea->setFillColor(Color::Black);
										linea->setPosition(270, 270);
										ventana1->draw(*linea);
										ventana1->display();
										GameLoop();
										Dibujar();
										ProcesarEventos();
									}
									
								}

								else {
									if (c1->getGlobalBounds().intersects(posicion_mouse)) {
										cuadrado->setFillColor(Color::Red);
										circulo->setFillColor(Color::Red);
										triangulo->setFillColor(Color::Red);
									}
									else {
										if (c2->getGlobalBounds().intersects(posicion_mouse)) {
											cuadrado->setFillColor(Color::Blue);
											circulo->setFillColor(Color::Blue);
											triangulo->setFillColor(Color::Blue);
										}
										else {
											if (c3->getGlobalBounds().intersects(posicion_mouse)) {
												cuadrado->setFillColor(Color::Yellow);
												circulo->setFillColor(Color::Yellow);
												triangulo->setFillColor(Color::Yellow);
											}
											else {
												if (c4->getGlobalBounds().intersects(posicion_mouse)) {
													cuadrado->setFillColor(Color::Green);
													circulo->setFillColor(Color::Green);
													triangulo->setFillColor(Color::Green);
												}
												else {
													if (c5->getGlobalBounds().intersects(posicion_mouse)) {
														cuadrado->setFillColor(Color::Cyan);
														circulo->setFillColor(Color::Cyan);
														triangulo->setFillColor(Color::Cyan);
													}
													else {
														if (c6->getGlobalBounds().intersects(posicion_mouse)) {
															cuadrado->setFillColor(Color::Magenta);
															circulo->setFillColor(Color::Magenta);
															triangulo->setFillColor(Color::Magenta);
														}
													}
												}
											}
										}
									}
								}
								
							}
							
						}
						
					}
					
				}
				break;

				case Event::MouseMoved:
					if (Mouse::isButtonPressed(Mouse::Right)) {
						FloatRect posicion_mouse(Vector2f(posicionMouse), { 32,32 });
						if (cuadrado->getGlobalBounds().intersects(posicion_mouse)) {
							cuadrado->setPosition(Vector2f(posicionMouse));
						}
						else {
							if (circulo->getGlobalBounds().intersects(posicion_mouse)) {
								circulo->setPosition(Vector2f(posicionMouse));
							}
							else {
								if (triangulo->getGlobalBounds().intersects(posicion_mouse)) {
									triangulo->setPosition(Vector2f(posicionMouse));
								}
								else {
									if (linea->getGlobalBounds().intersects(posicion_mouse)) {
										linea->setPosition(Vector2f(posicionMouse));
									}
								}
							}
						}
					}
					break;
				ProcesarEventos();
			}
		}
			
		
	}
	

void Lienzo::ProcesarMouse() {
	posicionMouse = Mouse::getPosition(*ventana1);
	//transforma pixeles a coordenadas(pixelToCoodrs
	posicionMouse = (Vector2i)ventana1->mapPixelToCoords(posicionMouse);
}