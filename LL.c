#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
struct node {
	int data;
	struct node * next;
};

struct node* addElement(struct node *r, int value){
	
	struct node * iter=r;
	
	if(r==NULL){
		r=(struct node*)malloc(sizeof(struct node));
		r->data=value;
		r->next=NULL;
	}
	while(iter->next!=NULL){
		iter=iter->next;
	}
	iter->next=(struct node*)malloc(sizeof(struct node));
	iter->next->data=value;
	iter->next->next=NULL;
	
	return iter;
}

void printList(struct node *r){
	
	while(r->next!=NULL){
		r=r->next;
		printf("%d\n",r->data);
	}	
}

struct node * deleteElement(struct node *r,int value){
	
	struct node * iter=r;
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	
	//control if LL doesnt have any element.
	if(r==NULL){
		printf("linked list does not have any elements. Please insert elements.");
	}
	
	//go ahead until find element
	while(iter->next!=NULL&&iter->next->data!=value){
		iter=iter->next;
	}
	if(iter->next->data!=value){
		printf("value you wanted to delete does not exist.");
	
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	
	return r;	
	
}

struct node * deleteLL(struct node* r){
	
	struct node * current=r;
	struct node * next;
	
	while(current!=NULL){
		
		next=current->next;
		free(current);
		current=next;	
	}
	r=NULL;	
}

int lengthofLL(struct node *r){
	
	int count=0;
	
	while(r->next!=NULL){
		count++;
		r=r->next;
	}
	return count;
}

int nthNodeofLL(struct node *r, int index){
	
	int currentposition=0;
	int value;
	while(currentposition<index){
		r=r->next;
		currentposition++;
	}
	
	value=r->data;
	
	return value;		
}

void printNthFromLast(struct node *r, int index){
	
	int currentposition=0;
	while(currentposition<index){
		r=r->next;
		currentposition++;
	}

	while(r!=NULL){
		r=r->next;
		printf("%d\n",r->data);
	}	

}

void middleoftheLL(struct node *r){
	
	struct node* iter=r;
	int i=0;
	int n=0;
	int middle=0;
	
	while(iter->next!=NULL){
		iter=iter->next;
		n++;
	}
	if(n%2==1){
		middle=(n/2)+1;
	}
	else 
	middle=n/2;
	
	while(i<middle){
		i++;
		r=r->next;
	}
	printf("\ncount of nodes is %d",r->data);

}

int count(struct node *r, int value){
	
	int count=0;
	
	struct node* iter=r;
	
	while(iter!=NULL){
		
		if(value==iter->data){
			count++;
		}
		iter=iter->next;

	}
	return count;
	
}

struct node * push(struct node * root, int value){
	
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=value;
		root->next=NULL;
		return root;
	}
	
	struct node * iter=root;
	
	while(iter->next!=NULL){
		iter=iter->next;
	}	
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	iter->next=temp;
	return root;
}

int pop(struct node * root){
	
	if(root==NULL){
		printf("can not pop.");
		return -1;
	}
	
	struct node * iter=root;
	while(iter->next->next!=NULL){
		iter=iter->next;
	}
	int popped=iter->next->data;
	free(iter->next);
	iter->next=NULL;
	return popped;
}

int top(struct node * root){
	
	if(root==NULL){
		printf("no value at top.");
	}
	
	struct node * iter=root;
	while(iter->next!=NULL){
		iter=iter->next;
	}
	int popped=iter->data;
	return popped;
}

struct node * isPalindrom(struct node *root){
	
	struct node * iter=root->next;
	
	struct node * stack;
	
	
	while(iter!=NULL){
		
		push(stack, iter->data);	
		iter=iter->next;
	
	}
	
	
	root=root->next;
	while(root!=NULL){
		
		int value=top(stack);
		pop(stack);
		if(root->data!=value){
			return 0;
		}
		root=root->next;
	
	}
	return 1;
	
}

struct node * removeDuplicate(struct node *root){
	
	struct node * iter=root;
	
	while(iter->next!=NULL){
			
			if(iter->data==iter->next->data){
				
				struct node * temp;
				temp=iter->next;
				iter->next=iter->next->next;
				free(temp);
			}
			
		else{
			
			iter=iter->next;
		}
		
	}
		return root;
	
}

int main(){
	
	struct node * root=(struct node*)malloc(sizeof(struct node));
	root->next=NULL;
	
	
	addElement(root,10);
	addElement(root,20);
	addElement(root,20);
	addElement(root,20);
	addElement(root,20);
	addElement(root,30);
	addElement(root,40);
	addElement(root,50);
	removeDuplicate(root);
	
	printList(root);
	
	
	
	//int result=isPalindrom(root);
	//if(result==1){
	//	printf("dogru");
	//}
	//else
	//	printf("yanlis");
	//printf("tekrar sayisi:%d\n",count(root,10));

	//printList(stack);
	

}
