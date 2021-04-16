#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <Windows.h>
#include <iomanip>
#include <time.h>
#include "Mylist.h"
#include "console.h"
using namespace std;

enum THAOTAC {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	//Chon
	ENTER = 13,
	//Xoa Nghia,Vi du
	DEL = 83,
	//Thoat
	ESC = 27,
	//Hieu chinh
	F1 = 59,
	//Luu tu
	F2 = 60,
	//Xoa Tu
	F3 = 61,
	//Them tu 
	F4 = 62
};

typedef char str[20];
str type[5] = {"Noun", "Verb", "Adjective", "Adverb", "Preposition"};
str sua[3] = {"Loai tu:", "Nghia:", "Vi du:"};
str them[4] = {"Tu:", "Loai tu:", "Nghia:", "Vi Du:"};
str nhac[2] = {"Khong", "Co"};

List TuDien[26];

void VeKhung(){
	VeKhungCH(0,0,143,35);
	gotoxy(35,35);
	cout << char(193);
	gotoxy(0, 2);
	cout << char(195);
	gotoxy(0, 4);
	cout << char(195);
	gotoxy(10, 1);
	printf("ENTER: CHON \t\tF1: HIEU CHINH \t\t F2: LUU TU \t F3: XOA TU \t\t F4: THEM TU \t\t ESC: THOAT");
	for (int i = 1; i < 143; i++){
		gotoxy(i, 2);
		cout << char(196);
	}
	gotoxy (35,2);
	cout << char(194);
	for (int i = 1; i < 35; i++){
		gotoxy(i, 4);
		cout << char(196);
	}
	for (int i = 3; i < 35; i++){
		gotoxy(35, i);
		cout << char(179);
	}
	gotoxy (35, 4); 
	cout << char(180);
	gotoxy(1, 5);
	printf("Goi y:");
}

void KhoiDong(){
	VeKhungCH(20,2, 90, 12);
	//T
	for ( int i = 0; i< 8; i++){
		gotoxy(40 + i, 5);
		printf("%c", (char)177 );
	}
	for ( int i = 0; i < 6; i++){
		for ( int j = 0; j< 2; j++){
			gotoxy ( 43 + j, 6 +i );
			printf("%c", (char)177 );
		}
	}
	
	//U
	for ( int i = 0; i < 6; i++){
		gotoxy(49, 5 + i);
		printf("%c%c", (char)177, (char)177);
		gotoxy(55, 5 + i);
		printf("%c%c", (char)177, (char)177);
	}
	for ( int i = 0; i< 8; i++){
		gotoxy(49 + i, 11);
		printf("%c", (char)177 );
	}
	
	//D
	for ( int i = 0; i < 7; i++){
		gotoxy(62, 5 + i);
		printf("%c%c", (char)177, (char)177);
		gotoxy(68, 5 + i);
		printf("%c%c", (char)177, (char)177);
	}
	for ( int i = 0; i< 8; i++){
		gotoxy(62 + i,  5);
		printf("%c", (char)177 );
		gotoxy(62 + i, 11);
		printf("%c", (char)177 );
	}
	for (int i = 0; i < 4; i++){
		gotoxy(61 + i, 8);
		printf("%c", (char)177 );
	}
	
	//I
	for ( int i = 0; i < 7; i++){
		gotoxy(71, 5 + i);
		printf("%c%c", (char)177, (char)177);
	}
	
	//E
	for (int i = 0; i< 8; i++){
		gotoxy(74 + i, 5);
		printf("%c", (char)177 );
		gotoxy(74 + i, 8);
		printf("%c", (char)177 );
		gotoxy(74 + i, 11);
		printf("%c", (char)177 );
	}
	for ( int i = 0; i < 7; i++){
		gotoxy(74, 5 + i);
		printf("%c%c", (char)177, (char)177);
	}

	//n
	for ( int i = 0; i< 8; i++){
		gotoxy(83 + i, 5);
		printf("%c", (char)177 );
	}
	for ( int i = 0; i < 6; i++){
		gotoxy(83, 6 + i);
		printf("%c%c", (char)177, (char)177);
		gotoxy(89, 6 + i);
		printf("%c%c", (char)177, (char)177);
	}
	
	ShowCur(0);
	char str[5]= "....";
	gotoxy(55, 23);
	printf("Loading");
	for ( int i = 0; i < 4; i++){
		gotoxy(63, 23);
		for ( int j = 0; j <= i; j++){
			Sleep(200);
			printf ("%c ", str[j]);
		}
	}
}

void XoaChu(int x, int y, int width, int height, int color){
	TextColor(color);
	int i, j;
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			gotoxy(x + j, y + i );
			printf(" ");
		}
	}
}

int Print_GoiY( NODE p){
	int dem = 0;
	NODE temp = p;
	for (int i = 6; i < 35 && temp != NULL; i++){
		TextColor(224);
		gotoxy(7, i);
		printf("%s", temp->infor.key);
		TextColor(231);
		printf("(%s)", temp->infor.type);
		temp = temp->right;
		dem++;
	}
	return dem;
}

void Del_GoiY(){
	TextColor(224);
	int y = 6;
	for (int i = 0; i < 29; i++){
		for (int j = 0; j < 30; j++){
			gotoxy(3 + j, y + i);
			printf(" ");
		}
	}
}

void Xoa(int x, int y){
	TextColor(224);
	gotoxy(x, y);		printf("  ");
	gotoxy(x + 32, y);		printf("  ");
}

void Move(int x, int y){
	TextColor(15);
	gotoxy(x, y); 	printf("<<");
	gotoxy(x + 32, y ); 	printf(">>");
}

int Chon(){
	int vt = 1;
	int KT = 1;
	int tempX = 55;
	int chon, extended;
	while ( KT ){
		chon = getch();
		if ( chon == ENTER){
			return vt;
		}
		else if ( chon == 224 ){
			extended = getch();
			switch (extended){
				case LEFT:
				case RIGHT:{
					TextColor(15);
					gotoxy(tempX, 9);
					printf("%s", nhac[vt]);
					if (vt == 1){
						vt = 0;
						tempX = 75;
					}
					else {
						vt = 1;
						tempX = 55;
					}
					TextColor(240);
					gotoxy(tempX, 9);
					printf("%s", nhac[vt]);
					break;
				}
			}
		}
	}
}


