/*
 * sorta1witha2.c
 * 
 * Copyright 2014 kartha <kartha@nirvana>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>


void merge(int *A,int *L,int lsize,int *R,int rsize)
{
	int i=0,j=0,k=0;
	while(i<lsize&&j<rsize)
	{
		if(L[i]<R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<lsize)
	{
		A[k]=L[i];
		k++;
		i++;
	}
	while(j<rsize)
	{
		A[k]=R[j];
		k++;
		j++;
	}
	
}
void part(int *A,int size)
{
	int L[size/2];
	int R[size/2];
	int i;
	if(size<2)
		return;
	else
	{
		int mid=size/2;
		for(i=0;i<mid;i++)
			L[i]=A[i];
		for(i=0;i<(size-mid);i++)
			R[i]=A[mid+i];
		part(L,mid);
		part(R,(size-mid));
		merge(A,L,mid,R,(size-mid));
	}
}

int binsearch(int *A,int size,int key)
{
	int s=0,e=size;
	int mid=(s+e)/2;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(A[mid]==key)
			return mid;
		else if(A[mid]>key)
			e=mid-1;
		else
			s=mid+1;
	}
	return -1;
}
int main(int argc, char **argv)
{
	int A1[]={2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8},A2[] = {2, 1, 8, 3};
	int temp[11];
	int i,ind=0;
	for(i=0;i<11;i++)
	{
		temp[i]=A1[i];
	}
	part(temp,11);

		for(i=0;i<4;i++)
		{
			int loc=binsearch(temp,11,A2[i]);
			while(loc>0)
			{
				A1[ind]=A2[i];
				ind++;
				temp[loc]=-1;
				loc=binsearch(temp,11,A2[i]);
			}
		}
		i=0;
		while(i<11)
		{
			if(temp[i]!=-1)
			{
				A1[ind]=temp[i];
				ind++;
			}
			i++;
		}
		
		for(i=0;i<11;i++)
		{
			printf("%d\n",A1[i]);
		}
	return 0;
}

