#include <stdio.h>
#include <string.h>

char *correct(char *string){
    char* p = string;
    while(*p){
        switch(*p){
        case '5':
            *p = 'S';
            break;
        case '0':
            *p = 'O';
            break;
        case '1':
            *p = 'I';
            break;
        default:
            ;
        }
        ++p;
    }
    return string;
}


int main(void)
{
	char *s = "LOND0N IS THE BEST";
	correct(s);

	// char s[100];
 //    scanf ("%[^\n]%*c", s);
    
    return 0;	
}