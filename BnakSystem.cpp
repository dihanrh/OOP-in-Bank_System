#include <bits/stdc++.h>
using namespace std;
 
class bank_system
{
private:
    string name, f_name, m_name, bdate, phone_no;
 
    float dep, bal;
 
public:
    int d, b;
    string n, bd;
 
    void create_acc_info()
    {
        ofstream file;
        file.open("user.txt", ios ::out | ios ::app);
 
        cout << "<<<<<<<<<<<<<<<<<<<<*****Welcome to A2Z Bank*****>>>>>>>>>>>>>>>>>>>>" << endl
             << endl;
        cout << "Enter Your Full Name                  :";
        getline(cin, name);
        cout << "Enter Your Father name                :";
        getline(cin, f_name);
        cout << "Enter Your Mother name                :";
        getline(cin, m_name);
        cout << "Enter Your Date of Birth (DD-MM-YYYY) :";
        cin >> bdate;
        cout << "Enter Your Phone number (01xxxxxxx)   :";
        cin >> phone_no;
        n = name;
        bd = bdate;
        file << endl
             << "<<<<<<<<<<<<<<<<<*****User info*****>>>>>>>>>>>>>>>>>>"
             << endl
             << "Full Name                  :" << name
             << endl
             << "Father name                :" << f_name
             << endl
             << "Mother name                :" << m_name
             << endl
             << "Date of Birth (DD-MM-YYYY) :" << bdate
             << endl
             << "Phone number (01xxxxxxx)   :" << phone_no;
 
        file.close();
    }
    int call_verify()
    {
        string udate;
        cout << "<<<<<<<<<<<<<<<<***Verification****>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << "Hello," << n << " Enter Your Birthdate :";
        cin >> udate;
 
        if (udate == bd)
            return 1;
        else
            return 0;
    }
    void activation_msg()
    {
        cout << endl
 
             << "<<<<<<<<<<<<<<<<<<<<***Congratulation !!!"
             << " " << n << " "
             << ",your Debit Card has been activated***>>>>>>>>>>>>>>"
             << endl
             << endl
             << "<<<<<<<<<<<<<<<< SMS >>>>>>>>>>>>>>>>>>>>>>>>>"
             << endl
 
             << "Your PIN is : 98752" << endl
             << "Please Do not Share Your PIN"
             << endl
             << "Thank You for Banking with us ";
        ofstream file;
        file.open("user.txt", ios ::out | ios ::app);
        file << "Verification               :Succeded " << endl;
        file.close();
    }
    void not_confirmed()
    {
        cout << endl
             << "=========Sorry,Your data has not been matched.Activation declined!============";
    }
    void activation()
    {
        if (call_verify() == 1)
            activation_msg();
        else
            not_confirmed();
    }
    void thanks_giving()
    {
        cout << endl
             << "Thank You For Banking With Us" << endl;
    }
};
 
class user_action : public bank_system
{
public:
    void display_msg()
    {
        cout << endl
             << "<<<<<<<<<<<<***Congratulation !!! Your account has been created***>>>>>>>>>>>>>" << endl
             << "Your Account number is :012345" << endl  ;
    }
    void t_action()
    {
        cout << "Select what you want to do :" << endl;
        int num;
        cout << "1 for deposite " << endl
             << "2 for available balance " << endl;
 
        cin >> num;
 
        switch (num)
        {
        case 1:
            cout << "Enter amount you want to deposite :" << endl;
            cin >> d;
            cout << "You have deposited :" << d << endl;
            break;
        case 2:
            cout << "Available balance is :" << d << endl;
 
        default:
            cout << "Enter correct information " << endl;
            break;
        }
 
        ofstream file;
        file.open("user.txt", ios ::out | ios ::app);
        file << endl
 
             << "Account number is          :012345" << endl
             << "Deposited                  :" << d << endl;
        file.close();
    }
    int apply_card()
    {
        ofstream file;
        file.open("user.txt", ios ::out | ios ::app);
 
        int card;
        cout << "Do you want to apply for Debit Card ? (Yes : 1/No : 0 ) :  ";
        cin >> card;
 
        if (card == 1)
        {
            cout << "Your Debit Card application hass been submitted" << endl
                 << endl;
            file << "Card Application           :Submitted " << endl;
            file.close();
            return 1;
        }
        else
        {
            cout << "Your Debit Crad application has been canceled " << endl;
            file << "Card Application : Canceled ";
            file.close();
            return 0;
        }
    }
};
 
void user_file()
{
    cout << endl ;
    string info;
 
    ifstream file("user.txt", ios ::in);
 
    while (getline(file, info))
    {
        cout << info << endl;
    }
}
 
int main()
{
    bank_system user;
    user.create_acc_info();
    user_action display;
    display.display_msg();
    display.t_action();
    if (display.apply_card() == 1)
    {
        user.activation();
        user_file();
    }
    else
        user.thanks_giving();
 
    return 0;
}