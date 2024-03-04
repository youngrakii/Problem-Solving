/* 1. Job이라는 이름의 클래스를 생성합니다. 이 클래스는 작업 ID, 인쇄 요청을 한 사용자의 이름, 인쇄 페이지 수 등으로 구성됩니다.
   2. Printer 클래스를 생성합니다. 이 클래스는 새 인쇄 작업을 추가하고, 현재까지 추가된 모든 인쇄 작업을 처리하는 기능을 제공합니다.
   3. Printer 클래스를 구현하려면, 모든 지연되고 있는 인쇄 요청을 저장해야 합니다. 인쇄 요청은 먼저 요청된 순서대로 처리하는 방식을 따릅니다. 즉, 가장 빠른 인쇄 요청부터 처리하여 인쇄됩니다.
   4. 마지막으로 여러 사람이 프린터에 작업을 추가하는 시나리오를 구현하고, 프린터는 차례대로 인쇄 작업을 수행합니다.*/
#include <iostream>
#include <queue>
using namespace std;

class Job {
	int id;
	string user;
	int pages;

	static int count;

public:
	Job(const string& u, int p) : user(u), pages(p), id(++count) {}

	friend ostream& operator << (ostream& os, const Job& j) {
		os << "id: " << j.id << ", 사용자: " << j.user << ", 페이지 수: " << j.pages << "장";
		return os;
	}
};

int Job::count = 0;


// 메모리에 저장할 수 있는 최대 인쇄 요청 개수를 템플릿 인자로 받는 클래스를 템플릿 형태로 작성
template <size_t N>
class Printer
{
	queue<Job> jobs;

public:
	bool addNewJob(const Job& job) {
		if (jobs.size() == N) {
			cout << "인쇄 대기열에 추가 실패: " << job << "\n";
			return false;
		}

		cout << "인쇄 대기열에 추가: " << job << "\n";
		jobs.push(job);
		return true;
	}

	// 실제 프린트를 수행하는 함수
	void startPrinting() {
		while (not jobs.empty()) {
			cout << "인쇄 중: " << jobs.front() << "\n";
			jobs.pop();
		}
	}
};

int main() {
	Printer<5> printer;

	Job j1("광희", 10);
	Job j2("정다", 4);
	Job j3("현수", 5);
	Job j4("유미", 7);
	Job j5("채원", 8);
	Job j6("시원", 10);

	printer.addNewJob(j1);
	printer.addNewJob(j2);
	printer.addNewJob(j3);
	printer.addNewJob(j4);
	printer.addNewJob(j5);
	printer.addNewJob(j6);
	printer.startPrinting();
}