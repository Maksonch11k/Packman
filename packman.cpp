#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <locale.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#define RED "\033[31m"
#define WHITE "\033[0m"
using namespace std;


char mape[23][32];
struct hhh {
	int hod;
	int x;
	int y;
	int back;
};

struct iuda {
	int x;
	int y;
};

vector<iuda> he;

vector<hhh> mmas;
char map[23][32] = {
	"№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№",
	"|                             |",
	"|№№ №№№№№№№№№№№ №№   №№№№№№№№№|",
	"|   №                         |",
	"| № №№№№№№  №           №     |",
	"| №        №№  №№№  №   №  №  |",
	"| № №№№  №№№№  №    №№№№ № №  |",
	"| №           №№№№  №      №  |",
	"| №№№№№№ №№№         №№       |",
	"| №№№      №№№№№№  №№№№№№№ №№№|",
	"|           №№№№№             |",
	"|№ №   №№№№   №   №№№   №№ №№№|",
	"|№№   №№№    №№№  №        №№№|",
	"|           №№№№              |",
	"|   № №  №№№№                |",
	"| № №№№  №№№№  №    №№№№ № №  |",
	"| №           №№№№  №      №  |",
	"| №№№№№№ №№№         №№       |",
	"| №№№      №№№№№№  №№№№№№№ №№№|",
	"|           №№№№№№№           |",
	"|                             |",
	"№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№№"
};
char raspyatye[22][35] = {
	
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"    №№№№№№№№№№№№№№№№№№№№№         ",
	"    №№№№№№№№№№№№№№№№№№№№№         ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"             №№№                  ",
	"                                  "
};
void ShowMap()
{
	for (int i = 0; i < 23; i++) {
		cout << map[i] << endl;
	}
}

void positt(int x, int y)
{
	
	COORD position = { x, y };
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, position);
}

class entity {
public:
	entity(int x, int y) {
		this->x = x;
		this->y = y;
	}
int get_x() { 
		return x;
	}
int get_y() {
		return y;
	}

	void xxx(int p) {
		if (map[y][x + p] == ' ') { x = x + p; }
	}

	void yyy(int p) {
		if (map[y + p][x] == ' ') { y=y+p; }
	}

	void m(int p, int q) {
		x += p;
		y += q;
	}

	
	
	void spf(char p) {
		map[x][y] = p;
		positt(x, y); 
		cout << p;
	}

private:
	int x;
	int y;
};



void mas(int x, int y, int wc, int back) {
	if (mape[y][x] == ' ' || mape[y][x] == '.') {
		mape[y][x] = '№';
		hhh h1;
		h1.x = x;
		h1.y = y;
		h1.hod = wc;
		h1.back = back;
		mmas.push_back(h1);
	}
}

void ps(int Iuda_sx, int Iuda_sy, int x, int y) {
	memcpy(mape, map, sizeof(map));
	mmas.clear();
	hhh h1;
	h1.x = Iuda_sx;
	h1.y = Iuda_sy;
	h1.hod = 0;
	h1.back = -1;
	mmas.push_back(h1);

	int i = 0;
	while (i < mmas.size()) {
		if (mmas[i].x == x && mmas[i].y == y) {
			he.clear();
			iuda h12;
			while (mmas[i].hod != 0) {
				h12.x = mmas[i].x;
				h12.y = mmas[i].y;
				he.push_back(h12);

				i = mmas[i].back;
			}

			break;
		}
mas(mmas[i].x - 1, mmas[i].y, mmas[i].hod + 1, i);
		mas(mmas[i].x, mmas[i].y + 1, mmas[i].hod + 1, i);
		mas(mmas[i].x, mmas[i].y - 1, mmas[i].hod + 1, i);
		mas(mmas[i].x + 1, mmas[i].y, mmas[i].hod + 1, i);
		
		i++;
	}

	mmas.clear();
}


int wmain(int argc, char* argv[], char* envp[])

{

	setlocale(LC_ALL, "Russian");


	int point = 0;
	int x = 11; 
	int y = 7; 

	int Iuda_x = 7;
	int Iuda_y = 1;

	int oldx;
	int oldy;



	cout<<"Hard"<<endl<<"Normal"<<endl<<"Easy "<<endl;

	char diffi;
	int speed = 3;

	cin >> diffi;
system("cls");
	ShowMap();
	if (diffi == 'N') {
		speed = 2;
	}
	 if (diffi == 'H') {
		speed = 1;
	}

	

	positt(x, y); 
	cout << (char)0x534D;

	int frame = 0;

	ps(Iuda_x, Iuda_y, x, y);

	while (1==1) {
		positt(x, y); cout << " ";

		oldx = x;
		oldy = y;
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (map[y][x + 1] == '.') { x++; point++; }
			else {
				if (map[y][x + 1] == ' ') { x++; }
			}
		}
		if (GetAsyncKeyState(VK_UP)) {
			if (map[y - 1][x] == '.') { y--; 
			point++; }
			else {
				if (map[y - 1][x] == ' ') { y--; }
			}
		}	if (GetAsyncKeyState(VK_LEFT)) {
			if (map[y][x - 1] == '.') { x--;
			point++; }
			else {
				if (map[y][x - 1] == ' ') { x--; }
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (map[y + 1][x] == '.') { y++;
			point++; }
			else {
				if (map[y + 1][x] == ' ') { y++; }
			}
		}
	
		

		
			ps(Iuda_x, Iuda_y, x, y);
		

		positt(x, y);
		cout << RED;
		wcout << (char)0x534D;
		cout << WHITE;
		map[Iuda_y][Iuda_x] = '.';
		positt(Iuda_x, Iuda_y); 
		cout << ".";

		if (frame % speed == 0) {
			Iuda_y = he.back().y;
			Iuda_x = he.back().x;
			
			he.pop_back();
		}

		positt(Iuda_x, Iuda_y); 
		cout << RED;

		cout << "I";
		cout << WHITE;
		if (Iuda_x == x && Iuda_y == y) {
			break;
		}


		
		positt(34, 8); 
		cout << point;
		Sleep(100);
		frame++;
	}

	system("cls");

	bool chek=true;
	while (chek) {
		
		cout << "Вас распяли "<<point;
	cout << endl;
		for (int i = 0; i < 22; i++) {
			if (GetAsyncKeyState(VK_TAB)) {

				chek = false;
				break;
			}
			cout << raspyatye[i] << endl;
			Sleep(100);
		}
		system("cls");
	}

	
	
	
	return 0;
}

		

		
