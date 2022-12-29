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


void draw(Record R[], int N, int j, int k) {
	setcolor(4), setfontcolor(4);

	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery, "R[Index]Key");

	for (int i = 1; i <= N; ++i)
	{
		if (i == k || i == j) setcolor(9), setfontcolor(9);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, i);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery, R[i].Key);

		rectangle(Otyperectx + 61 * i, Otyperecty - 15 * R[i].Key,
			Otyperectx + 50 + 61 * i, Otyperecty);
		setcolor(4), setfontcolor(4);
	}
}

void draw2(Record R[], int N, int j, int k) {
	system("cls");
	draw(R, N, j, k);
	Sleep(10);
	draw(R, N, j, k);
	Sleep(1000);
}


void SelectionSort(Record R[], int N) {
	int pos;
	Record P;

	draw(R, N, -1, -1);

	for (int j = N; j >= 2; --j) {
		pos = j;
		P = R[j];
		draw2(R, N, -1, -1);

		for (int i = j; i >= 1; --i) {
			draw2(R, N, -1, -1);


			if (R[i].Key > P.Key) {
				draw2(R, N, j, pos);

				P = R[i];
				pos = i;
			}
		}
		draw2(R, N, j, pos);

		Record temp = R[j];
		R[j] = R[pos];
		R[pos] = temp;
		draw2(R, N, j, pos);

	}

	draw2(R, N, -1, -1);
}




int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);



	cout << "Hay nhap so luong phan tu: ";
	int N; cin >> N;
	Record R[100];
	cout << "Nhap vao gia tri cac phan tu: ";
	for (int i = 1; i <= N; ++i) cin >> R[i].Key;

	SelectionSort(R, N);

	_getch();
	system("cls");
	return 0;
}