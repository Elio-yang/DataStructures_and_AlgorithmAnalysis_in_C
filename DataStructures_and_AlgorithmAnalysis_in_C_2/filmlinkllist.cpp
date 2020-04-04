#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45

typedef  struct film
{
    char title[TSIZE];
    int rating;
    struct film* next;
}FILM;
char* s_gets(char*st,int n);

int main(){
    FILM* head=NULL;
    FILM*prev,*current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input,TSIZE)!=NULL&&input[0]!='\0')
    {
        current=(FILM*)malloc(sizeof(FILM));
        if(head==NULL){
            head=current;
        }
        else
        {
            prev->next=current;
        }
        current->next=NULL;
        
        strcpy(current->title,input);
        puts("Enter your rating <0-10>:");
        scanf("%d",&current->rating);
        while (getchar()!='\n')
        {
            continue;
        }
        
        puts("Enter next movie title (empty line to stop):");
        prev=current;//current node will be the previous for next operation
        
    }
    if(head==NULL){
        printf("No data entered. ");
        
    }
    else
    {
        printf("Here is the film listL:\n");
    }
    current=head;
    while(current!=NULL){
        printf("Movie:%s \nRating:%d\n",current->title,current->rating);
        current=current->next;//next pt the next node
    }
    current=head;//back to head
    while(head!=NULL){
        current=head;
        head=current->next;//the next will be the head
        free(current);//current node are freed
    }
    puts("Bye!");
    system("pause");
    return 0;

}
char* s_gets(char*st,int n){
    char*ret_val;
    char*find;
    ret_val=fgets(st,n,stdin);
    if(ret_val){
        find=strchr(st,'\n');
        if(find){
            *find='\0';
        }
        else{
            while (getchar()!='\n')
            {
                continue;
            }
            
        }
    }
    return ret_val;
}
