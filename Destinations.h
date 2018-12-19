
struct Departures{

  char time[13];
  char destination[12];
  char bus_number[7];
  char bus_type[15];


};
//typedef struct Departures record;

char Destination_Function()
{
    system("title NEW JOURNEY DEPARTURES");
    system("cls");
    printf("\n\n\t\t\t\t\tCHECK ALL DEPARTURE TIMES\n\n");
    char ch;

/*declare bus of type departures*/
struct Departures bus001;
struct Departures bus002;
struct Departures bus003;
struct Departures bus004;

/*BUS 001 INFORMATION*/
strcpy(bus001.time, "8:00am");
strcpy(bus001.destination, "GAROUA");
strcpy(bus001.bus_number, "B097CE");
strcpy(bus001.bus_type, "ECONOMIC CLASS");

/*BUS 002 INFORMATION */
strcpy(bus002.time,"9:00am");
strcpy(bus002.destination,"NGAOUNDERE");
strcpy(bus002.bus_number,"B125CE");
strcpy(bus002.bus_type,"VIP CLASS");

/*BUS 003 INFORMATION*/
strcpy(bus003.time, "12:00 Noon");
strcpy(bus003.destination, "DOUALA");
strcpy(bus003.bus_number, "B135CE");
strcpy(bus003.bus_type, "ECONOMIC CLASS");

/*BUS 004 INFORMATION*/
strcpy(bus004.time, "9:30pm");
strcpy(bus004.destination, "DSCHANG");
strcpy(bus004.bus_number, "B225CE");
strcpy(bus004.bus_type, "ECONOMIC CLASS");

 /* print Bus1 info */
   printf( "\t\t\t\xB2\xB2 Bus 001 time : %s\n", bus001.time);
   printf( "\t\t\t\xB2\xB2 Bus 001 Destination: %s\n", bus001.destination);
   printf( "\t\t\t\xB2\xB2 Bus 001 Bus Number: %s\n", bus001.bus_number);
   printf( "\t\t\t\xB2\xB2 Bus 001 Bus Type: %s\n\n", bus001.bus_type );

   /*print Bus002 info*/
   printf( "\t\t\t\xB2\xB2 Bus 002 time : %s\n",       bus002.time);
   printf( "\t\t\t\xB2\xB2 Bus 002 Destination: %s\n", bus002.destination);
   printf( "\t\t\t\xB2\xB2 Bus 002 Bus Number: %s\n",  bus002.bus_number);
   printf( "\t\t\t\xB2\xB2 Bus 002 Bus Type: %s\n\n",  bus002.bus_type);

   /*PRINT BUS 003 INFO*/
   printf( "\t\t\t\xB2\xB2 Bus 003 time : %s\n",       bus003.time);
   printf( "\t\t\t\xB2\xB2 Bus 003 Destination: %s\n", bus003.destination);
   printf( "\t\t\t\xB2\xB2 Bus 003 Bus Number: %s\n",  bus003.bus_number);
   printf( "\t\t\t\xB2\xB2 Bus 003 Bus Type: %s\n\n",  bus003.bus_type );

   /*PRINT BUS 004 INFO*/
   printf( "\t\t\t\xB2\xB2 Bus 004 time : %s\n", bus004.time);
   printf( "\t\t\t\xB2\xB2 Bus 004 Destination: %s\n", bus004.destination);
   printf( "\t\t\t\xB2\xB2 Bus 004 Bus Number: %s\n", bus004.bus_number);
   printf( "\t\t\t\xB2\xB2 Bus 004 Bus Type: %s\n\n", bus004.bus_type );


	printf("\t\t\t\t\t1. RETURN TO MAIN MENU\n");
	printf("\t\t\t\t\tQ. QUIT PROGRAM\n");
	do{
        ch = getch();
        fflush(stdin);
    }while (ch!='1'&& ch!='Q'&& ch!='q');
     return ch;

}

