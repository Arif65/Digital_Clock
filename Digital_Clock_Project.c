#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>

void gotoxy(int,int);
void hidecursor();
void Max_Console_size();

void loading();
void box();
void box_no_gap(int,int,int,int);
void menu();

void intro_myself();
void intro_project_name();

void print_digit(char, int, int);
void print_letter(char, int ,int);

void zero(int, int);
void one(int, int);
void two(int, int);
void three(int, int);
void four(int, int);
void five(int, int);
void six(int, int);
void seven(int, int);
void eight(int, int);
void nine(int, int);
void remove_digit();

void letter_A(int, int);
void letter_S(int, int);
void letter_T(int, int);
void letter_U(int, int);
void letter_N(int, int);
void letter_M(int, int);
void letter_O(int, int);
void letter_E(int, int);
void letter_W(int, int);
void letter_D(int, int);
void letter_H(int, int);
void letter_F(int, int);
void letter_R(int, int);
void letter_I(int, int);
void letter_J(int, int);
void letter_B(int, int);
void letter_P(int, int);
void letter_Y(int, int);
void letter_L(int, int);
void letter_G(int, int);
void letter_C(int, int);
void letter_V(int, int);
void letter_Q(int, int);
void letter_X(int, int);
void letter_Z(int, int);
void letter_K(int, int);

void colon(int, int);
void blink(int, int);

int valid(char, int);
void set_time_to_country(char *, char *, char *);
void change_date_to_next(char *);
int to_next(int , char *);
void change_date_to_previous(char *);

void show_country_name(char str[60][30], int);
int time_region();

int asia(char str[60][30]);
void list_Asian_countries(int, int, char str[60][30]);
int europe(char str[60][30]);
void list_Europian_countries(int, int, char str[60][30]);
int africa(char str[60][30]);
void list_African_countries(int, int, char str[60][30]);
int north_america(char str[60][30]);
void list_North_American_countries(int, int, char str[60][30]);
int south_america(char str[60][30]);
void list_South_American_countries(int, int, char str[60][30]);
int ocenia(char str[60][30]);
void list_Ocenian_countries(int, int, char str[60][30]);

void to_12_hour(char *);
int hour_format();

int leap_year(char *);

int show_current_time();

int timer();
int valid(char ch, int pos);

int stopwatch();


int get_alarm_record();
void next_from_alarm(int, int);
void show_alarm_record(int);
void set_alarm_record();
int valid_2(char, int);
void delete_alarm_record();
void delete_all();

int alarm();
int pause_time=1;

void description();

int return_input=0;

int main()                   /// MAIN ///
{
    Max_Console_size();
    intro_myself();
    menu();
}

/// Maximizing Console Window Size
void Max_Console_size()
{
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}

/// initializing gotoxy function
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/// for hiding the cursor
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

/// printing digits
void print_digit(char ch, int x, int y)
{
    if(ch=='0')
        zero(x, y);
    else if(ch=='1')
        one(x, y);
    else if(ch=='2')
        two(x, y);
    else if(ch=='3')
        three(x, y);
    else if(ch=='4')
        four(x, y);
    else if(ch=='5')
        five(x, y);
    else if(ch=='6')
        six(x, y);
    else if(ch=='7')
        seven(x, y);
    else if(ch=='8')
        eight(x, y);
    else if(ch=='9')
        nine(x, y);
}

void print_letter(char ch, int x, int y)
{
    ch = toupper(ch);
    if(ch=='A')
            letter_A(x, y);
    else if(ch=='S')
        letter_S(x, y);
    else if(ch=='T')
        letter_T(x, y);
    else if(ch=='U')
        letter_U(x, y);
    else if(ch=='N')
        letter_N(x, y);
    else if(ch=='M')
        letter_M(x, y);
    else if(ch=='O')
        letter_O(x, y);
    else if(ch=='E')
        letter_E(x, y);
    else if(ch=='W')
        letter_W(x, y);
    else if(ch=='D')
        letter_D(x, y);
    else if(ch=='H')
        letter_H(x, y);
    else if(ch=='F')
        letter_F(x, y);
    else if(ch=='R')
        letter_R(x, y);
    else if(ch=='I')
        letter_I(x, y);
    else if(ch=='J')
        letter_J(x, y);
    else if(ch=='B')
        letter_B(x, y);
    else if(ch=='P')
        letter_P(x, y);
    else if(ch=='Y')
        letter_Y(x, y);
    else if(ch=='L')
        letter_L(x, y);
    else if(ch=='G')
        letter_G(x, y);
    else if(ch=='C')
        letter_C(x, y);
    else if(ch=='V')
        letter_V(x, y);
    else if(ch=='Q')
        letter_Q(x, y);
    else if(ch=='X')
        letter_X(x, y);
    else if(ch=='Z')
        letter_Z(x, y);
    else if(ch=='K')
        letter_K(x, y);
}


void menu()
{
    char t;
    system("CLS");
    box_no_gap(25, 5, 70, 9);
    {
        for(int i=25; i<=95; i++)
        {
            gotoxy(i, 4);
            if(i<50)
                printf("%c", 175);
            else if(i>=75)
                printf("%c", 174);
            if(i==53)
                printf("M E N U    B A R");
        }
    }

    gotoxy(30, 6);
        printf("Press 1 to see current time.");
    gotoxy(30, 7);
        printf("Press 2 to use timer.");
    gotoxy(30, 8);
        printf("Press 3 to start stopwatch.");
    gotoxy(30, 9);
        printf("Press 4 to go to Alarm section.");
    gotoxy(30, 10);
        printf("Press 5 to read the features of this applications");
    gotoxy(30, 11);
        printf("Press 0 to exit.");

    gotoxy(30, 13);
        printf("Press a number as given the direction to move on: ");

    box_no_gap(40, 17, 40, 3);
    gotoxy(45, 18);
        printf("Your chosen number is: ");
    gotoxy(69, 18);
        scanf("%c", &t);                                                     ///

    if(return_input==1)
    {
        gotoxy(69, 18);
            scanf("%c", &t);                                                     ///
        gotoxy(90, 19);
            printf("               ");
        return_input=0;
    }
    while(t<'0' || t>'5')
    {
        gotoxy(90, 19);
            printf("Invalid input.");
        gotoxy(69, 18);
            printf("  ");
        gotoxy(45, 18);
            printf("Your chosen number is: ");
        gotoxy(69, 18);
            scanf("%c", &t);

    }

    system("CLS");
    if(t=='0')
    {
        gotoxy(50, 5);
            printf("Thanks for using this app!\n\n\n");
        exit(1);
    }
    if(t=='1')
        show_current_time();
    if(t=='2')
        timer();
    if(t=='3')
        stopwatch();
    if(t=='4')
        alarm();
    if(t=='5')
        description();
}

void loading()
{
    gotoxy(40, 10);
        system("PAUSE");
    system("CLS");
    int i;
    system("COLOR 4F");

    box_no_gap( 18, 9, 53, 2);

    gotoxy(20, 8);
    printf("Loading ...   Please wait a while ");
    fflush(stdout);

    //printf("%c", 218);

    for(i=1; i<=50; i++)
    {
        gotoxy(20+i, 10);
        printf("%c", 176);
        gotoxy(20, 13);
            printf("Loading... %d%%", i*2);
        Sleep(25);
        //Sleep(50);//usleep(50000);
        fflush(stdout);
    }
    system("CLS");
}

void box_no_gap(int x, int y, int len1, int len2) // without internal gap
{
    int i, j;

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y);
        if(i==0)
            printf("%c", 218);
        else if(i==len1+1)
            printf("%c\n", 191);
        else
            printf("%c", 196);
        fflush(stdout);
    }

    for(i=1; i<=len2; i++)
    {
        gotoxy(x, y+i);
        printf("%c", 179);
        for(j=1; j<=len1; j++)
            printf(" ");
        printf("%c\n", 179);
        fflush(stdout);
    }

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y+len2);
        if(i==0)
            printf("%c", 192);
        else if(i==len1+1)
            printf("%c\n", 217);
        else
            printf("%c", 196);
    }
}

/// to make a box shape around the time zone=> with internal gap. for only time zone
void box()
{
     int i, y=10;

     for(i=14; i<45; i++)
     {
         gotoxy(i, 9);
         printf("-");

         gotoxy(i, 14);
         printf("-");

         fflush(stdout);
     }

     for(i=0; i<4; i++)
     {
         gotoxy( 13, y+i);
         printf("|");

         gotoxy( 45, y+i);
         printf("|");

         fflush(stdout);
     }
 }

/// /// /// /// /// /// ///    C U R R E N T     T I M E

int hour_format()
{
    int r;
    box_no_gap(33, 5, 45, 5);
    gotoxy(35, 7);
        printf("Press 1 to continue with 12-hour format.");
    gotoxy(35, 8);
        printf("Press 2 to continue with 24-hour format.");
    box_no_gap(40, 13, 35, 2);
    gotoxy(45, 14);
        printf("Your chosen option: ");
        scanf("%d", &r);
    while(r!=1 && r!=2)
    {
        gotoxy(85,15);
        printf("Invalid input.");

        gotoxy(66, 14);
        printf("  ");
        gotoxy(65, 14);
            printf("Your chosen option: ");
            scanf("%d", &r);
    }
    gotoxy(85,15);
        printf("               ");
    system("CLS");
    return r;
}

