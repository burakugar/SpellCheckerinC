#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removePunc(char temp[20]){   /* function that removes a punctuation from a string */
	int i;
	int j;
	for ( i = 0; temp[i] != '\0'; ++i) {
      /* enter the loop if the character is not an alphabet */
      /* and not the null character */
      	while (!(temp[i] >= 'a' && temp[i] <= 'z') && !(temp[i] >= 'A' && temp[i] <= 'Z') && !(temp[i] == '\0')) {
        		for (j = i; temp[j] != '\0'; ++j) {
            /* if jth element of line is not an alphabet */
            /* assign the value of (j+1)th element to the jth element */
            temp[j] = temp[j + 1];
         }
         temp[j] = '\0';
      }
   }
}

int doeshavePunc(char str[20]){
	/* ! " # $ % & ' ( ) * +, - . / : ;  ? @ [ \ ] ^ _ ` { | } ~ */
int i;
char arr[30];
strcpy(arr,"*!#$%&'()*+,-./:;?@[]^_`{|}~""");
int n;
int k=0; /* assingning all the puncts to an array to check any string has a punc ot not */
int flag=0;
for(i=0;i<strlen(str);i++){
	for(k=0;k<29;k++){
		if(str[i]==arr[k]){
		flag=1; /* using flag control */
		return flag;
			}
		else{
			continue;
			}
		}
	}
return flag;
}
int indexofthePunc(char* str){
	int i;
	int j;
	for ( i = 0; str[i] != '\0'; ++i) {
      // enter the loop if the character is not an alphabet
      // and not the null character
      	while (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '\0')) {
        		for (j = i; str[j] != '\0'; ++j) {
        	return j;
         }
      }
   }
}
char findPunc(char* str){
	int i;
	int j;
	for ( i = 0; str[i] != '\0'; ++i) {
      // enter the loop if the character is not an alphabet
      // and not the null character
      	while (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '\0')) {
        		for (j = i; str[j] != '\0'; ++j) {
        	return str[j];
         }
      }
   }
}
int numberofDiff(char str1[20], char str2[20]){
	int i,j; /* function that calculates the number of difference between two string using iterative algorithm ( for loops) */
	int len1=strlen(str1);
	int len2=strlen(str2);
	int count=0;
	j=0;
	if(len2>=len1){ /* comparing the string lengths */
	for(i=0;i<len2;i++){
			if(str1[i]!=str2[j]){
				count++;
			}
		j++;
		}
	}
	else{
	for(i=0;i<len1;i++){
			if(str1[i]!=str2[j]){
				count++;
			}
		j++;
		}	
	}
	return count;
}
int findfirstDiff(char str1[20], char str2[20]){ /* function that finds the difference between two string */
	int i,j=0,flag;
	int len1=strlen(str1);
	int len2=strlen(str2);
	if(len2>=len1){
		for(i=0;i<len2;i++){
			if(str1[i]!=str2[j]){
				flag=i; /* if find the first difference then assign it to flag value */
				goto y;
			}
		j++;
		}
	}
	else{
		for(i=0;i<len1;i++){
			if(str1[i]!=str2[j]){
				flag=i;
				goto y;
			}
		j++;
		}	
	}
	y:
	return flag; /* return the flag value which is the index of first uncommon char between two string */ 
}

void addChar( char s[], char c, int index )
{ /* function that add a given char to the string with given index */
    int i = 0;

    while ( i < index && s[i] ) ++i;

    if ( i == index )
    {
        do 
        {
            char tmp = s[i];
            s[i++] = c;
            c = tmp;
        } while ( c );

        s[i] = c;
    }
}
int checkVowel(char* str){ /* checks whether a char is vowel or not */
	 // evaluates to 1 if variable c is a lowercase vowel
    char vowels[11];
	strcpy(vowels,"aeiouAEIOU"); /* assing all the chars to an char array then compare them one by one using for loop */
	int i,k,flag=0;
	for(i=0;i<strlen(str);i++){
		for(k=0;k<strlen(vowels);k++)
		{
		if(str[i]==vowels[k]){
			flag=i;
			goto z;
			}
		}
	}
	z:
	return flag;
}
int checkifVowelchar(char ch){ /* function that checks whether a CHAR is vowel or not using same method above */
	int i=0,flag=0;
	char vowels[11];
	strcpy(vowels,"aeiouAEIOU");
	for(i=0;i<strlen(vowels);i++){
		if(vowels[i]==ch){
			flag=1;
			goto r;
		}
	}
	r:
	return flag;
}
int checkConsonant(char* str){ /* function that returns the first consonant char in a string as an index */
	int i,flag=0;
	for(i=0;i<strlen(str);i++){
	 if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') && checkifVowelchar(str[i])==0){
			flag=i;
		}
	}
	return flag;
}

