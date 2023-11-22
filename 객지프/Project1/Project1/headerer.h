Book 클래스

private:
	bookname : stringb // 책 이름
		writer : string // 저자   
		publisher : string // 출판사
		genre : string // 장르
		numbering : float // 고유번호
		star_point : float // 별점
		review : string // 리뷰
		page : int // 페이지 수
		rent : bool // 대여 여부
		rentingMemberId : string // 대여한 아이디

public:
	// 생성자: 도서 정보를 초기화
	Book(const string& bookName, const string& writer, const string& publisher, const string& genre,
		float numbering, float starPoint, const string& review, int page, bool rent, string rentId)

		// Getter 메서드들: 속성값을 반환
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

		// Setter 메서드들: 속성값을 설정
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

		// 도서 정보를 화면에 출력하는 메서드
		void display()




		Member 클래스
protected:
	id : string // 아이디
		pw : string // 비밀번호
		name : string // 이름
		job : string // 직업

private:
	vector<string> rentedBooks // 대여 중인 책들의 이름을 저장하는 벡터

public:
	// 주어진 정보로 Member 객체를 초기화하는 생성자
	Member(const string& memberId, const string& password, const string& memberName,
		const string& memberJob)

		// 회원 정보를 얻기 위한 Getter 함수들
		string getId()
		string getPassword()
		string getName()
		string getJob()

		// 대여 중인 책 목록을 얻기 위한 Getter 함수
		const vector<string>& getRentedBooks()

		// 대여한 책을 추가하는 함수
		void addRentedBook(const string& bookName)

		// 대여한 책을 제거하는 함수
		void removeRentedBook(const string& bookName)


		// 회원 정보를 화면에 출력하는 함수
		void display()



	User: Member 클래스(Member클래스 상속)
private:
	booklimit : string // 대여 가능한 권수
		daylimit : string // 대여 가능 기간

public:

	// 추가로 User 클래스의 정보를 초기화
	User(const string& memberId, const string& password, const string& memberName, const string& memberJob,
		int bookLimit, int daysLimit)

		int getBookLimit()
		int getDaysLimit()
		void setBookLimit(int bookLimit)
		void setDaysLimit(int daysLimit)




		BookSystem 클래스
private:

	vector<Book>books // 도서 목록을 저장하는 벡터
		currentMemberId : string // 현재 로그인한 회원의 아이디

public:
	BookSystem() // 생성자 : 파일에서 도서 정보를 읽어옴

		// 특정 회원으로 초기화되는 생성자: 현재 로그인한 회원의 아이디를 설정하고 도서 정보를 읽어옴
		BookSystem(string memberId) : currentMemberId(memberId)

		// 도서 추가 메서드: 새로운 도서를 도서 목록에 추가하고 파일에 저장
		void add_Book(const Book& book)

		// 도서 대여 메서드: 특정 도서를 대여하고 파일에 저장
		bool rent_Book(const string& bookName, const string& memberId)

		// 도서 반납 메서드: 특정 도서를 반납하고 파일에 저장
		bool return_Book(const string& bookName, const string& memberId)

		// 도서 목록 반환 메서드
		const vector<Book>& getBooks()

		// 도서 삭제 메서드: 도서 목록에서 특정 도서를 삭제하고 파일에 저장
		void remove_Book(const string& book_Name)

		// 도서 정보와 파일 저장 메서드
		void book_and_app()

private:

	// 파일에서 책 정보 읽어오기
	void Load_Book_File()

		// 책 정보를 파일에 저장하기
		void save_Book_File()


		Admin : Member 클래스(Member 클래스 상속)
public:
	// Admin 클래스의 생성자. Member 클래스의 생성자를 호출하여 기본 정보를 초기화
	Admin(const string& adminId, const string& password, const string& adminName, const string& adminJob)


		MemberSystem 클래스
private:
	vector<Member> members; // 회원 정보를 저장하는 벡터
	vector<Admin> admins;  // 관리자 정보를 저장하는 벡터

