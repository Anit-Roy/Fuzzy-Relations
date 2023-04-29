#include<stdio.h>
#include<stdlib.h>

void initialize();
void maxminforcompositerelation();

float *a,*b,*c;
int sizedata[3];
float **RAB, **RBC,**RAC;
 
int main()
{
    initialize();
    maxminforcompositerelation();
    showrelations();
    return 0;
}

void initialize()
{
    int i,j;

/* get number of elements in fuzzy set A*/
    printf("Number of elements in fuzzy set A:?");
    scanf("%d", &sizedata[0]);
/* get number of elements in fuzzy set B*/
    printf("Number of elements in fuzzy set B:?");
    scanf("%d", &sizedata[1]);
/* get number of elements in fuzzy set C*/
    printf("Number of elements in fuzzy set C:?");
    scanf("%d", &sizedata[2]);
    
/*Allocate memories for storing membership degrees for each set, according to their number of elements*/
    a=(float *)malloc(sizedata[0]*sizeof(float));
    b=(float *)malloc(sizedata[1]*sizeof(float));
    c=(float *)malloc(sizedata[2]*sizeof(float));

/* scan the degrees of membership elementwise, setwise first of set A then B followed by elements of C*/
    for(i=0;i<3;i++)
    {
   	 printf("Enter degree of membership for %d elements of %c:", sizedata[i], 65+i);
   	 
    if(i==0){
   	 for(j=0;j<sizedata[i];j++)
   		 scanf("%f", &a[j]);
    }
    if(i==1){
   	 for(j=0;j<sizedata[i];j++)
   		 scanf("%f", &b[j]);
    }
    if(i==2){
   	 for(j=0;j<sizedata[i];j++)
   		 scanf("%f", &c[j]);
    }
    }

/*Allocate memory for storing relationship matrix A x B of relationship from A to B*/
    RAB=(float **)malloc(sizedata[0]*sizeof(float*));
    for(i=0;i<sizedata[0];i++)
   	 RAB[i]=(float *)malloc(sizedata[1]*sizeof(float));

/*Allocate memory for storing relationship matrix B x C of relationship from B to C*/
    RBC=(float **)malloc(sizedata[1]*sizeof(float*));
    for(i=0;i<sizedata[1];i++)
   	 RBC[i]=(float *)malloc(sizedata[2]*sizeof(float));

/*Allocate memory for storing relationship matrix A x C of composite relation from A to C via B*/
    RAC=(float **)malloc(sizedata[0]*sizeof(float*));
    for(i=0;i<sizedata[0];i++)
   	 RAC[i]=(float *)malloc(sizedata[2]*sizeof(float));
}

void maxminforcompositerelation()
{
/*
    code for max-min rule evaluation for composite relation from A to C
*/
for(int i=0;i<sizedata[0];i++){
	for(int j=0;j<sizedata[1];j++){
    	if(a[i]<=b[j]){
        	RAB[i][j]=a[i];
       	 
    	}
    	else{
        	RAB[i][j]=b[j];
    	}
    	//printf("%.4f \n",RAB[i][j]);
	}
}
for(int i=0;i<sizedata[1];i++){
	for(int j=0;j<sizedata[2];j++){
    	if(b[i]<=c[j]){
        	RBC[i][j]=b[i];
       	 
    	}
    	else{
        	RBC[i][j]=c[j];
    	}
   	// printf("%.4f \n",RBC[i][j]);
	}
for(int i=0;i<sizedata[0];i++){
	for(int j=0;j<sizedata[2];j++){
    	if(RAB[i][j]>=RBC[i][j]){
        	RAC[i][j]=RAB[i][j];
    	}
    	else{
        	RAC[i][j]=RBC[i][j];
    	}
    	//printf("%.4f \n",RAC[i][j]);
	}
}
}
}

void showrelations()
{
int i,j;
for(printf("\n\t Relation matrix for AxB:\n"), i=0;i<sizedata[0];i++)
{
   for(j=0;j<sizedata[1];j++)
  	printf("%.4f  ", RAB[i][j] );
   printf("\n");

}

for(printf("\n\t Relation matrix for BxC:\n"), i=0;i<sizedata[1];i++)
{
   for(j=0;j<sizedata[2];j++)
  	printf("%.4f  ", RBC[i][j] );
   printf("\n");

}

for(printf("\n\t Relation matrix for composite relatoin AxC via B:\n"), i=0;i<sizedata[0];i++)
{
   for(j=0;j<sizedata[2];j++)
  	printf("%.4f  ", RAC[i][j] );
   printf("\n");

}

}