void to_12_hour(char s[])
{
    if(s[0]=='0' && s[1] == '0')
    {
        s[0]='1';
        s[1]='2';
        s[8]='A';
        return;
    }
    if(s[0]=='0' && s[1] == '1')
    {
        s[0]='0';
        s[1]='1';
        s[8]='A';
        return;
    }
    if(s[0]=='0' && s[1] == '2')
    {
        s[0]='0';
        s[1]='2';
        s[8]='A';
        return;
    }
    if(s[0]=='0' && s[1] == '3')
    {
        s[0]='0';
        s[1]='3';
        s[8]='A';
        return;
    }
    if(s[0]=='0' && s[1] == '4')
    {
        s[0]='0';
        s[1]='4';
        s[8]='A';
        return;
    }
    if(s[0]=='0' && s[1] == '5')
    {
        s[0]='0';
        s[1]='5';
        s[8]='A';
    }
    if(s[0]=='0' && s[1] == '6')
    {
        s[0]='0';
        s[1]='6';
        s[8]='A';
        return;
    }
    if(s[0]=='0' && s[1] == '7')
    {
        s[0]='0';
        s[1]='7';
        s[8]='A';
    }
    if(s[0]=='0' && s[1] == '8')
    {
        s[0]='0';
        s[1]='8';
        s[8]='A';
        return;
    }
    if(s[0]=='0' && s[1] == '9')
    {
        s[0]='0';
        s[1]='9';
        s[8]='A';
        return;
    }
    if(s[0]=='1' && s[1] == '0')
    {
        s[0]='1';
        s[1]='0';
        s[8]='A';
        return;
    }
    if(s[0]=='1' && s[1] == '1')
    {
        s[0]='1';
        s[1]='1';
        s[8]='A';
        return;
    }

    if(s[0]=='1' && s[1] == '2')
    {
        s[0]='1';
        s[1]='2';
        s[8]='P';
        return;
    }
    if(s[0]=='1' && s[1] == '3')
    {
        s[0]='0';
        s[1]='1';
        s[8]='P';
        return;
    }
    if(s[0]=='1' && s[1] == '4')
    {
        s[0]='0';
        s[1]='2';
        s[8]='P';
        return;
    }
    if(s[0]=='1' && s[1] == '5')
    {
        s[0]='0';
        s[1]='3';
        s[8]='P';
        return;
    }
    if(s[0]=='1' && s[1] == '6')
    {
        s[0]='0';
        s[1]='4';
        s[8]='P';
        return;
    }
    if(s[0]=='1' && s[1] == '7')
    {
        s[0]='0';
        s[1]='5';
        s[8]='P';
        return;
    }
    if(s[0]=='1' && s[1] == '8')
    {
        s[0]='0';
        s[1]='6';
        s[8]='P';
        return;
    }
    if(s[0]=='1' && s[1] == '9')
    {
        s[0]='0';
        s[1]='7';
        s[8]='P';
        return;
    }
    if(s[0]=='2' && s[1] == '0')
    {
        s[0]='0';
        s[1]='8';
        s[8]='P';
        return;
    }
    if(s[0]=='2' && s[1] == '1')
    {
        s[0]='0';
        s[1]='9';
        s[8]='P';
        return;
    }
    if(s[0]=='2' && s[1] == '2')
    {
        s[0]='1';
        s[1]='0';
        s[8]='P';
        return;
    }
    if(s[0]=='2' && s[1] == '3')
    {
        s[0]='1';
        s[1]='1';
        s[8]='P';
        return;
    }

}

void list_Asian_countries(int x, int y, char str[60][30])
{
    int i;
    strcpy( str[0], "Afghanistan");
    strcpy( str[1], "Armenia");
    strcpy( str[2], "Azerbijan");
    strcpy( str[3], "Bahrain");
    strcpy( str[4], "Bangladesh");
    strcpy( str[5], "Bhutan");
    strcpy( str[6], "Brunei");
    strcpy( str[7], "Combodia");
    strcpy( str[8], "China");
    strcpy( str[9], "Cyprus");

    strcpy( str[10], "Georgia");
    strcpy( str[11], "Hong Kong");
    strcpy( str[12], "India");
    strcpy( str[13], "Indonesia");
    strcpy( str[14], "Iran");
    strcpy( str[15], "Iraq");
    strcpy( str[16], "Japan");
    strcpy( str[17], "Jordan");
    strcpy( str[18], "Kazakhstan");
    strcpy( str[19], "Korea, North");

    strcpy( str[20], "Korea, South");
    strcpy( str[21], "Kuwait");
    strcpy( str[22], "Kyrgystan");
    strcpy( str[23], "Laos");
    strcpy( str[24], "Lebanon");
    strcpy( str[25], "Macau");
    strcpy( str[26], "Malaysia");
    strcpy( str[27], "Maldives");
    strcpy( str[28], "Myanmar");
    strcpy( str[29], "Mongolia");

    strcpy( str[30], "Nepal");
    strcpy( str[31], "Oman");
    strcpy( str[32], "Pakistan");
    strcpy( str[33], "Palestine");
    strcpy( str[34], "Philippines");
    strcpy( str[35], "Qatar");
    strcpy( str[36], "Russia");
    strcpy( str[37], "Saudi Arabia");
    strcpy( str[38], "Singapore");
    strcpy( str[39], "Srilanka");

    strcpy( str[40], "Syria");
    strcpy( str[41], "Taiwan");
    strcpy( str[42], "Tajikistan");
    strcpy( str[43], "Thailand");
    strcpy( str[44], "Turkmenistan");
    strcpy( str[45], "Turkey");
    strcpy( str[46], "United Arab Emirates");
    strcpy( str[47], "Uzbekistan");
    strcpy( str[48], "Vietnam");
    strcpy( str[49], "Yemen");

    for(i=0; i<50; i++)
    {
        gotoxy(x, y++);
            if(i<9)
                printf(" ");
            printf("%d %s", i+1, str[i]);
        if(i==16)
        {
            x=45;
            y=2;
        }
        if(i==33)
        {
            x=78;
            y=2;
        }
    }
}

int asia(char str[60][30])
{
    int p;
    for(int i=10; i<=110; i++)
    {
        gotoxy(i, 0);
        if(i<=45)
            printf("%c", 175);
        if(i>=75)
            printf("%c", 174);
        if(i==47)
            printf("Countries of Asian Region");
    }

    box_no_gap(10, 1, 33, 18);
    box_no_gap(44, 1, 33, 18);
    box_no_gap(77, 1, 33, 18);

                                  /// List of Asian Countries
    list_Asian_countries(11, 2, str);

    box_no_gap(45, 22, 30, 2);
    gotoxy(50, 23);
        printf("Your chosen country: ");
        scanf("%d", &p);

    while(p<1 || p>50)
    {
        gotoxy(80,23);
            printf("Invalid input.");
        gotoxy(71, 23);
            printf("    ");
        gotoxy(50, 23);
            printf("Your chosen country: ");
            scanf("%d", &p);
    }
    gotoxy(80,23);
            printf("               ");

    system("CLS");
    return p;
}

void list_Europian_countries(int x, int y, char str[60][30])
{
    int i;
    strcpy( str[0], "Albania");
    strcpy( str[1], "Andorra");
    strcpy( str[2], "Austria");
    strcpy( str[3], "Belarus");
    strcpy( str[4], "Belgium");
    strcpy( str[5], "Bosnia-Herzegovina");
    strcpy( str[6], "Bulgaria");
    strcpy( str[7], "Croatia");
    strcpy( str[8], "Czech");
    strcpy( str[9], "Denmark");

    strcpy( str[10], "England");
    strcpy( str[11], "Estonia");
    strcpy( str[12], "Finland");
    strcpy( str[13], "France");
    strcpy( str[14], "Georgia");
    strcpy( str[15], "Germany");
    strcpy( str[16], "Gibraltar");
    strcpy( str[17], "Greece");
    strcpy( str[18], "Greenland");
    strcpy( str[19], "Guernsey");

    strcpy( str[20], "Hungary");
    strcpy( str[21], "Iceland");
    strcpy( str[22], "Ireland");
    strcpy( str[23], "Isle of Man");
    strcpy( str[24], "Italy");
    strcpy( str[25], "Jersey");
    strcpy( str[26], "Kosovo");
    strcpy( str[27], "Latvia");
    strcpy( str[28], "Liechtenstein");
    strcpy( str[29], "Lithunia");

    strcpy( str[30], "Luxembourg");
    strcpy( str[31], "Malta");
    strcpy( str[32], "Moldova");
    strcpy( str[33], "Montenegra");
    strcpy( str[34], "Netherlands");
    strcpy( str[35], "Norway");
    strcpy( str[36], "Poland");
    strcpy( str[37], "Portugal");
    strcpy( str[38], "Romania");
    strcpy( str[39], "Serbia");

    strcpy( str[40], "San Marino");
    strcpy( str[41], "Slovakia");
    strcpy( str[42], "Slovenia");
    strcpy( str[43], "Spain");
    strcpy( str[44], "Sweden");
    strcpy( str[45], "Switzerland");
    strcpy( str[46], "Turkey");
    strcpy( str[47], "Ukrain");
    strcpy( str[48], "United Kingdom");
    strcpy( str[49], "Vatican City");

    for(i=0; i<50; i++)
    {
        gotoxy(x, y++);
            if(i<9)
                printf(" ");
            printf("%d %s", i+1, str[i]);
        if(i==16)
        {
            x=45;
            y=2;
        }
        if(i==33)
        {
            x=78;
            y=2;
        }
    }

}