char* uppertoLower(char str[20]){ /* function that makes an upper letter string to lowerletter */
   int i;
   for(i=0;i<=strlen(str);i++){
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;
   }
   	return str;
}
char* lowertoUpper(char str[20]){ /* function that makes an lower letter string to upper letter */
   int i;
   for (i = 0; str[i]!='\0'; i++) {
      if(str[i] >= 'a' && str[i] <= 'z') {
         str[i] = str[i] - 32;
      }
   }
   return str;
}
int findnumofWords(){  /* function that finds the number of words in a file */
	FILE* fp= fopen("text.txt","r");
	int count=0;
	char buffer[20];
	while(!feof(fp)){
		fscanf(fp,"%s",buffer);
		count++;
	}
	return count;
}
int findinT(char str[20], char str1[20]){
	FILE* fp2=fopen("dictionary.txt","r");
	char dic[20];
	int flag=0;
	int i=0;
	while(!feof(fp2)){ //function checks whether given two string in the same file or not */
		fscanf(fp2,"%s",dic);
		if(strcmp(str,dic)==0||strcmp(str1,dic)==0){
			flag=i;
		}
		i++;
	}
	fclose(fp2);
	return flag;
}
int findinC(char str[20]){ 
	FILE* fp1=fopen("text.txt","r");
	char dic[20];
	int flag=0;
	while(!feof(fp1)){
		fscanf(fp1,"%s",dic);
		if(doeshavePunc(dic)==1 && strlen(dic)==1){
			flag=1;
		}
	}
	fclose(fp1);
	return flag;
}
int checkifUpper(char str[20]){ /* controls if a char is upper or not */
	int i;
	int count=0;
	int len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			count++;
		}
	}
	if(count== len){
		return 1;
	}
	else{
		return 0;
	}
}
int checkifLower(char str[20]){ /* controls if a char is lower or not */
	int i;
	int count=0;
	int len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			count++;
		}
	}
	if(count== len){
		return 1;
	}
	else{
		return 0;
	}
}

