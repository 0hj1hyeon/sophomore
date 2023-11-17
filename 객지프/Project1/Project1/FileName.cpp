#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

// Book Ŭ����: ���� ������ ��Ÿ���� Ŭ����
class Book {
private:
    // ���� ������ �Ӽ���
    string bookname;
    string writer;
    string publisher;
    string genre;
    float numbering;
    float star_point;
    string review;
    int page;
    bool rent;
    string rentingMemberId; // �뿩 ���� ȸ���� ���̵�

public:
    // ������: ���� ������ �ʱ�ȭ
    Book(const string& bookName, const string& writer, const string& publisher, const string& genre, float numbering, float starPoint, const string& review, int page, bool rent, string rentId)
        : bookname(bookName), writer(writer), publisher(publisher), genre(genre), numbering(numbering), star_point(starPoint), review(review), page(page), rent(rent), rentingMemberId(rentId) {}

    // Getter �޼����: �Ӽ����� ��ȯ
    string getBookName() const {
        return bookname;
    }
    string getWriter() const {
        return writer;
    }
    string getPublisher() const {
        return publisher;
    }
    string getGenre() const {
        return genre;
    }
    float getNumbering() const {
        return numbering;
    }
    float getStarPoint() const {
        return star_point;
    }
    string getReview() const {
        return review;
    }
    int getPage() const {
        return page;
    }
    bool isRented() const {
        return rent;
    }

    // Setter �޼����: �Ӽ����� ����
    void setBookName(const string& bookName) {
        bookname = bookName;
    }
    void setWriter(const string& writer) {
        this->writer = writer;
    }
    void setPublisher(const string& publisher) {
        this->publisher = publisher;
    }
    void setGenre(const string& genre) {
        this->genre = genre;
    }
    void setNumbering(float numbering) {
        this->numbering = numbering;
    }
    void setStarPoint(float starPoint) {
        star_point = starPoint;
    }
    void setReview(const string& review) {
        this->review = review;
    }
    void setPage(int page) {
        this->page = page;
    }
    void setRentStatus(bool rent) {
        this->rent = rent;
    }

    // ���� ������ ȭ�鿡 ����ϴ� �޼���
    void display() const {
        cout << "���� �̸�: " << bookname << endl;
        cout << "����: " << writer << endl;
        cout << "���ǻ�: " << publisher << endl;
        cout << "�帣: " << genre << endl;
        cout << "������ȣ: " << numbering << endl;
        cout << "����: " << star_point << endl;
        cout << "����: " << review << endl;
        cout << "������ ��: " << page << endl;
        cout << "�뿩 ����: " << (rent ? "�뿩 ��" : "�뿩 ����") << endl;
        cout << "------------------------" << endl;
    }


    string getRentingMemberId() const {
        return rentingMemberId;
    }

    // �뿩 ���� ����
    void setRentingStatus(bool rent, const string& memberId) {
        this->rent = rent;
        rentingMemberId = memberId;
    }
};


class Member {
protected:
    string id;
    string pw;
    string name;
    string job;

private:
    vector<string> rentedBooks; // �뿩 ���� å���� �̸��� �����ϴ� ����

public:
    Member(const string& memberId, const string& password, const string& memberName, const string& memberJob)
        : id(memberId), pw(password), name(memberName), job(memberJob) {}

    string getId() const {
        return id;
    }

    string getPassword() const {
        return pw;
    }

    string getName() const {
        return name;
    }

    string getJob() const {
        return job;
    }


    const vector<string>& getRentedBooks() const {
        return rentedBooks;
    }

    // �뿩�� å �߰�
    void addRentedBook(const string& bookName) {
        rentedBooks.push_back(bookName);
    }

    // �뿩�� å ����
    void removeRentedBook(const string& bookName) {
        auto it = find(rentedBooks.begin(), rentedBooks.end(), bookName);
        if (it != rentedBooks.end()) {
            rentedBooks.erase(it);
        }
    }

    void display() const {
        cout << "���̵�: " << id << endl;
        cout << "��й�ȣ: " << pw << endl;
        cout << "�̸�: " << name << endl;
        cout << "����: " << job << endl;
    }
};



