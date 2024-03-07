#include <bits/stdc++.h>
using namespace std;

 template <typename T>
    class TreeNode
    {
    public:
        T data;
        int height;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data, int height)
        {
            this->data = data;
            this->height = height;
            left = NULL;
            right = NULL;
        }
    };

int height(TreeNode<int>* Node){
    if(Node == NULL){
        return -1;
    }
    else{
        return 1 + max(height(Node->left), height(Node->right));
    }
}

TreeNode<int>* RightRotation(TreeNode<int>* y){
    // cout<<"s";
    TreeNode<int>* x = y->left;
    TreeNode<int>* T1 = x->right;
    x->right = y;
    y->left = T1;

    y->height = height(y);
    x->height = height(x);
    // cout<<x->data<<" "<<x->right->data<<" "<<x->left->data<<endl;
    return x;
}


TreeNode<int>* LeftRotation(TreeNode<int>* y){
    TreeNode<int>* x = y->right;
    TreeNode<int>* T1 = x->left;
    x->left = y;
    y->right = T1;

    y->height = height(y);
    x->height = height(x);

    return x;
}

 TreeNode<int>* RotationType(TreeNode<int>* temp){
    int lh = -1;
    int rh = -1;
    if(temp->left){
        lh = temp->left->height;
    }
    if(temp->right){
        rh = temp->right->height;
    }
    if(lh > rh){
        TreeNode<int>* next = temp->left;

        int nlh = -1;
        int nrh = -1;
        if(next->left){
            nlh = next->left->height;
        }
        if(next->right){
            nrh = next->right->height;
        }
        if(nlh > nrh){
            return RightRotation(temp);
        }
        else{
            temp->left = LeftRotation(temp->left);
            return RightRotation(temp);
        }
    }
    else{
        TreeNode<int>* next = temp->right;
        int nlh = -1;
        int nrh = -1;
        if(next->left){
            nlh = next->left->height;
        }
        if(next->right){
            nrh = next->right->height;
        }
        if(nrh > nlh){
            return LeftRotation(temp);
        }
        else{
            temp->right =  RightRotation(temp->right);
            return LeftRotation(temp);
        }
    }
    return temp;
}

TreeNode<int>* insertion(TreeNode<int>* root, int p){
    TreeNode<int>* temp = root;
    TreeNode<int>* Node = new TreeNode(p,0);

    if(p < temp->data){
        if(temp->left!= NULL){
            temp->left = insertion(temp->left, p);
        }
        else{
            // cout<<"a";
            temp->left = Node;
        }
    }
    else if(p > temp->data){
        if(temp->right != NULL){
            // cout << "pp";
            temp->right = insertion(temp->right, p);
        }
        else{
            temp->right = Node;
        }
    }
    temp->height = height(temp);
    int lh = -1;
    int rh = -1;
    if(temp->left){
        lh = temp->left->height;
    }
    if(temp->right){
        rh = temp->right->height;
    }
    // cout<<lh<<" "<<rh<<endl;
    int BF = abs(lh - rh);
    if(BF>=2){
        // cout<<"ada";
       return RotationType(temp);
    }
    return temp;
}

void search(TreeNode<int>* root, int p){
    TreeNode<int>* temp = root;
    TreeNode<int>* Node = new TreeNode(p,0);

    if(temp == NULL){
        cout << endl << "Not Found" << endl;
    }
    else if(p == temp->data){
        cout << endl << "Found" << endl;
    }
    else if(p < temp->data){
        search(temp->left, p);
    }
    else{
        search(temp->right, p);
    }
}

void printing(TreeNode<int>* root){
    vector<int> path;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();
        path.push_back(cur->data);
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
    for(auto it: path){
        cout << it << " ";
    }
    cout << endl;
}

TreeNode<int>* deletion(TreeNode<int>* root, int p){
    if(root == NULL){
        cout << "Node not Found" << endl;
        return root;
    }
    else if(p < root->data){
        root->left = deletion(root->left, p);
    }
    else if(p > root->data){
        root->right = deletion(root->right, p);
    }
    else{
        if(root->left == NULL){
            TreeNode<int>* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            TreeNode<int>* temp = root->left;
            delete root;
            return temp;
        }
        else{
            TreeNode<int>* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }
    root->height = height(root);
    int lh = -1;
    int rh = -1;
    if(root->left){
        lh = root->left->height;
    }
    if(root->right){
        rh = root->right->height;
    }
    int BF = abs(lh - rh);
    if(BF >= 2){
        return RotationType(root);
    }
    return root;
}


int main(){
    int choice;
    int r;
    cout << "Enter Root Data" << endl;
    cin >> r;
    TreeNode<int>* root= new TreeNode(r, 0);
    root->data = r;
    int n;
    while(true){
        cout << "## Enter 1 for Insertion of Node in AVL tree" << endl;
        cout << "## Enter 2 for Searching of Node in AVL tree" << endl;
        cout << "## Enter 3 for Deletion of Node in AVL tree" << endl;
        cout << "## Enter 4 for Printing AVL tree" << endl;
        cout << "## Enter 0 to Exit" << endl;
        cout << endl <<  "Enter Your Choice" << endl;
        cin >> n;
        if(n == 0){
            break;
        }
        switch (n)
        {
        case 1:
            cout << "Enter Node Value" << endl;
            int p;
            cin >> p;
            root = insertion(root, p);
            // cout<<root->data<<endl;
            // if(root->left) cout<<root->left->data<<" ";
            // if(root->right) cout<<root->right->data<<" ";
            break;
        case 2:
            cout << "Enter Node Value" << endl;
            int c;
            cin >> c;
            search(root, c);
            break;
        case 3:
            cout << "Enter Node To Be Deleted" <<endl;
            int k;
            cin >> k;
            root = deletion(root, k);
            break;
        case 4:
            printing(root);
            break;
        default:
            while (choice < 0 || choice > 4)
            {
                cout << "Wrong Option\n";
                cout << "Input your choice (Number Only): ";
                cin >> choice;

                    if (choice < 0 || choice > 4)
                {
                    continue;
                }
            }
        }
    }
}

