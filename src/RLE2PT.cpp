#include<iostream>
#include<fstream> 
using namespace std;

string solve(string s) {                   //Huge thanks to https://helloacm.com/c-run-length-decoding-algorithm/ for this decompressing function
    int i = 0;
    string ans = "";
    while (i < s.size()) {
        int j = i;
        while (isdigit(s[j]) && (j < s.size())) {
            j ++;
        }
        int a = stoi(s.substr(i, j - i + 1));
        int k = j;
        while (isalpha(s[k]) && k < s.size()) {
            k ++;
        }
        auto t = s.substr(j, k - j);
        for (int k = 0; k < a; ++ k) {
            ans += t;
        }
        i = k;
    }    
    return ans;
}


int main(){
	ifstream INPUT;
	ofstream OUTPUT;
	INPUT.open("input(RLE).txt",ios::in);
	OUTPUT.open("input(Plaintext).txt",ios::out | ios::trunc);
	int x,y;
	string buffer;
	getline(INPUT, buffer);
	sscanf(buffer.c_str(),"x = %d, y = %d, rule = B3/S23",&x,&y); //Extract size info
	char map[y][x];
	for(int i = 0;i<y;i++){
		for(int j = 0;j<x;j++){
			map[i][j] = '.';
		}
	}
	//---------------decompression(start)------------------------------
	string data;
	int pos;
	while(!INPUT.eof()){
		getline(INPUT,buffer);
		data += buffer;
	}
	//cout<<data<<"\n\n";
	//------------Add 1s to the stream & turn $ into S and turn ! to l for the decompression function
	for(int i = 0;i<data.length();i++){
		if(data[i] == '$'){
			data[i] = 'S';
		}
		else if(data[i] == '!'){
			data[i] = 'l';
		}
	}
	for(int i = 0;i<data.length();i++){
		if(!isdigit(data[i]) && !isdigit(data[i+1])){
			data.insert(i+1,"1");
		}
	}
	if(!isdigit(data[0]))
	data.insert(0,"1");
	data.erase(data.length()-1,1);//erase the extra 1
	//cout<<data<<"\n\n";
	//-----------Decompression--------------
	string expanded_data = solve(data);
//	cout<<expanded_data<<"\n\n";
	//------------Drawing it out on a blank map---------------
	int xcor = 0,ycor = 0;
	for(int i = 0;i<expanded_data.length();i++){
		if(expanded_data[i] == 'S'){
			xcor = 0;
			ycor++;
		}
		else if(expanded_data[i] == 'b'){
			xcor++;
		} 
		else if(expanded_data[i] == 'o'){
			map[ycor][xcor] = 'O';
			xcor++;
		}
	}
	//--------------------------------------------------------
/*	for(int i = 0;i<y;i++){
		for(int j = 0;j<x;j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}*/


	OUTPUT<<x<<' '<<y<<'\n';
	buffer.clear();
	buffer.resize(x);
	for(int i = 0;i<y;i++){
		buffer.clear();
	for(int j = 0;j<x;j++){
		buffer+=map[i][j];
	}
	buffer+='\n';
	OUTPUT<<buffer;
	}
	cout<<"Conversion complete. Enter anything to close the program\n";
	cin.clear();
	cin.sync();
	cin.get();
	INPUT.close();
	OUTPUT.close();
return 0;
}
