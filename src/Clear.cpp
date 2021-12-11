#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream INPUT1;
	ofstream INPUT2;
	ofstream OUTPUT;
	ofstream STATS;
	INPUT1.open("input(RLE).txt",ios::out | ios::trunc);
	INPUT2.open("input(Plaintext).txt",ios::out | ios::trunc);
	OUTPUT.open("output.txt",ios::out | ios::trunc);
	STATS.open("Statistics.txt",ios::out | ios::trunc);
	cout<<"Clear complete. Enter anything to close the program\n";
	cin.clear();
	cin.sync();
	cin.get();
	INPUT1.close();
	INPUT2.close();
	OUTPUT.close();
	STATS.close();
return 0;
}

