# include<iostream>
# include <fstream>
# include <iomanip>
using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void admin_login_menu();
        void admin_login();
        void admin_register();
        void admin_update();
        void view();
        void menu();
        void administratior();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
        void clearscreen();
};

void shopping :: menu(){

    clearscreen();
    m:
    int choice;

    cout << "\t\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|                      MAIN MENU                            |\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|___________________________________________________________|\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";
    cout << "\t\t\t\t\t\t|    1)    Administrator    |\n";
    cout << "\t\t\t\t\t\t|    2)    Buyer            |\n";
    cout << "\t\t\t\t\t\t|    3)    Exit             |\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";

    cout << "\n\t\t\t\t Please Enter Your Choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            admin_login_menu();
            break;
        case 2:
            buyer();
            break;

        case 3:
            exit(0);

        default:
            cout << "Enter Valid Option To Access !!\n\n";

    }goto m;
}

void shopping :: admin_login_menu(){

    clearscreen();
    m:
    int choice;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|                   ADMINISTRATOR LOGIN MENU                |\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|___________________________________________________________|\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";
    cout << "\t\t\t\t\t\t|    1) Admin Login         |\n";
    cout << "\t\t\t\t\t\t|    2) Admin Register      |\n";
    cout << "\t\t\t\t\t\t|    3) Admin Update        |\n";
    cout << "\t\t\t\t\t\t|    4) Main Menu           |\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";

    cout << "\n\n\t\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch(choice){

        case 1:
            admin_login();
            break;

        case 2:
            admin_register();
            break;

        case 3:
            admin_update();
            break;

        case 4:
            menu();
            break;

        default :
            cout << "\n\n\t\t\t\t Enter Valid Option Number!!!\n";
    }goto m;

}


void shopping::admin_login() {
    string username, password;
    string user, pass;
    fstream info("information.txt", ios::in);

    if (!info.is_open()) {
        cout << "\n\n\t\t\t\t No Admin Registered!!!\n";
        cout << "\n\n\t\t\t\t Please Register....!!!\n";
        info.close();
        admin_login_menu();
    } else {
        info >> username >> password;
        info.close();

        cout << "\n\n\t\t\t\t Enter Username: ";
        cin >> user;
        cout << "\n\n\t\t\t\t Enter Password: ";
        cin >> pass;

        if (user == username && pass == password) {
            administratior();
        } else {
            cout << "\n\n\t\t\t\t Invalid Username Password!!!\n";
            admin_login_menu();
        }
    }
}

void shopping::admin_register() {
    string username, password;
    string user, pass;
    fstream info("information.txt", ios::in);

    if (info.is_open()) {
        info >> username >> password;
        info.close();

        if (username != " " && password != " ") {
            cout << "\n\n\t\t\t\t Admin Is Already Registered!!!\n";
            cout << "\n\n\t\t\t\t Please Update Or Login.....\n";
            admin_login_menu();
        }
    }

    fstream info_out("information.txt", ios::out);
    cout << "\n\n\t\t\t\t Enter Admin Username: ";
    cin >> user;
    cout << "\n\n\t\t\t\t Enter Admin Password: ";
    cin >> pass;
    info_out << user << " " << pass;
    info_out.close();
    cout << "\n\n\t\t\t\t Admin Registered Successfully!!!\n";
}

void shopping::admin_update() {
    string username, password;
    string user, pass, newuser, newpass;
    fstream info("information.txt", ios::in);

    if (!info.is_open()) {
        cout << "\n\n\t\t\t\t No Admin Registered!!!\n";
        cout << "\n\n\t\t\t\t Please Register....\n";
        info.close();
        admin_login_menu();
    } else {
        info >> username >> password;
        info.close();

        cout << "\n\n\t\t\t\t Enter Current Username And Password To Validate\n";
        cout << "\n\n\t\t\t\t Enter Username: ";
        cin >> user;
        cout << "\n\n\t\t\t\t Enter Password: ";
        cin >> pass;

        if (user == username && pass == password) {
            fstream info1("information1.txt", ios::out);
            cout << "\n\n\t\t\t\t Enter New Username: ";
            cin >> newuser;
            cout << "\n\n\t\t\t\t Enter New Password: ";
            cin >> newpass;
            info1 << newuser << " " << newpass;
            info1.close();
            remove("information.txt");
            rename("information1.txt", "information.txt");
        } else {
            cout << "\n\n\t\t\t\t Invalid Username Password!!!\n";
            admin_login_menu();
        }
    }
}

