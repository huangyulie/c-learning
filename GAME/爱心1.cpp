#include<stdio.h>
int main()
{
	int n;
	int a[100];
	scanf("%d",&n);
	int i,j,k;
	int flag=0;
	int sum=0;
	int max=0;
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			for(k=j+1;k<n;++k)
			{
				if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])
				{
					sum=a[i]+a[k]+a[j];
					if(sum>max)
					max=sum;
					flag=1;
				}
			}
		}
	}
	if(flag==1)
	{
		printf("%d",max);
	}
	else if(flag==0)
	{
		printf("0");
	}
}
