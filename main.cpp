#include "App.h"
#include <conio.h>  //De aqu� utilizaremos la funci�n kbhit()
#include <dos.h> //Usaremos esta librer�a por la funci�n delay(int valor) que nos permite  
#include <graphics.h> //Esta es la librer�a que nos permite usar gr�ficos.
#include <Windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	initwindow(800,800, "Hola");
	//outtextxy(450, 20 + 20, 'Pincel Activo!');
	readimagefile("paleta.jpg", 1, 1, 260, 100);
	readimagefile("formas.jpg", 380, 1, 200, 100);
	App aplicacion;
	aplicacion.Principal();
}
