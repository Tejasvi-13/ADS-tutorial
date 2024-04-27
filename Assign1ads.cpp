#include <iostream>
using namespace std;
int n, i;
class book {
public:
  int id, isbn, price;
  char *title, *author, *publisher;
  void accept();
  void display();
  void search();
  void update();
  void Delete();
} b[100];
void book::accept() {
  title = new char;
  author = new char;
  publisher = new char;
  cout << "\nEnter the Book ID : ";
  cin >> id;
  cout << "\nEnter Title of the Book : ";
  cin >> title;
  cout << "\nEnter Author of the Book : ";
  cin >> author;
  cout << "\nEnter Publisher of the Book : ";
  cin >> publisher;
  cout << "\nEnter ISBN NO. of the Book : ";
  cin >> isbn;
  cout << "\nEnter Price of the Book : ";
  cin >> price;
}
void book::display() {
  cout << "\n"
       << id << "\t" << title << "\t" << author << "\t" << publisher << "\t"
       << isbn << "\t" << price;
}
void book::search() {
  int book_id, flag = 0;
  cout << "\nEnter the book id to Search : ";
  cin >> book_id;
  for (i = 0; i < n; i++) {
    if (b[i].id == book_id) {
      flag = 1;
      cout << "\nBook Found At Location " << i + 1;
      b[i].display();
      break;
    }
  }
  if (flag == 0) {
    cout << "Book Not Found";
  }
}
void book::update() {
  int book_id, flag = 0;
  cout << "\nEnter the book id which u want to update : ";
  cin >> book_id;
  for (i = 0; i < n; i++) {
    if (b[i].id == book_id) {
      flag = 1;
      b[i].accept();
      cout << "Your Book record is updated Successfully";
      break;
    }
  }
  if (flag == 0) {
    cout << "Book Not Found";
  }
}
void book::Delete() {
  int book_id, flag = 0;
  cout << "\nEnter the book id which u want to Delete : ";
  cin >> book_id;
  for (i = 0; i < n; i++) {
    if (b[i].id == book_id) {
      flag = 1;
      do {
        b[i] = b[i + 1];
        i++;
      } while (i < n);
      cout << "\nBook Deleted Successfully";
      break;
    }
  }
  if (flag == 0) {
    cout << "\nBook Not Found";
  }
}
int main() {
  int ch;
  cout << "\nEnter Total no. of Book Records : ";
  cin >> n;
  do {
    cout << "\n\n___________________Library Management "
            "System___________________";
    cout << "\nYour Choices are : ";
    cout << "\n1.Accept\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit";
    cout << "\nEnter You choice : ";
    cin >> ch;
    switch (ch) {
    case 1:
      for (i = 0; i < n; i++) {
        b[i].accept();
      }
      break;
    case 2:
      cout << "\nBook ID\tTitle\tAuthor\tPublisher\tISBN No.\tPrice";
      for (i = 0; i < n; i++) {
        b[i].display();
      }
      break;
    case 3:
      b[i].search();
      break;
    case 4:
      b[i].update();
      break;
    case 5:
      b[i].Delete();
    }

  } while (ch != 0);
  return 0;
}
