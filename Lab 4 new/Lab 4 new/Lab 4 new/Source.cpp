#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y)
{
	
	gotoxy(x, y);
	printf("       ");
	
}
void draw_ship(int x, int y)
{
	/*gotoxy(x, y);
	printf(" <-0-> ");*/
	x = max(x, 0);
	y = max(y, 0);
	x = min(x, 80);
	y = min(y, 28);
	gotoxy(x, y);
	printf(" <-0-> ");
}

int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	gotoxy(x, y);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') 
			{ 
				erase_ship(x, y);
				gotoxy(x, y);
				draw_ship(--x, y); 
				if (x < 0)
				{
					x = 0;
				}
			}
			if (ch == 'd') 
			{
				erase_ship(x, y);
				gotoxy(x, y);
				draw_ship(++x, y); 
				if (x > 80)
				{
					x = 80;
				}
				
			}
			if (ch == 'w')
			{
				erase_ship(x, y);
				gotoxy(x, y);
				draw_ship(x, --y);
				if (y < 0)
				{
					y = 0;
				}
				
			}
			if (ch == 's')
			{
				erase_ship(x, y);
				gotoxy(x, y);
				draw_ship(x, ++y);
				if (y > 28)
				{
					y = 28;
				}
				
			}
			fflush(stdin);
		}
		Sleep(500);
	} while (ch != 'x');
	return 0;
}