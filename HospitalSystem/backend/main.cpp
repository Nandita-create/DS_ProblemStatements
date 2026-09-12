#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

/*#include "httplib.h"
int main() {

    httplib::Server server;

    server.Get("/api/test", [](const httplib::Request& req,
                               httplib::Response& res) {

        res.set_content(
            "Hospital Backend Connected!",
            "text/plain"
        );
    });

    cout << "Server running at http://localhost:8080\n";

    server.listen("localhost", 8080);

    return 0;
}*/


// Get current date
string getCurrentDate() {

    time_t now = time(0);
    tm* localTime = localtime(&now);

    stringstream date;

    date << setfill('0')
         << setw(2) << localTime->tm_mday << "-"
         << setw(2) << localTime->tm_mon + 1 << "-"
         << localTime->tm_year + 1900;

    return date.str();
}


// Get current time
string getCurrentTime() {

    time_t now = time(0);
    tm* localTime = localtime(&now);

    stringstream currentTime;

    currentTime << setfill('0')
                << setw(2) << localTime->tm_hour << ":"
                << setw(2) << localTime->tm_min << ":"
                << setw(2) << localTime->tm_sec;

    return currentTime.str();
}


struct Patient{
    int patientID;
    string name;
    int age;
    string gender;
    string bloodGroup;
    string phone;
    string address;
    string department;
    int doctorID;
};


struct PatientNode{
    Patient data;
    PatientNode* next;

    PatientNode(Patient p) {
        data = p;
        next = nullptr;
    }
};


//Singly Linked List
class PatientList {
private:
    PatientNode* head;

public:
    PatientList() {
        head = nullptr;
    }

    void addPatient(Patient p);
    void deletePatient(int patientID);
    Patient* searchPatient(int patientID);
    void displayPatients();
    void updatePatient(int patientID);
};


struct MedicalRecord{
    int recordID;
    string date;
    int doctorID;
    string diagnosis;
    string prescription;
    string notes;
};


struct MedicalRecordNode {
    MedicalRecord data;
    MedicalRecordNode* next;
    MedicalRecordNode* prev;

    MedicalRecordNode(MedicalRecord record) {
        data = record;
        next = nullptr;
        prev = nullptr;
    }
};


//Dpubly Linked List
class MedicalHistory {
private:
    MedicalRecordNode* head;
    MedicalRecordNode* tail;

public:
    MedicalHistory() {
        head = nullptr;
        tail = nullptr;
    }

    void addRecord(MedicalRecord record);
    void displayForward();
    void displayBackward();
    void deleteRecord(int recordID);
};


struct Doctor{
    int doctorID;
    string name;
    string specialization;
    string department;
    string phone;
};


struct Appointment{
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;
    string status;
};


struct AppointmentNode {
    Appointment data;
    AppointmentNode* next;

    AppointmentNode(Appointment appointment) {
        data = appointment;
        next = nullptr;
    }
};


// Queue using Linked List
class AppointmentQueue {
private:
    AppointmentNode* front;
    AppointmentNode* rear;

public:
    AppointmentQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(Appointment appointment);
    void dequeue();
    Appointment* peek();
    void display();
    bool isEmpty();
};


struct EmergencyEntry{
    int patientID;
    int severity;
    string arrivalTime;
};


struct EmergencyNode {
    EmergencyEntry data;
    EmergencyNode* next;

    EmergencyNode(EmergencyEntry entry) {
        data = entry;
        next = nullptr;
    }
};


class EmergencyQueue {
private:
    EmergencyNode* front;
    EmergencyNode* rear;

public:
    EmergencyQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(EmergencyEntry patient);
    void dequeue();
    EmergencyEntry* peek();
    void display();
    bool isEmpty();
};


struct Department{
    int departmentID;
    string name;
};


