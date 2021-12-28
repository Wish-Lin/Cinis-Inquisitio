#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
using namespace std;
int main(){
	ifstream INPUT;
	ofstream OUTPUT;
	ofstream STATS;
	int x = 0,y = 0;
	string buffer;
	int initial_population = 0,end_population = 0;
	int blockcount = 0,vert_blinkercount = 0,horiz_blinkercount = 0,vert_beehivecount = 0,horiz_beehivecount = 0,tubcount = 0,lu_boatcount = 0,ru_boatcount = 0,ld_boatcount = 0,rd_boatcount = 0,lurd_shipcount = 0,ruld_shipcount = 0,lu_loafcount = 0,ru_loafcount = 0,ld_loafcount = 0,rd_loafcount = 0,pond_count = 0;
//---------------Read from file(start)--------------------
	INPUT.open("input(Plaintext).txt",ios::in);
	OUTPUT.open("output.txt",ios::out | ios::trunc);
	STATS.open("Statistics.txt",ios::out | ios::trunc);
	getline (INPUT, buffer);
	sscanf(buffer.c_str(),"%d %d",&x,&y);
	vector<vector<char>> map( y , vector<char> (x));
	for(int i = 0;i<y;i++){
		getline(INPUT, buffer);
		for(int j = 0;j<x;j++){
			map[i][j] = buffer[j];
			if(map[i][j] == 'O'){
				initial_population++;   //count initial population while reading the file
			}
		}
	}
	double initial_density = float(initial_population)/(float(x)*float(y));
	end_population = initial_population;
//--------------Read from file(end)--------------	
	cout<<"x = "<<x<<" ; y = "<<y<<" ; population = "<<initial_population<<'\n';
	cout<<"Enter anything to start analyzing:\n";
	cin.clear();
	cin.sync();
	cin.get();
	cout<<'\n';
	for(int i = 0;i<y;i++){
	for(int j = 0;j<x;j++){
//-------------------Searching function(start)--------------------------
			
//from here on more cells are considered in the identification 
//
// . X 3
// 4 1 2
// 5 6 7
//	
		if(map[i][j] == 'O'){
			//block start (123)
			if(map[i+1][j] == 'O' && map[i+1][j+1] == 'O' && map[i][j+1] == 'O' && map[i+1][j-1] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+1] == '.'){
				if(map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-1] == '.' && map[i][j+2] == '.' && map[i+1][j-1] == '.' && map[i+1][j+2] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+1] == '.' && map[i+2][j+2] == '.'){
					cout<<"Block found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j+1] = '.';
					blockcount++;
					end_population -= 4;
				}
			} //block end
			
			//blinker vertical start (16)
			if(map[i+1][j] == 'O' && map[i+1][j+1] == '.' && map[i][j+1] == '.' && map[i+1][j-1] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == 'O' && map[i+2][j+1] == '.'){
				if(map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i][j-1] == '.' && map[i][j+1] == '.' && map[i+1][j-1] == '.' && map[i+1][j+1] == '.' && map[i+2][j-1] == '.' && map[i+2][j+1] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.'){
					cout<<"Vertical Blinker found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j] = '.';
					map[i+2][j] = '.';
					vert_blinkercount++;
					end_population -= 3;
				}
			} //blinker vertical end
			
			//blinker horizontal start (3)
			if(map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i][j+1] == 'O' && map[i+1][j-1] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+1] == '.'){
				if(map[i-1][j-1] == '.' && map[i][j-1] == '.' && map[i+1][j-1] == '.' && map[i-1][j] == '.' && map[i+1][j] == '.' && map[i-1][j+1] == '.' && map[i+1][j+1] == '.' && map[i-1][j+2] == '.' && map[i+1][j+2] == '.' && map[i-1][j+3] == '.' && map[i][j+3] == '.' && map[i+1][j+3] == '.'){
					cout<<"Horizontal Blinker found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i][j+2] = '.';
					horiz_blinkercount++;
					end_population -= 3;
				}
			} //blinker horizontal end
			
			//beehive vertical start (2457)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == '.' && map[i+1][j-1] == 'O' && map[i+2][j-1] == 'O' && map[i+2][j] == '.' && map[i+2][j+1] == 'O'){
				if(map[i+3][j] =='O' && map[i][j-1] =='.' && map[i][j+1] =='.' && map[i+3][j-1] =='.' && map[i+3][j+1] =='.' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-2] == '.' && map[i][j+2] == '.' && map[i+1][j-2] == '.' && map[i+1][j+2] == '.' && map[i+2][j-2] == '.' && map[i+2][j+2] == '.' && map[i+3][j-2] == '.' && map[i+3][j+2] == '.' && map[i+4][j-2] == '.' && map[i+4][j-1] == '.' && map[i+4][j] == '.' && map[i+4][j+1] == '.' && map[i+4][j+2] == '.'){ //probably unnecessary [i+3][j]'O' identification at front
					cout<<"Vertical Beehive found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j-1] = '.';
					map[i+2][j+1] = '.';
					map[i+3][j] = '.';
					vert_beehivecount++;
					end_population -= 6;
				}
			} //beehive vertical end
			
			//beehive horizontal start (3467)
			if(map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i][j+1] == 'O' && map[i+1][j-1] == 'O' && map[i+2][j-1] == '.' && map[i+2][j] == 'O' && map[i+2][j+1] == 'O'){
				if(map[i+1][j+2] =='O' && map[i][j-1] == '.' && map[i][j+2] == '.' && map[i+2][j-1] == '.' && map[i+2][j+2] == '.' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i-1][j+3] == '.' && map[i][j-2] == '.' && map[i][j+3] == '.' && map[i+1][j-2] == '.' && map[i+1][j+3] == '.' && map[i+2][j-2] == '.' && map[i+2][j+3] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.' && map[i+3][j+3] == '.'){ //probably unnecessary [i+1][j+2]'O' identification at front
					cout<<"Horizontal Beehive found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+2] = '.';
					map[i+2][j] = '.';
					map[i+2][j+1] = '.';
					horiz_beehivecount++;
					end_population -= 6;
				}
			} //beehive horizontal end
			
			//tub start (246)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == '.' && map[i+1][j-1] == 'O' && map[i+2][j-1] == '.' && map[i+2][j] == 'O' && map[i+2][j+1] == '.'){
				if(map[i][j-1] == '.' && map[i][j+1] == '.' && map[i+2][j-1] == '.' && map[i+2][j+1] == '.' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-2] == '.' && map[i][j+2] == '.' && map[i+1][j-2] == '.' && map[i+1][j+2] == '.' && map[i+2][j-2] == '.' && map[i+2][j+2] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.'){
					cout<<"Tub found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j] = '.';
					tubcount++;
					end_population -= 4;
				}
			} //tub end
			
			//boat lu start (137)
			if(map[i+1][j] == 'O' && map[i+1][j+1] == '.' && map[i][j+1] == 'O' && map[i+1][j-1] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+1] == 'O'){
				if(map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i-1][j+3] == '.' && map[i][j-1] == '.' && map[i][j+2] == '.' && map[i][j+3] == '.' && map[i+1][j-1] == '.' && map[i+1][j+1] == '.' && map[i+1][j+2] == 'O' && map[i+1][j+3] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+2] == '.' && map[i+2][j+3] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.' && map[i+3][j+3] == '.'){
					cout<<"LU Boat found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j] = '.';
					map[i+1][j+2] = '.';
					map[i+2][j+1] = '.';
					lu_boatcount++;
					end_population -= 5;
				}
			} //boat lu end
			
			//boat ru start (2346)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == 'O' && map[i+1][j-1] == 'O' && map[i+2][j-1] == '.' && map[i+2][j] == 'O' && map[i+2][j+1] == '.'){
				if(map[i][j-1] == '.' && map[i][j+1] == 'O' && map[i+2][j-1] == '.' && map[i+2][j+1] == '.' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-2] == '.' && map[i][j+2] == '.' && map[i+1][j-2] == '.' && map[i+1][j+2] == '.' && map[i+2][j-2] == '.' && map[i+2][j+2] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.'){
					cout<<"RU Boat found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j] = '.';
					ru_boatcount++;
					end_population -= 5;
				}
			} //boat ru end
			
			//boat ld start (2456)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == '.' && map[i+1][j-1] == 'O' && map[i+2][j-1] == 'O' && map[i+2][j] == 'O' && map[i+2][j+1] == '.'){
				if(map[i][j-1] == '.' && map[i][j+1] == '.' && map[i+2][j-1] == 'O' && map[i+2][j+1] == '.' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-2] == '.' && map[i][j+2] == '.' && map[i+1][j-2] == '.' && map[i+1][j+2] == '.' && map[i+2][j-2] == '.' && map[i+2][j+2] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.'){
					cout<<"LD Boat found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j-1] = '.';
					map[i+2][j] = '.';
					ld_boatcount++;
					end_population -= 5;
				}
			} //boat ld end
			
			//boat rd start (2467)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == '.' && map[i+1][j-1] == 'O' && map[i+2][j-1] == '.' && map[i+2][j] == 'O' && map[i+2][j+1] == 'O'){
				if(map[i][j-1] == '.' && map[i][j+1] == '.' && map[i+2][j-1] == '.' && map[i+2][j+1] == 'O' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-2] == '.' && map[i][j+2] == '.' && map[i+1][j-2] == '.' && map[i+1][j+2] == '.' && map[i+2][j-2] == '.' && map[i+2][j+2] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.'){
					cout<<"RD Boat found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j] = '.';
					map[i+2][j+1] = '.';
					rd_boatcount++;
					end_population -= 5;
				}
			} //boat rd end
			
			//ship lurd start (137)
			if(map[i+1][j] == 'O' && map[i+1][j+1] == '.' && map[i][j+1] == 'O' && map[i+1][j-1] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+1] == 'O'){
				if(map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i-1][j+3] == '.' && map[i][j-1] == '.' && map[i][j+2] == '.' && map[i][j+3] == '.' && map[i+1][j-1] == '.' && map[i+1][j+1] == '.' && map[i+1][j+2] == 'O' && map[i+1][j+3] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+2] == 'O' && map[i+2][j+3] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.' && map[i+3][j+3] == '.'){
					cout<<"LURD Ship found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j] = '.';
					map[i+1][j+2] = '.';
					map[i+2][j+1] = '.';
					map[i+2][j+2] = '.';
					lurd_shipcount++;
					end_population -= 6;
				}
			} //ship lurd end
			
			//ship ruld start (23456)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == 'O' && map[i+1][j-1] == 'O' && map[i+2][j-1] == 'O' && map[i+2][j] == 'O' && map[i+2][j+1] == '.'){
				if(map[i][j-1] == '.' && map[i][j+1] == 'O' && map[i+2][j-1] == 'O' && map[i+2][j+1] == '.' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-2] == '.' && map[i][j+2] == '.' && map[i+1][j-2] == '.' && map[i+1][j+2] == '.' && map[i+2][j-2] == '.' && map[i+2][j+2] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.'){
					cout<<"RULD Ship found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j-1] = '.';
					map[i+2][j] = '.';
					ruld_shipcount++;
					end_population -= 6;
				}
			} //ship ruld end
			
			//loaf lu start (3457)
			if(map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i][j+1] == 'O' && map[i+1][j-1] == 'O' && map[i+2][j-1] == 'O' && map[i+2][j] == '.' && map[i+2][j+1] == 'O'){
				if(map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i-1][j+3] == '.' && map[i][j-2] == '.' && map[i][j-1] == '.' && map[i][j] == 'O' && map[i][j+1] == 'O' && map[i][j+2] == '.' && map[i][j+3] == '.' && map[i+1][j-2] == '.' && map[i+1][j-1] == 'O' && map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i+1][j+2] == 'O' && map[i+1][j+3] == '.' && map[i+2][j-2] == '.' && map[i+2][j-1] == 'O' && map[i+2][j] == '.' && map[i+2][j+1] == 'O' && map[i+2][j+2] == '.' && map[i+2][j+3] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == 'O' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.' && map[i+3][j+3] == '.' && map[i+4][j-2] == '.' && map[i+4][j-1] == '.' && map[i+4][j] == '.' && map[i+4][j+1] == '.' && map[i+4][j+2] == '.'){
					cout<<"LU Loaf found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+2] = '.';
					map[i+2][j-1] = '.';
					map[i+2][j+1] = '.';
					map[i+3][j] = '.';
					lu_loafcount++;
					end_population -= 7;
				}
			} //loaf lu end
			
			//loaf ru start (346)
			if(map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i][j+1] == 'O' && map[i+1][j-1] == 'O' && map[i+2][j-1] == '.' && map[i+2][j] == 'O' && map[i+2][j+1] == '.'){
				if(map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i-1][j+3] == '.' && map[i][j-2] == '.' && map[i][j-1] == '.' && map[i][j] == 'O' && map[i][j+1] == 'O' && map[i][j+2] == '.' && map[i][j+3] == '.' && map[i+1][j-2] == '.' && map[i+1][j-1] == 'O' && map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i+1][j+2] == 'O' && map[i+1][j+3] == '.' && map[i+2][j-2] == '.' && map[i+2][j-1] == '.' && map[i+2][j] == 'O' && map[i+2][j+1] == '.' && map[i+2][j+2] == 'O' && map[i+2][j+3] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == '.' && map[i+3][j+1] == 'O' && map[i+3][j+2] == '.' && map[i+3][j+3] == '.' && map[i+4][j-1] == '.' && map[i+4][j] == '.' && map[i+4][j+1] == '.' && map[i+4][j+2] == '.' && map[i+4][j+3] == '.'){
					cout<<"RU Loaf found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+2] = '.';
					map[i+2][j] = '.';
					map[i+2][j+2] = '.';
					map[i+3][j+1] = '.';
					ru_loafcount++;
					end_population -= 7;
				}
			} //loaf ru end
			
			//loaf ld start (245)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == '.' && map[i+1][j-1] == 'O' && map[i+2][j-1] == 'O' && map[i+2][j] == '.' && map[i+2][j+1] == '.'){
				if(map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-2] == '.' && map[i][j-1] == '.' && map[i][j] == 'O' && map[i][j+1] == '.' && map[i][j+2] == '.' && map[i][j+3] == '.' && map[i+1][j-2] == '.' && map[i+1][j-1] == 'O' && map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i+1][j+2] == '.' && map[i+1][j+3] == '.' && map[i+2][j-2] == '.' && map[i+2][j-1] == 'O' && map[i+2][j] == '.' && map[i+2][j+1] == '.' && map[i+2][j+2] == 'O' && map[i+2][j+3] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == 'O' && map[i+3][j+1] == 'O' && map[i+3][j+2] == '.' && map[i+3][j+3] == '.' && map[i+4][j-2] == '.' && map[i+4][j-1] == '.' && map[i+4][j] == '.' && map[i+4][j+1] == '.' && map[i+4][j+2] == '.' && map[i+4][j+3] == '.'){
					cout<<"LD Loaf found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j-1] = '.';
					map[i+2][j+2] = '.';
					map[i+3][j] = '.';
					map[i+3][j+1] = '.';
					ld_loafcount++;
					end_population -= 7;
				}
			} //loaf ld end
			
			//loaf rd start (247)
			if(map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i][j+1] == '.' && map[i+1][j-1] == 'O' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+1] == 'O'){
				if(map[i-1][j-3] == '.' && map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i][j-3] == '.' && map[i][j-2] == '.' && map[i][j-1] == '.' && map[i][j] == 'O' && map[i][j+1] == '.' && map[i][j+2] == '.' && map[i+1][j-3] == '.' && map[i+1][j-2] == '.' && map[i+1][j-1] == 'O' && map[i+1][j] == '.' && map[i+1][j+1] == 'O' && map[i+1][j+2] == '.' && map[i+2][j-3] == '.' && map[i+2][j-2] == 'O' && map[i+2][j-1] == '.' && map[i+2][j] == '.' && map[i+2][j+1] == 'O' && map[i+2][j+2] == '.' && map[i+3][j-3] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == 'O' && map[i+3][j] == 'O' && map[i+3][j+1] == '.' && map[i+3][j+2] == '.' && map[i+4][j-3] == '.' && map[i+4][j-2] == '.' && map[i+4][j-1] == '.' && map[i+4][j] == '.' && map[i+4][j+1] == '.' && map[i+4][j+2] == '.'){
					cout<<"RD Loaf found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+1] = '.';
					map[i+2][j-2] = '.';
					map[i+2][j+1] = '.';
					map[i+3][j-1] = '.';
					map[i+3][j] = '.';
					rd_loafcount++;
					end_population -= 7;
				}
			} //loaf rd end
			
			//pond start (345)
			if(map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i][j+1] == 'O' && map[i+1][j-1] == 'O' && map[i+2][j-1] == 'O' && map[i+2][j] == '.' && map[i+2][j+1] == '.'){
				if(map[i-1][j-2] == '.' && map[i-1][j-1] == '.' && map[i-1][j] == '.' && map[i-1][j+1] == '.' && map[i-1][j+2] == '.' && map[i-1][j+3] == '.' && map[i][j-2] == '.' && map[i][j-1] == '.' && map[i][j] == 'O' && map[i][j+1] == 'O' && map[i][j+2] == '.' && map[i][j+3] == '.' && map[i+1][j-2] == '.' && map[i+1][j-1] == 'O' && map[i+1][j] == '.' && map[i+1][j+1] == '.' && map[i+1][j+2] == 'O' && map[i+1][j+3] == '.' && map[i+2][j-2] == '.' && map[i+2][j-1] == 'O' && map[i+2][j] == '.' && map[i+2][j+1] == '.' && map[i+2][j+2] == 'O' && map[i+2][j+3] == '.' && map[i+3][j-2] == '.' && map[i+3][j-1] == '.' && map[i+3][j] == 'O' && map[i+3][j+1] == 'O' && map[i+3][j+2] == '.' && map[i+3][j+3] == '.' && map[i+4][j-2] == '.' && map[i+4][j-1] == '.' && map[i+4][j] == '.' && map[i+4][j+1] == '.' && map[i+4][j+2] == '.'&& map[i+4][j+3] == '.'){
					cout<<"Pond found at ("<<j<<","<<i<<")\n";
					map[i][j] = '.';
					map[i][j+1] = '.';
					map[i+1][j-1] = '.';
					map[i+1][j+2] = '.';
					map[i+2][j-1] = '.';
					map[i+2][j+2] = '.';
					map[i+3][j] = '.';
					map[i+3][j+1] = '.';
					pond_count++;
					end_population -= 8;
				}
			} //pond end
		}
