#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
struct Node{
    struct Node *previous;
    int data;
    struct Node *next;
};

struct Node *head;

void insert_in_begining(){
    struct Node *ptr,*temp;
    int number;
    printf("Please Enter an element you want to be inserted:");
    scanf("%d",&number);
    printf("You have Entered %d\n",number);
    ptr = (struct Node *) malloc(sizeof(struct Node *));
    if (head == NULL){
        ptr->previous = NULL;
        ptr->data = number;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        ptr->data = number;
        ptr->previous = NULL;
        ptr->next = head;
        head->previous = ptr;
        head = ptr;
    }
    
}
void insert_in_end(){
    struct Node *ptr,*temp;
    int number;
    printf("Please Enter an element you want to be inserted at End:");
    scanf("%d",&number);
    printf("You have Entered %d\n",number);
    ptr = (struct Node *) malloc(sizeof(struct Node *));
    ptr->data = number;
    if (head == NULL){
        ptr->previous = NULL;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        temp = head;
        while(temp!=NULL){
            if (temp->next == NULL){
                break;
            }
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->previous = temp;
        ptr->next = NULL;
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
                temp->next->previous = ptr;
                ptr -> previous = temp;
                temp->next = ptr;
                break;
            }
            temp = temp -> next;
        }
    }
    else{
        printf("\nElement you have entered is not in the linked list");
    }
}

void print_list_from_the_begining(){
    struct Node *temp;
    if (head==NULL){
        printf("There are no elements to print");
    }
    else{
        temp = head;
        printf("\nhead->");
        while(temp!=NULL){
            printf("%d-->",temp->data);
            temp = temp->next;
        }
    }
}
void print_list_from_the_end(){
    struct Node *temp,*back;
    if (head==NULL){
        printf("There are no elements to print");
    }
    else{
        temp = head;
        while(temp!=NULL){
            if(temp->next == NULL){
                back = temp;
            }
            temp = temp->next;
        }
        printf("\n<--back");
        while(back!=NULL){
            printf("<--%d",back->data);
            back = back->previous;
        }
    }
}
void delete_element(){
    struct Node *temp,*temp2;
    int i,element,found = 0;
    if (head == NULL){
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
                    temp->next->previous =temp;

                }
                else{
                    temp=temp->next;
                }
            }
        }

    }

}
int main(){
    insert_in_begining();
    insert_in_begining();
    insert_in_end();
    insert_in_the_middle();
    print_list_from_the_begining();
    print_list_from_the_end();
    delete_element();
    print_list_from_the_begining();
    print_list_from_the_end();
}