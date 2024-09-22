#include <string.h>
#include <stdlib.h>

void send_money(char str[30]){
	system("CLS");
	char temp[20] = "cust_details/";
	strcat(temp,str);
	char temp2[20] = ".txt";
	strcat(temp,temp2);
	
	char name[20];
	int amount;
	char line[1000];
	printf("\n------- Send Money -------\n\n");
	printf("Enter Name of the person to send: ");
	scanf("%s",name);
	
	
	
	
	char name2[20] = ".txt";
	strcat(name,name2);
	char name3[20] = "cust_details/";
	strcat(name3,name);
	int flag =0;
	FILE *fp3 = fopen(name3,"r");
	if(fp3){
		flag = 1;
	}
	fclose(fp3);
	if(flag==1){
	printf("How much amount: ");
	scanf("%d",&amount);
	
	FILE *fp = fopen(temp, "r");
	int lin = 5;
	int count = 0;
	int sum =0;
	int d;
	while(fgets(line,1000,fp) != NULL){
		count++;
		if(count == lin){
			for(int i=0; line[i] != '\0'; i++){
				if((line[i] >='0') && (line[i] <= '9')){
					d = line[i] - 48;
					sum = sum*10 + d;
				}
			}
		}
	}
	fclose(fp);
	if(sum>=amount){
	
	fp = fopen(temp,"r");
	FILE *fp1 = fopen("temp.txt","w");
	count = 0;
	while(fgets(line,1000,fp) != NULL){
		count++;
		if(count == lin){
			fprintf(fp1,"Balance : %d\n",sum - amount);
			
		}
		else{
			fputs(line,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove(temp);
	rename("temp.txt",temp);
	
	fp3 = fopen(name3,"r");
	
	int sum1=0;
	count =0;
	FILE *fp2 = fopen("temp1.txt","w");
	while(fgets(line,1000,fp3) != NULL){
		count++;
		if(count == lin){
			for(int i=0; line[i] != '\0'; i++){
				if(line[i] >='0' && line[i]<= '9'){
					int d = line[i] - 48;
					sum1 = sum1*10 + d;
				}
			}
			fprintf(fp2,"Balance : %d\n",sum1+amount);
		}
		else{
			fputs(line,fp2);
		}
		
	}
	fclose(fp2);
	fclose(fp3);
	remove(name3);
	
	rename("temp1.txt",name3);
	printf("Succesfully Sended!\n\n");
	printf("Your Total Balance : %d\n",sum-amount);
	
	
	
	
	
	
	
}
else{
	printf("Enough Balance Not have in your account\n");
}
   }
   else{
   	printf("User Not Found to send\n");
   }
}

void check_userbal(char str[20]){
	system("CLS");
	printf("\n------- Balance Check -------\n\n");
	char temp[20] = "cust_details/";
	strcat(temp,str);
	char temp2[20] = ".txt";
	strcat(temp,temp2);
	FILE *fp = fopen(temp, "r");
	int lin = 5;
	int count = 0;
	int sum =0;
	char line[1000];
	int d;
	while(fgets(line,1000,fp) != NULL){
		count++;
		if(count == lin){
			for(int i=0; line[i] != '\0'; i++){
				if((line[i] >='0') && (line[i] <= '9')){
					d = line[i] - 48;
					sum = sum*10 + d;
				}
			}
		}
	}
	fclose(fp);
	printf("Your Balance : %d \n",sum);
	
	
	
}

void change_userpass(char str[30]){
	char pass[20];
	printf("\n------- Change Password -------\n\n");
	printf("Enter NEW Password: ");
	scanf("%s",pass);
	
	FILE *fp = fopen(str,"w");
	fputs(pass,fp);
	fclose(fp);
	printf("Successfully Changed\n\n");
	
	
}
