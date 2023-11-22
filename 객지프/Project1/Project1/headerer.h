Book Ŭ����

private:
	bookname : stringb // å �̸�
		writer : string // ����   
		publisher : string // ���ǻ�
		genre : string // �帣
		numbering : float // ������ȣ
		star_point : float // ����
		review : string // ����
		page : int // ������ ��
		rent : bool // �뿩 ����
		rentingMemberId : string // �뿩�� ���̵�

public:
	// ������: ���� ������ �ʱ�ȭ
	Book(const string& bookName, const string& writer, const string& publisher, const string& genre,
		float numbering, float starPoint, const string& review, int page, bool rent, string rentId)

		// Getter �޼����: �Ӽ����� ��ȯ
		string getBookName()
		string getWriter()
		string getPublisher()
		string getGenre()
		float getNumbering()
		float getStarPoint()
		string getReview()
		int getPage()
		bool isRented()
		string getRentingMemberId()

		// Setter �޼����: �Ӽ����� ����
		void setBookName(const string& bookName)
		void setWriter(const string& writer)
		void setPublisher(const string& publisher)
		void setGenre(const string& genre)
		void setNumbering(float numbering)
		void setStarPoint(float starPoint)
		void setReview(const string& review)
		void setPage(int page)
		void setRentStatus(bool rent)
		void setRentingStatus(bool rent, const string& memberId)

		// ���� ������ ȭ�鿡 ����ϴ� �޼���
		void display()




		Member Ŭ����
protected:
	id : string // ���̵�
		pw : string // ��й�ȣ
		name : string // �̸�
		job : string // ����

private:
	vector<string> rentedBooks // �뿩 ���� å���� �̸��� �����ϴ� ����

public:
	// �־��� ������ Member ��ü�� �ʱ�ȭ�ϴ� ������
	Member(const string& memberId, const string& password, const string& memberName,
		const string& memberJob)

		// ȸ�� ������ ��� ���� Getter �Լ���
		string getId()
		string getPassword()
		string getName()
		string getJob()

		// �뿩 ���� å ����� ��� ���� Getter �Լ�
		const vector<string>& getRentedBooks()

		// �뿩�� å�� �߰��ϴ� �Լ�
		void addRentedBook(const string& bookName)

		// �뿩�� å�� �����ϴ� �Լ�
		void removeRentedBook(const string& bookName)


		// ȸ�� ������ ȭ�鿡 ����ϴ� �Լ�
		void display()



	User: Member Ŭ����(MemberŬ���� ���)
private:
	booklimit : string // �뿩 ������ �Ǽ�
		daylimit : string // �뿩 ���� �Ⱓ

public:

	// �߰��� User Ŭ������ ������ �ʱ�ȭ
	User(const string& memberId, const string& password, const string& memberName, const string& memberJob,
		int bookLimit, int daysLimit)

		int getBookLimit()
		int getDaysLimit()
		void setBookLimit(int bookLimit)
		void setDaysLimit(int daysLimit)




		BookSystem Ŭ����
private:

	vector<Book>books // ���� ����� �����ϴ� ����
		currentMemberId : string // ���� �α����� ȸ���� ���̵�

public:
	BookSystem() // ������ : ���Ͽ��� ���� ������ �о��

		// Ư�� ȸ������ �ʱ�ȭ�Ǵ� ������: ���� �α����� ȸ���� ���̵� �����ϰ� ���� ������ �о��
		BookSystem(string memberId) : currentMemberId(memberId)

		// ���� �߰� �޼���: ���ο� ������ ���� ��Ͽ� �߰��ϰ� ���Ͽ� ����
		void add_Book(const Book& book)

		// ���� �뿩 �޼���: Ư�� ������ �뿩�ϰ� ���Ͽ� ����
		bool rent_Book(const string& bookName, const string& memberId)

		// ���� �ݳ� �޼���: Ư�� ������ �ݳ��ϰ� ���Ͽ� ����
		bool return_Book(const string& bookName, const string& memberId)

		// ���� ��� ��ȯ �޼���
		const vector<Book>& getBooks()

		// ���� ���� �޼���: ���� ��Ͽ��� Ư�� ������ �����ϰ� ���Ͽ� ����
		void remove_Book(const string& book_Name)

		// ���� ������ ���� ���� �޼���
		void book_and_app()

private:

	// ���Ͽ��� å ���� �о����
	void Load_Book_File()

		// å ������ ���Ͽ� �����ϱ�
		void save_Book_File()


		Admin : Member Ŭ����(Member Ŭ���� ���)
public:
	// Admin Ŭ������ ������. Member Ŭ������ �����ڸ� ȣ���Ͽ� �⺻ ������ �ʱ�ȭ
	Admin(const string& adminId, const string& password, const string& adminName, const string& adminJob)


		MemberSystem Ŭ����
private:
	vector<Member> members; // ȸ�� ������ �����ϴ� ����
	vector<Admin> admins;  // ������ ������ �����ϴ� ����

