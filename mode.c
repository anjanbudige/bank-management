#include <string.h>
#include <stdlib.h>
#include "adminfun.c"
#include "stafffun.c"
#include "custfun.c"

void admin(){
 //system("clear");
  system("CLS");
  char user[20];
  char pass[20];
  char pass2[20];
  int flag = 0;
	printf("\n--- Admin Login ----\n");
	printf("Enter Username: ");
	scanf("%s",user);
	char file[10] = ".txt";
	strcat(user,file);
	
	FILE *fp;
	fp = fopen(user, "r");
	if(fp != NULL){
	  printf("Enter Password: ");
	  scanf("%s",pass);
	  fgets(pass2,10,fp);
	  if(strcmp(pass2,pass)==0){
	    printf("Login Successful\n");
	    flag =1;
	    fclose(fp);
	  }
	  else{
	    printf("Password Wrong Please Check It\n");
	  }
	  
	  
	  
	  
	}
	else{
	  printf("User Not Found/n");
	}
	
	
	if(flag==1){
	admin:
		printf("\n------- Admin Panel -------\n");
	printf("1. Add Account\n2. Delete Account \n3. Check All Account\n4. Edit Account\n5. Change Your Password\n6. Exit\n\n");
	
	int a;
	printf("Enter Your Option: ");
	scanf("%d",&a);
	
	switch(a){
	  case 1:{
	    add_acc();
	    printf("\n");
	    goto admin;
	    break;
	  }
	  case 2:{
	    delete_acc();
	    printf("\n");
		goto admin;
	    break;
	  }
	  case 3:{
	    check_all();
	    printf("\n");
	    goto admin;
	    break;
	  }
	  case 4:
	  {
	    edit_acc();
	    printf("\n");
	    goto admin;
	    break;
	  }
	  case 5:{
	  	change_adminpass(user);
	  	goto admin;
		break;
	  }
	  case 6:{
	  	printf("Thanks For Using Our Service! \n");
	  	printf("\nDEVELOPED BY ANJAN BUDIGE\n");
	  	printf("\n\n");
	    break;
	    
	    
	  }
	  default:{
	    printf("Invalid Option\n");
	    goto admin;
	    break;
	    
	  }
	 
	  
	}
	
	
	}
	

	
	
}
void staff(){
  char user[20];
  char pass[20];
  char pass2[20];
  int flag = 0;
  system("CLS");
	printf("\n--- Staff Login ----\n");
	printf("Enter Username: ");
	scanf("%s",user);
	char file[20] = "staff_acc/";
	strcat(file,user);
	char file2[20] = ".txt";
	strcat(file,file2);
	char filen[20];
	strcpy(filen,file);
	FILE *fp;
	fp = fopen(filen, "r");
	if(fp != NULL){
	  printf("Enter Password: ");
	  scanf("%s",pass);
	  fgets(pass2,10,fp);
	  if(strcmp(pass2,pass)==0){
	    printf("Login Successful\n");
	    flag =1;
	    fclose(fp);
	  }
	  else{
	    printf("Password Wrong Please Check It\n");
	  }
	  
	  
	  
	  
	}
	else{
	  printf("User Not Found");
	}
	
	int a;
	if(flag==1){
		staff:
			printf("\n-------Staff Panel-------\n\n");
	printf("1. Withdraw\n2. Deposit \n3. User Balance Check\n4. Edit Account\n5. Change Your Password\n6. Exit\n\nSelect Option: ");
	scanf("%d",&a);
	switch(a){
		case 1:{
			withdraw();
			goto staff;
			break;
		}
		case 2:{
			deposit();
			goto staff;
			break;
		}
		case 3:{
			user_bal();
			goto staff;
			break;
		}
		case 4:{
			edit_acc();
			goto staff;
			break;
		}
		case 5:{
			change_pass(filen);
			goto staff;
			break;
		}
		case 6:{
			printf("Thank You for using our service\n");
			printf("\nDEVELOPED BY ANJAN BUDIGE\n");
			printf("\n\n");
			break;
		}
		default:{
			printf("Invalid Option\n");
			goto staff;
			break;
		}
		
		
	}
	
	
	
	}
	
}
void customer(){
	char user[20];
	char pass[20];
	char pass2[20];
	int flag =0;
	system("CLS");
	printf("\n--- Customer Login----\n\n");
	printf("Enter Username: ");
	scanf("%s",user);
	char file[20] = "cust_acc/";
	strcat(file,user);
	char file2[20] = ".txt";
	strcat(file,file2);
	char filen[20];
	strcpy(filen,file);
	FILE *fp;
	fp = fopen(filen, "r");
	if(fp != NULL){
	  printf("Enter Password: ");
	  scanf("%s",pass);
	  fgets(pass2,10,fp);
	  if(strcmp(pass2,pass)==0){
	    printf("Login Successful\n");
	    flag =1;
	    fclose(fp);
	  }
	  else{
	    printf("Password Wrong Please Check It\n");
	  }
	  
	}
	else{
	  printf("User Not Found");
	}
	int a;
	if(flag==1){
		cust:
			printf("\n-------Customer Panel-------\n\n");
			printf("Hi! %s\n",user);
	printf("1. Send Money\n2. Check Balance\n3. Change Your Password\n4. Exit\n\nSelect Option: ");
	scanf("%d",&a);
	switch(a){
		case 1:{
			send_money(user);
			goto cust;
			break;
		}
		case 2:{
			check_userbal(user);
			goto cust;
			break;
		}
		case 3:{
			change_userpass(filen);
			goto cust;
			break;
		}
		
		case 4:{
			printf("Thank You for using our service\n");
			printf("\nDEVELOPED BY ANJAN BUDIGE\n");
			printf("\n\n");
			break;
		}
		default:{
			printf("Invalid Option\n");
			goto cust;
			break;
		}
		
	
}
}
}