int Show(NODE &p, int start){
	int x = 36, y = 3;
	int so_dong, temp;
	MEAN mean = NULL;
	so_dong = 4 + p->infor.mean.n + p->infor.ex.n;
	mean = p->infor.mean.First;
	switch(start){
		case 0:{
			gotoxy(x, y++);
			SetColor(1);
			printf("%s", p->infor.key);
		}
		case 1:{
			SetColor(0);
			gotoxy (x, y++);
			printf("> Loai tu: %s", p->infor.type);	
		}
		case 2:{
			gotoxy (x, y++);
			printf("> Nghia: ");
			temp = 0;
		}
		default:{
			if( start > 2)
				temp = start - 3;
			for ( int i = 0; i < temp; i++){
				mean =  mean->next;
			}
			while ( mean != NULL && y < 35){
				gotoxy (x + 5, y++);
				printf("+ %s", mean->str);
				mean = mean->next;	
			}
			if ( y < 35){
				if ( p->infor.ex.n > 0){
					gotoxy (x, y++);
					printf("> Vi du: ");
				}
				temp =  35 - y;
				for ( int i = 0; (i < temp) && (i < p->infor.ex.n); i++){
					gotoxy (x + 5, y++);
					printf("+ %s", p->infor.ex.example[i]);
				}
			}
			break;
		}
	}
	if ( so_dong > 32 ){
		for ( int i = 0; i < 15; i++){
			if ( start < 16){
				TextColor(15);
				gotoxy(141, 4 + start + i );
				printf(" ");
			}
			else {
				TextColor(15);
				gotoxy(141, 4 + 16 + i );
				printf(" ");
			}
		}	
	}
	return so_dong;
}

void Print_exa(char str[], int &y){
	int length = strlen(str);
	char temp[100] = "";
	int x = 90;
	gotoxy(45, y);
	if ( length > 90){
		strncpy(temp, str, x);
		printf ("%s", temp);
	}
	else 
		printf("%s", str);
}

void Menu_LoaiTu(int extended, int &vt, int &x, int y ){
	TextColor(224);
	gotoxy (x, y);
	printf("%s", type[vt]);
	if ( extended == LEFT){
		if ( vt == 0){
			vt = 4;
			x = 125;
		}
		else {
			vt--;
			x -= 20;
		}
	}
	else if (extended == RIGHT ){
		if ( vt == 4 ){
			vt = 0;
			x = 45;
		}
		else {
			vt++;
			x += 20;
		}
	}
	TextColor(143);
	gotoxy (x, y);						
	printf("%s", type[vt]);												
}

void Menu_ThemTu(int extended, word infor, int &vt, int &y, int &y1, int start_mean){
	//y: vi tri hang hien tai cua con tro console
	//y1: so hang cuoi cung
	//vt, vt1: bien thao tac
	//start_mean: chi so cua mean 
	TextColor(224);
	if (extended == 0){
		int tempX, tempY;
		int length;
		char str[100] = "";
		MEAN mean = NULL;
		y1 = 5;
		gotoxy(36, y1++ );
		printf("Tu: %s", infor.key);
		gotoxy(36, y1++);
		printf("Loai tu: %s", infor.type);
		y1++;
		gotoxy(36, y1++);
		printf("Nghia: ");
		mean = infor.mean.First;
		for ( int i = 0; i < start_mean; i++){
			mean = mean->next;
		}
		
		for (int i =0; i < 10 && mean != NULL; i++ ){
			gotoxy (45, y1++);
			printf("%s", mean->str);
			mean = mean->next;
		}
		if ( infor.mean.n > 10){
			y1 = 19;
			gotoxy(45, y1++);
			printf("<<                     >> ");
		}
		TextColor(231);
		gotoxy(45, y1++);
		printf("Them nghia moi");
		TextColor(224);
		gotoxy(36, y1++);
		printf("Vi du: ");
		for (int i = 0; i < infor.ex.n; i++){
			Print_exa(infor.ex.example[i], y1);
			y1++;
		}
		if (infor.ex.n < 5){
			TextColor(231);
			gotoxy(45, y1);
			printf("Them vi du moi");
		}
		else 
			y1--;
		
		TextColor(228);
		gotoxy(36, y1 + 3);
		printf(">>> LUU Y:");
		gotoxy (36, y1 + 4);
		printf("Mot tu co toi da 5 vi du.");
		TextColor(224);
		ShowCur(0);
		return;
	}
	//--------------------------------------
	TextColor(224);
	gotoxy(36, y);
	printf("%s", them[vt]);
	if (extended == UP){
		if ( y == 5 ){
			if ( infor.mean.n <= 10)
				y = 10 + infor.mean.n;
			else
				y = 21;
			vt = 3;
		}
		else if ( y == 6){
			vt--;
			y--;
		}
		else if ( y == 8 ){
			vt--;
			y = 6;
		}
		else if ( y == 10 + infor.mean.n || y == 21){
			y = 8;
			vt--;
		}	
	}
	else if ( extended == DOWN ){
		if ( y == 5 ){
			y++;
			vt++;
		}
		else if ( y == 6){
			y = 8;
			vt++;
		}
		else if ( y == 8 ){
			if ( infor.mean.n <= 10)
				y = 10 + infor.mean.n;
			else
				y = 21;
			vt++;
		}
		else if ( y == 10 + infor.mean.n || y == 21){
			y = 5;
			vt = 0;
		}
	}
	TextColor (143);
	gotoxy(36, y);
	printf("%s", them[vt]);
	//------------------------------------------------
	ShowCur(0);	
}

void Menu_SuaTu(int extended, word infor, int &vt, int &y, int &y1, int start_mean){ 
	//y: vi tri hang hien tai cua con tro console
	//y1: so hang cuoi cung
	//vt: bien thao tac
	//start_mean: chi so cua mean
	TextColor(224);
	if (extended == 0){
		int tempX, tempY;
		MEAN mean = NULL;
		y1 = 5;
		gotoxy(36, y1++ );
		printf("Tu: %s", infor.key);
		gotoxy(36, y1++);
		printf("Loai tu: %s", infor.type);
		tempX = 45;
		y1++;
		gotoxy(36, y1++);
		printf("Nghia: ");
		mean = infor.mean.First;
		for ( int i = 0; i < start_mean; i++){
			mean = mean->next;
		}
		
		for (int i =0; i < 10 && mean != NULL; i++ ){
			gotoxy (45, y1++);
			printf("%s", mean->str);
			mean = mean->next;
		}
		if ( infor.mean.n > 10){
			y1 = 19;
			gotoxy(45, y1++);
			printf("<<                     >> ");
		}
		TextColor(231);
		gotoxy(45, y1++);
		printf("Them nghia moi");
		
		TextColor(224);
		gotoxy(36, y1++);
		printf("Vi du: ");
		for (int i = 0; i < infor.ex.n; i++){
			Print_exa(infor.ex.example[i], y1);
			y1++;
		}
		if (infor.ex.n < 5){
			TextColor(231);
			gotoxy(45, y1);
			printf("Them vi du moi");
		}
		else 
			y1--;
		
		TextColor(228);
		gotoxy(36, y1 + 3);
		printf(">>> LUU Y:");
		gotoxy (36, y1 + 4);
		printf("Mot tu co toi da 5 vi du.");
		TextColor(224);
		ShowCur(0);
		return;
	}
	//--------------------------------------
	TextColor(224);
	gotoxy(36, y);
	printf("%s", sua[vt]);
	if (extended == UP){
		if ( y == 6 ){
			if ( infor.mean.n <= 10)
				y = 10 + infor.mean.n;
			else
				y = 21;
			vt = 2;
		}
		else if ( y == 8 ){
			vt--;
			y = 6;
		}
		else if ( y == 10 + infor.mean.n || y == 21){
			y = 8;
			vt--;
		}	
	}
	else if ( extended == DOWN ){
		if ( y == 6){
			y = 8;
			vt++;
		}
		else if ( y == 8 ){
			if ( infor.mean.n <= 10)
				y = 10 + infor.mean.n;
			else
				y = 21;
			vt++;
		}
		else if ( y == 10 + infor.mean.n || y == 21){
			y = 6;
			vt = 0;
		}
	}
	TextColor (143);
	gotoxy(36, y);
	printf("%s", sua[vt]);
	//------------------------------------------------
	ShowCur(0);	
}

