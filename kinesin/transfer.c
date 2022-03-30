#include <math.h>
#include <stdio.h>

#define num1 1830
#define num2 1921
#define num 3751
#define factor 1.0
#define width 0.05
#define common 1.0 //factor of overlapped contact and sigma is similar
#define dual 1.0 //factor of overlapped contact and sigma is different
#define u1 0.05	// factor of unique contact in state1
#define u2 0.1  // factor of unique contact in state2 
#define rep (9.06573790849*0.000001)

int main()
{
	int i,j;
	int sign[num];
	int list[num][2];
	double dummy;
	double sigma[num]; 
	FILE *fp1,*fp2;

	fp1=fopen("all","r");

	for(i=0;i<num;i++)
	fscanf(fp1,"%d\t%d\t%lf\n",&list[i][0],&list[i][1],&sigma[i]);
	
	for(i=0;i<num;i++)
        sign[i] = 6;

	for(i=num1;i<num1+num2;i++)
	{
	//printf("%6d%7d 6   %11.9E   %11.9E   %11.9E   %11.9E\n",list[i][0],list[i][1],u2*factor,sigma[i],width,rep);
	}

	for(i=0;i<num1;i++)
	{
	for(j=num1;j<num1+num2;j++)
		{
		if((list[i][0]==list[j][0])&&(list[i][1]==list[j][1])) // overlapped contact
			{
			sign[i]=7;
			sign[j]=7;
			if(sqrt((sigma[i]-sigma[j])*(sigma[i]-sigma[j])) < 0.02) // if sigma too close, consider as single contact
			//printf("%6d%7d 6   %11.9E   %11.9E   %11.9E   %11.9E\n",list[i][0],list[i][1],common*factor,sigma[i],width,rep);
			printf("%6d%7d 6   %11.9E   %11.9E   %11.9E   %11.9E\n",list[i][0],list[i][1],common*factor,sigma[j],width,rep);
			else	// dual contact
				{
				dummy = sqrt((sigma[i]-sigma[j])*(sigma[i]-sigma[j]));
				//printf("%6d%7d 7   %11.9E   %11.9E   %11.9E   %11.9E   %11.9E   %11.9E\n",list[i][0],list[i][1],dual*factor,sigma[i],dummy,sigma[j],dummy,rep);
				printf("%6d%7d 7   %11.9E   %11.9E   %11.9E   %11.9E   %11.9E   %11.9E\n",list[i][0],list[i][1],dual*factor,sigma[i],width,sigma[j],width,rep);
				}
			
			break;
			}
		}
	}

	for(i=0;i<num1+num2;i++)
	if(sign[i]==6) // unique conatct
	{
		if(i<num1)
			//;
			printf("%6d%7d 6   %11.9E   %11.9E   %11.9E   %11.9E\n",list[i][0],list[i][1],u1*factor,sigma[i],width,rep);
		else
			printf("%6d%7d 6   %11.9E   %11.9E   %11.9E   %11.9E\n",list[i][0],list[i][1],u2*factor,sigma[i],width,rep);
	}

fclose(fp1);
}
