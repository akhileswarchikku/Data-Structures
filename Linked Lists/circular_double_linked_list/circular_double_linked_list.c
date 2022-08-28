#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *previous;
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
        printf("|%p|-->",head);
        while(temp->next!=head){
            printf("|%p|",temp->previous);
            printf("|present=%p|",temp);
            printf("|%d|",temp->data);
            printf("|%p|-->",temp->next);
            temp = temp->next;
        }
        printf("|%p|",temp->previous);
        printf("|present=%p|",temp);
        printf("|%d|",temp->data);
        printf("|%p|-->|||",temp->next);
    }
}

void insert_in_begining(){
    struct Node *ptr,*temp;
    int element;
    ptr = (struct Node *) malloc(sizeof(struct Node *));
    printf("\nEnter the element you want to insert in the begining:");
    scanf("%d",&element);
    ptr->data = element;
    if (head == NULL){
        ptr->previous = ptr;
        ptr->next = ptr;
        head = ptr;
    }
    else{
        temp=head;
        ptr->next = temp;
        temp->previous = ptr;
        while(temp->next!=head){
            temp=temp->next;
        }
        ptr->previous = temp->next;
        temp->next= ptr;
        head = ptr;
    }
}
void insert_in_end(){
    struct Node *temp,*ptr;
    int element;
    temp = head;
    if (temp==NULL){
        printf("\nThere are no elements to be added so please add the element first");
        insert_in_begining();
    }
    else{
        ptr = (struct Node *) malloc(sizeof(struct Node *));
        printf("\nEnter the element you want to insert in the end:");
        scanf("%d",&element);
        ptr->data = element;
        while(temp->next!=head){
            temp=temp->next;
        }
        ptr->previous = temp;
        temp->next = ptr;
        ptr->next = head;

    }
}
void delete_from_the_start(){
    struct Node *temp;
    int index=1;
    temp = head;
    while(temp->next!=head){
        temp=temp->next;
        index = index + 1;
    }
    if (head==NULL){
        printf("\nThere are no elements to delete");
    }
    else if(index == 1){
        head = NULL;
    }
    else{
        temp=head;
        while (temp->next!=head){
            temp=temp->next;
        }
        head=head->next;
        head->previous = temp;
        temp->next = head;
    }
}
void delete_from_the_end(){
    struct Node *temp;
    int index=1;
    temp = head;
    while(temp->next!=head){
        temp=temp->next;
        index = index + 1;
    }
    if (head==NULL){
        printf("\nThere are no elements to delete");
    }
    else if(index == 1){
        head = NULL;
    }
    else{
        temp=head;
        while (temp->next->next!=head){
            temp=temp->next;
        }
        head->previous = temp;
        temp->next = head;
    }
}

void delete_from_the_middle(){
    struct Node *temp;
    int index=1,element,found=0,length=1;
    temp = head;
    printf("\nEnter an element you want to delete:");
    scanf("%d",&element);
    while(temp->next!=head){
        temp=temp->next;
        length = length + 1;
    }
    temp=head;
    while(temp->next!=head){
        if (temp->data == element){
            found = 1;
            break;
        }
        temp=temp->next;
        index = index + 1;
    }
    if (temp->data == element && found == 0){
        index = index + 1;
    }
    if (index == 1 && found ==1){
        delete_from_the_start();
    }
    else if(index == length && found ==  1){
        delete_from_the_end();
    }
    else{
        temp = head;
        while(temp->next!=head){
            if (temp->next->data==element){
                temp->next=temp->next->next;
                temp->next->previous =temp;
            }
            else{
                temp = temp->next;
            }
        }
    }
}

int main(){
    insert_in_begining();
    insert_in_begining();
    insert_in_begining();
    insert_in_begining();
    insert_in_begining();
    insert_in_end();
    print_list();
    printf("\n");
    delete_from_the_start();
    print_list();
    printf("\n");
    delete_from_the_end();
    print_list();
    delete_from_the_middle();
    print_list();
}