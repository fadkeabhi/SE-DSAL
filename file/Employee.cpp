#include <iostream>
#include <fstream>
using namespace std;

class Data
{
public:
    char name[10];
    int id;

    void set()
    {
        cout << "Enter Name : ";
        cin.getline(name, 20);
        cout << "Enter Id : ";
        cin >> id;
        cin.ignore();
    }

    void display()
    {
        cout << id << " " << name << '\n';
    }
};

class FileHandling
{
    char filename[20] = "record.DAT";
    fstream fp;
    fstream fp2;

public:
    void save()
    {
        Data record;
        record.set();
        fp.open(filename, ios::out | ios::app);
        fp.write((char *)&record, sizeof(record));
        fp.close();
    }

    void search()
    {
        Data record;
        fp.open(filename, ios::in);
        int id;
        bool found = 0;
        cout << "Enter An Id: ";
        cin >> id;
        while (fp.read((char *)&record, sizeof(record)))
        {
            if (record.id == id)
            {
                found = 1;
                cout << "Record found.";
                record.display();
            }
        }
        if (!found)
        {
            cout << "Record Not Found.";
        }
        fp.close();
    }


    void displayAll()
    {
        Data record;
        fp.open(filename, ios::in);
        // fp.seekg(0,ios::beg);
        while (fp.read((char *)&record, sizeof(record)))
        {
                record.display();
        }
        fp.close();
    }

    void update()
    {
        Data record;
        fp.open(filename, ios::in | ios::out);
        fp2.open("tmp.DAT", ios::out);
        int id;
        bool found = 0;
        cout << "Enter An Id: ";
        cin >> id;
        while (fp.read((char *)&record, sizeof(record)))
        {
            if (record.id == id)
            {
                found = 1;
                cout << "Record found.";
                record.display();
                cin.ignore();
                cout << "Enter New Name: ";
                cin.getline(record.name, 20);
            }
            fp2.write((char *)&record, sizeof(record));
        }
        if (!found)
        {
            cout << "Record Not Found.";
        }
        fp.close();
        fp2.close();

        remove(filename);
        rename("tmp.DAT",filename);
    }
};

int main()
{
    FileHandling obj;

    //implement menu here
    obj.displayAll();
    obj.update();
    obj.displayAll();
    return 0;
}