int Save_Word( NODE &p ){
	if ( strlen(p->infor.key) == 0 || strlen(p->infor.type) == 0){
		return 1;
	}
	NODE q = NULL;
	int save;	
	int chon;		
	int ham_bam = HamBam( p->infor.key[0]);
	for ( q = TuDien[ham_bam].First; q != NULL; q = q->right){
		if ( stricmp(p->infor.key, q->infor.key) < 0){
			break;
		}
	}
	if ( q == TuDien[ham_bam].First){
		save = Insert_first(TuDien, ham_bam, p);
	}
	else if ( q == NULL){
		save = Insert_last(TuDien, ham_bam, p);
	}
	else {
		save = Insert_left(q, p);
	}
	//Write_word(TuDien, ham_bam, p);
	Write_file(TuDien, ham_bam);
	TextColor (15);
	VeKhungCH(40, 7, 60, 4);
	gotoxy (63, 8);
	printf("THONG BAO");
	gotoxy (58, 9);		
	if ( save == 1 ){
		printf("Them tu moi thanh cong.");
	}
	else 
		printf("Loi. Khong them duoc tu");

	chon = getch();
	XoaChu(36, 5, 86, 27, 224);
	return 0;
}

int Save_ThemTu( word &infor){
	TextColor (15);
	VeKhungCH(40, 7, 60, 4);
	gotoxy (52, 8);
	printf("Ban muon them tu %s vao tu dien khong?", infor.key);
	TextColor(240);
	gotoxy(55, 9);
	printf("Co");
	TextColor(15);
	gotoxy(75, 9);
	printf("Khong");
	ShowCur(0);
	//---------------------------------------------
	int KT = 1;
	int chon, extended;
	int vt = 1, tempX = 55;
	while ( KT ){
		chon = getch();
		if ( chon == ENTER){
			if ( vt == 1 ){
				NODE p = New_Node(infor);
				if ( Save_Word(p) == 1){
					if ( strlen(infor.key) == 0) return 5;
					else if (strlen(infor.type) == 0) return 6;
				}
			}	
			else{
				XoaChu(36, 5, 86, 27, 224);
			}
			KT = 0;
		}
		else if ( chon == 224 ){
			extended = getch();
			switch (extended){
				case LEFT:
				case RIGHT:{
					TextColor(15);
					gotoxy(tempX, 9);
					printf("%s", nhac[vt]);
					if (vt == 1){
						vt = 0;
						tempX = 75;
					}
					else {
						vt = 1;
						tempX = 55;
					}
					TextColor(240);
					gotoxy(tempX, 9);
					printf("%s", nhac[vt]);
					break;
				}
			}
		}
	}
	return 0;
}

void ThongBao_TT(NODE p){
	ShowCur(0);
	TextColor(15);
	VeKhungCH(40, 7, 50, 4);
	gotoxy (45, 8);
	printf("Tu %s (%s) da co trong Tu Dien.", p->infor.key, p->infor.type);
	TextColor(240);
	gotoxy ( 55, 9);
	printf("Xem Tu");
	TextColor(15);
	gotoxy( 70, 9);
	printf("Thoat");
	int chon, extended;
	int KT = 1;
	int vt = 1;
	int tempX = 55;
	while ( KT ){
		chon = getch();
		if ( chon == ENTER){
			XoaChu(36,5, 107, 30, 224);
			if ( vt == 1 ){
				XoaChu(36,3, 107, 2, 224);
				Show(p, 0);
			}
			return;
		}
		else if ( chon == 224 ){
			extended = getch();
			switch (extended){
				case LEFT:
				case RIGHT:{
					TextColor(15);
					gotoxy(tempX, 9);
					if (vt == 1){
						printf("Xem tu");
						vt = 0;
						tempX = 70;
						TextColor(240);
						gotoxy(tempX, 9);
						printf("Thoat");
					}
					else {
						printf("Thoat");
						vt = 1;
						tempX = 55;
						TextColor(240);
						gotoxy(tempX, 9);
						printf("Xem tu");
					}
					break;
				}
			}
		}
	}
}

//Kiem tra tu vua them da co chua
NODE KTraTu1( char str[]){
	int i = HamBam(str[0]);
	NODE p = NULL;
	p = TuDien[i].First;
	for (; p != NULL; p = p->right){
		if (stricmp(p->infor.key, str) == 0){
			return p;
		}
	}
	return NULL;
}

int KTraTu2( NODE &p, word &infor){
	do {
		if ( strcmp( infor.type, p->infor.type) == 0){
			return 1;
		}
		else p = p->right;
	}while( p != NULL && strcmp (infor.key, p->infor.key) == 0 );
	return 0;
}

