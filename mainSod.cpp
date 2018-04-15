#include <iostream>
#include <fstream>
#include "Sodoku.h"

using namespace std;

void inputfile() {								// Fungsi untuk input file

	string filein;
	string fileout;

	cout << "Masukan nama file: ";
	cin >> filein;

	cout << endl;

	Sodoku sodoku(filein);

	sodoku.printSodoku();
	cout << endl;

	if (sodoku.solveSodoku())
	{
		cout << "Masukan nama file output: ";
		cin >> fileout;

		sodoku.foutSodoku(fileout);
	}
	else cout <<"Tidak ada solusi" << endl;

}

void inputmanual() {								//Fungsi untuk input manual
	cout << "Masukan sodoku dengan mengisi 0 pada cell yang kosong" << endl;

	Sodoku sodoku;	
	sodoku.inputManual();

	cout << endl;

	if(sodoku.solveSodoku() == true)
	{
		cout << "Solusinya adalah " << endl;
		sodoku.printSodoku();
	}
	else cout << "tidak ada solusi" << endl;
}

int main() {
	int x;

	cout << "Apakah anda mau input file atau manual" << endl;
	cout << "1 = input file     2 = input manual" << endl;

	cin >>x;

	if (x==1) inputfile();
	else if (x==2) inputmanual();
	else cout <<"error";						//Jika tidak sesui error

	return 0;
}