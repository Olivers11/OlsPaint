#include <conio.h>  //De aquí utilizaremos la función kbhit()
#include <dos.h> //Usaremos esta librería por la función delay(int valor) que nos permite  
#include <graphics.h> //Esta es la librería que nos permite usar gráficos.
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;


class Dibujar{
	private:
		POINT puntero_cursor;//cursor
		int x;
		int y;
		int radio;
		int color;
		string modo;
		public:
			Dibujar()
			{
				this->modo = "normal";
				//blanco, negro, gris, rojo, verde, amarillo
				this->radio = 2;
				this->x = 0;
				this->y = 0;
				this->color = 15;// = blanco
			}
			
			bool VerificarLimite()
			{
				if(this->x >= 0 and this->x <800 and this->y < 126 and this->y >= 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			
			
			void CuadroColor()
			{
				setcolor(this->color);//negro
				setfillstyle(HATCH_FILL,this->color);
				circle(300, 50, 30);
				for(int i = 30; i >= 0; i--)
				{
					circle(300, 50, i);
				}	
			}
			
			string obtenerModo()
			{
				return this->modo;
			}
			
			
			void getModo(string modo)
			{
				this->modo = modo;
			}
			
			
			void ElegirColor(int posx, int posy)
			{
				
				if(posx > 136 and posx < 146 and posy > 36 and posy < 51)
				{
					this->color = 4;
				}
				else if(posx > 173 and posx < 185 and posy > 36 and posy < 51)
				{
					this->color = 14;
				}
				else if(posx > 192 and posx < 204 and posy > 36 and posy < 51)
				{
					this->color = 2;
				}
				else
				{
					this->color = 15;
				}
				this->CuadroColor();
			}
			
			
			void RellenarPunto(int x, int y)
			{
				setcolor(this->color); // por defecto es el blanco
				for(int i = 3; i >= 0; i--)
				{
					circle(x, y, i);
				}
			}
			
			void CrearPincel()
			{
				GetCursorPos(&this->puntero_cursor);
				/*
				if(ismouseclick(WM_LBUTTONUP))
				{
					cout << "Suelto" << endl;
				}*/
				this->x = this->puntero_cursor.x;
				this->y = this->puntero_cursor.y;
				
				if(this->VerificarLimite())
				{
					system("cls");
					cout << "tabla de colores!" << endl;
					cout << "X: " << this->x << "y: " << this->y << endl;
					this->ElegirColor(this->x, this->y);
				
				}
				else
				{
					system("cls");
					cout << "X: " << this->x << "y: " << this->y << endl;
					//readimagefile("cselect.jpg", this->x, this->y, 3, 20);
					setcolor(this->color);//blanco = 15
					circle(this->x, this->y-17, this->radio);
					this->RellenarPunto(this->x, this->y-17);
					//line(this->x, this->y, this->x, this->y+90);
					//line(this->x+1, this->y, this->x, this->y+90);
					//line(this->x-1, this->y, this->x, this->y+90);	
				}
				
			}
};

class Cuadrado{
	private:
		POINT puntero_cursor;
		int x;
		int y;
		int ref_x;
		int ref_y;
		int color;
		public:
			Cuadrado()
			{
				this->x = 0;
				this->y = 0;
				this->ref_x = 0;
				this->ref_y = 0;
				this->color = 15;///blanco
			}	
			
			bool VerificarLimite()
			{
				if(this->x >= 0 and this->x <800 and this->y < 126 and this->y >= 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			void CapturarInicial()
			{
				GetCursorPos(&this->puntero_cursor);
				this->ref_x = this->puntero_cursor.x;
				this->ref_y = this->puntero_cursor.y;
			}
			
			string RetornarAtributos()
			{
				string linea = "Tipo: Cuadrado  -- Posicion x:" + to_string(this->x);
				linea += "  y:" + to_string(this->y) + " color: " + to_string(this->color);
				return linea;
			}
			
			
			void BorrarCuadradoAnterior()
			{
				setcolor(0);
				if(!this->VerificarLimite())
				{
					line(this->ref_x, this->ref_x , this->ref_x, this->y);
					line(this->ref_x, this->y, this->x, this->y);
					line(this->ref_x, this->ref_y, this->x, this->ref_y);
					line(this->x, this->ref_y, this->x, this->y);
				}
				
			}
			
			
			void DibujarCuadrado()
			{
				
				GetCursorPos(&this->puntero_cursor);
				this->BorrarCuadradoAnterior();
				setcolor(this->color);
				this->x = this->puntero_cursor.x;
				this->y = this->puntero_cursor.y;
				if(!this->VerificarLimite())
				{
					line(this->ref_x, this->ref_y, this->ref_x, this->y);
					line(this->ref_x, this->y, this->x, this->y);
					line(this->ref_x, this->ref_y, this->x, this->ref_y);
					line(this->x, this->ref_y, this->x, this->y);
				}
			}
			
			
			
};


class Linea{
	private:
		POINT puntero_cursor;
		int x;
		int ref_x;
		int ref_y;
		int y;
		int color;
		public:
			Linea()
			{
				this->x = 0;
				this->y = 0;
				this->ref_x = 0;
				this->ref_y = 0;
				this->color = 15;//blanco
			}
			
			bool VerificarLimite()
			{
				if(this->x >= 0 and this->x <800 and this->y < 126 and this->y >= 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			void CapturarInicial()
			{
				GetCursorPos(&this->puntero_cursor);
				this->ref_x = this->puntero_cursor.x;
				this->ref_y = this->puntero_cursor.y;
			}	
			
			void BorrarLineaAnterior()
			{
				if(!this->VerificarLimite())
				{
					setcolor(0);
					line(this->ref_x, this->ref_y, this->x, this->y);
				}
				
			}
			
			string RetornarAtributos()
			{
				string linea = "Tipo: Linea  -- Posicion x:" + to_string(this->x);
				linea += "  y:" + to_string(this->y) + " color: " + to_string(this->color);
				return linea;
			}
			
			void DibujarLinea()
			{
				GetCursorPos(&this->puntero_cursor);
				this->BorrarLineaAnterior();
				setcolor(this->color);
				this->x = this->puntero_cursor.x;
				this->y = this->puntero_cursor.y;
				if(!this->VerificarLimite())
				{
					line(this->ref_x, this->ref_y, this->x, this->y);
				}
			}
			
			
};


class Circulo{
	private:
		POINT puntero_cursor;
		int x;
		int y;
		int ref_x;
		int ref_y;
		int radio;
		int color;
		public:
			Circulo()
			{
				this->radio = 0;
				this->x = 0;
				this->y = 0;
				this->ref_x = 0;
				this->ref_y = 0;
				this->color = 15;//negro
			}	
			
			
			
			
			bool VerificarLimite()
			{
				if(this->x >= 0 and this->x <800 and this->y < 126 and this->y >= 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			string RetornarAtributos()
			{
				string linea = "Tipo: Circulo  -- Posicion x:" + to_string(this->x);
				linea += "  y:" + to_string(this->y) + " color: " + to_string(this->color);
				return linea;
			}
			
			
			
			void CapturarInicial()
			{
				GetCursorPos(&this->puntero_cursor);
				this->ref_x = this->puntero_cursor.x;
				this->ref_y = this->puntero_cursor.y;
			}
			
			void BorrarCirculoAnterior()
			{
				if(!this->VerificarLimite())
				{
					setcolor(0);
					circle(this->ref_x, this->ref_y, this->radio);
				}
			}
			
			int DevolverRadio()
			{
				int resultadox = this->x - this->ref_x;
				resultadox *= resultadox;
				int resultadoy = this->y - this->ref_y;
				resultadoy *= resultadoy;
				int distancia = resultadox + resultadoy;
				distancia = sqrt(distancia);
				return distancia;
			}
			
			
			void DibujarCirculo()
			{
				
				GetCursorPos(&this->puntero_cursor);
				this->BorrarCirculoAnterior();
				setcolor(this->color);
				this->x = this->puntero_cursor.x;
				this->y = this->puntero_cursor.y;
				if(!this->VerificarLimite())
				{
					this->radio = this->DevolverRadio();
					circle(this->ref_x, this->ref_y, this->radio);
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
			
			bool VerificarLimite()
			{
				if(this->x >= 0 and this->x <800 and this->y < 126 and this->y >= 0)
				{
					
					return true;
				}
				else
				{
					return false;
				}
			}
			
			void AbrirArchivo()
			{
				system("elementos.txt");
			}
			
			void CrearBorrador(Dibujar &pincel)
			{
				
				GetCursorPos(&this->puntero_cursor);
				this->x = this->puntero_cursor.x;
				this->y = this->puntero_cursor.y;
				if(!this->VerificarLimite())
				{
					setcolor(this->color);//negro
					circle(this->x, this->y, this->radio);
					this->RellenarBorrador(this->x, this->y);
				}
				else
				{
					int posx = this->x;
					int posy = this->y;
					if(posx > 440 and posx < 453 and posy > 36 and posy < 47)
					{
						pincel.getModo("circulo");
					}
					else if(posx > 464 and posx < 478 and posy > 34 and posy < 51)
					{
						pincel.getModo("cuadrado");
					}
					else if(posx > 388 and posx < 405 and posy > 33 and posy < 52)
					{
						pincel.getModo("linea");
					}
					else if(posx > 490 and posx < 506 and posy > 99 and posy < 115)
					{
						this->AbrirArchivo();
					}
					else
					{
						pincel.getModo("normal");
					}
				}
				
			}
			
			void RellenarBorrador(int posx, int posy)
			{
				for(int i = this->radio; i >= 0; i--)
				{
					circle(posx, posy, i);
				}
			}
			
};








class App{//Clase principal
	private:
		bool salir = false;
		ofstream archivo;
		int contador = 0;
		Dibujar pincel = Dibujar();
		Borrador goma = Borrador();//borrador
		public:
			
			void Escribir(string linea)
			{
				this->archivo.open("elementos.txt", ios::app);
				if(this->archivo.fail())
				{
					cout << "ERROR" << endl;
				}
				else
				{
					this->archivo << "Elemento #: " << this->contador << endl;
					this->archivo << linea << endl;
				}
				this->archivo.close();
			}			
			
			
			
			void Limpiar()
			{
				this->archivo.open("elementos.txt", ios::out);
				if(this->archivo.fail())
				{
					cout << "NULL" << endl;
				}
				else
				{
					exit(3);
				}
			}
			
			
			
			void BorrarTexto(int posx, int posy)
			{
				setcolor(0);
				for(int i = 18; i >= 0; i--)
				{
					circle(posx, posy, i);
				}
				for(int i = 18; i >= 0; i--)
				{
					circle(710, 40, i);
				}
				for(int i = 18; i >= 0; i--)
				{
					circle(posx-30, posy, i);
				}
				for(int i = 18; i >= 0; i--)
				{
					circle(posx+10, posy, i);
				}
			}
			
			void PintarModo()
			{
				this->BorrarTexto(750, 40);
				char* chr = strdup(this->pincel.obtenerModo().c_str());
				setcolor(15);
				settextstyle(SANS_SERIF_FONT, 1, 15);
				outtextxy(750, 20 + 20, chr);	
			}	
			
			void Principal()
			{
				pincel.CuadroColor();
				do
				{
					//system("cls");GetAsyncKeyState(VK_LBUTTON)
					
					
					if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
					{
						this->PintarModo();
						if(pincel.obtenerModo() == "normal")
						{
							while((GetKeyState(VK_LBUTTON) & 0x100) != 0)
							{
								pincel.CrearPincel();
							}
							//system("cls");
							this->contador++;
							cout << "Suelto" << endl;
						}
						else if(pincel.obtenerModo() == "cuadrado")
						{
							Cuadrado cuadrado = Cuadrado();
							cuadrado.CapturarInicial();
							while((GetKeyState(VK_LBUTTON) & 0x100) != 0)
							{
								cuadrado.DibujarCuadrado();//
							}
							this->contador++;
							this->Escribir(cuadrado.RetornarAtributos());
							//system("cls");
							cout << "Suelto" << endl;
						}
						else if(pincel.obtenerModo() == "linea")
						{
							Linea linea_ = Linea();
							linea_.CapturarInicial();
							while((GetKeyState(VK_LBUTTON) & 0x100) != 0)
							{
								linea_.DibujarLinea();
							}
							this->contador++;
							this->Escribir(linea_.RetornarAtributos());
							//system("cls");
							cout << "Suelto" << endl;
						}
						else if(pincel.obtenerModo() == "circulo")
						{
							Circulo circulo = Circulo();
							circulo.CapturarInicial();
							while((GetKeyState(VK_LBUTTON) & 0x100) != 0)
							{
								circulo.DibujarCirculo();
							}
							this->contador++;
							this->Escribir(circulo.RetornarAtributos());
							//system("cls");
							cout << "Suelto" << endl;
						}
						
					}
					
					/*if(ismouseclick(WM_LBUTTONUP))
					{
						cout << "Suelto" << endl;
					}*/
					
					
					
					if(GetAsyncKeyState(VK_RBUTTON))
					{
						goma.CrearBorrador(pincel);
					}
					
				}while(!salir);
				this->Limpiar();
				getch();
				closegraph();//la segunda ventana
			}
};
