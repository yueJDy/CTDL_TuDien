#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include "console.h"
using namespace std;

struct mean{
	char str[91];
	mean *next;
};
typedef struct mean *MEAN;
typedef struct {
	int n;
	MEAN First;
}list_mean;

typedef struct{
	int n;
	char *example[5];
}list_exam;

typedef struct{
	char key[31];
	char type[21];
	list_mean mean;
	list_exam ex;
}word;

struct node{
	word infor;
	node *left;
	node *right;
};
typedef struct node *NODE;

typedef struct {
	NODE First;
	NODE Last;
}List;

// MEAN
MEAN New_Mean(){
	MEAN p = (MEAN)malloc(sizeof(mean));
	if ( p == NULL){
		printf("Loi bo nho.\n");
		exit(1);
	}
	p->next = NULL;
	return p;
}

MEAN Init_Mean(){
	MEAN nghia_moi = (MEAN) malloc(sizeof(mean));
	if ( nghia_moi == NULL ){
		printf ("Loi bo nho.\n");
	}
	printf("\nNghia moi: ");
	gets(nghia_moi->str);
	nghia_moi->next=NULL;
	return nghia_moi;
}

void Insert_MeanFirst(list_mean &M, MEAN p){
	if (M.First != NULL){
		p->next = M.First;
	}
	M.First = p;
}

int Insert_MeanMid( list_mean &M, MEAN q, MEAN p){ 	//them 1 nghia vao sau nghia q
	p->next = q->next;
	q->next = p;
}

void Insert_MeanLast(list_mean &M, MEAN &p){
	if ( M.First == NULL){
		M.First = p;
	}
	else {
		MEAN q = M.First;
		while( q->next != NULL){
			q = q->next;
		}
		q->next = p;
	}
}

int Del_MeanFirst(list_mean &M){ 	//xoa 1 nghia trong danh sach lien ket don.
	MEAN p = M.First;
	M.First = p->next;
	free(p);
	M.n--;
	return 1;
}

int Del_MeanMid(list_mean &M, int n){		//xoa 1 nghia trong danh sach tai vi tri n
	MEAN q, p;
	q = M.First;
	for (int i = 1; i < n - 1; i++){
		q = q->next;
	}
	p = q->next;
	q->next = p->next;
	free(p);
	M.n--;
	return 1;
} 	

void creat_mean(list_mean &M){	// tao danh sach nghia 
	char kt;
	M.First = NULL;
	M.n = 0;
	MEAN last, p;
	while(kt!='N'){
		p = Init_Mean();
		if (p != NULL){
			if (M.First == NULL ){
				M.First = p;
			}
			else {
				last->next = p;
			}
			last = p;
			M.n++;
		}
		printf("Tiep tuc them nghia?\n [Y/N]");
		kt=getche();
		if (kt >= 97 && kt <= 122){
			kt -= 32;
		}
	}
}

void Del_mean(list_mean &M){
	MEAN p;
	while (M.First != NULL){
		p = M.First;
		M.First = p->next;
		free(p);
		p = NULL;
	}
}

//EXAMPLE
int Insert_ExamFirst(list_exam &E, char str[]){
	if ( E.n == 5){
		return -1;
	}
	E.example[E.n] = (char*)malloc(sizeof(char)*151);
	if (E.example[E.n] == NULL){
		return 0;
	}
	for ( int i = E.n; i > 0; i--){
		strncpy(E.example[i], E.example[i-1], strlen(E.example[i-1]));
	}
	strncpy(E.example[0], str, strlen(str));
	E.n++;
	return 1;
}

int Insert_ExamMid(list_exam &E, char str[], int i){
	if (E.n == 5){
		return -1;
	}
	E.example[E.n] = (char*)malloc(sizeof(char)*151);
	if (E.example[E.n] == NULL){
		return 0;
	}
	for ( int j = E.n; j > i; j--){
		strncpy(E.example[i], E.example[i-1], strlen(E.example[i-1]));
	}
	strncpy(E.example[i], str, strlen(str));
	E.n++;
	return 1;
}

