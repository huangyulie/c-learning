#include<stdio.h>
#include<string.h>


char left[3][7];
char right[3][7];
char result[3][7];
bool isfake(char c,bool light);

int main()
{
	char c;
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;++i)
	{
		for(j=0;j<3;++j)
		{
			scanf("%s %s %s",&left[j],&right[j],&result[j]);
		}
		for(c='A';c<='L';++c)
		{
			if(isfake(c,true))
			{
				printf("%c is the counterfeit coin and it is light.\n",c);
				break;
			}
			else if(isfake(c,false))
			{
				printf("%c is the counterfeit coin and it is light.\n",c);
				break;
			}
		}
	}
 } 
 
bool isfake(char c,bool light)
{
	int i;
	for(i=0;i<3;++i)
	{
		char *pleft,*pright;
		if(light)
		{
			pleft=left[i];
			pright=right[i];
		}
		else
		{
			pleft=right[i];
			pright=left[i];
		}
		switch(result[i][0])
		{
			case 'u':
				if(strchr(pright,c)==NULL)
				return false;
				break;
			case 'e':
				if(strchr(pleft,c) || strchr(pright,c))
				return false;
				break;
			case 'd':
				if(strchr(pleft,c)==NULL)
				return false;
				break;
		}
	}
	return true;
}
