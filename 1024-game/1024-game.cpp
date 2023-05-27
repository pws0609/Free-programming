#include<iostream>					
#include<cstdlib>					
#include<ctime>					
#include<vector>					
using namespace std;					
					
const int level = 4;					
const int randnum = 2;					
int bignum();					
void gamestart();					
bool gameover();					
void print();					
void up();					
void left();					
void down();					
void right();					
void random();					
void copygraph();					
bool integrity();					
void moveup();					
void moveleft();					
void movedown();					
void moveright();					
int graph[level][level];					
int checker[level][level];					
//int graph[4][4] = { {2,0,0,6},{0,4,0,1},{0,0,0,3},{0,0,5,0} };					
					
int main(void) {					
	string input = " ";				
	gamestart();				
	for (int i = 0; i < level; i++) {				
		for (int j = 0; j < level; j++) {			
			graph[i][j] = 0;		
		}			
	}				
	random();				
	print();				
	while (bignum() < 1024 && input[0] != 'x') {				
		if (gameover()) {			
			cout << "GAME OVER!";		
			return 0;		
		}			
		cout << "input w, a, s, d.  x to quit: ";			
		cin >> input;			
					
		switch (input[0]) {			
		case 'w':			
		case 'W':			
			cout << "up" << endl;		
			up();		
			break;		
		case 'a':			
		case 'A':			
			cout << "left" << endl;		
			left();		
			break;		
		case 's':			
		case 'S':			
			cout << "down" << endl;		
			down();		
			break;		
		case 'd':			
		case 'D':			
			cout << "right" << endl;		
			right();		
			break;		
		case 'x':			
		case 'X':			
			cout << "Game end!";		
			break;		
		default:			
			printf("wrong input!\n");		
		}			
	}				
	return 0;				
}					
					
void gamestart() {					
	cout << "----------------------------------" << endl;				
	cout << "----        1024 GAME!        ----" << endl;				
	cout << "----                          ----" << endl;				
	cout << "----   Only first character   ----" << endl;				
	cout << "----  can be read by program  --" << endl;				
	cout << "----------------------------------" << endl;				
	cout << endl;				
}					
					
int bignum() {					
	int res = 0;				
	for (int i = 0; i < level; i++) {				
		for (int j = 0; j < level; j++) {			
			if (res < graph[i][j])		
				res = graph[i][j];	
		}			
	}				
	return res;				
}					
					
bool gameover() {					
	int cnt = 0;				
	for (int i = 0; i < level; i++) {				
		for (int j = 0; j < level; j++) {			
			if (graph[i][j] == 0)		
				cnt++;	
		}			
	}				
	if (cnt == 0)				
		return true;			
	else				
		return false;			
}					
					
void print() {					
	for (int i = 0; i < level; i++) {				
		for (int j = 0; j < level; j++) {			
			cout << '\t' << graph[i][j];		
		}			
		cout << endl;			
	}				
	cout << endl;				
}					
					
void up() {					
	copygraph();				
	moveup();				
					
	if (integrity()) {				
		/*	for (int i = 1; i < level; i++) {		
				for (int j = 0; j < level; j++) {	
					graph[i-1][j] += graph[i][j];
					graph[i][j] = 0;
				}	
			}*/		
		random();			
		print();			
	}				
	else {				
		cout << "No changes. Input another key." << endl;			
		print();			
	}				
}					
					
void left() {					
	copygraph();				
	moveleft();				
					
	if (integrity()) {				
		/*	for (int i = 0; i < level; i++) {		
				for (int j = 1; j < level; j++) {	
					graph[i][j - 1] += graph[i][j];
					graph[i][j] = 0;
				}	
			}*/		
		random();			
		print();			
	}				
	else {				
		cout << "No changes. Input another key." << endl;			
		print();			
	}				
}					
					
void down() {					
	copygraph();				
	movedown();				
					
	if (integrity()) {				
		/*	for (int i = level - 2; i >= 0; i--) {		
				for (int j = 0; j < level; j++) {	
					graph[i + 1][j] += graph[i][j];
					graph[i][j] = 0;
				}	
			}*/		
		random();			
		print();			
	}				
	else {				
		cout << "No changes. Input another key." << endl;			
		print();			
	}				
}					
					
void right() {					
	copygraph();				
	moveright();				
					
	if (integrity()) {				
		/*	for (int i = 0; i < level; i++) {		
				for (int j = level - 2; j >= 0; j--) {	
					graph[i][j + 1] += graph[i][j];
					graph[i][j] = 0;
				}	
			}*/		
		random();			
		print();			
	}				
	else {				
		cout << "No changes. Input another key." << endl;			
		print();			
	}				
}					
					
void random() {					
	vector<int> empty;				
	for (int i = 0; i < level; i++) {				
		for (int j = 0; j < level; j++) {			
			if (graph[i][j] == 0)		
				empty.push_back(i * 4 + j);	
		}			
	}				
	srand((unsigned int)time(NULL));				
	int num = empty[rand() % empty.size()];				
	cout << "rand pos: " << num + 1 << endl;				
	int row = num / 4;				
	int col = num % 4;				
	graph[row][col] = randnum;				
}					
					
void copygraph() {					
	for (int i = 0; i < level; i++) {				
		for (int j = 0; j < level; j++)			
			checker[i][j] = graph[i][j];		
	}				
}					
					
bool integrity() {					
	for (int i = 0; i < level; i++) {				
		for (int j = 0; j < level; j++) {			
			if (checker[i][j] != graph[i][j])		
				return true;	
		}			
	}				
	return false;				
}					
					
void moveup(){					
	for (int j = 0; j < level; j++) {				
		for (int k = 1; k < level; k++) {			
			for (int i = 1; i < level; i++) {		
				if (graph[i - 1][j] == 0) {	
					graph[i - 1][j] = graph[i][j];
					graph[i][j] = 0;
				}	
			}		
		}			
	}				
	return;				
}					
					
void moveleft(){					
	for (int i = 0; i < level; i++) {				
		for (int k = 1; k < level; k++) {			
			for (int j = 1; j < level; j++) {		
				if (graph[i][j - 1] == 0) {	
					graph[i][j - 1] = graph[i][j];
					graph[i][j] = 0;
				}	
			}		
		}			
	}				
	return;				
}					
					
void movedown(){					
	for (int j = 0; j < level; j++) {				
		for (int k = 0; k < level - 1; k++) {			
			for (int i = 0; i < level - 1; i++) {		
				if (graph[i + 1][j] == 0) {	
					graph[i + 1][j] = graph[i][j];
					graph[i][j] = 0;
				}	
			}		
		}			
	}				
	return;				
}					
					
void moveright(){					
	for (int i = 0; i < level; i++) {				
		for (int k = 1; k < level; k++) {			
			for (int j = 0; j < level - 1; j++) {		
				if (graph[i][j + 1] == 0) {	
					graph[i][j + 1] = graph[i][j];
					graph[i][j] = 0;
				}	
			}		
		}			
	}				
	return;				
}					

