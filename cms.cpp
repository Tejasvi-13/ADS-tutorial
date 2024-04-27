class CMS
{
  public:
  int did,amt;
  long int cn;
  string name,add;
  cms *next,*prev;
  void accept();
  void display();
  void search();
  void modify();
  void Delete();
  void count_R();
}*start,*end1;
void CMS::accept()
{
  CMS *nnode;
  nnode=new CMS;
  cout<<"\nEnter The Doner Details: ";
  cout<<"\n Enter Doner id: ";
  cin>>nnode->did;
  cout<<"\nEnter the Name of the Doner :";
  cin>>nnode->name;
  cout<<"\nEnter the Address of the doner: ";
  cin>>nnode->add;
  cout<<"\nEnter the Donated amount";
  cin>>nnode->amt;
  cout<<"\nEnter the Contact no.";
  cin>>nnode->cn;
  nnode->next=nnode->prev=NULL;
  if(start==NULL)
  {
   end1=start=nnode;
  }
  else
  {
   end1->next=nnode;
   nnode->prev=end1;
   end1=nnode;
   }
}
void CMS::display() {
int count=0;
CMS temp;
temp=start;
if(temp==NULL)
{
  cout<<"\nList is Empty";
 }
 else{
 while(temp!=NULL)
 {
  cout << "\n"
       << temp->did "\t" <<temp->name"\t" << temp->add "\t" << temp->amt "\t"<< temp->cn;
       temp=temp->next;
       count++;
  }
  }
  cout<<"\n No. of Records are : "<<count;
}  
void CMS::search()
{                       
  int id,f=0;
  cout<<"\n Enter the doner u want to search: ";
  cin>>id;
  CMS *temp;

  temp=start;
  while(temp != NULL)
  {
    if(id==temp->did)
    {
     f=1;
     cout<<"\n record is found";
     cout<<"\n"<<temp->did<<"\t"<<temp->name<<"\t"<<temp->add<<"\t"<<temp->amt<<"\t"<<temp->cn ;
     break;
     
     }
     temp=temp->next;
  }
  if(f==0)
  cout<<"\n Record is not found";
  
}  
int main() {
  CMS c;
  int ch,i;
  
  do {
 
    cout<<"_________Charity management system____________";
    cout << "\nYour Choices are : ";
    cout << "\n1.Accept\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit";
    cout << "\nEnter You choice : ";
    cin>>ch;
    switch(ch) {
    case 1:
      
     c.accept();
      break;
    case 2:
      cout<<"_________Doner Information________<<endl;
      cout<<"\n DID\tName\tADDRESS\tAMOUNT\tCONTACT_NO";
       c.display();
    
      break;
    case 3:
      c.search();
      break;
    
    }

  } while (ch != 0);
  return 0;
}