int Insert_ExamLast(list_exam &E, char str[]){
	if (E.n == 5){
		return -1;
	}
	E.example[E.n] = (char*)malloc(sizeof(char)*151);
	if (E.example[E.n] == NULL){
		return 0;
	}
	strncpy(E.example[E.n++], str, strlen(str));
	return 1;
}

int Del_Exam(list_exam &E, int i){
	E.n--;
	for (int j = i; j < E.n; j++){
		strcpy(E.example[j], E.example[j+1]);
	}
	free(E.example[E.n]);
	return 1;
}

void creat_example(list_exam &ex){
	char kt;
	int i = 0;
	ex.n = 0;
	do{
		ex.example[i] = (char *)malloc(sizeof(char)*151);
		printf("\nVi du thu %d: ", i + 1);
		gets(ex.example[i++]);
		if (i < 4){
			printf("Ban co muon tiep tuc them vi du khong?\n[Y/N]");
			fflush(stdin);
			kt = getche();
			if (kt >= 97 && kt <= 122)
				kt -= 32;
		}
		ex.n++;
	}while(i<5 && kt != 'N');
	printf("\n");
}

//NODE
void KT_Loaitu(char str[]){
	int kt = 1;
	while(kt){
		printf("Loai tu: ");
		gets(str);
		strlwr(str);
		if (strcmp(str,"Danh tu") == 0 || strcmp(str,"tinh tu") == 0 || strcmp(str, "trang tu") == 0 || strcmp(str, "dong tu") == 0){
			kt = 0;
		}
		else {
			printf("Loai tu khong phu hop. Moi ban nhap lai.\n");
		}
	}
}

void Sua_Chuoi1( int TH, char str[], char kytu[5], int start, int n){
	char temp1[151] = "";
	//them 1 ky tu vao chuoi str tai vi tri truoc dau nhay
	if (TH == 1){
		strncpy (temp1, str + start, n);
		temp1[n] = '\0';
		str[start] = '\0';
		strncat(str, kytu, strlen(kytu) );
		
		strcat (str, temp1);
	}
	//xoa 1 ky tu phia truoc dau nhay
	else if ( TH == 0){
		strncpy (temp1, str + start, n);
		str[--start] = '\0';
		strcat (str, temp1);
	}
}

void Sua_Chuoi( char str[], int a, int b, int len_max){
	ShowCur(1);
	int len = strlen(str);
	int tempX;
	int nhap, extended;
	char kytu[5] = "";
	char temp[151] = "";
	int n, x = len;			// x: chi so cua ky tu, n: so ky tu sao chep
	int start = len - 90; 		//vi tri bat dau sao chep
	TextColor(224);
	gotoxy(a, b);
	if (len > 90){
		strncpy (temp, str + start, 90);
		printf("%s", temp);
		tempX = a + 90;
	}
	else{
		printf("%s", str);
		tempX = a + len;
	}
	int KT = 1;
	while ( KT ){
		nhap = getch();
		if ( nhap == 8 ){
			if ( len > 0 && tempX > a){
				n = len - x;
				Sua_Chuoi1(0, str, kytu, x, n);
				for ( int i = 0; i < 90; i++){
					gotoxy (a + i, b);
					printf (" ");
				}
				x--;
				len--;
				gotoxy(a,b);
				if ( len > 90){
					if ( start < len - 90){
						tempX--;
					}
					else {
						start--;
					}
					strncpy (temp, str + start, 90);
					temp[90] = '\0';
					printf("%s", temp);
				}
				else{
					printf("%s",str);
					tempX--;
				}
				gotoxy(tempX, b);
			}
		}
		else if ( nhap == 224){
			extended = getch();
			if ( extended == 75 && x > 0){  //LEFT = 75
				x--;
				if (tempX == a && len > 90){
					start = x;
					strncpy (temp, str + start, 90);
					gotoxy(a,b);
					printf("%s", temp);
				}
				else if ( tempX > a) tempX--;
				gotoxy (tempX, b);
			}
			else if ( extended == 77 && x < len ){ 	// RIGHT = 77
				if (len > 90){
					if (tempX < (a + 90)) tempX++;
					else if ( tempX == a + 90 ){
						start++;
						strncpy (temp, str + start, 90);
						gotoxy(a,b);
						printf("%s", temp);
					}
				}
				else if (len <= 90 && tempX < a + len ){
					tempX++;
				}
				gotoxy(tempX, b);
				x++;
			}
		}
		// ENTER = 13;  ESC = 27
		else if ( nhap == 13 || nhap == 27){
			KT = 0;;
		}
		else if (len < len_max - 1) {
			kytu[0] = nhap;
			if ( (nhap == ' ' && str[x-1] != ' ' && str[x] != ' ') || nhap != ' '){
				n = len - x;
				Sua_Chuoi1( 1, str, kytu, x, n);
				
				for ( int i = 0; i < 90; i++){
					gotoxy (a +i, b);
					printf (" ");
				}
				gotoxy(a,b);
				if (len > 90){
					if ( x != len) tempX++;
					else if (start == len - 90 && x == len ) start++;
					x++;
					strncpy (temp, str + start, 90);
					printf("%s", temp);
				}
				else {
					x++;
					tempX++;
					printf("%s", str);
				}
				len++;	
				gotoxy(tempX, b);
			}	
		}
	}
	str[len] = '\0';
}