void shopping :: view(){

        int choice;
        fstream orders;
        int code , quantity ;
        string name;
        float disamount;
        float total = 0;


        orders.open("orders.txt" , ios :: in);
        if(!orders){
            cout << "\n\n\t\t\t\t No Orders Placed!!!\n";
        }
        else{
            cout << setw(30) << "---------------" << setw(30) << "-------------" << setw(30) << "------------------" << setw(30) <<"------------------------" << "\n";
            cout << setw(30) << "Product Number " << setw(30) << "Product Name" << setw(30) << "Product Quantity" << setw(30) << "Amount With Discount" << "\n";
            cout << setw(30) << "---------------" << setw(30) << "-------------" << setw(30) << "------------------" << setw(30) <<"------------------------" << "\n\n";
            orders >> code >> name >> quantity >> disamount;
            while(! orders.eof()){
                cout << setw(30) << code << setw(30) << name << setw(30) << quantity << setw(30) << disamount << "\n";
                total = total + disamount;
                orders >> code >> name >> quantity >> disamount;
            }
            orders.close();
            cout << "\n\n\t\t\t\t Total Money Obtained From All The Orders Placed Are: "<< total << "\n";
        }
        cout << "\n\n\t\t\t\t Press Any Key To Admin Menu: ";
        cin >> choice;

        switch(choice){
            default:
                administratior();
                break;
        }
        
}

void shopping :: administratior(){

    clearscreen();
    m:
    int choice;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|                    ADMINISTRATOR MENU                     |\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|___________________________________________________________|\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";
    cout << "\t\t\t\t\t\t|    1) Add Product         |\n";
    cout << "\t\t\t\t\t\t|    2) Modify Product      |\n";
    cout << "\t\t\t\t\t\t|    3) Remove Product      |\n";
    cout << "\t\t\t\t\t\t|    4) All Orders          |\n";
    cout << "\t\t\t\t\t\t|    5) Main Menu           |\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";

    cout << "\n\n\t\t\t\t Please Enter Your Choice: ";
    cin >> choice;

    switch(choice){
        
        case 1:
            add();
            break;
        
        case 2:
            edit();
            break;

        case 3:
            rem();
            break;

        case 4:
            view();
            break;

        case 5:
            menu();
            break;

        default:
            cout << "Invalid Choice !!!\n\n";
    }
    goto m;
}

