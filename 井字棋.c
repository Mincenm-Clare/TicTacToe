#include<stdio.h>
void boardnow(int board[3][3]);
int chess(int *board,int i);
void place(int * board,int *v,int i);
int judge1(int (*board)[3]);
int win(int judge,int i);
int again1(void);
void resetting(int board[][3]);
int main(void)
{
	printf("欢迎来到井字棋。\n");
		printf("┏━┳━┳━┓\n");
		printf("┃1 ┃2 ┃3 ┃\n");
		printf("┣━╋━╋━┫\n");
		printf("┃4 ┃5 ┃6 ┃\n");
		printf("┣━╋━╋━┫\n");
		printf("┃7 ┃8 ┃9 ┃\n");
		printf("┗━┻━┻━┛\n");
		int v,i,judge,again;
		int board[3][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9},
		};
		for(i=1,judge=0;1;)
		{
			v=chess(board[0],i);
			place(board[0],&v,i);
			boardnow(board);
			judge=judge1(board);
			again=win(judge,i);
			if(again==1)
			{
				resetting(board);
				boardnow(board);
				i=1;
				continue;
			}
			else if(again==2)
				break;
			i=i+1;
		}
		printf("感谢您的游玩！");
		getchar();
		return 0;
}
void boardnow(int board[3][3])
{
	int x,y,s;
	char chess;
	printf("┏━┳━┳━┓\n");
	for(y=0;y<3;y++)
	{
		printf("┃");
		for(x=0;x<3;x++)
		{
			if(board[y][x]==-1)
				printf("%c ┃",'O');
			else if(board[y][x]==-2)
				printf("%c ┃",'X');
			else
				printf("%d ┃",board[y][x]);
		}
		if(y<2)
			printf("\n┣━╋━╋━┫\n");
	}
	printf("\n┗━┻━┻━┛\n");
}

int chess(int * board,int i)
{
	int chessv;
	if(i%2==1)
		printf("现在是“O”的回合，请落子:");
	else
		printf("现在是“X”的回合，请落子:");
	while(1)
	{
		while(scanf("%d",&chessv)==1&&((chessv>=1)&&(chessv<=9)))
		{
			if(board[chessv-1]==-1)
			{
				printf("这里已经有一个“O”了，请不要下在重复的地方，请重新输入：");
				continue;
			}
			else if(board[chessv-1]==-2)
			{
				printf("这里已经有一个“X”了，请不要下在重复的地方，请重新输入：");
				continue;
			}
			else
				return chessv;
		}
		while(getchar()!='\n')
			continue;
		printf("请输入一个1-9之间的数字:");
	}
}

void place(int * board,int *v,int i)
{
	if(i%2==1)
		board[*v-1]=-1;
	else
		board[*v-1]=-2;
}

int judge1(int (*board)[3])
{
	if((board[0][0]==board[0][1])&&(board[0][0]==board[0][2]))
	{
		if(board[0][0]==-1)
			return 1;
		else
			return 2;
	}
	else if((board[1][0]==board[1][1])&&(board[1][0]==board[1][2]))
	{
		if(board[1][0]==-1)
			return 1;
		else
			return 2;
	}
	else if((board[2][0]==board[2][1])&&(board[2][0]==board[2][2]))
	{
		if(board[2][0]==-1)
			return 1;
		else
			return 2;
	}
	else if((board[0][0]==board[1][0])&&(board[0][0]==board[2][0]))
	{
		if(board[0][0]==-1)
			return 1;
		else
			return 2;
	}
	else if((board[0][1]==board[1][1])&&(board[0][1]==board[2][1]))
	{
		if(board[0][1]==-1)
			return 1;
		else
			return 2;
	}
	else if((board[0][2]==board[1][2])&&(board[0][2]==board[2][2]))
	{
		if(board[0][2]==-1)
			return 1;
		else
			return 2;
	}
	else if((board[0][0]==board[1][1])&&(board[0][0]==board[2][2]))
	{
		if(board[0][0]==-1)
			return 1;
		else
			return 2;
	}
	else if((board[0][2]==board[1][1])&&(board[0][2]==board[2][0]))
	{
		if(board[0][2]==-1)
			return 1;
		else
			return 2;
	}
	else
		return 0;
}

int again1(void)
{
	char v;
	while(getchar()!='\n')
			continue;
	while(1)
	{
		scanf("%c",&v);
		while(1)
		{
			if((v=='Y')||(v=='y'))
			{
				while(getchar()!='\n')
				continue;
				return 1;
			}
			else if((v=='N')||(v=='n'))
			{
				while(getchar()!='\n')
				continue;
				return 2;
			}
			else
				break;
		}
		printf("请重新输入(Y\\N):");
		if(v!='\n')
			while(getchar()!='\n')
				continue;
		continue;
	}
}

int win(int judge,int i)
{
	int again;
	if(judge==1)
		{
			printf("O赢了！");
			printf("是否重新开局(Y\\N):");
			again=again1();
			if(again==1)
				return 1;
			else
				return 2;
		}
	else if(judge==2)
		{
			printf("X赢了！");
			printf("是否重新开局(Y\\N):");
			again=again1();
			if(again==1)
				return 1;
			else
				return 2;
		}
	if(i==9)
		{
			printf("平局了。");
			printf("是否重新开局(Y\\N):");
			again=again1();
			if(again==1)
				return 1;
			else
				return 2;
		}
}

void resetting(int board[][3])
{
	int x,y,i;
	for(y=0,i=1;y<3;y++)
		for(x=0;x<3;x++,i++)
			board[y][x]=i;
}