void check_diff_2(int* first,int* sec, char temp[20],char dic[20]){ /* function that finds the indexes of uncommon characters of given 2 string */
	int i,j;
	int len1=strlen(temp);
	int len2=strlen(dic);
	j=0;
	int flag=0;
	if(len2>=len1){
	for(i=0;i<len2;i++){
			if(temp[i]!=dic[j] && flag==0){
				flag=1;
				*first=i;
			}
			else if(temp[i]!=dic[j] && flag==1){
				flag=2;
				*sec=i;
				goto g;
			}
		j++;
		}
		
		g:;
	}
	else{
	for(i=0;i<len1;i++){
			if(temp[i]!=dic[j] && flag==0){
				flag=1;
				*first=i;
			}
			else if(temp[i]!=dic[j] && flag==1){
				flag=2;
				*sec=i;
				goto g;
			}
		j++;
		}	
	}
}
void fix_spelling_error(char* temp,char* correct,FILE* fp2){ 
	char dic[20];
	char dic1[20];
	if(findinC(temp)==1){
	/*  check if the given word a single letter punct or not */
		goto t;
	}
	int key1=0, key2=0,key3=0;
	int flag1=0, flag2=0,flag3=0, flag4=0;
	char buffer[20];
	char firstocc[20];
	char secocc[20];
	char thirdocc[20];
	char t[20];
	char r_dic[20];
	int firstdiff,u1;
	strcpy(buffer,temp); // copying the char array to temp buffer 
	strcpy(t,temp);
	removePunc(t);
	char punc;
	int ch,index,numberofDic=0,flag=1,count=0;
	/********************************* IMPLEMENT VOWEL AND CONSONANT SIMILARITIES ****************************/
	numberofDic=findnumofWords(); 
	while(!feof(fp2)){
		l:
		fscanf(fp2, "%s", dic);
		count=0;
		if(strcmp(dic,t)!=0){
				count++;
			}
		if(findinT(t,temp)!=0){	
			goto i;
		}
		else if(doeshavePunc(temp)==0 && strcmp(lowertoUpper(temp),dic)==0){
			lowertoUpper(temp);
			goto m;
		}
		else if(doeshavePunc(temp)==0 && strcmp(uppertoLower(temp),dic)==0){
			uppertoLower(temp);
			goto m;
		}
		else if(doeshavePunc(temp)==1 && strcmp(lowertoUpper(temp),dic)==0){
			lowertoUpper(temp);
			index=indexofthePunc(temp);
			punc=findPunc(temp);
			removePunc(temp);
			strcpy(temp,dic);
			addChar(temp,punc,index);
			goto m;
		}
		else if(doeshavePunc(temp)==1 && strcmp(uppertoLower(temp),dic)==0){
			uppertoLower(temp); /* change array to upper to lower */
			index=indexofthePunc(temp); /* save punctuations index */
			punc=findPunc(temp); /* save puncs itself */
			removePunc(temp); /* remove the punc */
			strcpy(temp,dic);
			addChar(temp,punc,index); /* add the punc at the end */
			goto m;
		}
		m:
		strcpy(t,temp);
		removePunc(t); /*removing punctuations */
		/* controlling if the characters(first different char) is passing through consonant to vowel */
		if((numberofDiff(t,dic)==1)||(count==numberofDic && numberofDiff(t,dic)==1)&& strcmp(dic,t)!=0){
				firstdiff=findfirstDiff(t,dic);
				if(checkifVowelchar(dic[firstdiff])==1 && checkifVowelchar(dic[firstdiff-1])==0 && flag1==0){
					strcpy(firstocc,dic);
					flag2=1;
					key1=1;
					flag1=1;
					goto l;
				}
				 else if(checkifVowelchar(dic[firstdiff])==1 && checkifVowelchar(dic[firstdiff-1])==0 && flag2==1){
					strcpy(secocc,dic);
					flag3=1;
					flag1=2; 
					flag2=2;
					key2=1;
					goto l;
				}
				else if(checkifVowelchar(dic[firstdiff])==1 && checkifVowelchar(dic[firstdiff-1])==0 && flag3==1){
					strcpy(thirdocc,dic);
					flag3=2;
					key3=1;
				}
				else{
					continue;
				}
			}
			if(key1==1&& key2==1 && key3==0){
				if(doeshavePunc(temp)==0){
					strcpy(temp,secocc);
					goto t;
				}
				else{
				index=indexofthePunc(temp);
				punc=findPunc(temp);
				strcpy(temp,secocc);
				addChar(temp,punc,index);
				}
				goto t;
			}
			else if(key1==1&& key2==1 && key3==1){
				if(doeshavePunc(temp)==0){
					strcpy(temp,secocc);
				}
				else{
				index=indexofthePunc(temp);
				punc=findPunc(temp);
				strcpy(temp,secocc);
				addChar(temp,punc,index);
				goto t;
				}
			}
			else if(key1==1&& key2==0 && key3==0){
				if(doeshavePunc(temp)==0){
					strcpy(temp,firstocc);
					goto t;
				}
				else{
				index=indexofthePunc(temp);
				punc=findPunc(temp);
				strcpy(temp,firstocc);
				addChar(temp,punc,index);
				}
				goto t;
			}
		
		}
	i:
	/*******************************                                            ******************************/
	fseek(fp2,0,SEEK_SET);
	while(!feof(fp2)){
		fscanf(fp2, "%s", dic);
		strcpy(r_dic,dic);
		removePunc(r_dic);
		if(strcmp(dic,temp)==0){
			goto t;
		}
		/******************************** HANDLING THE UPPER OR LOWER CASES ****************************/
		/* there are 4 possibilities: 1. string does not have punc but dictionary version is uppercase when string is lowercase
							2. string does not have punc but dictionary version is lowercase when string is uppercase
							3. string have punc but dictionary version is uppercase when string is lowercase
							4. string have punc but dictionary version is lowercase when string is uppercase */
							
		else if(doeshavePunc(temp)==0 && strcmp(lowertoUpper(temp),dic)==0){
			lowertoUpper(temp);
			goto t;
		}
		else if(doeshavePunc(temp)==0 && strcmp(uppertoLower(temp),dic)==0){
			uppertoLower(temp);
			goto t;
		}
		else if(doeshavePunc(temp)==1 && strcmp(lowertoUpper(temp),dic)==0){
			lowertoUpper(temp);
			index=indexofthePunc(temp);
			punc=findPunc(temp);
			removePunc(temp);
			strcpy(temp,dic);
			addChar(temp,punc,index);
			goto t;
		}
		else if(doeshavePunc(temp)==1 && strcmp(uppertoLower(temp),dic)==0){
			uppertoLower(temp);
			index=indexofthePunc(temp);
			punc=findPunc(temp);
			removePunc(temp);
			strcpy(temp,dic);
			addChar(temp,punc,index);
			goto t;
		}
	
		else if(strcmp(t,dic)==0 && strcmp(t,dic)==0 && doeshavePunc(temp)==1 ){
			index=indexofthePunc(temp);
			punc=findPunc(temp);
			removePunc(temp);
			strcpy(temp,dic);
			addChar(temp,punc,index);
			goto t;
		}
		else if(strcmp(t,dic)!=0 && strcmp(t,dic)==0 && doeshavePunc(temp)==0){
			continue;
		}
		}
	fseek(fp2,0,SEEK_SET);
	while(!feof(fp2)){
		fscanf(fp2, "%s", dic);
		if(strcmp(dic,temp)==0){
			break;
		}
		else if(strcmp(dic,temp)==0 &&doeshavePunc(temp)==0 ){
			strcpy(temp,dic);
			break;
		}
		else if(strcmp(dic,temp)==0 &&doeshavePunc(temp)==1 ){
			index=indexofthePunc(temp);
			punc=findPunc(temp);
			removePunc(temp);
			strcpy(temp,dic);
			addChar(temp,punc,index);
		}
		else{
		strcpy(t,temp);
		removePunc(t);
		if(numberofDiff(buffer,dic)==1 && doeshavePunc(buffer)==0){
			if(strlen(buffer)>strlen(dic)){
				continue;
			}
			else
			strcpy(temp,dic);
			}
		
		else if(numberofDiff(buffer,dic)==1 && doeshavePunc(buffer)==1){
				if(strcmp(buffer,dic)!=0){
				continue;
			}
			else{
				if(numberofDiff(t,dic)==0){
				index=indexofthePunc(temp);
				punc=findPunc(temp);
				removePunc(temp);
				strcpy(temp,dic);
				addChar(temp,punc,index);
				}
			else{
			index=indexofthePunc(temp);
			punc=findPunc(temp);
			removePunc(temp);
			strcpy(temp,dic);
			addChar(temp,punc,index);
				}
			}
			}
		else if(numberofDiff(buffer,dic)==2 && doeshavePunc(temp)==0){
			if(strcmp(buffer,dic)!=0){
				continue;
			}
			else
			strcpy(temp,dic);
			
		}
		else if(numberofDiff(buffer,dic)==2 && doeshavePunc(temp)==1){
			if(strcmp(buffer,dic)!=0){
				if(numberofDiff(t,dic)==1){
				index=indexofthePunc(temp);
				punc=findPunc(temp);
				removePunc(temp);
				strcpy(temp,dic);
				addChar(temp,punc,index);
				}
				else{
					if(strcmp(t,dic)==0){
						strcpy(t,dic);
						index=indexofthePunc(temp);
						punc=findPunc(temp);
						addChar(t,punc,index);
						strcpy(temp,t);
					}
					else{
					
					continue;
					}
				}

			}
			else{
				if(numberofDiff(t,dic)==1){
				index=indexofthePunc(temp);
				punc=findPunc(temp);
				removePunc(temp);
				strcpy(temp,dic);
				addChar(temp,punc,index);
					
				}
				else{
				continue;
				}
			}
		
		}
		
		}
	
	}
	t:;
}

