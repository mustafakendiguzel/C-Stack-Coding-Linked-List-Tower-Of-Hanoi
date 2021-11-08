#include <stdio.h>
#include <stdlib.h>

struct stack {
	int data;
	struct stack *adres;
};
typedef struct stack bliste;
void showStack(bliste*);
void pop1();
void pop2();
void pop3();
int topDeger(bliste*);
bliste *push(int,bliste*,bliste*);
bliste *cubuk1,*cubuk2,*cubuk3;
bliste *top1,*top2,*top3 = NULL;

int main(){
	top1 = push(3,top1,cubuk1);
	top1 = push(2,top1,cubuk1);
	top1 = push(1,top1,cubuk1);
	/*
	Her zaman top olanı gösteriyor o yüzden top en soldaki sayı yani 3
	*/
        int secim;
 
	while(5==5) {
	
     	printf("\n1.Cubuk:");
     	showStack(top1);
     	printf("\n2.Cubuk:");
     	showStack(top2);
     	printf("\n3.Cubuk:");
     	showStack(top3);
     	printf("\nTek tek sayisal sirayla tuslama yapiniz(1-2-3...):");
	    scanf("%d",&secim);
	    
	    switch(secim)
	    {
	    	case 1:
	    		top3 = push(topDeger(top1),top3,cubuk3);
	    		pop1();
	    		break;
	    	
	    	case 2:
	    		top2 = push(topDeger(top1),top2,cubuk2);
	    		pop1();
	    		break;
	    	case 3:
	    		top2 = push(topDeger(top3),top2,cubuk2);
	    		pop3();
 	    		break;
 	    	case 4:
 	    		top3 = push(topDeger(top1),top3,cubuk3);
 	    		pop1();
 	    		break;
 	    	case 5:
 	    		top1 = push(topDeger(top2),top1,cubuk1);
 	    		pop2();
 	    		break;
 	    	case 6:
 	    		top3 = push(topDeger(top2),top3,cubuk3);
 	    		pop2();
 	    		break;
 	    	case 7:
 	    		top3 = push(topDeger(top1),top3,cubuk3);
 	    		pop1();
 	    		break;
		}
    }
	return 0;
}

bliste *push(int data,bliste *top,bliste *direk) {
	direk = (bliste*)malloc(sizeof(bliste));
	direk->data = data;
	direk->adres = NULL;
	if(top!=NULL)
	  direk->adres = top;
	top = direk;
	return direk;
}

void showStack(bliste *top){
	bliste *temp = top;
	while(temp != NULL){
		printf("%d ", temp -> data);
		temp = temp -> adres;
	}
}

void pop1() {
	if(top1 == NULL) {
		printf("Stack bos");
	}
	else {
		bliste *temp = top1;
		top1 = top1 ->adres;
		free(temp);
	}
}
void pop2() {
	if(top2 == NULL) {
		printf("Stack bos");
	}
	else {
		bliste *temp = top2;
		top2 = top2 ->adres;
		free(temp);
	}
}
void pop3() {
	if(top3 == NULL) {
		printf("Stack bos");
	}
	else {
		bliste *temp = top3;
		top3 = top3 ->adres;
		free(temp);
	}
}

int topDeger(bliste *top) {
	return top->data;
}









