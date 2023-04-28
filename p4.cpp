#include <iostream>
#include<fstream>
#include<istream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

const int m = 1000;

class Toll_Plaza
{
private:


    int buscount, allowed_truckcount, banned_truckcount, bikecount, carcount, pickupcount;

    int toll_bus[m];
    string Bus_name[m];
    string Bus_code[m];
    string Bus_type[m];

    string Truck_code[m];
    int toll_truck[m];
    int fine[m];
    string Banned_code[m];
    int allowed_wgt[m];
    int banned_wgt[m];

    string bike_model[m];
    string bike_name[m];
    int toll_bike[m];

    string Car_brand[m];
    string Car_model[m];
    int toll_car[m];

    string Pickup_name[m];
    string Pickup_model[m];
    int toll_pickup[m];

    int totalVehicle = 0;

public:
    void login();
    void create();
    void forgot();

    void CNT();

    void enterBus();
    void enterTruck();
    void enterBike();
    void enterCar();
    void enterPicup();

    void display();
    void print();
    void banned_vehicle();
    void totalamount();
    void totalvehicle();
    void emergency();
    void feedback();


};
void Toll_Plaza::print()
{
    p:
        system("cls");
        cout<<"\n\n\n\n\t************************************************************************************************************";
        cout<<"\n\n\t\t\t\t\t\t    VEHICLE TOLL SYSTEM";
        cout<<"\n\n\t************************************************************************************************************";

}