void CapNhat_mean(int y, int &tempY1, word &infor, int &flag){
	int vt, KT, chon, extended;
	int start_mean = 0;
	int tempY = y;
	TextColor(224);
	gotoxy(36, tempY++);
	printf("Nghia:");
	TextColor(143);
	gotoxy(45, tempY);
	if ( infor.mean.n == 0)
		printf("Them nghia moi");
	else
		printf("%s", infor.mean.First->str);
	vt = 0, KT = 1;
	MEAN mean = infor.mean.First;
	while ( KT ){
		chon = getch();
		if ( chon == ENTER ){
			//Them nghia moi
			if (vt == infor.mean.n){
				ShowCur(1);
				TextColor(224);
				mean = New_Mean();
				XoaChu(45, tempY, 50, 1, 224);
				KTraNhap(mean->str, 45, tempY, 90);
				if ( strlen(mean->str) > 0){
					Insert_MeanLast(infor.mean, mean);
					mean = mean->next;
					if ( infor.mean.n % 10 == 0 && infor.mean.n >= 10) {
						start_mean += 10;
						tempY = 20;
					}
					if ( infor.mean.n < 10){
						tempY++;
					}
					infor.mean.n++;
					vt++;
					
					flag = 1;
				}
			}
			//Sua nghia 
			else {
				Sua_Chuoi(mean->str, 45, tempY, 90);
				if ( strlen(mean->str) == 0){
					if ( mean == infor.mean.First){
						Del_MeanFirst(infor.mean);
						mean = infor.mean.First;
					}
					else {
						mean = mean->next;
						Del_MeanMid(infor.mean, vt + 1);
					}
					flag = 1;
				}
				/*else {
					mean = mean->next;
					vt++;
					tempY++;
				}*/
			}
			XoaChu(36, 5, 107, 30, 224);
			//Menu_ThemTu(0, infor, 0, tempY, tempY1, start_mean);
			Menu_SuaTu(0, infor, vt, tempY, tempY1, start_mean);
			TextColor(143);
			gotoxy(45, tempY);
			if (vt == infor.mean.n) 
				printf("Them nghia moi");
			else 
				printf("%s", mean->str);
		}
		else if (chon == 224){
			extended = getch();
			if ( extended == UP || extended == DOWN){
				gotoxy(45, tempY);
				if ( vt == infor.mean.n){
					TextColor(231);
					printf("Them nghia moi");
				}
				else{
					TextColor(224);
					printf("%s", mean->str);
				}
				if ( extended == UP){
					if (vt == start_mean){
						vt = infor.mean.n;
						mean = NULL;
						if (vt > 10) tempY = 20; 
						else tempY = 9 + vt;
					}
					else if (vt == infor.mean.n){
						if ( infor.mean.n > 10 ){
							if ( start_mean + 10 < infor.mean.n){
								tempY = 18;
								vt = start_mean + 9;
							}
							else {
								tempY = 9 + (infor.mean.n - start_mean - 1);
								vt =  infor.mean.n - 1;
							}
						} 
						else {
							tempY--;
							vt--;
						}
						mean = infor.mean.First;
						for (int i = 0; i < vt; i++){
							mean = mean->next;
						}
					}
					else{
						vt--;
						tempY--;
						mean = infor.mean.First;
						for (int i = 0; i < vt; i++){
							mean = mean->next;
						}
					}
				}
				else if ( extended == DOWN){
					if ( vt == infor.mean.n){
						vt = start_mean;
						tempY = 9;
						mean = infor.mean.First;
						for (int i = 0; i < vt; i++){
							mean = mean->next;
						}
					}
					else if ( vt == start_mean + 9 || mean->next == NULL){
						vt = infor.mean.n;
						if ( vt > 10) tempY = 20;
						else tempY++;
					}
					else{
						vt++;
						tempY++;
						mean = mean->next;
					}
				}
				TextColor(143);
				gotoxy(45, tempY);
				if ( vt == infor.mean.n )
					printf("Them nghia moi");
				else 
					printf("%s", mean->str);
			}
			else if ( extended == LEFT && start_mean >= 10){
				start_mean -= 10;
				vt = start_mean;
				tempY = 9;
				mean = infor.mean.First;
				for (int i = 0; i < vt; i++){
					mean = mean->next;
				}
				XoaChu(36, 5, 107, 30, 224);
				Menu_SuaTu(0, infor, vt, tempY, tempY1, start_mean);
				TextColor(143);
				gotoxy(45, tempY);
				if ( vt == infor.mean.n )
					printf("Them nghia moi");
				else 
					printf("%s", mean->str);
			}
			else if ( extended == RIGHT && (start_mean + 10 < infor.mean.n)){
				start_mean += 10;
				vt = start_mean;
				tempY = 9;
				mean = infor.mean.First;
				for (int i = 0; i < start_mean; i++){
					mean = mean->next;
				}
				XoaChu(36, 5, 107, 30, 224);
				Menu_SuaTu(0, infor, vt, tempY, tempY1, start_mean);
				TextColor(143);
				gotoxy(45, tempY);
				if ( vt == infor.mean.n )
					printf("Them nghia moi");
				else 
					printf("%s", mean->str);
			}
			//Xoa nghia da them
			else if ( extended == DEL && vt < infor.mean.n ){
				if ( mean == infor.mean.First){
					Del_MeanFirst(infor.mean);
					mean = infor.mean.First;
				}
				else {
					mean = mean->next;
					Del_MeanMid(infor.mean, vt + 1);
				}
				if ( start_mean == infor.mean.n) start_mean -=10;
				XoaChu(36, 5, 106, 30, 224);
				//Menu_ThemTu(0, infor, 0, tempY, tempY1, start_mean);
				Menu_SuaTu(0, infor, vt, tempY, tempY1, start_mean);
				TextColor(143);
				if ( mean == NULL){
					if ( infor.mean.n > 10 ){
						tempY = 20;
						vt =  infor.mean.n;
					}
					else if (infor.mean.n == 10 ) {
						tempY = 19;
						vt =  infor.mean.n;
						start_mean -= 10;
					}
					gotoxy(45, tempY);
					printf("Them nghia moi");
				}
				else{
					gotoxy(45, tempY);
					printf("%s", mean->str);
				}
				//Menu_SuaTu(0, infor, vt, tempY, tempY1, start_mean);
				flag = 1;
			}
		}
		else if ( chon == ESC ){
			KT = 0;
		}
	}
}

