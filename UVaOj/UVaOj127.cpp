#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

typedef struct node{
	char suit;
	char value;
}Card;

bool same(stack<Card>* list,int i,int j);
void prtlist(stack<Card>* list,int num);

int main()
{
	freopen("data.in","r",stdin);	
	Card temp;
	char judge;
	scanf("%c",&judge);
	while(judge!='#')
	{
		stack<Card> cardlist[52];
		int num=52;
		char _judge;
		scanf("%c",&_judge);
		temp.suit=_judge;
		temp.value=judge;
		cardlist[0].push(temp);
		for(int i=1;i<52;i++)
		{
			getchar();
			char in_suit,in_value;
			scanf("%c%c",&in_value,&in_suit);
			temp.suit=in_suit;
			temp.value=in_value;
			cardlist[i].push(temp);
		}
		bool nd_ctn;
		do{
			//here is the handles;
			nd_ctn=false;
			if(num==1)
				break;
			int cur=1;
			int change=0;
			while((!cardlist[cur].empty())&&cur<num)
			{
				if(cur>=3)
				{
					if(same(cardlist,cur,cur-3))
					{
						nd_ctn=true;
						change=3;
						break;
					}
					if(same(cardlist,cur,cur-1))
					{
						nd_ctn=true;
						change=1;
						break;
					}
					cur++;
				}
				else
				{
					if(same(cardlist,cur,cur-1))
					{
						nd_ctn=true;
						change=1;
						break;
					}
					cur++;
				}
			}
			if(nd_ctn)
			{
				//here means we need to change
				Card tempz=cardlist[cur].top();
				cardlist[cur].pop();
				cardlist[cur-change].push(tempz);
				if(cardlist[cur].empty())
				{
					num--;
					cur++;
					while(cur<=num)
					{
						cardlist[cur-1]=cardlist[cur];
						cur++;
					}
				}
			}
		}while(nd_ctn);
		prtlist(cardlist,num);
		getchar();
		scanf("%c",&judge);
	}
	return 0;
}

bool same(stack<Card>* list,int i,int j)
{
	bool is_same;
	Card temp1=list[i].top();
	Card temp2=list[j].top();
	if(temp1.value==temp2.value||temp1.suit==temp2.suit)
		is_same=true;
	else
		is_same=false;
	return is_same;
}
void prtlist(stack<Card>* list,int num)
{
	int count=num;
	printf("%d ",count);
	if(count>1)
		printf("piles remaining:");
	else
		printf("pile remaining:");
	for(int i=0;i<count;i++)
		printf(" %lld",list[i].size());
	printf("\n");
}
