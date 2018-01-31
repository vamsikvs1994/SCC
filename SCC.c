#include<stdio.h>


int v_entry[100];

int v_exit[100];

int highest_exit[100];

int visited[100];

int sorted_list[100];

int input[100][100];

int reverse_input[100][100];

int  sorted_list[100];

int temp;
 

void VISIT (int);

int nodes;

int v=1;

int x=1;

int N=1;

int valid_paths;

int t=0;

 

void main()

{

       printf("Enter number of vertices:\t");

     scanf("%d", &nodes);

       

       for(int i = 1; i <= nodes; i++)

     {

               for(int j = 1; j <= nodes; j++)

               {

           input[i][j]=9999;

               }

               

         }

 
 input[1][6]=1;
 input[6][7]=1;
 input[7][8]=1;
 input[8][9]=1;
 input[9][5]=1;
 input[5][4]=1;
 input[4][3]=1;
 input[3][2]=1;
 input[2][1]=1;
 input[6][10]=1;
 input[10][11]=1;
 input[11][12]=1;
 input[12][13]=1;
 input[9][13]=1; 
 input[13][18]=1;
 input[18][17]=1;
 input[17][16]=1;
 input[16][15]=1; 
 input[15][14]=1;
 input[14][10]=1; 
 input[18][20]=1;
 input[19][20]=1;
 input[19][14]=1;
  
        for(v=1; v<=nodes;v++)
        {
               while(visited[v]!=1 && v<=nodes)

               {
                        printf("\n Main Visited node is %d\n",v);

                       VISIT(v);
               }
        }


 printf("The sorted topological order of nodes is as follows:\n");
      for(int j=1;j<=nodes;j++)      
{
    printf("sorted_list[%d] = %d\t",j,sorted_list[j]);
}
    

    

    
       for(int i = 1; i <= nodes; i++)

     {

               for(int j = 1; j <= nodes; j++)

               {

                reverse_input[i][j]=input[j][i];

               }

               

         }
    
    
     for(int i=nodes,j=1;j<=nodes/2;i--,j++)
        {
            highest_exit[i] = sorted_list[j];
            highest_exit[j] = sorted_list[i];
        }
    
     printf("\n\nThe nodes with highest exit values is as follows:\n");
    
      for(int j=1;j<=nodes;j++)
        {
            printf("\t highest_exit[%d] = %d\t\n",j,highest_exit[j]);
        }   

    
    for(int i=0;i<=nodes;i++){
        visited[i]=0;
    }
        
    t=1;
    
    for(int i=1; i<=nodes;i++)
        {
               while(visited[highest_exit[i]]!=1)

               {
                        printf("\n Visited node for SCC with highest exit number is %d\n",highest_exit[i]);

                       VISIT(highest_exit[i]);


               }
               
        }
    
    
    
}

 

void VISIT(int v)

{

   visited[v]=1;

   v_entry[v] =N;

   N=N+1;

   for(int j=1;j<=nodes;j++)

   {

       if(input[v][j]==1 && visited[j]!=1 && t==0)

       {
           printf("\n Visited node is %d\n",j);
           VISIT(j);


       }
        else if(reverse_input[v][j]==1 && visited[j]!=1 && t==1)

       {
           printf("\n Related nodes for SCC is %d\n",j);
           VISIT(j);


       }

   }
   
   v_exit[v]=N;
 
   N=N+1;
   sorted_list[x] = v; 
   x++;



}