void Capnhat_exa(int y, int &tempY1, word &infor, int &flag, int start_mean){
	int KT, vt, chon, extended;
	int n = infor.ex.n;
	int tempY = y;
	int start;
	int length, strlen_exa;
	char temp[151] = "";
	TextColor(224);
	gotoxy(36, tempY++);
	printf("Vi du:");
	vt = 0, KT = 1;
	TextColor(143);
	gotoxy(45, tempY);
	if ( infor.ex.n == 0)
		printf("Them vi du moi");
	else
		Print_exa(infor.ex.example[vt], tempY);
	while ( KT ){
		chon = getch();
		if ( chon == ENTER ){
			//Them vi du moi
			if (vt == n && n < 5){
				ShowCur(1);
				TextColor(224);
				infor.ex.example[n] = (char*)malloc(sizeof(char)*150);
				XoaChu(36, tempY, 90, 1, 224);
				KTraNhap(infor.ex.example[vt], 45, tempY, 150);
				if ( strlen(infor.ex.example[vt]) > 0){
					infor.ex.n++;
					n++;
					vt++;
					tempY++;
					flag = 1;
				}
			}
			//Sua vi du da them
			else {
				Sua_Chuoi(infor.ex.example[vt], 45, tempY, 150);
				if ( strlen(infor.ex.example[vt]) == 0){
					int kt;
					kt = Del_Exam(infor.ex, vt);
					n--;
				}
				else{
					tempY++;
					vt++;
				}
				flag = 1;
			}
			XoaChu(36, 5, 107, 30, 224);
			Menu_SuaTu(0, infor, vt, tempY, tempY1, start_mean);
			TextColor(143);
			gotoxy(45, tempY);
			if (vt == n ){
				if ( n < 5 ) 
					printf("Them vi du moi");
				else {
					vt = 0;
					tempY = y + 1; 		// tempY1 - 5 + 1
					gotoxy(45, tempY);
					Print_exa(infor.ex.example[vt], tempY);
				}
			}
			else 
				Print_exa(infor.ex.example[vt], tempY);
		}
		else if (chon == 224){
			extended = getch();
			if (extended == UP || extended == DOWN ){
				gotoxy(45, tempY);
				if ( vt == n && n < 5){
					TextColor(231);
					printf("Them vi du moi");
				}
				else if ( vt < n  || n == 5){
					TextColor(224);
					Print_exa(infor.ex.example[vt], tempY);
				}
				if ( extended == UP){
					if (vt == 0 && n < 5){
						vt = n;
						tempY = tempY1;
					}
					else if ( n == 5 && vt == 0){
						vt = n - 1;
						tempY = tempY1;
					}
					else{
						tempY--;
						vt--;
					}
				}
				else if ( extended == DOWN){
					if ( vt == n ){
						vt = 0;
						tempY = tempY1 - infor.ex.n;
					}
					else if ( vt == n-1 && n == 5){
						vt = 0;
						tempY = tempY1 - 4;
					}
					else{
						tempY++;
						vt++;
					} 
				}
				TextColor(143);
				
				if ( vt == infor.ex.n && infor.ex.n < 5){
					gotoxy(45, tempY);
					printf("Them vi du moi");
				}
				else 
					Print_exa(infor.ex.example[vt], tempY);
			}
			//Xoa vi du da them
			else if ( extended == DEL){
				int kt;
				kt = Del_Exam(infor.ex, vt);
				n--;
				flag = 1;
				XoaChu(36, 5, 107, 30, 224);
				Menu_SuaTu(0, infor, vt, tempY, tempY1, start_mean);
				TextColor(143);
				gotoxy(45, tempY);
				if ( vt == infor.ex.n && infor.ex.n < 5){
					gotoxy(45, tempY);
					printf("Them vi du moi");
				}
				else 
					Print_exa(infor.ex.example[vt], tempY);
			}
		}
		else if( chon == ESC){
			KT = 0;
		}
		if ( (n == 5 || (n < 5  && vt < n) ) && strlen(infor.ex.example[vt]) > 90){
			start = 0;
			strlen_exa = strlen(infor.ex.example[vt]);
			length = 90;
			while (!kbhit()){
				if ( strlen_exa - start < 90) 
					length = strlen_exa - start;
				strncpy (temp, infor.ex.example[vt] + start, length);
				temp[length] = '\0';
				XoaChu(45, tempY, 90, 1, 143);
				TextColor(143);
				gotoxy(45, tempY);
				printf("%s", temp);
				start++;
				if ( start == strlen(infor.ex.example[vt])){
					start = 0;
					length = 90;
				}
				Sleep(200);
			}
		}
	}
}

