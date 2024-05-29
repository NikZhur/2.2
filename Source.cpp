#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int* createMasN(int N, int &tim) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	start = steady_clock::now();
	int* arr = new int[N];
	for (int* i = arr; i != arr + N; i++) {
		*i = rand() % 100;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "��� ������:\n";
	for (int* i = arr; i != arr + N; i++) {
		cout << *i << " ";
	}
	cout << "\n\n";
	tim = result.count();
	return arr;
}

int* createMas(int& el) {
	int* arr = new int[0];
	int N;
	int i = 0;
	cout << "������� Enter, ����� ��������� ���� ���������\n\n";
	while (cin >> N) {
		if (cin.get() == '\n') {
			break;
		}
		i++;
		int* rez = new int[i];
		for (int j = 0; j < i - 1; j++)
			rez[j] = arr[j];
		delete[] arr;
		arr = rez;
		arr[i - 1] = N;
	}
	i++;
	int* rez = new int[i];
	for (int j = 0; j < i - 1; j++)
		rez[j] = arr[j];
	delete[] arr;
	arr = rez;
	arr[i - 1] = N;
	cout << "\n��� ������:\n";
	for (int j = 0; j < i; j++) {
		cout << arr[j] << " ";
	}
	cout << "\n\n" << "���������� ��������� � �������: " << i << "\n\n";
	el = i;
	return arr;
}

int* newElem(int *arr, int &N, int &tim2) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	cout << "������� ������ ������ ��������:\n";
	int ind;
	cin >> ind;
	if (ind > N || ind < 0) {
		cout << "������ ������� �� ������������� ���������� ����������� �������\n";
		return arr;
	}
	else {
		int perem;
		cout << "\n������� ����� �������:\n";
		cin >> perem;
		start = steady_clock::now();
		int* rez = new int[N + 1];
		for (int j = 0; j < ind; j++)
			rez[j] = arr[j];
		for (int j = ind; j < N; j++)
			rez[j + 1] = arr[j];
		delete[] arr;
		arr = rez;
		arr[ind] = perem;
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "\n��� ������:\n";
		for (int j = 0; j < N + 1; j++) {
			cout << arr[j] << " ";
		}
		N = N + 1;
		cout << "\n\n" << "���������� ��������� � �������: " << N << "\n\n";
		tim2 = result.count();
		return arr;
	}
}

int* deleteElem_ind(int* arr, int &N, int &tim3) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	cout << "������� ������ ��������, ������� ������ �������:\n";
	int ind;
	cin >> ind;
	if (ind > N - 1 || ind < 0) {
		cout << "������ ������� �� ������������� ���������� ����������� �������\n";
		return arr;
	}
	else {
		start = steady_clock::now();
		int* rez = new int[N - 1];
		for (int j = 0; j < ind; j++)
			rez[j] = arr[j];
		for (int j = ind; j < N - 1; j++)
			rez[j] = arr[j + 1];
		delete[] arr;
		arr = rez;
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "\n��� ������:\n";
		for (int j = 0; j < N - 1; j++) {
			cout << arr[j] << " ";
		}
		N = N - 1;
		cout << "\n\n" << "���������� ��������� � �������: " << N << "\n\n";
		tim3 = result.count();
		return arr;
	}
}

int* deleteElem_num(int* arr, int& N) {
	cout << "������� ��������, ������� ������ ������� �� �������:\n";
	int ind;
	cin >> ind;
	int k = 0;
	int* mass = new int[N];
	for (int i = 0; i < N; i++) {
		mass[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] == ind) {
			mass[k] = i;
			k++;
		}
	}
	if (k == 0) {
		cout << "������ �������� � ������� ���\n";
		return arr;
	}
	int dop = N;
	int i = 0;
	while (mass[i] >= -1) {
		int* rez = new int[N - 1];
		for (int j = 0; j < mass[i]; j++)
			rez[j] = arr[j];
		for (int j = mass[i]; j < N - 1; j++)
			rez[j] = arr[j + 1];
		delete[] arr;
		arr = rez;
		N = N - 1;
		for (int i = 0; i < dop; i++) {
			mass[i] -= 1;
		}
		i++;
	}
	delete[] mass;
	cout << "\n��� ������:\n";
	for (int j = 0; j < N; j++) {
		cout << arr[j] << " ";
	}
	cout << "\n\n" << "���������� ��������� � �������: " << N << "\n\n";
	return arr;
}

