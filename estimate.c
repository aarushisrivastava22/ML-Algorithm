

#include <stdio.h>
#include <stdlib.h>
   double** transposeresult;
   double** transpose(double**matrix_x, int numhouses,int numattributes);
   double** finalresultmultiplyc; 
   double** finalresultmultiplyd; 
   double** multiply1(double ** matrix_x, double ** transposeresult,int numhouses, int numattributes); 
   double ** inversearray; 
   double ** inverse(double ** finalresultmultiplyc, int numhouses, int numattributes); 
   double**multiply2(double** matrix_y, double** transposeresult, int numhouses, int numattributes);
   double ** multiply3(double**inversearray, double**finalresultmultiplyd, int numhouses, int numattributes); 
   double ** finalresultmultiplye;
   double ** multiply4(double ** matrix_xdata, double ** finalresultmultiplye, int numhouses2, int numattributes); 
   double ** finalresult;   
int main(int argc, char **argv)
{
   FILE * fptr;
   FILE * fptr2; 
   int  numattributes;
   numattributes = 0;  
   int numhouses; 
   numhouses = 0;
   char bat[7];  
   char bat2[7]; 
   int numhouses2;
   numhouses2 =0;  
   int numattributes2;
   numattributes2 =0;
   //transposeresult= (double**)malloc((numattributes+1)*sizeof(double*));
 
   //double matrix_xnum;
  // double ** matrix_x = (double**) malloc(numhouses*sizeof(double*));  
   //argv[1] would be train.txt file  
   // to makesure the count is not less than 3   
    /*if(argc<3) 
    {
       printf("error"); 
       return 0 ; 
     } */ 
   fptr = fopen(argv[1], "r"); 
   if(fptr == NULL)
   {
      return 0; 

    }
    fscanf(fptr, "%s\n", bat); 
    fscanf(fptr, "%d\n", &numattributes); 
    fscanf(fptr, "%d\n", &numhouses); 
   // printf("The number of attributes: "); 
   // printf ("%d", numattributes);
   // printf("\n");  
   // printf("The number of houses: "); 
    //printf("%d", numhouses);
  
     transposeresult= (double**)malloc((numattributes+1)*sizeof(double*));
     finalresultmultiplyc = (double**)malloc((numattributes+1)*sizeof(double*));
     inversearray = (double**)malloc((numattributes+1)*sizeof(double*));  
     finalresultmultiplyd = (double**)malloc((numattributes+1)*sizeof(double*));
     finalresultmultiplye = (double**)malloc((numattributes+1)*sizeof(double*));  
      finalresult = (double**)malloc((numattributes+1)*sizeof(double*)); 
    double ** matrix_y; 
    matrix_y = (double**) malloc((numhouses)*sizeof(double*)); 
    int c1;
    //int d1; 
    for(c1 =0; c1< numhouses; c1++)
    {
       matrix_y[c1] = (double*)malloc(1*sizeof(double));    
    } 
 // Allocate space for matrix x which be number of houses * attributes +1; 
      double ** matrix_x; 
     matrix_x = (double**) malloc(numhouses*sizeof(double*));
    int a1;
    int b1;  
    for(a1 = 0; a1 < numhouses; a1++) 
    {
      matrix_x[a1] = (double*)malloc((numattributes+1)*sizeof(double));
     for(b1 = 0; b1<(numattributes+1); b1++)
     {  
         if(b1 == 0)
         {
            matrix_x [a1][0] = 1; 
          }  
         else {
          fscanf(fptr, "%lf" , &matrix_x[a1][b1]);  
         } 
    }
             fscanf(fptr, "%lf", &matrix_y[a1][0]);

    }

      transposeresult =transpose(matrix_x,numhouses, numattributes);  

    /*printf("Print matrix."); 
     printf("\n"); 
     int i; int j; 
     for(i = 0; i<numhouses; i++)
     { 
       for(j=0; j<(numattributes+1); j++)
       {

         printf("%lf\t",matrix_x[i][j]); 

       }
       printf("\n"); 
     }
      printf("Print transpose matrix."); 
      printf("\n"); 
     int m1; 
     int n1; 
     for(m1 =0; m1< numattributes+1; m1++)
     {
        for(n1 =0; n1<numhouses; n1++)
      {

          printf("%lf\t", transposeresult[m1][n1]); 

      }
     printf("\n"); 
    }*/

    finalresultmultiplyc = multiply1(matrix_x,transposeresult,numhouses, numattributes);
    inversearray= inverse(finalresultmultiplyc, numhouses, numattributes); 
    finalresultmultiplyd = multiply2(matrix_y, transposeresult, numhouses, numattributes);
    finalresultmultiplye = multiply3(inversearray, finalresultmultiplyd, numhouses, numattributes);    
    //printf("Print price matrix22."); 
    //printf("\n"); 
    /* int p;  
    for(p=0; p<numhouses; p++)
    {
          printf("%lf\t",matrix_y[p][0]);
          printf("%d",p);
          printf("\n");  
    } */
     fclose(fptr);    
     fptr2= fopen(argv[2], "r"); 
     if(fptr2 == NULL)
     {
       return 0; 
     }
     
     fscanf(fptr2, "%s\n", bat2); 
     fscanf(fptr2, "%d\n", &numattributes2); 
     fscanf(fptr2, "%d\n", &numhouses2);  
     //Allocate space for the data file 
     double ** matrix_xdata; 
     matrix_xdata = (double**) malloc(numhouses2*sizeof(double*)); 
     int e1; 
     int d1; 
     for(e1 = 0; e1<numhouses2; e1++)
     {
        matrix_xdata[e1] = (double*)malloc((numattributes2+1)*sizeof(double)); 
       for(d1 =0; d1< (numattributes2+1); d1++)
      {    if(d1 == 0)
          {
             matrix_xdata[e1][0] = 1; 
          }
           else   {
             fscanf(fptr2, "%lf", &matrix_xdata[e1][d1]); 
           }

      }
     }
     finalresult = (double**) malloc(numhouses2*sizeof(double*)); 
     finalresult = multiply4(matrix_xdata, finalresultmultiplye, numhouses2, numattributes); 
     
     //Now print matrix data file 
     /*printf("\n"); 
     printf("Print matrix data attributes");
     printf("\n");  
     int p1; 
     int q1; 
     for(p1 =0; p1<numhouses2; p1++)
     {
       for(q1=0; q1<(numattributes2 +1); q1++)
       {
          printf("%lf\t", matrix_xdata[p1][q1]);
         }
        printf("\n"); 
     }*/ 
     fclose(fptr2);
    return 0;  
}

