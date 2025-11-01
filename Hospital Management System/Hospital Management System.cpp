/*
    * Hospital Management System
    * author: Walid Rabei
    * 1/11/2025
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

class Patient
{
private:
    string name, gender, disease;
    int id, age;
    int assignedDoctor;

public:
    Patient(string name, string gender, string disease, int id, int age)
    {
        this->name = name;
        this->gender = gender;
        this->disease = disease;
        this->id = id;
        this->age = age;
        assignedDoctor = -1;
    }

    void displayDetails()
    {
        cout << "---------------------------------" << endl;

        cout << "Patient ID: \t" << id << endl;
        cout << "Name: \t\t" << name << endl;
        cout << "Age: \t\t" << age << endl;
        cout << "Gender: \t" << gender << endl;
        cout << "Disease: \t" << disease << endl;

        // check if doctor is assigned
        cout << "Assigned Doctor ID: ";
        if (assignedDoctor == -1)
        {
            cout << "Not Assigned Yet" << endl;
        }
        else
        {
            cout << assignedDoctor << endl;
        }

        cout << "---------------------------------" << endl
            << endl;
    }

    void assignDoctor(int doctorId)
    {
        assignedDoctor = doctorId;
    }

    int getId() { return id; }
    string getName() { return name; }
    string getGender() { return gender; };
    string getDisease() { return disease; };
    int getAge() { return age; };
    int getAssignedDoctor() { return assignedDoctor; }
};

class Doctor
{
private:
    string name, specialty;
    int id, age;

public:
    Doctor(string name, string specialty, int id, int age)
    {
        this->name = name;
        this->specialty = specialty;
        this->id = id;
        this->age = age;
    }

    void displayDetails()
    {
        cout << "---------------------------------" << endl;

        cout << "Doctor ID: \t" << id << endl;
        cout << "Name: \t\t" << name << endl;
        cout << "Age: \t\t" << age << endl;
        cout << "Specialty: \t" << specialty << endl;

        cout << "---------------------------------" << endl
            << endl;
    }

    int getId() { return id; }
    string getName() { return name; }
    string getSpecialty() { return specialty; };
    int getAge() { return age; };
};

class HospitalSystem
{
private:
    vector<Patient> patients;
    vector<Doctor> doctors;

    void loadData()
    {
        ifstream patientFile("patients.txt");
        if (patientFile.is_open())
        {
            string idStr, name, gender, disease, ageStr, docIdStr;

            while (getline(patientFile, idStr) &&
                getline(patientFile, name) &&
                getline(patientFile, gender) &&
                getline(patientFile, disease) &&
                getline(patientFile, ageStr) &&
                getline(patientFile, docIdStr))
            {
                int id = stoi(idStr);
                int age = stoi(ageStr);
                int docId = stoi(docIdStr);

                Patient newPatient(name, gender, disease, id, age);

                newPatient.assignDoctor(docId);

                patients.push_back(newPatient);
            }
            patientFile.close();
        }

        ifstream doctorFile("doctors.txt");
        if (doctorFile.is_open())
        {
            string idStr, name, specialty, ageStr;

            while (getline(doctorFile, idStr) &&
                getline(doctorFile, name) &&
                getline(doctorFile, specialty) &&
                getline(doctorFile, ageStr))
            {
                int id = stoi(idStr);
                int age = stoi(ageStr);

                Doctor newDoctor(name, specialty, id, age);
                doctors.push_back(newDoctor);
            }
            doctorFile.close();
        }
    }

public:
    HospitalSystem()
    {
        loadData();

        if (doctors.empty())
        {
            cout << "No doctors file found. Initializing default doctors..." << endl;
            Doctor d1("Dr. Ahmed", "Cardiology", 101, 45);
            doctors.push_back(d1);

            Doctor d2("Dr. Mona", "Dermatology", 102, 38);
            doctors.push_back(d2);

            Doctor d3("Dr. Samir", "Pediatrics", 103, 50);
            doctors.push_back(d3);
        }

        cout << "Hospital System Ready." << endl;
    }

    bool checkDuplicatePatient(int id)
    {
        for (auto& patient : patients)
        {
            if (patient.getId() == id)
            {
                cout << "Patient with ID " << id << " already exists. Cannot add duplicate." << endl;
                return true;
            }
        }
        return false;
    }

    int findPatientIndex(int id)
    {
        for (int i = 0; i < patients.size(); i++)
        {
            if (patients[i].getId() == id)
            {
                return i;
            }
        }
        return -1;
    }

    void addPatient()
    {
        int id, age;
        string name, gender, disease;
        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Patient Age: ";
        cin >> age;
        cout << "Enter Patient Gender: ";
        cin >> gender;
        cout << "Enter Patent disease: ";
        cin.ignore();
        getline(cin, disease);
        cout << "Enter Patient ID: ";
        cin >> id;

        if (!checkDuplicatePatient(id))
        {
            Patient newPatient(name, gender, disease, id, age);
            patients.push_back(newPatient);
            cout << "\033[1;32mPatient added successfully!\033[0m\n";
        }
    }

    void displayAllPatients()
    {
        if (patients.empty())
        {
            cout << "No patients found in the system." << endl;
            return;
        }
        for (auto& patient : patients)
        {
            patient.displayDetails();
        }
    }

    bool searchPatient()
    {
        int id = 0, choice = 0;
        string name;
        cout << "Search by:\n1. ID\n2. Name" << endl;
        cout << "Enter choice (1-2): ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Patient ID: ";
            cin >> id;
        }
        else if (choice == 2)
        {
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
        }
        else
        {
            cout << "Invalid choice." << endl;
            return false;
        }
        bool found = false;
        for (auto& patient : patients)
        {
            if ((choice == 1 && patient.getId() == id) || (choice == 2 && patient.getName() == name))
            {
                patient.displayDetails();
                found = true;
                if (choice == 1)
                {
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "Patient not found." << endl;
        }
        return found;
    }

    void assignDoctorToPatient()
    {
        int id;
        cout << "Enter Patient ID to assign a doctor: ";
        cin >> id;

        int patientIndex = findPatientIndex(id);

        if (patientIndex == -1)
        {
            cout << "Patient with ID " << id << " not found." << endl;
            return;
        }

        cout << "Available Doctors:" << endl;
        for (auto& doctor : doctors)
        {
            doctor.displayDetails();
        }

        int doctorId;
        cout << "Enter Doctor ID to assign: ";
        cin >> doctorId;

        bool doctorFound = false;
        for (auto& doctor : doctors)
        {
            if (doctor.getId() == doctorId)
            {
                doctorFound = true;
                break;
            }
        }

        if (!doctorFound)
        {
            cout << "Doctor with ID " << doctorId << " not found." << endl;
            return;
        }

        patients[patientIndex].assignDoctor(doctorId);
        cout << "Doctor with ID " << doctorId << " assigned to Patient ID " << id << " successfully." << endl;
    }

    void deletePatientRecord()
    {
        int id;
        cout << "Enter Patient ID to delete: ";
        cin >> id;

        int patientIndex = findPatientIndex(id);

        if (patientIndex == -1)
        {
            cout << "Patient with ID " << id << " not found." << endl;
            return;
        }

        patients.erase(patients.begin() + patientIndex);
        cout << "\033[1;31mPatient with ID " << id << " deleted successfully.\033[0m\n";
    }

    void run()
    {
        int choice = 0;
        while (choice != 6)
        {
            cout << "\n===== Hospital Management System =====" << endl;
            cout << "1. Add New Patient" << endl;
            cout << "2. Display All Patients" << endl;
            cout << "3. Search For Patient" << endl;
            cout << "4. Assign Doctor to Patient" << endl;
            cout << "5. Delete Patient Record" << endl;
            cout << "6. Exit System & Save Data" << endl;
            cout << "======================================" << endl;
            cout << "Enter your choice (1-6): ";

            if (cin >> choice)
            {
                switch (choice)
                {
                case 1:
                    addPatient();
                    break;
                case 2:
                    displayAllPatients();
                    break;
                case 3:
                    searchPatient();
                    break;
                case 4:
                    assignDoctorToPatient();
                    break;
                case 5:
                    deletePatientRecord();
                    break;
                case 6:
                    saveData();
                    cout << "Exiting system. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again (1-6)." << endl;
                    break;
                }
            }
            else
            {
                cout << "Invalid input. Please enter a number between 1 and 6." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
    }

    void saveData()
    {
        ofstream patientFile("patients.txt");
        if (!patientFile.is_open())
        {
            cout << "Error: Could not save patient data." << endl;
            return;
        }

        for (auto& patient : patients)
        {
            patientFile << patient.getId() << "\n";
            patientFile << patient.getName() << "\n";
            patientFile << patient.getGender() << "\n";
            patientFile << patient.getDisease() << "\n";
            patientFile << patient.getAge() << "\n";
            patientFile << patient.getAssignedDoctor() << "\n";
        }
        patientFile.close();

        ofstream doctorFile("doctors.txt");
        if (!doctorFile.is_open())
        {
            cout << "Error: Could not save doctor data." << endl;
            return;
        }

        for (auto& doctor : doctors)
        {
            doctorFile << doctor.getId() << "\n";
            doctorFile << doctor.getName() << "\n";
            doctorFile << doctor.getSpecialty() << "\n";
            doctorFile << doctor.getAge() << "\n";
        }
        doctorFile.close();

        cout << "\033[1;36mData saved successfully!\033[0m\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    HospitalSystem myHospital;
    myHospital.run();
    return 0;
}