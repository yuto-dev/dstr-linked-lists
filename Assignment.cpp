#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

void doctorMenu();
void nurseMenu();
bool nurseLogin(string username, string password);

string nurseUsername = "abc", nursePassword = "123";

struct patient_data
{
    string id, firstName, lastName, gender, phone, address, visitDate, visitTime, disabilityOption;
    int age;


};

struct Node
{
    patient_data data;
    struct Node* prev;
    struct Node* next;

};
struct Node* head = NULL;

struct treatNode
{
    patient_data data;
    struct treatNode* prev;
    struct treatNode* next;

};
struct treatNode* treatHead = NULL;

patient_data addPatient();
void displayPatient();
Node* searchPatientbyID();
void removePatient();
void treatPatient();
void sortPatient();
void ascSort();
int patientCount();

void insertAtEnd(patient_data data)       
{
    //Node* new_node = new Node();

    //Node* last = *head;

    //new_node->data = data;

    //new_node->next = NULL;

    //if (*head == NULL)
    //{
    //    new_node->prev = NULL;
    //    *head = new_node;
    //    return;

    //}

    //while (last->next != NULL)
    //{
    //    last = last->next;
    //    last->next = new_node;

    //    new_node->prev = last;
    //    return;
    //}
    Node* temp = new Node;

    struct Node* trav;
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    trav = head;

    if (head== NULL)
    {
        head = temp;
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;

        }
        temp->prev = trav;
        trav->next = temp;
    }

    

}

void start_menu()
{
    int selection = 0;
    cout << "************************************************************** \n";
    cout << "Welcome to Start Menu \n";
    cout << " Please choose from the following options - \n";
    cout << " 1. Nurse Login.\n";
    cout << " 2. Doctor Login.\n";
    cout << " 3. None.\n";
    cout << " 4. None.\n";
    cout << " 5. Exit.\n";
    cout << "\n Selection \t:";
    cin >> selection;
    //cout << "************************************************************** \n";



    switch (selection)
    {
        case 1:     //nurse login 
        {

            cin.clear();
            cin.ignore();
            system("CLS");

            if (nurseLogin(nurseUsername, nursePassword))
            {


                nurseMenu();
            }
            else
            {

                cin.clear();
                cin.ignore();
                system("CLS");
                cout << "\n\t\tUSERNAME OR PASSWORD NOT RECOGNISED\n\n";

                start_menu();
            }

            




        }
        break;

        case 2:     //doctor login
        {

            cin.clear();
            cin.ignore();
            system("CLS");

            cout << "chosen2";

        }
        break;

        case 3:     //none
        {
            cout << "Not yet added!";

        }
        break;

        case 4:     //none
        {
            cout << "Not yet added!";
        }
        break;

        case 5:     //exit program
        {

            cin.clear();
            cin.ignore();
            system("CLS");

            cout << "\t\tProgram ended. \n\t\tSee you next time!\n\n\n\n";
            exit(0);
        }
        break;



        default:        //other input than 1 or 2 or 5
        {

            cin.clear();
            cin.ignore();
            system("CLS");

            cout << "\n\t\tInvalid Option. Try Again.\n\n";
            start_menu();
        }
            break;
    }






}

bool nurseLogin(string username, string password)
{

    string inputUsername, inputPassword;
    cout << " Please enter username - ";
    cin >> inputUsername;
    cout << endl;
    cout << " Please enter password - ";
    cin >> inputPassword;

    if (username != inputUsername | password != inputPassword)
    {
        cout << " USERNAME OR PASSWORD NOT RECOGNISED\n";

        return false;
    }
    else
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        cout << " Login Credentials Accepted\n";
       
        return true;

    }



}

