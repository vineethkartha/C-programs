/*
 * maxdiffarray.c
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

int diff(int *a,int size)
{
	int maxdiff=a[1]-a[0];
	int min=a[0];
	int i;
	for(i=1;i<size;i++)
	{
		if((a[i]-min)>maxdiff)
		{
			maxdiff=a[i]-min;
		}
		if(a[i]<min)
			min=a[i];
	}
	return maxdiff;
}
int main(int argc, char **argv)
{
	int a[]={2, 3, 10, 6, 4, 8, 1};
	printf("Answer is %d",diff(a,7));
	return 0;
}

