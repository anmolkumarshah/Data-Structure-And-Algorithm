#include <iostream>
#include <queue>

using namespace std;

class BinaryTree{
public:
    class Node{
    public:
        int  data;
        Node *left;
        Node *right;
    };
    Node *root;
    queue<Node*> q;
    BinaryTree(int root_data)
    {
        root = new Node();
        root->data = root_data;
        root->left = root->right = nullptr;
        q.push(root);
        Node *p;
        int x;
        while(!q.empty())
        {
            p = q.front();
            q.pop();

            cout<<"Enter Left value of "<<p->data<<"\t";
            cin>>x;
            if(x != -1)
            {
                p->left = new Node();
                p->left->data = x;
                p->left->left = p->left->right = nullptr;
                q.push(p->left);
            }

            cout<<"Enter Right value of "<<p->data<<"\t";
            cin>>x;
            if(x != -1)
            {
                p->right = new Node();
                p->right->data = x;
                p->right->left = p->right->right = nullptr;
                q.push(p->right);
            }
        }
    }

    void preOrder(Node *root)
    {
        if(root)
        {
            cout<<root->data<<"\t";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(Node *root)
    {
        if(root)
        {
            inOrder(root->left);
            cout<<root->data<<"\t";
            inOrder(root->right);
        }
    }
    queue<Node *> q2;
    void levelOrder(Node *root)
    {
        q2.push(root);
        while(!q2.empty())
        {
            Node *p = q2.front();
            cout<<p->data<<"\t";
            q2.pop();
            if(p->left)
            {
                q2.push(p->left);
            }
            if(p->right)
            {
                q2.push(p->right);
            }
        }

    }
    int Count(Node *root)
    {
        int x,y;
        x=y=0;
        if(root)
        {
            x = Count(root->left);
            y = Count(root->right);
            return x+y+1;
        }
        return 0;
    }

    int Height(Node *root)
    {
        int x,y;
        x = y = 0;
        if(root)
        {
            x = Height(root->left);
            y = Height(root->right);
            if(x>y)
                return x+1;
            else
                return y+1;
        }
        return 0;
    }
};

int main()
{
    BinaryTree b(10);
    b.preOrder(b.root);
    cout<<endl;
    b.inOrder(b.root);
    cout<<endl;
    b.levelOrder(b.root);
    cout<<endl<<b.Count(b.root);
    cout<<endl<<b.Height(b.root);
    return 0;
}
