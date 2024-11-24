#include<iostream>
#include<windows.h>
using namespace std;
void header();
int Login();
int Customer_Top_Choice();
int Admin_Top_Choice();
void print_bus_schedule();
void print_train_schedule_UP();
void print_train_schedule_Down();
void print_flight_schedule();
void change_bus_schedule(string,int);
void change_train_schedule(string ,string,string, string);
void change_flight_schedule(int,string);
void change_bus_price(string,int);
void change_flight_price(int,string);
int find_flight_price(string);
void flight_price_schedule();
void bus_price_schedule();
bool isNo_Repeation(string , string );
    //Admin name and password
    string Admin_Name[100]={"John","Robert","Richard","Charles","Thomas"};
    string Admin_Password[100]={"1234","5678","1357","2468","2357"};
    //Bus 9
    string bus_route_P[9]={"Lahore-khanpur","Lahore-Karachi","Lahore-Islamabad","Islamabad-Lahore","Multan-Lahore","Multan-Lahore","Islamabad-Bahawalpur","Bahawalpur-Karachi","Multan-Khanpur"};
    string bus_route[9]={"Lahore-khanpur      ","Lahore-Karachi      ","Lahore-Islamabad    ","Islamabad-Lahore    ","Multan-Lahore       ","Multan-Lahore       ","Islamabad-Bahawalpur","Bahawalpur-Karachi  ","Multan-Khanpur      "};
    string bus_time[9]={"13:00","23:30","10:00","18:00","11:15","22:00","09:20","15:00","09:00"};
    string bus_price[9]={"3,000","6,000","2,000","2,000","1,700","3,000","3,000","2,400","3,800"};
    //Train UP 11 stations (Karachi to Rawalpindi)
    string Train_Route_P[11]={"Karachi","Hyderabad","Khairpur","Khanpur","Bahawalpur","Multan","Sahiwal","Lahore","Gujranwala","Jehlum","Rawalpindi"};
    string Train_Route[11]={"Karachi      ","Hyderabad    ","Khairpur     ","Khanpur      ","Bahawalpur   ","Multan       ","Sahiwal      ","Lahore       ","Gujranwala   ","Jehlum       ","Rawalpindi   "};
    string Train_Arrival_Time[11]={"-----","20:35","01:40","05:00","08:10","10:45","13:47","17:00","18:50","21:00","23:27"};
    string Train_Departure_Time[11]={"18:00","20:37","02:00","05:03","08:30","10:47","14:07","17:02","18:52","21:02","-----"};
    //Train Down 11 Stations (Rawalpindi to Karachi)
     string Train_Arrival_Down[11]={"-----","20:35","01:40","05:00","08:10","10:45","13:47","17:00","18:50","21:00","23:27"};
     string Train_Departure_Down[11]={"18:00","20:37","02:00","05:03","08:30","10:47","14:07","17:02","18:52","21:02","-----"};
     string Train_Route_Down[11]={"Rawalpindi   ","Jehlum       ","Gujranwala   ","Lahore       ","Sahiwal      ","Multan       ","Bahawalpur   ","Khanpur      ","Khairpur     ","Hyderabad   ","Karachi      "};
    //Flights 8
    string Flight_Route_P[8]={"Karachi ---- Lahore","Lahore ---- Karachi","Islamabad ---- Skardu","Multan ---- Riyadh", "Riyadh ---- Multan","Multan ---- Dubai", "Dubai ---- Multan","Skardu ---- Islamabad"};
    string Flight_Route[8]={"Karachi ---- Lahore   ","Lahore  ---- Karachi   ","Islamabad ---- Skardu ","Multan  ---- Riyadh    ", "Riyadh  ---- Multan    ","Multan  ---- Dubai     ", "Dubai   ---- Multan     ","Skardu ---- Islamabad  "};
    string Flight_Time[8]={" 07:00","11:10"," 13:03","07:15","05:05","11:30","21:45","18:30"};
    string Flight_Price[8]={"20,400","30,800","15,000","94,600","98,000","120,000","51,400","58,900"};
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X =x;
    coordinates.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

