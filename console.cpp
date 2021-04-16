#include <Windows.h>
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

//toa do max
#define xMax 132
#define yMax 35

//goc toa do
#define xOrdinal 0
#define yOrdinal 0
#define WHITE 7
using namespace std;

// resize lai console
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// set mau cho console
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
// set mau cho chu
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),coord
	);
}
void ShowCur(bool);
void VeKhungMenu()
{
	
	ShowCur(false);
	int i;
	gotoxy(xOrdinal, yOrdinal);
	// ve hang ngang tren
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}

	// ve hang ngang duoi
	gotoxy(xOrdinal, yOrdinal + 15);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}

	// ve hang doc trai
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xOrdinal, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "  ";
	}

	// ve hang doc phai
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xMax - 1, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "   ";
	}
}
/*void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}*/

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// ve thanh loading 
void CayLoading(int Color)
{
	//SetColor(Color);
	//system("color Color");
	for (int i = 10; i <= 10+100; i++)
	{
		gotoxy(i, 20);
		Sleep(15);
		cout << char(219);
	}
}
void VeKhungCH(int x, int y, int width, int height, bool draw) {
		//ve 4 goc 
		//ve goc tren ben trai
		gotoxy(x, y);
		cout << char(218);
		//ve goc tren ben phai
		gotoxy(x + width, y);
		cout << char(191);
		//ve goc duoi ben trai
		gotoxy(x, y + height);
		cout << char(192);
		//ve goc duoi ben phai
		gotoxy(x + width, y + height);
		cout << char(217);

		//ve thanh ngang tren
		for (int i = x + 1; i < (x + width); i++){
			gotoxy(i, y);
			cout << char(196);
		}
		//ve thanh ngang ben duoi
		for (int i = x + 1; i < (x + width); i++){
			gotoxy(i, y+height);
			cout << char(196);
		}
		//ve thanh doc ben trai
		for (int i = y + 1; i < (y + height); i++){
			gotoxy(x, i);
			cout << char(179);
		}
		//ve thanh doc ben phai
		for (int i = y + 1; i < (y + height); i++){
			gotoxy(x+width, i);
			cout << char(179);
		}
	
}
void menudong(){
	int kb_hit;
	int x= 5;
	while(true){
		if(kbhit()){
			kb_hit = getch();
			if (kb_hit == 224 || kb_hit == 0)
			{
				kb_hit = getch();
			}
			
			switch(kb_hit){
				case 75:{
					system("cls");
					gotoxy(5-x,5);
					SetBGColor(5);
					cout<<"luachon1";
					break;
				}
				case 77:{
					system("cls");
					gotoxy(5+x,5);
					SetBGColor(5);
					cout<<"luachon2";
					break;
				}
				case 13:
					return;
					break;
			}
		}
	}
}
//int main(){
	//SetBGColor(3);
	//resizeConsole(1000,500);
	//system("color 3E");	
	//ShowCur(false);
	//gotoxy(5,6);
	//printf("le thanh tuan");
	//CayLoading(10);VeKhungMenu
	//resizeConsole(900,800);	
	//VeKhungMenu();
	//VeKhungCH(0,0,50,10,0);
	/*printf("\n");
	gotoxy(xOrdinal + 44, yOrdinal + 34);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);

	gotoxy(xOrdinal + 44, yOrdinal + 35);
	cout << char(186) << setw(40) << setfill(' ') << char(186);

	gotoxy(xOrdinal + 44, yOrdinal + 36);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);*/
	//menudong();

	//chuChay(dongChuChay, xOrdinal + 45, yOrdinal + 35);
	//return 0;
//}
