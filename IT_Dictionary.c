#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fixWord.h"
#include "functions_fix_input.c"
#include "header_main_logic.h"
#include "dictionary_main_logic.c"
#include "visual_ask_new_word.h"
#include "visual_func_ask_new_word.c"
#include<conio.h>


void check_input(int count_lines);

int main()
{

	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    char str[]=" IT-TEARMS DICTIONARY";
    int count_lines=4;
	
    CharToOem(str,str);
	SetConsoleTitle(str);
	
	check_input(count_lines);

	return 0;
}


//check input & decides to print translation
// or to ask add new word,else exit
void check_input(int count_lines)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD l;
	COORD point;
	
	char* input,strEng[]="English",strUkr[]="Ukrainian",string,
	      inform1[]="enter word",inform2[]="введіть слово";
    char key,symb,waitAnswer;
    int i=0,lenStr=0,x,y,rules=0,k,numsScan,
	numWordsEng=0,numWordsUkr=0,add;
	
    pWord ENG=NULL;
	pWord UKR=NULL;

    
    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 1));
    start:
	numWordsUkr=fillStructUk(&UKR);
    point.X=0;
	point.Y=0;
	SetConsoleCursorPosition(hConsole,point);
	      	
	while(key!='E' || key!='e' || key!='U' || key!='u')
    {
        x=31;
        FillConsoleOutputAttribute(hConsole, x << 4,500*1000, point, &l);
        SetConsoleTextAttribute(hConsole, (WORD) ((6 << 5) | 0));
        point.X=0;	
	    point.Y=0;
	    SetConsoleCursorPosition(hConsole,point);
	    FillConsoleOutputAttribute(hConsole, x << 6,10*12, point, &l);
        printf("TO START ENTER <E>-English  <U>-Ukrainian.Press ESC + ENTER to EXIT.<Y>-YES/<N>-NO.TO CHANGE LANGUAGE PRESS KEY + ENTER\n");
        SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 1));
       
        key=getch();
        if(key==27)
        {
    	    free(ENG);
    	    free(UKR);
    	    return;
	    }
	    
        switch(key)
        {
        	
            case 'E':
  	        case 'e':
  	        	
  	    	    point.X=52;
			    point.Y=1;
			    SetConsoleCursorPosition(hConsole,point);
			    SetConsoleTextAttribute(hConsole, (WORD) ((11 << 4) | 1));
			    eng:
				numWordsEng=fillStructEng(&ENG);
				printf("%s",strEng);
			    point.X=53;
			    point.Y=3;
			    SetConsoleCursorPosition(hConsole,point);
			    printf("%s",inform1);
  	            SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 1));
  		        if(printf)count_lines++;
  		        while(1)
  		        {
  		            point.X=0;
			        point.Y=count_lines;
			        SetConsoleCursorPosition(hConsole,point);
  		        	//input reception eng
					input=type_input(count_lines);//--------------
  		            count_lines++;
  		  	        symbolDel(input);
  		  	        lenStr=strlen(input);
					printf(" ");
  		  	        if(lenStr<=2)
  		  	        {
					    if(input[0]==27)
						{
						  free(ENG);
						  free(UKR);
						  return;	
						}
	                        if(input[0]=='E'|| input[0]=='e')
	                        {
	                    	
	                    	    point.X=0;
			                    point.Y=2;
			                    SetConsoleCursorPosition(hConsole,point);
			                    printf("    ");
			                    SetConsoleCursorPosition(hConsole,point);
	                    	    point.X=62;
			                    point.Y=1;
			                    SetConsoleCursorPosition(hConsole,point);
			                    printf("       ");
			                    point.X=53;
			                    point.Y=3;
			                    SetConsoleCursorPosition(hConsole,point);
			                    printf("               ");
			                    point.X=52;
			                    point.Y=1;
			                    SetConsoleCursorPosition(hConsole,point);
			                    SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
	                    	    goto eng;
	                        }
	                        
	                        
	                        
		                    if(input[0]=='U' || input[0]=='u')
	                        { 
	                            point.X=52;
			                    point.Y=1;
			                    SetConsoleCursorPosition(hConsole,point);
			                    printf("       ");
			                    point.X=53;
			                    point.Y=3;
			                    SetConsoleCursorPosition(hConsole,point);
			                    printf("            ");
			                    point.X=62;
			                    point.Y=1;
			                    SetConsoleCursorPosition(hConsole,point);
			                    SetConsoleTextAttribute(hConsole, (WORD) ((11 << 4) | 1));
	                            ukr1:
								point.X=62;
			                    point.Y=1;
			                    SetConsoleCursorPosition(hConsole,point);
								printf("%s",strUkr);
	                            point.X=53;
			                    point.Y=3;
			                    SetConsoleCursorPosition(hConsole,point);
			                    printf("%s",inform2);
	                            if(printf)count_lines++;
	                            
	                            
					            while(1)
		    	                {
		    	            	    point.X=0;
		    	            	    point.Y=count_lines;
		    	                    SetConsoleCursorPosition(hConsole,point);
		    	                    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 1));
                                    //input reception ukr
									input=type_input(count_lines);//------------
                                    count_lines++;
                                    symbolDel(input);
                                    lenStr=strlen(input);
                                    printf(" ");
                                    lenStr=strlen(input);
								    if(lenStr<=2)
                                    {
                                        if(input[0]==27)
                                        {
                                	        free(ENG);
                                	        free(UKR);
						                    return;
								        }
								    
								    
	                                    if(*input=='U' || *input=='u')
	                                    {      
	                            	        point.X=52;
			                                point.Y=1;
			                                SetConsoleCursorPosition(hConsole,point);
			                                printf("        ");
			                             
			                                point.X=53;
			                                point.Y=3;
			                                SetConsoleCursorPosition(hConsole,point);
			                                printf("%s",inform2);
			                                SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
	                            	        goto ukr1;
								        }
								    
								    
	                                    if(*input=='e' || *input=='E')
	                                    {
	                            	        point.X=62;
			                                point.Y=1;
			                                SetConsoleCursorPosition(hConsole,point);
			                                printf("         ");
			                                point.X=53;
			                                point.Y=3;
			                                SetConsoleCursorPosition(hConsole,point);
			                                printf("             ");
										    point.X=53;
			                                point.Y=3;
			                                SetConsoleCursorPosition(hConsole,point);
			                                printf("%s",inform1);
			                                point.X=52;
			                                point.Y=1;
			                            	SetConsoleCursorPosition(hConsole,point);
			                            	SetConsoleTextAttribute(hConsole, (WORD) ((11 << 4) | 1));
	                            	    	goto eng;
								    	}
				                	}
				                	
				                	//input change/search ukr->eng
				                    //funcChangeI(input);
							    	upToLowUkr(input);
							    	point.X=40;
			                    	point.Y=count_lines-1;
			                    	SetConsoleCursorPosition(hConsole,point);
			                        changeGaps(input);
									add=searchUkrToEn(input,numWordsEng,numWordsUkr,&ENG,&UKR);
			                    	
									if(add==1)
	                            	{
	                                	symb=askToAddWord();
	                                	if(symb=='y' || symb=='Y')
	                                	{
	                                 		system("cls");
	                                 		numsScan=createWordUkr(&ENG,&UKR);
	                                 		
	                                	}
	                                
	                                	else if(symb=='n' || symb=='N')
						            	{
							            	FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
			                            	point.X=46;
			                            	point.Y=13;
			                            	SetConsoleTextAttribute(hConsole, (WORD) ((11 << 4) | 1));
			                            	SetConsoleCursorPosition(hConsole,point);
			                            	printf("continue to translate?  ");
						                	waitAnswer=getch();
						                	
						                	if(waitAnswer=='y' || waitAnswer=='Y')
							            	{
							                	system("cls");
							                	count_lines=4;
		                	                	goto start;	
							            	}
							            
							            	else if(waitAnswer==27 || waitAnswer =='n' || waitAnswer=='N')
							            	{
								            	point.X=46;
			                                	point.Y=13;
			                                	SetConsoleCursorPosition(hConsole,point);
			                                	printf("                         ");
							                	FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
							                	free(ENG);
							                	free(UKR);
						                    	return;
							            	}
							            
							            	else
						                	{
						                		FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
						                		point.X=46;
			                            		point.Y=13;
			                            		SetConsoleCursorPosition(hConsole,point);
			                            		printf("                         ");
			                            		FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
						                		SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    				point.X=40;
			                					point.Y=14;
			                					SetConsoleCursorPosition(hConsole,point);
						        				printf("              WRONG KEY!                ");
							    				sleep(1);
							    				system("cls");
							    				count_lines=4;
							    				goto start;
											}
						            	}
						            
						            	else
						            	{
						            	    FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
						            		point.X=46;
			                            	point.Y=13;
			                            	SetConsoleCursorPosition(hConsole,point);
			                            	printf("                         ");
											FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);		
						            		SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							            	point.X=40;
			                				point.Y=14;
			                				SetConsoleCursorPosition(hConsole,point);
						        			printf("              WRONG KEY!                ");
							    			sleep(1);
							    			system("cls");
							    			count_lines=4;
							    			goto start;
								    	}
	                                 	
	                                	if(numsScan==0)
	                                	{
	                                 		system("cls");
	                                 		count_lines=4;
											goto start;	
										}	
									}
	                            }
	                   	 	}
	            	}
			        
			   	   //input change/search eng->ukr
					upToLowEn(input);
					point.X=30;
			        point.Y=count_lines-1;
			        SetConsoleCursorPosition(hConsole,point);
			        if(input[0]!='e' && input[1]!=13)
			        {
			        	point.X=40;
			         	point.Y=count_lines-1;
			        	SetConsoleCursorPosition(hConsole,point);
			            changeGaps(input);
						add=searchEngToUkr(input,numWordsEng,numWordsUkr,&ENG,&UKR);
						
						if(add==1)
			        	{
			        		symb=askToAddWord();
			        		if(symb=='y' || symb=='Y')
			        		{
			        			system("cls");
			        			numsScan=createWordEn(&ENG,&UKR);
			        		}
							
							else if(symb=='n' || symb=='N')
							{
								FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
			                	point.X=46;
			                	point.Y=13;
			                	SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
			                	SetConsoleCursorPosition(hConsole,point);
								printf("continue to translate?");
								waitAnswer=getch();
								
								if(waitAnswer=='y' || waitAnswer=='Y')
								{
							   		system("cls");
							   		count_lines=4;
		                	   		goto start;	
								}
								
								else if(waitAnswer==27 || waitAnswer =='n' || waitAnswer=='N')
								{
									point.X=46;
			                    	point.Y=13;
			                    	SetConsoleCursorPosition(hConsole,point);
			                    	printf("                         ");
							    	FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
							    	free(ENG);
									free(UKR);
						        	return;
							    }
							    
								else
						    	{
						    	    FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
						        	point.X=46;
			                    	point.Y=13;
			                    	SetConsoleCursorPosition(hConsole,point);
			                    	printf("                         ");
									FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);	
						    		SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    	point.X=40;
			                		point.Y=14;
			                		SetConsoleCursorPosition(hConsole,point);
						        	printf("              WRONG KEY!                ");
							    	sleep(1);
							    	system("cls");
							    	count_lines=4;
							    	goto start;
								}
							}
							
							else
							{  	
							    FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
								point.X=46;
			                    point.Y=13;
			                    SetConsoleCursorPosition(hConsole,point);
			                    printf("                         ");
			                    FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
			                	SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    point.X=40;
			                	point.Y=14;
			                	SetConsoleCursorPosition(hConsole,point);
						        printf("              WRONG KEY!                ");
							    sleep(1);
							    system("cls");
							    count_lines=4;
							    goto start;
							}
			        	
                        	if(numsScan==0)
		                	{
		                		system("cls");
		                	    count_lines=4;
		                		goto start;
							}
		                } 
		              
		            }
		        }
			    
         
  	        case 'U':
            case 'u':
        	 
	        point.X=62;
			point.Y=1;
			SetConsoleCursorPosition(hConsole,point);
			SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 1));
    	    ukr:printf("%s\n",strUkr);
    	    point.X=53;
    	    point.Y=3;
    	    SetConsoleCursorPosition(hConsole,point);
    	    printf("%s",inform2);
    	    SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 1));
    	    if(printf)count_lines++;
    	        while(1)
    	        {
    	        	point.X=0;
			        point.Y=count_lines;
			        SetConsoleCursorPosition(hConsole,point);
		            //input reception ukr
					input=type_input(count_lines);//---------------
		            count_lines++;
		            symbolDel(input);
		            lenStr=strlen(input);
		            printf(" ");
		            
		            if(lenStr<=2)
		            {
		        	
				        if(input[0]==27)
				        {
					        free(ENG);
					        free(UKR);
					        return;
				        }
				        
	                    else if(input[0]=='U' || input[0]=='u')
	                    {
	                		point.X=52;
			            	point.Y=1;
			            	SetConsoleCursorPosition(hConsole,point);
			            	printf("         ");
			            	point.X=53;
			            	point.Y=3;
			            	SetConsoleCursorPosition(hConsole,point);
			            	printf("            ");
			            	point.X=62;
			            	point.Y=1;
			            	SetConsoleCursorPosition(hConsole,point);
			            	SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 1));
			            	goto ukr;
						}
						
	                	if(*input=='E' || *input=='e')
	                	{
	                		point.X=62;
			            	point.Y=1;
			            	SetConsoleCursorPosition(hConsole,point);
			            	printf("         ");
			            	point.X=53;
			            	point.Y=3;
			            	SetConsoleCursorPosition(hConsole,point);
			            	printf("             ");
			            	point.X=52;
			            	point.Y=1;
			            	SetConsoleCursorPosition(hConsole,point);
			            	SetConsoleTextAttribute(hConsole, (WORD) ((11 << 4) | 1));
	                   	 	
							eng1:
							printf("%s\n",strEng);
	                   	 	point.X=53;
			            	point.Y=3;
			            	SetConsoleCursorPosition(hConsole,point);
			            	printf("%s",inform1);
	                    	if(printf)count_lines++;
	                    	while(1)
	                    	{
	                    		
	                    		point.X=0;
			                	point.Y=count_lines;
			                	SetConsoleCursorPosition(hConsole,point);
			                	SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 1));
	           	            	//input reception eng
								input=type_input(count_lines);//----------
	           	            	count_lines++;
	           	            	symbolDel(input);
	           	            	lenStr=strlen(input);
	           	            	printf(" ");
	           	            	
	           	            	if(lenStr<=2)
	           	            	{
							  
	                        		if(input[i]==27)
	                        		{
	                        			free(ENG);
	                        			free(UKR);
						        		return;
									}
									
	                        		else if(input[i]=='E' || input[i]=='e')
									{
										point.X=62;
			                    		point.Y=1;
			                    		SetConsoleCursorPosition(hConsole,point);
			                    		printf("         ");
			                    		point.X=53;
			                    		point.Y=3;
			                    		SetConsoleCursorPosition(hConsole,point);
			                    		printf("            ");
			                    		point.X=52;
			                    		point.Y=1;
			                    		SetConsoleCursorPosition(hConsole,point);
			                    		SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
			                    		goto eng1;
									}
										
	                        		if(*input=='U' || *input=='u')
									{
										
										point.X=52;
			                    		point.Y=1;
			                    		SetConsoleCursorPosition(hConsole,point);
			                    		printf("         ");
			                    		point.X=53;
			                    		point.Y=3;
			                    		SetConsoleCursorPosition(hConsole,point);
			                    		printf("           ");
			                    		point.X=62;
			                    		point.Y=1;
			                    		SetConsoleCursorPosition(hConsole,point);
			                    		SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
			                    		goto ukr;
									}
									
	                        		else
	                        		{
	                        			// input change/search eng->ukr
	            	            		upToLowEn(input);
	            	            		point.X=40;
			                    		point.Y=count_lines-1;
			                    		SetConsoleCursorPosition(hConsole,point);
			                    		changeGaps(input);
										add=searchEngToUkr(input,numWordsEng,numWordsUkr,&ENG,&UKR);
			                    		if(add==1)
			                    		{
			        						symb=askToAddWord();
			        	            		if(symb=='y' || symb=='Y')
			        	            		{
			        		            		system("cls");
			        		            		numsScan=createWordEn(&ENG,&UKR);
			        						}
			        	
		                            		else if(symb=='n'  || symb=='N')
						            		{
						            			FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
			                            	    point.X=46;
			                            		point.Y=13;
			                            		SetConsoleCursorPosition(hConsole,point);
			                            		SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
							            		printf("continue to translate?  ");
							            		waitAnswer=getch();
							            		
							            		if(waitAnswer=='y' || waitAnswer=='Y')
							            		{
							             			system("cls");
							             			count_lines=4;
		                	             			goto start;	
							            		}
							            		
							            		else if(waitAnswer==27 || waitAnswer=='n' || waitAnswer=='N')
							            		{
								            		point.X=46;
			                                		point.Y=13;
			                                		SetConsoleCursorPosition(hConsole,point);
			                                		printf("                         ");
							                		FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
							                		free(ENG);
							                		free(UKR);
						                    		return;	
							            		}
							            		
							            		else
						                		{
						                			FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
						                			point.X=46;
						                	    	point.Y=13;
			                            			SetConsoleCursorPosition(hConsole,point);
							            			printf("                      ");
						                			FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
						                			SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    					point.X=40;
			                						point.Y=14;
			                						SetConsoleCursorPosition(hConsole,point);
						        					printf("             WRONG KEY!                ");
							    					sleep(1);
							    					system("cls");
							    					count_lines=4;
							    					goto start;
												}
						                    }
											
											else
						            		{
						            			FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
						            			point.X=46;
						            			point.Y=11;
						                		SetConsoleCursorPosition(hConsole,point);
						                		printf("                      ");
						                		point.Y=12;
						                		SetConsoleCursorPosition(hConsole,point);
						                		printf("                      ");
			                                	point.Y=13;
			                            		SetConsoleCursorPosition(hConsole,point);
							            		printf("                      ");
						                		FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
						            			SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    				point.X=40;
			                					point.Y=14;
			                					SetConsoleCursorPosition(hConsole,point);
						        				printf("              WRONG KEY!                ");
							    				sleep(1);
							    			    system("cls");
							    				count_lines=4;
							    				goto start;
											}
											
		                            		if(numsScan==0)
		                            		{
		                	            		system("cls");
		                	            		count_lines=4;
		                            			goto start;
						            		}
		                        		}
	            	            	}
				          		}
				          			//input change/search eng->ukr
									upToLowEn(input);
	            	            	point.X=40;
			                    	point.Y=count_lines-1;
			                    	SetConsoleCursorPosition(hConsole,point);
			                    	changeGaps(input);
									add=searchEngToUkr(input,numWordsEng,numWordsUkr,&ENG,&UKR);
			                    	
									if(add==1)
			                    	{
			        	                symb=askToAddWord();
			        	                
			        	            		if(symb=='y' || symb=='Y')
			        	            		{
			        		            		system("cls");
			        		            		numsScan=createWordEn(&ENG,&UKR);
			        						}
			        	
		                            		else if(symb=='n'  || symb=='N')
						            		{
						            	        
							            		FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
			                            		point.X=46;
			                            		point.Y=13;
			                            		SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
			                            		SetConsoleCursorPosition(hConsole,point);
			                            		printf("continue to translate?  ");
							            		waitAnswer=getch();
							            		
							            		if(waitAnswer=='y' || waitAnswer=='Y')
							            		{
							            			system("cls");
							            			count_lines=4;
		                	             			goto start;	
							            		}
							            		
							            		else if(waitAnswer==27 || waitAnswer=='n' || waitAnswer=='N')
							            		{
								            		point.X=46;
			                                		point.Y=13;
			                                		SetConsoleCursorPosition(hConsole,point);
			                                		printf("                         ");
							                		FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
							                		free(ENG);
							                		free(UKR);
						                    		return;	
							            		}
							            		
							            		else
						                		{	
						                			FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
													point.X=46;
													point.Y=13;
			                            			SetConsoleCursorPosition(hConsole,point);
							            			printf("                      ");
						                			FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
						                			SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    					point.X=40;
			                						point.Y=14;
			                						SetConsoleCursorPosition(hConsole,point);
						        					printf("              WRONG KEY!                ");
							    					sleep(1);
							    					system("cls");
							    					count_lines=4;
							    				    goto start;
												}
						            		}
						            		
						            		else
						            		{	
						            			FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
											    point.X=46;
			                            		point.Y=13;
			                            		SetConsoleCursorPosition(hConsole,point);
							            		printf("                        ");
						                		FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
						            			SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    				point.X=40;
			                					point.Y=14;
			                					SetConsoleCursorPosition(hConsole,point);
						        				printf("              WRONG KEY!                ");
							    				sleep(1);
							    				system("cls");
							    				count_lines=4;
							    				goto start;
											}
											
		                            		if(numsScan==0)
		                            		{
		                	            		system("cls");
		                	            		count_lines=4;
		                            			goto start;
						            		}
		                        	}
		                    }
	                    }
			    	}
			    	
			    	else
			        {
			        	//input change/search ukr->eng
			        	//funcChangeI(input);
						upToLowUkr(input);
			            point.X=40;
			            point.Y=count_lines-1;
			            SetConsoleCursorPosition(hConsole,point);
			            changeGaps(input);
						add=searchUkrToEn(input,numWordsEng,numWordsUkr,&ENG,&UKR);
			            
	                        if(add==1)
	                        {
	                            symb=askToAddWord();
	                            if(symb=='y' || symb=='Y')
	                            {
	                                system("cls");
	                                numsScan=createWordUkr(&ENG,&UKR);
			        			}
	                            
	                            else if(symb=='n' || symb=='N')
						        {
						        
						            FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
			                       	point.X=46;
			                        point.Y=13;
			                        SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 1));
			                        SetConsoleCursorPosition(hConsole,point);
							        printf("continue to translate?  ");
						            waitAnswer=getch();
						            
						            if(waitAnswer=='y' || waitAnswer=='Y')
							        {
							            system("cls");
							            count_lines=4;
		                	            goto start;	
							        }
							        
							        else if(waitAnswer==27 || waitAnswer=='n' || waitAnswer=='N')
							        {
								        point.X=46;
			                            point.Y=13;
			                            SetConsoleCursorPosition(hConsole,point);
			                            printf("                         ");
							            FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
							            free(ENG);
										free(UKR);
						                return;	
							        }
							        
							        else
							        {
							        	FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
							        	point.X=46;
			                            point.Y=13;
			                            SetConsoleCursorPosition(hConsole,point);
							            printf("                          ");
						                FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
							        	SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    		point.X=40;
			                			point.Y=14;
			                			SetConsoleCursorPosition(hConsole,point);
						        		printf("              WRONG KEY!                ");
							    		sleep(1);
							    		system("cls");
							    		count_lines=4;
							    		goto start;
									}
						        }
						        
						        else
							    {
							    	FillConsoleOutputAttribute(hConsole, x << 4,80*100, point, &l);
							    	point.X=46;
			                        point.Y=13;
			                        SetConsoleCursorPosition(hConsole,point);
							        printf("                        ");
						            FillConsoleOutputAttribute(hConsole, x << 4,10*5, point, &l);
							    	SetConsoleTextAttribute(hConsole, (WORD) ((10 << 4) | 0));
							    	point.X=40;
			                		point.Y=14;
			                		SetConsoleCursorPosition(hConsole,point);
						        	printf("              WRONG KEY!                ");
							    	sleep(1);
							    	system("cls");
							    	count_lines=4;
							    	goto start;
								}
	                                 	
	                            if(numsScan==0)
	                            {
	                                system("cls");
	                                count_lines=4;
									goto start;	
								}
					  		}
					}
			        
                }
   
           
            case 27:return;
        }
    }
   
}

			 