/* SECOND CHECK */
void fix_spelling_error_2(char* temp,FILE* fp2,FILE* fp3){
	char dic[20];
	char t[20];
	char buffer1[20];
	char buffer2[20];
	char buffer3[20];
	int index;
	int flag1=0,flag2=0,flag3=0;
	int key1=0,key2=0,key3=0;
	char punc;
	int first,second;
	strcpy(t,temp);
	removePunc(t); /* t is the array does not include punctuation */
	if(doeshavePunc(temp)==1){    /* CONTROLLING IF THE TEMP HAS PUNC*/
		index=indexofthePunc(temp);
		punc=findPunc(temp);
	}
	if(strcmp(lowertoUpper(t),dic)==0){
		strcpy(t,lowertoUpper(t));
	}
	else if(strcmp(uppertoLower(t),dic)==0){
		strcpy(t,uppertoLower(t));	
	}
	while(!(feof(fp2))){
		x:
		fscanf(fp2,"%s",dic);
		if(strcmp(t,dic)==0){
			goto w;						
		}
		else{
		
			if(numberofDiff(t,dic)==2 && (strlen(t)==strlen(dic))){
			check_diff_2(&first,&second,temp,dic);
	
				if(checkifVowelchar(t[first])==1 && checkifVowelchar(t[first-1])==0 && flag1==0 && checkifVowelchar(t[second])==1 && checkifVowelchar(t[second-1])==0){
					strcpy(buffer1,dic);
			/* first occurence in the dictionary */
					flag1=1;
					flag2=1;
					key1=1;
					goto x;
				}
				else if(checkifVowelchar(t[first])==1 && checkifVowelchar(t[first-1])==0 && flag2==1 && checkifVowelchar(t[second])==1 && checkifVowelchar(t[second-1])==0){
					strcpy(buffer2,dic);
					/* second occurence in the dictionary */
					flag2=2;
					flag3=1;
					key2=1;
					goto x;
				}
				else if(checkifVowelchar(t[first])==1 && checkifVowelchar(t[first-1])==0 && flag3==1 && checkifVowelchar(t[second])==1 && checkifVowelchar(t[second-1])==0){
					strcpy(buffer3,dic);
					/* third occurence in the dictionary */
					flag3=2;
					key3=1;
					
				}
			if(key1==1 && key2==1 && key3==1){
				strcpy(t,buffer2);
			}
			else if(key1==1 && key2==1 && key3==0){
				strcpy(t,buffer2);
			}
			else if(key1==1 && key2==0 && key3==0){
				strcpy(t,buffer1);
			}
			
		if(doeshavePunc(temp)!=0){
				addChar(t,punc,index);
		}
			strcpy(temp,t);
		}
		else{
			continue;
		}
	}
	w:; 
	}
}

int main(){
	FILE* fp1= fopen("text.txt","a+");
	FILE* fp2= fopen("dictionary.txt","r");
	FILE* fp3= fopen("text_last.txt","w");
	//FILE* fp3= fopen("dictionary.txt","r+");
	if(fp1==NULL||fp2==NULL){
		printf("Error has been occured when opening the files");
	}
	int i=0,j,count=0,index;
	int len1,len2;
	char c;
	char storage;
	int flag;
	char temp[20]; // volatile char* to count number of words in the text.txt 
	char dic[20];
	char correct[20];
	while(!(feof(fp1))){
		fp2= fopen("dictionary.txt","r");
		fscanf(fp1,"%s",temp);
		fix_spelling_error(temp,correct,fp2);
		fix_spelling_error_2(temp,fp2,fp3);
		fprintf(fp3,"%s ",temp);
		fclose(fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
