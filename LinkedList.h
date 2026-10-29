#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;

// Self-referential node structure for the Hospital Patient Management System.
struct PatientNode {
    int patientID;
    string patientName;
    int age;
    string disease;
    int priority;       // 1 = Urgent, 2 = Regular, 3 = Low
    PatientNode* next;
};

class LinkedList {
private:
    PatientNode* head;
    int count;

    PatientNode* CreateNode(int id, const string& name, int patientAge,
                            const string& patientDisease, int patientPriority);
    void SwapPatientData(PatientNode* first, PatientNode* second);

public:
    LinkedList();
    ~LinkedList();

    // Required linked-list operations.
    void Insert(int id, const string& name, int patientAge,
                const string& patientDisease, int patientPriority); // Insert at head
    void Remove();                                                   // Remove from head
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    void InsertAt(int index, int id, const string& name, int patientAge,
                  const string& patientDisease, int patientPriority);
    void RemoveAt(int index);
    void Swap(int firstIndex, int secondIndex);
    void Sort();      // Sort by priority: 1 (urgent) to 3 (low)
    void Reverse();
    void Print() const;

    // Project-specific operation: keep patients ordered by priority.
    void AddByPriority(int id, const string& name, int patientAge,
                       const string& patientDisease, int patientPriority);

    void QueueStatus() const;
    int Size() const;
};

#endif
