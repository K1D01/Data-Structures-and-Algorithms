


#include "graphics.h"
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <string>
#include<iostream>

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



void drawstep(Record A[], int t, int p, int q, int r, int d, int i, int stepth) {
	if (stepth >= 1) {
		if (stepth == 1) setfontcolor(7);
		outtextxy(10 + Otypetext2x, Otypetext2y + 40, "t = " + to_string(t));
		outtextxy(40 + Otypetext2x, Otypetext2y + 50, "p = " + to_string(p));
		outtextxy(40 + Otypetext2x, Otypetext2y + 60, "q = " + to_string(q));
		outtextxy(40 + Otypetext2x, Otypetext2y + 70, "r = " + to_string(r));
		outtextxy(40 + Otypetext2x, Otypetext2y + 80, "d = " + to_string(d));
		outtextxy(40 + Otypetext2x, Otypetext2y + 110, "Kiem tra (" + to_string(d) + " > 0)");
		setfontcolor(2);
	}

	if (stepth >= 2 && stepth <= 4) {
		if (stepth == 2) setfontcolor(9);
		outtextxy(70 + Otypetext2x, Otypetext2y + 140, "i = " + to_string(i));
		setfontcolor(2);
	}

	if (stepth >= 3 && stepth <= 4) {
		if (stepth == 3) setfontcolor(5);
		outtextxy(100 + Otypetext2x, Otypetext2y + 160, "Kiem tra (("
			+ to_string(i) + " & "
			+ to_string(p) + ") == "
			+ to_string(i) + " && "
			+ to_string(A[i + 1].Key) + " > "
			+ to_string(A[i + d + 1].Key) + ")");
		setfontcolor(2);
	}

	if (stepth == 4) {
		setfontcolor(5);
		outtextxy(130 + Otypetext2x, Otypetext2y + 190, "swap(A["
			+ to_string(i + 1) + "], A["
			+ to_string(i + d + 1) + "]);");
		setfontcolor(2);
	}

	if (stepth == 5) {
		setfontcolor(5);
		outtextxy(70 + Otypetext2x, Otypetext2y + 210, "d = " + to_string(q - p));
		outtextxy(70 + Otypetext2x, Otypetext2y + 220, "q = " + to_string(q / 2));
		outtextxy(70 + Otypetext2x, Otypetext2y + 230, "r = " + to_string(p));
		setfontcolor(2);
	}

	Sleep(1500);
}


void draw(Record A[], int N, int j, int k) {
	setcolor(2), setfontcolor(2);

	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery, "A[Index]Key");

	for (int i = 1; i <= N; ++i)
	{
		if (i == k || i == j) setcolor(5), setfontcolor(5);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, i);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery, A[i].Key);

		rectangle(Otyperectx + 61 * i, Otyperecty - 15 * A[i].Key,
			Otyperectx + 50 + 61 * i, Otyperecty);

		setcolor(2), setfontcolor(2);
	}
}
void draw2(Record A[], int N, int j, int k)
{
	system("cls");
	draw(A, N, j, k);
	Sleep(50);
	draw(A, N, j, k);
	Sleep(50);
}


void MergeSort(Record A[], int N) {
	draw(A, N, -1, -1);

	int T = log2(N) - (1 << (int)log2(N) == N);
	for (int t = T; t >= 0; --t) {
		int p = 1 << t;
		int q = 1 << T;
		int r = 0;
		int d = p;
		draw2(A, N, -1, -1);
		drawstep(A, t, p, q, r, d, -1, 1);

		while (d) {
			draw2(A, N, -1, -1);
			drawstep(A, t, p, q, r, d, -1, 2);
			for (int i = 0; i < N - d; ++i) {
				draw2(A, N, i + 1, i + d + 1);
				drawstep(A, t, p, q, r, d, i, 3);
				if ((i & p) == r && A[i + 1].Key > A[i + d + 1].Key) {
					draw2(A, N, i + 1, i + d + 1);
					drawstep(A, t, p, q, r, d, i, 4);
					swap(A[i + 1], A[i + d + 1]);
				}
			}
			draw2(A, N, -1, -1);
			drawstep(A, t, p, q, r, d, -1, 5);
			d = q - p;
			q = q / 2;
			r = p;
		}
	}
	draw2(A, N, -1, -1);
}

int main() {
	initgraph();
	DisableSelection();


	cout << "Nhap vao so luong phan tu: ";
	int N; cin >> N;
	Record R[100];
	cout << "Nhap vao gia tri cac phan tu: ";
	for (int i = 1; i <= N; ++i) cin >> R[i].Key;

	MergeSort(R, N);

	_getch();
	system("cls");
	return 0;
}