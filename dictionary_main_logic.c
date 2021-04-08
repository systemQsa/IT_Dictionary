//data input
char* type_input(int count_lines)
{

	int i=0,j=0,index=0;
	char* str;
	
	
	str=(char*)calloc(2,sizeof(char));
	do
	{
	    *(str+i)=getch();
	    while(str[index]!='\0')
	    {
	    	if(str[index]=='?')str[index]='i';
	    	index++;
		}
		while(str[0]=='e' && str[1]==13)
		{
			printf("\b\b");
			str[0]='e';
			return str;
		}
		 	
		while(str[0]=='u' && str[1]==13)	
		{
		  	printf("\b\b");
		  	str[0]='u';
		  	return str;
		}
	    
		if(str[i]==13)
		{
			str[i]='\0';
		    break;
		}
		
	    else if (str[i]==8)
        {
            if (i>0)
            {
                printf("%c%c%c",str[i],32,str[i]);
                realloc(str,sizeof(char)*i);
                i--;
            }
            continue;
        }
        else if(str[i]==27)
        {
        	return str;
		}
       
        printf("%c",str[i]);
		i++;
        str=(char*)realloc(str,sizeof(char)*(i+1));
    }while(1);
    
	return str;
}
//filling structures with english words
int fillStructEng(pWord* ENG)
{
	
	FILE* eng;
	
	char tmp_array[50];
	int numOfWord,i=0,numWordsTotal=0;
	
	eng=fopen("eng.txt","r");
   while(fscanf(eng,"%s%i",tmp_array,&numOfWord)!=EOF)
	{
	    numWordsTotal++;
	}
	
	(*ENG)=(pWord)malloc(sizeof(struct Word)*(numWordsTotal));
	
	rewind(eng);
	
	for(i=0;fscanf(eng,"%s%i",&(*ENG)[i].word,&(*ENG)[i].num)!=EOF;i++)
	{
		//printf(" struct %s %i\n",(*ENG)[i].word,(*ENG)[i].num);
	}
	 
	 fclose(eng);
     
     return numWordsTotal;
}


//filling structures with ukrainian words
int fillStructUk(pWord* UKR)
{
	char tmp_array[50];
	int i,numOfWord,numWordsTotal=0;;
	
	FILE*Ukr;
	
	Ukr=fopen("ukr.txt","r");
	
	while(fscanf(Ukr,"%s%i",tmp_array,&numOfWord)!=EOF)
	{
	    //funcChangeI(mas2);
	    numWordsTotal++;
	}
	
	(*UKR)=(pWord)malloc(sizeof(struct Word)*(numWordsTotal));
	
	rewind(Ukr);
	
	for(i=0;fscanf(Ukr,"%s%i",&(*UKR)[i].word,&(*UKR)[i].num)!=EOF;i++)
	{
		//funcChangeI((*UKR)[i].word);
		//printf(" struct %s %i\n",(*UKR)[i].word,(*UKR)[i].num);
	}

	fclose(Ukr);
	
	return numWordsTotal;
}


//compare input with word from database
int compare(char *word,char *input)
{
	int i,j;
	
	for(j=0;input[j]!='\0' && word[j]!='\0';j++)
	{
	    if(input[j]==' ' && word[j]=='_')
	    {
	    	input[j]='_';
	    }
	}
	
	for(i=0;word[i] || input[i];i++)
	{
	
		if(word[i]!=input[i])
		{
		 //printf("%s!=%s\n",word,input);	
		 return -1;	
		}
	  //printf("%s=%s\n",word,input);
	}
	
	return 0;
}

