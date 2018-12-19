

char Main_Menu_Function()
{
    system("title NEW JOURNEY MAIN MENU");
	char choice;
	system("cls");
    system("color 3F");
    printf("\n\n\n\t\t\t\tWELCOME TO NEW JOURNEY :: EXPERIENCE TRAVELLING AS NEVER BEFORE!");
	printf("\n\n\n");
	printf("\t\t\t\xB2\xB2\xB2  1. SELL TICKETS \n\n");
	printf("\t\t\t\xB2\xB2\xB2  2. DEPARTURE TIMES \n\n");
	printf("\t\t\t\xB2\xB2\xB2  3. TRIP DETAILS \n");
	printf("\n\t\t\t\xB2\xB2\xB2  4. SIGN OUT \n\n");
	printf("\t\t\t\xB2\xB2\xB2  Q. QUIT PROGRAM. \n\t\t\t\t\t");

	do
	  choice = getch();
	while (choice!='1' && choice!='2' && choice!='3' && choice!='4' && choice!='Q' && choice!='q');
	return choice;
}

char Quit_Function()
{
    char ch;
    printf("\n\n\n\t\t\t\tARE YOU SURE YOU WANT TO SIGN OUT (Y/N)::  ");
    printf("\n\n");
    do
    ch = getch();
    while(ch!='Y' && ch!='N'&& ch!='y' && ch!='n');
    switch(ch)
    {
    case 'Y': system("cls");  printf("\a\n\n\n\t\t\tTHANK YOU FOR CHOOSING NEW JOURNEY EXPRESS!\n\n");  Sleep(500); exit(1); break;
    case 'y': system("cls");  printf("\a\n\n\n\t\t\tTHANK YOU FOR CHOOSING NEW JOURNEY EXPRESS!\n\n");  Sleep(500); exit(1); break;
    case 'N': system("cls"); return '0';break;
    case 'n': system("cls"); return '0';break;
    }
}
