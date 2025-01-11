#include"algorithms.h"


/*
2024.12.15��ϰ
��һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�
С���ӳ����������º�ÿ��������һ�����ӣ��������Ӷ�������
��ÿ���µ���������Ϊ���٣�
*/
void test1() {
	//�˼��ϵĳ��ȱ������Ӷ���
	vector<int> v;

	//��һ�����ӣ����������������δ����ѭ�����㻹û�п�ʼ��
	int rab = 0;
	v.push_back(rab);

	int mouth = 1;
	while (mouth < 20) {
		//���������³���С����������־��Ϊ�˷�ֹ������ʧЧ�������ڵ���������ֱ���޸�
		int addrabbitdata = 0;
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			//�·ݿ�ʼѭ������ÿ�����ӵ��·ݽ���+1
			//��Ҫ��+1�ٽ����Ƿ������жϣ��������ֱ������������Ѿ������������£�����ֵ��ʾ��2�����²���������
			(*it)++;
			if ((*it) > 2) {
				addrabbitdata++;
			}
		}
		while (addrabbitdata > 0)
		{
			/*��������������Ѿ�����ѭ����������û�в���ǰ���+1
			�ڴ�ѭ��������һ���¾ͽ����ˣ������������1���£���˳�ֵ����Ϊ1��
			 ���ǲ��ܵ����¸�������+1��Ȼ��˵�����������ϸ���û��һ�㡱
			*/
			int newrab = 1;
			v.push_back(newrab);
			addrabbitdata--;
		}
		cout << "��ǰ�·�Ϊ����" << mouth << "���£���ǰ��������Ϊ��" << v.size() * 2 << "ֻ" << endl;
		mouth++;
	}
}

/*
* 2024.12.16
�ж�101-200֮���ж��ٸ��������������������
*/

void test2() {
	cout << "101-200�У������У�";
	for (int num = 101; num < 201; num++)
	{
		bool issu = true;
		int halfnum = num / 2;
		for (int a = 2; a <= halfnum; a ++) {
			if (num % a == 0) {
				issu = false;
			}
		}
		if (issu) {
			cout << num << "��";
		}
	}
	cout << endl;
}

/*
* 2024.12.17
��ӡ�����еġ�ˮ�ɻ���������ν��ˮ�ɻ�������ָһ����λ�������λ���������͵��ڸ�������
*/

void test3() {
	cout << "ˮ�ɻ����У�";
	for (int i = 100; i < 1000; i++) {
		string str_i = to_string(i);
		int data1 = stoi(str_i.substr(0,1));
		int data2 = stoi(str_i.substr(1, 1));
		int data3 = stoi(str_i.substr(2, 1));
		int rusult = data1 * data1 * data1 + data2 * data2 * data2 + data3 * data3 * data3;
		if (rusult == i) {
			cout << i << "��";
		}
	}
	cout << endl;
}

/*
* AI������ ���Ǻ��Ͻ�
����������
����һ����������nums��һ������val������Ҫ��дһ���������Ƴ����������е���val��Ԫ�أ��������Ƴ���������³��ȡ���ҪΪ�Ƴ��������������Ŀռ䣬�����ʹ�ó����ڴ��޸��������顣Ԫ�ص�˳����Ըı䡣�����³��ȵĲ�������Ժ��ԡ�
Ҫ��
��Ҫʹ�ö��������ռ䣬������ԭ���޸��������顣
�޸ĺ�����鳤��Ӧ��Ϊ�����ķ���ֵ��
*/

void test4() {
	int num[15] = { 1,2,5,3,4,8,9,4,6,8,6,2,5,1,5 };
	int the_data = 5;
	int movedata = 0;
	int numlen = sizeof(num) / sizeof(num[0]);
	for (int i = 0; i < numlen; i++) {
		if (num[i] == the_data) {
			movedata++;
			if (i+1 == numlen) {
				num[i] = NULL;
			}
			
		}
		else {
			num[i - movedata] = num[i];
		}
	}

	int finlen = numlen - movedata;
	cout << "�Ƴ������鳤��Ϊ��" << finlen<<endl;
	cout << "�Ƴ�������Ϊ��" ;
	for (int i = 0; i < finlen; i++) {
		cout << num[i]<<"��";
	}
	cout << endl;
}


/*
2024.12.18
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸣������㲻��ʹ��������ͬ��Ԫ�ء�
����԰�����˳�򷵻ش𰸡�
*/
void test5() {
	int num[7] = { 1,5,10,16,25,29,33 };
	int target = 39;

	unordered_map<int, int> map;

	int num_len = sizeof(num) / sizeof(num[0]);
	for (int i = 0; i < num_len; i++) {
		int finddata = target - num[i];
		if (map.find(finddata) != map.end()) {
			cout << i << "--" << map[finddata] << endl;
			cout << num[i] << "--" << finddata << endl;
		}
		map[num[i]] = i;
	}
}


