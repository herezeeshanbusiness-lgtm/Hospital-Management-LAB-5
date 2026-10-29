#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    count = 0;
}

PatientNode* LinkedList::CreateNode(int id, const string& name, int patientAge,
                                    const string& patientDisease, int patientPriority) {
    PatientNode* patient = new PatientNode;
    patient->patientID = id;
    patient->patientName = name;
    patient->age = patientAge;
    patient->disease = patientDisease;
    patient->priority = patientPriority;
    patient->next = nullptr;
    return patient;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        PatientNode* temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;
}

// Required Insert(): insert a patient at the head of the list.
void LinkedList::Insert(int id, const string& name, int patientAge,
                        const string& patientDisease, int patientPriority) {
    PatientNode* patient = CreateNode(id, name, patientAge, patientDisease, patientPriority);
    patient->next = head;
    head = patient;
    ++count;
    cout << "Patient inserted at the head successfully.\n";
}

// Project-specific Add(): insert by priority while keeping equal priorities in arrival order.
void LinkedList::AddByPriority(int id, const string& name, int patientAge,
                               const string& patientDisease, int patientPriority) {
    PatientNode* patient = CreateNode(id, name, patientAge, patientDisease, patientPriority);

    if (head == nullptr || patientPriority < head->priority) {
        patient->next = head;
        head = patient;
    } else {
        PatientNode* current = head;
        while (current->next != nullptr &&
               current->next->priority <= patientPriority) {
            current = current->next;
        }
        patient->next = current->next;
        current->next = patient;
    }

    ++count;
    cout << "Patient added in priority order successfully.\n";
}

// Required Remove(): remove the first node (head).
void LinkedList::Remove() {
    if (IsEmpty()) {
        cout << "No patients in the list.\n";
        return;
    }

    PatientNode* temp = head;
    cout << "\n===== Patient Being Processed =====\n";
    cout << "Patient ID: " << temp->patientID << '\n';
    cout << "Patient Name: " << temp->patientName << '\n';
    cout << "Age: " << temp->age << '\n';
    cout << "Disease/Complaint: " << temp->disease << '\n';
    cout << "Priority: " << temp->priority << " (" 
         << (temp->priority == 1 ? "Urgent" : temp->priority == 2 ? "Regular" : "Low")
         << ")\n";

    head = head->next;
    delete temp;
    --count;
    cout << "Patient removed from the head of the list.\n";
}

bool LinkedList::IsEmpty() const {
    return head == nullptr;
}

bool LinkedList::IsNotEmpty() const {
    return head != nullptr;
}

void LinkedList::InsertAt(int index, int id, const string& name, int patientAge,
                          const string& patientDisease, int patientPriority) {
    if (index < 0 || index > count) {
        cout << "Invalid index. Valid insertion indexes are 0 to " << count << ".\n";
        return;
    }

    PatientNode* patient = CreateNode(id, name, patientAge, patientDisease, patientPriority);

    if (index == 0) {
        patient->next = head;
        head = patient;
    } else {
        PatientNode* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        patient->next = current->next;
        current->next = patient;
    }

    ++count;
    cout << "Patient inserted at index " << index << ".\n";
}

void LinkedList::RemoveAt(int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index. Valid removal indexes are 0 to " << count - 1 << ".\n";
        return;
    }

    PatientNode* temp;

    if (index == 0) {
        temp = head;
        head = head->next;
    } else {
        PatientNode* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }

    cout << "Removed patient: " << temp->patientName
         << " (ID: " << temp->patientID << ")\n";
    delete temp;
    --count;
}

void LinkedList::SwapPatientData(PatientNode* first, PatientNode* second) {
    int tempID = first->patientID;
    first->patientID = second->patientID;
    second->patientID = tempID;

    first->patientName.swap(second->patientName);

    int tempAge = first->age;
    first->age = second->age;
    second->age = tempAge;

    first->disease.swap(second->disease);

    int tempPriority = first->priority;
    first->priority = second->priority;
    second->priority = tempPriority;
}

void LinkedList::Swap(int firstIndex, int secondIndex) {
    if (firstIndex < 0 || firstIndex >= count ||
        secondIndex < 0 || secondIndex >= count) {
        cout << "Invalid index. List indexes are 0 to " << count - 1 << ".\n";
        return;
    }

    if (firstIndex == secondIndex) {
        cout << "Both indexes are the same; no change made.\n";
        return;
    }

    PatientNode* first = head;
    PatientNode* second = head;

    for (int i = 0; i < firstIndex; ++i) first = first->next;
    for (int i = 0; i < secondIndex; ++i) second = second->next;

    SwapPatientData(first, second);
    cout << "Patients at indexes " << firstIndex << " and " << secondIndex
         << " have been swapped.\n";
}

void LinkedList::Sort() {
    if (count < 2) {
        cout << "Not enough patients to sort.\n";
        return;
    }

    // Bubble sort by priority; lower number means higher priority.
    for (PatientNode* end = nullptr; end != head; ) {
        bool swapped = false;
        PatientNode* current = head;

        while (current->next != end) {
            if (current->priority > current->next->priority) {
                SwapPatientData(current, current->next);
                swapped = true;
            }
            current = current->next;
        }

        if (!swapped) break;
        end = current;
    }

    cout << "Patients sorted by priority (urgent first).\n";
}

void LinkedList::Reverse() {
    PatientNode* previous = nullptr;
    PatientNode* current = head;

    while (current != nullptr) {
        PatientNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
    cout << "Patient list reversed.\n";
}

void LinkedList::Print() const {
    if (IsEmpty()) {
        cout << "No patients waiting in the list.\n";
        return;
    }

    cout << "\n===== Hospital Patient List =====\n";
    PatientNode* current = head;
    int index = 0;

    while (current != nullptr) {
        cout << "\nIndex: " << index << '\n';
        cout << "Patient ID: " << current->patientID << '\n';
        cout << "Patient Name: " << current->patientName << '\n';
        cout << "Age: " << current->age << '\n';
        cout << "Disease/Complaint: " << current->disease << '\n';
        cout << "Priority: " << current->priority << " ("
             << (current->priority == 1 ? "Urgent" :
                 current->priority == 2 ? "Regular" : "Low") << ")\n";
        cout << "-----------------------------\n";
        current = current->next;
        ++index;
    }
}

void LinkedList::QueueStatus() const {
    if (IsEmpty()) {
        cout << "List Status: Empty\n";
    } else {
        cout << "List Status: Not Empty\n";
        cout << "Patients in List: " << count << '\n';
    }
}

int LinkedList::Size() const {
    return count;
}