main()
{
    string name, password, Departure_Time, Customer_Name, New_Admin,New_Admin_Password;
    string from, to, Date;
    string Complaint,Customer_Route,Up_Dn;
    bool True_Date=true,True_City=true,isTrue=true,isTrue_LogIn,isTrue_Admin=true,isTrue_Customer=true;
    int Bus_Number, Choice,Customer_Choice,User_Choice,k,g,Option, Train_Choice, Sold_Bus_Tickets=0,Sold_Train_Tickets=0,Sold_Flight_Tickets=0;
    char YN='N', choice;
    header();
    while(isTrue)
    {
    User_Choice=Login();
    if(User_Choice==1)
     while(isTrue_Admin)
     {
       if(User_Choice==1)
    {
        Option=Admin_Top_Choice();// Menue of Admin
        if(Option==1)// Edit or Review Time Table
        {
            // Bus Schedule
            cout<<endl<<"1. BUS Schedule"<<endl<<endl;
            print_bus_schedule();
            cout<<endl;
             //Train Schedule
              print_train_schedule_UP();
              cout<<endl;
              print_train_schedule_Down();
            //Flight Schedule
            print_flight_schedule();
            cout<<endl<<"Want to Change? Y or N: ";
            cin>>YN;
            if(YN=='Y' || YN=='y')
            {
                cout<<"Which one? ";
                cin>>Choice;
                if(Choice==1)// Change Bus Schedule
                {
                  cout<<"\nEnter Bus Number: ";
                  cin>>Bus_Number;
                  cout<<"\nChange departure time: ";
                  cin>>Departure_Time;
                  change_bus_schedule(Departure_Time, Bus_Number);
                  cout<<endl;
                  cout<<"\nUpdated Time Table\n"<<endl;
                  print_bus_schedule();
                }
                else if(Choice==2)// Change Train Schedule
                {
               string Station_Name,Arrival_Time;
               cout<<"Enter Train (Up or Down)";
               cin>>Up_Dn;
               cout<<"\nEnter Station Name: ";
               cin>>Station_Name;
               cout<<"Change Arrival Time: ";
               cin>>Arrival_Time;
               cout<<"Change Departure Time: ";
               cin>>Departure_Time;
               change_train_schedule(Up_Dn, Departure_Time, Arrival_Time, Station_Name);
                cout<<"\nChanged Time Scheduled: "<<endl<<endl;
               if(Up_Dn=="Up" || Up_Dn=="up")
                print_train_schedule_UP();
               else if(Up_Dn=="Down" || Up_Dn=="down")
                print_train_schedule_Down();
                }
                else if(Choice==3)//Change Flight Schedule
                {
                    int Flight_Number;
                   cout<<"\nEnter Flight Number: ";
                   cin>>Flight_Number;
                   cout<<"\nChange departure time: ";
                   cin>>Departure_Time;
                   change_flight_schedule(Flight_Number,Departure_Time);
                    cout<<"Changed Schedule"<<endl;
                   print_flight_schedule();
                }
            }
        }
       else if(Option==2)//Second option of Admin: Change or view ticket prices
        {
            string Change_Price;
            bus_price_schedule();
            cout<<endl<<"2. Train Price is 500 per station"<<endl<<endl;//Train Price
            flight_price_schedule();
            cout<<"Want to Change? Y/N: ";
            cin>>YN;
            if(YN=='Y')
                cout<<"Which one? ";
                cin>>Choice;
                if(Choice==1)// Change bus price
                    {
                    cout<<"Enter bus number: ";
                    cin>>Bus_Number;
                    cout<<"Change price: ";
                    cin>>Change_Price;
                    change_bus_price(Change_Price,Bus_Number);
                    cout<<endl<<"Changed Price "<<endl;
                    bus_price_schedule();
                    }
                    else if(Choice==2)//change train price
                    {
                        cout<<"Change price: ";
                        cin>>Change_Price;
                        cout<<endl<<"Changed price: "<<endl;
                        cout<<"Train price per station is Rs "<<Change_Price<<endl;
                    }
                    else if(Choice==3)// Change flight price
                    {
                        int Flight_Number;
                        cout<<"Flight Number";
                        cin>>Flight_Number;
                         cout<<"Change price: ";
                        cin>>Change_Price;
                         change_flight_price(Flight_Number,Change_Price);
                        cout<<"Changed Price\n"<<endl;
                        flight_price_schedule();
                    }
        }
        else if(Option==3)//Third option of Admin: Add new admin
        {
            bool isCorrectAdmin=true;
            while(isCorrectAdmin)
            {
            cout<<"Enter new admin: ";
            cin>>New_Admin;
            cout<<"Assign password: ";
            cin>>New_Admin_Password;
            if(isNo_Repeation(New_Admin, New_Admin_Password))
             {
                isCorrectAdmin=false;
             }
            }
        }
        else if(Option==4)//Fourth option of Admin : Sold tickets
        {
          cout<<"Bus Tickets: "<<Sold_Bus_Tickets<<endl;
          cout<<"Train Tickets: "<<Sold_Train_Tickets<<endl;
          cout<<"Flight Tickets: "<<Sold_Flight_Tickets<<endl;
        }
        else if(Option==5)//See Complaints and suggestions
        {
            cout<<"Name: "<<Customer_Name<<endl;
            cout<<"Comment: " <<Complaint<<endl;
            Sleep(2000);
        }
        else if(Option==6)
            break;
        else if(Option==7)
            return 0;
   }
    }
   else if(User_Choice==2)//Customer
     while(isTrue_Customer)
   {
    if(User_Choice==2)
    {
        Customer_Choice=Customer_Top_Choice();
        if(Customer_Choice==1)//Bus booking
        {
            True_City=true;
            True_Date=true;
            from="";
            to="";
            Date="";
            print_bus_schedule();
            cout<<endl<<"Enter city name as given in table"<<endl;
            while(True_City)
            {
            Customer_Route="";
            cout<<"From: ";
            cin>>from;
            cout<<"To:  ";
            cin>>to;
            string Customer_Route=from+"-"+to;
            for(int x=0;x<9;x++)              // Checking for correct city name
            {
                if(Customer_Route==bus_route_P[x])
                True_City=false;
            }
                if(True_City==true)
                    cout<<"Enter Correct City"<<endl;
            }
            while(True_Date)
            {
            cout<<"Date: (MM/DD) ";
            cin>>Date;
             if(Date[0]=='1')// Checking Whether Date is correct
              {if((Date[1]>='0' && Date[1]<='2') && (Date[3]>='0' && Date[3]<='3') && (Date[4]>='0' && Date[4]<='9'))
                True_Date=false;
              }
            else if( Date[0]=='0')
              {if((Date[1]>='0' && Date[1]<='9') && (Date[3]>='0' && Date[3]<='3') && (Date[4]>='0' && Date[4]<='9'))
                True_Date=false;
              }
            else
            cout<<"Enter correct date"<<endl;
            }
         cout<<"Confirm ? (Y/N):"<<endl;
         cin>>YN;
         if(YN=='Y')
         {
            cout<<endl<<"Thanks for buying ticket"<<endl;
            Sold_Bus_Tickets++;
         }

        }
        else if(Customer_Choice==2)// Train Ticket Booking
        {
            True_City=true;
            True_Date=true;
            from="";
            to="";
            Date="";
          cout<<"1. UET Express (UP)"<<endl;
          cout<<"2. UET Express (Dn)"<<endl;
          cin>>Train_Choice;
            if(Train_Choice==2)
            print_train_schedule_Down();
            else
            print_train_schedule_UP();
            cout<<endl;
            True_Date=true, True_City=true;
            int y,x;
            while(True_City)
            {
            cout<<"From: ";
            cin>>from;
            cout<<"To: ";
            cin>>to;
            for(x=0,y=0;(y<11 || x<11);x++,y++)//Checking for Correct City Name
            {
                if(from==Train_Route_P[x])
                x=12;
                if(to==Train_Route_P[y])
                y=12;
            }
            if((x>=12) && (y>=12))
            True_City=false;
            else
                cout<<"Enter correct city name"<<endl;
            }
            while(True_Date)
            {
            cout<<"Date: (MM/DD) ";
            cin>>Date;
            if(Date[0]=='1')
              {if((Date[1]>='0' && Date[1]<='2') && (Date[3]>='0' && Date[3]<='3') && (Date[4]>='0' && Date[4]<='9'))
                True_Date=false;
              }
            else if( Date[0]=='0')
              {if((Date[1]>='0' && Date[1]<='9') && (Date[3]>='0' && Date[3]<='3') && (Date[4]>='0' && Date[4]<='9'))
                True_Date=false;
              }
            else
            cout<<"Enter correct date"<<endl;
            }
            for(int x=0;x<11;x++)
            {
                if(from==Train_Route_P[x])
                k=x;
                if(to==Train_Route_P[x])
                g=x;
            }
            int price_train=0;
            if(k<g)// Calculate price for Up train
            for(int x=k;x<g;x++)
                price_train=price_train+500;
            else  // Calculate price for down train
            for(int x=g;x<k;x++)
                price_train=price_train+500;
                cout<<endl<<"Confirm          Rs "<<price_train<<" Y/N? ";
                cin>>choice;
                if(choice=='Y')
                {
                cout<<"\nThanks for Buying Ticket"<<endl;
                Sold_Train_Tickets++;
                }

        }
             else if(Customer_Choice==3)// Flight Ticket
        {
            True_City=true;
            True_Date=true;
            from="";
            to="";
            Date="";
            True_Date=true, True_City=true;
              print_flight_schedule();
              while(True_City)
              {
              cout<<"From: ";
              cin>>from;
              cout<<"To: ";
              cin>>to;
              Customer_Route="";
              Customer_Route=from+" ---- "+to;
              for(int x=0;x<9;x++)              // Checking for correct city name
              {
                if(Customer_Route==Flight_Route_P[x])
                True_City=false;
              }
                if(True_City==true)
                    cout<<"Enter Correct City"<<endl;
              }
              int price;
             while(True_Date)
            {
            cout<<"Date:(MM/DD)";
            cin>>Date;//Check on date
            if(Date[0]=='1')
              {if((Date[1]>='0' && Date[1]<='2') && (Date[3]>='0' && Date[3]<='3') && (Date[4]>='0' && Date[4]<='9'))
                True_Date=false;
              }
            else if( Date[0]=='0')
              {if((Date[1]>='0' && Date[1]<='9') && (Date[3]>='0' && Date[3]<='3') && (Date[4]>='0' && Date[4]<='9'))
                True_Date=false;
              }
            else
            cout<<"Enter correct date"<<endl;
            }
            Customer_Route=from+" ---- "+to;
            price=find_flight_price(Customer_Route);
                    cout<<"Confirm         Rs "<<Flight_Price[price];
                    cout<<" Y/N? ";
                    cin>>choice;
                    if(choice=='Y')
                    {
                    cout<<"Thanks for buying ticket"<<endl;
                    Sold_Flight_Tickets++;
                    }
    }
    else if(Customer_Choice==4)// Comments
    {
        cout<<"Enter Your Name: ";
        cin>>Customer_Name;
        cin.ignore();
        cout<<"Enter complaints and reviews: ";
        getline(cin,Complaint);
        cout<<endl;
    }
    else if(Customer_Choice==5)//LogOut
        break;
    else if(Customer_Choice==6)//Exit
        return 0;
        }
    }
    }

}