void nurseMenu()
{
    int selection = 0;
    cout << "************************************************************** \n";
    cout << "Welcome to Nurse Menu \n";
    cout << " Please choose from the following options - \n";
    cout << " 1. Add Patient.\n";
    cout << " 2. Sort Patient.\n";
    cout << " 3. Display Patient.\n";
    cout << " 4. Treat Patient.\n";
    cout << " 5. Remove Patient.\n";
    cout << " 6. Sort Patient by Page (ascending).\n";
    cout << " 7. Exit.\n";

    cout << "Current Patient Queue Count :" << patientCount() << endl;

    cout << "\n Selection \t:";
    cin >> selection;
    //cout << "************************************************************** \n";



    switch (selection)
    {
    case 1:     //add patient
    {
        insertAtEnd(addPatient());

        cout << "\n\tPatient added!\n";
        cin.clear();
        cin.ignore();
        system("CLS");
        nurseMenu();


       // Node* current = head;
       // while (current!=NULL)
       // {
       //     cout << current->data.age << endl;
       //     current = current->next;
       // }
       //// cout << head->next->next << endl;


    }
    break;

    case 2:     //sort patient
    {

        cin.clear();
        cin.ignore();
        system("CLS");

        sortPatient();
        //nurseMenu();
        cout << "Patient sorted." << endl;
        nurseMenu();

    }
    break;

    case 3:     //display patient
    {
        displayPatient();

 
        system("CLS");

        nurseMenu();

    }
    break;

    case 4:     //treat patient
    {
        treatPatient();
    }
    break;

    case 5:     //remove patient
    {
        system("CLS");
        removePatient();


    }
    break;

    case 6:     //sort patient by page (ascending)
    {
        ascSort();
        system("CLS");
        nurseMenu();
    }
    break;

    case 7:     //logout
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        start_menu();
    }
    break;



    default:        //other input than 1-7
    {

        cin.clear();
        cin.ignore();
        system("CLS");

        cout << "\n\t\tInvalid Option. Try Again.\n\n";
        nurseMenu();
    }
    break;
    }







}

patient_data addPatient()
{
    cin.clear();
    cin.ignore();
    system("CLS");

    string Fname, Lname, gender, phone, address, visitDate, visitTime, disabilityOption;
    int age;



    cout << "Enter first name :";
    cin >> Fname;

    cout << "\nEnter last name :";
    cin >> Lname;

    cout << "\nEnter gender (M/F) :";
    cin >> gender;

    cout << "\n Enter age :";
    cin >> age;

    cout << "\nEnter phone number (xxx-xxxxxxx) :";
    cin.ignore();
    std::getline(std::cin, phone);

    cout << "\nEnter address (No space bar allowed.) :";
    getline(cin, address);
 
    cout << "\nEnter visit date (DD.MM.YYYY) :";
    cin >> visitDate;

    cout << "\nEnter visit time (24Hour FORMAT) (HH.MM):";
    cin >> visitTime;

    cout << "\nEnter disability option (yes/no) :";
    cin >> disabilityOption;
    
    Node* current;
    current = head;
    int count = 0;
    if (head!= NULL)
    {
        while (current!=NULL)
        {
            count = count + 1;
            current = current->next;
        }
    }
    string patientID = "P" + to_string(count);



    patient_data add;
    add.id = patientID;
    add.firstName = Fname;
    add.lastName = Lname;
    add.gender = gender;
    add.age = age;
    add.phone = phone;
    add.address = address;
    add.visitDate = visitDate;
    add.visitTime = visitTime;
    add.disabilityOption = disabilityOption;

    cin.clear();
    cin.ignore();
    system("CLS");
    return add;

}


const char separator = ' ';
const int largeWidth = 23;
const int midWidth = 15;
const int smallWidth = 8;

template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}

