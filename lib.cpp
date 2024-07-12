#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book{
    public:
    struct lib
    {
    string title;
    string author;
    string isbn;
    bool checkedOut;
    };
    public:
    vector<lib> books;

    void addBook(string title,string author,string isbn){
        lib newBook={title,author,isbn,false};
        books.push_back(newBook);
    }
    void displayBook(){
        if(books.empty())
        cout<<"No Books in Book library"<<endl;
        else{
            cout<<"Book Details\n";
            for(int i=0;i<books.size();i++){
                cout<<"\nBook Number "<<(i+1)<<"\n"<<endl;
                cout<<"Book Title  "<<books[i].title<<"\n"<<"Book Author  "<<books[i].author<<"\n"<<"Book ISBN  "<<books[i].isbn<<"\n"<<"Book Status  "<<(books[i].checkedOut?"Not Available":"Available")<<endl;
            }
        }
    }
    void BookSearch(string detail){
        int count=0;
        for(int i=0;i<books.size();i++){
            if(detail==books[i].title||detail==books[i].author||detail==books[i].isbn){
                count++;
                cout<<"Book Title  "<<books[i].title<<"\n"<<"Book Author  "<<books[i].author<<"\n"<<"Book ISBN  "<<books[i].isbn<<"\n"<<"Book Status  "<<(books[i].checkedOut?"Not Available":" Available")<<endl;
            }
        }
        if(count==0){
            cout<<"Book not found!.."<<endl;
        }
    }
    void checkOut(string detail){
        int count=0;
        for(int i=0;i<books.size();i++){
            if(detail==books[i].title||detail==books[i].author||detail==books[i].isbn){
                count++;
                books[i].checkedOut=true;
                cout<<"Book Title  "<<books[i].title<<"\n"<<"Book Author  "<<books[i].author<<"\n"<<"Book ISBN  "<<books[i].isbn<<"\n"<<"Book Status  "<<(books[i].checkedOut?"Not Available":" Available")<<endl;
            }
        }
        if(count==0){
            cout<<"Book not found!.."<<endl;
        }
    }
    void BookReturn(string detail){
        int count=0;
        for(int i=0;i<books.size();i++){
            if(detail==books[i].title||detail==books[i].author||detail==books[i].isbn){
                count++;
                books[i].checkedOut=false;
                cout<<"Book Title  "<<books[i].title<<"\n"<<"Book Author  "<<books[i].author<<"\n"<<"Book ISBN  "<<books[i].isbn<<"\n"<<"Book Status  "<<(books[i].checkedOut?"Not Available":" Available")<<endl;
            }
        }
        if(count==0){
            cout<<"Book not found!.."<<endl;
        }
    }
    void finecalculation(int days){
        if(days>=1){
        cout<<"Fine Amount = ₹"<<(days*2)<<endl;
        }else{
            cout<<"Invalid Entry!.."<<endl;
        }
    }
};
int main(){
    Book book;
    string detail;
    int days,choice;
    book.addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    book.addBook("To Kill a Mockingbird", "Harper Lee", "9780061120084");
    book.addBook("1984", "George Orwell", "9780451524935");
    book.addBook("Pride and Prejudice", "Jane Austen", "9781503290563");
    book.addBook("The Catcher in the Rye", "J.D. Salinger", "9780316769488");
    book.addBook("The Hobbit", "J.R.R. Tolkien", "9780547928227");
    book.addBook("Fahrenheit 451", "Ray Bradbury", "9781451673319");
    book.addBook("The Chronicles of Narnia", "C.S. Lewis", "9780066238500");
    book.addBook("Moby-Dick", "Herman Melville", "9781503280786");
    book.addBook("War and Peace", "Leo Tolstoy", "9780199232765");
    book.displayBook();
    do{
        cout << "\n1. Search book\n";
        cout << "2. Book checkout\n";
        cout << "3. Book return\n";
        cout << "4. Fine calculation\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            cout << "Enter a detail (title, author, or ISBN) to search: ";
            cin.ignore();
            getline(cin,detail);
            book.BookSearch(detail);
            break;
        case 2:
            cout << "Enter a detail (title, author, or ISBN) to checkout book: ";
            cin.ignore();
            getline(cin,detail);
            book.checkOut(detail);
            break;
        case 3:
            cout << "Enter a detail (title, author, or ISBN) to return book: ";
            cin.ignore();
            getline(cin,detail);
            book.BookReturn(detail);
            break;
        case 4:
            cout<<"Enter Number of days for fine calculation: ";
            cin>>days;
            book.finecalculation(days);
            break;
        case 5:
            cout <<"Exiting the Library Management application." << endl;
            break;
        case 6:
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }while(choice!=5);
    return 0;
}