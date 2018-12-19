
char Trip_Details_Function()
{
    system("title NEW JOURNEY TRIP DETAILS");
    system("cls");
    file_copy();
    char ch;
    ticket:
    ch = Trip_detials();

    switch(ch)
    {
    case '1':
              searching:
              ch = Search_Passenger_In_File("C:\\New_Journey\\Search_Db.txt");
              switch(ch)
                    {
                    case '1': goto searching; break; //LOOK CLOSELY AT PERFORMINNG ANOTHER SEARCH
                    case '2': goto ticket; break;
                    case 'Q': ch = Quit_Function(); goto searching; break;
                    case 'q': ch = Quit_Function(); goto searching; break;
                    } break;

    case '2':   system("cls");
                someother:
                ch = View_List();
                switch(ch){
              case '1':
                    system("cls");
                    ch =  Read_Db8AM();
                    switch(ch)
                    {
                    case '1':system("cls"); goto someother; break;

                    case '2':system("cls"); goto ticket;  break;

                    case 'Q': ch = Quit_Function(); system("cls"); goto someother; break;
                    case 'q': ch = Quit_Function(); system("cls"); goto someother; break;
                    } break;

              case '2':
                    system("cls");
                    ch =  Read_Db9AM();
                    switch(ch)
                    {
                    case '1':system("cls"); goto someother; break;
                    case '2':system("cls"); goto ticket;  break;
                    case 'Q': ch = Quit_Function(); system("cls"); goto someother; break;
                    case 'q': ch = Quit_Function(); system("cls"); goto someother; break;
                    } break;

              case '3':
                    system("cls");
                    ch =  Read_Db12N();
                    switch(ch)
                    {
                    case '1':system("cls"); goto someother; break;
                    case '2':system("cls"); goto ticket;  break;
                    case 'Q': ch = Quit_Function(); system("cls"); goto someother; break;
                    case 'q': ch = Quit_Function(); system("cls"); goto someother; break;
                    } break;

              case '4':
                    system("cls");
                    ch =  Read_Db9PM();
                    switch(ch)
                    {
                    case '1':system("cls"); goto someother; break;
                    case '2':system("cls"); goto ticket;  break;
                    case 'Q': ch = Quit_Function(); system("cls");  goto someother; break;
                    case 'q': ch = Quit_Function(); system("cls"); goto someother; break;
                    } break;

                case '5': system("cls"); goto ticket; break;
                case 'Q': ch = Quit_Function();system("cls"); goto someother; break;
                case 'q': ch = Quit_Function(); system("cls");goto someother; break;

            } break;

    case '3': system("cls"); return '0';  break;
    case 'Q': ch = Quit_Function(); system("cls"); goto ticket ; break;
    case 'q': ch = Quit_Function(); system("cls"); goto ticket ; break;

    }

}





int Trip_detials()
{
    char usr_choice;
        system("cls");
        system("color 3F");
        printf("\n\n\t\t\t\tTRIP DETAILS\n\n");
        printf("\t\t\tALL DETAILS ABOUT NEW JOURNEY'S SERVICES\n\n");
        printf("\t\t\t1. SEARCH PASSENGER\n");
        printf("\t\t\t2. VIEW TRAVEL LISTS\n");
        printf("\t\t\t3. Return to MAIN MENU\n");
        printf("\t\t\tQ. Quit\n\t\t\t\t");
    do
    {
        usr_choice = getch(); // HOW DO I TAKE VALUES WITHOUT MOVING TO A NEW LINE AND NEW COLUMN
        fflush(stdin);
    }while(usr_choice != '1' && usr_choice != '2' && usr_choice != '3' && usr_choice != 'Q'  && usr_choice != 'q');
    return usr_choice;
}

int View_List()
{
     char usr_choice;
        printf("\n\n\t\t\t\tTRIP DETAILS - VIEW TRAVEL LIST\n\n");
        printf("\t\t\tSELECT JOURNEY TO VIEW PASSENGER INFORMATION\n\n");
        printf("\t\t\t1. 8:00 AM JOURNEY\n");
        printf("\t\t\t2. 9:00 AM VIP JOURNEY\n");
        printf("\t\t\t3. 12:00 MIDDAY JOURNEY\n");
        printf("\t\t\t4. 9:00 PM JOURNEY\n");
        printf("\t\t\t5. Return to TRIP DETAILS\n");
        printf("\t\t\tQ. Quit\n\t\t\t\t");
      do
    {
        usr_choice = getch(); // HOW DO I TAKE VALUES WITHOUT MOVING TO A NEW LINE AND NEW COLUMN
        fflush(stdin);
    }while(usr_choice != '1' && usr_choice != '2' && usr_choice != '3' && usr_choice != '4'&& usr_choice != '5' && usr_choice != 'Q'&& usr_choice != 'q');
    return usr_choice;
}

