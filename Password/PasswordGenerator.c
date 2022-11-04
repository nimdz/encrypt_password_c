/* include header files*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Function for check number is contain in password*/
void password_numcheck(char *p)
{

    int count = 0;
    while (*p != '\0')
    {
        if (isdigit(*p) != 0)
        {
            count++;
        }
        p++;
    }
    if (count == 0)
    {
        printf("Number Should Contain In Password\n");
        exit(0);
    }
}
/* Function for add 4 for all digits in password*/
void add_num(char *p)
{
    while (*p != '\0')
    {
        if (isnumber(*p)) /* ISNUMBER() is a predefined function used for check string contains any numbers*/
        {
            *p += 4;
        }
        p++;
    }
}
/* Function for add length of given password at begin*/
void add_len_password(char *p)
{

    int len = strlen(p); // Get Input password's length using STRLEN function
    char i = len + '0';
    int k;
    /* For loop to add length to begin of string*/
    for (k = len + 1; k >= 0; k--)
    {
        if (k == 0)
        {
            p[k] = i;
        }
        else
        {
            p[k] = p[k - 1];
        }
    }
}
/* Function for convert all characters to upper case*/
void convert_upper(char *p)
{
    while (*p != '\0')
    {
        char ch = *p;
        *p = toupper(ch);
        p++;
    }
}
/* Function for add * at the end of password*/
void add_end_password(char *p)
{
    char ch[] = "*";
    strcat(p, ch);
}
/*Function To Reverse and Print the password*/
void reverse_password(char *p)
{
    int len = strlen(p);
    int i;
    for (i = len; i >= 0; i--)
    {
        printf("%c", p[i]);
    }
}
/* main method*/
int main()
{
    char password[100]; // variable for store input password
    printf("Enter your Password Please:\n");
    scanf("%s", password);
    /* Check Whether input Password Contains Correct Length*/
    while (strlen(password) < 6 || strlen(password) > 9)
    {
        printf("Error!\n");
        printf("Please Enter Your Password Again:\n");
        scanf("%s", password);
    }
    password_numcheck(password); // checks number contains in input password
    add_num(password);           // use to add 4 for all numbers in input password
    add_len_password(password);  // use add length of password at begining of string
    convert_upper(password);     // use to convert all characters to upper
    add_end_password(password);  // use to add * at the end of the password
    reverse_password(password);  // print encrypted password to th user
    return 0;
}