void PatientList::addPatient(Patient p)
{
    PatientNode* newNode = new PatientNode(p);

    if (head==NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        PatientNode* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}


void PatientList::deletePatient(int patientID) {

    if (head == nullptr) {
        cout << "Patient list is empty.\n";
        return;
    }

    // Patient is the first node
    if (head->data.patientID == patientID) {

        PatientNode* temp = head;
        head = head->next;
        delete temp;

        cout << "Patient deleted successfully.\n";
        return;
    }

    PatientNode* temp = head;

    while (temp->next != nullptr &&
           temp->next->data.patientID != patientID) {

        temp = temp->next;
    }

    // Patient not found
    if (temp->next == nullptr) {
        cout << "Patient not found.\n";
        return;
    }

    // Delete the node
    PatientNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    delete nodeToDelete;

    cout << "Patient deleted successfully.\n";
}


Patient* PatientList::searchPatient(int patientID) {

    PatientNode* temp = head;

    while (temp != nullptr) {

        if (temp->data.patientID == patientID) {
            return &temp->data;
        }

        temp = temp->next;
    }

    return nullptr;
}


void PatientList::displayPatients() {

    if (head == nullptr) {
        cout << "No patients registered.\n";
        return;
    }

    PatientNode* temp = head;

    while (temp != nullptr) {

        cout << "\n-------------------------\n";
        cout << "Patient ID   : " << temp->data.patientID << endl;
        cout << "Name         : " << temp->data.name << endl;
        cout << "Age          : " << temp->data.age << endl;
        cout << "Gender       : " << temp->data.gender << endl;
        cout << "Blood Group  : " << temp->data.bloodGroup << endl;
        cout << "Phone        : " << temp->data.phone << endl;
        cout << "Address      : " << temp->data.address << endl;
        cout << "Department   : " << temp->data.department << endl;
        cout << "Doctor ID    : " << temp->data.doctorID << endl;

        temp = temp->next;
    }

    cout << "-------------------------\n";
}


void PatientList::updatePatient(int patientID) {

    Patient* patient = searchPatient(patientID);

    if (patient == nullptr) {
        cout << "Patient not found.\n";
        return;
    }

    cout << "Enter new name: ";
    cin >> ws;
    getline(cin, patient->name);

    cout << "Enter new age: ";
    cin >> patient->age;

    cout << "Enter new gender: ";
    cin >> patient->gender;

    cout << "Enter new blood group: ";
    cin >> patient->bloodGroup;

    cout << "Enter new phone: ";
    cin >> patient->phone;

    cout << "Enter new address: ";
    cin >> ws;
    getline(cin, patient->address);

    cout << "Enter new department: ";
    cin >> ws;
    getline(cin, patient->department);

    cout << "Enter new doctor ID: ";
    cin >> patient->doctorID;

    cout << "Patient updated successfully.\n";
}


void MedicalHistory::addRecord(MedicalRecord record) {

    MedicalRecordNode* newNode = new MedicalRecordNode(record);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}


void MedicalHistory::displayForward() {

    if (head == nullptr) {
        cout << "No medical records found.\n";
        return;
    }

    MedicalRecordNode* temp = head;

    while (temp != nullptr) {

        cout << "\n-------------------------\n";
        cout << "Record ID    : " << temp->data.recordID << endl;
        cout << "Date         : " << temp->data.date << endl;
        cout << "Doctor ID    : " << temp->data.doctorID << endl;
        cout << "Diagnosis    : " << temp->data.diagnosis << endl;
        cout << "Prescription : " << temp->data.prescription << endl;
        cout << "Notes        : " << temp->data.notes << endl;

        temp = temp->next;
    }
}


void MedicalHistory::displayBackward() {

    if (tail == nullptr) {
        cout << "No medical records found.\n";
        return;
    }

    MedicalRecordNode* temp = tail;

    while (temp != nullptr) {

        cout << "\n-------------------------\n";
        cout << "Record ID    : " << temp->data.recordID << endl;
        cout << "Date         : " << temp->data.date << endl;
        cout << "Doctor ID    : " << temp->data.doctorID << endl;
        cout << "Diagnosis    : " << temp->data.diagnosis << endl;
        cout << "Prescription : " << temp->data.prescription << endl;
        cout << "Notes        : " << temp->data.notes << endl;

        temp = temp->prev;
    }
}


void MedicalHistory::deleteRecord(int recordID) {

    if (head == nullptr) {
        cout << "No medical records found.\n";
        return;
    }

    MedicalRecordNode* temp = head;

    while (temp != nullptr && temp->data.recordID != recordID) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Record not found.\n";
        return;
    }

    // If deleting the first node
    if (temp == head) {

        head = temp->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;

        cout << "Record deleted successfully.\n";
        return;
    }

    // If deleting the last node
    if (temp == tail) {

        tail = temp->prev;
        tail->next = nullptr;

        delete temp;

        cout << "Record deleted successfully.\n";
        return;
    }

    // If deleting a middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    cout << "Record deleted successfully.\n";
}


