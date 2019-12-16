//Microwosoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64

#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

class TreeNode
{
    public: 
    TreeNode();
    TreeNode(int value) : value(value) {};
    
    void Print()
    {
        if (left != nullptr)
        {
            left->Print();
        }
        cout << value << ", ";

        if (right != nullptr)
        {
            right->Print();
        }
    }
    
    TreeNode* InsertValue(TreeNode* current_node, int value)
    {
        //leaf
        if(current_node == nullptr)
        {
            return new TreeNode(value);
        }
        
        //not leaf(branch)
        if(current_node->value >= value)
        {
            current_node->left = InsertValue(current_node->left, value);
        }
        else
        {
            current_node->right = InsertValue(current_node->right, value);
        }
        return current_node;
     
    }
    
    int value;
    TreeNode* left;
    TreeNode* right;
};

class BinarySearchTree
{
    public:
    BinarySearchTree() : root(nullptr) {};
    
    TreeNode* root;
    
    void Print()
    {
        root->Print();
    }
    
    void InsertValue(int value)
    {
        if(root != nullptr)
        {
            root = root->InsertValue(root, value);
        }
        else
        {
            root = new TreeNode(value);
        }
    }    
};

int main()
{
    vector<int> values = { 49, 23, 80, 10, 37, 62, 89, 3, 19, 30, 49, 59, 70, 89, 100, 105 };

    BinarySearchTree tree;
    
    for(int v : values)
    {
        tree.InsertValue(v);
    }
    
    tree.Print();
    
    cout << endl << endl << "┬──┬◡ﾉ(° -°ﾉ)" << std::endl;
}



//With Find Split

#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

class TreeNode
{
public:
    TreeNode();
    TreeNode(int value) : value(value) {};

    void Print()
    {
        if (left != nullptr)
        {
            left->Print();
        }
        cout << value << ", ";

        if (right != nullptr)
        {
            right->Print();
        }
    }

    TreeNode* InsertValue(TreeNode* current_node, int value)
    {
        //leaf
        if (current_node == nullptr)
        {
            return new TreeNode(value);
        }

        //not leaf(branch)
        if (current_node->value >= value)
        {
            current_node->left = InsertValue(current_node->left, value);
        }
        else
        {
            current_node->right = InsertValue(current_node->right, value);
        }

        return current_node;
    }


    TreeNode* FindSplitNode(TreeNode* treeRoot, int min, int max)
    {
        TreeNode* current_node = treeRoot;

        while (current_node != nullptr && (max <= current_node->value || min > current_node->value))
        {
            //If max is smaller than the current value go into left side
            if (max <= current_node->value)
            {

                current_node = current_node->left;
            }//If min is bigger than current value go right
            else
            {
                current_node = current_node->right;
            }

        }

        return current_node;

    }

    int value;
    TreeNode* left;
    TreeNode* right;
};

class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr) {};

    TreeNode* root;

    void Print()
    {
        root->Print();
    }

    void InsertValue(int value)
    {
        if (root != nullptr)
        {
            root = root->InsertValue(root, value);
        }
        else
        {
            root = new TreeNode(value);
        }
    }
};

int main()
{
    vector<int> values = { 49, 23, 80, 10, 37, 62, 89, 3, 19, 30, 49, 59, 70, 89, 100, 105 };

    BinarySearchTree tree;

    for (int v : values)
    {
        tree.InsertValue(v);
    }

    tree.Print();

    cout << "" << std::endl;
}