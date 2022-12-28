#include "graphics.h"
#include<conio.h>
#include<sstream>
#include<iostream>
#include<string.h>

using namespace std;

int A[10];
int n;
// Ve hop
void DrawBox(int x1, int y1) {
	line(x1, y1, x1, y1 + 50);
	line(x1, y1, x1 + 70, y1);
	line(x1 + 70, y1, x1 + 70, y1 + 50);
	line(x1, y1 + 50, x1 + 70, y1 + 50);

}

//Tao mang o vuong 
void InsertRectangle(int A[], int n) {
	char text2[] = "Sort";
	outtextxy(70, 200, text2);
	int x2 = 183, y2 = 210;
	for (int i = 0; i < n; i++) {
		string s = to_string(A[i]);
		char const* pchar = s.c_str();
		drawText(x2 + 25, y2 + 15, pchar);
		DrawBox(x2, y2);
		x2 += 120;
	}

}


// Thuat toan chinh
void ShellSortVisualize(int A[], int n) {
	char text2[] = "Sort";
	outtextxy(70, 200, text2);
	int x2 = 183, y2 = 210;
	for (int i = 0; i < n; i++) {
		string s = to_string(A[i]);
		char const* pchar = s.c_str();
		drawText(x2 + 25, y2 + 15, pchar);
		DrawBox(x2, y2);
		x2 += 120;
	}


	for (int k = n/2; k > 0; k = k / 2) {
		int swap;
		int khoangcach = 120;
		int x1 = 183, y1 = 210;
		char textk[] = "K = ";
		drawText(70, 300, textk);
		string aa = to_string(k);
		char const* pchar = aa.c_str();
		drawText(100, 300, pchar);
		Sleep(1000);
		if (k == 1) {
			system("cls");
			InsertRectangle(A, n);
			string aa = to_string(k);
			char const* pchar = aa.c_str();
			drawText(70, 300, textk);
			drawText(100, 300, pchar);
			Sleep(1000);
			for (int dem = 0; dem < n-1; dem++) {
				
				setcolor(2);
				DrawBox(x1 + dem * khoangcach, y1);
				DrawBox(x1 + dem * khoangcach + khoangcach * (k), y1);
				Sleep(1000);
				setcolor(15);
				DrawBox(x1 + dem * khoangcach, y1);
				DrawBox(x1 + dem * khoangcach + khoangcach * (k), y1);
				if (A[dem] > A[dem + k]) {
					swap = A[dem];
					A[dem] = A[dem + k];
					A[dem + k] = swap;
					system("cls");
					InsertRectangle(A, n);
					string aa = to_string(k);
					char const* pchar = aa.c_str();
					drawText(70, 300, textk);
					drawText(100, 300, pchar);
					Sleep(1000);



					if (dem - k >= 0) {
						if (A[dem - k] > A[dem]) {
							swap = A[dem - k];
							A[dem - k] = A[dem];
							A[dem] = swap;
							setcolor(2);
							DrawBox(x1 + dem * khoangcach, y1);
							DrawBox(x1 - dem * khoangcach + khoangcach * (k), y1);
							Sleep(1000);
							setcolor(15);
							DrawBox(x1 + dem * khoangcach, y1);
							DrawBox(x1 - dem * khoangcach + khoangcach * (k), y1);
							system("cls");
							InsertRectangle(A, n);
							string aa = to_string(k);
							char const* pchar = aa.c_str();
							drawText(70, 300, textk);
							drawText(100, 300, pchar);
							Sleep(1000);
						}
					}
					system("cls");
					InsertRectangle(A, n);
					string a1 = to_string(k);
					char const* pchar1 = aa.c_str();
					drawText(70, 300, textk);
					drawText(100, 300, pchar1);
					

				}
			}
		}
		else {
			if (n % 2 == 0) {
				for (int dem = 0; dem < n / 2; dem++) {
					setcolor(2);
					DrawBox(x1 + dem * khoangcach, y1);
					DrawBox(x1 + dem * khoangcach + khoangcach * (k), y1);
					Sleep(1000);
					setcolor(15);
					DrawBox(x1 + dem * khoangcach, y1);
					DrawBox(x1 + dem * khoangcach + khoangcach * (k), y1);
					if (A[dem] > A[dem + k]) {
						swap = A[dem];
						A[dem] = A[dem + k];
						A[dem + k] = swap;
						system("cls");
						InsertRectangle(A, n);
						string aa = to_string(k);
						char const* pchar = aa.c_str();
						drawText(70, 300, textk);
						drawText(100, 300, pchar);
						Sleep(1000);

						if (dem - k >= 0) {
							if (A[dem - k] > A[dem]) {
								swap = A[dem - k];
								A[dem - k] = A[dem];
								A[dem] = swap;
								setcolor(2);
								DrawBox(x1 + dem * khoangcach, y1);
								DrawBox(x1 + dem * khoangcach - khoangcach * (k), y1);
								Sleep(1000);
								setcolor(15);
								DrawBox(x1 + dem * khoangcach, y1);
								DrawBox(x1 + dem * khoangcach - khoangcach * (k), y1);
								system("cls");
								InsertRectangle(A, n);
								string aa = to_string(k);
								char const* pchar = aa.c_str();
								drawText(70, 300, textk);
								drawText(100, 300, pchar);

							}
						}

						system("cls");
						InsertRectangle(A, n);
						string aa2 = to_string(k);
						char const* pchar2 = aa.c_str();
						drawText(70, 300, textk);
						drawText(100, 300, pchar2);
					}
				}
			}
			if (n % 2 == 1) {
				for (int dem = 0; dem <= n / 2; dem++) {
					setcolor(2);
					DrawBox(x1 + dem * khoangcach, y1);
					DrawBox(x1 + dem * khoangcach + khoangcach * (k), y1);
					Sleep(1000);
					setcolor(15);
					DrawBox(x1 + dem * khoangcach, y1);
					DrawBox(x1 + dem * khoangcach + khoangcach * (k), y1);
					if (A[dem] > A[dem + k]) {
						swap = A[dem];
						A[dem] = A[dem + k];
						A[dem + k] = swap;
						system("cls");
						InsertRectangle(A, n);
						string aa = to_string(k);
						char const* pchar = aa.c_str();
						drawText(70, 300, textk);
						drawText(100, 300, pchar);
						


						if (dem - k >= 0) {
							if (A[dem - k] > A[dem]) {
								swap = A[dem - k];
								A[dem - k] = A[dem];
								A[dem] = swap;
								setcolor(2);
								DrawBox(x1 + dem * khoangcach, y1);
								DrawBox(x1 - dem * khoangcach + khoangcach * (k), y1);
								Sleep(1000);
								setcolor(15);
								DrawBox(x1 + dem * khoangcach, y1);
								DrawBox(x1 - dem * khoangcach + khoangcach * (k), y1);
								system("cls");
								InsertRectangle(A, n);
								string aa = to_string(k);
								char const* pchar = aa.c_str();
								drawText(70, 300, textk);
								drawText(100, 300, pchar);
								
							}
						}

						system("cls");
						InsertRectangle(A, n);
						string aa3 = to_string(k);
						char const* char3 = aa.c_str();
						drawText(70, 300, textk);
						drawText(100, 300, char3);

					}
				}

			}
		}
	
	
	}
 
}



int main() {

	initgraph();
	char string1[] = "Mo phong cach hoat dong cua ShellSort";
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
	
	Sleep(1000);
	ShellSortVisualize(A, n);
	Sleep(1000);
	system("cls");
	char string2[] = "-----Mo phong hoan tat-------";
	outtextxy(200, 100, string2);
	Sleep(2000);
	return 0;

}