void displayPatient()
{
    cin.clear();
    cin.ignore();
    system("CLS");

    if (head == NULL)
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        cout << "\n List is empty.\n";
        nurseMenu();
    }

    Node* current = head;


    cout << "**************************************************************\n";
    cout << "Patient List    :\n";
    //cout << "\n ID\t"<<"Name\t\t\t\t" << "Gender \t" << "Phone \t\t" << "Address \t\t\t" << "Visit Date \t\t" << "Visit Time \t\t" << "Disability Option \t\n";

    printElement("ID ", smallWidth);
    printElement("Name", largeWidth);
    printElement("Gender", smallWidth);
    printElement("Phone", midWidth);
    printElement("Visit Date", midWidth);
    printElement("Visit Time", midWidth);
    printElement("Disability Option", midWidth);
    cout << endl;

    
    while (current!=NULL)
    {
        //cout <<" "<< current->data.id << "\t" << current->data.firstName << " " << current->data.lastName << "\t\t" << current->data.gender << "\t" << current->data.phone << "\t\t" << current->data.address << "\t\t"
        //    << current->data.visitDate << "\t\t" << current->data.visitTime << "\t\t\t" << current->data.disabilityOption << "\t\n";

        printElement(current->data.id, smallWidth);
        printElement((current->data.firstName)+" "+ (current->data.lastName), largeWidth);
        printElement(current->data.gender, smallWidth);
        printElement(current->data.phone, midWidth);
        printElement(current->data.visitDate, midWidth);
        printElement(current->data.visitTime, midWidth);
        printElement(current->data.disabilityOption, midWidth);
        cout << endl;

        current = current->next;
    }

    cout << "\n\n";
    system("pause");



}

Node* searchPatientbyID( string id)
{
    Node* temp = head;
    Node* found;
    int pos = 0;

    if (head == NULL)
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        cout << "\n List is empty.\n";
        nurseMenu();
    }


    while (temp->data.id !=id && temp->next != NULL)
    {
        pos++;
        temp = temp->next;
    }

    if (temp->data.id != id)
    {
        cout << "Not found\n\n";
        nurseMenu();
    }

    found = temp;
    return found;

}

void removePatient()
{
    string id;
    cout << "Enter Patient ID to be deleted :";
    cin >> id;
    
    struct Node* deleteNode;
    deleteNode = searchPatientbyID(id);


    if (head == NULL)
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        cout << "\n List is empty.\n";
        nurseMenu();
    }

    if (head == deleteNode)
    {
        head = deleteNode->next;
    }

    if (deleteNode->next != NULL)
    {
        deleteNode->next->prev = deleteNode->prev;
    }

    if (deleteNode->prev != NULL)
    {
        deleteNode->prev->next = deleteNode->next;
    }


    cin.clear();
    cin.ignore();
    system("CLS");

    cout << "\n Patient ID of " << deleteNode->data.id << " , has been deleted.\n"; 
    nurseMenu();

    free(deleteNode);


}

void treatPatient()
{
    struct Node* deleteNode;
    deleteNode = head;
    struct treatNode* temp = new treatNode;
    struct treatNode* trav;

    if (head == NULL)
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        cout << "\n List is empty.\n";
        nurseMenu();
    }


    if (head == deleteNode)
    {
        head = deleteNode->next;
    }

    

    //moves delete nodes to treatedList
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = deleteNode->data;
    trav = treatHead;


    if (treatHead == NULL)
    {
        treatHead = temp;
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;

        }
        temp->prev = trav;
        trav->next = temp;
    }




    cin.clear();
    cin.ignore();
    system("CLS");

    cout << "\n Patient ID of " << deleteNode->data.id <<"("<<deleteNode->data.firstName<<" "<<deleteNode->data.lastName<<")" << " , has been treated.\n";

    nurseMenu();

    free(deleteNode);




}

