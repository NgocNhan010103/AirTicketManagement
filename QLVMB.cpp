#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;


struct DATE
{
    int d,m,y;
};

struct HOUR
{
    int hour,minute,second;
};


void STANDARDNAME(string &fullname)
{
	while (fullname[0] == ' ')
		fullname.erase(0, 1); 
	while (fullname[fullname.length() - 1] == ' ')
		fullname.pop_back(); 
	int i = 0;
	while (i < fullname.length() - 1)
	{
		if (fullname[i] == ' '&&fullname[i + 1] == ' ')
		{
			fullname.erase(i, 1);
			i--;
		}
		i++;
	}
	int l = fullname.length();
	strlwr((char*)fullname.c_str());
	fullname[0] = fullname[0] - 32;
	for (int i = 0; i < l-1;i++)
	if (fullname[i]==' '&& fullname[i+1]!=' ')
		fullname[i+1] = fullname[i+1] - 32;
};

class Trip
{
    protected:
        string departure;
        DATE time;
        HOUR hours;
        string type;
        string pos;
        double price;
    public:
        Trip(){}

        Trip(string departure,DATE time,HOUR hours, string type,string pos, double price):
        departure(departure),time(time),hours(hours),type(type),pos(pos),price(price){}

        ~Trip(){}

        void OutTrip()
        {
            cout << "\033[1m" ;
            cout << "                                                   INFORMATION ABOUT YOUR FLIGHT" << endl;
            cout << "+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+" << endl;
            cout << "|          Trip           |       Time of trip      |      Departure time     |       Ticket type       |      Seat position      |           Price         |" << endl;
            cout << "+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+" << endl;
            cout << "| "<< setw(24) << left << departure << "| " << right << setfill('0') << setw(2) << time.d << "/" << right << setfill('0') << setw(2) << time.m << "/" << setw(4) << left << time.y << "              | " << right << setfill('0') << setw(2) << hours.hour << ":" << right << setfill('0') << setw(2)<< hours.minute << ":" << right << setfill('0') << setw(2) << hours.second << "                | " << setw(24) << setfill(' ') << left << type << "| " << setw(24) << left << pos << "| " << setw(3) << left << price << setw(21) << left << "$" << "|" << endl;
            cout << "+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+" << endl;
            cout << "\033[0m" << endl;
        }

        void setdeparture(string value1)
        {
            this-> departure = value1;
        }

        void settime(int d,int m,int y)
        {
            this -> time.d = d;
            this -> time.m = m;
            this -> time.y = y;
        }

        void sethours(HOUR hours)
        {
            this -> hours = hours;
        }

        void settype(string value2)
        {
            this -> type = value2;
        }

        void setpos(string value3)
        {
            this -> pos = value3;
        }

        void setprice(double value4)
        {
            this -> price = value4;
        }

        string getdeparture()
        {
            return departure;
        }

        DATE gettime()
        {
            return time;
        }

        HOUR gethours()
        {
            return hours;
        }

        string gettype()
        {
            return type;
        }

        string getpos()
        {
            return pos;
        }

        double getprice()
        {
            return price;
        }

};

int n =10;
Trip *trips = new Trip[10];


class FlightTickets:public Trip
{
    protected:
        string flightname;
        DATE flightdate;
        double priceticket;
    public:
        FlightTickets(){}

        ~FlightTickets(){}

        void setflightname()
        {
            this -> flightname = getdeparture();
        }

        void setpriceticket()
        {
            this-> priceticket = getprice();
        }

        void setflightdate()
        {
            this -> flightdate = gettime();
        }

        void OutputFlight()
        {
            cout << "Flight Name: " << flightname << endl;
            cout << "Date: " << flightdate.d << "/" << flightdate.m << "/" << flightdate.y << endl;
            cout << "Price Ticket: " << priceticket << endl;
        }

        double getgiave()
        {
            return priceticket;
        }

};

class User:public FlightTickets
{
    protected:
        string fullname;
        string sex;
        int age;
        string phone;
        string email;
        string username;
        string password;
    public:
        User(){}

