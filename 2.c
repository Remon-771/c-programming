#include<stdio.h>


char keywords[][10] = {"if", "else", "while", "for", "int", "float", "char", "return"};
int keywordCount = 8;


int keyword(char word[])
{
    int i;
    for(i=0;i<keyword; i++)
    {
        if(stringequal(word,keywords[i]))
            return 1;

    }
    return 0;
}

int stringequal(char a[], char b[])
{
    int i=0;
    while (a[i]!='\0' && b[i] != '\0')
    {
        if(a[i] != b[i])
            return 0;

    }
    i++;
}








int isidentifier(char word[])
{
    if (!((word[0] >= 'a' && word[0] <= 'z') ||
          (word[0] >= 'A' && word[0] <= 'Z') ||
           word[0] == '_'))
        return 0;

    for(i=1 , word[i]!='\0',i++){
            if (!((word[i] >= 'a' && word[i] <= 'z') ||
              (word[i] >= 'A' && word[i] <= 'Z') ||
              (word[i] >= '0' && word[i] <= '9') ||
               word[i] == '_'))
            return 0;

    }
    return 1;


}


int main()
{
    char sen[100],word[50];

    printf("enter sentence= ");
    gets(sen);

    int i=0,j=0;
    while(1)
    {

        if( sen[i]==' ' || sen[i]=='\0' || sen[i]=='{' || sen[i]=='}' ||sen[i]=='(' ||sen[i]==')' ||sen[i]=='; ' ||sen[i]=='<' ||sen[i]=='>' ||)
            {
               if (j > 0) { // If we collected a word
                word[j] = '\0';
                if (iskeyword(word))
                    printf("%s : Keyword\n", word);
                else if (isidentifier(word))
                    printf("%s : Identifier\n", word);
                else
                    printf("%s : (Not classified as keyword or identifier)\n", word);
                j = 0; // Reset for next word
            }

            else
            {

            word[j++]= sen[i];

            }

            i++;
            }



    }

}