int europe(char str[60][30])
{
    int p;
    for(int i=10; i<=110; i++)
    {
        gotoxy(i, 0);
        if(i<=45)
            printf("%c", 175);
        if(i>=75)
            printf("%c", 174);
        if(i==47)
            printf("Countries of Europian Region");
    }

    box_no_gap(10, 1, 33, 18);
    box_no_gap(44, 1, 33, 18);
    box_no_gap(77, 1, 33, 18);

    list_Europian_countries(11, 2, str);

    box_no_gap(45, 22, 30, 2);
    gotoxy(50, 23);
        printf("Your chosen country: ");
        scanf("%d", &p);

    while(p<1 || p>50)
    {
        gotoxy(80,23);
            printf("Invalid input.");
        gotoxy(71, 23);
            printf("    ");
        gotoxy(50, 23);
            printf("Your chosen country: ");
            scanf("%d", &p);
    }
    gotoxy(80,23);
        printf("               ");

    system("CLS");
    return p;
}

void list_African_countries(int x, int y, char str[60][30])
{
    int i;
    strcpy( str[0], "Algeria");
    strcpy( str[1], "Angolia");
    strcpy( str[2], "Benin");
    strcpy( str[3], "Botswane");
    strcpy( str[4], "Burkina Faso");
    strcpy( str[5], "Burundi");
    strcpy( str[6], "Cameroon");
    strcpy( str[7], "Chad");
    strcpy( str[8], "Comoros");
    strcpy( str[9], "Congo");

    strcpy( str[10], "Djibouti");
    strcpy( str[11], "Egypt");
    strcpy( str[12], "Eritrea");
    strcpy( str[13], "Eswatini");
    strcpy( str[14], "Etheopia");
    strcpy( str[15], "Gabon");
    strcpy( str[16], "Gambia");
    strcpy( str[17], "Ghana");
    strcpy( str[18], "Huinea");
    strcpy( str[19], "Kenya");

    strcpy( str[20], "Lesotho");
    strcpy( str[21], "Liberia");
    strcpy( str[22], "Libya");
    strcpy( str[23], "Madagascar");
    strcpy( str[24], "Malawi");
    strcpy( str[25], "Mali");
    strcpy( str[26], "Mauritania");
    strcpy( str[27], "Mauritius");
    strcpy( str[28], "Mayotte");
    strcpy( str[29], "Morocco");

    strcpy( str[30], "Mozambique");
    strcpy( str[31], "Namibia");
    strcpy( str[32], "Niger");
    strcpy( str[33], "Nigeria");
    strcpy( str[34], "Reunion");
    strcpy( str[35], "Rwanda");
    strcpy( str[36], "Saint Helena");
    strcpy( str[37], "Senegal");
    strcpy( str[38], "Seychelles");
    strcpy( str[39], "Sierra Leone");

    strcpy( str[40], "Somalia");
    strcpy( str[41], "South Africa");
    strcpy( str[42], "Sudan");
    strcpy( str[43], "Swaziland");
    strcpy( str[44], "Tanzania");
    strcpy( str[45], "Togo");
    strcpy( str[46], "Tunisia");
    strcpy( str[47], "Uganda");
    strcpy( str[48], "Western Sahara");
    strcpy( str[49], "Zambia");

    strcpy( str[50], "Zimbabwe");

    for(i=0; i<=50; i++)
    {
        gotoxy(x, y++);
            if(i<9)
                printf(" ");
            printf("%d %s", i+1, str[i]);
        if(i==16)
        {
            x=45;
            y=2;
        }
        if(i==33)
        {
            x=78;
            y=2;
        }
    }

}

int africa(char str[60][30])
{
    int p;
    for(int i=10; i<=110; i++)
    {
        gotoxy(i, 0);
        if(i<=45)
            printf("%c", 175);
        if(i>=75)
            printf("%c", 174);
        if(i==47)
            printf("Countries of African Region");
    }

    box_no_gap(10, 1, 33, 18);
    box_no_gap(44, 1, 33, 18);
    box_no_gap(77, 1, 33, 18);

    list_African_countries(11, 2, str);

    box_no_gap(45, 22, 30, 2);
    gotoxy(50, 23);
        printf("Your chosen country: ");
        scanf("%d", &p);

    while(p<1 || p>51)
    {
        gotoxy(80,23);
            printf("Invalid input.");
        gotoxy(71, 23);
            printf("    ");
        gotoxy(50, 23);
            printf("Your chosen country: ");
            scanf("%d", &p);
    }
    gotoxy(80,23);
        printf("                ");

    system("CLS");
    return p;
}

void list_North_American_countries(int x, int y, char str[60][30])
{
    int i;
    strcpy( str[0], "Aruba");
    strcpy( str[1], "Bahamas");
    strcpy( str[2], "Barbados");
    strcpy( str[3], "Belize");
    strcpy( str[4], "Bermuda");
    strcpy( str[5], "Canada");
    strcpy( str[6], "Costa Rica");
    strcpy( str[7], "Cuba");
    strcpy( str[8], "Dominica");
    strcpy( str[9], "El Salvador");

    strcpy( str[10], "Greneda");
    strcpy( str[11], "Guatemala");
    strcpy( str[12], "Haiti");
    strcpy( str[13], "Honduras");
    strcpy( str[14], "Jamaica");
    strcpy( str[15], "Mexico");
    strcpy( str[16], "Montsernat");
    strcpy( str[17], "Nicaragua");
    strcpy( str[18], "Panama");
    strcpy( str[19], "Saint Lucia");

    strcpy( str[20], "United States of America");

    for(i=0; i<=20; i++)
    {
        gotoxy(x, y++);
            if(i<9)
                printf(" ");
            printf("%d %s", i+1, str[i]);
        if(i==10)
        {
            x=51;
            y=2;
        }
    }
}

int north_america(char str[60][30])
{
    int p;
    for(int i=10; i<=110; i++)
    {
        gotoxy(i, 0);
        if(i<=45)
            printf("%c", 175);
        if(i>=75)
            printf("%c", 174);
        if(i==47)
            printf("Countries of North American Region");
    }

    box_no_gap(10, 1, 50, 15);
    box_no_gap(50, 1, 50, 15);

    list_North_American_countries(11, 2, str);

    box_no_gap(35, 18, 30, 2);
    gotoxy(40, 19);
        printf("Your chosen country: ");
        scanf("%d", &p);

    while(p<1 || p>21)
    {
        gotoxy(70,19);
            printf("Invalid input.");
        gotoxy(61, 19);
            printf("    ");
        gotoxy(40, 19);
            printf("Your chosen country: ");
            scanf("%d", &p);
    }
    gotoxy(70,19);
        printf("               ");

    system("CLS");
    return p;
}

void list_South_American_countries(int x, int y, char str[60][30])
{
    int i;
    strcpy( str[0], "Argentina");
    strcpy( str[1], "Bolivia");
    strcpy( str[2], "Chile");
    strcpy( str[3], "Brazil");
    strcpy( str[4], "Columbia");
    strcpy( str[5], "Ecuador");
    strcpy( str[6], "Gyana");
    strcpy( str[7], "Paraguay");
    strcpy( str[8], "Peru");
    strcpy( str[9], "Suriname");

    strcpy( str[10], "Uruguay");
    strcpy( str[11], "Venezuela");

    for(i=0; i<=11; i++)
    {
        gotoxy(x, y++);
            if(i<9)
                printf(" ");
            printf("%d %s", i+1, str[i]);
    }

}

int south_america(char str[60][30])
{
    int p;
    for(int i=20; i<=60; i++)
    {
        gotoxy(i, 0);
        if(i<=40)
            printf("%c", 175);
        if(i>=60)
            printf("%c", 174);
        if(i==42)
            printf("Countries of South American Region");
    }

    box_no_gap(20, 1, 60, 15);

    list_South_American_countries(21, 2, str);

    box_no_gap(35, 18, 30, 2);
    gotoxy(40, 19);
        printf("Your chosen country: ");
        scanf("%d", &p);

    while(p<1 || p>12)
    {
        gotoxy(70,19);
            printf("Invalid input.");
        gotoxy(60, 19);
            printf("    ");
        gotoxy(40, 19);
            printf("Your chosen country: ");
            scanf("%d", &p);
    }
    gotoxy(70,19);
        printf("             ");

    system("CLS");
    return p;
}

void list_Ocenian_countries(int x, int y, char str[60][30])
{
    int i;
    strcpy( str[0], "Australia");
    strcpy( str[1], "Fiji");
    strcpy( str[2], "Guam");
    strcpy( str[3], "Kiribati");
    strcpy( str[4], "Micronesia");
    strcpy( str[5], "Nauru");
    strcpy( str[6], "New Caledonia");
    strcpy( str[7], "New Zealand");
    strcpy( str[8], "Palau");
    strcpy( str[9], "Papua New Guinea");

    strcpy( str[10], "Samoa");
    strcpy( str[11], "Solomon Island");
    strcpy( str[12], "Tongo");
    strcpy( str[13], "Tuvalu");
    strcpy( str[14], "Vanatu");
    strcpy( str[15], "Wake Island");

    for(i=0; i<=15; i++)
    {
        gotoxy(x, y++);
            if(i<9)
                printf(" ");
            printf("%d %s", i+1,  str[i]);
    }

}

int ocenia(char str[60][30])
{
    int p;
    for(int i=20; i<=60; i++)
    {
        gotoxy(i, 0);
        if(i<=40)
            printf("%c", 175);
        if(i>=60)
            printf("%c", 174);
        if(i==42)
            printf("Countries of Ocenian Region");
    }

    box_no_gap(20, 1, 60, 18);

    list_Ocenian_countries(21, 2, str);

    box_no_gap(35, 20, 30, 2);
    gotoxy(40, 21);
        printf("Your chosen country: ");
        scanf("%d", &p);

    while(p<1 || p>16)
    {
        gotoxy(70,21);
            printf("Invalid input.");
        gotoxy(60, 21);
            printf("    ");
        gotoxy(40, 21);
            printf("Your chosen country: ");
            scanf("%d", &p);
    }
    gotoxy(70,21);
        printf("               ");

    system("CLS");
    return p;
}

