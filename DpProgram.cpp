#include <iostream>
#include <string.h>
using namespace std;

/****
 *
 *Problem One:
 *Find the longest increasing sub sequence;
 ***********O(n)
 **/
 int LISdyna(int *sequence,int lenth)
 {
 	int dp_seq[lenth];
 	int new_flag,pre_flag;
 	for(new_flag=1,dp_seq[0]=1;new_flag<lenth;new_flag++)
 	{
 		int longest_len=0;
 		for(pre_flag=0;pre_flag<new_flag;pre_flag++)
 			if(sequence[pre_flag]<sequence[new_flag]&&dp_seq[pre_flag]>longest_len)
 				longest_len=dp_seq[pre_flag];
 		dp_seq[new_flag]=longest_len+1;
 	}
 	int LIS=dp_seq[0];
 	for(int i=1;i<lenth;i++)
 		if(dp_seq[i]>LIS)
 			LIS=dp_seq;
 	return dp_seq;
 }

