#include<iostream>
#include<thread>
#include<chrono>
#include<limits>
using namespace std;

class studentmanagementsystem{
    int completed;
    
    struct student{
        string id,name,fname,add;
        long long mobileno;
    };
    student students[100];

    public:

    studentmanagementsystem() {completed=0;}
    void option();
    void addnewstudent();
    void display();
    void searchstudent();
    void update();
    void deletestudent();
    
};
void studentmanagementsystem::option(){
    char select;
    while(true){
        cout<<"\n=====student menu=====\n";
        cout<<"\n1.add student";
        cout<<"\n2.display information" ;
        cout<<"\n3.search student";
        cout<<"\n4.update";
        cout<<"\n5.deletestudent";
        cout<<"\n6.logout";
        cout<<"\n7.exit";
        cout<<"\nenter choice";
        cin>>select;

        switch(select){
            case '1': addnewstudent(); break;
            case '2': display(); break;
            case '3': searchstudent(); break;
            case '4': update(); break;
            case '5': deletestudent(); break;
            case '6': return;
            case '7': exit(0);
        }
    }
}
void studentmanagementsystem::addnewstudent(){
    cout<<"\nadding new student";
    cout<<"\n enter the detail of student"<<completed+1;
    cout<<"\nenter the student id=";
    cin>>students[completed].id;
    cout<<"\nenter the name of student=";
    cin.ignore();
    getline(cin,students[completed].name);
    cout<<"\nenter the name of father name=";
    getline(cin,students[completed].fname);
    cout<<"\nenter the address=";
    getline(cin,students[completed].add);
    cout<<"\nenter the mobileno=";
    while(!(cin>>students[completed].mobileno)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\nenvailid number! enter again:";
    }
    completed++;
    cout<<"\nstudent added successfully";
}

void studentmanagementsystem::display(){
    if(completed==0){
        cout<<"\nstudent record not found";
        return;
    }
    cout<<"\n====student record list====";
    for(int i=0; i<completed; i++){
    cout<<"\nstudent"<< i+1 << ":\n";
    cout<<"1. id="<<students[i].id<<endl;
    cout<<"2. name="<<students[i].name<<endl;
    cout<<"3. fname="<<students[i].fname<<endl;
    cout<<"4. add="<<students[i].add<<endl;
    cout<<"5. mobileno="<<students[i].mobileno<<endl;
    }
}
void studentmanagementsystem::searchstudent(){
    if(completed==0){
        cout<<"\nrecord not found";
        return;
    }

    string searchid;
    cout<<"\nenter student id";
    cin>>searchid;

    bool found=false;
    for(int i=0; i<completed; i++){
        if(students[i].id==searchid){
             found=true;

            cout<<"1. id"<<students[i].id<<endl;
            cout<<"2. id"<<students[i].name<<endl;
            cout<<"3. id"<<students[i].fname<<endl;
            cout<<"4. id"<<students[i].add<<endl;
            cout<<"5. id"<<students[i].mobileno<<endl;
            return;
        }
    }
    if(!found){
        cout<<"\nstudent id not found";
    }
}
void studentmanagementsystem::update(){
    if(completed==0){
        cout<<"\nrecord not found";
        return;
    }
    string searchid;
    cout<<"\nenter id to update";
    cin>>searchid;
    bool found=false;

    for(int i=0; i<completed; i++){
        if(students[i].id==searchid){
            found=true;

            cout<<"\nstudent found what do you want to update";
            cout<<"\n1.name";
            cout<<"\n2.fname";
            cout<<"\n3.add";
            cout<<"\n4.mobileno";

            int choice;
            cin>>choice;
            cin.ignore();

            switch(choice){
                case 1:
                cout<<"\nenter the new name";
                cin>>students[i].name;
                break;

                case 2:
                cout<<"\nenter the new fname";
                cin>>students[i].fname;
                break;
                
                case 3:
                cout<<"\nenter the new add";
                cin>>students[i].add;
                break;

                case 4:
                cout<<"\nenter the new mobileno";
                cin>>students[i].mobileno;
                break;
                default:
                cout<<"\ninvalide choice";
            }
            cout<<"\nstudent updated successfully";
            return;
        } 
    }
       
        if(!found){
            cout<<"\nstudent record not found"; 

    }
}

void studentmanagementsystem::deletestudent(){
    if(completed==0){
        cout<<"\nstudent record not found";
        return;
    }

    string searchid;
    cout<<"\nenter to search id";
    cin>>searchid;

    for(int i=0; i<completed; i++){
        if(students[i].id==searchid){
            for(int j=i; j<completed; j++){
                students[j]=students[j+1];
            }
            completed--;
            cout<<"\nstudent record deleted successfully";
            return;
        }
    }
    cout<<"\nstudent record not found";
}

int main(){
    string id, conformid;
    int password,conformpassword;

    cout<<"\n=====wellcome to student managemet system=====\n";


    cout<<"\nsingh up here\n";


    cout<<"\nenter the id=";
    cin>>id;
    cout<<"\nenter the password=";
    cin>>password;

    cout<<"\ncreating the account";
    for(int i=0; i<4; i++){
        cout<<"."<<flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout<<"\naccount created successfully\n"<<endl;
    system("clear");
    
    bool loggedin=false;

    while(!loggedin){
        cout<<"\nenter the conform id=";
        cin>>conformid;
        cout<<"\nenter the conformpassword=";
        cin>>conformpassword;
        
        if(id==conformid && password==conformpassword){
            cout<<"\nlogin successfully"<<endl;
            loggedin=true;
            system("clear");

            studentmanagementsystem obj;
            obj.option();
        }
        else{
            if(id!=conformid){
                cout<<"\nplease enter the vailide id";
            }
            if(password!=conformpassword){
                cout<<"\nenter the vailide password";
            }
        }
    }
    return 0;
}