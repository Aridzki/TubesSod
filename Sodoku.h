#ifndef SODOKU_H
#define SODOKU_H

#include <iostream>

using namespace std;

class Sodoku {
	int m_sodoku[9][9];

public:
	Sodoku();
	Sodoku(string file);

	void inputManual();
	bool findZero(int &row, int &col);
	bool cekAll(int row, int col, int prob);
	bool solveSodoku();
	bool cekRow(int row, int prob);
	bool cekCol(int col, int prob);
	bool cekBox(int startRow, int startCol, int prob);
	bool cekHyper(int startRow, int startCol, int prob);
	void printSodoku();
	void foutSodoku(string file);
};

#endif