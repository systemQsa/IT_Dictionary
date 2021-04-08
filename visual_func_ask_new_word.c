char askToAddWord()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD p;
	COORD point;
	
	int k,x,y;
    char key;
    
	point.X=40;
	for(k=11;k<18;k++)
		{
			point.Y=k;
			SetConsoleCursorPosition(hConsole,point);
		    point.Y=13;
		    printf("                                   ");
		    SetConsoleCursorPosition(hConsole,point);
			SetConsoleTextAttribute(hConsole, (WORD) ((13 << 2) | 15));
			printf("\t  Not found :(\t");
			point.Y=14;
			SetConsoleCursorPosition(hConsole,point);
		    printf("\t  continue to tanslate?\t");                     
			point.Y=15;
			SetConsoleCursorPosition(hConsole,point);
			SetConsoleTextAttribute(hConsole, (WORD) ((13 << 2) | 4));
			printf("\t |Yes|\t\t|No|");
			point.Y=16;
			SetConsoleCursorPosition(hConsole,point);
			SetConsoleTextAttribute(hConsole, (WORD) ((13 << 2) | 15));
			printf("\t _________________ ");
		}
		
		   key=getch();
		    
		   if(key=='y' || key=='n' || key=='Y' || key=='N')
			{
	            point.Y=13;
				SetConsoleCursorPosition(hConsole,point);
			    printf("                           ");
				point.Y=15;
				SetConsoleCursorPosition(hConsole,point);
				printf("                              ");
	            point.Y=16;
			    SetConsoleCursorPosition(hConsole,point);
			    printf("                              ");
				point.X=40;
			        
			    for(k=11;k<18;k++)
				{
					point.Y=k;
					SetConsoleCursorPosition(hConsole,point);
					printf("                               ");
				}
			}
			
			else if(key!='y' || key!='n' || key!='Y' || key!='N')
			{
				point.Y=13;
				SetConsoleCursorPosition(hConsole,point);
			    printf("                           ");
				point.Y=15;
				SetConsoleCursorPosition(hConsole,point);
				printf("                              ");
				point.Y=16;
			    SetConsoleCursorPosition(hConsole,point);
			    printf("                              ");
				point.X=40;
			        
			    for(k=11;k<18;k++)
				{
					point.Y=k;
					FillConsoleOutputAttribute(hConsole, x << 4,4*10, point, &p);	
					SetConsoleCursorPosition(hConsole,point);
				}
			  
			}
			
	return key;
}
