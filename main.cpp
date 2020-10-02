#include "App.h"

int main()
{
	initwindow(800,800, "Hola");
	readimagefile("paleta.jpg", 1, 1, 260, 100);
	App aplicacion = App();
	aplicacion.Principal();
}