        ~User(){}


        void setUsername() {
            this->username = username;
        }

        void setPassword() {
            this -> password = password;
        }

        void Info()
        {
            cout << "Enter fullname: ";
            getline(cin, fullname);
            STANDARDNAME(fullname);

            cout << "Enter sex: ";
            getline(cin, sex);

            cout << "Enter age: ";
            cin >> age;

            cout << "Enter phone: ";
            cin.ignore(); // loại bỏ kí tự '\n' còn lại trong bộ nhớ đệm
            getline(cin, phone);

            cout << "Enter email: ";
            getline(cin, email);
        }

        void setFullname() {
            this->fullname = fullname;
        }
        
        string getfullname()
        {
            return fullname;
        }

        void setSex() {
            this->sex = sex;
        }

        string getsex()
        {
            return sex;
        }

        void setAge() {
            this->age = age;
        }

        int getage()
        {
            return age;
        }

        void setPhone() {
            this->phone = phone;
        }

        string getphone()
        {
            return phone;
        }

        void setEmail() {
            this->email = email;
        }

        string getemail()
        {
            return email;
        }
};

class Administrator:public User
{
    private:
        string usernamead;
        string passwordad;
    public:
        Administrator()
        {
            usernamead = "123";
            passwordad = "123";
        }

        ~Administrator(){}

        bool Loginad()
        {
            do
            {
                cout << "Username: " ;
                cin >> username;
            } 
            while (this->username != usernamead);

            do
            {
                cout << "Password: " ;
                cin >> password;
            }
            while(this->password != passwordad);

            cout << "Successfully logged in with administrator account !" << endl;
        }

};

class Client:public User
{
    private:
        string usernameclient;
        string passwordclient;
        
    public:
        Client(){}

        ~Client(){}

        void Register();

        void Login();

        void setusernameclient(string value)
        {
            this -> usernameclient = value;
        }

        void setpasswordclient(string value1)
        {
            this -> passwordclient = value1;
        }

        string getusernameclient() 
        {
            return usernameclient;
        }

        string getpasswordclient()
        {
            return passwordclient;
        }

};

Client *clients = new Client[10];
int countarr = 0;
int countar = 0;
int thu = 0;

class Passenger: public Client
{
    private:
        FlightTickets *ve;
        int quantity;
        double pay;
    public:
        Passenger(){}

        ~Passenger(){}

        void Inquantity()
        {
            cout << "CHOOSE THE NUMBER OF TICKETS: ";
            cin >> quantity;
        }

        void InputPay()
        {
            cout << "Enter the amount to pay: " ;
            cin >> pay;
        }

        int getquantity()
        {
            return quantity;
        }

        double getpay()
        {
            return pay;
        }

        bool Banking()
        {
            if (pay >= getprice())
                return true;
            return false;
        }

        double TotalMoney()
        {
            return trips[thu].getprice()*quantity;
            thu++;
        }

        void InfoOut()
        {                 
            cout << "\033[1m" ;
            cout << "+-------------------------+---------+---------+------------------+-------------------------+----------------------+" << endl;
            cout << "| "<< setw(24) << left << fullname << "| "<< setw(8) << left << sex << "| " << setw(8) << left << age << "| "<< setw(17) << left << phone << "| "<< setw(24) << left << email << "| " << setw(21) << left << TotalMoney() << "|"<< endl;
            cout << "+-------------------------+---------+---------+------------------+-------------------------+----------------------+" << endl;
            cout << "\033[0m" << endl; 
        }
};

Passenger *passenger = new Passenger[10];

