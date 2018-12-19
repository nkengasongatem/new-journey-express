
// DEFINITION OF THE STRUCTURE MUST BE IN THE HEADER FILE AND NOT IN THE MAIN FILE
struct CustomerInfo
{
   char Cname[30];
   char Cdestin[30];
   char CNI[10];
   int  Csit;
   char  Bnbr[4];
   int  Ticketsrl;
};

struct CustomerInfo customer;

// DECLARATION OF FUNCTIONS REMEMBER NAME CONTROL FUNCTION
int ticket_menu();
char DataEntry8AM(struct CustomerInfo customer);       //use static local variable to save number of sold tickets
char DataEntry9AM(struct CustomerInfo customer);
char DataEntry12N(struct CustomerInfo customer);
char DataEntry9PM(struct CustomerInfo customer);

// MAIN FUNCTION
char Sell_Tickets_Function()
{
    system("title NEW JOURNEY TICKETS");
    system("cls");
    int s,b;
    char ch;

    ticket:
        ch =  ticket_menu();

    switch(ch)
    {
    case '1':  system("cls");
              printf("\n 8:00 AM ECONOMIC CLASS JOURNEY\n");
              another:
              ch = DataEntry8AM(customer);
              switch(ch){
              case '1':
                    system("cls");
                    goto another;
                    break;
              case '2':
                    system("cls");
                    goto ticket;
                    break;
              }
              break;

    case '2':   system("cls");
                printf("\n 9:00 AM VIP CLASS JOURNEY\n");
                someother:
                ch = DataEntry9AM(customer);
                switch(ch){
              case '1':
                    system("cls");
                    goto another;
                    break;
              case '2':
                    system("cls");
                    goto ticket;
                    break;
              }
                break;


    case '3':   system("cls");
                 printf("\n 12:00 NOON ECONOMIC CLASS JOURNEY\n");
                 order:
                ch = DataEntry12N(customer);
               switch(ch){
              case '1':
                    system("cls");
                    goto another;
                    break;
              case '2':
                    system("cls");
                    goto ticket;
                    break;
              }
                break;
    case '4':   system("cls");
                 printf("\n 9:00 PM ECONOMIC CLASS JOURNEY\n");
                 somemore:
                ch = DataEntry9PM(customer);
                switch(ch){
              case '1':
                    system("cls");
                    goto another;
                    break;
              case '2':
                    system("cls");
                    goto ticket;
                    break;
              }
                break;

    case '5':   system("cls"); return '0'; break;

    case 'Q': ch = Quit_Function(); Sell_Tickets_Function(); break;
    case 'q': ch = Quit_Function(); Sell_Tickets_Function(); break;

    }

}


// SELL TICKET MENU
int ticket_menu()
{
    char usr_choice;
        system("color 3F");
        printf("\n\n\t\t\t\tSALE OF TICKETS\n\n");
        printf("\t\t\tSELECT JOURNEY TIME\n\n");
        printf("\t\t\t1. 8:00 AM JOURNEY\n");
        printf("\t\t\t2. 9:00 AM VIP JOURNEY\n");
        printf("\t\t\t3. 12:00 MIDDAY JOURNEY\n");
        printf("\t\t\t4. 9:00 PM JOURNEY\n");
        printf("\t\t\t5. Return to MAIN MENU\n");
        printf("\t\t\tQ. Quit\n\t\t\t\t");
    do
    {
        usr_choice = getch(); // HOW DO I TAKE VALUES WITHOUT MOVING TO A NEW LINE AND NEW COLUMN
        fflush(stdin);
    }while(usr_choice != '1' && usr_choice != '2' && usr_choice != '3' && usr_choice != '4'&& usr_choice != '5' && usr_choice != 'Q' && usr_choice != 'q');
    return usr_choice;
}