void AppointmentQueue::enqueue(Appointment appointment)
{
    AppointmentNode* newNode = new AppointmentNode(appointment);

    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Appointment added to OPD queue.\n";

    return;
}


void AppointmentQueue::dequeue()
{
    if (front == nullptr)
    {
        cout<<"OPD queue is empty \n";
        return;
    }

    AppointmentNode* temp = front;

    cout<<"Attending appointment ID: "
        << temp->data.appointmentID
        << " for Patient ID: "
        << temp->data.patientID
        << endl;

    front = front->next;

    if (front==nullptr)
    {
        rear = nullptr;
    }

    delete temp;

    cout<<"Appointment attended and removed from OPD Queue"
        <<endl;
}


Appointment* AppointmentQueue::peek() {

    if (front == nullptr) {
        cout << "OPD queue is empty.\n";
        return nullptr;
    }

    return &front->data;
}


bool AppointmentQueue::isEmpty() {

    return front == nullptr;
}


void AppointmentQueue::display() {

    if (front == nullptr) {
        cout << "OPD queue is empty.\n";
        return;
    }

    AppointmentNode* temp = front;

    while (temp != nullptr) {

        cout << "\n-------------------------\n";
        cout << "Appointment ID : " << temp->data.appointmentID << endl;
        cout << "Patient ID     : " << temp->data.patientID << endl;
        cout << "Doctor ID      : " << temp->data.doctorID << endl;
        cout << "Date           : " << temp->data.date << endl;
        cout << "Time           : " << temp->data.time << endl;
        cout << "Status         : " << temp->data.status << endl;

        temp = temp->next;
    }

    cout << "-------------------------\n";
}


