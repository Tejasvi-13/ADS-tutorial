#include<iostream>
using namespace std;
int cnt=0;
class FMT
{
  public:
    string name,bd,dd,bg,gender;
    int gen,age;
    FMT *rchild,*lchild;
    void accept();
    void display();
    void insert(FMT *root,FMT *next);
    void preorder(FMT *root);
    }*root;
    void FMT::accept()
    {
     int ch;
   FMT *next;
     root=new FMT();
     cout<<"Enter data such as name,bd,dd,bg,gender,gen,age:";
     cin>>root->name>>root->bd>>root->dd>>root->bg>>root->gender>>root->gen>>root->age;
     root->rchild=root->lchild=NULL;
     cnt++;
     do
     {
        cout<<"Do you want  to add new family member information press 1";
        cin>>ch;
        if(ch==1)
        {
          next=new FMT;
          cout<<"Enter the data for new family member";
          cin>>next->name>>next->bd>>next->dd>>next->bg>>root->gender>>root->gen>>root->age;
           next->rchild=next->lchild=NULL;
          insert(root,next);
          }
        }while(ch==1);
     }
     void FMT::insert(FMT *root,FMT *next)
     {
      char chr;
      cout<<"Enter where you want to insert the root node(L or R):";
      cin>>chr;
      if(chr=='l' || chr=='L')
      {
        if(root->lchild==NULL)
        {
           root->lchild=next;
           cnt++;
        }
        else
        {
          insert(root->lchild,next);
         }
      }
      else if(chr=='r' || chr=='R')
      {
        if(root->rchild==NULL)
        {
           root->rchild=next;
           cnt++;
        }
        else
        {
          insert(root->rchild,next);
         }
      }
     }
     void FMT::preorder(FMT *root)
     {
       if(root==NULL)
          return;
       else
       {
         cout<<"\n"<<root->name<<"\t"<<root->bd<<"\t"<<root->dd<<"\t"<<root->bg<<"\t"<<root->gender<<"\t"<<root->gen<<"\t"<<root->age;
         preorder(root->lchild);
        preorder(root->rchild);
       }
     }
     int main()
{
    int chc;
    FMT t;
    
    do
    {
        cout << "Your Choices are:\n";
        cout << "1. Accept\n";
        cout << "2. Display\n";
        cout << "3. Exit\n";
        cout << "Enter Your choice: ";
        cin >> chc;
        
        switch (chc)
        {
        case 1:
            t.accept();
            break;
        case 2:
            cout << "Displaying FMT Data:\n";
            t.preorder(root); // Assuming root is a global variable
            break;
        case 3:
            cout << "Exiting...\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (chc != 3); // Loop until user chooses to exit

    return 0;
}