char DataEntry8AM(struct CustomerInfo customer)
{
     // USE MULTIPLE DO WHILE LOOPS TO CONTROL USER INFORMATION ENTERED BY EMPLOYEE
     time_t start, finish, now;
     size_t loc;
     struct tm *ptr;
     char *c;
     char ch;

     static int ticket_counter = 0;
     system("color 3F");

      ticket_counter++;
      if (ticket_counter>70)
      {
          printf("\n\n\n\n\t\t\t\tALL TICKETS FOR THIS JOURNEY HAVE BEEN SOLD!\n");
          Sleep(10000);
          return ('2');
      }else{

       FILE *fp = fopen("C:\\New_Journey\\Cust_Db8AM.txt","a+");
      int fflush(FILE *fp);

      if (fp == NULL) {
        perror("Could not open Cust_Db8AM.txt");
        return;
      }

       start = time(0);
       time(&now);
       ptr = localtime(&now);
       c = asctime(ptr);



     printf("\nPlease Fill in the information below. TICKET Number %d /70 \n",ticket_counter);

     printf("\nCUSTOMER NAME : ");
     check:
        fgets(&customer.Cname,30,stdin);
        if (strlen(&customer.Cname) != strcspn(&customer.Cname, "0123456789"))
        {
           printf("\nInvalid Name Format Try Again: ");
           goto check;
        }
     fflush(stdin);
     printf("\nDESTINATION : ");
	do
     gets(&customer.Cdestin);
 	while ((strcmp(strupr(&customer.Cdestin),"MAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"GAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"NGAOUNDERE")!=0)&&
         	(strcmp(&customer.Cdestin,"DSCHANG")!=0) && (strcmp(&customer.Cdestin,"DOUALA")!=0)&& (strcmp(&customer.Cdestin,"BUEA")!=0) &&
            (strcmp(strupr(&customer.Cdestin),"DOUALA")!=0));
     fflush(stdin);
     printf("\nCNI : ");
	do
     fgets(&customer.CNI,10,stdin);
	while (strlen(&customer.CNI) != 9);
     fflush(stdin);
     printf("\nSIT : ");
	do
     scanf("%d",&customer.Csit);
	while(customer.Csit < 1 || customer.Csit > 70);
     fflush(stdin);

     printf("\nBUS NUMBER (BUSxxx): ");
	do
     fgets(&customer.Bnbr,4,stdin);
	while (strlen(&customer.Bnbr) != 3);
     fflush(stdin);

	customer.Ticketsrl = rand()%(9999 + 1 - 1000) + 1000;

     fflush(stdin);

       setvbuf(stdout,NULL,_IONBF,BUFSIZ);
	   fprintf(fp,"\n\n/************************************New Journey Ticket**********************************************\0'");
	   fprintf(fp,"\n----------------------------------- ");
       fprintf(fp,"%s",c);
       fprintf(fp,"%s" ,"----------------------------------- ");
// MIGHTY PUT TICKET NUMBER HERE
	   fprintf(fp,"\nNEW JOURNEY EXPRESS           |");
	   fprintf(fp,"  NEW JOURNEY EXPRESS");
	   fprintf(fp,"\nOFFICE : YAOUNDE              |");
	   fprintf(fp,"  DEPARTURE AGENCY : MVAN ");
	   fprintf(fp,"\nB.O BOX : 458                 |");
	   fprintf(fp,"  NAME : ");
       fprintf(fp,"%s",strupr(&customer.Cname));
	   fprintf(fp,"TEL : +237653398462           |");
	   fprintf(fp,"  DESTINATION : ");
       fprintf(fp, "%s ",strupr(&customer.Cdestin));
	   fprintf(fp,"\nDEPARTURE AGENCY : MVAN       |");
	   fprintf(fp,"  DEPARTURE TIME : ");
	   fprintf(fp,"8:00 am");
	   fprintf(fp,"\nJOURNEY CLASS : ");
	   fprintf(fp," Economic     |");
	   fprintf(fp,"  COST :");
	   fprintf(fp," 4000 FCFA");
	   fprintf(fp,"  CNI : ");
	   fprintf(fp, "%s ", &customer.CNI);
	   fprintf(fp,"\nSIT : ");
	   fprintf(fp,"%d  |", customer.Csit);
	   fprintf(fp," BUS Number : ");
	   fprintf(fp,"BUS%s    |", &customer.Bnbr);
	   fprintf(fp,"  TICKET SERIAL : ");
	   fprintf(fp,"NJE%dX ", customer.Ticketsrl);
	fprintf(fp,"\n-----------------------------------------------------------------------------------------------------\0'");
	fprintf(fp,"\n/****************************************************************************************************\0'\n\n");
	fclose(fp);
	fprintf(stdout, "\nPassenger Information has been recorded\n");
	printf("\t\t\t1. SELL ANOTHER TICKET\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2');
     return ch;
    }

}

// ONCE WE HAVE FINISHED PRINTING IN THE FILE WE PRINT USING THE PRINTER// ALLOW THE POSSIBLILITY TO PRINT THE ENTIRE FILE????
// DECLARATION OF FILE TO STORE INFORMATION FROM THE USER WHICH WILL LATER BE DISPLAYED IN THE TICKET FORMAT
char DataEntry9AM(struct CustomerInfo customer)
{
     // USE MULTIPLE DO WHILE LOOPS TO CONTROL USER INFORMATION ENTERED BY EMPLOYEE
     time_t start, finish, now;
     size_t loc;
     struct tm *ptr;
     char *c,ch;
     static int ticket_counter = 0;

      ticket_counter++;
      if (ticket_counter>70)
      {
          printf("\n\n\n\n\t\t\t\tALL TICKETS FOR THIS JOURNEY HAVE BEEN SOLD!\n");
          Sleep(10000);
          ch = '2';
      }else{

       system("color 3F");
       FILE *fp = fopen("C:\\New_Journey\\Cust_Db9AM.txt","a+");
      int fflush(FILE *fp);

      if (fp == NULL) {
        perror("Could not open Cust_Db9AM.txt");
        return;
      }

       start = time(0);
       time(&now);
       ptr = localtime(&now);
       c = asctime(ptr);



     printf("\nPlease Fill in the information below. TICKET Number %d /70 \n",ticket_counter);

     printf("\nCUSTOMER NAME : ");
     check:
        fgets(&customer.Cname,30,stdin);
        if (strlen(&customer.Cname) != strcspn(&customer.Cname, "0123456789"))
        {
           printf("\nInvalid Name Format Try Again: ");
           goto check;
        }
     fflush(stdin);
     printf("\nDESTINATION : ");
	do
     gets(&customer.Cdestin);
 	while ((strcmp(strupr(&customer.Cdestin),"MAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"GAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"NGAOUNDERE")!=0)&&
         	(strcmp(&customer.Cdestin,"DSCHANG")!=0) && (strcmp(&customer.Cdestin,"DOUALA")!=0)&& (strcmp(&customer.Cdestin,"BUEA")!=0) &&
            (strcmp(strupr(&customer.Cdestin),"DOUALA")!=0));
     fflush(stdin);
     printf("\nCNI : ");
	do
     fgets(&customer.CNI,10,stdin);
	while (strlen(&customer.CNI) != 9);
     fflush(stdin);
     printf("\nSIT : ");
	do
     scanf("%d",&customer.Csit);
	while(customer.Csit < 1 || customer.Csit > 70);
     fflush(stdin);

     printf("\nBUS NUMBER (BUSxxx): ");
	do
     fgets(&customer.Bnbr,4,stdin);
	while (strlen(&customer.Bnbr) != 3);
     fflush(stdin);

    customer.Ticketsrl = rand()%(9999 + 1 - 1000) + 1000;

     fflush(stdin);

       setvbuf(stdout,NULL,_IONBF,BUFSIZ);
	   fprintf(fp,"\n\n/************************************New Journey Ticket**********************************************\0'");
	   fprintf(fp,"\n----------------------------------- ");
       fprintf(fp,"%s",c);
       fprintf(fp,"%s" ,"----------------------------------- ");
// MIGHTY PUT TICKET NUMBER HERE
	   fprintf(fp,"\nNEW JOURNEY EXPRESS           |");
	   fprintf(fp,"  NEW JOURNEY EXPRESS");
	   fprintf(fp,"\nOFFICE : YAOUNDE              |");
	   fprintf(fp,"  DEPARTURE AGENCY : MVAN ");
	   fprintf(fp,"\nB.O BOX : 458                 |");
	   fprintf(fp,"  NAME : ");
       fprintf(fp,"%s",strupr(&customer.Cname));
	   fprintf(fp,"TEL : +237653398462           |");
	   fprintf(fp,"  DESTINATION : ");
       fprintf(fp, "%s ",strupr(&customer.Cdestin));
	   fprintf(fp,"\nDEPARTURE AGENCY : MVAN       |");
	   fprintf(fp,"  DEPARTURE TIME : ");
	   fprintf(fp,"9:00 am");
	   fprintf(fp,"\nJOURNEY CLASS : ");
	   fprintf(fp," VIP          |");
	   fprintf(fp,"  COST :");
	   fprintf(fp," 7000 FCFA");
	   fprintf(fp,"  CNI : ");
	   fprintf(fp, "%s ", &customer.CNI);
	   fprintf(fp,"\nSIT : ");
	   fprintf(fp,"%d  |", customer.Csit);
	   fprintf(fp," BUS Number : ");
	   fprintf(fp,"BUS%s    |", &customer.Bnbr);
	   fprintf(fp,"  TICKET SERIAL : ");
	   fprintf(fp,"NJE%dX ", customer.Ticketsrl);
	fprintf(fp,"\n-----------------------------------------------------------------------------------------------------\0'");
	fprintf(fp,"\n/****************************************************************************************************\0'\n\n");
	fclose(fp);
	fprintf(stdout, "\nPassenger Information has been recorded\n");
	printf("\t\t\t1. SELL ANOTHER TICKET\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2');

    return ch;
    }
}




char DataEntry12N(struct CustomerInfo customer)
{
     // USE MULTIPLE DO WHILE LOOPS TO CONTROL USER INFORMATION ENTERED BY EMPLOYEE
     time_t start, finish, now;
     size_t loc;
     struct tm *ptr;
     char *c,ch;
     static int ticket_counter = 0;

      ticket_counter++;
      if (ticket_counter>70)
      {
          printf("\n\n\n\n\t\t\t\tALL TICKETS FOR THIS JOURNEY HAVE BEEN SOLD!\n");
           Sleep(10000);
          ch = '2';
      }else{

       system("color 3F");
       FILE *fp = fopen("C:\\New_Journey\\Cust_Db12N.txt","a+");
      int fflush(FILE *fp);

      if (fp == NULL) {
        perror("Could not open Cust_Db12N.txt");
        return;
      }

       start = time(0);
       time(&now);
       ptr = localtime(&now);
       c = asctime(ptr);



     printf("\nPlease Fill in the information below. TICKET Number %d /70 \n",ticket_counter);

     printf("\nCUSTOMER NAME : ");
     check:
        fgets(&customer.Cname,30,stdin);
        if (strlen(&customer.Cname) != strcspn(&customer.Cname, "0123456789"))
        {
           printf("\nInvalid Name Format Try Again: ");
           goto check;
        }
     fflush(stdin);
     printf("\nDESTINATION : ");
	do
     gets(&customer.Cdestin);
 	while ((strcmp(strupr(&customer.Cdestin),"MAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"GAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"NGAOUNDERE")!=0)&&
         	(strcmp(&customer.Cdestin,"DSCHANG")!=0) && (strcmp(&customer.Cdestin,"DOUALA")!=0)&& (strcmp(&customer.Cdestin,"BUEA")!=0) &&
            (strcmp(strupr(&customer.Cdestin),"DOUALA")!=0));
     fflush(stdin);
     printf("\nCNI : ");
	do
     fgets(&customer.CNI,10,stdin);
	while (strlen(&customer.CNI) != 9);
     fflush(stdin);
     printf("\nSIT : ");
	do
     scanf("%d",&customer.Csit);
	while(customer.Csit < 1 || customer.Csit > 70);
     fflush(stdin);

     printf("\nBUS NUMBER (BUSxxx): ");
	do
     fgets(&customer.Bnbr,4,stdin);
	while (strlen(&customer.Bnbr) != 3);
     fflush(stdin);

     customer.Ticketsrl = rand()%(9999 + 1 - 1000) + 1000;
     fflush(stdin);

       setvbuf(stdout,NULL,_IONBF,BUFSIZ);
	   fprintf(fp,"\n\n/************************************New Journey Ticket**********************************************\0'");
	   fprintf(fp,"\n----------------------------------- ");
       fprintf(fp,"%s",c);
       fprintf(fp,"%s" ,"----------------------------------- ");
// MIGHTY PUT TICKET NUMBER HERE
	   fprintf(fp,"\nNEW JOURNEY EXPRESS           |");
	   fprintf(fp,"  NEW JOURNEY EXPRESS");
	   fprintf(fp,"\nOFFICE : YAOUNDE              |");
	   fprintf(fp,"  DEPARTURE AGENCY : MVAN ");
	   fprintf(fp,"\nB.O BOX : 458                 |");
	   fprintf(fp,"  NAME : ");
       fprintf(fp,"%s",strupr(&customer.Cname));
	   fprintf(fp,"TEL : +237653398462           |");
	   fprintf(fp,"  DESTINATION : ");
       fprintf(fp, "%s ",strupr(&customer.Cdestin));
	   fprintf(fp,"\nDEPARTURE AGENCY : MVAN       |");
	   fprintf(fp,"  DEPARTURE TIME : ");
	   fprintf(fp,"12:00 Noon");
	   fprintf(fp,"\nJOURNEY CLASS : ");
	   fprintf(fp," Economic     |");
	   fprintf(fp,"  COST :");
	   fprintf(fp," 4000 FCFA");
	   fprintf(fp,"  CNI : ");
	   fprintf(fp, "%s ", &customer.CNI);
	   fprintf(fp,"\nSIT : ");
	   fprintf(fp,"%d  |", customer.Csit);
	   fprintf(fp," BUS Number : ");
	   fprintf(fp,"BUS%s    |", &customer.Bnbr);
	   fprintf(fp,"  TICKET SERIAL : ");
	   fprintf(fp,"NJE%dX ", customer.Ticketsrl);
	fprintf(fp,"\n-----------------------------------------------------------------------------------------------------\0'");
	fprintf(fp,"\n/****************************************************************************************************\0'\n\n");
	fclose(fp);
	fprintf(stdout, "\nPassenger Information has been recorded\n");
	printf("\t\t\t1. SELL ANOTHER TICKET\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2');

    return ch;
    }
}



char DataEntry9PM(struct CustomerInfo customer)
{
     // USE MULTIPLE DO WHILE LOOPS TO CONTROL USER INFORMATION ENTERED BY EMPLOYEE
     time_t start, finish, now;
     size_t loc;
     struct tm *ptr;
     char *c,ch;
     static int ticket_counter = 0;

      ticket_counter++;
      if (ticket_counter>70)
      {
          printf("\n\n\n\n\t\t\t\tALL TICKETS FOR THIS JOURNEY HAVE BEEN SOLD!\n");
          Sleep(10000);
          ch = '2';
      }else{

       system("color 3F");
       FILE *fp = fopen("C:\\New_Journey\\Cust_Db9PM.txt","a+");
      int fflush(FILE *fp);

       if (fp == NULL) {
        perror("Could not open Cust_Db9PM.txt");
        return;
      }

       start = time(0);
       time(&now);
       ptr = localtime(&now);
       c = asctime(ptr);



     printf("\nPlease Fill in the information below. TICKET Number %d /70 \n",ticket_counter);

     printf("\nCUSTOMER NAME : ");
     check:
        fgets(&customer.Cname,30,stdin);
        if (strlen(&customer.Cname) != strcspn(&customer.Cname, "0123456789"))
        {
           printf("\nInvalid Name Format Try Again: ");
           goto check;
        }
     fflush(stdin);
     printf("\nDESTINATION : ");
	do
     gets(&customer.Cdestin);
 	while ((strcmp(strupr(&customer.Cdestin),"MAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"GAROUA")!=0) && (strcmp(strupr(&customer.Cdestin),"NGAOUNDERE")!=0)&&
         	(strcmp(&customer.Cdestin,"DSCHANG")!=0) && (strcmp(&customer.Cdestin,"DOUALA")!=0)&& (strcmp(&customer.Cdestin,"BUEA")!=0) &&
            (strcmp(strupr(&customer.Cdestin),"DOUALA")!=0));
     fflush(stdin);
     printf("\nCNI : ");
	do
     fgets(&customer.CNI,10,stdin);
	while (strlen(&customer.CNI) != 9);
     fflush(stdin);
     printf("\nSIT : ");
	do
     scanf("%d",&customer.Csit);
	while(customer.Csit < 1 || customer.Csit > 70);
     fflush(stdin);

     printf("\nBUS NUMBER (BUSxxx): ");
	do
     fgets(&customer.Bnbr,4,stdin);
	while (strlen(&customer.Bnbr) != 3);
     fflush(stdin);

     customer.Ticketsrl = rand()%(9999 + 1 - 1000) + 1000;

     fflush(stdin);

       setvbuf(stdout,NULL,_IONBF,BUFSIZ);
	   fprintf(fp,"\n\n/************************************New Journey Ticket**********************************************\0'");
	   fprintf(fp,"\n----------------------------------- ");
       fprintf(fp,"%s",c);
       fprintf(fp,"%s" ,"----------------------------------- ");
// MIGHTY PUT TICKET NUMBER HERE
	   fprintf(fp,"\nNEW JOURNEY EXPRESS           |");
	   fprintf(fp,"  NEW JOURNEY EXPRESS");
	   fprintf(fp,"\nOFFICE : YAOUNDE              |");
	   fprintf(fp,"  DEPARTURE AGENCY : MVAN ");
	   fprintf(fp,"\nB.O BOX : 458                 |");
	   fprintf(fp,"  NAME : ");
       fprintf(fp,"%s",strupr(&customer.Cname));
	   fprintf(fp,"TEL : +237653398462           |");
	   fprintf(fp,"  DESTINATION : ");
       fprintf(fp, "%s ",strupr(&customer.Cdestin));
	   fprintf(fp,"\nDEPARTURE AGENCY : MVAN       |");
	   fprintf(fp,"  DEPARTURE TIME : ");
	   fprintf(fp,"9:00 pm");
	   fprintf(fp,"\nJOURNEY CLASS : ");
	   fprintf(fp," Economic     |");
	   fprintf(fp,"  COST :");
	   fprintf(fp," 4000 FCFA");
	   fprintf(fp,"  CNI : ");
	   fprintf(fp, "%s ", &customer.CNI);
	   fprintf(fp,"\nSIT : ");
	   fprintf(fp,"%d  |", customer.Csit);
	   fprintf(fp," BUS Number : ");
	   fprintf(fp,"BUS%s    |", &customer.Bnbr);
	   fprintf(fp,"  TICKET SERIAL : ");
	   fprintf(fp,"NJE%dX ", customer.Ticketsrl);
	fprintf(fp,"\n-----------------------------------------------------------------------------------------------------\0'");
	fprintf(fp,"\n/****************************************************************************************************\0'\n\n");
	fclose(fp);
	fprintf(stdout, "\nPassenger Information has been recorded\n");
	printf("\t\t\t1. SELL ANOTHER TICKET\n");
	printf("\t\t\t2. RETURN TO TICKET MENU\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1' && ch!='2');

    return ch;
    }
}