class User : public Member {
private:
    int booklimit; // �뿩 ������ �� ��
    int daylimit;  // �뿩 ���� �Ⱓ 

public:
    User(const string& memberId, const string& password, const string& memberName, const string& memberJob,
        int bookLimit, int daysLimit)
        : Member(memberId, password, memberName, memberJob), booklimit(bookLimit), daylimit(daysLimit) {}

    int getBookLimit() const {
        return booklimit;
    }

    int getDaysLimit() const {
        return daylimit;
    }

    void setBookLimit(int bookLimit) {
        booklimit = bookLimit;
    }

    void setDaysLimit(int daysLimit) {
        daylimit = daysLimit;
    }
};

// BookSystem Ŭ����: ���� ���� �ý����� ��Ÿ���� Ŭ����
class BookSystem {
private:
    // ���� ����� �����ϴ� ����
    vector<Book> books;
    string currentMemberId; // ���� �α����� ȸ���� ���̵�

public:
    // ������: ���Ͽ��� ���� ������ �о��
    BookSystem() {
        Load_Book_File();
    }

    BookSystem(string memberId) : currentMemberId(memberId) {
        Load_Book_File();
    }
    // ���� �߰� �޼���: ���ο� ������ ���� ��Ͽ� �߰��ϰ� ���Ͽ� ����
    void add_Book(const Book& book) {
        books.push_back(book);

        for (const Book& book : books) {
            book.display();
        }
        save_Book_File();
    }

    // ���� ���� �޼���: ���� ��Ͽ��� Ư�� ������ �����ϰ� ���Ͽ� ����
    void remove_Book(const string& book_Name) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getBookName() == book_Name;
            });

        if (it != books.end()) {
            books.erase(it);
            save_Book_File();
            cout << book_Name << "�� ���� �Ǿ����ϴ�." << endl;
        }
        else {
            cout << book_Name << "�̶�� ������ �����ϴ�." << endl;
        }
    }

    // ���� ��� ��ȯ �޼���
    const vector<Book>& getBooks() const {

        return books;
    }


    void book_and_app() {
        save_Book_File();
    }


    // ���� �뿩 �޼���: Ư�� ������ �뿩�ϰ� ���Ͽ� ����
    bool rent_Book(const string& bookName, const string& memberId) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getBookName() == bookName;
            });

        if (it != books.end()) {
            if (!it->isRented()) {
                it->setRentingStatus(true, memberId);
                save_Book_File();
                cout << bookName << "��(��) �뿩�Ǿ����ϴ�." << endl;
                return true; // �뿩 ���� �� true ��ȯ
            }

            else {
                cout << bookName << "��(��) �̹� �뿩 ���Դϴ�." << endl;
            }
        }
        else {
            cout << bookName << "��(��)��� ������ �����ϴ�." << endl;
        }

        return false; // �뿩 ���� �� false ��ȯ
    }

    // ���� �ݳ� �޼���: Ư�� ������ �ݳ��ϰ� ���Ͽ� ����
    bool return_Book(const string& bookName, const string& memberId) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getBookName() == bookName && book.isRented() && book.getRentingMemberId() == memberId;
            });

        if (it != books.end()) {
            it->setRentingStatus(false, "");
            save_Book_File();
            cout << bookName << "��(��) �ݳ��Ǿ����ϴ�." << endl;
            return true; // ���������� �ݳ��� ��� true ��ȯ
        }
        else {
            cout << "�ش� ������ �뿩 ���� ȸ���� �ƴϰų� ������ �������� �ʽ��ϴ�." << endl;
            return false; // �ݳ� ������ ��� false ��ȯ
        }
    }

    ~BookSystem() {
        save_Book_File();
    }