void ThemTu(){
	int flag = 0;
	int KT = 1, KT1 = 1;
	int nhap, chon, extended;
	int vt, vt1;
	vt = 1;
	int y, tempX, tempY, tempY1 ;
	NODE temp_p = NULL;
	int ham_bam;
	int KTword = 0;
	//y: vi tri hang cua con tro console
	//tempY1: vi tri hang cuoi cung
	//----------------------------------------------
	XoaChu(36, 5, 106, 30, 224);
	word infor;
	char temp_w[31] = "";
	char s[151] = "";
	strncpy(infor.key, s, strlen(infor.key));
	strncpy(infor.type, s, strlen(infor.type));
	infor.mean.First = NULL;
	infor.mean.n = 0;
	infor.ex.n = 0;
	tempX = 55;
	y = 5, vt = 0, vt1 = 0; // vt1 la vi tri chon loai tu
	KT = 1, KT1 = 1;
	MEAN mean = NULL;
	for (int i = 36; i < 143; i++){
		gotoxy(i, 4);
		cout << char(196);
	}
	gotoxy(85, 3);
	printf("THEM TU MOI");
	Menu_ThemTu(0, infor, vt, y, tempY1, 0);
	TextColor(143);
	gotoxy(36, 5);
	printf("Tu:");
	//---------------------------------
	while ( KT ){
		nhap = getch();
		if ( nhap == ENTER ){
			//Tu moi
			if ( vt == 0){
				XoaChu(40, 5, 20, 1, 224);
				temp_w[0] = '\0';
				KTraNhapTu(temp_w, 40, 5);
				if ( strlen(temp_w) == 0){
					gotoxy ( 40, 5);
					printf ("%s", infor.key);
				}
				else {
					strcpy(infor.key, temp_w);
					ham_bam = HamBam(temp_w[0]);
					temp_p = KTraTu1(infor.key);
					if ( temp_p != NULL ){
						if ( strlen(infor.type) > 0 ){
							if ( KTraTu2(temp_p, infor)){
								ThongBao_TT(temp_p);
								return;
							}
						}
						else {
							KTword = 1;
						}
					}
				}
				Menu_ThemTu(DOWN, infor, vt, y, tempY1, 0);
			}
			//Chon loai tu
			else if (vt == 1){
				tempX = 45;
				vt1 = 0;
				KT1 = 1;
				TextColor(224);
				gotoxy (36, 6);
				printf("Loai tu: %s", infor.type);
				for (int i = 0; i < 5; i++){
					gotoxy(tempX, 7);
					printf("%s", type[i]);
					tempX += 20;
				}
				tempX = 45;
				TextColor (143);
				gotoxy(tempX, 7);
				printf("%s", type[vt1]);
				while ( KT1 ){
					chon = getch();
					switch( chon ){
						case 224:{
							extended = getch();
							Menu_LoaiTu(extended, vt1, tempX, 7);
							break;
						}
						case ENTER:{
							strcpy(infor.type, type[vt1]);
							XoaChu(36, 6, 30, 1, 224);
							TextColor (224);
							gotoxy(tempX, 7);
							printf("%s", type[vt1]);
							gotoxy(36, 6);
							printf("Loai tu: %s", infor.type);
						}
						case ESC:{
							XoaChu(36, 5, 107, 30, 224);
							Menu_ThemTu(0, infor, vt, y, tempY1, 0);
							Menu_ThemTu(DOWN, infor, vt, y, tempY1, 0);
							KT1 = 0;
							break;
						}
					}
				}
				if ( KTword == 1 ){
					do {
						if ( strcmp( infor.type, temp_p->infor.type) == 0){
							ThongBao_TT(temp_p);
							return;
						}
						else temp_p = temp_p->right;
					}while( temp_p != NULL && strcmp (infor.key, temp_p->infor.key) == 0 );
				}
			}
			//Them nghia moi hoac sua nghia da co
			else if (vt == 2){
				CapNhat_mean(y, tempY1, infor, flag);
				TextColor(224);
				Menu_ThemTu(0, infor, vt, y, tempY1, 0);
				Menu_ThemTu(DOWN, infor, vt, y, tempY1, 0 );
			}
			//Them vi du moi hoac sua vi du da co
			else if ( vt == 3 ){
				Capnhat_exa(y, tempY1, infor, flag, 0);
				TextColor(224);
				Menu_ThemTu(0, infor, vt, y, tempY1, 0);
				Menu_ThemTu(DOWN, infor, vt, y, tempY1, 0 );
			}
		}
		else if (nhap == 224){
			extended = getch();
			Menu_ThemTu(extended, infor, vt, y, tempY1, 0 );
		}
		else if ( nhap == ESC){
			int loi = Save_ThemTu(infor);
			if ( loi == 0){
				XoaChu(40, 7, 60, 4, 224);
				TextColor (15);
				VeKhungCH(40, 7, 60, 4);
				gotoxy (50, 8);
				printf("Ban co muon tiep tuc them tu khong?");
				TextColor(240);
				gotoxy(55, 9);
				printf("Co");
				TextColor(15);
				gotoxy(75, 9);
				printf("Khong");
				ShowCur(0);
				//--------------------------------------
				chon = Chon();
				if (chon == 0){
					XoaChu(36, 3, 107, 30, 224);
					XoaChu(1, 3, 20, 1, 224);
					gotoxy(1,3);
					return;
				}
				else{
					infor.key[0] = '\0';
					infor.type[0] = '\0';
					infor.mean.First = NULL;
					infor.mean.n = 0;
					infor.ex.n = 0;
					KTword = 0;
					XoaChu(36, 5, 107, 30, 224);
					Menu_ThemTu(0, infor, vt, y, tempY1, 0);
					vt = 0;
					y = 5;
					TextColor(143);
					gotoxy(36, 5);
					printf("Tu:");
				}
			}
			else if ( loi == 5){
				XoaChu(36, 5, 107, 30, 224);
				Menu_ThemTu(0, infor, vt, y, tempY1, 0);
				vt = 0;
				gotoxy (36, 5);
				TextColor(143);
				printf("Tu:");
			}
			else if ( loi == 6){
				XoaChu(36, 5, 107, 30, 224);
				Menu_ThemTu(0, infor, vt, y, tempY1, 0 );
				vt = 1;
				gotoxy (36, 6);
				TextColor(143);
				printf("Loai tu:");
			}
		}
		//Luu lai tu vua them
		else if ( nhap == 0 ){
			extended = getch();
			if (extended == F2){
				NODE p = New_Node(infor);
				int loi = Save_Word(p);
				if ( loi == 0){
					TextColor (15);
					VeKhungCH(40, 7, 50, 4);
					gotoxy (50, 8);
					printf("Ban co muon tiep tuc them tu khong?");
					TextColor(240);
					gotoxy(55, 9);
					printf("Co");
					TextColor(15);
					gotoxy(75, 9);
					printf("Khong");
					ShowCur(0);
					//--------------------------------------
					chon = Chon();
					if ( chon == 0 ){
						XoaChu(36, 3, 107, 30, 224);
						XoaChu(1, 3, 20, 1, 224);
						gotoxy(1, 3);
						return;
					}
					else{
						infor.key[0] = '\0';
						infor.type[0] = '\0';
						infor.mean.First = NULL;
						infor.mean.n = 0;
						infor.ex.n = 0;
						XoaChu(36, 5, 106, 30, 224);
						Menu_ThemTu(0, infor, vt, y, tempY1, 0);
						vt = 0;
						y = 5;
						KTword = 0;
						TextColor(143);
						gotoxy(36, 5);
						printf("Tu:");
					}	
				}
				else if ( loi == 1){
					if ( strlen(infor.key) == 0){
						XoaChu(36, 5, 107, 30, 224);
						Menu_ThemTu(0, infor, vt, y, tempY1, 0);
						vt = 0;
						gotoxy (36, 5);
						TextColor(143);
						printf("Tu:");
					}
					else if ( strlen(infor.type) == 0){
						XoaChu(36, 5, 107, 30, 224);
						Menu_ThemTu(0, infor, vt, y, tempY1, 0);
						vt = 1;
						gotoxy (36, 6);
						TextColor(143);
						printf("Loai tu:");
					}
				}	
			}
		}
	}
}

//Kiem tra cac tu xung quanh p 
NODE KT_around(NODE p, char type[]){
	NODE temp = NULL;
	//Kiem tra cac tu ben trai
	temp = p->left;
	while ( temp != NULL && strcmp (p->infor.key, temp->infor.key) == 0 ){
		if (strcmp(type, temp->infor.type) == 0) return temp;
		else temp = temp->left;
	}
	//Kiem tra cac tu ben phai
	temp = p->right;
	while ( temp != NULL && strcmp (p->infor.key, temp->infor.key) == 0 ){
		if (strcmp(type, temp->infor.type) == 0) return temp;
		else temp = temp->right;;
	}
	return NULL;
}

