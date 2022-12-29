#include "graphics.h"
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;


const int Otypetext2x = 500;
const int Otypetext2y = 0;

const int Otypenumberx = 100;
const int Otypenumbery = 50;

const int Otyperectx = 50;
const int Otyperecty = 300;


struct Record {
	char Data;
	int Key;
};


void draw(Record A[], int n, int j, int k) {
	setcolor(4), setfontcolor(4);

	outtextxy(Otypenumberx - 80, Otypenumbery - 10, "Index");
	outtextxy(Otypenumberx - 80, Otypenumbery, "R[Index]Key");

	for (int i = 1; i <= n; ++i)
	{
		if (i == k || i == j) setcolor(9), setfontcolor(9);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, i);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery, A[i].Key);

		rectangle(Otyperectx + 61 * i, Otyperecty - 15 * A[i].Key,
			Otyperectx + 50 + 61 * i, Otyperecty);
		setcolor(4), setfontcolor(4);
	}
}

void draw2(Record A[], int n, int j, int k) {
	system("cls");
	draw(A, n, j, k);
	Sleep(10);
	draw(A, n, j, k);
	Sleep(500);
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}


void SelectionSort(Record A[], int n) {
	int i, j, vt = 0;
	Record max;
	Record temp;
	draw(A, n, -1, -1);
	for (i = n - 1; i >= 1; i--) {
		max = A[i];
		draw2(A, n, -1, -1);
		for (j = i - 1; j >= 0; j--) {
			draw2(A, n, -1, -1);
			if (A[j].Key > max.Key) {
				draw2(A, n, j, vt);
				max = A[j];
				vt = j;
			}
		}
		if (max.Key != A[i].Key) {
			draw2(A, n, i, vt);
			temp = A[i];
			A[i] = max;
			A[vt] = temp;
			draw2(A, n, i, vt);
		}
		draw2(A, n, -1, -1);
	}
	

}


int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	char string1[] = "MO PHONG CACH HOAT DONG CUA SELECTIONSORT";
	setfontcolor(8);//xanh
	char string3[] = "(nhan bat ki phim de tiep tuc)";//do
	outtextxy(500, 200, string1);
	setfontcolor(9);
	outtextxy(540, 240, string3);
	cout << endl;
	_getch();
	system("cls");
	setfontcolor(7);
	cout << "Nhap so luong phan tu: ";
	setfontcolor(10);
	int N; cin >> N;
	setfontcolor(7);
	do {
		if (N <= 1) {
			setfontcolor(3);
			cout << "Vui long nhap lai n:";
			cin >> N;
		}
	} while (N <= 1);
	Record R[100];
	setfontcolor(7);
	cout << "Nhap vao gia tri cac phan tu: ";
	setfontcolor(10);
	for (int i = 1; i <= N; ++i) cin >> R[i].Key;

	SelectionSort(R, N);
	char string2[] = "-----MO PHONG HOAN TAT-------";
	outtextxy(500, 100, string2);
	Sleep(5000);
	return 0;


}