private:
    // ���Ͽ��� å ���� �о����
    void Load_Book_File() {
        ifstream file("books.txt");

        if (file.is_open()) {
            books.clear();

            string bookName, writer, publisher, genre, review, getRentingMemberId;
            float numbering, starPoint;
            int page;
            bool rent;

            while (file >> bookName >> writer >> publisher >> genre >> numbering >> starPoint >> review >> page >> rent >> getRentingMemberId) {
                Book book(bookName, writer, publisher, genre, numbering, starPoint, review, page, rent, getRentingMemberId);
                books.push_back(book);
            }

            file.close();
        }
    }



    // å ������ ���Ͽ� �����ϱ�
    void save_Book_File() {
        ofstream file("books.txt");

        if (file.is_open()) {
            for (const Book& book : books) {
                file << book.getBookName() << " " << book.getWriter() << " " << book.getPublisher() << " " << book.getGenre()
                    << " " << book.getNumbering() << " " << book.getStarPoint() << " " << book.getReview() << " " << book.getPage()
                    << " " << (book.isRented() ? 1 : 0) << " " << book.getRentingMemberId() << endl;
            }
            file.close();
        }
    }
};

class MemberSystem {
private:
    vector<Member> members;

public:

    MemberSystem() {
        Load_Member_File();
    }

    void signUp(const Member& member) {

        members.push_back(member);
        save_Member_File();
        cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
    }

    bool login(const string& id, const string& password) {
        for (const Member& member : members) {
            if (member.getId() == id && member.getPassword() == password) {
                cout << "�α��� ����!" << endl;
                return true;
            }
        }
        cout << "�α��� ����. ���̵� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
        return false;
    }

    bool deleteMember(const string& id) {
        auto it = find_if(members.begin(), members.end(), [&](const Member& member) {
            return member.getId() == id;
            });

        if (it != members.end()) {
            members.erase(it);
            Load_Member_File();
            cout << id << " ȸ���� �����Ǿ����ϴ�." << endl;
            return true;
        }
        else {
            cout << "�ش� ���̵��� ȸ���� ã�� �� �����ϴ�." << endl;
            return false;
        }
    }






    bool rentBook(const string& memberId, const string& bookName) {
        auto it = find_if(members.begin(), members.end(), [&](const Member& member) {
            return member.getId() == memberId;
            });

        if (it != members.end()) {
            it->addRentedBook(bookName);
            save_Member_File();
            cout << bookName << "��(��) �뿩�Ǿ����ϴ�." << endl;
            return true;
        }
        else {
            cout << "�ش� ���̵��� ȸ���� ã�� �� �����ϴ�." << endl;
            return false;
        }
    }

    // å �ݳ� ��� �߰�
    bool returnBook(const string& memberId, const string& bookName) {
        auto it = find_if(members.begin(), members.end(), [&](const Member& member) {
            return member.getId() == memberId;
            });

        if (it != members.end()) {
            it->removeRentedBook(bookName);
            save_Member_File();
            cout << bookName << "��(��) �ݳ��Ǿ����ϴ�." << endl;
            return true;
        }
        else {
            cout << "�ش� ���̵��� ȸ���� ã�� �� �����ϴ�." << endl;
            return false;
        }
    }









    void displayMembers() {
        if (members.empty()) {
            cout << "ȸ�� ����� ��� �ֽ��ϴ�." << endl;
        }
        else {
            cout << "ȸ�� ���: " << endl;
            for (size_t i = 0; i < members.size(); ++i) {
                cout << "ȸ�� ��ȣ: " << i + 1 << endl;
                members[i].display();
                cout << "-------------------" << endl;
            }

            int deleteMemberNumber;
            cout << "������ ȸ���� ��ȣ�� �Է��ϼ��� (0: ���): ";
            cin >> deleteMemberNumber;

            if (deleteMemberNumber > 0 && deleteMemberNumber <= members.size()) {
                // ȸ�� ����
                removeMemberByIndex(deleteMemberNumber - 1);
            }
            else if (deleteMemberNumber != 0) {
                cout << "�߸��� ȸ�� ��ȣ�Դϴ�." << endl;
            }
        }
    }



