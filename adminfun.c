#include <string.h>
#include <stdlib.h>
	void check_user();
struct cust{
  char name[20];
  int accno;
  int bal;
  char pass[10];
}cust1;

void add_acc(){
	int ac;
  FILE *f = fopen("acc.txt","r");
  fscanf(f,"%d",&ac);
  fclose(f);
  f = fopen("acc.txt","w");
  fprintf(f,"%d",ac+1);
  fclose(f);
  
  
  system("CLS");
  char name[20];
  char name2[20];
  char cust_name[20];
  printf("----Add Account-----\n\n");
  printf("Enter Customer Name (without spaces): ");
  scanf("%s",cust1.name);
  strcpy(name,cust1.name);
  strcpy(cust_name,name);
  cust1.accno = ++ac;
  printf("Enter Customer Opening Balance: ");
  scanf("%d",&cust1.bal);
  printf("Enter Customer Password: ");
  scanf("%s",cust1.pass);
  char temp[20] = "cust_acc/";
  strcat(temp,name);
  char temp2[20] = ".txt";
  strcat(temp,temp2);
  FILE *fp;
  fp = fopen(temp,"w");
  fputs(cust1.pass,fp);
  fclose(fp);
  
  char temp3[20] = "cust_details/";
  char temp4[10] = ".txt";
  strcpy(name2,cust1.name);
  strcat(temp3,name2);
  strcat(temp3,temp4);
  
  fp = fopen(temp3, "w");
  fprintf(fp,"---Account Details---\n\n");
  fprintf(fp,"Name : %s\nAccount No: %d\nBalance: %d\n",cust_name,cust1.accno,cust1.bal);
  
  fclose(fp);
  fp = fopen(temp3, "r");
  if(fp){
  	printf("-----------------------");
    printf("\nSuccessful Added Account\n");
    char c;
    c = fgetc(fp);
    while(c != EOF){
      printf("%c",c);
      c = fgetc(fp);
    }
	fclose(fp);
	
    fp = fopen("cust.txt", "a+");
    fprintf(fp,"\n%d \t %s \t %d \t",cust1.accno,cust_name,cust1.bal);
    fclose(fp);
    printf("Succesfully Done\n");

    printf("-----------------------");
  }
    else{
      printf("Something Went Wrong");
    }
    
   
  }
  
  void delete_acc(){
    system("clear");
    char name[30];
    char line[200];
    int a,b;
    char c;
    printf("Enter Account Name : ");
    scanf("%s",name);
    char folder[20] = "cust_details/";
    char name2[20] = ".txt";
    strcat(name,name2);
    strcat(folder,name);
    printf("%s\n",folder);
    FILE *fp;
    fp = fopen(folder,"r");
    if(fp){
      printf("Account Found\n\n");
      printf("Check Details\n");
      c = fgetc(fp);
      while(c != EOF){
        printf("%c",c);
        c = fgetc(fp);
      }
      fclose(fp);
      printf("\n\n Are you want to delete this account (Enter 1 for yes, 2 for no) : ");
      scanf("%d",&b);
      if(b==1){
        remove(folder);
        printf("Account Deleted Succsesfully\n");
      }
      else{
        printf("Deletion of account cancelled");
      }
      
    }else{
      printf("Customer Details Not Found\n");
    }
   /*if(a==2){
      printf("Enter Customer Account No: ");
      scanf("%s",name);
      DIR *dr;
      dr = opendir("/cust_details");
      struct dirent *filen;
      char found[20];
      char c;
      int flag = 0;
      if(dr){
        while ((filen = readdir(dr)) != NULL) {
      
          FILE *fp1;
          fp1 = fopen(filen->d_name,"r");
          fgets(line,100,fp1);
          while(line != NULL){
            if(strstr(line,name)){
              strcpy(found,filen);
              flag = 1;
              break;
            }
            }
            if(flag==1){
              printf("Account Found\n");
              break;
          }
          fclose(fp1);
          if(flag==0){
            printf("User Not Found\n");
          }
        }
      }
      else{
        printf("Accouns Files Not Found");
      }
      if(flag==1){
        FILE *fp1;
        fp1 = fopen(found,"r");
        printf("\nCheck Detials\n");
        c = fgetc(fp1);
        while(c!=EOF){
          printf("%c",c);
          c = fgetc(fp1);
        }
        printf("\n\n Are you want to delete this account (Enter 1 for yes, 2 for no) : ");
      scanf("%d",&b);
      if(b==1){
        if(remove(found)==0){
          printf("Account Deleted Successfully\n");
        }
        else{
          printf("Unable To Delete\n");
        }
      }
      else{
        printf("Deletion of account cancelled");
      }
        
      }*/
      
      
      
      
    }
    
    void check_all(){
    	int a;
    	char c;
    	printf("All Accounts User Names in this bank\n\n");
    	FILE *fp;
    	fp = fopen("cust.txt", "r");
    	if(fp){
    		c = fgetc(fp);
    		while(c!=EOF){
    			printf("%c",c);
    			c = fgetc(fp);
			}
			printf("\n");
			fclose(fp);
		}
	printf("\nWant to check any user Details: \n");
	printf("1.Yes\n2.No\n\nSelect Option: ");
	scanf("%d",&a);
	if(a==1){
		check_user();
	}
	
	}
	
	void check_user(){
	system("CLS");
	char tempn[20];
	char c;
	printf("Enter Customer Name: ");
	scanf("%s",tempn);
	char name2[20]= ".txt";
	char name3[20]="cust_details/";
	strcat(tempn,name2);
	strcat(name3,tempn);
	FILE *fp;
	fp = fopen(name3,"r");
	if(fp){
		printf("User Details\n");
		c = fgetc(fp);
		while(c!=EOF){
			printf("%c",c);
			c = fgetc(fp);
		}
		fclose(fp);
	}
	else{
		printf("User Not Found\n");
	}
	
	
	}
	
	
	void edit_acc(){
    char name[20];
		char newname[20];
		int amount;
		int a,i;
		char line[1000];
		system("CLS");
		char c;
		printf("\n------- Edit Account--------\n\n");
		printf("Enter Cutomer Name : ");
		scanf("%s",name);
		char tname[20];
		char name2[20] = ".txt";
		strcat(name,name2);
		char name3[20] = "cust_details/";
		strcat(name3,name);
		
		
		FILE *fp = fopen(name3, "r");
		 fflush(stdin);
		if(fp){
			c = fgetc(fp);
			while(c!=EOF){
				printf("%c",c);
				c = fgetc(fp);
			}
			
			printf("\n\n");
			fclose(fp);
		
			printf("Edit User\n1.Username Change\n2.Change Balance\n\nSelect Option: ");
			scanf("%d",&a);
			
			
			if(a==1){
				
					fp = fopen(name3, "r");
					FILE *fp1 = fopen("temp.txt", "w");
					
				printf("\nEnter New Username: ");
				scanf("%s",newname);
				strcpy(tname,newname);
				char tempn[20] = "Name : ";
				
				strcat(tempn,newname);
				
				int count =0;
				int lin = 3;
				while((fgets(line,1000,fp) != NULL)){
					count ++;
					
					if (count == lin){
						fputs(tempn, fp1);
						fputc('\n',fp1);
						}
						else{
						fputs(line, fp1);
						}
					    }
					    
					    fclose(fp);
					    fclose(fp1);
					    
					    remove(name3);
					    char temp5[20]="cust_details/";
					    char temp6[20] = ".txt";
					    strcat(temp5,tname);
					    strcat(temp5,temp6);
					    rename("temp.txt",temp5);
					    
				
				printf("\nSuccesfully Edited\n");
				
				fp = fopen(temp5,"r");
				c = fgetc(fp);
			while(c!=EOF){
				printf("%c",c);
				c = fgetc(fp);
			}
			fclose(fp);
			printf("\n");
			
			
				
				
			}
			if(a==2){
				printf("Enter New Balance: ");
				scanf("%d",&amount);
				fp = fopen(name3,"r");
				FILE *fp1 = fopen("temp.txt","w");
				int count =0;
				int lin =5;
				while(fgets(line,1000,fp)!= NULL){
					count++;
					if(count == lin){
						fprintf(fp1,"Balance : %d\n",amount);
						
					}
					else{
						fputs(line,fp1);
					}
					
				}
				
				fclose(fp);
				fclose(fp1);
				remove(name3);
				rename("temp.txt",name3);
				
				printf("Succesfully Edited\n\n");
				
				fp = fopen(name3, "r");
				c = fgetc(fp);
				while(c != EOF){
					printf("%c",c);
					c = fgetc(fp);
				}
				printf("\n");
				
				
				
				
			}
			
			
			
		}else{
			printf("User Not Found\n");
		}
}