int time_region()
{
    int x;
    box_no_gap(30, 5, 50, 10);
    for(int i=130; i<=60; i++)
    {
        gotoxy(i, 4);
        if(i<=50)
            printf("%c", 175);
        if(i>=60)
            printf("%c", 174);
        if(i==52)
            printf("Regions");
            fflush(stdout);
    }
    gotoxy(35, 6);
        printf("1 Asian Region");
    gotoxy(35, 7);
        printf("2 Europian Region");
    gotoxy(35, 8);
        printf("3 African Region");
    gotoxy(35, 9);
        printf("4 North Amerian Region");
    gotoxy(35, 10);
        printf("5 South American Region");
    gotoxy(35, 11);
        printf("6 Ocenia & Pacific Ocean Region");

    box_no_gap(40, 17, 30, 2);
    gotoxy(45, 18);
        printf("Your chosen region: ");
        scanf("%d", &x);
    while(x<1 || x>6)
    {
        gotoxy(95, 18);
            printf("Invalid input.");
        gotoxy(65,18);
            printf("  ");
        gotoxy(45, 18);
            printf("Your chosen region: ");
            scanf("%d", &x);
    }
    gotoxy(95, 18);
        printf("               ");
    system("CLS");
    return x;
}

void show_country_name(char str[60][30], int p)
{
    int i, x_pos;
    for(i=0; i<30; i++)
    {
        gotoxy(i, 0);
        if(str[p][i]==' ' && str[p][i+1]==' ')
            return;
        x_pos=(i+2)*4;
        if(i!=0 && str[p][i-1]=='I')
            x_pos-=2;
        print_letter(str[p][i], x_pos, 2);
    }
}

void set_time(int r, int c, char to_change[9])
{
    to_change[1]='0';
    if(r==1) /// Asia
    {
        if(c==0) // -01:30
        {
            to_change[0]='-';
            to_change[2]='1';
            to_change[4]='3';
        }
        if(c==1||c==2||c==10||c==31||c==46) // -02:00
        {
            to_change[0]='-';
            to_change[2]='2';
        }
        if(c==3||c==14||c==21||c==35||c==36||c==37||c==45||c==49) // -03:00
        {
            to_change[0]='-';
            to_change[2]='3';
        }
        if(c==6||c==8||c==11||c==25||c==26||c==29||c==34||c==38||c==41) // +02:00
        {
            to_change[2]='2';
        }
        if(c==7||c==13||c==23||c==43||c==48) // +01:00
        {
            to_change[2]='1';
        }
        if(c==9||c==17||c==24||c==33||c==40)  // -04:00
        {
            to_change[0]='-';
            to_change[2]='4';
        }
        if(c==12||c==39) // -00:30
        {
            to_change[0]='-';
            to_change[4]='3';
        }
        if(c==15) // -02:30
        {
            to_change[0]='-';
            to_change[2]='2';
            to_change[4]='3';
        }
        if(c==16||c==19||c==20) // +03:00
        {
            to_change[0]='+';
            to_change[2]='3';
        }
        if(c==28) // +00:30
        {
            to_change[4]='3';
        }
        if(c==30) // -00:15
        {
            to_change[0]='-';
            to_change[4]='1';
            to_change[5]='5';
        }
        if(c==27||c==32||c==42||c==44||c==47) // -01:00
        {
            to_change[0]='-';
            to_change[2]='1';
        }
    }
    if(r==2) // Europe
    {
        to_change[0]='-';
        to_change[2]='5';
        if(c==3||c==46)
        {
            to_change[2]='3';
        }
        if(c==6||c==11||c==12||c==17||c==27||c==29||c==32||c==38||c==47)
        {
            to_change[2]='4';
        }
        if(c==14)
        {
            to_change[2]='2';
        }
        if(c==10||c==21||c==22||c==23||c==25||c==37||c==48)
        {
            to_change[2]='6';
        }
        if(c==18)
        {
            to_change[2]='9';
        }
    }
    if(r==3)
    {
        to_change[0]='-';
        to_change[2]='5';
        if(c==3||c==5||c==11||c==13||c==20||c==22||c==24||c==30||c==31||c==35||c==41||c==42||c==43||c==49||c==50)
        {
            to_change[2]='4';
        }
        if(c==4||c==16||c==17||c==18||c==21||c==25||c==26||c==36||c==37||c==39||c==45)
        {
            to_change[2]='6';
        }
        if(c==8||c==10||c==12||c==14||c==19||c==23||c==28||c==40||c==44||c==47)
        {
            to_change[2]='3';
        }
        if(c==27||c==34||c==38)
        {
            to_change[2]='2';
        }
    }
    if(r==4)
    {
        to_change[0]='-';
        to_change[1]='1'; // -10:00:00
        if(c==3||c==6||c==9||c==11||c==13||c==15||c==17)
        {
            to_change[2]='2';
        }
        if(c==14||c==18)
        {
            to_change[2]='1';
        }
        if(c==4)
        {
            to_change[1]=='0';
            to_change[2]='9';
        }
    }
    if(r==5)
    {
        to_change[0]='-';
        to_change[2]='9'; // -09:00:00
        if(c==1||c==6||c==11)
        {
            to_change[1]='1';
            to_change[2]='0';
        }
        if(c==4||c==5||c==8)
        {
            to_change[1]='1';
            to_change[2]='1';
        }
    }
    if(r==6)
    {
        to_change[2]='6';
        if(c==0||c==6||c==11||c==14)
        {
            to_change[2]='5';
        }
        if(c==2||c==4||c==9)
        {
            to_change[2]='4';
        }
        if(c==7||c==12)
        {
            to_change[2]='7';
        }
        if(c==8)
        {
            to_change[2]='3';
        }
        if(c==10)
        {
            to_change[2]='8';
        }
    }
}