void KTraNhap(char str[], int a, int b, int len_max){
	ShowCur(1);
	gotoxy (a, b);
	int nhap;
	char kytu[5] = "";
	char chuoi[len_max + 1] = ""; 
	char temp[151] = "";
	int len = 0;
	int x, y;
	while( nhap = getch()){
		if ( nhap == 8 ){
			if (len > 0){
				x = whereX();
				y = whereY();
				gotoxy(--x, y);
				printf(" ");
				gotoxy(x,y);
				chuoi[--len] = '\0';
			}
		}
		else if ( nhap == 13){
			break;
		}
		else if ( nhap == 224){
			nhap = getch();
		}
		else if ( nhap != 27 && len < len_max - 1){
			if ( nhap == ' ' ){
				if (  len > 0 && chuoi[len - 1] != ' '){
					kytu[0] = nhap;
					strncat(chuoi,kytu,1);
					len++;
				}
			}
			else{
				kytu[0] = nhap;
				strncat(chuoi,kytu,1);
				len++;
			}
			gotoxy(a, b);
			if (len > 90){
				strncpy (temp, chuoi + (len - 90), 90);
				printf("%s", temp);
			}
			else
				printf("%s", chuoi);
		}
	}
	strcpy(str, chuoi);
	str[len] ='\0';
}

void KTraNhapTu(char str[], int a, int b){
	ShowCur(1);
	gotoxy (a, b);
	TextColor(224);
	int nhap;
	char kytu[5] = "";
	char tratu[31] = ""; 
	int len = 0;
	int x, y;
	while( nhap = getch() ){
		if ( ((nhap >= 97 && nhap <= 122) || (nhap >= 65 && nhap <= 90)) && len < 30 ){
			kytu[0] = nhap;
			strlwr(kytu);
			strncat(tratu,kytu,1);
			len++;
			gotoxy(a, b);
			printf("%s", tratu);
		}
		else if ( nhap == 8 && len > 0){
			x = whereX();
			y = whereY();
			gotoxy(--x, y);
			printf(" ");
			gotoxy(x,y);
			tratu[--len] = '\0';
		}
		else if ( nhap == 13){
			break;
		}
		fflush(stdin);
	}
	strcpy(str, tratu);
	//str[len] ='\0';
}

word New_word(){
	word a;
	printf("Tu moi: ");
	//KTraNhapTu(a.key, 0, 1);
	KT_Loaitu(a.type);
	creat_mean(a.mean);
	creat_example(a.ex);
	return a;
}