void shopping :: buyer(){

    clearscreen();
    m:
    int choice;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|                       BUYERS MENU                         |\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|___________________________________________________________|\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";
    cout << "\t\t\t\t\t\t|    1) Buy Product         |\n";
    cout << "\t\t\t\t\t\t|    2) Main Menu           |\n";
    cout << "\t\t\t\t\t\t|---------------------------|\n";

    cout << "\n\n\t\t\t\t Please Enter Your Choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            receipt();
            break;

        case 2:
            menu();
            break;

        default:
            cout << "Invalid Choice !!!\n\n";
    }goto m;
}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p ;
    float d ;
    string n ;

    cout << "\n\n\t\t\t\t Add New Product";
    cout << "\n\n\t\t\t\t Product Code Of The Product: ";
    cin >> pcode;
    cout << "\n\n\t\t\t\t Name Of The Product: ";
    cin >> pname;
    cout << "\n\n\t\t\t\t Price Of The Product: ";
    cin >> price;
    cout << "\n\n\t\t\t\t Discount On The Product: ";
    cin >> dis;

    data.open("database.txt", ios :: in);

    if(!data){
        data.open("database.txt" , ios :: app | ios :: out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else{
        data >> c >> n >> p >> d;
        while(! data.eof()){
            if(c == pcode){
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if(token == 1){
            cout <<"\n\n\t\t\t\t Duplicate Product Code!!!\n";
            goto m;
        }
        else{
            data.open("database.txt" , ios :: app | ios :: out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t\t\t Record Inserted Successfully.\n\n";
}


void shopping :: edit(){

    fstream data , data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    list();
    cout << "\n\n\t\t\t\t Modify The Record";
    cout << "\n\n\t\t\t\t Product Code: ";
    cin >> pkey;

    data.open("database.txt" , ios :: in);
    if (!data){
        cout << "\n\n\t\t\t\t File Does Not Exist!!";
    }
    else{
        data1.open("database1.txt" , ios :: out | ios :: trunc );

        data >> pcode >> pname >> price >> dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout << "\n\n\t\t\t\t Product New Code: ";
                cin >> c;
                cout << "\n\n\t\t\t\t Product Name: ";
                cin >> n;
                cout << "\n\n\t\t\t\t Price Of The Product: ";
                cin >> p;
                cout << "\n\n\t\t\t\t Discount On The Product: ";
                cin >>d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t\t\t Record Edited Sucessfully \n";
                token++;
            }
            else{
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis ;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt" ,"database.txt");

        if (token == 0){
            cout << "\n\n\t\t\t\t Record Not Found !!!\n\n";
        }
    }
}


void shopping :: rem(){


    fstream data , data1;
    int pkey;
    int token = 0;
    list();
    cout << "\n\n\t\t\t\t Remove Product";
    cout << "\n\n\t\t\t\t Product Code: ";
    cin >> pkey;
    data.open("database.txt" , ios :: in );
    if(!data){
        cout << "\n\n\t\t\t\t File Does Not Exist!!!\n\n";
    }
    else{
        data1.open("database1.txt" , ios :: app | ios :: out);
        data >> pcode >> pname >> price >> dis ;
        while(!data.eof()){
            if(pcode == pkey){
                cout << "\n\n\t\t\t\t Product Removed Sucessfully\n\n";
                token++;
            }
            else{
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis ;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt" , "database.txt");

        if (token == 0){
            cout << "\n\n\t\t\t\t Record Not Found !!!";
        }
    }
}


void shopping::list() {

    fstream data;
    data.open("database.txt", ios::in);

    if (!data) {
        cout << "\n\n\t\t\t\t Empty Database !!!";
    } else {
        cout << "\n\n";
        cout << setw(20) << "---------------" << setw(20) << "----" << setw(20) << "-----" << setw(20) << "--------" << "\n";
        cout << setw(20) << "Product Number" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Discount" << "\n";
        cout << setw(20) << "---------------" << setw(20) << "----" << setw(20) << "-----" << setw(20) << "--------" << "\n";

        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            cout << setw(20) << pcode << setw(20) << pname << setw(20) << price << setw(20) << dis << "\n";
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }
}

void shopping::receipt() {

    clearscreen();
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT \n";
    data.open("database.txt", ios::in);

    if (!data) {
        cout << "\n\n\t\t\t\t Empty Database !!!";
    } else {
        data.close();
        list();
        fstream orders("orders.txt", ios::app);

        do {
            
            cout << "\n\n\t\t\t\t Enter The Product Code: ";
            cin >> arrc[c];
            cout << "\n\n\t\t\t\t Enter The Quantity: ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n\t\t\t\t Duplicate Product Code !!! \n";
                    cout << "\n\n\t\t\t\t Please Try Again!!! \n";
                    goto m;
                }
            }

            c++;
            m:
            cout << "\n\n\t\t\t\t Do You Want To Add More Product ? (y/n): ";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n";
        cout << setw(20) << "---------------" << setw(20) << "-------------" << setw(20) << "------------------" << setw(20) << "--------------" << setw(20) << "------" << setw(30) << "------------------------" << "\n";
        cout << setw(20) << "Product Number " << setw(20) << "Product Name" << setw(20) << "Product Quantity" << setw(20) << "Product Price" << setw(20) << "Amount" << setw(30) << "Amount With Discount" << "\n";
        cout << setw(20) << "---------------" << setw(20) << "-------------" << setw(20) << "------------------" << setw(20) << "--------------" << setw(20) << "------" << setw(30) << "------------------------" << "\n\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    dis = amount - ((amount) * dis / 100);
                    total = total + dis;
                    cout << setw(20) << pcode << setw(20) << pname << setw(20) << arrq[i] << setw(20) << price << setw(20) << amount << setw(30) << dis << "\n";

                    orders << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << dis << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        orders.close();
    }

    cout << "|---------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << "\t\t\t\t\t\t | Total Amount: " << total << " |\n";
    cout << "|---------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << "|---------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << "\t\t\t\t\t\t |.....PLEASE VISIT AGAIN.....|\n";
    cout << "|---------------------------------------------------------------------------------------------------------------------------------|\n";

    
}

void shopping :: clearscreen() {
    for (int i = 0; i < 50; ++i) {
        cout << "\n";
    }
}

int main(){

    shopping s;
    s.menu();
    return 0;
}