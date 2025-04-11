#include <fstream>
#include <iostream>
#include <sstream>
#include "StdAfx.h"
#include "student.h"
#include <locale>
#include <string>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	bool ok;
	ifstream file(argv[1]);
	if (!file.is_open()) {
		cerr << "Cannot open file!" << endl;
		exit;
	}

	string data[MAX_ROWS][MAX_COLS];
	string line;
	int row = 0;
	int col = 0;
	while (getline(file, line) && row < MAX_ROWS) {
		stringstream ss(line);
		string cell;
		int col = 0;
		while (getline(ss, cell, ',') && col < MAX_COLS) {
			data[row][col] = cell;
			col++;
		}
		row++;
	}
	file.close();

	Student *stu = new Student[row];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < MAX_COLS && !data[i][j].empty();
			j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i < row; i++) {
		for (int j = 0; j < MAX_COLS && !data[i][j].empty();
			j++) {
			stu[i].last_name = data[i][0];
			stu[i].first_name = data[i][1];
			stu[i].fathers_name = data[i][2];
			stringstream tmp(data[i][3]);
			int age;
			tmp >> age;
			//int age = stoi(data[i][3]);
			stu[i].age = age;
			stu[i].gender = data[i][4];
		}
	}
	for (int i = 1; i < row; i++) {
		cout << i << ". ";
		stu[i].PrintInfo();
	}
	return 0;
}
