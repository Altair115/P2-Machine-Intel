#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    
    Node() : value(0), next(nullptr) {}
    Node(int value) : value(value), next(nullptr) {}
    
    int value;
    Node* next;
};

class LinkedList{
    public:
    LinkedList() : head(nullptr) {}
    
    void InsertValue(int value)
    {
        Node* new_node = new Node(value);
        
        if(head == nullptr || value <= head->value)
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        //I am a comment
        Node* current = head;
        while(current->next != nullptr && value >= current->next->value)
        {
            current = current->next;
        }
        
        //Add node
        new_node->next = current->next;
        current->next = new_node;
    }
    
    void PrintList()
    {
        //New comment
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << ", ";
            current = current->next;
        }
    }
    
    Node* head;
};

void BucketSort(vector<int> input, int n_buckets)
{
    vector<LinkedList> buckets(n_buckets);
    
    for(int i = 0; i < input.size(); i++)
    {
        buckets.at(input.at(i) / n_buckets).InsertValue(input.at(i));
    }
    
    for(auto bucket : buckets)
    {
        bucket.PrintList();
    }
    
    
}

int main(){
    const unsigned int element_count = 100;
    vector<int> numbers(element_count);
    for (int& i : numbers)
    {
        i = rand() % 100;
    }
    
    BucketSort(numbers, 10);
    cout << endl;
    cout << "Hello World!\n";

}