void header()
{
    gotoxy(5,3);
    cout<<"######     #####     #####    #    #        #       #    #      #       ######### ########    #####    #    #   #######   #######"<<endl;
    gotoxy(5,4);
    cout<<"#     #   #     #   #     #   #   #         # #   # #    #      #           #         #      #     #   #   #    #            #"<<endl;
    gotoxy(5,5);
    cout<<"#     #   #     #   #     #   #  #          #  # #  #    #      #           #         #      #         #  #     #            #"<<endl;
    gotoxy(5,6);
    cout<<"######    #     #   #     #   ###           #   #   #    ########           #         #      #         ###      #######      #"<<endl;
    gotoxy(5,7);
    cout<<"#     #   #     #   #     #   #  #          #       #           #           #         #      #         #  #     #            #"<<endl;
    gotoxy(5,8);
    cout<<"#     #   #     #   #     #   #   #         #       #    #      #           #         #      #     #   #   #    #            #"<<endl;
    gotoxy(5,9);
    cout<<"######     #####     #####    #    #        #       #    ########           #      #######    #####    #    #   #######      #"<<endl;
}

int Login()
{
    int User_Choice=0,Index=0,p,n;
    string name,password;
    string Customer_Name[100]={"Saeed"};
    string Customer_Password[100]={"124"};
    bool isTrue=true,isTrue_Name=false, isTrue_Password=false, isTrue_Admin=true,isTrue_SignUp=true;
    int LogIn_Choice;
    while(isTrue)
    {
    cout<<"1. Login"<<endl;
    cout<<"2. Sign Up"<<endl;
    cin>>LogIn_Choice;
    if(LogIn_Choice==1) //Login for  For Admin and registereed customers
    {
        isTrue_Admin=true;
        cout<<endl<<"1. Admin"<<endl;
        cout<<"2. Customer"<<endl;
        cin>>User_Choice;
         while(isTrue_Admin)
         {
        if(User_Choice==1)// Admin Login
        {
            isTrue_Password=false,isTrue_Name=false;
            cout<<"Name: ";
            cin>>name;
            cout<<"Password: ";
            cin>>password;

            for(n=0;n<100;n++)// Checking whether entered admin name matches in the specified Admin string
            if(Admin_Name[n]==name)
            {
            isTrue_Name=true;
            break;
            }

            for(p=0;p<100;p++)// Checking whether entered password matches in the specified Admin Password string
            if(Admin_Password[p]==password)
            {
                isTrue_Password=true;
                break;
            }


            if(isTrue_Name==true && isTrue_Password==true && p==n)//If name and password with their correct corrospondence (p==n) are true then loop should terminate
            {
            isTrue=false;
            isTrue_Admin=false;
            }

            if(isTrue_Name==false || p!=n)
            cout<<"Enter correct name"<<endl;
            if(isTrue_Password==false || p!=n)
            cout<<"Enter correct password"<<endl;

        }
        else if (User_Choice==2)// Customer Login
         {
        cout<<"Name: ";
        cin>>name;
        cout<<"Pssword: ";
        cin>>password;
        for(p=0;p<100;p++)// Checking whether entered customer password matches the one provided during SignUp
            if(Customer_Password[p]==password)
            {
                isTrue_Password=true;
                break;
            }

        for(n=0;n<100;n++)//Checking whether entered customer name matches the one provided during SignUp
            if(Customer_Name[n]==name)
            {
                isTrue_Name=true;
                break;
            }
        if(isTrue_Name==true && isTrue_Password==true && p==n)//If name and password with their correct corrospondence (p==n) are true then loop should terminate
            {
            isTrue=false;
            isTrue_Admin=false;
            }

        if(isTrue_Name==false && p!=n)
            cout<<"Enter correct name"<<endl;
        if(isTrue_Password==false && p!=n)
            cout<<"Enter correct password"<<endl;
         }
    }
    }
    else if(LogIn_Choice==2)// SignUp
    {
        while(isTrue_SignUp)
        {
        cout<<"Name: ";
        cin>>name;
        cout<<"Pssword: ";
        cin>>password;
        for(int x=0;x<100;x++)
        {
            if(Customer_Name[x]!="\0" && Customer_Password[x]!="\0")
            Index++;
            else
                break;
        }
        Customer_Name[Index]=name;
        Customer_Password[Index]=password;
        for(int x=0;x<Index;x++)// Asuring that same password should not be given to two users
        {
        if(Customer_Password[x]==Customer_Password[Index])
        {
        cout<<"This Password has already taken. Please try another one"<<endl;
        Customer_Password[Index]='\0';// Removing previously entered values
        Customer_Name[Index]='\0';
        isTrue_SignUp=true;
        break;
        }
        if(Customer_Name[x]==Customer_Name[Index])// Assuring that two user names should not have same user name
        {
        cout<<"This Username has already taken. Please try another one"<<endl;
        Customer_Password[Index]='\0';// Removing previously entered values
        Customer_Name[Index]='\0';
        isTrue_SignUp=true;
        break;
        }
        else
            isTrue_SignUp=false;
        }
        }
    }
    }
    return User_Choice;
}
// Add Total Route and Distance of train
void print_train_schedule_UP()
{
    cout<<endl<<"2. Train Schedule (UP)"<<endl;
    cout<<endl<<"Train Route        Arrival Time        Departure Time"<<endl;
    for(int x=0;x<11;x++)
    cout<<Train_Route[x]<<"        " <<Train_Arrival_Time[x]<<"             " <<Train_Departure_Time[x]<<endl;
}
void print_train_schedule_Down()
{
    cout<<endl<<"2. Train Schedule (Down)"<<endl;
    cout<<endl<<"Train Route        Arrival Time        Departure Time"<<endl;
    for(int x=0;x<11;x++)
    cout<<Train_Route_Down[x]<<"        " <<Train_Arrival_Down[x]<<"             " <<Train_Departure_Down[x]<<endl;
}
void print_flight_schedule()
{
    cout<<endl<<"3. FLIGHT Schedule"<<endl;
    cout<<endl<<"Flight        Flight Route         Flight Time       Price"<<endl;
    for(int x=-1;x<7;)
    cout<<"PK-"<<++x <<"      "<<Flight_Route[x]<<"     " <<Flight_Time[x]<<"     "<<Flight_Price[x]<<endl;
}

