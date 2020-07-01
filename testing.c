#include<stdio.h>
void nameprinter(int i)
{
	switch(i)
	{
		case 0:	printf("Apple");break;
		case 1:	printf("Papaya");break;
		case 2:	printf("Orange");break;
		case 3:	printf("Kiwi");break;
		case 4:	printf("Pear");break;
		case 5:	printf("Lemon");break;
		case 6:	printf("Mango Green");break;
		case 7:	printf("Strawberry");break;
	}
}
int largest(float ans[])
{
	float l=ans[0];
	int index=0;
	for(int i=1;	i<8;	i++)
	{
		if(ans[i]>l)
		{
			index=i;
			l=ans[i];	
		}	
	}
	return index;
}
void main()
{
	float a;
	float ans[8];
	float tx[3],y[8];
	int tY[11];
	float w[3][8];
	float thres[8];
	FILE *fp1;
	FILE *fr;
	FILE *fw;
	fw=fopen("returnvalue.txt","w");
	fr=fopen("info.txt","r");
	fp1=fopen("training.txt","r");
	for(int i=0;	i<3;	i++)
	{
		for(int j=0;	j<8;	j++)
		{
			fscanf(fp1,"%f",&w[i][j]);
		}
	}
	fscanf(fp1,"%f",&a);
	for(int i=0;	i<8;	i++)
	{
		y[i]=0;
		thres[i]=0;
	}
	printf("\n\nTesting color:\n");
	printf("Enter input\n");
	for(int i=0;	i<3;	i++)
	{
	//	scanf("%f",&tx[i]);
		fscanf(fr,"%f",&tx[i]);
		printf("tx[%d] = %.2f\n",i+1,tx[i]);
	}
	for(int i=0;	i<8;	i++)
	{
		for(int j=0;	j<3;	j++)
		{
			y[i]=y[i]+tx[j]*a*w[j][i]*(j+1)*(j+1)*(j+1)*(j+1);
			thres[i]=thres[i]+w[j][i]*w[j][i]*(j+1)*(j+1)*(j+1)*(j+1);
		}
		printf("y =%.2f thres = %.2f ",y[i],thres[i]);
		if(y[i]>thres[i]+0.07*a)
			tY[i]=0;
		else if(y[i]<thres[i]-0.07*a)
			tY[i]=0;
		else
			tY[i]=1;
		float temp=thres[i]-y[i];
		if(temp<0)
			temp=-temp; 
		ans[i]=temp/thres[i];
		if(ans[i]<0 || ans[i] >1)
			ans[i]=1;
		printf("tY[%d] : %d",i+1,tY[i]);
		ans[i]=1.00-ans[i];
		printf(" Accuracy(");
		nameprinter(i);
		printf("):%.2f\n",ans[i]);
	}


	int z[9],threshold[9];
	int tZ[9];
	float W[11][9];
	FILE *fp2;
	float returnvalue=0.0;
	fp2=fopen("train.txt","r");
	for(int i=0;	i<11;	i++)
	{
		for(int j=0;	j<9;	j++)
		{
			fscanf(fp2,"%f",&W[i][j]);
		}
	}
	for(int i=0;	i<9;	i++)
	{
		z[i]=0;
		threshold[i]=0;
	}
	printf("\n\nTesting shape:\n");
	printf("Enter input\n");
	for(int i=8;	i<11;	i++)
	{
	//	scanf("%d",&tY[i]);
		fscanf(fr,"%d",&tY[i]);
		printf("ty[%d] = %d\n",i-7,tY[i]);
	}
	for(int i=0;	i<9;	i++)
	{
		for(int j=0;	j<11;	j++)
		{
			z[i]=z[i]+tY[j]*W[j][i];
			threshold[i]=threshold[i]+W[j][i]*W[j][i];
		}
		if(z[i]==threshold[i])
			tZ[i]=1;
		else
			tZ[i]=0;
		printf("%d ",tZ[i]);
	}
	printf("\n");
	int sum=0;
	for(int i=0;	i<8;	i++)
		sum=sum+tY[i];
	if(sum>1 || tY[8]==0 && tY[9]==0 && tY[10]==0 || tY[8]==1 && tY[9]==1 && tY[10]==1)
	{
		fprintf(fw,"%.2f",returnvalue);
		return ;
	}
	for(int i=0;	i<8;		i++)
	{
		if(tZ[i]==1)
		{
			returnvalue=(i+1)/1.0;
			fprintf(fw,"%.2f",returnvalue);
			return ;
		}
		
	}
	int index=largest(ans);
	if(ans[index]>=0.95)
		returnvalue=8+index+ans[index];
	fprintf(fw,"%.2f",returnvalue);
	return ;
}