NODE New_Node(word moi){
	NODE p = (NODE)malloc(sizeof(node));
	if (p == NULL){
		printf ("Bo nho khong du. Khong the them tu moi.\n");
		exit(1);
	}
	p->infor = moi;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int Insert_first(List A[], int i, NODE &p){
	if (A[i].First == NULL)
		A[i].Last = p;
	else{
		p->right = A[i].First;
		A[i].First->left = p;
	}
	A[i].First = p;
	return 1;
}

int Insert_right( NODE &q, NODE &p){ 	// them p vao ben phai q
	NODE r;		// r la nut sau cua q
	r = q->right;
	p->right = r;
	p->left = q;
	r->left = p;
	q->right = p;
	return 1;
}

int Insert_left(NODE &q, NODE &p){ 	// them p vao ben trai q
	NODE r;
	r = q->left;
	p->right = q;
	p->left = r;
	r->right = p;
	q->left = p;
	return 1;
}

int Insert_last(List A[], int i, NODE &p){
	if ( A[i].First == NULL){
		A[i].First = p;
	}
	else {
		A[i].Last->right = p;
		p->left = A[i].Last;
	}
	A[i].Last = p;
	return 1;
}

int Del_first(List A[], int i){
	NODE p = NULL;
	p = A[i].First;
	A[i].First = p->right;
	A[i].First->left = NULL;
	free(p);
	return 1;
}

int Del_mid(NODE &p){
	NODE t, s;
	t = p->left;
	s = p->right;
	t->right = s;
	s->left = t;
	free(p);
	return 1;
}

int Del_last(List A[], int i){
	NODE p = NULL;
	p = A[i].Last;
	A[i].Last = p->left;
	A[i].Last->right = NULL;
	free(p);
	return 1;
}

int Del_Node(NODE &p){
	Del_mean(p->infor.mean);
	for (int i = 0; i < p->infor.ex.n; i++){
		free(p->infor.ex.example[i]);
	}
	free(p);
	p = NULL;
	return 1;
}

void Del_List(List A[], int i){
	NODE p = A[i].First;
	if ( p == NULL )
		return;
	while ( p != NULL){
		A[i].First = p->right;
		if ( Del_Node(p) != 1 ){
			printf("Loi");
			exit(1);
		}
		p = A[i].First;
	}
}

NODE search(List A[], int i, char str[31]){
	NODE p = NULL;
	p = A[i].First;
	for (; p != NULL; p = p->right){
		if (strnicmp(p->infor.key, str, strlen(str)) == 0){
			return p;
		}
	}	
	return NULL;
}

int HamBam(int s){
	return s - 97;
}

void InitTuDien(List A[]){
	for (int i = 0; i < 26; i++){
	//	A[i] = (List*)malloc(sizeof(List));
		A[i].First = NULL;
		A[i].Last = NULL;
	}
}

void ReCreat_tudien(List A[]){
	int kiemtra = 1;
	int kt;
	word w;
	char kytu;
	NODE p = NULL;
	NODE q = NULL;
	int ham_bam;
	int c = 13;
	while(kiemtra ){
		system("cls");
		w = New_word();
		p = New_Node(w);
		kytu = w.key[0];
		ham_bam = HamBam((int)kytu);
		for ( q = A[ham_bam].First; q != NULL; q = q->right){
			if ( stricmp(w.key, q->infor.key) < 0){
				break;
			}
		}
		if ( q == A[ham_bam].First){
			kt = Insert_first(A, ham_bam, p);
		}
		else if ( q == NULL){
			kt = Insert_last(A, ham_bam, p);
		}
		else {
			kt = Insert_left(q, p);
		}
		if (kt == 0){
			exit(1);
		}
		printf("Tiep tuc them tu moi khong?");
		fflush(stdin);
		c = getch();
		if ( c == 27 ){
			kiemtra = 0;
		}
	}
}

void Read_data(List A[]){
	char s[6] = "a.txt";
	int ham_bam = 0;
	NODE p = NULL; 
	word infor;
	MEAN temp;
	for (int i = 0; i < 26; i++){
		s[0] = 'a' + i ;
		FILE *file = fopen (s, "rb");
		if (file == NULL){
			printf("Khong the mo file de doc.");
			exit(1);
		}
		while ( fread(&(infor.key), 31*sizeof (char), 1, file) ){
			//p = (NODE)malloc(sizeof(node));
			//fread(&(infor.key), 20*sizeof (char), 1, file);
			//cout << infor.key << endl;
			fread(&(infor.type), 21*sizeof(char), 1, file);
			//cout << infor.type << endl;
			fread(&(infor.mean.n), sizeof(int), 1, file);
			//cout << infor.mean.n << endl;
			infor.mean.First = NULL;
			for ( int j = 0; j< infor.mean.n; j++){
				temp = New_Mean();
				fread(&(temp->str), 91*sizeof(char), 1, file);
				//cout << temp->str << endl;
				//Insert_MeanFirst(infor.mean, temp);
				Insert_MeanLast(infor.mean, temp);
			}
			fread(&(infor.ex.n), sizeof(int), 1, file);
			//cout << infor.ex.n << endl;
			for ( int j = 0; j < infor.ex.n; j++){
				infor.ex.example[j]=(char *)malloc(sizeof(char)*151);
				fread((infor.ex.example[j]), 151*sizeof(char), 1, file);
				//cout << infor.ex.example[j] << endl;
			}
			p = New_Node(infor);
			//cout << ham_bam << endl;
			Insert_last( A, i, p);
		}
		fclose(file);
	}
}

void Write_file(List A[], int n){
	NODE p = NULL;
	MEAN temp1 = NULL;
	char name[6] = "a.txt";
	name[0] = 'a' + n;
	FILE *file = fopen (name, "wb");
	if (file == NULL){
		printf("Loi mo File");
		exit(1);
	}
	p = A[n].First;
	while (p != NULL ){
		fwrite(&(p->infor.key), 31*sizeof (char), 1, file);
		fwrite(&(p->infor.type), 21*sizeof(char), 1, file);
		fwrite(&(p->infor.mean.n), sizeof(int), 1, file);
		temp1 = p->infor.mean.First;
		for ( ; temp1 != NULL; temp1 = temp1->next){
			fwrite(&(temp1->str), 91*sizeof(char), 1, file);
		}
		fwrite(&(p->infor.ex.n), sizeof(int), 1, file);
		for (int i = 0; i < p->infor.ex.n; i++){
			fwrite((p->infor.ex.example[i]), 151*sizeof(char), 1, file);
		}
		p = p->right;
	}
	fclose(file);
}

void Write_data(List A[]){
	char s[6] = "a.txt";
	for (int i = 0; i < 26; i++){
		Write_file(A, i);
	}
}

void Write_word(List A[], int i, NODE p){
	char s[6] = "a.txt";
	MEAN temp1 = NULL;
	s[0] = 'a' + i;
	FILE *file = fopen (s, "ab");
	if (file == NULL){
		printf("Loi mo File");
		exit(1);
	}
	fwrite(&(p->infor.key), 31*sizeof (char), 1, file);
	fwrite(&(p->infor.type), 21*sizeof(char), 1, file);
	fwrite(&(p->infor.mean.n), sizeof(int), 1, file);
	temp1 = p->infor.mean.First;
	for ( ; temp1 != NULL; temp1 = temp1->next){
		fwrite(&(temp1->str), 91*sizeof(char), 1, file);
	}
	fwrite(&(p->infor.ex.n), sizeof(int), 1, file);
	for (int i = 0; i < p->infor.ex.n; i++){
		fwrite((p->infor.ex.example[i]), 151*sizeof(char), 1, file);
	}
	fclose(file);
}