void SuaTu(NODE &p){
	int flag = 0;
	int y = 6;
	int tempY1 = 5;
	int tempY;
	int vt = 0, vt1;
	int kt;
	for (int i = 36; i < 143; i++){
		gotoxy(i, 4);
		cout << char(196);
	}
	gotoxy(85, 3);
	printf("CHINH SUA TU");
	Menu_SuaTu(0, p->infor, vt, y, tempY1, 0);
	TextColor(143);
	gotoxy(36, 6);
	printf("Loai tu:");
	//-------------------------------------------
	int KT = 1, KT1 = 1;
	int nhap, extended, chon;
	int tempX = 50;
	
	word infor;
	infor.mean.First = NULL;
	MEAN temp_mean;
	MEAN mean = p->infor.mean.First;
	strncpy(infor.key, p->infor.key, strlen(p->infor.key)); 	infor.key[strlen(infor.key)] = '\0';
	strncpy(infor.type, p->infor.type, strlen(p->infor.type));		infor.type[strlen(infor.type)] = '\0';
	infor.mean.n = p->infor.mean.n;
	for ( int j = 0; j < infor.mean.n; j++){
		temp_mean = New_Mean();
		strncpy(temp_mean->str, mean->str, strlen(mean->str));
		temp_mean->str[strlen(temp_mean->str)] = '\0';
		Insert_MeanLast(infor.mean, temp_mean);
		mean = mean->next;
	}
	infor.ex.n = p->infor.ex.n;
	for ( int j = 0; j < infor.ex.n; j++){
		infor.ex.example[j]=(char *)malloc(sizeof(char)*151);
		strncpy(infor.ex.example[j], p->infor.ex.example[j], strlen(p->infor.ex.example[j]));
		infor.ex.example[j][strlen(infor.ex.example[j])] = '\0';
	}
	
	mean = NULL;
	NODE temp_p = NULL;
	while ( KT ){
		nhap = getch();
		switch(nhap){
			case ENTER:{
				//Chinh sua loai tu
				if (vt == 0){
					tempX = 45;
					vt1 = 0;
					KT1 = 1;
					TextColor(224);
					gotoxy (36, 6);
					printf("Loai tu: %s", infor.type);
					for (int i = 0; i < 5; i++){
						gotoxy(tempX, 7);
						printf("%s", type[i]);
						tempX += 20;
					}
					tempX = 45;
					TextColor (143);
					gotoxy(tempX, 7);
					printf("%s", type[vt1]);
					while ( KT1 ){
						chon = getch();
						switch( chon ){
							case 224:{
								extended = getch();
								Menu_LoaiTu(extended, vt1, tempX, 7);
								break;
							}
							case ENTER:{
								if (strcmp(type[vt1], infor.type) != 0){
									temp_p = KT_around(p, type[vt1]);
									if ( temp_p != NULL ){
										ThongBao_TT(temp_p);
										return;
									}
									else {
										strcpy(infor.type, type[vt1]);
										flag = 1;
									}
								}
							}
							case ESC:{
								XoaChu(36, 5, 107, 30, 224);
								Menu_SuaTu(0, infor, vt, y, tempY1, 0);
								Menu_SuaTu(DOWN, infor, vt, y, tempY1, 0);
								KT1 = 0;
								break;
							}
						}
					}
				}
				//Chinh sua nghia hoac them nghia moi
				else if (vt == 1){
					CapNhat_mean(y, tempY1, infor, flag);
					TextColor(224);
					Menu_SuaTu(0, infor, vt, y, tempY1, 0);
					Menu_SuaTu(DOWN, infor, vt, y, tempY1, 0);
				}
				//Them vi du moi hoac sua vi du da co
				else if ( vt == 2){
					Capnhat_exa(y, tempY1, infor, flag, 0);
					TextColor(224);
					Menu_SuaTu(0, infor, vt, y, tempY1,0 );
					Menu_SuaTu(DOWN, infor, vt, y, tempY1, 0);
				}
				break;
			}
			case 224: {
				extended = getch();
				Menu_SuaTu(extended, infor, vt, y, tempY1, 0);
				break;
			}
			case ESC:{
				if (flag == 1){
					TextColor (15);
					VeKhungCH(40, 7, 60, 4);
					gotoxy (45, 8);
					printf("Ban co muon luu lai noi dung vua Chinh Sua khong?");
					TextColor(240);
					gotoxy(55, 9);
					printf("Co");
					TextColor(15);
					gotoxy(75, 9);
					printf("Khong");
					ShowCur(0);
					//--------------------------------------
					chon = Chon();
					if (chon == 0){
						XoaChu(36, 3, 107, 32, 224);
						TextColor(224);
						Show(p, 0);
					}
					else{
						Del_mean(p->infor.mean);
						for (int i = 0; i < p->infor.ex.n; i++){
							free(p->infor.ex.example[i]);
						}
						p->infor = infor;
						int n = HamBam(p->infor.key[0]);
						Write_file(TuDien, n);
						XoaChu(36, 3, 107, 32, 224);
						TextColor(224);
						Show(p, 0);
					}	
				}
				return;
			}
			//Luu lai tu vua sua
			case 0:{
				extended = getch();
				if (extended == F2){
					Del_mean(p->infor.mean);
					for (int i = 0; i < p->infor.ex.n; i++){
						free(p->infor.ex.example[i]);
					}
					p->infor = infor;
					int n = HamBam(p->infor.key[0]);
					Write_file(TuDien, n);
					XoaChu(36, 3, 107, 32, 224);
					TextColor(224);
					Show(p, 0);
					return;
				}
				break;
			}
		}
	}
}

void XoaTu_TD( int i, NODE &p){
	//XoaChu(31, 3, 80, 27 );
	TextColor (15);
	VeKhungCH(40, 7, 50, 4);
	gotoxy (52, 8);
	printf("Ban muon xoa tu %s?", p->infor.key);
	TextColor(240);
	gotoxy(55, 9);
	printf("Co");
	TextColor(15);
	gotoxy(70, 9);
	printf("Khong");
	ShowCur(0);
	//---------------------------------
	int KT = 1;
	int chon, extended;
	int vt = 1, tempX = 55;
	int del;
	while ( KT ){
		chon = getch();
		if ( chon == ENTER){
			if ( vt == 1 ){
				if ( p->left == NULL )
					del = Del_first(TuDien, i);
				else if ( p->right == NULL )
					del = Del_last(TuDien, i);
				else 
					del = Del_mid(p);
				if ( del == 1 ){
					TextColor(15);
					VeKhungCH(40, 7, 50, 4);
					gotoxy (60, 8);
					printf("THONG BAO");
					gotoxy (58, 9);
					printf("Xoa tu thanh cong.");
					chon = getch();
					XoaChu(36, 3, 107, 30, 224);
				}
			}
			else{
				XoaChu(36, 3, 107, 30, 224);
				Show(p, 0);
			}
			KT = 0;
		}
		else if ( chon == 224 ){
			extended = getch();
			switch (extended){
				case LEFT:
				case RIGHT:{
					TextColor(15);
					gotoxy(tempX, 9);
					printf("%s", nhac[vt]);
					if (vt == 1){
						vt = 0;
						tempX = 70;
					}
					else {
						vt = 1;
						tempX = 55;
					}
					TextColor(240);
					gotoxy(tempX, 9);
					printf("%s", nhac[vt]);
					break;
				}
			}
		}
	}
}

