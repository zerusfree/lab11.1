#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateBIN(char* fname)
{
	ofstream fout(fname, ios::binary);
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "enter line: "; getline(cin, s);
		for (unsigned i = 0; i < s.length(); i++)
			fout.write((char*)&s[i], sizeof(s[i]));
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintBIN(char* fname)
{
	ifstream fin(fname, ios::binary);
	char c;
	while (fin.read((char*)&c, sizeof(c)))
	{
		cout << c << endl;
	}
	cout << endl;
}

void ProcessBIN1(char* fname, char* gname)
{
	ifstream f(fname, ios::binary);
	ofstream g(gname, ios::binary);

	char c;

	while (f.read((char*)&c, sizeof(c)))
	{
		

		if (f.peek() == '0'|| f.peek() == '1' || f.peek() == '2' || f.peek() == '3' || f.peek() == '4'
			|| f.peek() == '5' || f.peek() == '6' || f.peek() == '7' || f.peek() == '8' || f.peek() == '9')
		{
			g.write((char*) & c, sizeof(c));

		}

	}
}


int main()
{
	char fname[100];

	cout << "Enter file name 1: "; cin >> fname;
	CreateBIN(fname);
	PrintBIN(fname);

	char gname[100];

	cout << "Enter file name 2: "; cin >> gname;
	ProcessBIN1(fname, gname);
	PrintBIN(gname);
	return 0;
}

