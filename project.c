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



Node *head = NULL, *end = NULL;
Node *curr = NULL;

void Append();

void printList();
void deleteNode();
int length();
void print_node(Node *);
int find(int code);
int findName(char name[]);
void update();
void updateName(char name[]);
void insert();

void main(){
Append();
printf("welcome to the library\nwhat do you want to day\n1- add new book\n2- show books\n3- number of books\n4- search\n5- update data of a book\n6- delete book****if you want to end this programm please click zero\n");
    unsigned int choice;
    scanf("%u", &choice);

    while (choice != 0) {


     switch (choice) {
     case 1:
     insert();
     break;

     case 2:
        printList();
        break;
     case 3:
        printf("%d\n\n", length());
        break;
     case 4:
        printf("enter the code of the book");
        int code;
        scanf("%d", &code);
        find(code);
        print_node(curr);
        break;
     case 5:
        update();
        break;
     case 6:
        deleteNode();
        break;
     default :
        printf("invalid input");
        break;
     }
        printf("do you want to do any thing else?\n1- add new book\n2- show books\n3- number of books\n4- search\n5- update data of a book\n6- delete book ****if you want to end this programm please click zero\n");
        scanf("%u", &choice);
     }

FILE *file1;

   file1=fopen("books.txt","wb+");

    curr=head;
    while(curr!=NULL){
    fwrite(&curr->category,sizeof(curr->category),1,file1);
    fwrite(&curr->code,sizeof(curr->code),1,file1);
    fwrite(&curr->copies,sizeof(curr->copies),1,file1);
    fwrite(&curr->name,sizeof(curr->name),1,file1);
    fwrite(&curr->price,sizeof(curr->price),1,file1);

        curr=curr->next;
    }

    fclose(file1);


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
    if( fread(&bk->category,sizeof(bk->category),1,file)==0 )break;
    fread(&bk->code,sizeof(bk->code),1,file);
    fread(&bk->copies,sizeof(bk->copies),1,file);
    fread(&bk->name,sizeof(bk->name),1,file);
    fread(&bk->price,sizeof(bk->price),1,file);
bk->next=NULL;
        if(head == NULL){head = bk; end=bk;}

        end->next=bk;
        end=end->next;

        }
   end->next = NULL ;


        
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
int find(int code) {


   if(head == NULL) {
      printf("\nthe library is empty\n\n");
      return 1;
   }

   Node *current = head;

   while(current->code != code) {
      if(current->next == NULL){
         printf("\nthis code doesn't exist");
         return 1;
      }
       else
         current = current->next;
   }
   printf("\nfound book\n");

    curr=current;
   return 0;
}

int findName(char name[30]){
Node *bk = head;
while( bk != NULL){
    if(strcmp(name,bk->name)==0)
        break;
    bk=bk->next;
}
if(bk == NULL)
    return 0;

else
{
    curr=bk;
    return 1;
}

}
void update()
{
int code;
printf("enter the code");
scanf("%d", &code);
if(find(code)==0){
print_node(curr);
printf("change book's category: ");
 scanf("\n%[^\n]",curr->category);

 printf("change book's name: ");
 scanf("\n%[^\n]",curr->name);

 printf("change book's code: ");
 scanf("%d", &curr->code);

 printf("change book's copies: ");
 scanf("%d", &curr->copies);

 printf("change book's price: ");
 scanf("%f", &curr->price);

 printf("Updation Successful!!!\nnew data\n");
 print_node(curr);
            return;
}
else{
    return;
}

}


void updateName(char name[])
{
if(findName(name)==1){
print_node(curr);
printf("change book's category: ");
 scanf("\n%[^\n]",curr->category);

 printf("change book's name: ");
 scanf("\n%[^\n]",curr->name);

 printf("change book's code: ");
 scanf("%d", &curr->code);

 printf("change book's copies: ");
 scanf("%d", &curr->copies);

 printf("change book's price: ");
 scanf("%f", &curr->price);

 printf("Updation Successful!!!\nnew data\n");
 print_node(curr);
            return;
}
else{
    return;
}

}

 
 void insert(){

Node *newbook=malloc(sizeof(Node));
int num;
 printf("Please, enter book's name: ");
 scanf("\n%[^\n]",newbook->name);
 while(findName(newbook->name)==1){
    printf("book is already in the library\n");
    printf("choose \n1- update book\n2- change name\n");
    scanf("%d", &num);
    switch(num){
case 1:
    updateName(newbook->name);
    break;
case 2:
 printf("Please, enter book's name: ");
 scanf("\n%[^\n]",newbook->name);
 break;
    }
 }
 printf("Please, enter book's code: ");
 scanf("%d", &newbook->code);
 while(!find(newbook->code)){
    printf("code is already in the library\n");
    printf("enter another code\n");
    scanf("%d", &newbook->code);
 }
 printf("Please, enter book's category: ");
 scanf("\n%[^\n]",newbook->category);
 printf("Please, enter book's copies: ");
 scanf("%d", &newbook->copies);
 printf("Please, enter book's price: ");
 scanf("%f", &newbook->price);
 newbook->next=NULL;

if(head==NULL){head=newbook;end=newbook;}
else{
  Node *pre=NULL, *current=head;
  while(current!=NULL){
    if(current->code>newbook->code){
        break;
    }
    else{
        pre=current;
        current=current->next;
    }
  }
  if(pre==NULL){
    newbook->next=head;
    head=newbook;
  }
  else{
    pre->next=newbook;
    newbook->next=current;
  }
}
 }

 