void change_date_to_previous(char tmp[25])
{
    int i, j, k;
    char str_day[7][3] = { "SAT", "SUN", "MON", "TUE", "WED", "THU", "FRI" }; // Day
    for(k=0; k<20; k++)
    {
        if(tmp[k]>='a'&&tmp[k]<='z' || tmp[k]>='A'&&tmp[k]<='Z')
            tmp[k]=toupper(tmp[k]);
    }
    for(i=0; i<7; i++)
    {
        if(tmp[0]==str_day[i][0] && tmp[1]==str_day[i][1])
        {
            if(i==0)
                j=6;
            else
                j=i-1;
            tmp[0]=str_day[j][0];
            tmp[1]=str_day[j][1];
            tmp[2]=str_day[j][2];
            break;
        }
    }
                                                                                    // MM
    if(tmp[8]=='0'&&tmp[9]=='1')
    {
        char str_mon[12][3] ={ "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
        for(i=0; i<12; i++)
        {
            if(tmp[4]==str_mon[i][0] && tmp[5]==str_mon[i][1] && tmp[6]==str_mon[i][2])
            {
                if(i==0)
                    j=11;
                else
                    j=i-1;
                tmp[4]=str_mon[j][0];
                tmp[5]=str_mon[j][1];
                tmp[6]=str_mon[j][2];
                break;
            }
        }
    }
                                                                                    // DD
    if(tmp[8]=='0'&&tmp[9]=='1')
    {
        char str_mon[12][3] ={ "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
        for(i=0; i<11; i++)
        {
            if(tmp[4]==str_mon[i][0] && tmp[5]==str_mon[i][1] && tmp[6]==str_mon[i][2])
            {
                if(i==1||i==3||i==5||i==7||i==8||i==10||i==0)
                {
                    tmp[8]='3';
                }
                if(i==4||i==6||i==9||i==1)
                {
                    tmp[8]='3';
                    tmp[9]='0';
                }
                if(i==2)
                {
                    tmp[8]='2';
                    if(leap_year(tmp))
                        tmp[9]='9';
                    else
                        tmp[9]='8';
                }
                break;
            }
        }
    }
    else
    {
        if(tmp[9]=='0')
        {
            tmp[9]='9';
            tmp[8]--;
        }
        else
        {
            tmp[9]--;
        }
    }
                                                                                    // YYYY
    if(tmp[4]=='J'&&tmp[5]=='A'&& tmp[6]=='N'&&tmp[8]=='0'&&tmp[9]=='1')
    {
        if(tmp[23]=='0')
        {
            tmp[23]='9';
            if(tmp[22]=='0')
            {
                tmp[22]='9';
                if(tmp[21]=='0')
                {
                    tmp[21]='9';
                    tmp[20]--;
                }
                else
                    tmp[21]--;
            }
            else
                tmp[22]--;
        }
        else
            tmp[23]--;
    }
}

int leap_year(char tmp[25])
{
    int x = (int)(tmp[20]-'0')*1000;
    x+=(int)(tmp[21]-'0')*100;
    x+=(int)(tmp[22]-'0')*10;
    x+=(int)(tmp[23]-'0');

    if(x%400==0 || (x%4==0 && x%100!=0))
        return 1;
    return 0;
}

int to_next(int i, char tmp[25])
{
    if( (i==0||i==2||i==4||i==6||i==7||i==9||i==11) && tmp[8]=='3' && tmp[9]=='1' )
        return 1;
    else if( (i==3||i==5||i==8||i==10) && tmp[8]=='3' && tmp[9]=='0' )
        return 1;
    if(i==1)
    {
        if(leap_year(tmp) && tmp[8]=='2' && tmp[9]=='9')
            return 1;
        else if(tmp[8]=='2' && tmp[9]=='8')
            return 1;
    }
    return 0;
}

void change_date_to_next(char tmp[25])
{
    int i, j, k;
    char str_day[7][3] = { "SAT", "SUN", "MON", "TUE", "WED", "THU", "FRI" };
    char str_mon[12][3] ={ "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
    for(k=0; k<20; k++)
    {
        if(tmp[k]>='a'&&tmp[k]<='z' || tmp[k]>='A'&&tmp[k]<='Z')
            tmp[k]=toupper(tmp[k]);
    }
    for(i=0; i<7; i++)
    {
        if(tmp[0]==str_day[i][0] && tmp[1]==str_day[i][1])
        {
            if(i==6)
                j=0;
            else
                j=i+1;
            tmp[0]=str_mon[j][0];
            tmp[1]=str_mon[j][1];
            tmp[2]=str_mon[j][2];
            break;
        }
    }
                                                                                    // MM
    for(i=0; i<12; i++)
    {
        if(tmp[4]==str_mon[i][0] && tmp[5]==str_mon[i][1] && tmp[6]==str_mon[i][2])
        {
            if( to_next(i, tmp) )
            {
                if(i==11)
                    j=0;
                else
                    j=i+1;
                tmp[4]=str_day[j][0];
                tmp[5]=str_day[j][1];
                tmp[6]=str_day[j][2];
                break;
            }
        }
    }
                                                                            // DD
    for(int i=0; i<11; i++)
    {
        if(tmp[4]==str_mon[i][0] && tmp[5]==str_mon[i][1] && tmp[6]==str_mon[i][2])
        {
            if( (i==11||i==3||i==5||i==6||i==8||i==10) && tmp[8]=='3' && tmp[9]=='0' )
            {
                tmp[8]='0';
                tmp[9]='1';
            }
            if( (i==0||i==2||i==4||i==7||i==9) && tmp[8]=='3' && tmp[9]=='1' )
            {
                tmp[8]='0';
                tmp[9]='1';
            }
            if(i==1)
            {
                if(leap_year(tmp) && tmp[8]=='2' && tmp[9]=='9')
                {
                    tmp[8]='0';
                    tmp[9]='1';
                }
                else if(tmp[8]=='2' && tmp[9]=='9')
                {
                    tmp[8]='0';
                    tmp[9]='1';
                }
            }
            break;
        }
    }
                                                                                    //YYYY
    if(tmp[4]=='D'&&tmp[5]=='E'&& tmp[6]=='C'&&tmp[8]=='3'&&tmp[9]=='1')
    {
        if(tmp[23]=='9')
        {
            tmp[23]='0';
            if(tmp[22]=='9')
            {
                tmp[22]='0';
                if(tmp[21]=='9')
                {
                    tmp[21]='0';
                    tmp[20]++;
                }
                else
                    tmp[21]++;
            }
            else
                tmp[22]++;
        }
        else
            tmp[23]++;
    }
}

void set_time_to_country(char s[9], char to_change[9], char tmp[25])
{
    int h1, h2, m1, m2, h, m, flag, c;
    h1 = ((int)s[0]-'0')*10+((int)s[1]-'0'); // present
    m1 = ((int)s[3]-'0')*10+((int)s[4]-'0');

    h2 = ((int)to_change[1]-'0')*10+((int)to_change[2]-'0'); // to update
    m2 = ((int)to_change[4]-'0')*10+((int)to_change[5]-'0');

    //printf("Current: h1 = %d, m1 = %d\n", h1, m1);
    //printf("Current: h2 = %d, m2 = %d\n", h2, m2);

    if(to_change[0]=='-')
    {
        flag=0, c=0;
        if(h1<h2 || (h1==h2 && m1<m2))
            c=1;
        if(m1>=m2)
            m=m1-m2;
        else
        {
            flag=1;
            m=60+m1-m2;
        }
        if(h1>=h2)
            h=h1-h2;
        else
            h=24+h1-h2;
        if(flag)
            h--;
        if(c)
        {
            change_date_to_previous(tmp);
            h%=24;
        }
    }
    else
    {
        flag=0, c=0;
        if(h1+h2>=24 || (h1==h2 && m1+m2>=60))
            c=1;
        m=m1+m2;
        if(m>=60)
            flag=1;
        m%=60;
        h=h1+h2;
        if(flag)
            h++;
        if(c)
        {
            change_date_to_next(tmp);
            h%=24;
        }
    }
    s[1]=(char)(h%10+'0');
    s[0]=(char)(h/10+'0');

    s[4]=(char)(m%10+'0');
    s[3]=(char)(m/10+'0');
}

struct A
{
    int pos;
    char s[10];
};
typedef struct A STD;
STD p[21];
int ttl_alarm;

int show_current_time()
{
    pause_time=1;
    int i, j, k, var_alarm, flag_alarm=0, x, y, cnt, var, region, country;
    char tmp[25], s[9], day[4], date[3], month[4], year[5], ch0, ch1, ch3, ch4, ch6, ch7, str[60][30], str_alarm[20][8];
    char to_change[9];
    var = hour_format();

    region = time_region();

    for(i=0; i<30; i++)
        for(j=0; j<60; j++)
            str[j][i]=' ';

    for(i=0; i<9; i++)
    {
        to_change[i]='0';
        if(i==0)
            to_change[i]='+';
        if(i==3||i==6)
            to_change[i]=':';
    }

    if(region==1)
        country = asia(str);
    if(region==2)
        country = europe(str);
    if(region==3)
        country = africa(str);
    if(region==4)
        country = north_america(str);
    if(region==5)
        country = south_america(str);
    if(region==6)
        country = ocenia(str);
    country--;
    set_time(region, country, to_change);

    loading();
    time_t t;

    time(&t);
    strcpy(tmp,ctime(&t));

    for(i=0; i<8; i++)
    {
        s[i]=tmp[i+11];
    }

    system("COLOR 8F");
    system("CLS");

    hidecursor();

    for(int i=13; i<=45; i++)
    {
        show_country_name(str, country);
        gotoxy(i, 8);
        if(i<=21)
            printf("%c", 175);
        else if(i>=36)
            printf("%c", 174);
        if(i==23)
            printf("Current Time");
    }

    ch0=ch1=ch3=ch4=ch6=ch7='a';

    cnt=1;
    if(cnt==1)
    {
        box();
        box_no_gap(70, 10, 25, 4);

        box_no_gap(15, 20, 25, 4);
        box_no_gap(41, 20, 25, 4);
        box_no_gap(67, 20, 25, 4);
    }

    while(cnt++)
    {
        set_time_to_country(s, to_change, tmp);
        if(var==1)
        {
            to_12_hour(s);
            print_letter(s[8], 47, 10);
            print_letter('M', 51, 10);
        }
                            /// ///         Day

        print_letter(tmp[0], 77, 11);
        print_letter(tmp[1], 81, 11);
        print_letter(tmp[2], 85, 11);

                            /// ///         DD
        print_digit(tmp[8], 22, 21);
        print_digit(tmp[9], 26, 21);

                            /// ///         MMM

        print_letter(tmp[4], 48, 21);
        print_letter(tmp[5], 52, 21);
        print_letter(tmp[6], 56, 21);
                            /// ///         YYYY

        print_digit(tmp[20], 74, 21);
        print_digit(tmp[21], 78, 21);
        print_digit(tmp[22], 82, 21);
        print_digit(tmp[23], 86, 21);

        var_alarm = get_alarm_record();
        //if(flag_alarm)
          //  flag_alarm=0;
        for(k=1;k<=var_alarm; k++)
        {
            if(s[0]==p[k].s[0] && s[1]==p[k].s[1] && s[3]==p[k].s[3] && s[4]==p[k].s[4] && s[6]==p[k].s[6] && s[7]==p[k].s[7])
            {
                flag_alarm=1;
                break;
            }
        }

        if(flag_alarm)
        {
            Beep(750, 100);
            gotoxy(10, 15);
                printf("Alarm time!!!"); /// beep sound

            flag_alarm++;
            if(flag_alarm==10)
            {
                flag_alarm=0;
                gotoxy(10, 15);
                    printf("             ");
            }
        }

                                                // H 1

        if(s[0]!=ch0)
        {
            ch0=s[0];
            x=15;
            y=10;

            if(ch0=='0')
                zero(x, y);
            else if(ch0=='1')
                one(x, y);
            else if(ch0=='2')
                two(x, y);
        }
                                                    //   H  2
        if(s[1]!=ch1)
        {
            ch1 = s[1];
            x=19;
            y=10;

            print_digit(ch1, x, y);
        }
                                                          //   :
        if(cnt%2)
            s[2]=' ';

        if(s[2]==':')
        {
            x=23;
            y=10;

            colon(x, y);
        }

        if(s[2]==' ')
        {
            x=23;
            y=10;

            blink(x, y);
        }
                                                          //   M  1
        if(s[3]!=ch3)
        {
            ch3 = s[3];
            x=26;
            y=10;

            print_digit(ch3, x, y);
        }
                                                        //  M 2
        if(s[4]!=ch4)
        {
            ch4 = s[4];
            x=30;
            y=10;

            print_digit(ch4, x, y);
        }

                                                        //   :
        if(cnt%2)
            s[5]=' ';

        if(s[5]==':')
        {
            x=34;
            y=10;

            colon(x, y);
        }

        if(s[5]==' ')
        {
            x=34;
            y=10;

            blink(x, y);
        }
                                                             //  S  1
        if(s[6]!=ch6)
        {
            ch6 = s[6];
            x=37;
            y=10;

            print_digit(ch6, x, y);
        }
                                                            // S   2

        if(s[7]!=ch7)
        {
            ch7 = s[7];
            x=41;
            y=10;

            print_digit(ch7, x, y);
        }

        time(&t);
        strcpy(tmp,ctime(&t));
        for(i=0; i<8; i++)
        {
            s[i]=tmp[i+11];
        }

        /// to return to main menu

        gotoxy(15, 25);
        printf("Press Escape(Esc) to go to main menu: ");
        int it=0;
        while(1)
        {
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                system("CLS");
                return_input=1;
                menu();
                Sleep(200);
            }
            if(it>20000000)
                break;
            it++;
        }
    }
}

/// /// /// /// /// /// ///  A L A R M

int get_alarm_record()
{
    int i, n;
    char t[10];
    FILE *fp = fopen("alarm.txt", "r");

    if(fp==0)
    {
        //printf("You haven't yet saved any alarm.");
        fp = fopen("alarm.txt", "w");
        fprintf(fp,"0");
    }

    fscanf(fp,"%d", &n);

    for(i=1; i<=n; i++)
    {
        fscanf(fp," %s", t);
        strcpy(p[i].s, t);
        p[i].pos=i;
    }

    fclose(fp);

    return n;
}

void next_from_alarm(int x_pos, int m)
{
    gotoxy(x_pos, m);
        printf("Press Escape(Esc) to go to the main menu");
    gotoxy(x_pos, m+1);
        printf("Press Back(Backspace) to go to the Alarm menu");
    gotoxy(x_pos, m+2);

    while(1)
    {
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            system("CLS");
            return_input=1;
            menu();
        }
        else if(GetAsyncKeyState(VK_BACK))
        {
            system("CLS");
            alarm();
        }
    }
}

void show_alarm_record(int f)
{
    return_input = 1;
    int i=0, n, m;
    char y;
    system("CLS");
    n = get_alarm_record();

    box_no_gap(45, 5, 30, n+2);

    for(i=45; i<=75; i++)
    {
        gotoxy(i, 4);
        if(i<=55)
            printf("%c", 175);
        if(i>=65)
            printf("%c", 174);
        if(i==57)
            printf("Alarms");
    }
    if(n==0)
    {
        gotoxy(50, 6);
        printf("There's no alarm.");
    }
    for(i=1; i<=n; i++)
    {
        gotoxy(50, i+5);
            printf("%d %s\n", p[i].pos, p[i].s);
    }
    if(f)
    {
        next_from_alarm( 45, i+7);
    }
}

int valid2(char ch, int pos)
{
    if(pos==2 || pos ==5 )
    {
        if(ch!=':')
            return 0;
    }
    if(pos!=2 && pos!=5)
    {
        if(ch<'0')
            return 0;
    }
    if(pos==0  && ch>'2')
        return 0;
    if(pos==1 && ch>'9') ///
        return 0;
    if(pos==3 || pos==6)
    {
        if(ch>'5')
            return 0;
    }
    if(pos==4 || pos==7)
    {
        if(ch>'9')
            return 0;
    }
    return 1;
}

void set_alarm_record()
{
    int i, n, flag, m, f=0;
    n = get_alarm_record();
    show_alarm_record(f);
    gotoxy(10, n+10);
        printf("Set a new alarm: [Format: HH:MM:SS]");
    gotoxy(10, n+11);
        printf("*Input must be of 24 hour format.");
    box_no_gap(45, n+9, 15, 2);
    gotoxy(47, n+10);
        scanf("%s", p[n+1].s);

    flag=1;
    while(flag)
    {
        flag=0;
        if(p[n+1].s[0]=='2' && (p[n+1].s[0]<'0' || p[n+1].s[0]>'3') )
            flag=1;
        for(int i=0; i<8; i++)
        {
            if( valid2(p[n+1].s[i], i) == 0 )
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            gotoxy(47, n+10);
                printf("         ");
            gotoxy(67, n+10);
                printf("Invalid format.");
            gotoxy(47, n+10);
                scanf("%s", p[n+1].s);
        }
    }
    gotoxy(67, n+10);
            printf("                ");
    gotoxy(67, n+10);
        printf("New Alarm has been set");
    FILE *fp = fopen("alarm.txt", "w");
    n++;
    fprintf(fp,"%d\n", n);
    for(i=1; i<=n; i++)
        fprintf(fp,"%s\n", p[i].s);
    fclose(fp);

    next_from_alarm(45, n+12);
}

void delete_alarm_record()
{
    int t, n, i, f=0;
    n = get_alarm_record();
    show_alarm_record(f);
    if(n==0)
        return;
    gotoxy(45, n+8);
        printf("Delete an alarm: (Choose one from the list)");
    box_no_gap(45, n+10, 30, 2);
    gotoxy(47, n+11);
        printf("Your chosen option: ");
        scanf("%d", &t);
    while(t<1 || t>n)
    {
        gotoxy(85, n+11);
            printf("Invalid option");
        gotoxy(47, n+11);
            printf("                     ");
        gotoxy(47, n+11);
            printf("Your chosen option: ");
            scanf("%d", &t);
    }
    FILE *fp = fopen("alarm.txt", "w");
    fprintf(fp, "%d\n", n-1); //
    for(i=1; i<=n; i++)
    {
        if(i!=t)
        {
            if(i!=n)
                fprintf(fp,"%s\n", p[i].s);
            else
                fprintf(fp, "%s", p[i].s);
        }
    }
    fclose(fp);

    gotoxy(45, n+14);
        printf("Alarm no. %d has been deleted.", t);

    next_from_alarm(45, n+16);
}

void delete_all()
{
    FILE *fp = fopen("alarm.txt", "w");
    fprintf(fp,"0");
    fclose(fp);
    gotoxy(40, 8);
        printf("All alarms have been deleted.");
    next_from_alarm(40, 10);
}

int alarm()
{
    //loading();
    system("COLOR 3F");
    int t, i;
    box_no_gap(35, 5, 40, 6);
    for(i=35; i<=75; i++)
    {
        gotoxy(i, 4);
        if(i<49)
            printf("%c", 175);
        if(i>60)
            printf("%c", 174);
        if(i==50)
            printf("Alarm Menu");
    }
    gotoxy(36, 6);
        printf("1 Show previous Alarms.");
    gotoxy(36, 7);
        printf("2 Set a new Alarm.");
    gotoxy(36, 8);
        printf("3 Delete an Alarm");
    gotoxy(36, 9);
        printf("4 Delete all Alarms.");
    gotoxy(36, 10);
        printf("0 Return to the main menu.");

    box_no_gap(35, 12, 30, 2);
    gotoxy(40, 13);
        printf("Your chosen option is: ");
        scanf("%d", &t);
    if(t<0 || t>4)
    {
        gotoxy(75, 13);
            printf("Invalid input.");
        gotoxy(63, 13);
            printf("  ");
        gotoxy(40, 13);
            printf("Your chosen option is: ");
            scanf("%d", &t);
    }
    system("CLS");
    if(t==1)
        show_alarm_record(1);
    if(t==2)
        set_alarm_record();
    if(t==3)
        delete_alarm_record();
    if(t==4)
        delete_all();
    if(!t)
        menu();
}


/// /// /// /// /// /// ///  T I M E R

int valid(char ch, int pos)
{
    if(pos==0 || pos==1 || pos==3 || pos==4 || pos==6 || pos==7)
    {
        if(ch>='0'&&ch<='9')
            return 1;
    }
    return 0;
}

int timer()
{
    int i, x, y, cnt, flag;
    char s[9], ch0, ch1, ch3, ch4, ch6, ch7, format;

    system("CLS");

    box_no_gap(34, 5, 40, 11);
    gotoxy(35, 3);
        printf("Select an option to start the timer");
    gotoxy(35, 6);
        printf("0 : To set the timer manually");
    gotoxy(35, 7);
        printf("1 : 5 seconds");
    gotoxy(35, 8);
        printf("2 : 10 seconds");
    gotoxy(35, 9);
        printf("3 : 30 seconds");
    gotoxy(35, 10);
        printf("4 : 1 minute");
    gotoxy(35, 11);
        printf("5 : 5 minutes");
    gotoxy(35, 12);
        printf("6 : 10 minutes");
    gotoxy(35, 13);
        printf("7 : 30 minutes");
    gotoxy(35, 14);
        printf("8 : 1 hour");
    gotoxy(35, 15);
        printf("9 : 100 minutes/ 1 hour & 40 minutes");

    box_no_gap(40, 17, 30, 2);
    gotoxy(42, 18);
        printf("Choose your option: ");
    gotoxy(63, 18);
        scanf(" %c", &format);

    while(format<'0' || format>'9')
    {
        gotoxy(42, 18);
            printf("                   ");
        gotoxy(42, 18);
            printf("Choose your option: ");
        gotoxy(63, 18);
            scanf(" %c", &format);
    }

    system("CLS");
    if(format=='0')
    {
        gotoxy(30, 10);
            printf("Please enter the time for countdown in this format: ");
        gotoxy(30, 13);
            printf("HH:MM:SS");
        box_no_gap(40, 12, 10, 2);
            gotoxy(41, 13);
            scanf(" %c%c:%c%c:%c%c", &s[0], &s[1], &s[3], &s[4], &s[6], &s[7]);

        flag=1;
        while(flag)
        {
            flag=0;
            for(int i=0; i<8; i++)
            {
                if( (i!=2 && i!=5) && !valid(s[i], i))
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                gotoxy(55, 13);
                    printf("Invalid format.");
                gotoxy(41, 13);
                    printf("         ");
                gotoxy(41, 13);
                    scanf(" %c%c:%c%c:%c%c", &s[0], &s[1], &s[3], &s[4], &s[6], &s[7]);
            }
        }
        system("CLS");
    }

    s[2]=':';
    s[5]=':';

    if(format=='1') // 5s
    {
        s[0]='0';
        s[1]='0';

        s[3]='0';
        s[4]='0';

        s[6]='0';
        s[7]='5';
    }
    if(format=='2') // 10s
    {
        s[0]='0';
        s[1]='0';

        s[3]='0';
        s[4]='0';

        s[6]='1';
        s[7]='0';
    }
    if(format=='3') // 30s
    {
        s[0]='0';
        s[1]='0';

        s[3]='0';
        s[4]='0';

        s[6]='3';
        s[7]='0';
    }
    if(format=='4') // 1m
    {
        s[0]='0';
        s[1]='0';

        s[3]='0';
        s[4]='1';

        s[6]='0';
        s[7]='0';
    }
    if(format=='5') // 5m
    {
        s[0]='0';
        s[1]='0';

        s[3]='0';
        s[4]='5';

        s[6]='0';
        s[7]='0';
    }
    if(format=='6') // 10m
    {
        s[0]='0';
        s[1]='0';

        s[3]='1';
        s[4]='0';

        s[6]='0';
        s[7]='0';
    }
    if(format=='7') // 30m
    {
        s[0]='0';
        s[1]='0';

        s[3]='3';
        s[4]='0';

        s[6]='0';
        s[7]='0';
    }
    if(format=='8') // 1h
    {
        s[0]='0';
        s[1]='1';

        s[3]='0';
        s[4]='0';

        s[6]='0';
        s[7]='0';
    }
    if(format=='9') // 100m
    {
        s[0]='0';
        s[1]='1';

        s[3]='4';
        s[4]='0';

        s[6]='0';
        s[7]='0';
    }
    loading();

    system("COLOR 8F");
    system("CLS");

    hidecursor();

    for(int i=13; i<=45; i++)
    {
        gotoxy(i, 8);
        if(i<=24)
            printf("%c", 175);
        else if(i>=33)
            printf("%c", 174);
        if(i==26)
            printf("Timer");
    }

    ch0=ch1=ch3=ch4=ch6=ch7='a';

    cnt=1;
    if(cnt==1)
        box();
    while(cnt++)
    {
        s[2]=s[5]=':';
                                               // H 1
        if(s[0]!=ch0)
        {
            ch0=s[0];
            x=15;
            y=10;

            print_digit(ch0, x, y);
        }
                                                   //   H  2

        if(s[1]!=ch1)
        {
            ch1 = s[1];
            x=19;
            y=10;

            print_digit(ch1, x, y);
        }

                                                          //   :
        if(cnt%2)
            s[2]=' ';

        if(s[2]==':')
        {
            x=23;
            y=10;

            colon(x, y);
        }

        if(s[2]==' ')
        {
            x=23;
            y=10;

            blink(x, y);
        }
                                                      //   M  1

        if(s[3]!=ch3)
        {
            ch3 = s[3];
            x=26;
            y=10;

            print_digit(ch3, x, y);
        }
                                                        //  M 2

        if(s[4]!=ch4)
        {
            ch4 = s[4];
            x=30;
            y=10;

            print_digit(ch4, x, y);
        }

                                                        //   :
        if(cnt%2)
            s[5]=' ';

        if(s[5]==':')
        {
            x=34;
            y=10;

            colon(x, y);
        }

        if(s[5]==' ')
        {
            x=34;
            y=10;

            blink(x, y);
        }

                                                             //  S  1

        if(s[6]!=ch6)
        {
            ch6 = s[6];
            x=37;
            y=10;

            print_digit(ch6, x, y);
        }

                                                             /// S   2

        if(s[7]!=ch7)
        {
            ch7 = s[7];
            x=41;
            y=10;

            print_digit(ch7, x, y);
        }

        if(s[0]=='0' && s[1]=='0' && s[3]=='0' && s[4]=='0' && s[6]=='0' && s[7]=='0')   /// 00:00:00
        {
            gotoxy(10, 18);
            printf("                                      ");

            gotoxy(55, 10);
                printf("Time's up!!!\n\n");
            gotoxy(55, 12);
                printf("Main menu will be displayed after 5 seconds.");
            gotoxy(55, 13);
                printf("Please wait.");
            sleep(5); // Sleep(5);

            fflush(stdout);
            return_input=1;
            menu();
            //break;
        }

        if(s[7]!='0')
            s[7]--;
        else
        {
            s[7]='9';
            if(s[6]!='0')
                s[6]--;
            else
            {
                s[6]='5';
                if(s[4]!='0')
                    s[4]--;
                else
                {
                    s[4]='9';
                    if(s[3]!='0')
                        s[3]--;
                    else
                    {
                        s[3]='5';
                        if(s[1]!='0')
                            s[1]--;
                        else
                        {
                            s[1]='9';
                            if(s[0]!='0')
                                s[0]--;
                            else
                                continue;
                         }
                     }
                 }
             }
         }
         /// to return to main menu

        gotoxy(10, 18);
        printf("Press Escape(Esc) to go to main menu: ");
        int it=0;
        while(1)
        {
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                system("CLS");
                return_input=1;
                menu();
                Sleep(200);
            }
            if(it>20000000)
                break;
            it++;
        }
    }
}


