#include <iostream>
#include <string>
#include <limits>
#include "LinkedList.h"
using namespace std;

bool ReadInteger(const string& message, int& value) {
    cout << message;
    if (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return false;
    }
    return true;
}

bool ReadPatientDetails(int& id, string& name, int& age,
                        string& disease, int& priority) {
    if (!ReadInteger("Enter Patient ID: ", id)) return false;

    cout << "Enter Patient Name: ";
    getline(cin >> ws, name);
    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return false;
    }

    if (!ReadInteger("Enter Patient Age: ", age)) return false;
    if (age < 0 || age > 130) {
        cout << "Please enter a valid age (0-130).\n";
        return false;
    }

    cout << "Enter Disease or Complaint: ";
    getline(cin >> ws, disease);
    if (disease.empty()) {
        cout << "Disease/complaint cannot be empty.\n";
        return false;
    }

    if (!ReadInteger("Enter Priority (1=Urgent, 2=Regular, 3=Low): ", priority))
        return false;

    if (priority < 1 || priority > 3) {
        cout << "Invalid priority. Enter 1, 2, or 3.\n";
        return false;
    }
    return true;
}

int main() {
    LinkedList hospital;
    int choice = 0;

    do {
        cout << "\n===== Hospital Management System (Linked List) =====\n";
        cout << "1. Add Patient by Priority\n";
        cout << "2. Insert Patient at Head\n";
        cout << "3. Process Highest-Priority Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Check List Status\n";
        cout << "6. Insert Patient at Index\n";
        cout << "7. Remove Patient at Index\n";
        cout << "8. Swap Patients at Two Indexes\n";
        cout << "9. Sort Patients by Priority\n";
        cout << "10. Reverse Patient List\n";
        cout << "11. Exit\n";

        if (!ReadInteger("Enter your choice: ", choice)) continue;

        switch (choice) {
            case 1:
            case 2: {
                int id, age, priority;
                string name, disease;

                if (!ReadPatientDetails(id, name, age, disease, priority)) break;

                if (choice == 1)
                    hospital.AddByPriority(id, name, age, disease, priority);
                else
                    hospital.Insert(id, name, age, disease, priority);
                break;
            }

            case 3:
                // Re-sort first so the head is the highest-priority patient,
                // even if other list operations changed the order.
                hospital.Sort();
                hospital.Remove();
                break;

            case 4:
                hospital.Print();
                break;

            case 5:
                hospital.QueueStatus();
                break;

            case 6: {
                int index, id, age, priority;
                string name, disease;

                if (!ReadInteger("Enter insertion index (0 to current size): ", index))
                    break;
                if (!ReadPatientDetails(id, name, age, disease, priority)) break;

                hospital.InsertAt(index, id, name, age, disease, priority);
                break;
            }

            case 7: {
                int index;
                if (!ReadInteger("Enter index to remove: ", index)) break;
                hospital.RemoveAt(index);
                break;
            }

            case 8: {
                int firstIndex, secondIndex;
                if (!ReadInteger("Enter first index: ", firstIndex)) break;
                if (!ReadInteger("Enter second index: ", secondIndex)) break;
                hospital.Swap(firstIndex, secondIndex);
                break;
            }

            case 9:
                hospital.Sort();
                break;

            case 10:
                hospital.Reverse();
                break;

            case 11:
                cout << "Exiting Hospital Management System.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 11);

    return 0;
}