// Tranpose function
double ** transpose(double**matrix_x, int numhouses, int numattributes){
//double ** transposeresult= (double**)malloc((numattributes+1)*sizeof(double*));
// double ** transposeresult= (double**)malloc((numattributes+1)*sizeof(double*));
     int t;
      //int y;
      for(t=0; t<(numattributes+1); t++)
     {
     transposeresult[t] = (double*)malloc(numhouses*sizeof(double));

      }  
int t1; 
int y1; 
for( t1= 0; t1< (numattributes+1); t1++)
{

   for(y1 = 0; y1< numhouses; y1++)
   {
      transposeresult[t1][y1] = matrix_x[y1][t1];  
   }
}

return transposeresult;  

}

//Multiplication function
double ** multiply1(double ** matrix_x, double ** transposeresult,int numhouses,int numattributes )
{
int m2;
//int n2; 
for(m2=0; m2<numattributes+1; m2++)
{
  finalresultmultiplyc[m2] = (double*)malloc(numhouses*sizeof(double)); 
} 
int h; 
int g; 
int g1; 
for(h=0; h<numattributes+1; h++)
{
   for(g =0 ; g<numattributes+1; g++) {
   finalresultmultiplyc[h][g] = 0; 
    for(g1=0; g1<(numhouses) ; g1++) 
      {
        finalresultmultiplyc[h][g] = finalresultmultiplyc[h][g] + transposeresult[h][g1] * matrix_x[g1][g]; 
      } 
  }
 
}
/*printf("Print X^T *X"); 
printf("\n"); 
int u1;
int i1; 
for(u1=0; u1<numattributes+1; u1++)
{
 for(i1=0; i1<numattributes+1; i1++)
 {
   printf("%lf\t" ,finalresultmultiplyc[u1][i1]); 
 }
 printf("\n"); 

}*/ 
return finalresultmultiplyc; 
}

