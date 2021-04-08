
//change upper case to lower for english words
void upToLowEn(char*input)
{
	int i=0;
	
	while(input[i]!='\0')
	{
	
		switch(input[i])
		{
			case 'A':input[i]='a';break;
			case 'B':input[i]='b';break;
			case 'C':input[i]='c';break;
			case 'D':input[i]='d';break;
			case 'E':input[i]='e';break;
			case 'F':input[i]='f';break;
			case 'G':input[i]='g';break;
			case 'H':input[i]='h';break;
			case 'I':input[i]='i';break;
			case 'J':input[i]='j';break;
			case 'K':input[i]='k';break;
			case 'L':input[i]='l';break;
			case 'M':input[i]='m';break;
			case 'N':input[i]='n';break;
			case 'O':input[i]='o';break;
			case 'P':input[i]='p';break;
			case 'Q':input[i]='q';break;
			case 'R':input[i]='r';break;
			case 'S':input[i]='s';break;
			case 'T':input[i]='t';break;
			case 'U':input[i]='u';break;
			case 'V':input[i]='v';break;
			case 'W':input[i]='w';break;
			case 'X':input[i]='x';break;
			case 'Y':input[i]='y';break;
			case 'Z':input[i]='z';break;
		}
	    i++;
	}
}


//change upper case to lower for ukrainian words
void upToLowUkr(char *input)
{
	int k=0;
	
	while(input[k]!='\0')
	{
	
		switch(input[k])
		{
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
			case '�':input[k]='�';break;
		}
		k++;
	}  
}

//for special case change ? to letter i
void funcChangeI(char *str)
{
	int k=0;
	while(str[k]!='\0')
	{
	  if(str[k]=='?')str[k]='i';
	  k++;
	 	
	}
}

//checking presence of gaps
void symbolDel(char *input)
{
	
	char* temp1=input;
	char* temp2=input;
    while(*temp1!='\0')
    {
    	if(*temp1==' ')
    	{
    		temp1++;
		}
		
		else if(*temp1!=' ')
		{
			*temp2=*temp1;
			temp2++;
			temp1++;
			if(*temp1==' ')
			{
				*temp2=*temp1;
				temp2++;
				temp1++;
			}
		}
	}
	*(temp2)='\0';
}

//change gaps to undercore
void changeGaps(char* input)
{
	int i;
	for(i=0;input[i]!='\0';i++)
	{
		if(input[i]==' ')input[i]='_';
	}
	//printf(" input %s",input);
}