public:
	// 생성자: 회원 및 관리자 정보 파일을 읽어온다.
	MemberSystem()

		// 회원가입 메서드: 새로운 회원 정보를 추가하고 파일에 저장
		void signUp(const Member& member)

		// 로그인 메서드: 입력받은 아이디와 비밀번호로 회원 로그인을 시도하고 결과를 반환
		bool login(const string& id, const string& password)

		// 입력된 아이디가 관리자인지 여부를 확인하는 메서드
		bool isAdmin(const string& id)

		// 관리자 추가 메서드: 새로운 관리자 정보를 추가하고 파일에 저장
		void add_Admin(const Admin& admin)

		// 회원 삭제 메서드: 입력된 아이디에 해당하는 회원을 삭제하고 파일에 저장
		bool deleteMember(const string& id)


		// 도서 대여 메서드: 입력된 아이디로 회원을 찾고 해당 회원이 책을 대여하고 파일에 저장
		bool rentBook(const string& memberId, const string& bookName)

		// 도서 반납 메서드: 입력된 아이디로 회원을 찾고 해당 회원이 책을 반납하고 파일에 저장
		bool returnBook(const string& memberId, const string& bookName)

		// 회원 목록을 화면에 출력하는 메서드
		void displayMembers()

		// 사용자에게 비밀번호를 안전하게 입력받는 메서드
		string getPasswordFromUser()

private:
	// 회원 정보 파일을 읽어오는 메서드
	void Load_Member_File()

		// 회원 정보를 파일에 저장하는 메서드
		void save_Member_File()

		// 회원을 벡터에서 인덱스로 제거하고 파일에 저장하는 메서드
		void removeMemberByIndex(int index)

		// 회원을 번호로 제거하고 파일에 저장하는 메서드
		bool deleteMemberByNumber(int memberNumber)

		// 관리자 정보 파일을 읽어오는 메서드
		void Load_Admin_File()

		// 관리자 정보를 파일에 저장하는 메서드
		void save_Admin_File()


		App 클래스
public:
	// 가상 함수 run: 파생 클래스에서 재정의할 메서드
	virtual void run() = 0

		AdminApp : App(App 클래스 상속)
private:
	BookSystem system; // 도서 관리 시스템
	MemberSystem& memberSystem; // 회원 관리 시스템

public:
	// 생성자: BookSystem 및 MemberSystem을 초기화
	AdminApp(BookSystem& bookSystem, MemberSystem& mSystem)

		// run 메서드: AdminApp의 메인 루프로, 사용자 입력에 따라 각 기능을 수행
		void run() override


private:
	// 메뉴 출력 메서드
	void showMenu()

		// 사용자 선택 입력 메서드
		int getChoice()

		// 도서 목록 출력 메서드
		bool displayBooks()

		// 관리자 추가 메서드
		void addAdmin()

		// 도서 추가 메서드
		void addBook()

		// 회원 목록 출력 메서드
		void displayMembers()


		StudentApp : App(App 클래스 상속)
private:
	BookSystem& system; // 도서 관리 시스템
	string currentMemberId; // 현재 로그인한 학생의 아이디
	MemberSystem memberSystem; // 회원 관리 시스템

public:
	// 생성자: BookSystem 및 학생의 아이디를 초기화한다.
	StudentApp(BookSystem& bookSystem, string Id)

		// run 메서드: StudentApp의 메인 루프로, 사용자 입력에 따라 각 기능을 수행
		void run() override


private:
	// 메뉴 출력 메서드
	void showMenu()

		// 사용자 선택 입력 메서드
		int getChoice()

		// 도서 목록 출력 메서드
		bool displayBooks()

		// 대여 기능 추가
		void rentBook()

		// 반납 기능 추가
		void returnBook()


		LoginApp : App(App 클래스 상속)

private:
	MemberSystem& memberSystem; // 회원 관리 시스템

public:
	// 생성자: MemberSystem을 초기화
	LoginApp(MemberSystem& memSys)

		// run 메서드: LoginApp의 메인 루프로, 사용자 입력에 따라 로그인 또는 회원 가입을 수행
		void run() override
private:

	// 메뉴 출력 메서드
	void showMenu()

		// 사용자 선택 입력 메서드
		int getChoice() const

		// 로그인 기능 추가
		void login()

		// 회원 가입 기능 추가
		void signup()