/*
2024.12.19
# һ������Υ����ͨ����ײ�˺����ܡ��ֳ�������Ŀ�����¼�������û�м�ס���ţ�ֻ�����˳��ŵ�һЩ������
# ��˵�����յ�ǰ��λ��������ͬ�ģ�
# ��˵�����յĺ���λ��������ͬ�ģ�����ǰ��λ��ͬ��
# ������ѧ�ң���˵��4λ�ĳ��Ÿպ���һ��������ƽ����
# ������һ����ѧ�ң������й������������һ������ƽ����ȴ�ǲ�סһ�����ơ�
*/
void test6() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (i != j) {
				//�˴��ɸ�Ϊ i* 1100 + j * 11
				int checknum = i * 1000 + i * 100 + j * 10 + j * 1;
				//�˴��ɸ�Ϊ isPerfectSquare�������˺����������һ�������Ƿ�����ȫƽ����
				double d = sqrt(checknum);
				int a = d;
				if (a == d) {
					if (i == 0) {
						cout << "���ƺ�Ϊ��00" << checknum << endl;
					}
					else {
						cout << "���ƺ�Ϊ��" << checknum << endl;
					}
				}
			}
		}
	}
}

/*
* 2024.12.20
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ��ĳ��ȡ�
*/

void test7() {
	
	/*
	int maxlen = 0;
	string max_str = "";
	string temp_str = "";
	set<char> se;
	for (size_t i = 0; i < s.size(); i++)
	{
		bool b = se.insert(s[i]).second;
		if (b) {
			temp_str += s[i];
		}
		else
		{
			if (temp_str.size() > max_str.size()) {
				max_str = temp_str;
			}
			i = i - se.size() + 1;
			temp_str = s[i];
			se.clear();
			se.insert(s[i]);
		} 
	}
	if (temp_str.size() > max_str.size()) {
		max_str = temp_str;
	}
	cout << max_str.size() << "----" << max_str << endl;*/

	string s = "dvda";
	unordered_set<char> s_str;
	int first = 0;
	int last = 0;
	int templen = 0;
	int maxlen = 0;
	int s_size = s.size();
	while (true)
	{
		bool isinsert = s_str.insert(s[last]).second;
		if (isinsert) {
			last++;
			templen++;
		}
		else {
			s_str.erase(s[first]);
			first++;
			templen--;
		}
		if (templen > maxlen) {
			maxlen = templen;
		}
		if (last == s_size) {
			break;
		}
	}
	cout << maxlen << endl;
}



/*
* 2024.12.21
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
��������0֮�⣬���Ƕ�������0��ͷ
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};

void addinlistnode(ListNode *&head,int val) {
	ListNode* newNode = new ListNode(val, head);
	head = newNode;
}

void test8(){
	//893 + 483 = 1376
	ListNode* head1 = nullptr;
	addinlistnode(head1, 8);
	addinlistnode(head1, 9);
	addinlistnode(head1, 3);

	ListNode* head2 = nullptr;
	addinlistnode(head2, 4);
	addinlistnode(head2, 8);
	addinlistnode(head2, 3);

	ListNode* head = nullptr;
	bool hasnext = true;
	bool add1 = false;

	while (hasnext) {
		int node_sum = 0;
		if (head1 == nullptr&&head2 == nullptr) {
			if (add1) {
				node_sum = 1;
				addinlistnode(head, node_sum);
			}
			add1 = false;
			hasnext = false;
			continue;
		}
		if (head1 != nullptr) {
			node_sum += head1->val;
			head1 = head1->next;
		}
		if (head2 != nullptr) {
			node_sum += head2->val;
			head2 = head2->next;
		}
		if (add1) {
			node_sum = node_sum + 1;
			add1 = false;
		}
		if (node_sum > 9) {
			node_sum = node_sum - 10;
			add1 = true;
		}
		addinlistnode(head, node_sum);
		
	}
	//������
	cout << "�����";
	while (true) {
		if (head != nullptr) {
			cout << head->val;
			head = head->next;
		}
		else {
			break;
		}
	}
	cout << endl;
}

/*
* 2024.12.24
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��
*/
double test9() {
	//ԭ����Ĳ�������vector
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(5);
	vector<int> nums2;
	nums2.push_back(3);
	nums2.push_back(4);

	
	if (nums1.size() > nums2.size()) {
		nums1.swap(nums2);
	}

	int m = nums1.size();
	int n = nums2.size();
	int totallength = m + n;
	int left = 0;
	int right = m;

	while (left <= right) {
		int partition1 = (left + right) / 2;
		int partition2 = (totallength + 1) / 2 - partition1;

		int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
		int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

		int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
		int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

		if (maxLeft1 < minRight2 && maxLeft2 < minRight1) {
			if (totallength % 2 == 0) {
				return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
			}
			else {
				return max(maxLeft1, maxLeft2);
			}
		}
		else if (maxLeft1 >minRight2) {
			right = partition1 - 1;
		}
		else {
			left = partition1 + 1;
		}

	}
}


/*
2024.12.28

*/




















































