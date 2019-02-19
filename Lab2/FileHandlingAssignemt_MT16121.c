#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Lab 2 assignment submitted by:

                                    Ankit Sharma - MT16121
                                    Ankit Rehani - MT16085

*/

struct llistnode
{
    char name[100];
    int marks;
};
typedef struct llistnode Node;

void mysort(Node* myarr[1000],int len);

Node* arr[1000];

int main(int z,char* argv[]) {
    char n[100];
    int avg;
    int i,m,linecount=0,in=0,total=0;
    FILE* fptr;
    FILE* fptro;
    fptr = fopen(argv[1],"r");
    while(!feof(fptr)){
                fscanf(fptr,"%s %d",n,&m);
                total=total+m;
                Node * ptr=(Node*)malloc(sizeof(Node));
                strcpy(ptr->name,n);
                ptr->marks=m;
                arr[in]=ptr;
                in++;
                linecount++;
            }
                fclose(fptr);
                mysort(arr,linecount);
                avg=total/linecount;
                fptro = fopen(argv[2],"w");
                for(i=0;i<linecount;i++)
                {
                  fprintf(fptro,"%s %d\n",arr[i]->name,arr[i]->marks);
                }
                fprintf(fptro,"%s %d\n","Average Marks are-",avg);
                fclose(fptro);
                return 0;

        }
void mysort(Node* myarr[1000],int length)
{
    int j,k;
    int temp;
    for(j=0;j<length;j++)
    {
        for(k=j;k<length;k++)
        {
          if((myarr[k]->marks)>=(myarr[j]->marks))
            {
               temp=myarr[j];
               myarr[j]=myarr[k];
               myarr[k]=temp;
            }
        }
    }
}