void EmergencyQueue::enqueue(EmergencyEntry patient)
{
    EmergencyNode* newNode = new EmergencyNode(patient);

    if (front==nullptr)
    {
        front = newNode;
        rear = newNode;

        cout<<"Emergency Patient added to Queue \n";

        return;
    }

    if (patient.severity > front->data.severity)
    {
        newNode->next = front;
        front = newNode;

        cout<<"Emergency Patient added to Queue \n";

        return;
    }

    // Find correct position
    EmergencyNode* temp = front;

    while (temp->next != nullptr &&
           temp->next->data.severity >= patient.severity) {

        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    // New node became the rear
    if (newNode->next == nullptr) {
        rear = newNode;
    }

    cout << "Emergency patient added based on priority.\n";
}


void EmergencyQueue::dequeue() {

    if (front == nullptr) {
        cout << "Emergency queue is empty.\n";
        return;
    }

    EmergencyNode* temp = front;

    cout << "Treating Patient ID: "
         << temp->data.patientID
         << " | Severity: "
         << temp->data.severity << endl;

    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}


EmergencyEntry* EmergencyQueue::peek()
{
    if (front==nullptr)
    {
        cout<<"Emergency Queue is Empty \n";
        return nullptr;
    }

    return &front->data;
}


bool EmergencyQueue::isEmpty()
{
    if (front==nullptr)
    {
        return true;
    }

    return false;
}


void EmergencyQueue::display() {

    if (front == nullptr) {
        cout << "Emergency queue is empty.\n";
        return;
    }

    EmergencyNode* temp = front;

    while (temp != nullptr) {

        cout << "\n-------------------------\n";
        cout << "Patient ID   : " << temp->data.patientID << endl;
        cout << "Severity     : " << temp->data.severity << endl;
        cout << "Arrival Time : " << temp->data.arrivalTime << endl;

        temp = temp->next;
    }

    cout << "-------------------------\n";
}


int main() {

    PatientList patients;
    MedicalHistory history;
    AppointmentQueue appointments;
    EmergencyQueue emergency;

    int choice;

    do {

        cout << "\n\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Display All Patients\n";
        cout << "6. Add Medical Record\n";
        cout << "7. Display Medical History\n";
        cout << "8. Add Appointment\n";
        cout << "9. Attend Appointment\n";
        cout << "10. Display Appointment Queue\n";
        cout << "11. Add Emergency Patient\n";
        cout << "12. Treat Emergency Patient\n";
        cout << "13. Display Emergency Queue\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        // Prevent infinite loop if user enters a non-number
        if (cin.fail()) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a number.\n";

            continue;
        }


        // ================= PATIENT =================

        if (choice == 1) {

            Patient p;

            cout << "\nEnter Patient ID: ";
            cin >> p.patientID;

            cout << "Enter Name: ";
            cin >> ws;
            getline(cin, p.name);

            cout << "Enter Age: ";
            cin >> p.age;

            cout << "Enter Gender: ";
            cin >> p.gender;

            cout << "Enter Blood Group: ";
            cin >> p.bloodGroup;

            cout << "Enter Phone: ";
            cin >> p.phone;

            cout << "Enter Address: ";
            cin >> ws;
            getline(cin, p.address);

            cout << "Enter Department: ";
            cin >> ws;
            getline(cin, p.department);

            cout << "Enter Doctor ID: ";
            cin >> p.doctorID;

            patients.addPatient(p);

            cout << "\nPatient added successfully!\n";
        }


        else if (choice == 2) {

            int id;

            cout << "Enter Patient ID to delete: ";
            cin >> id;

            patients.deletePatient(id);
        }


        else if (choice == 3) {

            int id;

            cout << "Enter Patient ID to search: ";
            cin >> id;

            Patient* p = patients.searchPatient(id);

            if (p != nullptr) {

                cout << "\nPatient Found!\n";
                cout << "Name       : " << p->name << endl;
                cout << "Age        : " << p->age << endl;
                cout << "Gender     : " << p->gender << endl;
                cout << "Blood Group: " << p->bloodGroup << endl;
                cout << "Phone      : " << p->phone << endl;
                cout << "Department : " << p->department << endl;
                cout << "Doctor ID  : " << p->doctorID << endl;
            }

            else {
                cout << "Patient not found.\n";
            }
        }


        else if (choice == 4) {

            int id;

            cout << "Enter Patient ID to update: ";
            cin >> id;

            patients.updatePatient(id);
        }


        else if (choice == 5) {

            patients.displayPatients();
        }


        // ================= MEDICAL HISTORY =================

        else if (choice == 6) {

            MedicalRecord record;

            cout << "\nEnter Record ID: ";
            cin >> record.recordID;

            record.date = getCurrentDate();

            cout << "Date: " << record.date << endl;

            cout << "Enter Doctor ID: ";
            cin >> record.doctorID;

            cout << "Enter Diagnosis: ";
            cin >> ws;
            getline(cin, record.diagnosis);

            cout << "Enter Prescription: ";
            getline(cin, record.prescription);

            cout << "Enter Notes: ";
            getline(cin, record.notes);

            history.addRecord(record);

            cout << "Medical record added successfully!\n";
        }


        else if (choice == 7) {

            history.displayForward();
        }


        // ================= APPOINTMENT =================

        else if (choice == 8) {

            Appointment a;

            cout << "\nEnter Appointment ID: ";
            cin >> a.appointmentID;

            cout << "Enter Patient ID: ";
            cin >> a.patientID;

            cout << "Enter Doctor ID: ";
            cin >> a.doctorID;

            a.date = getCurrentDate();
            a.time = getCurrentTime();

            cout << "Date: " << a.date << endl;
            cout << "Time: " << a.time << endl;

            cout << "Enter Status: ";
            cin >> ws;
            getline(cin, a.status);

            appointments.enqueue(a);
        }


        else if (choice == 9) {

            appointments.dequeue();
        }


        else if (choice == 10) {

            appointments.display();
        }


        // ================= EMERGENCY =================

        else if (choice == 11) {

            EmergencyEntry e;

            cout << "\nEnter Patient ID: ";
            cin >> e.patientID;

            cout << "Enter Severity (1-10): ";
            cin >> e.severity;

            e.arrivalTime = getCurrentTime();

            cout << "Arrival Time: " << e.arrivalTime << endl;

            emergency.enqueue(e);
        }


        else if (choice == 12) {

            emergency.dequeue();
        }


        else if (choice == 13) {

            emergency.display();
        }


        else if (choice == 0) {

            cout << "\nExiting Hospital Management System...\n";
        }


        else {

            cout << "\nInvalid choice. Please try again.\n";
        }


    } while (choice != 0);


    return 0;
}

//To run use:
// cd backend
// g++ main.cpp -o hospital
// .\hospital