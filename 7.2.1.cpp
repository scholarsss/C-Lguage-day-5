#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define a 3
#define b 3
void qi(char san[a][b])
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			san[i][j]=' ';
		}
	}
}
void bu(char san[a][b])
{
	printf("+---+---+---+\n");
	for(int i=0;i<a;i++)
	{
		printf("| %c | %c | %c |\n",san[i][0],san[i][1],san[i][2]);
		printf("+---+---+---+\n");
	}
}
void play(char san[a][b])
{
	while(1)
	{
		int x,y;
		printf("请输入所要下的坐标（中间用空格隔开）\n");
		scanf("%d%d",&x,&y);
		if(x<0||x>=a||y>=b||y<0)
		{
			printf("输入错误，请在（1，1）到（3，3）的范围内重新输入\n");
			continue;
		}
		else if(san[x][y]!=' ')
			{
				printf("该位子已有棋子\n");
				continue;
			}
		else
		{
			san[x][y]='x';
			break;
        }  
    }
}
void dian(char san[a][b])
{
	while(1)
	{
		int x=rand()%a;
		int y=rand()%b;
		if(san[x][y]!=' '||san[x][y]=='x')
		{
			continue;
		}
		else
		{
			san[x][y]='o';
			break;
		}
	}
}
int ping(char san[a][b])
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(san[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char pan(char san[a][b])
{
	for(int i=0;i<a;i++)
	{
		if(san[i][0]!=' '&&san[i][0]==san[i][1]&&san[i][1]==san[i][2])
		{
			return san[i][0];
		}	
	}
	for(int j=0;j<b;j++)
	{
	    if(san[0][j]!=' '&&san[0][j]==san[1][j]&&san[1][j]==san[2][j])
		{
				return san[1][j];		
		}
	}
	if(san[0][0]==san[1][1]&&san[1][1]==san[2][2]&&san[0][0]!=0)
	{
		return san[0][0];
	}
	if(san[2][0]==san[1][1]&&san[1][1]==san[0][2]&&san[2][0])
	{
		return san[2][0];
	}
	if(ping(san)==1)
	{
		return 'h';
	}
	return 'j';
}
void game()
{
	char ret='0';
	char san[a][b]={0};//定义一个3*3的数组
	qi(san);//对3*3数组进行初始化
	bu(san);//布置棋盘架构
	while(1)
	{
		play(san);//玩家进行下棋
		bu(san);//布置棋盘架构
		ret=pan(san);
		if(ret!='j')
		{
			break;
		}
		dian(san);//电脑进行下棋
		bu(san);//布置棋盘架构
		ret=pan(san);
		if(ret!='j')
		{
			break;
		}
	}
    if(ret=='x')
	{
		printf("恭喜您获胜了\n");
	}
	else if(ret=='o')
	{
		printf("电脑获胜了\n");
	}
	else
	{
		printf("平局\n");
	}
}
int menu()
{
	int en;
	printf("##########################\n");
	printf("##1.进入游戏  0.退出游戏##\n");
	printf("##########################\n");
	scanf("%d",&en);
	return en;
}
int main()
{
	srand((unsigned int)time(0));
	while(1)
	{
		int en=menu();
		if(en==1)
		{
			game();
		}
		else if(en==0)
		{
			printf("退出游戏\n");
			break;
		}
		else
		{
			printf("输入错误！请重新输入！\n");
			continue;
		}
	}
	return 0;
}
