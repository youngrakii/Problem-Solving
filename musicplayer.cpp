/* 여러 개의 음악을 이용하여 재생 목록을 생성할 수 있습니다.
   재생 목록에 음악을 추가할 수 있어야 합니다.
   재생 목록에서 음악을 제거할 수 있어야 합니다.
   음악을 순환적으로 재생할 수 있어야 합니다.(이 기능의 구현은 노래 제목 출력으로 대신합니다.*/





   //필요한 헤더 파일 포함하고 필요한 데이터 멤버를 가지는 노드 구조체 정의

#include <iostream>
using namespace std;

template <typename T>
struct cir_list_node
{
	T* data;
	cir_list_node* next;
	cir_list_node* prev;

	~cir_list_node()
	{
		delete data;
	}
};

template <typename T>
struct cir_list
{
public:
	using node = cir_list_node<T>;
	using node_ptr = node*;
private:
	node_ptr head;
	size_t n;
public:
	cir_list() :n(0)
	{
		head = new node{ NULL, NULL, NULL };
		head->next = head;
		head->prev = head;
	}
	size_t size() const
	{
		return n;
	}

	void insert(const T& value) {
		node_ptr newNode = new node{ new T(value), NULL, NULL };
		n++;
		auto dummy = head->prev;
		dummy->next = newNode;
		newNode->prev = dummy;
		if (head == dummy)
		{
			dummy->prev = newNode;
			newNode->next = dummy;
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	void erase(const T& value) {
		auto cur = head, dummy = head->prev;
		while (cur != dummy) {
			if (*(cur->data) == value)
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				if (cur == head)
					head = head->next;
				delete cur;
				n--;
				return;
			}
			cur = cur->next;
		}
	}

	// cir_list에서 사용할 반복자를 정의하고, 실제 원소 데이터에 접근하는 함수

	struct cir_list_it
	{
	private:
		node_ptr ptr;
	public:
		cir_list_it(node_ptr p) : ptr(p) {}

		T& operator*()
		{
			return *(ptr->data);
		}

		node_ptr get()
		{
			return ptr;
		}

		cir_list_it& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		cir_list_it operator++(int) {
			cir_list_it it = *this;
			++(*this);
			return it;
		}

		cir_list_it& operator--()
		{
			ptr = ptr->prev;
			return*this;
		}

		cir_list_it operator--(int) {
			cir_list_it it = *this;
			--(*this);
			return it;
		}

		friend bool operator==(const cir_list_it& it1, const cir_list_it& it2)
		{
			return it1.ptr == it2.ptr;
		}

		friend bool operator!=(const cir_list_it& it1, const cir_list_it& it2)
		{
			return it1.ptr != it2.ptr;
		}
	};

	cir_list_it begin() {
		return cir_list_it{ head };
	}

	cir_list_it begin() const
	{
		return cir_list_it{ head };
	}

	cir_list_it end() {
		return cir_list_it{ head->prev };
	}
	cir_list_it end() const
	{
		return cir_list_it{ head->prev };
	}

	cir_list(const cir_list<T>& other) : cir_list() {
		for (const auto& i : other)
			insert(i);
	}

	cir_list(const std::initializer_list<T>& il) :head(NULL), n(0)
	{
		for (const auto& i : il)
			insert(i);
	}
	~cir_list()
	{
		while (size()) {
			erase(*(head->data));
		}

		delete head;
	}

};

struct playlist {
	cir_list<int> list;

	void insert(int song) {
		list.insert(song);
	}
	void erase(int song) {
		list.erase(song);
	}

	void loopOnce()
	{
		for (auto& song : list)
			cout << song << " ";
		cout << "\n";
	}
};

int main() {
	playlist pl;
	pl.insert(1);
	pl.insert(2);
	cout << "재생 목록 : ";
	pl.loopOnce();

	playlist pl2 = pl;
	pl2.erase(2);
	pl2.insert(3);
	cout << "두 번째 재생 목록 : ";
	pl2.loopOnce();
}