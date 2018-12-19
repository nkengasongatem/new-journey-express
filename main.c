#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <process.h>
#include <dir.h>

#include "Destinations.h"
#include "Main_Menu.h"
#include "Sell_Tickets_Main.h"
#include "Trip_Details.h"

int main()
{

    char user[15];
    char pass[15];
    char ch;

    system("title NEW JOURNEY LOGIN");
    system("mkdir C:\\New_Journey\\data");    //stdprn .PRINTER AND MERGE FILES TO EASILY SEARCH EACH TIME YOU WANT TO SEARCH, call the search function, LET IT OPEN ALL FILES, CREATED IF NOT EXISTING THEN JOIN ALL THEIR CONTENT TO CONDCT ONE SEARCH
    SignOut:
    do{
    printf("\n\n\t****************************************");
    printf("\n\n\t\t WELCOME TO NEW JOURNEY  \n");
    printf("\n\n\t****************************************");
    printf("\n SIGN IN \n\n");
    system("color 3f");
    printf("\n USERNAME: ");
    scanf("%s",user);
    printf("\n PASSWORD : ");
    scanf("%s",pass);
    if(strcmp(strupr(user),"ADMIN")==0 && strcmp(strupr(pass),"UNLOCK")==0)
    {
        printf("\a\n\t\t\tACCESS GRANTED. EXPERIENCE TRAVELING AS NEVER BEFORE!");// call the function of the main menu
        Sleep(1000);
        menu:
        ch = Main_Menu_Function();
    switch(ch)
    {
    case '1': ch = Sell_Tickets_Function();  goto menu; break;

    case '2': depart:
              ch = Destination_Function();
              switch(ch)
              {
              case '1': system("cls"); goto menu; break;
              case 'Q': ch = Quit_Function();  goto depart; break;
              case 'q': ch = Quit_Function();  goto depart; break;
              }break;

    case '3': ch = Trip_Details_Function();  goto menu; break;

    case '4': printf("\n\n\n\t\t\t\tARE YOU SURE YOU WANT TO SIGN OUT (Y/N)::  ");
              do
              ch = getch();
              while(ch!='Y' && ch!='N'&& ch!='y' && ch!='n');
              Sleep(500);
              switch(ch)
              {
                  case 'Y': system("cls"); goto SignOut; break;
                  case 'y': system("cls"); goto SignOut; break;
                  case 'N': system("cls"); goto menu; break;
                  case 'n': system("cls"); goto menu; break;
              } break;

    case 'Q': ch = Quit_Function(); goto menu; break;
    case 'q': ch = Quit_Function(); goto menu; break;


    }
    }
    else printf("\n\n\t\t\t\t\tSORRY USERNAME OR PASSWORD IS INCORRECT PLEASE TRRY AGAIN...");
    Sleep(5000);
    system("cls");
    }while(strcmp(user,"admin")!=0 || strcmp(pass,"pass")!=0);


    return EXIT_SUCCESS;
}
