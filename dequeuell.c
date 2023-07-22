//DEQUE USING CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>

int main(){
   int count=0;
   
   struct node{
       int data;
       struct node *next;
   };
   int n;
   printf("Enter the maximum number of nodes");
   scanf("%d",&n);
   
   struct node *front,*rear;
   front=NULL;rear=NULL;
   
   //Enqueue Front
   
   void enqueuefront(int x){
       
       struct node *enqueuefront;
       enqueuefront=(struct node *)malloc(sizeof(struct node));
       enqueuefront->data=x;
       
       
      if(front==NULL && rear==NULL){
           front=enqueuefront;rear=enqueuefront;
           count++;
       }
       else if(rear->next==front && count==n){
            printf("Queue is full\n");   
          }
       else{
           struct node *temp1;
           temp1=front;
           front=enqueuefront;
           front->next=temp1;
           rear->next=front;
           count++;
       }
       
   }
   
   //Enqueue Rear
   
   void enqueuerear(int x){
       
       struct node *enqueuerear;
       enqueuerear=(struct node *)malloc(sizeof(struct node));
       enqueuerear->data=x;
       
       if(front==NULL && rear==NULL){
           front=enqueuerear;rear=enqueuerear;
           count++;
       }
       else if(rear->next==front && count==n){
           printf("Queue is full\n");
       }
       else{
           enqueuerear->next=front;
           rear->next=enqueuerear;
           rear=enqueuerear;
           count++;
       }
       
   }
   
   //Dequeue Front
   
   void dequeuefront(){
       
       if(front==NULL && rear==NULL){
           printf("Queue is Empty\n");
       }
       else{
            front=front->next;
            rear->next=front;
            count--;
       }
       
   }
   
   //Dequeue Rear
   
   void dequeuerear(){
       
        if(front==NULL && rear==NULL){
           printf("Queue is Empty\n");
       }
       else{
           struct node *temp,*prev;
           temp=front;
           
           while(temp->next!=rear->next){
               prev=temp;
               temp=temp->next;
           }
           prev->next=front;
           rear=prev;
           
           count--;
       }
   }
   
   
   void display(){
       struct node *temp,*prev;
       
       temp=front;
       
       while(rear->next!=temp->next){
           printf("%d ",temp->data);
           temp=temp->next;
       }
       printf("%d ",temp->data);
   }
   
    enqueuefront(10);
    display();
    printf("\n");
    enqueuefront(20);
    display();
    printf("\n");
    enqueuefront(30);
    display();
    printf("\n");
    enqueuerear(40);
    display();
    printf("\n");
    enqueuerear(50);
    display();
    printf("\n");
    enqueuerear(60);
    display();
    printf("\n");
    dequeuefront();
    display();
    printf("\n");
    dequeuerear();
    display();
}




//SAMPLE OUTPUT

// Enter the maximum number of nodes5
// 10 
// 20 10 
// 30 20 10 
// 30 20 10 40 
// 30 20 10 40 50 
// Queue is full
// 30 20 10 40 50 
// 20 10 40 50 
// 20 10 40 