void Ticketondemand()
{
    int i = 0;
    Administrator administrators;
    int chosse1;
    string departure[] = {"Ha Noi", "Quang Ngai", "Da Nang", "Nha Trang", "Vung Tau", "Vinh Ha Long", "Hai Phong", "Con Dao", "Ninh Binh", "Sapa"};
    do
    {
        system("cls");
        cout << "                                       PLEASE CHOOSE A DESTINATION                                        " << endl;
        cout << "+--------------------+--------------------+--------------------+--------------------+--------------------+" << endl;
        cout << "|      1.Ha Noi      |    2.Quang Ngai    |      3.Da Nang     |     4.Nha Trang    |     5.Vung Tau     |" << endl;
        cout << "+--------------------+--------------------+--------------------+--------------------+--------------------+" << endl;
        cout << "|   6.Vinh Ha Long   |     7.Hai Phong    |      8.Con Dao     |     9.Ninh Binh    |       10.Sapa      |" << endl;
        cout << "+--------------------+--------------------+--------------------+--------------------+--------------------+" << endl;
        cout << "Please chosse a destination: ";
        cin >> chosse1;
        if (chosse1 >= 1 && chosse1 <= 10) 
        {
            trips[i].setdeparture(departure[chosse1 - 1]);
            int chosse2;
            do
            {
                system("cls");
                cout << "                                      PLEASE CHOOSE A DATE                                      " << endl;
                cout << "+------------------+------------------+------------------+------------------+------------------+" << endl;
                cout << "|    01/06/2023    |    02/06/2023    |    03/06/2023    |    04/06/2023    |    05/06/2023    |" << endl;
                cout << "+------------------+------------------+------------------+------------------+------------------+" << endl;
                cout << "|    06/06/2023    |    07/06/2023    |    08/06/2023    |    09/06/2023    |    10/06/2023    |" << endl;
                cout << "+------------------+------------------+------------------+------------------+------------------+" << endl;
                cout << "|    11/06/2023    |    12/06/2023    |    13/06/2023    |    14/06/2023    |    15/06/2023    |" << endl;
                cout << "+------------------+------------------+------------------+------------------+------------------+" << endl;
                cout << "|    16/06/2023    |    17/06/2023    |    18/06/2023    |    19/06/2023    |    20/06/2023    |" << endl;
                cout << "+------------------+------------------+------------------+------------------+------------------+" << endl;
                cout << "|    21/06/2023    |    22/06/2023    |    23/06/2023    |    24/06/2023    |    25/06/2023    |" << endl;
                cout << "+------------------+------------------+------------------+------------------+------------------+" << endl;
                cout << "|    26/06/2023    |    27/06/2023    |    28/06/2023    |    29/06/2023    |    30/06/2023    |" << endl;
                cout << "+------------------+------------------+------------------+------------------+------------------+" << endl;
                cout << "Please choose your departure date: ";
                cin >> chosse2;
                HOUR hours[] = {{8,30,0},{9,30,0},{10,30,0},{11,30,0},{12,30,0},{13,30,0},{14,30,0},{15,30,0},{16,30,0},{17,30,0},{18,30,0},{19,30,0},{20,30,0},{21,30,0},{22,30,0}};
                if (chosse2 >= 1 && chosse2 <= 30)
                {
                    trips[i].settime(chosse2, 6, 2023);
                    int chosse6;
                    do
                    {
                        system("cls");
                        cout << "                              DEPARTMENT TIMES                              " << endl;
                        cout << "+--------------+--------------+--------------+--------------+--------------+" << endl;
                        cout << "|   08:30:00   |   09:30:00   |   10:30:00   |   11:30:00   |   12:30:00   |" << endl;
                        cout << "|      1       |       2      |       3      |       4      |       5      |" << endl;
                        cout << "+--------------+--------------+--------------+--------------+--------------+" << endl;
                        cout << "|   13:30:00   |   14:30:00   |   15:30:00   |   16:30:00   |   17:30:00   |" << endl;
                        cout << "|      6       |       7      |       8      |       9      |      10      |" << endl;
                        cout << "+--------------+--------------+--------------+--------------+--------------+" << endl;
                        cout << "|   18:30:00   |   19:30:00   |   20:30:00   |   21:30:00   |   22:30:00   |" << endl;
                        cout << "|      11      |      12      |      13      |      14      |      15      |" << endl;
                        cout << "+--------------+--------------+--------------+--------------+--------------+" << endl;
                        cout << "Please chosse your departure time: ";
                        cin >> chosse6;
                        if (chosse6 >=1 && chosse6 <= 15)
                        {
                            trips[i].sethours(hours[chosse6 -1]);
                        int chosse3;
                    do
                    {
                        system("cls");
                        cout << "                                       TYPES OF TICKET                                        " << endl;
                        cout << "+------------------------------+------------------------------+------------------------------+" << endl;
                        cout << "|       1.Business class       |        2.Economy class       |    3.Premium economy class   |" << endl;
                        cout << "+------------------------------+------------------------------+------------------------------+" << endl;
                        cout << "|        4.Special fares       |        5.Low-cost fares      |       6.Companion fares      |" << endl;
                        cout << "+------------------------------+------------------------------+------------------------------+" << endl;
                        cout << "Choose the type of ticket you want: ";
                        cin >> chosse3;
                        string type[] = {"Business class", "Economy class", "Premium economy class", "Special fares", "Low-cost fares", "Companion fares"};
                        if (chosse3 >= 1 && chosse3 <= 6)
                            trips[i].settype(type[chosse3 - 1]);
                        string pos1[] = {"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E4","E5","E6","F1","F2","F3","F4","F5","F6"};
                        string pos2[] = {"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E4","E5","E6","F1","F2","F3","F4","F5","F6"};
                        string pos3[] = {"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E4","E5","E6","F1","F2","F3","F4","F5","F6"};
                        string pos4[] = {"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E4","E5","E6","F1","F2","F3","F4","F5","F6"};
                        string pos5[] = {"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E4","E5","E6","F1","F2","F3","F4","F5","F6"};
                        string pos6[] = {"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E4","E5","E6","F1","F2","F3","F4","F5","F6"};
                        int chosse4, chosse5;
                        if (chosse3 >=1 && chosse3 <=6) 
                        {
                            string* pos;
                            string seat_type;
                            switch (chosse3) 
                            {
                                case 1:pos = pos1;seat_type = "BUSINESS CLASS";break;
                                case 2:pos = pos2;seat_type = "FIRST CLASS";break;
                                case 3:pos = pos3;seat_type = "PREMIUM ECONOMY CLASS";break;
                                case 4:pos = pos4;seat_type = "SPECIAL FARES";break;
                                case 5:pos = pos5;seat_type = "LOW-COST FARES";break;
                                case 6:pos = pos6;seat_type = "COMPANION FARES";break;
                                default: break;
                            }
                            do 
                            {
                                system("cls");
                                cout << setw(28) << seat_type << endl;
                                cout << "+---------+---------+---------+-||  ||-+---------+---------+---------+" << endl;
                                cout << "|   1-" << pos[0] << "  |   2-" << pos[1] << "  |   3-" << pos[2] << "  |-||  ||-|   4-" << pos[3] << "  |   5-" << pos[4] << "  |   6-" << pos[5] << "  |" << endl;
                                cout << "+---------+---------+---------+-||  ||-+---------+---------+---------+" << endl;
                                cout << "|   7-" << pos[6] << "  |   8-" << pos[7] << "  |   9-" << pos[8] << "  |-||  ||-|  10-" << pos[9] << "  |  11-" << pos[10] << "  |  12-" << pos[11] << "  |" << endl;
                                cout << "+---------+---------+---------+-||  ||-+---------+---------+---------+" << endl;
                                cout << "|  13-" << pos[12] << "  |  14-" << pos[13] << "  |  15-" << pos[14] << "  |-||  ||-|  16-" << pos[15] << "  |  17-" << pos[16] << "  |  18-" << pos[17] << "  |" << endl;
                                cout << "+---------+---------+---------+-||  ||-+---------+---------+---------+" << endl;
                                cout << "|  19-" << pos[18] << "  |  20-" << pos[19] << "  |  21-" << pos[20] << "  |-||  ||-|  22-" << pos[21] << "  |  23-" << pos[22] << "  |  24-" << pos[23] << "  |" << endl;
                                cout << "+---------+---------+---------+-||  ||-+---------+---------+---------+" << endl;
                                cout << "|  25-" << pos[24] << "  |  26-" << pos[25] << "  |  27-" << pos[26] << "  |-||  ||-|  28-" << pos[27] << "  |  29-" << pos[28] << "  |  30-" << pos[29] << "  |" << endl;
                                cout << "+---------+---------+---------+-||  ||-+---------+---------+---------+" << endl;
                                cout << "|  31-" << pos[30] << "  |  32-" << pos[31] << "  |  33-" << pos[32] << "  |-||  ||-|  34-" << pos[33] << "  |  35-" << pos[34] << "  |  36-" << pos[35] << "  |" << endl;
                                cout << "+---------+---------+---------+-||  ||-+---------+---------+---------+" << endl;
                                cout << "Please choose the seat position: ";
                                cin >> ((chosse3 == 2) ? chosse5 : chosse4);
                                if (((chosse3 == 2) ? chosse5 : chosse4) >= 1 && ((chosse3 == 2) ? chosse5 : chosse4) <= 36) 
                                    trips[i].setpos(pos[((chosse3 == 2) ? chosse5 : chosse4) - 1]);
                                double price[10][6] = { {220, 130, 110, 90, 50, 75},{180, 110, 90, 70, 40, 60},{160, 90, 70, 55, 35, 50},{200, 120, 90, 75, 45, 65},{130, 65, 50, 40, 25, 35},
                                                        {180, 100, 80, 60, 40, 55},{160, 90, 70, 55, 35, 50},{200, 125, 100, 80, 50, 70},{180, 100, 80, 60, 40, 60},{220, 130, 110, 90, 50, 75} };
                                for (int row = 0; row < 10; row++) {
                                    if (trips[i].getdeparture() == departure[row]) {
                                        for (int col = 0; col < 36; col++) {
                                            if (trips[i].gettype() == type[col]) {trips[i].setprice(price[row][col]); } } } };
                                break;
                            } 
                            while (((chosse3 == 2) ? chosse5 : chosse4) >= 1 && ((chosse3 == 2) ? chosse5 : chosse4) <= 36);
                        }
                        break;
                    }
                    while (chosse3 > 0 && chosse3 <= 6);
                    }
                    break;
                }
                while (chosse6 >=1 && chosse6 <=15);
                }
                break;
            }
            while (chosse1 >0 && chosse1 <= 30);
        }
        break;
    }
    while (chosse1 >0 && chosse1 <= 10);
};