//seaching the word in database [english to ukrainian]
int searchEngToUkr(char* input,int numWordsEng,int numWordsUkr,pWord* language,pWord* UKR)
{
    int i,j,flag=0,wordNum;
	
	for(i=0;i<numWordsEng;i++)
	{
		if(compare((*language)[i].word,input)==0)
		{
		    flag=1;
		   	wordNum=(*language)[i].num;
		   	//printf(" %s",(*ENG)[i].word);
		    break;
		}
		
	}
	
	for(i=0;i<numWordsUkr;i++)
	{
	    if(wordNum==(*UKR)[i].num)
		{
			for(j=0;(*UKR)[i].word[j]!='\0';j++)
			{
				
				if((*UKR)[i].word[j]=='_')
				{
					(*UKR)[i].word[j]=' ';
					
				}
			}
			
			printf("%s",(*UKR)[i].word);
			break;
		}
			
	}
	
	if(flag==0)
	{
	    return 1;
	}
    
	return 0;
}

	
//searching the word in database [ukrainian to english]
int searchUkrToEn(char* input,int numWordsEng,int numWordsUkr,pWord* ENG,pWord* UKR)
{
	int i,j,flag=0,wordNum;
	char key;
	
	for(i=0;i<numWordsUkr;i++)
	{
		//funcChangeI((*UKR)[i].word);
		//funcChangeI(input);
		if(compare((*UKR)[i].word,input)==0)
		{
			flag=1;
			wordNum=(*UKR)[i].num;
			//printf(" %s",(*UKR)[i].word);
		    break;
	    }
		
	}
	
	for(i=0;i<numWordsEng;i++)
	{
		if(wordNum==(*ENG)[i].num)
		{
			for(j=0;(*ENG)[i].word[j]!='\0';j++)
			{
				if((*ENG)[i].word[j]=='_')
				{
					(*ENG)[i].word[j]=' ';	
				}
			}
			
			printf("%s",(*ENG)[i].word);
			break;
		}
	}
	
	if(flag==0)
	{
		return 1;
	}
	
	return 0;
}



//write the new word and it`s translation to the file
//[english to ukrainian]
int createWordEn(pWord *ENG,pWord* UKR)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD p;
	COORD point;
	
	FILE *eng,*ukr;
	eng=fopen("eng.txt","a+");
	ukr=fopen("ukr.txt","a+");
	
	char eng_w[200],ukr_w[200];
	int numOfWordsEng,numOfWordsUkr,i,j,numScan=2,words_count=0;
	
	if(eng==NULL || ukr==NULL)return 1;
	while(words_count=fscanf(eng,"%s%i",eng_w,&numOfWordsEng)!=EOF);
    
	//funcChangeI(ukr_w);
	while(fscanf(ukr,"%s%i",ukr_w,&numOfWordsUkr)!=EOF);
	
	if(numOfWordsEng==numOfWordsUkr)
	{
        point.X=41;
        point.Y=1;
        SetConsoleCursorPosition(hConsole,point);
        SetConsoleTextAttribute(hConsole, (WORD) ((13 << 2) | 14));
	    printf("PRESS SHIFT + '*' + ENTER TO STOP\n");
	    
	    for(i=1;i<=200;i++)
	    { 
			printf("enter english word\n");
			if(numScan)numScan++;
			gets(eng_w);
			changeGaps(eng_w);
			*ENG=(pWord)realloc(*ENG,sizeof(struct Word)*(words_count+i));
			*ENG+=words_count; 	
		    fflush(stdin);
		    
		    for(j=1;j<=i;j++)
			{
				strcpy((*ENG)[j].word,eng_w);
				(*ENG)[j].num=numOfWordsEng;
			    
			}
			
			if(numScan)numScan++;
			if(eng_w[0]=='*')
			{
				fclose(eng);
	        	fclose(ukr);
	        	point.X=50;
            	point.Y=10;
            	SetConsoleCursorPosition(hConsole,point);
	        	printf("THANK YOU!\n");
	        	sleep(1);
	        	break;
	    	}
	
	    	printf("enter ukrainian word\n");
	    	if(numScan)numScan++;
			gets(ukr_w);
			changeGaps(ukr_w);
			
			*UKR=(pWord)realloc(*UKR,sizeof(struct Word)*(words_count+i));
			*UKR+=words_count;
			fflush(stdin);
			
			for(j=1;j<=i;j++)
			{
			    strcpy((*UKR)[j].word,ukr_w);
				(*UKR)[j].num=numOfWordsEng;
			}
			numOfWordsEng++;
			//funcChangeI(ukr_w);
			
			if(numScan)numScan++;
			if(ukr_w[0]=='*')
			{
				fclose(eng);
	        	fclose(ukr);
	        	point.X=50;
            	point.Y=10;
            	SetConsoleCursorPosition(hConsole,point);
	        	printf("THANK YOU!\n");
	        	sleep(1);
	        	break;
			}
		    //funcChangeI(ukr_w);
			//printf("%s    %s      num %i\n",eng_w,ukr_w,num);
			fprintf(ukr,"%s %i\n",ukr_w,numOfWordsEng);
			fprintf(eng,"%s %i\n",eng_w,numOfWordsEng);
		}
	    
    }
    else
	{
	   return -1;	
	} 

    
    return 0;
}