public:
	// ������: ȸ�� �� ������ ���� ������ �о�´�.
	MemberSystem()

		// ȸ������ �޼���: ���ο� ȸ�� ������ �߰��ϰ� ���Ͽ� ����
		void signUp(const Member& member)

		// �α��� �޼���: �Է¹��� ���̵�� ��й�ȣ�� ȸ�� �α����� �õ��ϰ� ����� ��ȯ
		bool login(const string& id, const string& password)

		// �Էµ� ���̵� ���������� ���θ� Ȯ���ϴ� �޼���
		bool isAdmin(const string& id)

		// ������ �߰� �޼���: ���ο� ������ ������ �߰��ϰ� ���Ͽ� ����
		void add_Admin(const Admin& admin)

		// ȸ�� ���� �޼���: �Էµ� ���̵� �ش��ϴ� ȸ���� �����ϰ� ���Ͽ� ����
		bool deleteMember(const string& id)


		// ���� �뿩 �޼���: �Էµ� ���̵�� ȸ���� ã�� �ش� ȸ���� å�� �뿩�ϰ� ���Ͽ� ����
		bool rentBook(const string& memberId, const string& bookName)

		// ���� �ݳ� �޼���: �Էµ� ���̵�� ȸ���� ã�� �ش� ȸ���� å�� �ݳ��ϰ� ���Ͽ� ����
		bool returnBook(const string& memberId, const string& bookName)

		// ȸ�� ����� ȭ�鿡 ����ϴ� �޼���
		void displayMembers()

		// ����ڿ��� ��й�ȣ�� �����ϰ� �Է¹޴� �޼���
		string getPasswordFromUser()

private:
	// ȸ�� ���� ������ �о���� �޼���
	void Load_Member_File()

		// ȸ�� ������ ���Ͽ� �����ϴ� �޼���
		void save_Member_File()

		// ȸ���� ���Ϳ��� �ε����� �����ϰ� ���Ͽ� �����ϴ� �޼���
		void removeMemberByIndex(int index)

		// ȸ���� ��ȣ�� �����ϰ� ���Ͽ� �����ϴ� �޼���
		bool deleteMemberByNumber(int memberNumber)

		// ������ ���� ������ �о���� �޼���
		void Load_Admin_File()

		// ������ ������ ���Ͽ� �����ϴ� �޼���
		void save_Admin_File()


		App Ŭ����
public:
	// ���� �Լ� run: �Ļ� Ŭ�������� �������� �޼���
	virtual void run() = 0

		AdminApp : App(App Ŭ���� ���)
private:
	BookSystem system; // ���� ���� �ý���
	MemberSystem& memberSystem; // ȸ�� ���� �ý���

public:
	// ������: BookSystem �� MemberSystem�� �ʱ�ȭ
	AdminApp(BookSystem& bookSystem, MemberSystem& mSystem)

		// run �޼���: AdminApp�� ���� ������, ����� �Է¿� ���� �� ����� ����
		void run() override


private:
	// �޴� ��� �޼���
	void showMenu()

		// ����� ���� �Է� �޼���
		int getChoice()

		// ���� ��� ��� �޼���
		bool displayBooks()

		// ������ �߰� �޼���
		void addAdmin()

		// ���� �߰� �޼���
		void addBook()

		// ȸ�� ��� ��� �޼���
		void displayMembers()


		StudentApp : App(App Ŭ���� ���)
private:
	BookSystem& system; // ���� ���� �ý���
	string currentMemberId; // ���� �α����� �л��� ���̵�
	MemberSystem memberSystem; // ȸ�� ���� �ý���

public:
	// ������: BookSystem �� �л��� ���̵� �ʱ�ȭ�Ѵ�.
	StudentApp(BookSystem& bookSystem, string Id)

		// run �޼���: StudentApp�� ���� ������, ����� �Է¿� ���� �� ����� ����
		void run() override


private:
	// �޴� ��� �޼���
	void showMenu()

		// ����� ���� �Է� �޼���
		int getChoice()

		// ���� ��� ��� �޼���
		bool displayBooks()

		// �뿩 ��� �߰�
		void rentBook()

		// �ݳ� ��� �߰�
		void returnBook()


		LoginApp : App(App Ŭ���� ���)

private:
	MemberSystem& memberSystem; // ȸ�� ���� �ý���

public:
	// ������: MemberSystem�� �ʱ�ȭ
	LoginApp(MemberSystem& memSys)

		// run �޼���: LoginApp�� ���� ������, ����� �Է¿� ���� �α��� �Ǵ� ȸ�� ������ ����
		void run() override
private:

	// �޴� ��� �޼���
	void showMenu()

		// ����� ���� �Է� �޼���
		int getChoice() const

		// �α��� ��� �߰�
		void login()

		// ȸ�� ���� ��� �߰�
		void signup()