void PayingUser()
{
    
    int pay;
    do
    {
        
        system("cls");
        cout << "+----------------------------------------------+" << endl;
        cout << "|               PAYMENT METHODS                |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "+-------------------+      +-------------------+" << endl;
        cout << "|     1.BANKING     |      |  2.DIRECT PAYMENT |" << endl;
        cout << "+-------------------+      +-------------------+" << endl;
        cout << "Please enter options: ";
        cin >> pay;
        if (pay == 1)
        {
            if (passenger[countar].Banking())
            {
                system("cls");
                cout << "The price of the ticket type " << trips[countar].gettype() << " to " << trips[countar].getdeparture() << " is " << passenger[countar].TotalMoney() << "$" << endl;
                cout << "Quantity ticket: " << passenger[countar].getquantity() << endl;
                passenger[countar].InputPay();
                if (passenger[countar].getpay() >= passenger[countar].TotalMoney() )
                {
                    cout << "\033[1m";
                    cout << "+----------------------------------------------+" << endl;
                    cout << "|              PAYMENT SUCCESS !               |" << endl;
                    cout << "+----------------------------------------------+" << endl;
                    cout << "\033[0m";
                    countar++;
                    break;
                    if (passenger[countar].getpay() < passenger[countar].TotalMoney())
                    {
                        cout << "\033[1;31m" ;
                        cout << "+----------------------------------------------+" << endl;
                        cout << "|                PAYMENT FAIL !                |" << endl;
                        cout << "+----------------------------------------------+" << endl;
                        cout << "\033[0m";
                        break;
                    }
                }
            }
        }
        if (pay == 2)
        {
            cout << "\033[1m" ;
            cout << "+----------------------------------------------------------------------------------+" << endl;
            cout << "|   YOU HAVE CHOOSE DIRECT PAYMENT PLEASE GO TO THE PAYMENT KIT AND GET TICKETS    |" << endl;
            cout << "+----------------------------------------------------------------------------------+" << endl;
            cout << "\033[0m";
            break;
        }
        
    }
    while (pay >= 1 && pay <= 2);
    
}