void sortPatient()
{
    int swapped;
    Node* current = head;
    Node* temp = NULL;

    if (head == NULL)
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        cout << "\n List is empty.\n";
        nurseMenu();
    }

    do            //bubble sort
    {
        swapped = 0;
        current = head;

        while (current->next != temp)
        {
            int near; int later;
            vector<string> date_v1;
            vector<string> date_v2;
            stringstream s1(current->data.visitDate);
            while (s1.good())
            {
                string substr;
                getline(s1, substr, '.');
                date_v1.push_back(substr);
            }

            stringstream s2(current->next->data.visitDate);
            while (s2.good())
            {
                string substr;
                getline(s2, substr, '.');
                date_v2.push_back(substr);
            }


            if (date_v1[1] > date_v2[1])              //comparing by month
            {
                swap(current->data, current->next->data);
                swapped = 1;
            }
            else if (date_v1[1] == date_v2[1])              //comparing by date
            {
                if (date_v1[0] > date_v2[0])
                {
                    swap(current->data, current->next->data);
                    swapped = 1;

                }
                else if (date_v1[0] == date_v2[0])  //comparing by time
                {
                    int soon, late;
                    vector<string> time_v1;
                    vector<string> time_v2;
                    stringstream ss1(current->data.visitTime);
                    while (ss1.good())
                    {
                        string substr;
                        getline(ss1, substr, '.');
                        time_v1.push_back(substr);
                    }

                    stringstream ss2(current->next->data.visitTime);
                    while (ss2.good())
                    {
                        string substr;
                        getline(ss2, substr, '.');
                        time_v2.push_back(substr);
                    }

                    if (time_v1[0] > time_v2[0]) //comparing by hour
                    {
                        swap(current->data, current->next->data);
                        swapped = 1;
                    }
                    else if (time_v1[0] == time_v2[0])  //comparing by minutes
                    {
                        int now, comparing;
                        
                        if (current->data.disabilityOption == "yes")    //comparing by disability option
                        {
                            now = 1;
                        }
                        else
                        {
                            now = 0;
                        }

                        if (current->next->data.disabilityOption=="yes")
                        {
                            comparing = 1;
                        }
                        else
                        {
                            comparing = 0;
                        }



                        if (now < comparing )
                        {
                            swap(current->data, current->next->data);
                            swapped = 1;
                        }
                        else if (now = comparing)       //comparing by time if both disbility options are the same.
                        {

                            if (time_v1[1] > time_v2[1])
                            {
                                swap(current->data, current->next->data);
                                swapped = 1;
                            }
                        }
                    }
                }
            }
            current = current->next;
        }
        temp = current;

    } while (swapped);

    return;
    //    swapped = 0;
    //    current = head;

    //    while (current->next != temp)
    //    {
    //        int now, comparing;
    //
    //        if (current->data.disabilityOption == "yes")
    //        {
    //            now = 1;
    //        }
    //        else
    //        {
    //            now = 0;
    //        }
   
    //        if (current->next->data.disabilityOption=="yes")
    //        {
    //            comparing = 1;
    //        }
    //        else
    //        {
    //            comparing = 0;
    //        }



    //        if (now < comparing )
    //        {
    //            swap(current->data, current->next->data);
    //            swapped = 1;
    //        }
    //        else if (now = comparing)           //filter by date and time
    //        {
    //            int near, later;
    //            vector<string> date_v1;
    //            vector<string> date_v2;
    //            stringstream s1(current->data.visitDate);
    //            while (s1.good())
    //            {
    //                string substr;
    //                getline(s1, substr, '.');
    //                date_v1.push_back(substr);
    //            }

    //            stringstream s2(current->next->data.visitDate);
    //            while (s2.good())
    //            {
    //                string substr;
    //                getline(s2, substr, '.');
    //                date_v2.push_back(substr);
    //            }


    //            if (date_v1[1]> date_v2[1] )              //comparing by month
    //            {
    //                swap(current->data, current->next->data);
    //                swapped = 1;
    //            }
    //            else if (date_v1[1]==date_v2[1])              //comparing by date
    //            {
    //                if (date_v1[0]>date_v2[0])            
    //                {
    //                    swap(current->data, current->next->data);
    //                    swapped = 1;

    //                }
    //                else if (date_v1[0] == date_v2[0])  //comparing by time
    //                {
    //                    int soon, late;
    //                    vector<string> time_v1;
    //                    vector<string> time_v2;
    //                    stringstream ss1(current->data.visitTime);
    //                    while (ss1.good())
    //                    {
    //                        string substr;
    //                        getline(ss1, substr, '.');
    //                        time_v1.push_back(substr);
    //                    }

    //                    stringstream ss2(current->next->data.visitTime);
    //                    while (ss2.good())
    //                    {
    //                        string substr;
    //                        getline(ss2, substr, '.');
    //                        time_v2.push_back(substr);
    //                    }

    //                    if (time_v1[0]> time_v2[0]) //comparing by hour
    //                    {
    //                        swap(current->data, current->next->data);
    //                        swapped = 1;
    //                    }
    //                    else if (time_v1[0] == time_v2[0])  //comparing by minutes
    //                    {
    //                        if (time_v1[1] > time_v2[1])
    //                        {
    //                            swap(current->data, current->next->data);
    //                            swapped = 1;
    //                        }


    //                    }





    //                }

    //            }
    //            



    //        }
    //        current = current->next;

    //    }
    //    temp = current;

    //} while (swapped);





    //while (current->next!=NULL)
    //{
    //    int now, comparing;
    //    
    //    if (current->data.disabilityOption == "yes")
    //    {
    //        now = 1;
    //    }
    //    else
    //    {
    //        now = 0;
    //    }
    //   
    //    if (current->next->data.disabilityOption=="yes")
    //    {
    //        comparing = 1;
    //    }
    //    else
    //    {
    //        comparing = 0;
    //    }


    //    if (now > comparing || now == comparing)
    //    {
    //        current = current->next;
    //    }

 

    //    if (now < comparing)
    //    {
    //        //Node* changing_node = new Node();
    //        //changing_node->data = current->data;
    //        //changing_node->next = current->next->next;
    //        //changing_node->prev = current->next->prev;

    //        //current->next->prev = current->prev;
    //        //current->next->next = current->next;

    //        //current = current->next;

    //        //current->next = changing_node;
    //        patient_data swap_data = current->data;
    //        current->data = current->next->data;
    //        current->next->data = swap_data;

    //        


    //    }
    //    current = current->next;

    //}
   
    
}