int* swapElem(int* arr, int& N) {
	cout << "������� ������� ���������, ������� ������ ��������:\n";
	int num1, num2;
	cin >> num1;
	cin >> num2;
	if (num1 < 0 || num1 >= N || num2 < 0 || num2 >= N) {
		cout << "�������� � ����� �������� ���\n";
		return arr;
	}
	int perem = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = perem;
	cout << "\n��� ������:\n";
	for (int j = 0; j < N; j++) {
		cout << arr[j] << " ";
	}
	cout << "\n\n" << "���������� ��������� � �������: " << N << "\n\n";
	return arr;
}

void searchElem_ind(int* arr, int& N, int &tim4) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	cout << "������� ������ ��������, ����� �������� ���\n";
	int ind;
	cin >> ind;
	int res;
	if (ind < 0 || ind >= N) {
		cout << "�������� � ����� �������� ���\n";
	}
	else {
		start = steady_clock::now();
		res = arr[ind];
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		tim4 = result.count();
		cout << "��� �������: " << res;
	}	
}

void searchElem_num(int* arr, int& N) {
	cout << "������� ��������, ������� ������ ��������:\n";
	int ind;
	cin >> ind;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (arr[i] == ind) {
			flag = true;
			cout << "��� ������� �� ��������� " << ind << " ����� ������: " << i << "\n\n";
		}
	}
	if (!flag) {
		cout << "������ �������� ���\n";
	}
}