void TraTu(){
	ShowCur(1);
	gotoxy(1,3);
	int KT = 1, KT1;
	int nhap, extended;
	char xoa[20] = "";
	char kytu[5] = "";
	char tratu[31] = ""; int len = 0;
	int GoiY = 0;
	NODE goiy_node = NULL;
	NODE p = NULL;
	NODE temp_p = NULL;
	int ham_bam = 0;
	int x = 1, y = 3;
	int tempX = 1, tempY = 6; 		//vi tri tu muon xem
	int tempX1 = 0, tempY1 = 0;
	int so_dong, start, vt = 1, start_i = 4;
	//--------------------------------------------------------
	int kb_hit;
	int kbhit_ext;
	//-------------------------------------------------------
	srand(time(NULL));
	ham_bam = rand() % 26;
	p = TuDien[ham_bam].First;
	GoiY = Print_GoiY(p);
	tempY = 3;
	gotoxy(x + len, 3);
	//-------------------------------------------------------
	while( KT ){
		nhap = getch();
		if ( nhap >= 97 && nhap <= 122 ){
			kytu[0] = nhap;
			strncat(tratu, kytu, 1);
			tratu[++len] = '\0';
			temp_p = NULL;
			XoaChu(1,3,20,1, 224);
			Xoa(tempX, tempY);
			gotoxy(1, 3);
			printf("%s", tratu);
			ham_bam = HamBam( tratu[0]);
			p = search(TuDien, ham_bam, tratu);
			Del_GoiY();
			if ( p != NULL){
				GoiY = Print_GoiY(p);
				TextColor(224);
				Move(1, 6);
			}
			TextColor(224);
			goiy_node = p;
			gotoxy(x + len, 3);
			ShowCur(1);
			tempY = 6;
		}
		else if ( nhap == 8 && len > 0){
			XoaChu(1,3, 20, 1, 224);
			gotoxy (1, 3);
			printf("%s", tratu);
			char temp[20] = "";
			tempX1 = whereX();
			tempY1 = whereY();
			gotoxy(--tempX1, tempY1);
			printf(" ");
			gotoxy(tempX1, tempY1);
			tratu[--len] = '\0';
			if ( len > 0){
				ham_bam = HamBam( tratu[0]);
				p = search(TuDien, ham_bam, tratu);
				goiy_node = p;
				Del_GoiY();
				if ( p != NULL){
					GoiY = Print_GoiY(p);
				}
			}
			gotoxy(x + len, 3);
		}
		else if ( nhap == 224 && p != NULL){
			extended = getch();
			if ( vt == 1){
				if (extended == UP && goiy_node->left != NULL){
					if (tempY == 6 ) {
						p = p->left;
						goiy_node = p;
						Del_GoiY();
						GoiY = Print_GoiY(p);
						XoaChu(1, 3, 20, 1, 224);
						gotoxy(1, 3); printf("%s", goiy_node->infor.key);
						Move(tempX, tempY);
						ShowCur(0);
					}
					else if (tempY > 6 ){
						Xoa(tempX, tempY);
						tempY--;
						goiy_node = goiy_node->left;
						XoaChu(1, 3, 20, 1, 224);
						gotoxy(1, 3); printf("%s", goiy_node->infor.key);
						Move(tempX, tempY);
						ShowCur(0);
					}
					//if (tempY == 3){}
				}
				else if (extended == DOWN ){
					if ( tempY == 3){
						goiy_node = p;
						tempY = 6;
						XoaChu(1, 3, 20, 1, 224);
						gotoxy(1, 3);
						printf("%s", goiy_node->infor.key);
						Move(tempX, tempY);
						ShowCur(0);
					}
					else if ( tempY < GoiY + 5 && tempY >= 6 ){
						Xoa(tempX, tempY);
						tempY++;
						goiy_node = goiy_node->right;
						XoaChu(1, 3, 20, 1, 224);
						gotoxy(1, 3);
						printf("%s", goiy_node->infor.key);
						Move(tempX, tempY);
						ShowCur(0);
					}
					else if (tempY == GoiY + 5 && goiy_node->right != NULL){
						p = p->right;
						goiy_node = goiy_node->right;
						Del_GoiY();
						GoiY = Print_GoiY(p);
						XoaChu(1, 3, 20, 1, 224);
						gotoxy(1, 3);
						printf("%s", goiy_node->infor.key);
						Move(tempX, tempY);
						ShowCur(0);
					}
					// if (goiy_node-> == NULL) {}
				}
				else if ( extended == RIGHT && so_dong > 32){
					vt = 2;
					Xoa(tempX, tempY);
					TextColor(15);
					for ( int i = 0; i < 15; i++){
						gotoxy(141, 4 + i );
						printf(" ");
					}
				}
			}
			else if (vt == 2){
				if ( extended == LEFT){
					vt = 1;
					Move(tempX, tempY);
					TextColor(224);
					for ( int i = 0; i < 31; i++){
						gotoxy(141, 4 + i );
						printf(" ");
					}
				}
				else if ( extended == UP && start > 0){
					start_i -= 1;
					XoaChu(36, 3, 107, 32, 224);
					Show(temp_p, --start);
				}
				else if ( extended == DOWN && start < so_dong - 32){
					start_i += 1;
					XoaChu(36, 3, 107, 32, 224);
					Show(temp_p, ++start);
				}
			}
		}
		
		else if ( nhap == 0){
			extended = getch();
			//Them tu vao Tu Dien
			if ( extended == F4 ){
				XoaChu(36, 3, 107, 32, 224);
				ThemTu();
				tratu[0] = '\0';
				len = 0;
				XoaChu(1,3, 20, 1, 224);
				gotoxy(1,3);
				ShowCur(1);
			}
			//Chinh sua tu dang xem
			else if ( extended == F1 && temp_p != NULL ){
				XoaChu(36, 3, 107, 32, 224);
				SuaTu(temp_p);
				XoaChu(1, 3, 30, 1, 224);
				XoaChu(36, 3, 107, 32, 224);
				so_dong = Show(temp_p, 0);
				gotoxy(1, 3);
			}
			//Xoa tu dang xem
			else if ( extended == F3 && temp_p != NULL ){
				XoaTu_TD( ham_bam, temp_p);
				temp_p = NULL;
				//-----------------------------------------
				if (len > 0) {
					ham_bam = HamBam(tratu[0]);
					p = search(TuDien, ham_bam, tratu);
				}
				else {
					p = TuDien[0].First;
				}
				Del_GoiY();
				XoaChu(1, 3, 30, 1, 224);
				Xoa(tempX, tempY);	
				if ( p != NULL ){
					GoiY = Print_GoiY(p);
					tempY = 3;
					gotoxy(x + len, 3);
				}
			}
		}
		else if ( nhap == ENTER && goiy_node != NULL){
			temp_p = goiy_node;
			XoaChu(36, 3, 107, 32, 224);
			so_dong = Show(temp_p, 0);
			start = 0;
			if ( so_dong > 32) {
				Xoa(tempX, tempY);	
				vt = 2;
			}
			else 
				gotoxy( x + len, 3);
		}
		else if ( nhap == ESC){
			KT = 0;
		}
	}
}

int main(){
	resizeConsole(1200,700);
	
	KhoiDong();
	
	
	system("color E0");
	InitTuDien(TuDien);
	//creat_tudien(TuDien);
	Read_data(TuDien);
	
	VeKhung();
	TraTu();
	
	Write_data(TuDien);
	for (int i = 0; i < 26; i++){
		Del_List(TuDien, i);
	}
	
	TextColor(224);
	gotoxy(0, 35);
	return 0;
}

