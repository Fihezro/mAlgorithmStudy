#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int moveonto=1;
const int moveover=2;
const int pileonto=3;
const int pileover=4;
const int quit=5;
int curPac[26];
/****Make the class of place****/
class Place{
public:
	int contains[25];
	int number;
	void init(int i){number=1;contains[0]=i;}
	void printplace();
	int foundaim(int aim);
};
int Place::foundaim(int aim)
{
	int i;
	for(i=0;i<number;i++)
	{
		if(contains[i]==aim)
			break;
	}
	return i;
}
void Place::printplace()
{
	for(int i=0;i<number;i++)
		printf(" %d",contains[i]);
}

Place putPlace[26];
/****Function for each handle****/
void f_moveonto(int a,int b);
void f_moveover(int a,int b);
void f_pileonto(int a,int b);
void f_pileover(int a,int b);

void terminatePrint(int number)
{
	for(int i=0;i<number;i++)
	{
		printf("%d:",i);
		putPlace[i].printplace();
		printf("\n");
	}
}
/********************************/
int main()
{
	freopen("data.in","r",stdin);
	/*******get whole data*******/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		curPac[i]=i;
		putPlace[i].init(i);
	}
	/*******handle*********/
	char operate[5];
	char type[5];
	int pl_a,pl_b;
	while(scanf("%s",operate)&&operate[0]!='q')
	{
		scanf("%d %s %d",&pl_a,&type,&pl_b);
		if(curPac[pl_a]==curPac[pl_b])
			continue;
		int handle=0;
		if(operate[0]=='m')
		{
			if(type[1]=='n')
				handle=moveonto;
			else
				handle=moveover;
		}
		else if(operate[0]=='p')
		{
			if(type[1]=='n')
				handle=pileonto;
			else
				handle=pileover;
		}

		switch(handle)
		{
		case moveonto:
			f_moveonto(pl_a,pl_b);
			break;
		case moveover:
			f_moveover(pl_a,pl_b);
			break;
		case pileonto:
			f_pileonto(pl_a,pl_b);
			break;
		case pileover:
			f_pileover(pl_a,pl_b);
			break;
		}
	}
	terminatePrint(n);
	return 0;
}

/******functions***********/
void f_moveonto(int a,int b)
{
	int from=curPac[a];
	int to=curPac[b];
	int from_aim=putPlace[from].foundaim(a);
	int to_aim=putPlace[to].foundaim(b);
	for(int i=to_aim+1;i<putPlace[to].number;i++)
	{
		curPac[putPlace[to].contains[i]]=putPlace[to].contains[i];
		putPlace[putPlace[to].contains[i]].contains[0]=putPlace[to].contains[i];
		putPlace[putPlace[to].contains[i]].number=1;
	}
	putPlace[to].contains[to_aim+1]=a;
	putPlace[to].number=to_aim+2;
	for(int i=from_aim+1;i<putPlace[from].number;i++)
	{
		curPac[putPlace[from].contains[i]]=putPlace[from].contains[i];
		putPlace[putPlace[from].contains[i]].contains[0]=putPlace[from].contains[i];
		putPlace[putPlace[from].contains[i]].number=1;
	}
	putPlace[from].number=from_aim;
	curPac[a]=to;
}
void f_moveover(int a,int b)
{
	int from=curPac[a];
	int to=curPac[b];
	int from_aim=putPlace[from].foundaim(a);
	putPlace[to].contains[putPlace[to].number]=a;
	putPlace[to].number++;
	for(int i=from_aim+1;i<putPlace[from].number;i++)
	{
		curPac[putPlace[from].contains[i]]=putPlace[from].contains[i];
		putPlace[putPlace[from].contains[i]].contains[0]=putPlace[from].contains[i];
		putPlace[putPlace[from].contains[i]].number=1;
	}
	putPlace[from].number=from_aim;
	curPac[a]=to;
}
void f_pileonto(int a,int b)
{
	int from=curPac[a];
	int to=curPac[b];
	int from_aim=putPlace[from].foundaim(a);
	int to_aim=putPlace[to].foundaim(b);
	for(int i=to_aim+1;i<putPlace[to].number;i++)
	{
		curPac[putPlace[to].contains[i]]=putPlace[to].contains[i];
		putPlace[putPlace[to].contains[i]].contains[0]=putPlace[to].contains[i];
		putPlace[putPlace[to].contains[i]].number=1;
	}
	int j=to_aim+1;
	for(int i=from_aim;i<putPlace[from].number;i++)
	{
		putPlace[to].contains[j]=putPlace[from].contains[i];
		curPac[putPlace[from].contains[i]]=to;
		j++;
	}
	putPlace[to].number=j;
	putPlace[from].number=from_aim;
}
void f_pileover(int a,int b)
{
	int from=curPac[a];
	int to=curPac[b];
	int from_aim=putPlace[from].foundaim(a);
	int j=putPlace[to].number;
	for(int i=from_aim;i<putPlace[from].number;i++)
	{
		putPlace[to].contains[j]=putPlace[from].contains[i];
		curPac[putPlace[from].contains[i]]=to;
		j++;
	}	
	putPlace[to].number=j;
	putPlace[from].number=from_aim;
}
