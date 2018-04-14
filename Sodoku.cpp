#include "Sodoku.h"
#include <iostream>
#include <fstream>

using namespace std;

Sodoku::Sodoku() {						//Default constructor membuat semua isinya jadi 0
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			m_sodoku[i][j] = 0;
		}
	}
}

Sodoku::Sodoku(string file) {				//Constructor dengan parameter file input
	char x;									//Secara otomatis mengubah file eksternal 
	ifstream fin;							//menjadi array

	fin.open(file);

	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			fin >> x;

			if(x=='x') m_sodoku[i][j] = 0;
			else if(x=='1') m_sodoku[i][j] = 1;
			else if(x=='2') m_sodoku[i][j] = 2;
			else if(x=='3') m_sodoku[i][j] = 3;
			else if(x=='4') m_sodoku[i][j] = 4;
			else if(x=='5') m_sodoku[i][j] = 5;
			else if(x=='6') m_sodoku[i][j] = 6;
			else if(x=='7') m_sodoku[i][j] = 7;
			else if(x=='8') m_sodoku[i][j] = 8;
			else if(x=='9') m_sodoku[i][j] = 9;
		}
	}

	fin.close();
} 

bool Sodoku::solveSodoku() {						//Ini merupang komponen paling penting
	int row;										//Fungsi ini merupakan looping sekaligus backtrackin
	int col;

	if(!findZero(row, col)) return true;			//Looping terjadi di sini

	for (int prob=1 ; prob <=9 ; prob++)			//prob merupakan kemungkinan angka
	{
		if(cekAll(row, col, prob))
		{
			m_sodoku[row][col] = prob;				//Mengisi kemungkinan angka untuk sementara

			if(solveSodoku()) return true;

			m_sodoku[row][col] = 0;					//Jika salah kembali jadi 0 dan mencoba
		}											//kmungkinan angka berikutnya
	}

	return false;									//Backtracking terjadi di sini
}

void Sodoku::inputManual() {		
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cin >> m_sodoku[i][j];
		}
	}
}

bool Sodoku::findZero(int &row, int &col) {				//Alasan mengapa bisa terjadi loopng di sini
	for(row=0; row<9; row++ )							// adalah parameternya reference
	{
		for (col=0; col<9 ; col++)
		{
			if(m_sodoku[row][col] == 0) return true;
		}
	}
	return false;
}

bool Sodoku::cekRow(int row, int prob) {				//Kolomnya konstan
	for(int col = 0; col<9; col++)
	{
		if(m_sodoku[row][col] == prob) return true;
	}
	return false;
}

bool Sodoku::cekCol(int col, int prob) {				//Barisnya konstan
	for(int row=0; row<9; row++)
	{
		if(m_sodoku[row][col] == prob) return true;
	}
	return false;
}

bool Sodoku::cekBox(int startRow, int startCol, int prob) {						//Karena box merupakan 3xg
	for(int row = 0; row<3; row++)												//Didapatkan pola seperti ini
	{
		for(int col=0; col<3; col++)
		{
			if(m_sodoku[row+startRow][col+startCol] == prob) return true;
		}
	}
	return false;
}

bool Sodoku::cekAll(int row, int col, int prob) {						//Dibagi menjadi 2 kasus karena ada hyperbox
	if(row%4==0 || col%4==0) {										//Jika Cell tidak masuk hyperbox			
		return !cekRow(row, prob) &&
				!cekCol(col, prob) &&
				!cekBox(row - row%3, col - col%3, prob);
	}
	else {															//Jika cell masuk hyperbox
		return !cekRow(row, prob) &&
				!cekCol(col, prob) &&
				!cekBox(row - row%3, col - col%3, prob) &&
				!cekBox(row - row%4 + 1, col - col%4 + 1, prob);
	}
}

void Sodoku::printSodoku() {
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cout << m_sodoku[i][j]<< " ";
		}
		cout << endl;
	}
}

void Sodoku::foutSodoku(string file) {				//Output ke file eksternal
	ofstream fout;

	fout.open(file);;

	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			fout << m_sodoku[i][j];
		}
		fout << endl;
	}
}