void Register()
{
string username, password;

bool found = false ;

do 
{
    found = false;
    cout << "Enter Username Client: ";
    getline(cin, username);
    cout << "Enter Password Client: ";
    getline(cin, password);
    for (int i = 0; i < sizeof(clients); i++) 
    {
        if (username == clients[i].getusernameclient()) 
        {
            found = true;
            break;
        }
    }
    if (found) 
    {
        cout << "\033[1;31m" ;
        cout << "+-----------------------------------------------+" << endl;
        cout << "| USERNAME ALREADY EXISTS. PLEASE TRY AGAIN !!! |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "\033[0m";
    }
} 
while (found);


clients[countarr].setusernameclient(username);
clients[countarr].setpasswordclient(password);
passenger[countarr].Info();

// Thêm thông tin client vào mảng clients
countarr++;

    system("cls");
    cout << "+------------------------------------------------------------+" << endl;
    cout << "| ACCOUNT HAS BEEN CREATED, PLEASE COMPLETE USER INFORMATION |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
};

void Menu();



void Out()
{
    cout << "\033[1m";
    cout << "INFOMATION PASSENGER"<< endl;
    cout << "+-------------------------+---------+---------+------------------+-------------------------+----------------------+" << endl;
    cout << "|          NAME           |   SEX   |   AGE   |      PHONE       |           EMAIL         |      TOTAL PRICE     |" << endl;
    cout << "+-------------------------+---------+---------+------------------+-------------------------+----------------------+" << endl;
    cout << "\033[0m";
}

void Login()
{
    int d = 0;
    bool found = false;
    string username, password;
    do
    {
    cout << "ENTER YOUR ACCOUNT INFORMATION: " << endl;
    cout << "USER NAME: " ;
    getline(cin, username);
    cout << "PASSWORD: " ;
    getline(cin, password);
    for (int i = 0; i < sizeof(clients);i++)
    {
        if (username == clients[i].getusernameclient() && password == clients[i].getpasswordclient()) 
        {
                found = true;
                system("cls");
                cout << "+----------------------------------------------------------+" << endl;
                cout << "|                   Login successful !!!                   |" << endl;
                cout << "+----------------------------------------------------------+" << endl;
                int option2;    
                passenger[i].Inquantity();
                
                do
                {
                system("cls");
                    cout << "                             ACTIVATE WITH CLIENTS AUTHORIZATION                              " << endl;
                    cout << "+------------------------------+------------------------------+------------------------------+" << endl;
                    cout << "|     1.Tickets on demand      |   2.Passenger information    |             3.Pay            |" << endl;
                    cout << "+------------------------------+------------------------------+------------------------------+" << endl;
                    cout << "To buy tickets you will follow the order 1-2-3 above, do you want to do the operation ?" << endl;
                    cout << "                                    +----------+----------+" << endl;
                    cout << "                                    |  1-YES   |   2-NO   |" << endl;
                    cout << "                                    +----------+----------+" << endl;
                    cout << "Please enter options: " ;
                    cin >> option2;
                    if (option2 == 1)
                    {
                        system("cls");
                        Ticketondemand();
                        system("cls");
                        trips[i].OutTrip();
                        system("pause");
                        PayingUser();
                    }
                    if (option2 == 2) 
                    {
                        
                        int chossee;
                        do  
                        {
                            system("cls");
                        cout << "\033[1;31m" ;
                        cout << "+-----------------------------------------------------------------------------------+" << endl;
                        cout << "|                                        WARNING !!                                 |" << endl;
                        cout << "|          After you select cancel, you will be taken to the login screen!          |" << endl;
                        cout << "|                                 Do you want to continue ?                         |" << endl;
                        cout << "|                     1-YES                                     2-NO                |" << endl;
                        cout << "+-----------------------------------------------------------------------------------+" << endl;
                        cout << "\033[0m";
                        cout << "Your choice:";
                        cin >> chossee;
                        if (chossee == 1) Menu();
                        if (chossee == 2) 
                        {
                            system("cls");
                            Ticketondemand();
                            system("cls");
                            trips[i].OutTrip();
                            system("pause");
                            PayingUser();
                        }
                        }
                        while (chossee >= 1 && chossee <= 2);
                        break;
                    }
                    break;
                    
                }
                while (option2 >= 1 && option2 <= 2);
                break;
            }
        }    
        if (!found)
            {
                d++;
                cout << "\033[1;31m" ;
                cout << "+----------------------------------------------------------+" << endl;
                cout << "|    INVALID USERNAME OR PASSWORD. PLEASE TRY AGAIN !!!    |" << endl;
                cout << "+----------------------------------------------------------+" << endl;
                cout << "\033[0m";
            }       
            if (d==3)
            {
                cout << "\033[1;31m" ;
                cout << "+----------------------------------------------------------+" << endl;
                cout << "|          WRONG ACCOUNT OVER THE NUMBER OF RULES          |" << endl;
                cout << "+----------------------------------------------------------+" << endl;
                cout << "\033[0m";
            }
    }
    while (!found);
};


void SWAP(Passenger& a, Passenger& b)
{
    Passenger t = a;
    a = b;
    b = t;
}

void Menu()
{
    int i = 0;
    int chosse;
    do
    {
        system("cls");
        cout << "                                  MANAGEMENT OF AIR TICKETS                                   " << endl;
        cout << "+------------------------------+------------------------------+------------------------------+" << endl;
        cout << "|         1.Register           |            2.Login           |   3.login as administrator   |" << endl;
        cout << "+------------------------------+------------------------------+------------------------------+" << endl;
        cout << "Please enter options: " ;
        cin >> chosse;
        cin.ignore();
        int n;
        Administrator administrators;
        if (chosse == 1)
        {
            Register();
            
        }
        if (chosse == 2)
        {
            Login();
        }
        if (chosse == 3)
        {
            if (administrators.Loginad())
            {
                int option3;
                do
                {
                    system("cls");
                    cout << "                                          ACTIVATE WITH ADMINISTRATIVE AUTHORIZATION                          " << endl;
                    cout << "+------------------------------+------------------------------+------------------------------+------------------------------+" << endl;
                    cout << "|    1.Payment Confirmation    |        2.Print tickets       |      3.Passenger display     |      4.Sort descending       |" << endl;
                    cout << "+------------------------------+------------------------------+------------------------------+------------------------------+" << endl;
                    cout << "Please enter options: " ;
                    cin >> option3;
                    if (option3 == 1)
                    {
                        int k;
                        cout << "Enter the passenger: ";
                        cin >> k;
                        if (passenger[k].getpay() != 0)
                        if  (passenger[k].getpay() == passenger[k].TotalMoney())
                        {
                            system("cls");
                            cout << "\033[1m" ;
                            cout << "+----------------------------------------------------------+" << endl;
                            cout << "|                   PASSENGER HAVE PAYED                   |" << endl;
                            cout << "+----------------------------------------------------------+" << endl;
                            cout << "\033[0m";
                        }
                        else
                        {
                            system("cls");
                            cout << "\033[1,31m" ;
                            cout << "+----------------------------------------------------------+" << endl;
                            cout << "|              PASSENGER HAS NOT PAYED TICKETS             |" << endl;
                            cout << "+----------------------------------------------------------+" << endl;
                            cout << "\033[0m";
                            
                        }
                        system("pause");
                    }
                    if (option3 == 2)
                    {
                            int k;
                            cout << "Enter the passenger: ";
                            cin >> k;
                            if (passenger[k].getage() != 0)
                            {
                            
                                system("cls");
                                cout << "\033[1;33m" ;
                                cout << "+----------------------------------------+" << endl;
                                cout << "| FLIGHTNAME: Ho Chi Minh - "<< setw(13) << trips[i].getdeparture() << "|" << endl;
                                cout << "| FLIGHTDATE: " << right << setfill('0') << setw(2) << trips[i].gettime().d << "/" << right << setfill('0') << setw(2) << trips[i].gettime().m << "/" << left << setfill(' ') << setw(21) << trips[i].gettime().y << "|" << endl;
                                cout << "| DEPARTURE TIME: " << right << setfill('0') << setw(2) << trips[i].gethours().hour << ":" << right << setfill('0') << setw(2)<< trips[i].gethours().minute << ":" << right << setfill('0') << setw(2) << trips[i].gethours().second << setw(16) << setfill(' ') << "|" << endl;
                                cout << "| TYPE: " << setw(33) << left << trips[i].gettype() << "|" << endl;
                                cout << "| SEAT POSITION: " << setw(24) << left << trips[i].getpos() << "|" << endl;
                                cout << "| QUANTITY TICKET: " << setw(22) << left << passenger[i].getquantity() << "|" << endl;
                                cout << "| PRICE TICKET: " << setw(3) << left << trips[i].getprice() << setw(22) << left << "$" << "|" << endl;
                                cout << "|========================================|"  << endl;
                                cout << "|========================================|"  << endl;
                                cout << "| NAME: " << setw(33) << left << passenger[i].getfullname() << "|" << endl;
                                cout << "| SEX: " << setw(34) << left << passenger[i].getsex() <<  "|" << endl;
                                cout << "| AGE: " << setw(34) << left << passenger[i].getage() <<  "|" << endl;
                                cout << "| PHONE: " << setw(32) << left << passenger[i].getphone() << "|" << endl;
                                cout << "| EMAIL: " << setw(32) << left << passenger[i].getemail() << "|" << endl;
                                cout << "+----------------------------------------+" << endl;
                                cout << "\033[0m" ;
                                
                            if  (passenger[k].getpay() != passenger[k].TotalMoney())
                            {
                                system("cls");
                                cout << "\033[1,31m" ;
                                cout << "+----------------------------------------------------------+" << endl;
                                cout << "|              PASSENGER HAS NOT PAYED TICKETS             |" << endl;
                                cout << "+----------------------------------------------------------+" << endl;
                                cout << "\033[0m";
                            }
                            }
                    }       
                    if (option3 == 3)
                    {
                        system("cls");
                        Out();
                        for ( int i = 0;i < sizeof(passenger);i++)
                        {
                            if (passenger[i].getage() != 0)
                                    passenger[i].InfoOut();
                                    
                        }
                        system("pause");
                    }
                    if (option3 == 4)
                    {
                        for ( int c = 0; c < sizeof(passenger); c++)
                        {
                            for ( int v = c + 1; v <= sizeof(passenger); v++)
                            {
                                if (passenger[c].TotalMoney() < passenger[v].TotalMoney())
                                    SWAP(passenger[c],passenger[v]);
                            }
                        }
                        system("cls");
                        Out();
                        for ( int i = 0;i < sizeof(passenger);i++)
                        {
                            if (passenger[i].getage() != 0)
                                    passenger[i].InfoOut();
                                    
                        }
                        system("pause");
                        Menu();
                    }
                    system("pause");

                }
                while (option3 > 0 && option3 <= 4);
                system("pause");
            }
        }
        system("pause");
    }
    while (chosse > 0 && chosse <=3);
     system("pause");
};

int main()
{   
    Menu();
    delete[] clients;
    delete[] passenger;

    return 0;
};