    string getPasswordFromUser() {
        string password = "";
        char ch;
        while (true) {
            ch = _getch(); // Ű �Է��� �н��ϴ�.
            if (ch == 13) // Enter Ű�� �ԷµǸ� �Է� ����.
                break;
            else if (ch == 8) { // �齺���̽� Ű�� �ԷµǸ� ������ ���� ����.
                if (password.length() > 0) {
                    password.pop_back();
                    cout << "\b \b"; // �齺���̽��� ���� ���� ���ڸ� ȭ�鿡�� ����ϴ�.
                }
            }
            else {
                password.push_back(ch); // ��й�ȣ�� ���� �߰�.
                cout << '*'; // ��ǥ�� ǥ��.
            }
        }
        cout << endl;
        return password;
    }

private:

    void Load_Member_File() {
        ifstream file("members.txt");
        if (file.is_open()) {
            members.clear();
            string id, password, name, job;
            while (file >> id >> password >> name >> job) {
                Member member(id, password, name, job);
                members.push_back(member);
            }
            file.close();
        }
    }


    void save_Member_File() {
        ofstream file("members.txt");
        if (file.is_open()) {
            for (const Member& member : members) {
                file << member.getId() << " " << member.getPassword() << " " << member.getName() << " " << member.getJob() << endl;
            }
            file.close();
        }
    }



    void removeMemberByIndex(int index) {
        members.erase(members.begin() + index);
        save_Member_File();
        cout << "ȸ�� ������ �Ϸ�Ǿ����ϴ�." << endl;
    }

    bool deleteMemberByNumber(int memberNumber) {
        if (memberNumber > 0 && memberNumber <= members.size()) {
            removeMemberByIndex(memberNumber - 1);
            return true;
        }
        else {
            cout << "�߸��� ȸ�� ��ȣ�Դϴ�." << endl;
            return false;
        }
    }
};



// Book_App Ŭ����: ���� ���� ���ø����̼��� ��Ÿ���� Ŭ����
class Book_App {
private:
    BookSystem system;
    MemberSystem memberSystem;
    string currentMemberId; // ���� �α����� ȸ���� ���̵�

public:
    // ������
    Book_App(string id) : currentMemberId(id), system() {
    }



    // ���ø����̼� ���� �޼���
    void run() {
        while (true) {
            try {
                showMenu();
                int choice = getChoice();

                switch (choice) {
                case 0:
                    cout << "���α׷��� �����մϴ�." << endl;
                    return;
                case 1:
                    display_Books();
                    break;
                case 2: {
                    if (!display_Books()) {
                        break;
                    }
                    string bookName;



                    cout << "������ ���� �̸��� �Է��ϼ���: ";
                    cin.ignore();
                    getline(cin, bookName);
                    system.remove_Book(bookName);
                    break;
                }
                case 3:
                    Add_Book();
                    break;
                case 4:
                    rentBook();
                    break;
                case 5:
                    returnBook();
                    break;
                default:
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                }
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl; // ���� �޽��� ���
            }
        }
    }



    // �޴� ��� �޼���
    void showMenu() const {
        cout << "���� ���� ���α׷�" << endl;
        cout << "1. ���� ��ȸ" << endl;
        cout << "2. ���� ����" << endl;
        cout << "3. ���� �߰�" << endl;
        cout << "4. ���� �뿩" << endl;
        cout << "5. ���� �ݳ�" << endl;
        cout << "0. ����0" << endl;
        cout << "�޴� ����: " << endl;
    }

    // ����� �Է� �޴� �޼���
    int getChoice() const {
        int choice;
        cin >> choice;
        return choice;
    }

    // ���� ��� ��� �޼���
    bool display_Books() const {
        const vector<Book>& books = system.getBooks();

        if (books.empty()) {
            cout << "���� ����� ��� �ֽ��ϴ�." << endl;
            return 0;
        }
        else {
            cout << "���� ���: " << endl;
            for (const Book& book : books) {
                book.display();
            }
        }
    }


    // �뿩 ��� �߰�
    void rentBook() {
        if (currentMemberId.empty()) {
            cout << "�α����� �ʿ��մϴ�." << endl;
            return;
        }

        string bookName;
        cout << "�뿩�� ���� �̸��� �Է��ϼ���: ";
        cin.ignore();
        getline(cin, bookName);

        if (system.rent_Book(bookName, currentMemberId)) {
            memberSystem.rentBook(currentMemberId, bookName);
        }
    }

