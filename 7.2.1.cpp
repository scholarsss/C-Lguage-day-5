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
		printf("��������Ҫ�µ����꣨�м��ÿո������\n");
		scanf("%d%d",&x,&y);
		if(x<0||x>=a||y>=b||y<0)
		{
			printf("����������ڣ�1��1������3��3���ķ�Χ����������\n");
			continue;
		}
		else if(san[x][y]!=' ')
			{
				printf("��λ����������\n");
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
	char san[a][b]={0};//����һ��3*3������
	qi(san);//��3*3������г�ʼ��
	bu(san);//�������̼ܹ�
	while(1)
	{
		play(san);//��ҽ�������
		bu(san);//�������̼ܹ�
		ret=pan(san);
		if(ret!='j')
		{
			break;
		}
		dian(san);//���Խ�������
		bu(san);//�������̼ܹ�
		ret=pan(san);
		if(ret!='j')
		{
			break;
		}
	}
    if(ret=='x')
	{
		printf("��ϲ����ʤ��\n");
	}
	else if(ret=='o')
	{
		printf("���Ի�ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
int menu()
{
	int en;
	printf("##########################\n");
	printf("##1.������Ϸ  0.�˳���Ϸ##\n");
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
			printf("�˳���Ϸ\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
			continue;
		}
	}
	return 0;
}
