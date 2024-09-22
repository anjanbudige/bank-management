#include <stdio.h>
#include "mode.c"
int main(){
	main:
	printf("Alpha Bank Management System V1.0 \n\n");
	printf("1. Admin Login\n2. Staff Login\n3. Customer Login\n4. Create account\n5. Exit\n\n");

int a;
printf("Enter Your Choice: ");
scanf("%d",&a);
switch(a){
	case 1: {
		admin();
		goto main;
		break;
	}
	case 2: {
		staff();
		goto main;
		break;
	}
	case 3: {
		customer();
		goto main;
		break;
	}
	
	case 4:{
		create_acc();
		printf("\n\n");
		goto main;
		break;
	}
	case 5:{
		printf("\nThanks For Using Our Service\n\nDEVELOPED BY ANJAN BUDIGE   \n");
		break;
	}
		
	
}
}