int Read_Db8AM()
{
    int c;
    char ch;
    FILE *fp;

    if ((fp = fopen("C:\\New_Journey\\Cust_Db8AM.txt","r")) == NULL)
    {
        printf("\n\n\n\n\t\t\t\t\tError! opening file.");
    Sleep(5000);
    ch = '1';
    }
    if (fp){
        while ((c = getc(fp))!= EOF)
            putchar(c);
    }
    fclose(fp);
    printf("\n\n\t\t\t1. RETURN TO PREVIOUS MENU\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	printf("\t\t\tQ. QUIT PROGRAM\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2' && ch!='Q'&& ch!='Q'&& ch!='q');

     return ch;
}

int Read_Db9AM()
{
    int c;
    char ch;
    FILE *fp;

    if ((fp = fopen("C:\\New_Journey\\Cust_Db9AM.txt","r")) == NULL)
    {
        printf("\n\n\n\n\t\t\t\t\tError! opening file.");
    Sleep(5000);
    ch = '1';
    }
    if (fp){
        while ((c = getc(fp))!= EOF)
            putchar(c);
    }
    fclose(fp);
    printf("\n\n\t\t\t1. RETURN TO PREVIOUS MENU\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	printf("\t\t\tQ. QUIT PROGRAM\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2' && ch!='Q'&& ch!='q');

     return ch;
}

int Read_Db12N()
{
    int c;
    char ch;
    FILE *fp;

    if ((fp = fopen("C:\\New_Journey\\Cust_Db12N.txt","r")) == NULL)
    {
        printf("\n\n\n\n\t\t\t\t\tError! opening file.");
    Sleep(5000);
    ch = '1';
    }
    if (fp){
        while ((c = getc(fp))!= EOF)
            putchar(c);
    }
    fclose(fp);
    printf("\n\n\t\t\t1. RETURN TO PREVIOUS MENU\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	printf("\t\t\tQ. QUIT PROGRAM\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2' && ch!='Q'&& ch!='q');

     return ch;
}

int Read_Db9PM()
{
    int c;
    char ch;
    FILE *fp;

    if ((fp = fopen("C:\\New_Journey\\Cust_Db9PM.txt","r")) == NULL)
    {
        printf("\n\n\n\n\t\t\t\t\tError! opening file.");
    Sleep(5000);
    ch = '1';
    }
    if (fp){
        while ((c = getc(fp))!= EOF)
            putchar(c);
    }
     fclose(fp);
    printf("\n\n\t\t\t1. RETURN TO PREVIOUS MENU\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	printf("\t\t\tQ. QUIT PROGRAM\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2' && ch!='Q'&& ch!='q');

     return ch;
}




 file_copy()   //I WON'T NEED INPUT PARAMETERS!
 {
 FILE *fold, *fnew;
 int c;

 // Open the source file for reading in binary mode.

  fold = fopen( "C:\\New_Journey\\Cust_Db8AM.txt", "a" );
  fclose(fold);
  fold = fopen( "C:\\New_Journey\\Cust_Db8AM.txt", "r" );
  fnew = fopen( "C:\\New_Journey\\Search_Db.txt", "w" );

 while (1)
 {
 c = fgetc( fold );

 if ( !feof( fold ) )
 fputc( c, fnew );
 else
 break;
 }
 fclose ( fold );
 fold = fopen( "C:\\New_Journey\\Cust_Db9AM.txt", "a" );
 fclose(fold);
 fold = fopen( "C:\\New_Journey\\Cust_Db9AM.txt", "r" );

 while (1)
 {
 c = fgetc( fold );

 if ( !feof( fold ) )
 fputc( c, fnew );
 else
 break;
 }

 fclose ( fold );
 fold = fopen( "C:\\New_Journey\\Cust_Db12N.txt", "a" );
 fclose(fold);
 fold = fopen( "C:\\New_Journey\\Cust_Db12N.txt", "r" );

 while (1)
 {
 c = fgetc( fold );

 if ( !feof( fold ) )
 fputc( c, fnew );
 else
 break;
 }

 fclose ( fold );
 fold = fopen( "C:\\New_Journey\\Cust_Db9PM.txt", "a" );
 fclose(fold);
 fold = fopen( "C:\\New_Journey\\Cust_Db9PM.txt", "r" );

 while (1)
 {
 c = fgetc( fold );

 if ( !feof( fold ) )
 fputc( c, fnew );
 else
 break;
 }
 fclose(fold);
 fclose ( fnew );
 }



int Search_Passenger_In_File(char* filename)
{
    char name[32],ch;
    int line_num = 1;
    int find_result = 0;
    char temp[102];
    FILE *fp;
    system("cls");
    if ((fp = fopen(filename,"r")) == NULL)
    {
        printf("\n\n\n\n\t\t\t\t\tError! opening file OR file does not exist yet.");
        Sleep(2000);
        return('1');
    }
    printf("\n\n\t\t\tSEARCH PASSENGER INFORMATION BY NAME\n");
    printf("\n\n\t\t\tENTER PASSENGER FULL NAME: ");
    do
    fgets(name,32,stdin);
    while (strlen(name) != strcspn(name, "0123456789"));
    fflush(stdin);

    while(fgets(temp, 102, fp)!= NULL){
            if((strstr(temp,strupr(name))) != NULL){
                    printf("\n\t\t\t\t\t\t\t  A match found!\n"); //line_num GO BACK EXACTLY SIX LINES
                    fseek(fp,-(strlen(name)+364),SEEK_CUR); // +40 12 lines from up to bottom
                    int mycount = 15;
                    while(mycount>=1)
                    {
                        fgets(temp,102,fp);
                        printf("\t\t\t%s",temp);
                        mycount--;
                    }


                    find_result++;
            }
            line_num++;
    }
    if(find_result == 0){
        printf("\n\t\t\t\tSorry, Couldn't find a match to any existing passenger.");
    }
    fclose(fp);
    printf("\n\n\n\t\t\t1. PERFORM ANOTHER SEARCH\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	printf("\t\t\tQ. QUIT PROGRAM\n");

	fclose(fp);
	fflush(fp);
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2' && ch!='Q'&& ch!='q');

     return ch;
}