    // �ݳ� ��� �߰�
    void returnBook() {
        if (currentMemberId.empty()) {
            cout << "�α����� �ʿ��մϴ�." << endl;
            return;
        }

        string bookName;
        cout << "�ݳ��� ���� �̸��� �Է��ϼ���: ";
        cin.ignore();
        getline(cin, bookName);

        if (system.return_Book(bookName, currentMemberId)) {
            memberSystem.returnBook(currentMemberId, bookName);
        }
    }



    // ���ο� ���� �߰� �޼���
    void Add_Book() {
        try {
            string bookName, writer, publisher, genre, review;
            float numbering, starPoint;
            int page;
            bool rent = 0;
            string rentId = "����";

            cout << "���� �̸�: ";
            cin.ignore();
            getline(cin, bookName);
            cout << "����: ";
            getline(cin, writer);
            cout << "���ǻ�: ";
            getline(cin, publisher);
            cout << "�帣: ";
            getline(cin, genre);
            cout << "������ȣ: ";
            cin >> numbering;
            cout << "����: ";
            cin >> starPoint;
            cout << "����: ";
            cin.ignore();
            getline(cin, review);
            cout << "������ ��: ";
            cin >> page;

            Book newBook(bookName, writer, publisher, genre, numbering, starPoint, review, page, rent, rentId);
            system.add_Book(newBook);
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl; // ���� �޽��� ���
        }
    }

    void setcurrentMemberId(string id) {
        currentMemberId = id;
    }

    string getcurrentMemberId() {
        return currentMemberId;
    }
};

class Member_App {
private:
    MemberSystem system;
    string cuid;


public:
    Member_App() {}

    void run() {
        while (true) {
            try {
                showMenu();
                int choice = getChoice();

                switch (choice)
                {
                case 0:
                    cout << "���α׷��� �����մϴ�." << endl;
                    break;
                case 1:
                    Login();
                    break;
                case 2:
                    signup();
                    break;
                case 3: {
                    string deleteId;
                    cout << "ȸ�� ����" << endl;
                    cout << "������ ȸ���� ���̵�: ";
                    cin >> deleteId;
                    system.deleteMember(deleteId); // ȸ�� ���� �Լ� ȣ��
                    break;
                }
                case 4:
                    system.displayMembers();
                    break;
                default:
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                    break;
                }
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl; // ���� �޽��� ���
            }
        }
    }

    void showMenu() const {
        cout << "�α��� ���α׷�" << endl;
        cout << "1. �α���" << endl;
        cout << "2. ȸ�� ����" << endl;
        cout << "3. ȸ�� ����" << endl;
        cout << "4. ȸ�� ��ȸ�� ����" << endl;
        cout << "0. ����" << endl;
        cout << "��ɾ� ����: " << endl;
    }

    int getChoice() const {
        int choice;
        cin >> choice;
        return choice;
    }

    void Login() {
        string id = "", password = "";
        cout << "�α���" << endl;
        cout << "���̵�: ";
        cin >> id;
        cin.ignore(); // ���� �Է� ���۸� ���ϴ�.
        cout << "��й�ȣ: ";
        password = system.getPasswordFromUser(); // ��й�ȣ �Է� �Լ� ȣ��.
        if (system.login(id, password)) { // �α��� �Լ� ȣ��
            Book_App App(id);
            App.run();
        }
    }

    void signup() {
        string id = "", password = "", name = "", job = "";
        User newUser("", "", "", "", 0, 0);

        // ȸ�� ���� �Է�
        cout << "ȸ������" << endl;
        cout << "���̵�: ";
        cin >> id;
        cout << "��й�ȣ: ";
        cin >> password;
        cout << "�̸�: ";
        cin >> name;
        cout << "����: ";
        cin >> job;
        newUser = User(id, password, name, job, 5, 15); // ���÷� bookLimit�� daysLimit�� �ʱⰪ���� ����
        system.signUp(newUser);                   // ȸ������ �Լ� ȣ��

    }

};








int main() {
    Member_App App;
    App.run();
    return 0;
}




