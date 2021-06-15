#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_book {
	char name[30];
	char category[30];
	int code;
	int copies;
	float price;
    struct node_book *next;
}Node;


typedef struct Book
{
	char name[30];
	char category[30];
	int code;
	int copies;
	float price;
}book;
Node *head = NULL, *end = NULL;


void Append();


void main(){

}
void Append()
{
     FILE *file ;
    file= fopen("books.txt","rb");
    if(file==NULL)
    {
        printf("file not available\n");
        exit(1);
    }


    while( 1 ){
Node *bk = malloc(sizeof(Node));
    if( fread(&bk->category,sizeof(bk->category),1,file)==0 )return;
    fread(&bk->code,sizeof(bk->code),1,file);
    fread(&bk->copies,sizeof(bk->copies),1,file);
    fread(&bk->name,sizeof(bk->name),1,file);
    fread(&bk->price,sizeof(bk->price),1,file);
bk->next=NULL;
        if(head == NULL){head = bk; end=bk;}

        end->next=bk;
        end=end->next;
printf("done\n\n");
        }
   end->next = NULL ;


        printf("end\n\n");
    fclose(file);
 }


