#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void withdraw(){
	system("CLS");
	char name[20];
	int amount;
	int a;
	printf("\n------- Withdraw -------\n\n");
	printf("Enter User Name: ");
	scanf("%s",name);
	char temp1[20] = "cust_details/";
	char temp2[20] = ".txt";
	strcat(temp1,name);
	strcat(temp1,temp2);
	FILE *fp = fopen(temp1,"r");
	char c;
	c = fgetc(fp);
	while(c!=EOF){
		printf("%c",c);
		c = fgetc(fp);
	}
	printf("\n\n");
	fclose(fp);
	printf("Enter Amount To Withdraw: ");
	scanf("%d",&amount);
	fp = fopen(temp1, "r");
	FILE *fp1 = fopen("temp.txt", "w");
	char line[1000];
	int count =0;
	int lin =5;
	int sum =0;
	while(fgets(line,1000,fp) != NULL){
		count++;
		char temp3[10];
		char t[10];
		char b[10];
		
		if(count == lin){
			for(int i=0; line[i]!='\0'; i++){
				if((line[i] >='0')&& (line[i]<='9') ){
					int d = line[i] - 48;
					sum = sum*10 +d;
				}
			}
			
			fprintf(fp1,"Balance : %d\n",sum-amount);
		}
		else{
			fputs(line,fp1);
		}
		
	}
	
	fclose(fp);
	fclose(fp1);
	remove(temp1);
	rename("temp.txt",temp1);
	
	printf("Successfully Withdrawn\n\n");
	fp = fopen(temp1, "r");
	c = fgetc(fp);
	while(c!=EOF){
		printf("%c",c);
		c = fgetc(fp);
	}
	printf("\n");
	fclose(fp);

	
	
	
	
	
}

void deposit(){
	system("CLS");
	char name[20];
	int amount;
	int a;
	printf("\n------- Deposit -------\n\n");
	printf("Enter User Name: ");
	scanf("%s",name);
	char temp1[20] = "cust_details/";
	char temp2[20] = ".txt";
	strcat(temp1,name);
	strcat(temp1,temp2);
	FILE *fp = fopen(temp1,"r");
	char c;
	c = fgetc(fp);
	while(c!=EOF){
		printf("%c",c);
		c = fgetc(fp);
	}
	printf("\n\n");
	fclose(fp);
	printf("Enter Amount To Deposit: ");
	scanf("%d",&amount);
	fp = fopen(temp1, "r");
	FILE *fp1 = fopen("temp.txt", "w");
	char line[1000];
	int count =0;
	int lin =5;
	int sum =0;
	while(fgets(line,1000,fp) != NULL){
		count++;
		char temp3[10];
		char t[10];
		char b[10];
		
		if(count == lin){
			for(int i=0; line[i]!='\0'; i++){
				if((line[i] >='0')&& (line[i]<='9') ){
					
					int d = line[i] - 48;
					sum = sum*10 +d;
				}
			}
			
			fprintf(fp1,"Balance : %d\n",sum+amount);
		}
		else{
			fputs(line,fp1);
		}
		
	}
	
	fclose(fp);
	fclose(fp1);
	remove(temp1);
	rename("temp.txt",temp1);
	
	printf("Successfully Deposit\n\n");
	fp = fopen(temp1, "r");
	c = fgetc(fp);
	while(c!=EOF){
		printf("%c",c);
		c = fgetc(fp);
	}
	printf("\n");
	fclose(fp);

	
	
	
	
	
}


void user_bal(){
	system("CLS");
	printf("\n-------Balance Check-------\n\n");
	char name[20];
	int amount;
	int a;
	printf("Enter User Name: ");
	scanf("%s",name);
	char temp1[20] = "cust_details/";
	char temp2[20] = ".txt";
	strcat(temp1,name);
	strcat(temp1,temp2);
	FILE *fp = fopen(temp1,"r");
	char c;
	c = fgetc(fp);
	while(c!=EOF){
		printf("%c",c);
		c = fgetc(fp);
	}
	printf("\n\n");
	fclose(fp);	
}

void change_pass(char str[30]){
	char pass[20];
	printf("\n------- Change Password -------\n\n");
	printf("Enter NEW Password: ");
	scanf("%s",pass);
	
	FILE *fp = fopen(str,"w");
	fputs(pass,fp);
	fclose(fp);
	printf("Successfully Changed\n\n");
	
	
}
