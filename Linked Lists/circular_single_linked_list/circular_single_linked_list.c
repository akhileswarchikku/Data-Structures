#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

void print_list(){
    struct Node *temp;
    temp=head;
    if(head == NULL){
        printf("\nThere are no elements to print");
    }
    else{
        printf("\nhead-->");
        printf("|%d|-->",head);
        while(temp->next!=head){
            printf("|present = %d|",temp);
            printf("|%d|",temp->data);
            printf("|%d|-->",temp->next);
            temp = temp->next;
        }
        printf("|present = %d|",temp);
        printf("|%d|",temp->data);
        printf("|%d|-->|||",temp->next);
    }
}

void insert_in_begining(){
    int element;
    struct Node *ptr,*temp;
    printf("\nEnter a number you want to be inserted at the begining:");
    scanf("%d",&element);
    printf("The element u have entered is %d",element);
    ptr = (struct Node *) malloc(sizeof(struct Node *));
    ptr->data = element;
    if (head==NULL){
        ptr->next = head;
        head = ptr;
        ptr->next = head;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    
}
void insert_in_middle(){
    int before,index=1,found=0;
    struct Node *ptr,*temp;
    print_list();
    printf("\nEnter the number after you want insert:");
    scanf("%d",&before);
    temp=head;
    if (temp->data==before && head==temp->next){
        printf("Element found in %d index",index);
        found = 1;
    }
    else if (found==0){
        while(temp->next!=head){
            if (temp->data == before){
                printf("\nElement found in %d index",index);
                found = 1;
                break;
            }
            temp = temp->next;
            index = index +1;
        }
    }
    if (temp->data==before && found ==0){
        index = index + 1;
        printf("Element found in %d index",index);
        found = 1;
    }
    if (found == 1){
        int element,inserted=0;
        printf("\nEnter the number you want to insert:");
        scanf("%d",&element);
        ptr = (struct Node *) malloc(sizeof(struct Node *));
        ptr->data = element;
        while(temp->next!=head){
            if (temp->data == before){
                ptr->next = temp->next;
                temp->next = ptr;
                inserted = 1;
                break;
            }
            temp = temp->next;
        }
        if (temp->data == before && inserted==0){
            temp->next = ptr;
            ptr->next = head;
        } 
    }
    
}
void insert_in_end(){
    int element;
    struct Node *ptr,*temp;
    printf("\nEnter a number you want to be inserted at the end:");
    scanf("%d",&element);
    printf("The element u have entered is %d",element);
    ptr = (struct Node *) malloc(sizeof(struct Node *));
    ptr->data = element;
    temp=head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
}
void delete_from_the_start(){
    if (head==NULL){
        printf("\nThere are no elements to be deleted");
    }
    else{
        struct Node *temp,*temp2;
        int index = 1;
        temp=head;
        while(temp->next!=head){
            temp = temp->next;
            index = index + 1;
        }
        if (index==1){
            printf("\nElement Deleted From start");
            temp=head;
            head = NULL;
        }
        else{
            temp=head;
            int index=1;
            printf("\nElement Deleted From start");
            while(temp->next!=head){
                temp = temp->next;
                index = index + 1; 
            }
            temp->next = head->next;
            head = head->next;
        }
    }
}
void delete_from_the_end(){
    if (head==NULL){
        printf("\nThere are no elements to be deleted");
    }
    else{
        struct Node *temp,*temp2;
        int index = 1;
        temp=head;
        while(temp->next!=head){
            temp = temp->next;
            index = index + 1;
        }
        if (index==1){
            printf("\nElement Deleted From End");
            temp=head;
            head = NULL;
        }
        else{
            temp=head;
            int index=1;
            printf("\nElement Deleted From End");
            while(temp->next->next!=head){
                temp = temp->next;
                index = index + 1; 
            }
            temp->next = head;
        }
    }
}
void delete_from_the_middle(){
    struct Node *temp;
    int element,index =1,deleted=0;
    printf("\nPlease Enter the element you want to delete:");
    scanf("%d",&element);
    temp = head;
    while(temp->next!=head){
        if (temp->next->data==element){
            temp->next=temp->next->next;
        }
        else{
            temp=temp->next;
        }
    }
}
int main(){
    insert_in_begining();
    insert_in_begining();
    insert_in_middle();
    insert_in_end();
    print_list();
    delete_from_the_start();
    delete_from_the_middle();
    delete_from_the_end();
    print_list();
    return 0;
}
