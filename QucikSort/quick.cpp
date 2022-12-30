#include "graphics.h"
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
using namespace std;
const int Otypetext2x = 500;
const int Otypetext2y = 0;

const int Otypenumberx = 100;
const int Otypenumbery = 50;

const int Otyperectx = 50;
const int Otyperecty = 300;

struct Record {
	int Key;
};

struct Data {
	int l, r;
	Data* next;
};

void draw(Record R[], int N, int l, int j, int k) {
	setcolor(4), setfontcolor(4);

	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery, "R[Index]Key");

	for (int i = 1; i <= N; ++i)
	{
		if (i == l)	setcolor(7), setfontcolor(7);
		if (i == j)	setcolor(11), setfontcolor(11);
		if (i == k) setcolor(9), setfontcolor(9);

		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, i);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery, R[i].Key);

		rectangle(Otyperectx + 61 * i, Otyperecty - 15 * R[i].Key,
			Otyperectx + 50 + 61 * i, Otyperecty);

		setcolor(4), setfontcolor(4);
	}
}
void Draw(Record R[], int N, int l, int j, int k)
{
	system("cls");
	draw(R, N, l, j, k);
	Sleep(10);
	draw(R, N, l, j, k);
	Sleep(1000);
}



void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
int partition(Record A[], int low, int high)
{
	int pivot = A[high].Key;    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && A[left].Key < pivot) left++;
		while (right >= left && A[right].Key > pivot) right--;
		if (left >= right) break;
		swap(A[left], A[right]);
		left++;
		right--;
	}
	swap(A[left], A[high]);
	return left;
}

void QuickSort(Record A[], int N, int low, int high) {
	Draw(A, N, -1, -1, -1);
	
	/* Hàm thực hiện giải thuật quick sort */
		if (low < high)
		{
			/* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
			 và là phần tử chia mảng làm 2 mảng con trái & phải */
			int pi = partition(A, low, high);

			// Gọi đệ quy sắp xếp 2 mảng con trái và phải
			QuickSort(A,N, low, pi - 1);
			Draw(A, N,-1, low, pi-1);
			QuickSort(A,N, pi + 1, high);
			Draw(A,N, -1, pi+1, high);
		}
		Draw(A, N, -1, -1, -1);
	

}

int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	char string1[] = "/=MO PHONG CACH HOAT DONG CUA QUICK SORT==";
	setfontcolor(8);//xanh
	char string3[] = "(nhan bat ki phim de tiep tuc)";//do
	outtextxy(500, 200, string1);
	setfontcolor(9);
	outtextxy(520, 240, string3);
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
	Record A[100];
	int low, high;
	setfontcolor(7);
	cout << "Nhap vao gia tri cac phan tu: ";
	setfontcolor(10);
	for (int i = 1; i <= N; ++i) cin >> A[i].Key;

	QuickSort(A, N, low, high);
	char string2[] = "-----MO PHONG HOAN TAT-------";
	outtextxy(500, 100, string2);
	Sleep(5000);
	return 0;

}