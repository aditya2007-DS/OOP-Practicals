/*Assignment 3
Publication class*/
#include<iostream>
#include<string>
using namespace std;

class Publication {
protected:
  string title;
  double price;
  int copies;
  
public:
  Publication(string t, double p, int c) {
    title = t;
    price = p;
    copies = c;
  }
  virtual double saleCopy() {
    return price*copies;
  }
  virtual void_display() {
    cout << "Title: " << title << endl;
    cout << "Price: " << price << endl;
    cout << "Copies: " << copies << endl;
  }
  virtual ~Publication() {}
};

class Book : public Publication {
private:
  string author;

public:
  Book(string t, double p, int c, string a) : Publication(t, p, c) {
    author = a;
  }
  void orderCopies(int qty) {
    copies +=qty;
    cout << qty << "book copies ordered." << endl;
  }
  double saleCopy() override {
    return price*copies;
  }
  void display() override {
    cout << "\n--- Book Details ---" << endl;
    Publication::display();
    cout << "Author: " << author << endl;
  }
};
class Magazine : public Publication {
private:
  int orderQty;
public:
  Magazine(string t, double p, int c, int q) : Publication(t, p, c) {
    orderQty = q;
  }
  void receiveIssue() {
    copies += orderQty;
    cout << orderQty << "magazine copies received." << endl;
  }
  double saleCopy() override {
    return price*copies;
  }
  void display() override {
    cout << "\n--- Magazine Details ---" << endl;
    Publication::display();
    cout << "Order Quantity: " << orderQty << endl;
  }
};

int main() {
  Book b("C++ Programming", 500, 10, "Bjarne Stroustrup");
  
  Magazine m("Tech World", 150, 20, 30);
  
  b.orderCopies(5);
  m.receiveIssue();
  
  Publication* p1 = &b;
  Publication* p2 = &m;
  
  p1->display();
  p2->display();
  
  double totalSales = p1->saleCopy() + p2->saleCopy();
  
  cout << "\nTotal Publication Sales: Rs. " << totalSales << endl;
  
  return 0;
}
