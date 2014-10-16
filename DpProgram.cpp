#include <iostream>
#include <stdio.h>
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
 			LIS=dp_seq[i];
 	return LIS;
 }

/****
 *
 *Problem One
 *Version two
 ******O(nlogn)
 ***/
 int LIS(int *sequence,int lenth)
 {
 	int biSearch(int aim,int tail,int *sequence,int *smallist);
 	int smallist[lenth];//smallist[k] means the smallist tail of all the k-lenth subsequence;
 	smallist[1]=sequence[0];
 	int now_lenth=1;
 	int visit_flag;     //visit the whole sequence, we make the LIS longer 
 	                    //by add subsequence and fresh the record;
 	for(visit_flag=1;visit_flag<lenth;visit_flag++)
 	{
 		if(sequence[visit_flag]>=smallist[now_lenth])
 			smallist[++now_lenth]=sequence[visit_flag];
 		else
 			smallist[biSearch(visit_flag,now_lenth,sequence,smallist)]=sequence[visit_flag];
 	}
 	return now_lenth;
 }
 int biSearch(int aim,int tail,int *sequence,int *smallist)
 {
 	if(sequence[aim]<smallist[1])
 		return 1;
 	int lo,hi;
 	for(lo=1,hi=tail;lo!=hi-1;){
 		if(smallist[tail=(lo+hi)/2]<=sequence[aim])
 			lo=tail;
 		else
 			hi=tail;
 	}
 	return hi;
 }
 