double** multiply2(double**matrix_y, double** transposeresult, int numhouses, int numattributes)
{
int n2; 
for(n2=0; n2 <(numattributes+1); n2++)
{
  finalresultmultiplyd[n2] = (double*)malloc(1*sizeof(double)); 
}
int a10;
int a11;
a10 = 0;
int a12=0;
  for (a12=0; a12<(numattributes+1);a12++)
  {
    finalresultmultiplyd[a10][0] = 0; 
    for(a11=0; a11<(numhouses); a11++)
     {
      finalresultmultiplyd[a10][0] = finalresultmultiplyd[a10][0] + (transposeresult[a10][a11] * matrix_y[a11][0]);
     } 
      a10++;
   } 

/*printf("Print Tranpose * y result");
printf("\n");  
int u6;
int i6 = 0;
 
 for(u6 =0; u6<(numattributes+1); u6++)
 {
    printf("%lf", finalresultmultiplyd[u6][i6]); 
    printf("\n"); 
  }*/ 
return finalresultmultiplyd;
}
double **multiply3(double**inversearray, double** finalresultmultiplyd, int numhouses, int numattributes)
{
int n3;
for(n3=0; n3<(numattributes+1); n3++)
{
  finalresultmultiplye[n3] = (double*)malloc(1*sizeof(double)); 
}
int a13;
int a14; 
int a9;
a9 =0; 
for(a13=0; a13<(numattributes+1); a13++)
{
  finalresultmultiplye[a9][0]=0;
  for(a14 =0; a14<(numattributes+1); a14++)
  {
   finalresultmultiplye[a9][0] = finalresultmultiplye[a9][0] + (inversearray[a9][a14] * finalresultmultiplyd[a14][0]); 
    } 

   a9++;

} 

/*printf("Print Inverse * finalresultd"); 
printf("\n");
int u7;
int i7 =0; 
for(u7=0; u7<(numattributes+1); u7++)
{
   printf("%lf", finalresultmultiplye[u7][i7]); 
  printf("\n"); 

}*/ 
return finalresultmultiplye;  
}

