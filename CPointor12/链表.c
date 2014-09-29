#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

typedef struct NODE {
	struct NODE *next;
	int value;
} Node;

Node * node_insert(Node * current , int value);
Node * insert_node(Node * current , int value); // 有序链表
Node * insert_reserve(Node * current , int value); //逆序插入 每次插入在头结点之前
int count_nodes(Node* current);
Node * find_node(Node* current,int value);
Node * reverse(Node* current);
int sll_remove(Node * root , int value);
void main(){
	Node * newNode;
	Node * current = (Node *)malloc(sizeof(Node));
	current->next = NULL; // 指针要初始化为NULL
	current->value = 0;
	insert_node(current,1);
	insert_node(current,2);
	insert_node(current,3);
	insert_node(current,4);
	insert_node(current,5);
	insert_node(current,6);
	insert_node(current,7);
	//printf("%d\n",count_nodes(current));
	//printf("%d\n",find_node(current,7)->value);
	//newNode = reverse(current);
	sll_remove(current,5);
	printf("123");
}

Node *  node_insert(Node * current , int value){
	 Node * copy , *previouce;
	 Node * newNode = (Node *)malloc(sizeof(Node));
	 if(newNode!=NULL){
		 if(current == NULL){
		     newNode->value = value;
		     newNode->next = NULL;
			 return newNode;
		 }
		 newNode->value = value;
		 newNode->next = NULL;
		 copy = current;
		 while(copy!=NULL){
			 previouce = copy;
			 copy = copy->next;
		 }
		 previouce->next = newNode;
	 }
	 return current;
}
//有序链表
Node * insert_node(Node * current , int value){
	  Node * copy , *previonce;
      Node * newNode = (Node *)malloc(sizeof(Node));
	  if(newNode!=NULL){
		  newNode->next = NULL;
		  newNode->value = value;
		  if(current->value > value){
			  newNode->next = current;
			  return newNode;
		  } else {
			  copy = current;
			  while(copy!=NULL){
				  if(copy->value > value){
					  previonce->next = newNode;
					  newNode->next = copy;
					  return current;
				  }
				  previonce = copy;
				  copy = copy->next;
			  }
		  }
		  if(copy == NULL && newNode->next == NULL){
			  previonce->next = newNode;
			  return current;
		  }	  
	  }
	  return NULL;
}

int count_nodes(Node* current){
   int count;
   for(count = 0;current!=NULL;current= current ->next)
	   count++;
   return count;
}

Node * find_node(Node* current,int value){
	while(current!=NULL){
		if(current->value == value)
			return current;
		current = current->next;
	}
	return NULL;
}

Node * reverse(Node* current){
    Node *newNode = NULL;
	while(current!=NULL){
		newNode = insert_reserve(newNode,current->value);
		current = current->next;
	}
	return newNode;
}

Node * insert_reserve(Node * current , int value){
      Node *newNode = (Node *)malloc(sizeof(Node));
	  if(newNode == NULL) return NULL;
	  newNode->value = value;
	  newNode->next = current;
	  return newNode;
}

int sll_remove(Node * root , int value){
	Node * pre;
	if(root == NULL) return FALSE;
	// 如果是头结点
	if(root->value == value){
	    free(root);
		root = NULL;
		return TRUE;
	}
	pre = root;
	root = root->next;
	while(root!=NULL){
		if(root->value == value){
			pre->next = root->next;
			free(root);
			return TRUE;
		}
		pre = root;
		root = root->next;
	}
	return FALSE;
} 