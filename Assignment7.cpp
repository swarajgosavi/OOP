#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class data{
private:
    char name[10];
    int roll;
public:
    void readdata();
    void writedata();
};

void data :: readdata(){
    cout << "Enter Name : "; cin >> name;
    cout << "Enter Roll No : "; cin >> roll;
}

void data :: writedata(){
    cout << setiosflags(ios::left)
        << setw(10) << name
        << setw(10) << roll
        << endl;
}

int main(){
    data st[3];

    int n;
    cout << "Enter total number of students : ";
    cin >> n;

    fstream file;

    file.open("Data.txt", ios::out);

    cout << "Enter Details of " << n << " Students : \n";
    for(int i=0; i<n; i++){
        st[i].readdata();
        file.write((char *)& st[i], sizeof(st[i]));
    }
    file.close();

    file.open("Data.txt", ios::in);

    cout << "\nOUTPUT\n\n";
    cout << setiosflags(ios::left)
        << setw(10) << "Name"
        << setw(10) << "Roll No."
        << endl;
    for(int i=0; i<n; i++){
        file.read((char *)& st[i], sizeof(st[i]));
        st[i].writedata();
    }
    file.close();
    return 0;
}