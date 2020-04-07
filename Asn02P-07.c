#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
int c[2][2];
void pow_mul(int a[],int b[],int d[][2])
{
	static int x = 0,y = 0;
	if(x >= 2)
		return;
	if(y < 2)
	{
		b[x] += a[y] * d[y][x];
		y++;
		pow_mul(a,b,d);					
	}
	y = 0;
	x++;
	pow_mul(a,b,d);
}

int power(int n)
{
	static int a[][2] = {0,1,1,1},F[2] = {0,1},t[2]= {0},b[][2] = {0,1,1,1};
	int c[2][2] = {0};
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
			for(int k = 0;k<2;k++)
				c[i][j] += a[i][k]*b[k][j];
	memcpy(a,c,sizeof(a));
	n--;
	if(n == 1)
		{
			pow_mul(F,t,c);	
			return(t[0]);
		}
	power(n--);
}
  
int main(int argc, char* argv[]) 
{ 
  	int n = atoi(argv[1]); 
	if(argc == 2 && atoi(argv[1]) > 0)
	{
 		if(n == 1)
			printf("F(%d) = 1\n",n);
  		else
			printf("F(%d) = %d\n",n,power(n)); 
  		return 0; 
	}
	else
	{
		printf("Invalid input ..!  or Enter './a.out 5(any number)' \n");
			exit(0);
	}
} 