//inverse function
double ** inverse(double ** finalresultmultiplyc, int numhouses, int numattributes)
{ 
//M is finalresultmultiplyc 
//inversearray (N) is identity matrix 
// Augement Matrix
int i2; 
//int j2; 

for(i2 = 0; i2<numattributes+1; i2++)
{    inversearray[i2] = (double*)malloc(((numattributes+1))*sizeof(double)); 
   
}
//printf("viurus"); 
//int d3; 
 
 
//Augmented Matrix 
int k2;
int g2;   
//int b2; 
for(k2=0; k2<numattributes+1; k2++) 
{
 for(g2 = 0; g2<(numattributes+1); g2++)

  {
  if(k2 == g2)
  { 
   inversearray[k2][g2] = 1;
   }
  else {
     inversearray[k2][g2]= 0; 
   }
 } 
}
//Print identity matrix
//printf("Print identity matrix " );
//printf("\n"); 
//int g3;
//int b3; 
//for(g3=0; g3<numattributes+1; g3++)
//{
// for(b3= 0; b3<(numattributes+1); b3++)
// {
//   printf("%lf\t", inversearray[g3][b3]); 
//
// }
//printf("\n"); 
//}

double entry1;
double entry2;  
int p; 
int p2; 
int p3;
int p4; 
int p5; 
int i9;
int p8;
int p9; 
double entry3;    
for(p=0; p<numattributes+1; p++)
{ 
   entry1 = finalresultmultiplyc[p][p];
  
  for(p2 = 0; p2 < (numattributes+1); p2++)
  { 
     finalresultmultiplyc[p][p2] = finalresultmultiplyc[p][p2] / (entry1);
    }
   for(p3 = 0; p3 <(numattributes+1); p3++)
   {
     inversearray[p][p3] = inversearray[p][p3] / (entry1); 
    
   }

   for(i9 = p + 1; i9 < numattributes+1 ;i9++)
   {
   entry2 = finalresultmultiplyc[i9][p]; 

    for(p4 =0; p4<(numattributes+1); p4++)
    {  
       finalresultmultiplyc[i9][p4] = finalresultmultiplyc[i9][p4] - (entry2*finalresultmultiplyc[p][p4]);
    }
    for(p5 =0; p5<(numattributes+1); p5++)
    { 
      inversearray[i9][p5] = inversearray[i9][p5] - entry2*inversearray[p][p5]; 
     } 
    }
  }
 
//int ix1;
//int ix2;
//for(ix1=0 ; ix1<numattributes+1; ix1++)
//{
// for (ix2=0; ix2 <(numattributes+1); ix2++)
// {
//   printf("%lf\t", finalresultmultiplyc[ix1][ix2]); 
// }
// printf("\n"); 
//}
//
//printf("\n"); 
 
   
  for(p = (numattributes+1) -1; p>=0; p--)
  {
    for(i9 = p-1; i9>=0; i9--)
    {
       entry3 = finalresultmultiplyc[i9][p];
       
       for( p8 =0; p8<(numattributes+1); p8++)
       {
        finalresultmultiplyc[i9][p8] = finalresultmultiplyc[i9][p8] - (entry3*finalresultmultiplyc[p][p8]) ; 
       } 
      for( p9 =0; p9<(numattributes+1); p9++)
       {
       inversearray[i9][p9] = inversearray[i9][p9] - (entry3*inversearray[p][p9]); 
       }
   }

 }

//printf("Print final matrix2."); 
//printf("\n"); 
//int ix11;
//int ix12;
//for(ix11 =0; ix11<numattributes+1; ix11++)
//{
// for(ix12=0; ix12<(numattributes+1); ix12++)
// {
//  printf("%lf\t", finalresultmultiplyc[ix11][ix12]); 
// }
//printf("\n"); 
//} 
//
//printf("\n"); 
//
/*printf ("Print inverser array: ");
int index1;
int index2; 
for(index1 = 0; index1<numattributes+1; index1++)
{
 for(index2 =0; index2<(numattributes+1); index2++)
 {
    printf("%lf\t", inversearray[index1][index2]); 

  }
printf("\n"); 
} */ 

return inversearray;

} 

double ** multiply4(double** matrix_xdata, double ** finalresultmultiplye, int numhouses2, int numattributes)
{

int n5;
for(n5 =0; n5<(numhouses2); n5++)
{
  finalresult[n5] = (double*)malloc(1*sizeof(double)); 
}
int a22;
int a23;
int a41; 
a41 = 0; 
for(a22 =0; a22<(numhouses2); a22++)
{

   finalresult[a41][0] = 0; 
  for(a23=0; a23<(numattributes+1); a23++)
 {
      finalresult[a41][0] = finalresult[a41][0] + (matrix_xdata[a41][a23] * finalresultmultiplye[a23][0]); 
  }
 a41++; 
}
//printf("\n"); 
//printf("Print final matrix3333!!"); 
//printf("\n"); 
int u34;
int i34 =0; 
for(u34 = 0; u34<numhouses2; u34++)
{
  printf("%0.0lf\n", finalresult[u34][i34]);
  //printf("\n");  
}
printf("\n"); 
return finalresult; 
}