void create_acc(){
	int ac;
  FILE *f = fopen("acc.txt","r");
  fscanf(f,"%d",&ac);
  fclose(f);
  f = fopen("acc.txt","w");
  fprintf(f,"%d",ac+1);
  fclose(f);
  
  
  system("CLS");
  char name[20];
  char name2[20];
  char cust_name[20];
  printf("----Create Account-----\n\n");
  printf("Enter Your Name (without spaces): ");
  scanf("%s",cust1.name);
  strcpy(name,cust1.name);
  strcpy(cust_name,name);
  cust1.accno = ++ac;
  printf("Create Password: ");
  scanf("%s",cust1.pass);
  char temp[20] = "cust_acc/";
  strcat(temp,name);
  char temp2[20] = ".txt";
  strcat(temp,temp2);
  FILE *fp;
  fp = fopen(temp,"w");
  fputs(cust1.pass,fp);
  fclose(fp);
  
  char temp3[20] = "cust_details/";
  char temp4[10] = ".txt";
  strcpy(name2,cust1.name);
  strcat(temp3,name2);
  strcat(temp3,temp4);
  
  fp = fopen(temp3, "w");
  fprintf(fp,"---Account Details---\n\n");
  fprintf(fp,"Name : %s\nAccount No: %d\nBalance: %d\n",cust_name,cust1.accno,0);
  
  fclose(fp);
  fp = fopen(temp3, "r");
  if(fp){
  	printf("-----------------------");
    printf("\nSuccessfully Created\n");
    char c;
    c = fgetc(fp);
    while(c != EOF){
      printf("%c",c);
      c = fgetc(fp);
    }
	fclose(fp);
	
    fp = fopen("cust.txt", "a+");
    fprintf(fp,"\n%d \t %s \t %d \t",cust1.accno,cust_name,0);
    fclose(fp);
    printf("Succesfully Done\n");

    printf("-----------------------");
  }
    else{
      printf("Something Went Wrong");
    }
    
   
  }

void change_adminpass(char str[30]){
	char pass[20];
	printf("\n------- Change Password -------\n\n");
	printf("Enter NEW Password: ");
	scanf("%s",pass);
	
	FILE *fp = fopen(str,"w");
	fputs(pass,fp);
	fclose(fp);
	printf("Successfully Changed\n\n");
	
	
}