int* menu(int *p, int * p2, int * p3, int * p4, int * mas, int &N) {
	cout << "������� 1, ���� ������ ������� ������������ ������, ����� ���������� ���������:\n";
	cout << "������� 2, ���� ������ ������� ������������ ������, ����� ���� ���������:\n";
	cout << "������� 3, ���� ������ ������� ����� �������� ������������ ������, ����� ���������� ���������:\n";
	cout << "������� 4, ���� ������ �������� ������� � ������������ ������:\n";
	cout << "������� 5, ���� ������ ������� ����� ���������� ��������:\n";
	cout << "������� 6, ���� ������ ������� ������� �� ������������� ������� �� �������:\n";
	cout << "������� 7, ���� ������ ������� ����� �������� �������� �� �������:\n";
	cout << "������� 8, ���� ������ ������� ������� �� ������������� ������� �� ��������:\n";
	cout << "������� 9, ���� ������ �������� �������� �������\n";
	cout << "������� 10, ���� ������ �������� ������� �� �������:\n";
	cout << "������� 11, ���� ������ ������ ����� ��������� ������� �� �������:\n";
	cout << "������� 12, ���� ������ �������� ������� �� ��������:\n";
	cout << "������� 0, ���� ������ ����� � �������� ����:\n";
	int perem;
	cin >> perem;
	switch (perem) {
	case 1:
		system("cls");
		cout << "������� ���������� ���������:\n";
		int dop;
		dop = N;
		cin >> N;
		int tim;
		tim = 0;
		if (N > 0) {
			delete[] mas;
			mas = createMasN(N, tim);
		}
		else {
			cout << "������� ������������ �����\n";
			N = dop;
		}
		p = &tim;
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 2:
		system("cls");
		delete[] mas;
		mas = createMas(N);
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 3:
		system("cls");
		if (p != 0) {
			cout << "����� ����������: " << *p << " ��" << '\n';
		}
		else {
			cout << "�� ��� �� ������� ������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 4:
		system("cls");
		int tim2;
		tim2 = 0;
		if (mas != 0) {
			cout << "��� ������:\n";
			for (int i = 0; i < N; i++) {
				cout << mas[i] << " ";
			}
			cout << "\n\n\n";
			mas = newElem(mas, N, tim2);
			p2 = &tim2;
			cout << "\n\n\n";
		}
		else {
			cout << "������� �������� ������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 5:
		system("cls");
		if (p2 != 0) {
			cout << "����� ����������: " << *p2 << " ��" << '\n';
		}
		else {
			cout << "�� ��� �� ��������� �������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 6:
		system("cls");
		int tim3;
		tim3 = 0;
		if (mas != 0) {
			cout << "��� ������:\n";
			for (int i = 0; i < N; i++) {
				cout << mas[i] << " ";
			}
			cout << "\n\n\n";
			mas = deleteElem_ind(mas, N, tim3);
			p3 = &tim3;
			cout << "\n\n\n";
		}
		else {
			cout << "������� �������� ������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 7:
		system("cls");
		if (p3 != 0) {
			cout << "����� ����������: " << *p3 << " ��" << '\n';
		}
		else {
			cout << "�� ��� �� ������� �������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 8:
		system("cls");
		if (mas != 0) {
			cout << "��� ������:\n";
			for (int i = 0; i < N; i++) {
				cout << mas[i] << " ";
			}
			cout << "\n\n\n";
			mas = deleteElem_num(mas, N);
			cout << "\n\n\n";
		}
		else {
			cout << "������� �������� ������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 9:
		system("cls");
		if (mas != 0) {
			cout << "��� ������:\n";
			for (int i = 0; i < N; i++) {
				cout << mas[i] << " ";
			}
			cout << "\n\n\n";
			mas = swapElem(mas, N);
			cout << "\n\n\n";
		}
		else {
			cout << "������� �������� ������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 10:
		system("cls");
		int tim4;
		tim4 = 0;
		if (mas != 0) {
			cout << "��� ������:\n";
			for (int i = 0; i < N; i++) {
				cout << mas[i] << " ";
			}
			cout << "\n\n\n";
			searchElem_ind(mas, N, tim4);
			p4 = &tim4;
			cout << "\n\n\n";
		}
		else {
			cout << "������� �������� ������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 11:
		system("cls");
		if (p4 != 0) {
			cout << "����� ����������: " << *p4 << " ��" << '\n';
		}
		else {
			cout << "�� ��� �� �������� �������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 12:
		system("cls");
		if (mas != 0) {
			cout << "��� ������:\n";
			for (int i = 0; i < N; i++) {
				cout << mas[i] << " ";
			}
			cout << "\n\n\n";
			searchElem_num(mas, N);
			cout << "\n\n\n";
		}
		else {
			cout << "������� �������� ������\n";
		}
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	case 0:
		return mas;
	default:
		cout << "������� ������������ �����, ��������� ����\n\n";
		system("Pause");
		system("cls");
		menu(p, p2, p3, p4, mas, N);
		break;
	}
}

struct List
{
	int data;
	List* head;
	List* tail;
};


List* createListL(int len, int& tim) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	start = steady_clock::now();
	List* curr = 0, * next = 0;
	for (int i = 0; i < len; i++)
	{
		curr = new List;
		curr->data = rand() % 100;
		curr->tail = next;
		if (next)
			next->head = curr;
		next = curr;
	}
	curr->head = 0;
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	tim = result.count();
	return curr;
}

List* createList(int& L) {
	List* curr = 0, * prev = 0, *start = 0;
	int N;
	int i = 0;
	cout << "������� Enter, ����� ��������� ���� ���������\n\n";
	while (cin >> N) {
		if (cin.get() == '\n') {
			break;
		}
		i++;
		curr = new List;
		if (i == 1) {
			start = curr;
		}
		curr->data = N;
		curr->head = prev;
		if (prev)
			prev->tail = curr;
		prev = curr;
	}
	i++;
	curr = new List;
	if (i == 1) {
		start = curr;
	}
	curr->data = N;
	curr->head = prev;
	if (prev)
		prev->tail = curr;
	prev = curr;
	curr->tail = 0;
	L = i;
	return start;
}

List* newListelem(List* list, int &L, int &tim2) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	cout << "������� ������, � ������� ������ �������� ����� �������:\n";
	int index;
	cin >> index;
	if (index < 0 || index > L) {
		cout << "������ ������� �� ������������� ���������� ����������� ������\n";
		return list;
	}
	cout << "\n\n������� ����� �������:\n";
	int el;
	cin >> el;
	start = steady_clock::now();
	List* item = new List;
	item->data = el;
	if (!index || !list) {
		list->head = item;
		item->head = 0;
		item->tail = list;
		list = item;
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		tim2 = result.count();
		L++;
		return item;
	}
	List* predItem = list;
	--index;
	while (predItem->tail && (index--)) {
		predItem = predItem->tail;
	}
	item->head = predItem;
	item->tail = predItem->tail;
	predItem->tail = item;
	if (item->tail != 0) {
		item->tail->head = item;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	tim2 = result.count();
	L++;
	return list;
}

List* deleteElemList_ind(List* list, int& L, int& tim3) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	cout << "������� ������ ��������, ������� ������ �������:\n";
	int ind;
	cin >> ind;
	if (ind < 0 || ind >= L) {
		cout << "������ ������� �� ������������� ���������� ����������� ������\n";
		return list;
	}
	start = steady_clock::now();
	List* item;
	if (!ind) {
		item = list->tail;
		delete list;
		list = item;
		if (list != 0) {
			list->head = 0;
		}
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		tim3 = result.count();
		L--;
		return list;
	}
	item = list;
	--ind;
	while (ind--) {
		item = item->tail;
	}
	List* dItem = item->tail;
	item->tail = dItem->tail;
	if (item->tail != 0) {
		item->tail->head = item;
	}
	delete dItem;
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	tim3 = result.count();
	L--;
	return list;
}

List* deleteElemList(List* list, int& L, int ind) {
	if (ind < 0 || ind >= L) {
		cout << "������ ������� �� ������������� ���������� ����������� ������\n";
		return list;
	}
	List* item;
	if (!ind) {
		item = list->tail;
		delete list;
		list = item;
		if (list != 0) {
			list->head = 0;
		}
		L--;
		return list;
	}
	item = list;
	--ind;
	while (ind--) {
		item = item->tail;
	}
	List* dItem = item->tail;
	item->tail = dItem->tail;
	if (item->tail != 0) {
		item->tail->head = item;
	}
	delete dItem;
	L--;
	return list;
}

List* deleteElemList_num(List* list, int& L) {
	cout << "������� ��������, ������� ������ ������� �� ������:\n";
	int num;
	cin >> num;
	int k = 0;
	int* mass = new int[L];
	for (int i = 0; i < L; i++) {
		mass[i] = -1;
	}
	List* curr = 0;
	curr = list;
	int ind = 0;
	while (curr) {
		if (curr->data == num) {
			mass[k] = ind;
			k++;
		}
		curr = curr->tail;
		ind++;
	}
	if (k == 0) {
		cout << "������ �������� � ������ ���\n";
		return list;
	}

	int dop = L;
	int i = 0;
	while (mass[i] >= -1) {
		list = deleteElemList(list, L, mass[i]);
		for (int i = 0; i < dop; i++) {
			mass[i] -= 1;
		}
		i++;
	}
	delete[] mass;
	return list;
}


void deleteList(List*& list)
{
	List* next;
	while (list)
	{
		next = list->tail;
		delete list;
		list = next;
	}
}


List* listItem(List* list, int index) {
	while (list && (index--))
		list = list->tail;
	return list;
}



List* swapEl(List* list, int &L) {	
	cout << "������� ������� ���������, ������� ������ ��������:\n";
	int num1, num2;
	cin >> num1;
	cin >> num2;
	if (num1 < 0 || num1 >= L || num2 < 0 || num2 >= L) {
		cout << "�������� � ����� �������� ���\n";
		return list;
	}
	if (num1 - num2 == 0) {
		cout << "�������� ���������\n";
		return list;
	}
	int temp;
	if (num2 < num1) {
		temp = num2;
		num2 = num1;
		num1 = temp;
	}
	List* lst1 = listItem(list, num1);
	List* lst2 = listItem(list, num2);
	struct List* prev1, * prev2, * next1, * next2;
	prev1 = lst1->head;
	prev2 = lst2->head;
	next1 = lst1->tail;
	next2 = lst2->tail;
	if (lst2 == next1) {
		lst2->tail = lst1;
		lst2->head = prev1;
		lst1->tail = next2;
		lst1->head = lst2;
		if (next2 != NULL)
			next2->head = lst1;
		if (lst1 != list)
			prev1->tail = lst2;
	}
	else if (lst1 == next2) {
		lst1->tail = lst2;
		lst1->head = prev2;
		lst2->tail = next1;
		lst2->head = lst1;
		if (next1 != NULL)
			next1->head = lst2;
		if (lst2 != list)
			prev2->tail = lst1;
	}
	else {
		if (lst1 != list)
			prev1->tail = lst2;
		lst2->tail = next1;
		if (lst2 != list)
			prev2->tail = lst1;
		lst1->tail = next2;
		lst2->head = prev1;
		if (next2 != NULL)
			next2->head = lst1;
		lst1->head = prev2;
		if (next1 != NULL)
			next1->head = lst2;
	}
	if (lst1 == list)
		return(lst2);
	if (lst2 == list)
		return(lst1);
	return list;
}

void searchElemList_ind(List* list, int &L, int& tim4) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	cout << "������� ������ ��������, ����� �������� ���\n";
	int ind;
	cin >> ind;
	int res;
	if (ind < 0 || ind >= L) {
		cout << "�������� � ����� �������� ���\n";
	}
	else {
		start = steady_clock::now();
		List* curr = list;
		while (ind--)
			curr = curr->tail;
		res = curr->data;
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		tim4 = result.count();
		cout << "��� �������: " << res << "\n\n";
	}
}

void searchElemList_num(List* list, int& L) {
	cout << "������� ��������, ������� ������ ��������:\n";
	int num;
	cin >> num;
	bool flag = false;
	List* curr = 0;
	curr = list;
	int count = 0;
	while (curr)
	{
		if (curr->data == num) {
			cout << "��� ������� �� ��������� " << num << " ����� ������: " << count << "\n\n";
			flag = true;
		}
		curr = curr->tail;
		count++;
	}
	if (!flag) {
		cout << "������ �������� ���\n";
	}
}


List* menuList(int* m, int* m2, int* m3, int* m4, List* list, int &L) {
	cout << "������� 1, ���� ������ ������� ���������� ������, ����� ���������� ���������:\n";
	cout << "������� 2, ���� ������ ������� ���������� ������, ����� ���� ���������:\n";
	cout << "������� 3, ���� ������ ������� ����� �������� ����������� ������, ����� ���������� ���������:\n";
	cout << "������� 4, ���� ������ �������� ������� � ���������� ������:\n";
	cout << "������� 5, ���� ������ ������� ����� ���������� ��������:\n";
	cout << "������� 6, ���� ������ ������� ������� �� ����������� ������ �� �������:\n";
	cout << "������� 7, ���� ������ ������� ����� �������� �������� �� �������:\n";
	cout << "������� 8, ���� ������ ������� ������� �� ����������� ������ �� ��������:\n";
	cout << "������� 9, ���� ������ �������� �������� �������\n";
	cout << "������� 10, ���� ������ �������� ������� �� �������:\n";
	cout << "������� 11, ���� ������ ������ ����� ��������� ������� �� �������:\n";
	cout << "������� 12, ���� ������ �������� ������� �� ��������:\n";
	cout << "������� 0, ���� ������ ����� � �������� ����:\n";
	int perem;
	cin >> perem;
	switch (perem) {
		case 1:
			system("cls");
			cout << "������� ���������� ���������:\n";
			int dop;
			dop = L;
			cin >> L;
			int tim;
			tim = 0;
			if (L > 0) {
				deleteList(list);
				list = createListL(L, tim);
				cout << "��� ������:\n";
				List* curr = 0;
				curr = list;
				while (curr)
				{
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
			}
			else {
				cout << "������� ������������ �����\n";
				L = dop;
			}
			m = &tim;
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 2:
			system("cls");
			deleteList(list);
			list = createList(L);
			cout << "��� ������:\n";
			List* curr;
			curr = list;
			while (curr) {
				cout << curr->data << ' ';
				curr = curr->tail;
			}
			cout << "\n\n";
			cout << "���������� ��������� � ������: " << L << "\n\n";
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 3:
			system("cls");
			if (m != 0) {
				cout << "����� ����������: " << *m << " ��" << '\n';
			}
			else {
				cout << "�� ��� �� ������� ������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 4:
			system("cls");
			int tim2;
			tim2 = 0;
			if (list != 0) {
				cout << "��� ������:\n";
				List* curr;
				curr = list;
				while (curr) {
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
				list = newListelem(list, L, tim2);
				cout << '\n';
				m2 = &tim2;
				cout << "��� ������:\n";
				curr = list;
				while (curr)
				{
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
			}
			else {
				cout << "������� �������� ������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 5:
			system("cls");
			if (m2 != 0) {
				cout << "����� ����������: " << *m2 << " ��" << '\n';
			}
			else {
				cout << "�� ��� �� ��������� �������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 6:
			system("cls");
			int tim3;
			tim3 = 0;
			if (list != 0) {
				cout << "��� ������:\n";
				List* curr;
				curr = list;
				while (curr) {
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
				list = deleteElemList_ind(list, L, tim3);
				cout << '\n';
				m3 = &tim3;
				cout << "��� ������:\n";
				curr = list;
				while (curr)
				{
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
			}
			else {
				cout << "������� �������� ������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 7:
			system("cls");
			if (m3 != 0) {
				cout << "����� ����������: " << *m3 << " ��" << '\n';
			}
			else {
				cout << "�� ��� �� ������� �������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 8:
			system("cls");
			if (list != 0) {
				cout << "��� ������:\n";
				List* curr;
				curr = list;
				while (curr) {
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
				list = deleteElemList_num(list, L);
				cout << '\n';
				cout << "��� ������:\n";
				curr = list;
				while (curr)
				{
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
			}
			else {
				cout << "������� �������� ������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 9:
			system("cls");
			if (list != 0) {
				cout << "��� ������:\n";
				List* curr;
				curr = list;
				while (curr) {
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
				list = swapEl(list, L);
				cout << '\n';
				cout << "��� ������:\n";
				curr = list;
				while (curr)
				{
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
			}
			else {
				cout << "������� �������� ������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 10:
			system("cls");
			int tim4;
			tim4 = 0;
			if (list != 0) {
				cout << "��� ������:\n";
				List* curr;
				curr = list;
				while (curr) {
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
				searchElemList_ind(list, L, tim4);
				m4 = &tim4;
			}
			else {
				cout << "������� �������� ������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 11:
			system("cls");
			if (m4 != 0) {
				cout << "����� ����������: " << *m4 << " ��" << '\n';
			}
			else {
				cout << "�� ��� �� �������� �������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 12:
			system("cls");
			if (list != 0) {
				cout << "��� ������:\n";
				List* curr;
				curr = list;
				while (curr) {
					cout << curr->data << ' ';
					curr = curr->tail;
				}
				cout << "\n\n";
				searchElemList_num(list, L);
			}
			else {
				cout << "������� �������� ������\n";
			}
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
		case 0:
			return list;
		default:
			cout << "������� ������������ �����, ��������� ����\n\n";
			system("Pause");
			system("cls");
			menuList(m, m2, m3, m4, list, L);
			break;
	}
}


List* idzList(List* list, int& L) {
	List* curr = 0;
	curr = list;
	while (curr) {
		curr->data += rand() % 6;
		curr = curr->tail;
	}
	cout << "��������������� ������:\n";
	curr = list;
	while (curr)
	{
		cout << curr->data << ' ';
		curr = curr->tail;
	}
	cout << "\n\n";
	return list;
}

int* idz(int* arr, int &N, List* list, int &L) {
	List* curr = 0;
	curr = list;
	while (curr) {
		if (curr->data > 0) {
			int* rez = new int[N + 1];
			for (int i = 0; i < N; i++)
				rez[i] = arr[i];
			delete[] arr;
			arr = rez;
			arr[N] = curr->data;
			N = N + 1;
		}
		curr = curr->tail;
	}
	
	cout << "\n��������������� ������:\n";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";
	return arr;
}


void menuML(int* p, int* p2, int* p3, int* p4, int* mas, int &N, int* m, int* m2, int* m3, int* m4, List* list, int &L) {
	cout << "������� 1, ���� ������ �������� � ������������ ��������;\n";
	cout << "������� 2, ���� ������ �������� � ��������� �������;\n";
	cout << "������� 3, ���� ������ ��������� ���;\n";
	cout << "������� 0, ���� ������ ����� �� ���������:\n";
	int perem;
	cin >> perem;
	switch (perem) {
	case 1:
		system("cls");
		mas = menu(p, p2, p3, p4, mas, N);
		system("cls");
		menuML(p, p2, p3, p4, mas, N, m, m2, m3, m4, list, L);
		break;
	case 2:
		system("cls");
		list = menuList(m, m2, m3, m4, list, L);
		system("cls");
		menuML(p, p2, p3, p4, mas, N, m, m2, m3, m4, list, L);
		break;
	case 3:
		system("cls");
		cout << "��������� ������:\n";
		List* curr;
		curr = list;
		while (curr)
		{
			cout << curr->data << ' ';
			curr = curr->tail;
		}
		cout << "\n\n";
		list = idzList(list, L);
		cout << "\n��������� ������:\n";
		for (int i = 0; i < N; i++) {
			cout << mas[i] << " ";
		}
		cout << "\n";
		mas = idz(mas, N, list, L);
		system("Pause");
		system("cls");
		menuML(p, p2, p3, p4, mas, N, m, m2, m3, m4, list, L);
		break;
	case 0:
		break;
	default:
		cout << "������� ������������ �����, ��������� ����\n\n";
		system("Pause");
		system("cls");
		menuML(p, p2, p3, p4, mas, N, m, m2, m3, m4, list, L);
		break;
	}
}

int main() {
	setlocale(0, "");
	int* p = 0;
	int* p2 = 0;
	int* p3 = 0;
	int* p4 = 0;
	int* mas = 0;
	int N = 0;
	int* m = 0;
	int* m2 = 0;
	int* m3 = 0;
	int* m4 = 0;
	List* list = 0;
	int L = 0;
	menuML(p, p2, p3, p4, mas, N, m, m2, m3, m4, list, L);
	delete[] mas;
	deleteList(list);
	return 0;
}