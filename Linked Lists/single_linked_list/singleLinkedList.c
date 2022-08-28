#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

void print_list(){
    struct Node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("\nThere are no elements to print");
    }
    else{
        printf("\nhead");
        while (ptr!=NULL){
            printf("-->");
            printf("%d",ptr->data);
            ptr = ptr -> next;
        }
    }
}

void insert_in_begining(){
    struct Node *ptr;
    int item;
    ptr = (struct Node *) malloc(sizeof(struct Node *)); 
    printf("Enter an element to be inserted at the begining:");
    scanf("%d",&item);
    ptr->data = item;
    ptr->next = head;
    head = ptr;
}

void insert_in_the_end(){
    struct Node *ptr, *temp;
    int item;
    ptr = (struct Node *) malloc(sizeof(struct Node *)); 
    printf("Enter an element to be inserted at the end:");
    scanf("%d",&item);
    ptr->data = item;
    if (head == NULL){
        head = ptr;
        head -> next = NULL;
    }
    else
    {
        temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp ->next = ptr;
        ptr -> next = NULL;
    }
}

void insert_in_the_middle(){
    struct Node *ptr, *temp;
    int item,before;
    ptr = (struct Node *) malloc(sizeof(struct Node *)); 
    printf("\nEnter the element where you want to insert after:");
    scanf("%d",&before);
    int i=0,found=0;
    temp = head;
    while(temp->next !=NULL){
        if (temp -> data == before){
            printf("\nElement Found in index %d",i+1);
            found = 1;
            break;
        }
        temp = temp -> next;
        i = i + 1;
    }
    if (found==1){
        printf("\nEnter the element to be inserted:");
        scanf("%d",&item);
        ptr->data = item;
        temp = head;
        while(temp->next !=NULL){
            if (temp -> data == before){
                ptr -> next = temp ->next;
                temp -> next = ptr;
                break;
            }
            temp = temp -> next;
        }
    }
    else{
        printf("\nElement you have entered is not in the linked list");
    }
}

void delete_element(){
    struct Node *temp,*temp2;
    temp = head;
    int i,element,found = 0;
    if (temp == NULL){
        printf("\nThere are no elements to delete");
    }
    else{
        printf("\nEnter a number to delete:");
        scanf("%d",&element);
        temp = head;
        while(temp -> next != NULL)
        {
            if (temp -> data == element){
                printf("\nElement Found in index %d",i);
                found = 1;
            }
            temp = temp -> next;
            i = i + 1;
        }
        if (found == 1){
            temp = head;
            while(temp->next!=NULL){
                if (temp->next->data == element){
                    temp->next=temp->next->next;
                }
                else{
                    temp=temp->next;
                }
            }
        }

    }

}

int main(){
    insert_in_the_end();
    insert_in_begining();
    insert_in_begining();
    insert_in_the_end();
    print_list();
    insert_in_the_middle();
    print_list();
    delete_element();
    print_list();
    return 0;
}