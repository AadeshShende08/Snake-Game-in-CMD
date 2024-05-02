#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
int height = 20,width=20;

int x,y,fruitX,fruitY,score;

int tailx[100],taily[100],ntail = 1;

enum eDirection {STOP=0,UP,DOWN,LEFT,RIGHT};
eDirection dir;

void setup()
{
	gameOver = false;
	dir = STOP;
	x=width/2;
	y=height/2;
	fruitX = rand() % width;
	fruitY = rand() % height;
}

void Draw()
{
	system("CLS");
	
	for(int i =0;i<width;i++)
	{
		cout<<"-";
	}cout<<endl;
	
	for(int i =0;i<height;i++)
	{
		for(int j=0;j<height;j++)
		{
			if(j==0 || j==width-1)
			{
				cout<<"|";
			}
			else if(i==y && j==x)
			{
				cout<<"O";
			}
			else if(i==fruitY && j==fruitX)
			{
				cout<<"F";
			}
			else
			{
				bool print  = false;
				for(int k =0;k<ntail;k++)
				{
					if(i==taily[k] && j==tailx[k])
					{
					cout<<"o";
					print = true;
					break;
					}
				}
				if(!print){cout<<" ";}
			}
		}cout<<endl;
	}
	for(int i =0;i<width;i++)
	{
		cout<<"-";
	}cout<<endl;
	cout<<endl<<"score = "<<score<<endl;
}

void Input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case'w':
				dir = UP;
				break;
			case'a':
				dir = LEFT;
				break;
			case's':
				dir = DOWN;
				break;
			case'd':
				dir = RIGHT;
				break;
			default:
				break;
		}
	}
}

void Logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	tailx[0]=x;
	taily[0]=y;
	int prev2x,prev2y;

	for(int i = 0 ;i<ntail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}


	switch(dir){
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		default:
			break;
	}
	if (x<=0 || x>=width || y<=0 || y>=height)
	{
		gameOver=true;
	}

	for(int i=0 ; i<ntail;i++)
	{
		if(x==tailx[i] && y == taily[i])
		{
			gameOver = true;
		}
	}

	if(x==fruitX && y==fruitY)
	{
		score+=1;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++;
	}
	
}
int main(){
	setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(300);

	}
	return 0;
}
