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
Node *curr = NULL;

void Append();

void printList();
void deleteNode();
int length();
void print_node(Node *);

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

void printList() {
   curr=head;

   //start from the beginning
   while(curr!=NULL) {
      printf("name: %-12s\tcategory: %-12s\tcode number: %3d\tprice: %7.2f\tcopies: %2d\n",curr->name,curr->category,curr->code,curr->price, curr->copies);
      curr = curr->next;
   }
   }
   
   
   void print_node(Node *current){
      printf("name: %-12s\tcategory: %-12s\tcode number: %3d\tprice: %7.2f\tcopies: %2d\n",current->name,current->category,current->code,current->price, current->copies);
 }
 
 
   int length() {
   int length=0;
   Node *leng;
leng=head;
   while(leng!=NULL){
    length++;
    leng=leng->next;
   }

   return length;
}

   
void deleteNode(){

   if(head == NULL) {
      printf("\nthe library is empty\n\n");
      return;
   }

   int code;
   printf("please enter the code of the book: ");
   scanf("%d", &code);

   Node *pre=NULL, *current=head;

   while(current->code != code) {
      if(current->next == NULL){
         printf("\nthis code is invalid\n");
         return;
      }
       else
         {
         pre = current;
         current = current->next;
         }
   }
   printf("\nfound book\n");

    print_node(current);

    if(current==head)head=head->next;
    else pre->next = current->next;

    free(current);
}