/// /// /// /// /// /// /// ///             S T O P W A T C H

int stopwatch()
{
    int i, x, y, cnt, lap=0, r=0;
    char s[9], ch0, ch1, ch3, ch4, ch6, ch7;

    system("CLS");

    //if(!lap)
      //  loading();

    system("COLOR 9F");
    system("CLS");

    hidecursor();

    s[0]=s[1]=s[3]=s[4]=s[6]=s[7]='0';
    s[2]=s[5]=':';

    ch0=ch1=ch3=ch4=ch6=ch7='a';

    for(int i=13; i<=45; i++)
    {
        gotoxy(i, 8);
        if(i<=21)
            printf("%c", 175);
        else if(i>=36)
            printf("%c", 174);
        if(i==25)
            printf("Stop Watch");
    }

    cnt=1;
    if(cnt==1)
        box();
    while(cnt++)
    {
                                               // H 1
        if(s[0]!=ch0)
        {
            ch0=s[0];
            x=15;
            y=10;

            print_digit(ch0, x, y);
        }
                                                    //   H  2
        if(s[1]!=ch1)
        {
            ch1 = s[1];
            x=19;
            y=10;

            print_digit(ch1, x, y);
        }
                                                          //   :
        if(cnt%2)
            s[2]=' ';

        if(s[2]==':')
        {
            x=23;
            y=10;

            colon(x, y);
        }

        if(s[2]==' ')
        {
            x=23;
            y=10;

            blink(x, y);
        }
                                                          //   M  1
        if(s[3]!=ch3)
        {
            ch3 = s[3];
            x=26;
            y=10;

            print_digit(ch3, x, y);
        }
                                                        //  M 2
        if(s[4]!=ch4)
        {
            ch4 = s[4];
            x=30;
            y=10;

            print_digit(ch4, x, y);
        }

                                                        //   :
        if(cnt%2)
            s[5]=' ';

        if(s[5]==':')
        {
            x=34;
            y=10;

            colon(x, y);
        }

        if(s[5]==' ')
        {
            x=34;
            y=10;

            blink(x, y);
        }
                                                             //  S  1
        if(s[6]!=ch6)
        {
            ch6 = s[6];
            x=37;
            y=10;

            print_digit(ch6, x, y);
        }
                                                            // S   2

        if(s[7]!=ch7)
        {
            ch7 = s[7];
            x=41;
            y=10;

            print_digit(ch7, x, y);
        }

        if(s[0]=='9'&&s[1]=='9' && s[3]=='5'&&s[4]=='9' && s[6]=='5'&&s[7]=='9')
        {
            gotoxy(13, 16);
            printf("It has been 100 hours!!!\n\n");
            fflush(stdout);
            break;
        }

        if(s[7]!='9')
            s[7]++;
        else
        {
            s[7]='0';
            if(s[6]!='5')
                s[6]++;
            else
            {
                s[6]='0';
                if(s[4]!='9')
                    s[4]++;
                else
                {
                    s[4]='0';
                    if(s[3]!='5')
                        s[3]++;
                    else
                    {
                        s[3]='0';
                        if(s[1]!='9')
                            s[1]++;
                        else
                        {
                            s[1]='0';
                            if(s[0]!='9')
                                s[0]++;
                            else
                                continue;
                        }
                    }
                }
            }
        }

        s[2]=s[5]=':';

        /// to return to main menu

        if(!r)
        {
            gotoxy(10, 16);
                printf("Press Tab to pause the stopwatch ");
        }

        gotoxy(10, 18);
            printf("Press Back(Backspace) to restart the stopwatch from zero");

        gotoxy(10, 20);
            printf("Press Space to elapse time to current point ");

        gotoxy(10, 22);
            printf("Press Escape(Esc) to go to the main menu ");

        int it=0;
        while(1)
        {
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                system("CLS");
                return_input=1;
                menu();
                //Sleep(200);
            }
            if(it>10000000)
                break;
            it++;
        }

        //it=0;
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                lap++;
                if(lap<=10)
                {
                    gotoxy(80, 8+lap*2);
                        printf("Lap %d : %s", lap, s);
                }
                else
                {
                    gotoxy(100, 8+(lap-10)*2);
                        printf("Lap %d : %c%c:%c%c:%c%c", lap, s[0], s[1], s[3], s[4], s[6], s[7]);
                }
            }
            if(it>10000000)
                break;
            it++;
        }

        //it=0;
        while(1)
        {
            if(GetAsyncKeyState(VK_BACK))
            {
                stopwatch();
            }
            if(it>10000000)
                break;
            it++;
        }

        while(r==0)
        {
            if(GetAsyncKeyState(VK_TAB))
            {
                r=1;
                gotoxy(10, 16);
                    printf("                                        ");
                gotoxy(10, 16);
                    printf("Press Tab to resume the stopwatch");
            }
            if(it>10000000)
                break;
            it++;
        }

        //it=0;
        while(r==1)
        {
            if(GetAsyncKeyState(VK_TAB))
            {
                r=0;
                gotoxy(10, 16);
                    printf("                                        ");
                gotoxy(10, 16);
                    printf("Press Tab to pause the stopwatch");
                break;
            }
            //it++;
        }

    }
}

