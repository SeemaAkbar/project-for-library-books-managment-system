#include<iostream>
#include<string>
#include<vector>
using namespace std;
//creat class for book
class Book{
	public:
		int id;
		string author;
		string title;
		string status;//Available or Returned
		//constructor
		Book(int i,string a,string t){
			id=i;
			author=a;
			title=t;
			status="Available";
		}
void display(){
	cout<<"ID:"<<id;
	cout<<"\nTitle:"<<title;
	cout<<"\nAuthor:"<<author;
	cout<<"\nstatus:"<<status<<endl;
}
};
//Global vector(an array which hold a list of iteams) to store many books
vector<Book>books;
//add functions
void addbook(){
	int id;
	string title,author;
	cout<<"Add a new Book\n";
	cout<<"Enter book ID:";
	cin>>id;
	cout<<"Enter book title:";
	cin>>title;
	cout<<"Enter book Author: ";
	cin>>author;
	Book newbook(id,title,author);
	books.push_back(newbook);
	cout<<"\n Book added sucessfully\n";
 
}
//view all books function

void viewBooks(){
	if(books.size()==0 ){
		cout<<"No books found in library yet! "<<endl;
		return;
	}
	cout<<"All Books"<<endl;
	for(int i=0;i<books.size() ;i++){
		books[i].display();
	}
}
//search book function by ID
void searchBook(){
	int id;
	cout<<"Enter book id to search:";
	cin>>id;
	bool found =false;
	for(int i=0;i<books.size() ;i++){
		if(books[i].id==id) 
		cout<<"Book found:"<<endl;
		books[i].display();
		found=true;
		break;
	}
if (found){
	cout<<"Book with ID:"<<id<<"\nnot found!"<<endl;
}
}
//Return book function
void returnBook(){
	int id;
	cout<<"Enter book id to return:";
	cin>>id;
	for(int i=0;i<books.size();i++){
		if(books[i].id==id){
			books[i].status="\nAvailable";
			cout<<"Book Returned successfully!"<<endl;
			return;
		}
	}
	cout<<"\nBook ID not found"<<endl;	
}
int main(){
	int choice;
	do{
		cout<<"Library Managment System"<<endl;
		cout<<"1.Add Book"<<endl;
		cout<<"2.view All Books"<<endl;
		cout<<"3.search Book"<<endl;
		cout<<"4.Return Book"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"enter your choice";
		cin>>choice;
		cin.ignore();
		//using if else
		if(choice==1){
			addbook();
		}
		else if(choice==2){
			viewBooks();
		}
		else if(choice==3){
			searchBook();
		}
		else if(choice==4){
			returnBook();
		}
		else if(choice==5){
			cout<<"Thank you! Exiting Program."<<endl;
		}
		else{
			cout<<"Invalid choice! Try again."<<endl;
		}
	}
	while(choice!=5);
	//repeat menu until exit
	return 0;
}
