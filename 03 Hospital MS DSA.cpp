#include<iostream>
#include<string>
using namespace std;

class Data {
public:
    int age, room;
    string name, address, disease, gender, description;
};

class Node {
public:
    Data data;
    Node* next;
};

Node* Insertfront(Node* head, Data data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

Node* append(Node* head, Data data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return head;
    }
    Node* last = head;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    cout << "Append Completed!";
    return head;
}

void changeNode(Node* head, string data, string newData) {
    while (head != NULL) {
        if (head->data.name == data) {
            head->data.name = newData;
            break;
        }
        head = head->next;
    }
}

void printLinkedList(Node* head) {
    if (head == NULL) {
        cout << "Head is NULL\n";
        return;
    }
    cout << "Name\tAddress\tGender\tDisease\tDescription\tAge\tSpecialist No.\n";
    while (head != NULL) {
        cout << head->data.name << "\t" << head->data.address << "\t" << head->data.gender << "\t" << head->data.disease << "\t";
        cout << head->data.description << "\t" << head->data.age << "\t" << head->data.room << endl;
        head = head->next;
    }
}

int listlength(Node* head) {
    int temp = 0;
    if (head == NULL) {
        cout << "Node is empty" << endl;
        return 0;
    }
    while (head != NULL) {
        ++temp;
        head = head->next;
    }
    return temp;
}

void delElement(Node* head, int loc) {
    Node* temp = head;
    if (head == NULL) {
        cout << "Node is null" << endl;
        return;
    }
    for (int i = 1; i < loc - 1; ++i) {
        if (temp != NULL)
            temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Location not found" << endl;
        return;
    }
    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

Node* searchList(Node* head, string v) {
    if (head == NULL) {
        cout << "Node is empty returning null" << endl;
        return NULL;
    }
    int l = 1;
    while (head != NULL && head->data.name != v) {
        head = head->next;
        ++l;
    }
    if (head != NULL)
        cout << "Element found at location: " << l << endl;
    else
        cout << "Element not found" << endl;
    return head;
}

Data inputPatients() {
    string name, address, disease, gender, description;
    int specialRoomNo, age;
    Data p;
    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Patient Address: ";
    getline(cin, address);
    cout << "Enter Patient Disease: ";
    getline(cin, disease);
    cout << "Enter Patient Gender: ";
    getline(cin, gender);
    cout << "Enter Disease Description: ";
    getline(cin, description);
    cout << "Enter Patient Special Room No.: ";
    cin >> specialRoomNo;
    cout << "Enter Patient Age: ";
    cin >> age;
    p.name = name;
    p.address = address;
    p.gender = gender;
    p.description = description;
    p.room = specialRoomNo;
    p.age = age;
    cout << "Input Function Completed!";
    return p;
}

int main() {
    Node* head = NULL;
    Data patient;
    string nameToSearch, oldName, newName;
    int op;
    cout << "\n1-Add Patient\n2-Del Patient\n3-Search by Name\n4-List Length\n5-Print List\n6-Change Patient Name\n7-Insert new at front\n";
    while (cin >> op) {
        switch (op) {
        case 1:
            cout << "Enter Patient Details Below" << endl;
            patient = inputPatients();
            head = append(head, patient);
            break;
        case 2:
            if (listlength(head) < 2) {
                cout << "Length is less than two.\nTerminating program" << endl;
                exit(1);
            }
            else {
                cout << "Enter location where you want to delete a patient, at least three patients must be in list: ";
                int l;
                cin >> l;
                delElement(head, l);
            }
            break;
        case 3:
            cout << "Enter name to search patient: ";
            cin.ignore();
            getline(cin, nameToSearch);
            searchList(head, nameToSearch);
            break;
        case 4:
            cout << "You have " << listlength(head) << " Patients in your Hospital." << endl;
            break;
        case 5:
            printLinkedList(head);
            break;
        case 6:
            cin.ignore();
            cout << "Enter old name: ";
            getline(cin, oldName);
            cout << "Enter New Name: ";
            getline(cin, newName);
            changeNode(head, oldName, newName);
            break;
        case 7:
            patient = inputPatients();
            head = Insertfront(head, patient);
            break;
        default:
            cout << "Wrong option Selected" << endl;
        }
        cout << "\n1-Add Patient\n2-Del Patient\n3-Search by Name\n4-List Length\n5-Print List\n6-Change Patient Name\n7-Insert new at front\n";
    }
    return 0;
}