void intro_myself()
{
    hidecursor();
    gotoxy(30, 5);
        printf("Name: MOHAMMAD ARIFUL ISLAM");
    gotoxy(30, 6);
        printf("Institution: INTERNATIONAL ISLAMIC UNIVERSITY CHITTAGONG(IIUC)");
    gotoxy(30, 7);
        printf("Session: 2020-2021, 1st Year");
    gotoxy(30, 8);
        printf("Department: Computer Science and Engineering(CSE)");
    //system("PAUSE");
    sleep(5);
    system("CLS");
    intro_project_name();
}

void intro_project_name()
{
    int j, il=25, m=15;

    for(j=0; j<=4; j++)
    {
        letter_P(10+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(10+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_R(14+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(14+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_O(18+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(18+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_J(22+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(22+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_E(25+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(25+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_C(29+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(29+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_T(32+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(32+m, j);
            printf("    ");
        }
    }

    for(j=0; j<=4; j++)
    {
        letter_N(40+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(40+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_A(44+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(44+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_M(48+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(48+m, j);
            printf("   ");
        }
    }
    for(j=0; j<=4; j++)
    {
        letter_E(52+m, j);
        Sleep(il);
        if(j<4)
        {
            gotoxy(52+m, j);
            printf("   ");
        }
    }

    box_no_gap(35, 8, 30, 15);
    letter_D(40, 10);
    letter_I(43, 11);
    letter_G(46, 12);
    letter_I(50, 13);
    letter_T(52, 14);
    letter_A(56, 15);
    letter_L(60, 16);

    letter_C(40, 15);
    letter_L(44, 16);
    letter_O(48, 17);
    letter_C(52, 18);
    letter_K(55, 19);

    sleep(5);
}

void description()
{
    system("CLS");

    box_no_gap(10, 5, 100, 26);

    for(int i=10; i<=110; i++)
    {
        gotoxy(i, 4);
        if(i<=55)
            printf("%c", 175);
        else if(i>65)
            printf("%c", 174);
        if(i==57)
            printf("Features");
    }

    gotoxy(11, 6);
        printf("Basically this is a console based application built up using C programming language.");
    gotoxy(11, 7);
        printf("The functions of this application are similar to the digital clock functions.");
    gotoxy(11, 9);
        printf("This application is of 4 major portions: ");
    gotoxy(12, 11);
        printf("1. Current Time: In this option, the user can select a region of which he wants to know");
    gotoxy(15, 12);
        printf("the current time of.");
    gotoxy(15, 13);
        printf("All the regions i.e., the components of the world are included here.");
    gotoxy(15, 14);
        printf("After selecting a region, the user is needed to choose a country of that region.");
    gotoxy(15, 15);
        printf("Almost 200 countries are added here.");
    gotoxy(12, 17);
        printf("2. Timer: It's nothing but the countdown process.");
    gotoxy(15, 18);
        printf("The user can either manually set the timer or select an option from the given list.");
    gotoxy(12, 20);
        printf("3. Stopwatch: Here, the user can start elapsing time from zero and lap for multiple times."); // max size
    gotoxy(12, 22);
        printf("4. Alarm: There are 4 sub-portions within this part:");
    gotoxy(17, 23);
        printf("i) to show the alarms that are set currently(if there's any).");
    gotoxy(17, 24);
        printf("ii) to set a new alarm.");
    gotoxy(17, 25);
        printf("iii) to delete a specific alarm.");
    gotoxy(17, 26);
        printf("iv) to delete all of the alarms at a time i.e., to clear the alarms.");
    gotoxy(15, 27);
        printf("Most interesting part of this portion is that the alarms will be set up for the user's curent");
    gotoxy(15, 28);
        printf("location's time but will function for any other region across the world.");
    gotoxy(15, 29);
        printf("The user will be able to hear a beeping sound for 10 seconds starting right at the alarm time");
    gotoxy(15, 30);
        printf("while viewing the current time of a country.");

    gotoxy(10, 32);
        printf("Press Escape(Esc) to go to the main menu");
    while(1)
    {
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            system("CLS");
            return_input=1;
            menu();
        }
    }

}

/*
 __
|  |
|__|
*/

void zero(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

 /*
     |
     |
*/

void one(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("  | ");
        if(i==2)
            printf("  | ");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*
 __
 __|
|__
*/

void two(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf(" __|");
        if(i==2)
            printf("|__ ");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*
 __
 __|
 __|
*/

void three(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf(" __|");
        if(i==2)
            printf(" __|");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*

|__|
   |
*/

void four(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("   |");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*
 __
|__
 __|
*/

void five(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf(" __|");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*
 __
|__
|__|
*/

void six(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*
 __
   |
   |
*/

void seven(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("   |");
        if(i==2)
            printf("   |");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*
 __
|__|
|__|
*/

void eight(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);
}

/*
 __
|__|
   |
*/

void nine(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("   |");

        fflush(stdout);
    }
    if(x==41)
        Sleep(800);//sleep(pause_time);

}

/*

 .
 .
*/

 void colon(int x, int y)
 {
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);
        if(i==0)
            printf("   ");
        if(i==1)
            printf(" . ");
        if(i==2)
            printf(" . ");

        fflush(stdout);
    }
 }

 /// for blinking: blank spaces to replace colon

 void blink(int x, int y)
 {
     int i;
     for(i=0; i<3; i++)
     {
         gotoxy( x, y+i);
         if(i==0)
            printf("   ");
         if(i==1)
            printf("   ");
         if(i==2)
            printf("   ");

         fflush(stdout);
     }
 }

/// /// /// letters

/*
 __
|__|
|  |
*/

void letter_A(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|  |");

        fflush(stdout);
    }
}

/*
 __
|__
 __|
*/

void letter_S(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf(" __|");

        fflush(stdout);
    }
}

/*
 ___
  |
  |
*/

void letter_T(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" ___");
        if(i==1)
            printf("  | ");
        if(i==2)
            printf("  | ");

        fflush(stdout);
    }
}

/*

|  |
|__|
*/

void letter_U(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
}

/*
|\ |
| \|
*/

void letter_N(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|\\ |");
        if(i==2)
            printf("| \\|");

        fflush(stdout);
    }
}

/*
|\/|
|  |
*/

void letter_M(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|\\/|");
        if(i==2)
            printf("|  |");

        fflush(stdout);
    }
}

/*
 __
|  |
|__|
*/

void letter_O(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
}

/*
 __
|__
|__
*/

void letter_E(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf("|__");

        fflush(stdout);
    }
}

/*
|   |
|//\|
*/

void letter_W(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|/\\|");

        fflush(stdout);
    }
}

/*
 __
|  |
|__|
*/

void letter_D(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" _  ");
        if(i==1)
            printf("| \\");
        if(i==2)
            printf("|_/");

        fflush(stdout);
    }
}

/*
|__|
|  |
*/

void letter_H(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|  |");

        fflush(stdout);
    }
}

/*
 __
|_
|
*/

void letter_F(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|_  ");
        if(i==2)
            printf("|   ");

        fflush(stdout);
    }
}


/*
 __
|__|
|  \
*/

void letter_R(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|  \\");

        fflush(stdout);
    }
}

/*
  |
  |
*/

void letter_I(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" ");
        if(i==1)
            printf(" |");
        if(i==2)
            printf(" |");

        fflush(stdout);
    }
}

/*
  |
__|
*/

void letter_J(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("   ");
        if(i==1)
            printf("  |");
        if(i==2)
            printf("__|");

        fflush(stdout);
    }
}

/*
 __
|__)
|__)
*/

void letter_B(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__)");
        if(i==2)
            printf("|__)");

        fflush(stdout);
    }
}

/*
 __
|__)
|
*/

void letter_P(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__)");
        if(i==2)
            printf("|   ");

        fflush(stdout);
    }
}

