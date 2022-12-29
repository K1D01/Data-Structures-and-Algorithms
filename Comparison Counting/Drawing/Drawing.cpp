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
	outtextxy(70, 110, text1);
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
	int x2 = 183, y2 = 210;
	for (int i = 0; i < 10; i++) {
		string s = to_string(A[i]);
		char const* pchar = s.c_str();
		drawText(x2 + 25, y2 + 10, pchar);
		DrawBox(x2, y2);
		x2 += 120;
	}
	
 
}
void Output(int A[], int n) {
	char text3[] = "Output";
	outtextxy(70, 270, text3);
	int x3 = 183, y3 = 300;
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
	char string1[] = "Mo phong cach hoat dong cua CountingSOrt";
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
	Sleep(1000);
	return 0;
}