#include <iostream>
#include <cstdio>
using namespace std;
typedef struct node
{
	int ID;
	struct node *pre;
	struct node *next;
}Applicants;


int main()
{
	freopen("data.in","r",stdin);
	int number,add,sub;
	while(scanf("%d %d %d",&number,&add,&sub)&&number!=0)
	{
		/*****************build the ring*******/
		Applicants *head=new Applicants;
		head->ID=1;
		head->next=head;
		head->pre=head;
		Applicants *cur=head;
		for(int i=2;i<=number;i++)
		{
			Applicants *add=new Applicants;
			add->ID=i;
			add->next=cur->next;
			add->pre=cur;
			cur->next->pre=add;
			cur->next=add;
			cur=add;
		}
		int curNum=number;
		Applicants *curadd=head;
		Applicants *cursub=cur;
		while(curNum>0)
		{
			for(int i=1;i<add;i++)
				curadd=curadd->next;
			for(int i=1;i<sub;i++)
				cursub=cursub->pre;
			if(curadd->ID==cursub->ID)
			{
				Applicants *move=curadd;
				curadd=curadd->next;
				cursub=cursub->pre;
				printf(" %d",move->ID);
				curNum--;
				curadd->pre=cursub;
				cursub->next=curadd;
				delete move;
				if(curNum!=0)
					printf(",");
			}
			else
			{
				printf("  %d  %d",curadd->ID,cursub->ID);
				curNum-=2;
				Applicants *moveadd=curadd;
				curadd=curadd->next;
				curadd->pre=moveadd->pre;
				moveadd->pre->next=curadd;
				if(curadd==cursub)
					curadd=curadd->next;
				Applicants *movesub=cursub;
				cursub=cursub->pre;
				cursub->next=movesub->next;
				movesub->next->pre=cursub;
				delete moveadd;
				delete movesub;
				if(curNum!=0)
					printf(",");
			}
		}
		printf("\n");
	}
	return 0;
}