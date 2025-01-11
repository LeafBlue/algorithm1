#include"algorithms.h"


/*
2024.12.15练习
有一对兔子，从出生后第3个月起每个月都生一对兔子，
小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，
问每个月的兔子总数为多少？
*/
void test1() {
	//此集合的长度便是兔子对数
	vector<int> v;

	//第一对兔子，这里出生的兔子尚未加入循环，算还没有开始长
	int rab = 0;
	v.push_back(rab);

	int mouth = 1;
	while (mouth < 20) {
		//设立“本月出生小兔子数”标志，为了防止迭代器失效，不能在迭代器里面直接修改
		int addrabbitdata = 0;
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			//月份开始循环，对每个兔子的月份进行+1
			//需要先+1再进行是否生崽判断，否则会出现本月兔子明明已经长到第三个月，但数值显示是2，导致不能生兔子
			(*it)++;
			if ((*it) > 2) {
				addrabbitdata++;
			}
		}
		while (addrabbitdata > 0)
		{
			/*这里出生的兔子已经加入循环，但由于没有参与前面的+1
			在此循环结束后一个月就结束了，因此算生长了1个月，因此初值设置为1，
			 我们不能等它下个月了再+1，然后说“这兔子在上个月没长一点”
			*/
			int newrab = 1;
			v.push_back(newrab);
			addrabbitdata--;
		}
		cout << "当前月份为：第" << mouth << "个月，当前兔子数量为：" << v.size() * 2 << "只" << endl;
		mouth++;
	}
}

/*
* 2024.12.16
判断101-200之间有多少个素数，并输出所有素数
*/

void test2() {
	cout << "101-200中，素数有：";
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
			cout << num << "、";
		}
	}
	cout << endl;
}

/*
* 2024.12.17
打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数本身
*/

void test3() {
	cout << "水仙花数有：";
	for (int i = 100; i < 1000; i++) {
		string str_i = to_string(i);
		int data1 = stoi(str_i.substr(0,1));
		int data2 = stoi(str_i.substr(1, 1));
		int data3 = stoi(str_i.substr(2, 1));
		int rusult = data1 * data1 * data1 + data2 * data2 * data2 + data3 * data3 * data3;
		if (rusult == i) {
			cout << i << "、";
		}
	}
	cout << endl;
}

/*
* AI出的题 不是很严谨
问题描述：
给定一个整数数组nums和一个整数val，你需要编写一个函数来移除数组中所有等于val的元素，并返回移除后数组的新长度。不要为移除后的数组分配额外的空间，你必须使用常量内存修改输入数组。元素的顺序可以改变。超出新长度的部分你可以忽略。
要求：
不要使用额外的数组空间，必须在原地修改输入数组。
修改后的数组长度应作为函数的返回值。
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
	cout << "移除后数组长度为：" << finlen<<endl;
	cout << "移除后数组为：" ;
	for (int i = 0; i < finlen; i++) {
		cout << num[i]<<"，";
	}
	cout << endl;
}


/*
2024.12.18
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。
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
# 一辆卡车违反交通规则，撞人后逃跑。现场有三人目击该事件，但都没有记住车号，只记下了车号的一些特征。
# 甲说：牌照的前两位数字是相同的；
# 乙说：牌照的后两位数字是相同的，但与前两位不同；
# 丙是数学家，他说：4位的车号刚好是一个整数的平方。
# 【丙，一个数学家，有那闲工夫算出数字是一个整数平方，却记不住一个车牌】
*/
void test6() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (i != j) {
				//此处可改为 i* 1100 + j * 11
				int checknum = i * 1000 + i * 100 + j * 10 + j * 1;
				//此处可改为 isPerfectSquare函数，此函数用来检查一个数字是否是完全平方数
				double d = sqrt(checknum);
				int a = d;
				if (a == d) {
					if (i == 0) {
						cout << "车牌号为：00" << checknum << endl;
					}
					else {
						cout << "车牌号为：" << checknum << endl;
					}
				}
			}
		}
	}
}

/*
* 2024.12.20
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。
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
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
除了数字0之外，它们都不会以0开头
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
	//输出结果
	cout << "结果：";
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
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
*/
double test9() {
	//原题给的参数就是vector
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




















