//---------------------Searching function(end)---------------------------

	}
}
	




















//---------Write output into file(start)----------
//	OUTPUT<<x<<' '<<y<<'\n';
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
//---------Write output into file(end)----------
//---------Write statistics into file(start)----------
	double end_density = float(end_population)/(float(x)*float(y));
	double remaining_percent = (float(end_population)/float(initial_population))*100;
	STATS<<"Bounding box:  "<<x<<"x"<<y<<'\n';
	STATS<<"Initial Population:  "<<initial_population<<'\n';
	STATS<<"Initial Density:  "<<initial_density*100<<"%\n";
	STATS<<"End Population:  "<<end_population<<'\n';
	STATS<<"End Density:  "<<end_density*100<<"%\n\n";
	
	STATS<<100-remaining_percent<<"% Initial ash deleted\n";
	STATS<<remaining_percent<<"% Initial ash remaining\n\n";
	
	STATS<<"Block count:  "<<blockcount<<'\n';
	STATS<<"Vertical Blinker count:  "<<vert_blinkercount<<'\n';
	STATS<<"Horizontal Blinker count:  "<<horiz_blinkercount<<'\n';
	STATS<<"Vertical Beehive count:  "<<vert_beehivecount<<'\n';
	STATS<<"Horizontal Beehive count:  "<<horiz_beehivecount<<'\n';
	STATS<<"LU Loaf count:  "<<lu_loafcount<<'\n';
	STATS<<"RU Loaf count:  "<<ru_loafcount<<'\n';
	STATS<<"LD Loaf count:  "<<ld_loafcount<<'\n';
	STATS<<"RD Loaf count:  "<<rd_loafcount<<'\n';
	STATS<<"LU Boat count:  "<<lu_boatcount<<'\n';
	STATS<<"RU Boat count:  "<<ru_boatcount<<'\n';
	STATS<<"LD Boat count:  "<<ld_boatcount<<'\n';
	STATS<<"RD Boat count:  "<<rd_boatcount<<'\n';
	STATS<<"Tub count:  "<<tubcount<<'\n';
	STATS<<"Pond count:  "<<pond_count<<'\n';
	STATS<<"LURD Ship count:  "<<lurd_shipcount<<'\n';
	STATS<<"RULD Ship count:  "<<ruld_shipcount<<'\n';

//---------Write statistics into file(end)----------
INPUT.close();
OUTPUT.close();
STATS.close();
cout<<"Analysis complete. Enter anything to close the program\n";
cin.clear();
cin.sync();
cin.get();
return 0;
}