//write the new word and it`s translation to the file
//[ukrainian to english]
int createWordUkr(pWord *ENG,pWord*UKR)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD p;
	COORD point;
	
	FILE*eng,*ukr;
	eng=fopen("eng.txt","a+");
	ukr=fopen("ukr.txt","a+");
	
	char eng_w[200],ukr_w[200];
	int numOfWordsEng,numOfWordsUkr,index=0,j_index,words_count=0;
	
	if(eng==NULL || ukr==NULL)return 1;
	while(fscanf(eng,"%s%i",eng_w,&numOfWordsEng)!=EOF);
	
    while(fscanf(ukr,"%s%i",ukr_w,&numOfWordsUkr)!=EOF)
	{
		//funcChangeI(ukr_w);
	}
	
	if(numOfWordsEng==numOfWordsUkr)
	{
	    point.X=41;
        point.Y=1;
        SetConsoleCursorPosition(hConsole,point);
        SetConsoleTextAttribute(hConsole, (WORD) ((13 << 2) | 14));
	    printf("PRESS SHIFT + '*'+ ENTER TO STOP\n");
	    
        for(index=1;index<=200;index++)
	    {
		    printf("enter ukrainian word\n");
		    gets(ukr_w);
		    changeGaps(ukr_w);
		    if(ukr_w[0]=='*')
		    {
		    	fclose(ukr);
			    fclose(eng);
			    point.X=50;
                point.Y=10;
                SetConsoleCursorPosition(hConsole,point);
			    printf("THANK YOU!\n");
			    sleep(1);
			    break;
		    }
		      
		    printf("enter english word\n");
		    gets(eng_w);
		    changeGaps(eng_w);
		    
		    *ENG=(pWord)realloc(*ENG,sizeof(struct Word)*(words_count+index));
			*UKR=(pWord)realloc(*UKR,sizeof(struct Word)*(words_count+index));
			*ENG+=words_count;
			*UKR+=words_count;
			fflush(stdin);
			for(j_index=1;j_index<=index;j_index++)
			{
				strcpy((*UKR)[j_index].word,ukr_w);
				(*UKR)[j_index].num=numOfWordsEng;
				strcpy((*ENG)[j_index].word,eng_w);
				(*ENG)[j_index].num=numOfWordsEng;
			}
		    numOfWordsEng++;
		
		    if(eng_w[0]=='*')
			{
				fclose(ukr);
				fclose(eng);
				point.X=50;
            	point.Y=10;
            	SetConsoleCursorPosition(hConsole,point);
				printf("THANK YOU!\n");
				sleep(1); 
				break;
		   	}
		   	
		   	//funcChangeI(ukr_w);
			//printf("%s    %s\n",ukr_w,eng_w);
			fprintf(ukr,"%s %i\n",ukr_w,numOfWordsEng);
			fprintf(eng,"%s %i\n",eng_w,numOfWordsEng);
			
		}
	}
	else
	{
		return -1;
	}

	return 0;
}