void Toll_Plaza::create()
{
    p:
        system("cls");
        string user,pass;
        char ch;
        cout<<"\n\n\n\n\n\t\t\t**********************************REGISTER**********************************";
        cout<<"\n\n\n\t\t\t\t\t\t Enter Username:";
        cin>>user;
        cout<<"\n\n\t\t\t\t\t\t Enter Password:";
         do
        {
            ch = getch();
            if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            {
                pass =ch;
                cout<<"*";

            }

        }
         while(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z');

        ofstream reg("database.txt",ios::app);
        reg<<user<<pass<<endl;
        cout<<"\n\n\n\t\t\t\t\t\tRegistration Successfully....!\n";




        login();

}
void Toll_Plaza::login()
{
    int exist;
    string user_n,user_p,u,p;
    char ch;
    system("cls");
    cout<<"\n\n\n\n\n\t\t\t********************************** LOG IN **********************************";
    cout<<"\n\n\n\t\t\t\t\t\tUsername:";
    cin>>user_n;
    cout<<"\n\n\t\t\t\t\t\tPassword:";
     do
        {
            ch = getch();
            if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            {
                user_p =ch;
                cout<<"*";

            }

        }
    while(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z');


    ifstream input("database.txt");

    while(input>>u>>p)
    {
        if(u == user_n && p==user_p)
        {
           exist = 1;
        }
    }
    input.close();
    if(exist == 1)
    {
        cout<<"\n\n\t\t\t\t\t\tSorry,Login Error...";
        cin.get();
        cin.get();
        int main();

    }
    else
    {
        cout<<"\n\n\n\n\t\t\t\t\tHELLO"<<" "<<user_n<<", "<<"We are glad that you are here...\n";
        cin.get();
        cin.get();
        int main();
    }




}
void Toll_Plaza::forgot()
{
    p:
        system("cls");
        int ex =0;
        string searchuser,su,sp;
        cout<<"username:";
        cin>>searchuser;

        ifstream searchu("database.txt");
        while(searchu>>su>>sp)
        {
            if(su == searchuser)
            {
                ex = 1;
                break;
            }
        }
        searchu.close();
        if(ex == 1)
        {
            cout<<"Hurray ! Account Found!\n";
            cout<<"Your Password is:"<<sp;
            cin.get();
            cin.get();
            int main();
        }
        else
        {
            cout<<"Sorry,Your Account is not found\n";
            cin.get();
            cin.get();
            int main();

        }



}
void Toll_Plaza::CNT()
{
    p:
        system("cls");
        buscount = 0, allowed_truckcount = 0, banned_truckcount = 0, bikecount = 0, carcount = 0, pickupcount = 0;
        cout<<"\n\n\t************************************************************************************************************";
        cout<<"\n\n\t\t\t\t\t\t    VEHICLE TOLL SYSTEM";
        cout<<"\n\n\t************************************************************************************************************";

}
void Toll_Plaza::enterBus()
{
    p:
        system("cls");
        cout << "\n\n\t\t\t\t\t\tEnter Bus Name : ";
        string name;
        cin >> name;
        {
            Bus_name[buscount] = name;
        }
        string code;
        cout << "\n\n\t\t\t\t\t\tEnter Bus Code : ";
        cin >> code;
        {
            Bus_code[buscount] = code;
        }
        cout << "\n\n\t\t\t Press <1> For Long route \t\t Press <2> For Local \n";
        char a;
        cin >> a;
        if (a == '1')
        {
            cout << "\n\n\n\t\t\t\t\tToll of this BUS  = Rs. 2000.Please Collect it...\n";
            toll_bus[buscount] = 2000;
            Bus_type[buscount] = "\n\n\t\t\t\t\t\tLong route";
            buscount++;
            totalVehicle++;
        }
        else if (a == '2')
        {
            cout << "\n\n\n\t\t\t\t\tToll of this BUS  = Rs. 1000.Please Collect it...\n";
            toll_bus[buscount] = 1000;
            Bus_type[buscount] = "\n\n\t\t\t\t\t\tLocal";
            buscount++;
            totalVehicle++;
        }
        else
        {
            cout <<"\n\n\t\t\t\t\t\tWrong input....\n";
        }
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::enterTruck()
{
    p:
        system("cls");
        cout << "\n\n\t\t\t\t\tCheck the Weight of Truck and input (in TON) : ";
        int weight;
        cin >> weight;

        string code;
        cout << "\n\n\t\t\t\t\t\t   Enter Truck Code : ";
        cin >> code;

        if (weight <= 50)
        {
            cout << "\n\n\n\t\t\t\t\tToll of this Truck = Rs.2500.Please Collect this.....\n";
            toll_truck[allowed_truckcount] = 2500;
            Truck_code[allowed_truckcount] = code;
            allowed_wgt[allowed_truckcount] = weight;
            allowed_truckcount++;
            totalVehicle++;
        }
        else
        {
            cout << "\n\n\n\t\t\t\tTruck is Overloaded ( more than 50 TON) ....It should be Banned........\n\n\t\t\t\t\t\t\tFine = Rs. 5000 \n";
            Banned_code[banned_truckcount] = code;
            fine[banned_truckcount] = 5000;
            banned_wgt[banned_truckcount] = weight;
            banned_truckcount++;
        }
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::enterBike()
{
    p:
        system("cls");
        string brand;
        cout << "\n\n\t\t\t\t\t\tEnter Bike Brand : ";
        cin >> brand;
        {
            bike_name[bikecount] = brand;
        }
        string model;
        cout << "\n\n\t\t\t\t\t\tEnter Bike Model : ";
        cin >> model;
        {
            bike_model[bikecount] = model;
        }

        cout<< "\n\n\n\t\t\t\tToll of this Bike is RS.500.Please Collect it..." << endl;
        toll_bike[bikecount] = 500;
        bikecount++;
        totalVehicle++;
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::enterCar()
{
    p:
        system("cls");
        string brand;
        cout << "\n\n\t\t\t\t\t\tEnter Car Brand : ";
        cin >> brand;
        {
            Car_brand[carcount] = brand;
        }
        string model;
        cout << "\n\n\t\t\t\t\t\tEnter car Model : ";
        cin >> model;
        {
            Car_model[carcount] = model;
        }
        cout << "\n\n\n\t\t\t\t\tToll of this Car is RS.800...Please Collect it...\n";
        toll_car[carcount] = 800;
        carcount++;
        totalVehicle++;
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::enterPicup()
{
    p:
        system("cls");
        cout << "\n\n\t\t\t\t\t\tEnter Brand : ";
        string brand;
        cin >> brand;
        {
            Pickup_name[pickupcount] = brand;
        }
        cout << "\n\n\t\t\t\t\t\tEnter Model : ";
        string model;
        cin >> model;
        {
            Pickup_model[pickupcount] = model;
        }
        cout << "\n\n\n\t\t\t\t\tToll of this Pickup is : Rs.700...Please Collect it ...\n";
        toll_pickup[pickupcount] = 700;
        pickupcount++;
        totalVehicle++;
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::display()
{
    p:
        system("cls");

        if (buscount == 0)
        {
            cout << "\n\n\t\t\t\t\t\tNo Bus Entered...........\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\tEntered Buses ..............\n";
            //print();
            for (int i = 0; i < buscount; i++)
            {
                cout << i + 1 << "\n\n\t\t\t\t\t\tBus Name : " << Bus_name[i] << "\t"
                        << "\n\n\t\t\t\t\t\tBus Code : " << Bus_code[i] << "\t"
                    << "\n\n\t\t\t\t\t\tBus Type :  " << Bus_type[i] << "\t"
                    << "\n\n\t\t\t\t\t\tToll amount : " << toll_bus[i] << endl;
              //  print();
            }
            cout << "\n\n\t\t\t\t\t\tTotal Entered Buses : " << buscount << endl;
        }

        if (allowed_truckcount == 0)
        {
            cout << "\n\n\t\t\t\t\t\tnNo Truck Entered ........\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\tEnter Trucks ............\n";
            int sum = 0;
//            print();
            for (int i = 0; i < allowed_truckcount; i++)
            {
                cout << i + 1 << "\n\t\t\t\t\t\tTruck Code : " << Truck_code[i] << "\t"
                    << "\n\t\t\t\t\t\tWeight  (ton): " << allowed_wgt[i] << "\t"
                    << "\n\t\t\t\t\t\tToll Amount : " << toll_truck[i] << endl;
                sum = sum + toll_truck[i];
//                print();
            }
            cout << "\n\t\t\t\t\t\tTotal Entered Truck : " << allowed_truckcount << endl;
            cout << "\n\t\t\t\t\t\tTotal Toll of Truck : " << sum << endl;
        }
        if (bikecount == 0)
        {
            cout << "\n\n\t\t\t\t\t\tNo Bike Entered.......... \n";
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\tEntered Bikes ............." << endl;
            int sum = 0;
//            print();
            for (int i = 0; i < bikecount; i++)
            {
                cout << i + 1 << "\n\t\t\t\t\t\tBrand : " << bike_name[i] << "\t"
                    << "\n\t\t\t\t\t\tBike model : " << bike_model[i] << "\t"
                    << "\n\t\t\t\t\t\tToll amount : " << toll_bike[i] << endl;
                sum = sum + toll_bike[i];
//                print();
            }
            cout << "\n\n\t\t\t\t\t\tTotal Entered Bike : " << bikecount << endl;
            cout << "\n\n\t\t\t\t\t\tTotal Toll of Bike : " << sum << endl
                << endl;
        }
        if (carcount == 0)
        {
            cout << "\n\n\t\t\t\t\t\tNo Car Entered...........\n";
        }
        else
        {
            cout << "\n\t\t\t\t\t\tEntered Cars...............\n";

            int sum = 0;
//            print();
            for (int i = 0; i < carcount; i++)
            {
                cout << i + 1 << "\n\t\t\t\t\t\tBrand : " << Car_brand[i] << "\t"
                    << "\n\t\t\t\t\t\tModel : " << Car_model[i] << "\t"
                    << "\n\t\t\t\t\t\tToll Amount : " << toll_car[i] << endl;
                sum = sum + toll_car[i];
//                print();
            }
            cout << "\n\t\t\t\t\t\tTotal Entered Car : " << carcount << endl;
            cout << "\n\t\t\t\t\t\tTotal Toll of Car : " << sum << endl
                << endl;
        }
        if (pickupcount == 0)
        {
            cout << "\n\n\t\t\t\t\t\tNo pickup entered........\n";
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\tEntered Pickups.............\n";

            int sum = 0;
//            print();
            for (int i = 0; i < pickupcount; i++)
            {
                cout << i + 1 << "\n\t\t\t\t\t\tBrand : " << Pickup_name[i] << "\t"
                    << "\n\t\t\t\t\t\tModel : " << Pickup_model[i] << "\t"
                    << "\n\t\t\t\t\t\tToll amount : " << toll_pickup[i] << endl;
                sum = sum + toll_pickup[i];
//                print();
            }
            cout << "\n\n\t\t\t\t\t\tTotal Entered Picup : " << pickupcount << endl;
            cout << "\n\t\t\t\t\t\tTotal toll of Pickup : " << sum << endl
                << endl;
        }

          cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::banned_vehicle()
{
    p:
        system("cls");
        int sum = 0;
//        print();
        for (int i = 0; i < banned_truckcount; i++)
        {
            cout << i + 1 << "\n\t\t\t\t\t\tTruck Code : " << Banned_code[i] << "\tWeight :  " << banned_wgt[i] << endl;
            sum = sum + fine[i];
//            print();
        }
            cout << "\n\t\t\t\t\t\tTotal Banned Trucks : " << banned_truckcount << endl;

        cout << "\n\t\t\t\t\t\tTotal Collected Fine : " << sum << " (5000) per Truck" << endl;
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::totalamount()
{
    p:
        system("cls");
        int sum = 0;
        for (int i = 0; i < buscount; i++)
        {
            sum = sum + toll_bus[i];
        }
        for (int i = 0; i < allowed_truckcount; i++)
        {
            sum = sum + toll_truck[i];
        }
        for (int i = 0; i < bikecount; i++)
        {
            sum = sum + toll_bike[i];
        }
        for (int i = 0; i < carcount; i++)
        {
            sum = sum + toll_car[i];
        }
        for (int i = 0; i < pickupcount; i++)
        {
            sum = sum + toll_pickup[i];
        }
        cout << "\n\t\t\t\t\t\tTotal Collected Amount = "<< "RS." <<sum<< endl;
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::totalvehicle()
{
    p:
        system("cls");
        cout << "\n\t\t\t\t\tTotal Entered Vehicle : " << totalVehicle << endl;
        cout<<"\t\t=================================================================================================";
}
void Toll_Plaza::emergency()
{
    p:
        system("cls");
   cout<<"\n\n\t\t\t\t   ================= EMERGENCY CONTACT LIST ================= ";
   cout<<"\n\n\t\t\t\t\t=>police:100";
   cout<<"\n\n\t\t\t\t\t=>Ambulance:101";
   cout<<"\n\n\t\t\t\t\t\tADD CONTACTS";
     cout<<"\t\t=================================================================================================";

}
void Toll_Plaza::feedback()
{
    p:
        system("cls");
  int c;
  cout<<"\n\n\t\t\t\t  ================= FEEDBACK ================= ";
  cout<<"\n\n\t\t\t\t\t\tNeed to Development of Roads\n\n\t\t\t\t\t\t";
  cout<<"1)Urgently Needed";
  cout<<"2)Needed";
  cout<<"3)Not Needed";
  cout<<"Enter:"<<c;
    cout<<"\t\t=================================================================================================";
}
int main()
{
    int choice;

    Toll_Plaza jamuna;

   // cout<<"\n\n\n\n\t************************************************************************************************************";
    //cout<<"\n\n\t\t\t\t\t\t    VEHICLE TOLL SYSTEM";
    //cout<<"\n\n\t************************************************************************************************************";
    jamuna.print();

    cout<<"\n\n\n\n\n\t\t\t\t************************** LOG IN **************************";;
    cout<<"\n\n\n\n\t\t\t\t\t\t  CREATE NEW ACCOUNT[press 1]"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\tLOG IN[press 2]"<<endl;
    cout<<"\n\n\t\t\t\t\t\t  Forgot password?[press 3]";
    cout<<"\n\npress:";
    cin>>choice;
    switch(choice)
    {
        case 1:
            jamuna.create();
            break;
        case 2:
            jamuna.login();
            break;
        case 3:
            jamuna.forgot();
            break;
        default:
            cout<<"Sorry,You Press...INVALID KEY";
            main();

    }

    jamuna.CNT();

    char xxx;

    do
    {
        cout << "\n\n\t\t\t\t\t\t1)Register a Vehicle\n\t\t\t\t\t\t2)Show Banned Trucks\n\t\t\t\t\t\t3)Show Registered Vehicle lists and Toll\n\t\t\t\t\t\t4)Show Total Amount(without fine)\n\t\t\t\t\t\t5)Show Number of Registered Vehicles\n\t\t\t\t\t\t6)Emergency Contacts\n\t\t\t\t\t\t7)Feedback\n\n";

        cout << "Select : ";
        cin >> xxx;
        switch (xxx)
        {
         case '1':
            cout << "\n\n\t\t\t\t\tRegister:a]For Bus\n\t\t\t\t\t         b]For Truck\n\t\t\t\t\t         c]For Bike\n\t\t\t\t\t         d]For Car\n\t\t\t\t\t         e]For Pickup\n\n";
            char x;
            cout << "Select :  ";
            cin >> x;
            switch (x)
            {
            case 'a':
                jamuna.enterBus();
                break;
            case 'b':
                jamuna.enterTruck();
                break;
            case 'c':
                jamuna.enterBike();
                break;
            case 'd':
                jamuna.enterCar();
                break;
            case 'e':
                jamuna.enterPicup();
                break;
            default:
                cout << "Wrong Input...\n";
                break;
            }

            break;
        case '2':
            jamuna.banned_vehicle();
            break;
        case '3':
            jamuna.display();
            break;
        case '4':
            jamuna.totalamount();
            break;
        case '5':
            jamuna.totalvehicle();
            break;
        case '6':
            jamuna.emergency();
            break;
        case 7:
            jamuna.feedback();
            break;
        default:
            cout<<"Program Terminated...!";
            break;
        }
    } while (1);

    return 0;
}
