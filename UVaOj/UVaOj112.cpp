#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
bool getaim=false;
void anylize(int aim,char *curStr,int cursum);
int main()
{
	freopen("data.in","r",stdin);
	char whole[1000];
	int number=0;
	while(gets(whole)!=NULL)
	{
		int leng=strlen(whole);
		int i=0;
		while(whole[i]!=' ')
		{
			number=number*10+whole[i]-'0';
			i++;
		}
		i++;
		int j=0;
		for(i;i<=leng;)
		{
			if(whole[i]==' '||whole[i]=='\n')
				i++;
			else
			{
				whole[j]=whole[i];
				i++;
				j++;
			}
		}
		getaim=false;
		anylize(number,whole,0);
		if(getaim==false)
			printf("no\n");
	}
	return 0;
}

void anylize(int aim,char *curStr,int cursum)
{
	if(getaim)
		return;
	if(strlen(curStr)==2)
	{
		if(aim==cursum)
		{
			printf("yes\n");
			getaim=true;
		}
		return;
	}
	int flag=1;
	int curnum=0;
	while(curStr[flag]!='(')
	{
		curnum=curnum*10+curStr[flag]-'0';
		flag++;
	}
	flag++;
	char left[1000];
	char right[1000];
	left[0]='(';
	right[0]='(';
	int stack=1;
	int i=1;
	while(stack!=0)
	{
		left[i]=curStr[flag];
		if(curStr[flag]=='(')
			stack++;
		else if(curStr[flag]==')')
			stack--;
		i++;
		flag++;
	}
	left[i]='\0';
	anylize(aim,left,cursum+curnum);
	stack=1;
	i=1;
	flag++;
	while(stack!=0)
	{
		right[i]=curStr[flag];
		if(curStr[flag]=='(')
			stack++;
		else if(curStr[flag]==')')
			stack--;
		i++;
		flag++;
	}
	right[i]='\0';
	anylize(aim,right,cursum+curnum);
}

//In this program,the input is not perfect;
//haven't solve the input with many lines;