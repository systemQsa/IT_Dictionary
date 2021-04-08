struct COORD
  {
   int X;
   int Y;
};


typedef struct Word{
	char word[100];
	int num;
}*pWord;

char* type_input(int count_lines);
int fillStructEng(pWord* ENG);
int fillStructUk(pWord* UKR);
int compare(char *word,char *input);
int searchEngToUkr(char* input,int numWordsEng,int numWordsUkr,pWord* language,pWord* UKR);
int searchUkrToEn(char* input,int numWordsEng,int numWordsUkr,pWord* ENG,pWord* UKR);
int createWordEn(pWord *ENG,pWord* UKR);
int createWordUkr(pWord *ENG,pWord*UKR);
