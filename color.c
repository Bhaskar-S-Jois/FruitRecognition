#include<stdio.h>
float w[3][8];
float yin[8];
float thres[8];
int Y[8];
float a,t;
void train(float x[],int z[])
{
	for(int k=0;	k<8;	k++)
	{
		thres[k]=0;
		yin[k]=0;
	}
		for(int i=0;	i<8;	i++)
		{
			for(int j=0;	j<3;	j++)
			{
				thres[i]=thres[i]+x[j]*x[j]*(3-j)*(3-j)*(3-j)*(3-j);
				yin[i] = yin[i] + x[j]*w[j][i]*(3-j)*(3-j)*(3-j)*(3-j);
			}
		
			if(yin[i] >thres[i]*a-0.07&&yin[i] <thres[i]*a+0.07)
				Y[i]=1;
			else 
				Y[i]=0;
			printf("yin = %.2f , Y = %d , z = %d\n",yin[i],Y[i],z[i]);
			if(z[i]!=Y[i])
			{
				printf("Weights : ");
				for(int j=0;	j<3;	j++)
				{
					w[j][i] = w[j][i]+(a*x[j]*z[i]);
					printf("W[%d] = %.2f",j,w[j][i]);
				}
			}
		}
		printf("\n");
		printf("Weights after case: \n");
		for(int i=0;	i<3;	i++)
		{
			for(int j=0;	j<8;	j++) 
				printf("%.2f,",w[i][j]);
			printf("\n");
		}

}
int main(int argc,char * argv[])
{
	int n;
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%f", &a);
	t=0;
	float x[3];
	int z[8];

	for(int k=0;	k<8;	k++)
			yin[k]=0;
	for(int i=0;	i<3;	i++)
		for(int j=0;	j<8;	j++)
			w[i][j]=0;
	for(int b=0;	b<n;	b++)
	{
		//case 1
		printf("Epoch : %d\n",b);
		printf("case 1 : \n");
		x[0]=0.70;		x[1]=0.16;		x[2]=0.14;		
		z[0]=1;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;	
		train(x,z);
		//case 2
		printf("Epoch : %d\n",b);
		printf("case 2 : \n");
		x[0]=0.5;		x[1]=0.34;		x[2]=0.16;		
		z[0]=0;		z[1]=1;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;	
		train(x,z);
		//case 3
		printf("Epoch : %d\n",b);
		printf("case 3 : \n");
		x[0]=0.625;		x[1]=0.32;		x[2]=0.056;		
		z[0]=0;		z[1]=0;		z[2]=1;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		
		train(x,z);		
		//case 4
		printf("Epoch : %d\n",b);
		printf("case 4 : \n");
		x[0]=0.445;		x[1]=0.34;		x[2]=0.22;		
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=1;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;	
		train(x,z);		
		//case 5
		printf("Epoch : %d\n",b);
		printf("case 5 : \n");
		x[0]=0.55;		x[1]=0.282;		x[2]=0.167;		
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=1;		z[5]=0;		z[6]=0;		z[7]=0;		
		train(x,z);		
		//case 6
		printf("Epoch : %d\n",b);
		printf("case 6 : \n");
		x[0]=0.49;		x[1]=0.38;		x[2]=0.12;		
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=1;		z[6]=0;		z[7]=0;	
		train(x,z);		
		//case 7
		printf("Epoch : %d\n",b);
		printf("case 7 : \n");
		x[0]=0.32;		x[1]=0.4;		x[2]=0.27;		
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=1;		z[7]=0;		
		train(x,z);		
		//case 8
		printf("Epoch : %d\n",b);
		printf("case 8 : \n");
		x[0]=0.66;		x[1]=0.18;		x[2]=0.15;		
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=1;		
		train(x,z);
	}
	printf("\nFinal weights :\n");
	FILE *fp;
	fp=fopen("training.txt","w");
	for(int i=0;	i<3;	i++)
	{
		for(int j=0;	j<8;	j++)
			{ 
				printf("%.2f ",w[i][j]);
				fprintf(fp,"%.2f ",w[i][j]);
			}
		fprintf(fp,"\n");
		printf("\n");
	}
	fprintf(fp,"%.2f ",a);
	printf("Epochs : %d\n",n);
	printf("Learning rate : %.2f\n",a);
	return 0;
}