void ascSort()
{
    sortPatient();

    if (head == NULL)
    {
        cin.clear();
        cin.ignore();
        system("CLS");

        cout << "\n List is empty.\n";
        nurseMenu();
    }

    system("CLS");
    Node* current;

    current = head;

    int i = 1, decision = 1;

    while (decision!=0)
    {
        //cout << "\tPatient Details :" << endl;
        //cout << setw(10) << ' ' << "Patient ID\t:" << current->data.id << endl;
        //cout << setw(10) << ' ' << "First Name\t:" << current->data.firstName << endl;
        //cout << setw(10) << ' ' << "Last Name\t:" << current->data.lastName << endl;
        //cout << setw(10) << ' ' << "Age\t:" << to_string(current->data.age) << endl;
        //cout << setw(10) << ' ' << "Gender\t:" << current->data.gender << endl;
        //cout << setw(10) << ' ' << "Phone\t:" << current->data.phone << endl;
        //cout << setw(10) << ' ' << "Address\t:" << current->data.address << endl;
        //cout << setw(10) << ' ' << "Visit Date\t:" << current->data.visitDate << endl;
        //cout << setw(10) << ' ' << "Visit Time\t:" << current->data.visitTime << endl;
        //cout << setw(10) << ' ' << "Disability Option \t:" << current->data.disabilityOption << endl;
        
        printElement(" ", largeWidth);
        printElement("Position ", largeWidth);
        cout << ": ";
        printElement(i, smallWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("ID ", largeWidth);
        cout << ": ";
        printElement(current->data.id, smallWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("Name ", largeWidth);
        cout << ": ";
        printElement((current->data.firstName) + " " + (current->data.lastName), largeWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("Gender ", largeWidth);
        cout << ": ";
        printElement(current->data.gender, smallWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("Phone ", largeWidth);
        cout << ": ";
        printElement(current->data.phone, midWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("Address ", largeWidth);
        cout << ": ";
        printElement(current->data.address, largeWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("Visit Date ", largeWidth);
        cout << ": ";
        printElement(current->data.visitDate, midWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("Visit Time ", largeWidth);
        cout << ": ";
        printElement(current->data.visitTime, midWidth);
        cout << endl;

        printElement(" ", largeWidth);
        printElement("Disability Option ", largeWidth);
        cout << ": ";
        printElement(current->data.disabilityOption, midWidth);
        cout << endl;

        cout << endl;

        cout << "\n\n\n 1.Next |\t2. Previous |\t0.Exit to Menu |\n";
        cout << "Select :";
        cin >> decision;
        cin.ignore();

        switch (decision)
        {
        case 1:
            if (current->next != NULL)
            {
                current = current->next;
                i++;


            }
            else
            {
                cout << "There is no more patient!" << endl;
                system("pause");
            }
            break;

        case 2:
            if (current->prev != NULL)
            {
                current = current->prev;
                i--;
            }
            else
            {
                cout << "There is no more patient!" << endl;
                system("pause");
            }
            break;
        case 0:
            return;

        default:
            cout << "Invalid Option, try again." << endl;
            system("pause");

        }
        system("CLS");
    }


}

int patientCount()
{
    Node* current;
    current = head;
    int count = 0;
    if (head != NULL)
    {
        while (current != NULL)
        {
            count = count + 1;
            current = current->next;
        }
    }
    return count;
}

void addDummyData()
{
     string dummy[10][9] = { {"LeBron","James", "M", "39", "012-3456789", "19 Ridgewood Court Clarkston, MI 48348", "11.11.2021", "11.10", "no"},
     {"Carmelo","Anthony", "M", "38", "012-3499812", "454 Arch St. Quakertown, PA 18951", "10.11.2021", "11.10", "no"} ,
     {"Anthony","Davis", "M", "35", "012-3433439", "8117 Shore St. Matawan, NJ 07747", "09.11.2021", "11.10", "yes"} ,
     {"Russell","Westbrook", "M", "33", "012-377689", "9 Glen Eagles Dr. Banning, CA 92220", "08.11.2021", "11.10", "yes"} ,
     {"DeAndre","Jordan", "M", "36", "012-3223289", "7197 Holly Lane Schererville, IN 46375", "08.11.2021", "11.20", "yes"},
      {"Horton","Tucker", "M", "36", "012-3019999", "8039 North Marlborough Ave. Muskogee, OK 74403", "08.11.2021", "10.21", "yes"} ,
     {"Advery","Bradley", "M", "33", "012-3556689", "84 East Johnson Street Patchogue, NY 11772", "08.11.2021", "09.11", "no"}, 
      {"Kent","Bazemore", "M", "27", "012-3334569", "794 Proctor Drive Madison, AL 35758", "10.11.2021", "18.26", "no"}, 
      {"Trevor","Ariza", "M", "37", "012-4456789", "8357 Mayfair St. Macon, GA 31204", "09.11.2021", "10.01", "yes"}, 
      {"Dwight","Howard", "M", "35", "012-5577991", "8 Maple Street West Haven, CT 06516", "23.11.2021", "21.11", "no"} };



     for (int a = 0; a < 10; a++)
     {

             Node* current;
             current = head;
             int count = 0;
             if (head != NULL)
             {
                 while (current != NULL)
                 {
                     count = count + 1;
                     current = current->next;
                 }
             }
             string patientID = "P" + to_string(count);

             patient_data add;
             add.id = patientID;
             add.firstName = dummy[a][0];
             add.lastName = dummy[a][1];
             add.gender = dummy[a][2];
             add.age = stoi(dummy[a][3]);
             add.phone = dummy[a][4];
             add.address = dummy[a][5];
             add.visitDate = dummy[a][6];
             add.visitTime = dummy[a][7];
             add.disabilityOption = dummy[a][8];

             insertAtEnd(add);
     }

}

void main()
{

    addDummyData();

    start_menu();


}