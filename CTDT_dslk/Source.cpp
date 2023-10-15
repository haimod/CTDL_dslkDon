#include<iostream>
using namespace std;
typedef int typedefData;
struct node {
	typedefData data;
	node* link;
};
typedef node* nodeptr;
nodeptr creatNode(int x) {
	nodeptr p;
	p = new node;
	p->data = x;
	p->link = NULL;
	return p;
}
void themDau(nodeptr& list, nodeptr p) {
	if (list == NULL) {
		list = p;
	}
	else {
		p->link = list;
		list = p;
	}
}
int isEmpty(nodeptr list) {
	return (list == NULL) ? 1 : 0;
}
void themCuoi(nodeptr& list, nodeptr p) {
	
	if (isEmpty(list)) {
		list = p;
	}
	else {
		nodeptr q;
		q = list;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
		p->link = NULL;

	}
}
void creatList(nodeptr& list) {
	list = NULL;
	do {
		int chon, x;
		cout << "\n chon Y(1)/N(0): ";
		cin >> chon;
		if (chon == 1) {
			cout << "\n nhap gia tri: ";
			cin >> x;
			nodeptr p = creatNode(x);
			themCuoi(list, p);
		}
		else {
			break;
		  }
		}
	while (1);
	}
void xuatList(nodeptr list) {
	if (list == NULL) {
		cout << "List is empty." << endl;
		return;
	}

	for (; list != NULL; list = list->link) {
		cout << list->data << " ";
	}
}
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void tangDan(nodeptr& list) {
	for (nodeptr k = list; k->link!=NULL; k = k->link) {
		for (nodeptr t = k->link; t != NULL; t = t->link) {
			if (k->data > t->data) {
				swap(k->data, t->data);
			}
		}
	}
	xuatList(list);
}
int phanTuX(nodeptr list) {
	int k, dem = 0;
	cout << "\n nhap gia tri x: ";
	cin >> k;
	for (nodeptr t = list; t != NULL; t = t->link) {
		if (t->data == k) {
			dem++;
		}
	}
	return dem;
}
nodeptr timPhanTuDauTien(nodeptr list) {
	int x;
	cout << "\n nhap x: ";
	cin >> x;
	nodeptr k = list;
	while (k != NULL) {
		if (k->data == x) {
			return k;
		}
		k = k->link;
	}
	return NULL;
}
nodeptr timPhanTuCuoiCung(nodeptr list) {
	int x;
	nodeptr h = NULL;
	cout << "\n nhap x: ";
	cin >> x;
	nodeptr k = list;
	while (k != NULL) {
		if (k->data == x) {
			h = k;
		}
		k = k->link;
	}
	return h;
}
nodeptr phanTuThuHai(nodeptr list) {
	int s, dem = 0;
	nodeptr h = NULL;
	nodeptr k = list;
	cout << "\n nhap x: ";
	cin >> s;
	while (k != NULL) {
		if (k->data == s) {
			dem++;
		}
		if (dem == 2) {
			h = k;
			break;
		}
		k = k->link;
	}
	return h;
}
int ktTang(nodeptr list) {
	for (nodeptr k = list; k->link != NULL; k = k->link) {
		for (nodeptr h = k->link; h != NULL; h = h->link) {
			if (k->data > h->data) {
				return 0;
			}
		}
	}
	return 1;
}
void tong2PhanTu(nodeptr list) {
		for (nodeptr k = list; k!=NULL && k->link!=NULL && k->link->link!=NULL; k = k->link) {
			if (k->data == k->link->data + k->link->link->data) {
				cout << k->data;
			}
		}
}
void tong2PTtruoc(nodeptr list) {
	if (list == NULL || list->link == NULL || list->link->link == NULL) {
		return;
	}
	for (nodeptr k = list; k->link != NULL && k->link->link != NULL; k = k->link) {
		if (k->data + k->link->data == k->link->link->data) {
			cout << k->link->link->data << " ";
		}
	}
}
bool snt(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
void xuatDCsntDau(nodeptr list) {
	for (nodeptr k = list; k != NULL; k = k->link) {
		if (snt(k->data) == true) {
			cout << k;
			break;
		}
	}
}
bool shh(int x) {
	int sum = 0;
	for (int i = 1; i <= x/2; i++) {
		if (x % i == 0)
			sum += i;
	}
	return sum == x;
}
int demSoHoanHao(nodeptr list) {
	int dem = 0;
	for (nodeptr k = list; k != NULL; k = k->link) {
		if (shh(k->data)) {
			dem++;
		}
	}
	return dem;
}
bool isPerfectSquare(int x) {
	int sqrtX = sqrt(x);
	return sqrtX * sqrtX == x;
}
void cacSoChinhPhuong(nodeptr list) {
	for (nodeptr k = list; k != NULL; k = k->link) {
		if (isPerfectSquare(k->data)) {
			cout << k->data<<" ";
		}
	}
}
int checkCapSoNhan3(nodeptr list) {
	// Nếu linkedlist trống thì không phải là dãy cấp số nhân 3
	if (list == nullptr) {
		return 0;
	}

	// Khởi tạo các biến cần thiết
	nodeptr current = list;
	int common_ratio = current->data;
	while (current->link != nullptr) {
		// Nếu giá trị tiếp theo không là bội số 3 của giá trị hiện tại thì không phải là dãy cấp số nhân 3
		if (current->link->data % common_ratio != 0) {
			return 0;
		}

		current = current->link;
	}

	// Nếu tất cả các giá trị trong linkedlist là bội số 3 của giá trị đầu tiên thì là dãy cấp số nhân 3
	return 1;
}

int soAmLonNhat(nodeptr list) {
	int x = INT_MIN;
	for (nodeptr k = list; k != NULL; k = k->link) {
		if (k->data < 0 && k->data > x) {
			x = k->data;
		}
	}
	return x;
}
void bubbleSortLinkedList(nodeptr &list) {
	// Nếu linkedlist trống thì không cần sắp xếp
	if (list == nullptr) {
		return;
	}

	// Khởi tạo các biến cần thiết
	nodeptr current = list;
	nodeptr next = nullptr;
	bool swapped = true;

	// Lặp qua linkedlist cho đến khi không có sự hoán đổi nào được thực hiện
	while (swapped) {
		swapped = false;
		current = list;
		next = current->link;

		// So sánh các giá trị của hai node liên tiếp
		while (next != nullptr) {
			if (current->data > next->data) {
				// Hoán đổi các giá trị nếu cần thiết
				swap(current->data, next->data);
				swapped = true;
			}

			current = next;
			next = current->link;
		}
	}
}

int main() {
	nodeptr a;
	creatList(a);
	xuatList(a);
	/*cout << "\n ***danh sach sau khi sap xep***";
	tangDan(a);
	cout << "\n so lan xuat hien x trong danh sach la: " << phanTuX(a);*/
	/*nodeptr  result = timPhanTuDauTien(a);
	cout << "\n vi tri cua phan tu x dau tien: ";
	cout << result;
	nodeptr  result1 = timPhanTuCuoiCung(a);
	cout << endl;
	cout << "\n vi tri cua phan tu x cuoi cung: ";
	cout << result1;
	cout << endl;
	nodeptr  result2 = phanTuThuHai(a);
	cout << "\n vi tri cua phan tu x thu 2: ";
	cout << result2;*/
	/*cout << "\n tong bang 2 phan tu lien ke: ";
	tong2PhanTu(a);
	cout << "\n dia chi so nguyen to dau tien la: ";
	xuatDCsntDau(a);*/
	cout << "\n cac so chinh phuong co trong danh sach: ";
	cacSoChinhPhuong(a);
	cout << "\n so am lon nhat la: " << soAmLonNhat(a);
	cout << "\n mang sau khi sap xep";
	bubbleSortLinkedList(a);
	xuatList(a);
	return 0;
}