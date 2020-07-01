#include<stdio.h>
float w[11][9];
int yin[9];
int Y[9];
float a,t;
void train(int x[],int z[])
{
	for(int k=0;	k<9;	k++)
			yin[k]=0;
		for(int i=0;	i<9;	i++)
		{
			for(int j=0;	j<11;	j++)
			{
				yin[i] = yin[i] + x[j]*w[j][i];
			}
			if(yin[i] >0)
				Y[i]=1;
			else if(yin[i]<0)
				Y[i]=-1;
			else
				Y[i]=0;
			printf("yin = %d , Y = %d , z = %d\n",yin[i],Y[i],z[i]);
			if(z[i]!=Y[i])
			{
				printf("Weights : ");
				for(int j=0;	j<11;	j++)
				{
					w[j][i] = w[j][i]+(x[j]*z[i]);
					printf("W[%d] = %.2f",j,w[j][i]);
				}
			}
		}
		printf("\n");
		printf("Weights after case: \n");
		for(int i=0;	i<11;	i++)
		{
			for(int j=0;	j<9;	j++) 
				printf("%.2f ",w[i][j]);
			printf("\n");
		}

}
int main(int argc,char ** argv)
{
	int n;
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%f", &a);
	t=0;
	int x[11],z[9];

	for(int k=0;	k<9;	k++)
			yin[k]=0;
	for(int i=0;	i<11;	i++)
		for(int j=0;	j<9;	j++)
			w[i][j]=0;
	for(int b=0;	b<n;	b++)
	{
		//case 1
		printf("Epoch : %d\n",b);
		printf("case 1 : \n");
		x[0]=1;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=1;		x[9]=0;	x[10]=0;			
		z[0]=1;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=0;
		train(x,z);
		//case 2
		printf("case 2 : \n");
		x[0]=0;		x[1]=1;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=1;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=1;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=0;
		train(x,z);
		//case 3
		printf("case 3 : \n");
		x[0]=0;		x[1]=0;		x[2]=1;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=1;	x[10]=1;			
		z[0]=0;		z[1]=0;		z[2]=1;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=0;	
		train(x,z);
		//case 4
		printf("case 4 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=1;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=1;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=1;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=0;
		train(x,z);
		//case 5
		printf("case 5 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=1;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=1;		x[9]=1;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=1;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=0;	
		train(x,z);
		//case 6
		printf("case 6 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=1;		x[6]=0;		x[7]=0;		x[8]=1;		x[9]=0;	x[10]=1;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=1;		z[6]=0;		z[7]=0;		z[8]=0;	
		train(x,z);
		//case 7
		printf("case 7 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=1;		x[7]=0;		x[8]=0;		x[9]=1;	x[10]=1;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=1;		z[7]=0;		z[8]=0;	
		train(x,z);
		//case 8
		printf("case 8 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=1;		x[8]=0;		x[9]=0;	x[10]=1;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=1;		z[8]=0;	
		train(x,z);

		
		
		//case 9
		printf("Epoch : %d\n",b);
		printf("case 9 : \n");
		x[0]=1;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		//case 10
		printf("Epoch : %d\n",b);
		printf("case 10 : \n");
		x[0]=0;		x[1]=1;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		//case 11
		printf("Epoch : %d\n",b);
		printf("case 11 : \n");
		x[0]=0;		x[1]=0;		x[2]=1;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		//case 12
		printf("Epoch : %d\n",b);
		printf("case 12 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=1;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		//case 13
		printf("Epoch : %d\n",b);
		printf("case 13 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=1;		x[5]=0;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		//case 14
		printf("Epoch : %d\n",b);
		printf("case 14 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=1;		x[6]=0;		x[7]=0;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		//case 15
		printf("Epoch : %d\n",b);
		printf("case 15 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=1;		x[7]=0;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		//case 16
		printf("Epoch : %d\n",b);
		printf("case 16 : \n");
		x[0]=0;		x[1]=0;		x[2]=0;		x[3]=0;		x[4]=0;		x[5]=0;		x[6]=0;		x[7]=1;		x[8]=0;		x[9]=0;	x[10]=0;			
		z[0]=0;		z[1]=0;		z[2]=0;		z[3]=0;		z[4]=0;		z[5]=0;		z[6]=0;		z[7]=0;		z[8]=1;
		train(x,z);
		
	}
	printf("\nFinal weights :\n");
	FILE *fp;
	fp=fopen("train.txt","w");
	for(int i=0;	i<11;	i++)
	{
		for(int j=0;	j<9;	j++)
			{ 
				printf("%.2f ",w[i][j]);
				fprintf(fp,"%.2f ",w[i][j]);
			}
		fprintf(fp,"\n");
		printf("\n");
	}
	printf("Epochs : %d\n",n);
	printf("Learning rate : %.2f\n",a);
	return 0;
}

