#include <conio.h>  //De aquí utilizaremos la función kbhit()
#include <dos.h> //Usaremos esta librería por la función delay(int valor) que nos permite  
#include <graphics.h> //Esta es la librería que nos permite usar gráficos.
#include <Windows.h>
#include <iostream>
using namespace std;



class Dibujar{
	private:
		POINT puntero_cursor;//cursor
		int x;
		int y;
		int radio;
		int colores[6];
		int color;
		public:
			Dibujar()
			{
				//blanco, negro, gris, rojo, verde, amarillo
				this->colores = {15, 0, 8, 4, 2, 14};
				this->radio = 2;
				this->x = 0;
				this->y = 0;
				this->color = 15;// = blanco
			}
			
			void CrearPincel()
			{
				GetCursorPos(&this->puntero_cursor);//detecta un click izquierdo
				this->x = this->puntero_cursor.x;//obtener las coordenadas de donde se hizo click
				this->y = this->puntero_cursor.y;
				if(GetAsyncKeyState(VK_LBUTTON))
				{
					system("cls");
					cout << this->x << " y: " << this->y << endl;
					if(this->x > 137 and this->x < 147 and this->y > 36 and this->y < 51)
					{
						cout << "Rojo" << endl;
						this->color = this->colores[3];
					}
					else if(this->x > 173 and this->x < 185 and this->y > 37 and this->y < 53 )
					{
						cout << "Amarillo" << endl;
						this->color = this->colores[5];
					}
					else
					{
						this->color = this->colores[0];
						cout << "Otro Color" << endl;
					}
					
					setcolor(this->color);//blanco
					circle(this->x, this->y-18, this->radio);
				}
				
			}
};



class Borrador{
	private:
		POINT puntero_cursor;
		int x;
		int y;
		int radio;
		int color;
		public:
			Borrador()
			{
				this->radio = 20;
				this->x = 0;
				this->y = 0;
				this->color = 0;//negro
			}
			
			void CrearBorrador()
			{
				
				GetCursorPos(&this->puntero_cursor);
				this->x = this->puntero_cursor.x;
				this->y = this->puntero_cursor.y;
				setcolor(this->color);//negro
				setfillstyle(HATCH_FILL,RED);
				circle(this->x, this->y, this->radio);
			}
};



class App{//Clase principal
	private:
		bool salir;
		Dibujar pincel = Dibujar();
		Borrador goma = Borrador();//borrador
		public:
			App()
			{
				this->salir = false;
			}
			
			void Principal()
			{
				
				do
				{
					
					pincel.CrearPincel();
					if(GetAsyncKeyState(VK_RBUTTON))
					{
						goma.CrearBorrador();
					}
				}while(!salir);
				getch();
				closegraph();//la segunda ventana
			}
};
