#include "graphics.h"
#include<conio.h>
#include<sstream>
#include<iostream>
#include<string.h>

using namespace std;

int A[10];
int n;

void DrawBox(int x1, int y1) {
	line(x1, y1, x1, y1 + 50);
	line(x1, y1, x1 + 70, y1);
	line(x1 + 70, y1, x1 + 70, y1 + 50);
	line(x1, y1 + 50, x1 + 70, y1 + 50);

}

void InsertRectangle(int A[], int n) {
	char text1[] = "Array";
	outtextxy(70, 90, text1);
	int x1 = 183, y1 = 120;
	for (int i = 0; i < n; i++) {
		string s = to_string(A[i]);
		char const* pchar = s.c_str();
		drawText(x1 + 25, y1 + 15, pchar);
		DrawBox(x1, y1);
		x1 += 120;
	}

}
void Cout(int A[], int n) {
	char text2[] = "Count";
	outtextxy(70, 200, text2);
	char text4[] = "1";
	outtextxy(80, 210, text4);
	char text5[] = "2";
	outtextxy(90, 210, text5);
	char text6[] = "3";
	outtextxy(80, 210, text6);
	char text7[] = "4";
	outtextxy(70, 210, text7);
	char text8[] = "5";
	outtextxy(70, 210, text8);
	char text9[] = "6";
	outtextxy(70, 210, text9);
	char text10[] = "7";
	outtextxy(70, 210, text10);
	char text11[] = "8";
	outtextxy(70, 210, text11);
	char text12[] = "9";
	outtextxy(70, 210, text12);
	int x2 = 183, y2 = 300;
	for (int i = 0; i < 10; i++) {
		
		DrawBox(x2, y2);
		x2 += 120;
	}
	
 
}


void Output(int A[], int n) {
	char text3[] = "Output";
	outtextxy(70, 270, text3);
	int x3 = 183, y3 = 410;
	for (int i = 0; i < n; i++) {
		string s = to_string(A[i]);
		char const* pchar = s.c_str();
		drawText(x3 + 25, y3 + 15, pchar);
		DrawBox(x3, y3);
		x3 += 120;
	}
}
int main() {
	initgraph();
	char string1[] = "Mo phong cach hoat dong cua CountingSort";
	outtextxy(500, 0, string1);
	cout << endl;
	cout << "Nhap so phan tu cua chuong trinh:";
	cin >> n;
	do {
		if (n <= 1) {
			cout << "Vui long nhap lai n:";
			cin >> n;
		}
	} while (n <= 1);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	system("cls");
	InsertRectangle(A, n);
	Sleep(1000);
	
	Cout(A, n);
	Sleep(1000);

	Output(A, n);
	Sleep(2000);
	system("cls");
	char string2[] = "-----Mo phong hoan tat-------";
	outtextxy(200, 100, string2);
	Sleep(2000);
	
	return 0;
}