#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
using namespace std;
bool gameover; 
const int height=20;
const int width=30;
int x,y,fruitx,fruity,score;
int tailx[50],taily[50],ntail;
enum direction {STOP=0,UP,DOWN,LEFT,RIGHT
} dir;
int setup()
{
	gameover = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitx = rand() % width;
	fruity = rand() % height;
}
int draw()
{
	system("cls");
	for(int i=0;i<width;i++)
	cout<<"#";
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0 || j==width-1)
			cout<<"#";
			
			if(i == x && j == y)
			cout<<"O";
			else if( i == fruitx && j == fruity)
			cout<<"F";
			else
			{
				bool print = false;
				for(int k=0;k<ntail;k++)
				{
					
					if(tailx[k]==i && taily[k]==j)
					{ 
						cout<<"o";
						print = true;
					}
				}
				if(!print)
					cout<<" ";
					
			}
			
		}
		cout<<endl;
	}
	
	
	for(int i=0;i<width;i++)
	cout<<"#";
	cout<<endl;
	cout<<"score = "<<score;
}
int input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameover = true;
				break;
		}
	}
	
}
int logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(dir)
	{
		case LEFT:
			y--;
			break;
		case RIGHT:
			y++;
			break;
		case UP:
			x--;
			break;
		case DOWN:
			x++;
			break;
	}
	if(y>width-2 || x> height || x<0 || y< 0)
	{
		gameover = true;
	}
	for(int i=0;i<ntail;i++)
		if(tailx[i]==x && taily[i]==y)
			gameover=true;
	if(x == fruitx && y == fruity)
	{
		ntail++;
		score+=10;
		fruitx = rand() % height;
		fruity = rand() % width;
	}
}
int main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		Sleep(25);
	}
}



	

