#include<iostream>
#include<cctype>
#include<vector>
#include<fstream> 
using namespace std;
int main(){
	ifstream INPUT;
	ofstream OUTPUT;
	INPUT.open("input(RLE).txt",ios::in);
	OUTPUT.open("input(Plaintext).txt",ios::out | ios::trunc);
	int x,y;
	string buffer;
	getline(INPUT, buffer);
	sscanf(buffer.c_str(),"x = %d, y = %d, rule = B3/S23",&x,&y); //Extract size info
	vector<vector<char>> map( y , vector<char> (x));
	for(int i = 0;i<y;i++){
		for(int j = 0;j<x;j++){
			map[i][j] = '.';
		}
	}
	//---------------decompression(start)------------------------------
int xpos = 0,ypos = 0;
	int N,temp;
	char C;
	while(!INPUT.eof()){
		getline(INPUT, buffer);
		for(int i = 0;i<buffer.length();i++){
			N = 0; C = ' ';
			temp = buffer[i];
			if(temp == '!')
			break;
			else if(isdigit(temp) == true){
				while(isdigit(temp) == true){
					N = N*10+(int(temp)-48);  //add digits up
					i++;
					temp = buffer[i]; 
				}
				C = temp;
			}
			else if(isdigit(temp) == false){
				N = 1;
				C = temp;
			}
			//N and C complete
			//-------------------------------Draw to map start
			//cout<<N<<' '<<C<<endl;
			if(C == '$'){
				ypos+=N;
				xpos = 0;
			}
			else if(C == 'b'){
				xpos+=N;
			}
			else if(C == 'o'){
				for(int k = 0;k<N;k++){
					map[ypos][xpos+k] = 'O';
				}
				xpos+=N;
			}
			//-------------------------------Draw to map end
		}
	}
	OUTPUT<<x<<' '<<y<<'\n';
	for(int i = 0;i<y;i++){
		for(int j = 0;j<x;j++){
			OUTPUT<<map[i][j];
		}
		OUTPUT<<"\n";
	}
	cout<<"Conversion complete. Enter anything to close the program\n";
	cin.clear();
	cin.sync();
	cin.get();
	INPUT.close();
	OUTPUT.close();
return 0;
}
