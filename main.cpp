#include <graphics.h>
#include <bits/stdc++.h>
#include <easyx.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;
int x = 1, y = 1;
char ch;
bool st = 0;
int getch(void);
ch = getch();

char a[50][50] = {"########################################", //0
                  "#i   #           *#         #          #",//1
                  "#        #       #####         #       #",//2
                  "######         *     #  *   #          #",//3
                  "#            # *  #  #  *   #  #*****  #",//4
                  "#             **  #  #  *  ##########* #",//5
                  "#          #***#  #   # * #          # #",//6
                  "#           ###         *    *         #",//4
                  "#    #***#        #     # #  #*    #####",//8
                  "#     ###                 #   *    #    ",//9
                  "#       ######        # # #  #*#   #    ",//0
                  "#                  #**#  *    #      *  ",//1
                  "#                  ####            #    ",//2
                  "#             #**     ##   *#   *  #####",//3
                  "#     #####    #*         #    *#      #",//4
                  "#               *     #        *       #",//5
                  "#               *     # *     *#*      #",//6
                  "#               *     # *     * *      #",//7
                  "#**************************************#",//8
                  "########################################",//9
                 };
int cnt = 1;

bool a1[50][50] = {0}; //1 -> lava

void outputmap() {
	IMAGE stonebrick, stone, hj, lava;
	loadimage(&stonebrick, "picture\\stonebrick.png", 35, 35);
	loadimage(&stone, "picture\\stone.png", 35, 35);
	loadimage(&hj, "picture\\hj.jpg", 35, 35);
	loadimage(&lava, "picture\\lava.png", 35, 35);
	for (int i = 0; i <= 39; i++) {
		for (int j = 0; j <= 19; j++) {
			int xx = i * 35, yy = j * 35;
			switch (a[j][i]) {
				case '#':
					putimage(xx, yy, &stonebrick);
					break;
				case ' ':
					putimage(xx, yy, &stone);
					break;
				case 'i':
					putimage(xx, yy, &hj);
					break;
				case '*':
					putimage(xx, yy, &lava);
					break;
			}
		}
	}
}
void thread01() {
	for (int i = 0; i <= 39; i++) {
		for (int j = 0; j <= 39; j++) {
			if (a[i][j] == '*') {
				a1[i][j] = 1;
			}
		}
	}
	while (y <= 39) {
		Sleep(250);
		if (a1[x][y] == 1) {
			break;
		}
		if (y >= 39/*win*/) {
			break;
		}
		if (a[x + 1][y] != '#') {
			a[x][y] = ' ';
			x++;
			a[x][y] = 'i';
			outputmap();
		}

	}
	st = 1;
	return;
}

void input() {
	Sleep(650);
	while (1) {
		ch = getch();
		if (a1[x][y] == 1) {
			break;
		}
		if (y >= 39/*win*/) {
			break;
		}
		Sleep(50);
		ch = 0;
		Sleep(150);
	}
	return;
}

int main() {
	initgraph(1400, 700);
	thread task01(thread01);
	task01.detach();
	thread in(input);
	in.detach();
	Sleep(500);
	while (1) {

		if (a1[x][y] == 1) {
			break;
		}
		if (y >= 39/*win*/) {
			break;
		}
		if (st == 1)
			break;
		Sleep(50);
		if (1) {
			if (ch == 's' && a[x + 1][y] != '#') {
				a[x][y] = ' ';
				x++;
				a[x][y] = 'i';
				outputmap();
			}
			if (ch == 'w') {
				if (a[x - 1][y] != '#') {
					a[x][y] = ' ';
					x--;
					a[x][y] = 'i';
					outputmap();
				}
			}
			if (ch == 'a') {
				if (a[x][y - 1] != '#') {
					a[x][y] = ' ';
					y--;
					a[x][y] = 'i';
					outputmap();
				}
			}
			if (ch == 'd') {
				if (a[x][y + 1] != '#') {
					a[x][y] = ' ';
					y++;
					a[x][y] = 'i';
					outputmap();
				}
			}
			if (a1[x][y] == 1) {
				break;
			}
			if (y >= 39/*win*/) {
				break;
			}

		}
	}
	closegraph();
	if (y >= 39/*win*/) {
		printf("\nYou win");
	} else {
		printf("\nYou lose");
	}
	return 0;
}