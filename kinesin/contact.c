#include <stdio.h>
#include <math.h>

#define num1 1830
#define num2 1921
#define snap 5000
#define res 316
#define cut 1.1

int main()
{
	int i,j,m,n,Q1,Q2;
	int list1[num1][2];
	int list2[num2][2];
	double sigma1[num1];
	double sigma2[num2];
	double coor[res][3];
	double X,dist;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;

	fp1=fopen("A","r");
	fp2=fopen("B","r");
	fp3=fopen("coord.dat","r");
	fp4=fopen("Q1.dat","w");
	fp5=fopen("Q2.dat","w");

	for(i=0;i<num1;i++)
	fscanf(fp1,"%d\t%d\t%lf\n",&list1[i][0],&list1[i][1],&sigma1[i]);

	for(i=0;i<num2;i++)
        fscanf(fp2,"%d\t%d\t%lf\n",&list2[i][0],&list2[i][1],&sigma2[i]);

	for(i=0;i<snap;i++)
	{
		for(j=0;j<res;j++)
		{
		fscanf(fp3,"%lf\t%lf\t%lf\n",&coor[j][0],&coor[j][1],&coor[j][2]);
		}

		Q1 = 0;
		Q2 = 0;

		for(j=0;j<num1;j++)
		{
		m = list1[j][0] - 1 ;
		n = list1[j][1] - 1 ;
		dist = sqrt((coor[m][0]-coor[n][0])*(coor[m][0]-coor[n][0])+(coor[m][1]-coor[n][1])*(coor[m][1]-coor[n][1])+(coor[m][2]-coor[n][2])*(coor[m][2]-coor[n][2]))/10.0;
		if((dist < (sigma1[j]*cut))&&(dist > sigma1[j]*(2.0-cut))) Q1++;
		}

		for(j=0;j<num2;j++)
                {
                m = list2[j][0] - 1 ;
                n = list2[j][1] - 1 ;
                dist = sqrt((coor[m][0]-coor[n][0])*(coor[m][0]-coor[n][0])+(coor[m][1]-coor[n][1])*(coor[m][1]-coor[n][1])+(coor[m][2]-coor[n][2])*(coor[m][2]-coor[n][2]))/10.0;
                if((dist < (sigma2[j]*cut))&&(dist > sigma2[j]*(2.0-cut))) Q2++;
                }

		fprintf(fp4,"%lf\n",(double)Q1/(double)num1);
		fprintf(fp5,"%lf\n",(double)Q2/(double)num2);
	}	

fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
fclose(fp5);
}
