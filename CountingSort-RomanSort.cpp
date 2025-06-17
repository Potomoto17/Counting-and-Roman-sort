#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

bool Branje_Stevil(vector<int>& vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
	ofstream output("out.txt");

	for (int i = 0; i < velikost; i++)
		output << polje[i] << ' ';
}

int findMin(vector<int> A)
{
	int min = A[0];

	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] < min)
			min = A[i];
	}

	return min;
}

int findMax(vector<int> A)
{
	int max = A[0];

	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] > max)
			max = A[i];
	}

	return max;
}

void negativeNumberSupport1(vector<int> A, int min)
{
	for (int i = 0; i < A.size(); i++)
		A[i] = A[i] - min;
}

void settingValuesInC(vector<int> A, vector<int> C)
{
	for (int i = 0; i < A.size(); i++)
		C[A[i]] = C[A[i]] + 1;
}

void addValuesOfC(vector<int> C)
{
	for (int i = 1; i < C.size(); i++)
	{
		C[i] = C[i] + C[i - 1];
	}
}

void fillBCounting(vector<int> A, vector<int> B, vector<int> C)
{
	for (int i = A.size(); i >= 0; i++)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
}

void negativeNumberSupport2(vector<int> B, int min)
{
	for (int i = 0; i < B.size(); i++)
		B[i] = B[i] + min;
}

void fillBRoman(vector<int> B, vector<int> C)
{
	int counterB = 0;
	for (int i = 0; i < C.size(); i++)
	{
		if (C[i] != 0)
		{
			for (int j = 0; j < C[i]; j++)
			{
				B[counterB] = C[i];
				counterB++;
			}
		}
	}
}

int main(int argc, const char* argv[]) {
	vector<int> A;

	if (argc < 3) return 0;
	if (!Branje_Stevil(A, argv[2])) return 0;

	if (argv[1][0] == '0') 
	{
		//Counting sort

		int min = findMin(A);
		int max = findMax(A);
		negativeNumberSupport1(A, min);
		vector<int> C(max, 0);
		settingValuesInC(A, C);
		addValuesOfC(C);
		vector<int> B(A.size());
		fillBCounting(A, B, C);
		negativeNumberSupport2(B, min);
	}

	else 
	{
		//Roman sort

		int min = findMin(A);
		int max = findMax(A);
		negativeNumberSupport1(A, min);
		vector<int> C(max, 0);
		settingValuesInC(A, C);
		vector<int> B(A.size());
		fillBRoman(B, C);
		negativeNumberSupport2(B, min);
	}

	Izpis_Stevil(&A[0], A.size());

	return 0;
}