/*

 \ /
  |
*/

void letter_Y(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("\\ /");
        if(i==2)
            printf(" |  ");

        fflush(stdout);
    }
}

/*

|
|__
*/

void letter_L(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("   ");
        if(i==1)
            printf("|  ");
        if(i==2)
            printf("|__");

        fflush(stdout);
    }
}

/*
 __
| _
|__|
*/

void letter_G(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("| _ ");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
}

/*
 __
|
|__
*/

void letter_C(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|   ");
        if(i==2)
            printf("|__ ");

        fflush(stdout);
    }
}

/*

\  /
 \/

*/

void letter_V(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("\\  /");
        if(i==2)
            printf(" \\/ ");

        fflush(stdout);
    }
}
/*

 \/
 /\
*/

void letter_X(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf(" \\/");
        if(i==2)
            printf(" /\\");

        fflush(stdout);
    }
}

/*
 __
|  |
|__¬
*/

void letter_Q(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("| _|");
        if(i==2)
            printf("|__%c", 191);

        fflush(stdout);
    }
}

/*

|/
|\\
*/

void letter_K(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("   ");
        if(i==1)
            printf(" |/");
        if(i==2)
            printf(" |\\");

        fflush(stdout);
    }
}

/*
 __
  /
 /_
*/
void letter_Z(int x, int y)
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("  / ");
        if(i==2)
            printf(" /_");

        fflush(stdout);
    }
    printf("\n");
}
