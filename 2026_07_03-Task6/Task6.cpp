#include <iostream>
#include <string>

using namespace std;

class BST {
public:
    string name;
    BST* left = NULL;
    BST* right = NULL;

    // Insert
    static void insert(BST*& root, string value) {

        if (root == NULL) {
            root = new BST();
            root->name = value;
            return;
        }

        if (value < root->name)
            insert(root->left, value);
        else
            insert(root->right, value);
    }

    // Search
    static bool search(BST* root, string value) {

        if (root == NULL)
            return false;

        if (root->name == value)
            return true;

        if (value < root->name)
            return search(root->left, value);
        else
            return search(root->right, value);
    }

    // Inorder Traversal (Ascending)
    static void inorder(BST* root) {

        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->name << endl;
        inorder(root->right);
    }

    // Preorder Traversal
    static void preorder(BST* root) {

        if (root == NULL)
            return;

        cout << root->name << endl;
        preorder(root->left);
        preorder(root->right);
    }

    // Postorder Traversal
    static void postorder(BST* root) {

        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->name << endl;
    }

    // Find Minimum
    static BST* findMin(BST* root) {

        while (root->left != NULL)
            root = root->left;

        return root;
    }

    // Delete
    static BST* deleteNode(BST* root, string value) {

        if (root == NULL)
            return NULL;

        if (value < root->name) {
            root->left = deleteNode(root->left, value);
        }
        else if (value > root->name) {
            root->right = deleteNode(root->right, value);
        }
        else {

            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL) {
                BST* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                BST* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            BST* temp = findMin(root->right);
            root->name = temp->name;
            root->right = deleteNode(root->right, temp->name);
        }

        return root;
    }
};

int main() {

    BST* root = NULL;

    BST::insert(root, "Jessy");
    BST::insert(root, "Ahmad");
    BST::insert(root, "Anajana");
    BST::insert(root, "Aimar");
    BST::insert(root, "Daniel");
    BST::insert(root, "Zack");

    cout << "Inorder Traversal\n";
    BST::inorder(root);

    cout << "\nPreorder Traversal\n";
    BST::preorder(root);

    cout << "\nPostorder Traversal\n";
    BST::postorder(root);

    cout << "\n";

    if (BST::search(root, "Daniel"))
        cout << "Daniel found.\n";
    else
        cout << "Daniel not found.\n";

    cout << "\nDeleting Ahmad...\n\n";

    root = BST::deleteNode(root, "Ahmad");

    cout << "Inorder Traversal After Deletion\n";
    BST::inorder(root);

    return 0;
}