void print_bus_schedule()
{
    int c=1;
    cout<<"Bus                   Route       \t\tTime        Price"<<endl;
    for(int x=0;x<9;x++)
    {
        cout<<"Bus Number "<<c<<"        "<<bus_route[x]<<"        "<<bus_time[x]<<"        "<<bus_price[x]<<endl;
        c++;
    }
}
void change_bus_schedule(string Departure_Time ,int Bus_Number)
{
    Bus_Number--;
    bus_time[Bus_Number]=Departure_Time;
}

void change_train_schedule(string Up_Dn, string Departure_Time, string Arrival_Time, string Station_Name)
{
    if(Up_Dn=="Up" || Up_Dn=="up")
    {
     for(int x=0;x<11;x++)
     if(Train_Route_P[x]==Station_Name)
     {
     Train_Departure_Time[x]=Departure_Time;
     Train_Arrival_Time[x]=Arrival_Time;
     x=11;
     }
    }
    else if(Up_Dn=="Down" || Up_Dn=="down")
    {
        for(int x=0;x<11;x++)
     if(Train_Route_P[x]==Station_Name)
     {
     Train_Departure_Down[x]=Departure_Time;
     Train_Arrival_Down[x]=Arrival_Time;
     x=11;
     }
    }

}
 void change_flight_schedule(int Flight_Number,string Departure_Time)
 {
        Flight_Time[Flight_Number]=Departure_Time;
}
void  bus_price_schedule()
{
     int c=1;
     cout<<"Bus                   Route       Price"<<endl;
    for(int x=0;x<9;x++)
    {
        cout<<"Bus Number "<<c<<"        "<<bus_route[x]<<"        RS "<<bus_price[x]<<endl;
        c++;
    }
}

 void flight_price_schedule()
{
    cout<<"3. Flight Prices "<<endl;//Flight Price
    cout<<"Flight        Flight Route      Price"<<endl;
    for(int x=-1;x<7;)
    cout<<"PK-"<<++x <<"  "<<Flight_Route[x]<<"   " <<Flight_Price[x]<<endl;
}
int find_flight_price(string Customer_Route)
{
    int price;
    for(int x=0;x<8;x++)
    {
    if(Customer_Route==Flight_Route_P[x])
        {
         price=x;
         x=8;
        }
    }
    return price;
}
void change_bus_price(string Change_Price,int Bus_Number)
{
   Bus_Number--;
   bus_price[Bus_Number]=Change_Price;
}
void change_flight_price(int Flight_Number, string Change_Price)
{
    Flight_Price[Flight_Number]=Change_Price;
}
int Customer_Top_Choice()
{
    int Customer_Choice;
        cout<<"1. Bus"<<endl;
        cout<<"2. Train"<<endl;
        cout<<"3. Flight"<<endl;
        cout<<"4. Reviews"<<endl;
        cout<<"5. Logout"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>Customer_Choice;
        return Customer_Choice;
}
int Admin_Top_Choice()
{
    int Option;
        cout<<endl<<"ADMIN"<<endl;
        cout<<"1. Edit or review Time Table: "<<endl;
        cout<<"2. Change or view Ticket Price"<<endl;
        cout<<"3. Add new admin"<<endl;
        cout<<"4. Sold tickets"<<endl;
        cout<<"5. See Complaints and Suggestions"<<endl;
        cout<<"6. Logout"<<endl;
        cout<<"7. Exit"<<endl;
        cin>>Option;
        return Option;
}
bool isNo_Repeation(string New_Admin, string New_Admin_Password)
{
    bool repetitition=false;
        for(int x=0;Admin_Name[x]!="\0";x++)// Assuring that two admins names should not have same user name// Asuring that same p should not be given to two admins
        {
        if(Admin_Name[x]==New_Admin)
        {
        cout<<"This Username has already taken. Please try another one"<<endl;
        New_Admin='\0';         // Removing previously entered values
        New_Admin_Password='\0';
        repetitition=false;
        break;
        }
        if(Admin_Password[x]==New_Admin_Password)
        {
        cout<<"This Password has already taken. Please try another one"<<endl;
        New_Admin_Password='\0';  // Removing previously entered values
        New_Admin='\0';
        repetitition=false;
        break;
        }
        else
            repetitition=true;
        }
        return repetitition;
}