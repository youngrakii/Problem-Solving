/* 1. Job�̶�� �̸��� Ŭ������ �����մϴ�. �� Ŭ������ �۾� ID, �μ� ��û�� �� ������� �̸�, �μ� ������ �� ������ �����˴ϴ�.
   2. Printer Ŭ������ �����մϴ�. �� Ŭ������ �� �μ� �۾��� �߰��ϰ�, ������� �߰��� ��� �μ� �۾��� ó���ϴ� ����� �����մϴ�.
   3. Printer Ŭ������ �����Ϸ���, ��� �����ǰ� �ִ� �μ� ��û�� �����ؾ� �մϴ�. �μ� ��û�� ���� ��û�� ������� ó���ϴ� ����� �����ϴ�. ��, ���� ���� �μ� ��û���� ó���Ͽ� �μ�˴ϴ�.
   4. ���������� ���� ����� �����Ϳ� �۾��� �߰��ϴ� �ó������� �����ϰ�, �����ʹ� ���ʴ�� �μ� �۾��� �����մϴ�.*/
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
		os << "id: " << j.id << ", �����: " << j.user << ", ������ ��: " << j.pages << "��";
		return os;
	}
};

int Job::count = 0;


// �޸𸮿� ������ �� �ִ� �ִ� �μ� ��û ������ ���ø� ���ڷ� �޴� Ŭ������ ���ø� ���·� �ۼ�
template <size_t N>
class Printer
{
	queue<Job> jobs;

public:
	bool addNewJob(const Job& job) {
		if (jobs.size() == N) {
			cout << "�μ� ��⿭�� �߰� ����: " << job << "\n";
			return false;
		}

		cout << "�μ� ��⿭�� �߰�: " << job << "\n";
		jobs.push(job);
		return true;
	}

	// ���� ����Ʈ�� �����ϴ� �Լ�
	void startPrinting() {
		while (not jobs.empty()) {
			cout << "�μ� ��: " << jobs.front() << "\n";
			jobs.pop();
		}
	}
};

int main() {
	Printer<5> printer;

	Job j1("����", 10);
	Job j2("����", 4);
	Job j3("����", 5);
	Job j4("����", 7);
	Job j5("ä��", 8);
	Job j6("�ÿ�", 10);

	printer.addNewJob(j1);
	printer.addNewJob(j2);
	printer.addNewJob(j3);
	printer.addNewJob(j4);
	printer.addNewJob(j5);
	printer.addNewJob(j6);
	printer.startPrinting();
}