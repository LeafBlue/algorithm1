#include"algorithms.h"


/*

有一对兔子，从出生后第3个月起每个月都生一对兔子，
小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，
问每个月的兔子总数为多少？
*/
void test1() {
	//此集合的长度便是兔子对数
	std::vector<int> v;

	//第一对兔子，这里出生的兔子尚未加入循环，算还没有开始长
	int rab = 0;
	v.push_back(rab);

	int mouth = 1;
	while (mouth < 20) {
		//设立“本月出生小兔子数”标志，为了防止迭代器失效，不能在迭代器里面直接修改
		int addrabbitdata = 0;
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
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
		std::cout << "当前月份为：第" << mouth << "个月，当前兔子数量为：" << v.size() * 2 << "只" << std::endl;
		mouth++;
	}
}

/*

判断101-200之间有多少个素数，并输出所有素数
*/

void test2() {
	std::cout << "101-200中，素数有：";
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
			std::cout << num << "、";
		}
	}
	std::cout << std::endl;
}

/*

打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数本身
*/

void test3() {
	std::cout << "水仙花数有：";
	for (int i = 100; i < 1000; i++) {
		std::string str_i = std::to_string(i);
		int data1 = stoi(str_i.substr(0,1));
		int data2 = stoi(str_i.substr(1, 1));
		int data3 = stoi(str_i.substr(2, 1));
		int rusult = data1 * data1 * data1 + data2 * data2 * data2 + data3 * data3 * data3;
		if (rusult == i) {
			std::cout << i << "、";
		}
	}
	std::cout << std::endl;
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
	std::cout << "移除后数组长度为：" << finlen<< std::endl;
	std::cout << "移除后数组为：" ;
	for (int i = 0; i < finlen; i++) {
		std::cout << num[i]<<"，";
	}
	std::cout << std::endl;
}


/*

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。
*/
void test5() {
	int num[7] = { 1,5,10,16,25,29,33 };
	int target = 39;

	std::vector<int> result;

	std::unordered_map<int, int> map;

	int num_len = sizeof(num) / sizeof(num[0]);
	for (size_t i = 0; i < num_len; i++)
	{
		int finddata = target - num[i];
		if (map.count(finddata) > 0) {
			result.push_back(i);
			result.push_back(map[finddata]);
		}
		else {
			map[num[i]] = i;
		}
	}
}


/*

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
						std::cout << "车牌号为：00" << checknum << std::endl;
					}
					else {
						std::cout << "车牌号为：" << checknum << std::endl;
					}
				}
			}
		}
	}
}

/*

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

	std::string s = "dvda";
	std::unordered_set<char> s_str;
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
	std::cout << maxlen << std::endl;
}



/*

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
	std::cout << "结果：";
	while (true) {
		if (head != nullptr) {
			std::cout << head->val;
			head = head->next;
		}
		else {
			break;
		}
	}
	std::cout << std::endl;
}




/*

练习 1: 简单的二分查找
给定一个已排序且无重复元素的整数数组 nums 和一个目标值 target，请编写一个函数来搜索 target 在 nums 中的索引。如果 target 不存在，则返回 -1。
示例：
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 存在于 nums 中，在索引 4 处。
提示：
数组中的元素数量 n 将满足 1 <= n <= 10^4。
-9999 <= nums[i] <= 9999
所有数值唯一且按升序排列。
-9999 <= target <= 9999
*/
int test9() {
	int nums[6] = { - 1, 0, 3, 5, 9, 12 };
	int target = 9;
	int len = sizeof(nums) / sizeof(nums[0]);
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int half_num = left + (right - left) / 2;
		if (nums[half_num] == target) {
			return half_num;
		}
		else if (nums[half_num] > target) {
			right = half_num - 1;
		}
		else if (nums[half_num] < target) {
			left = half_num + 1;
		}
	}
}

/*
练习 2: 查找左边界
给定一个可能包含重复元素的有序数组 nums 和一个目标值 target，请编写一个函数来查找 target 的起始位置（即第一个出现的位置）。如果 target 不存在，则返回 -1。
示例：
输入: nums = [5,7,7,8,8,10], target = 8
输出: 3
解释: 8 第一次出现在索引 3 处。
*/
int test10() {
	int nums[6] = { 5,7,7,8,8,10 };
	int target = 8;
	int len = sizeof(nums) / sizeof(nums[0]);
	int left = 0;
	int right = len - 1;
	int target_index = -1;
	while (left <= right) {
		int half_num = left + (right - left) / 2;
		if (nums[half_num] == target) {
			target_index = half_num;
			right = half_num - 1;
		}
		else if (nums[half_num] > target) {
			right = half_num - 1;
		}
		else if (nums[half_num] < target) {
			left = half_num + 1;
		}
	}
	return target_index;
}

/*
练习 3: 查找右边界
和练习 2 类似，但这次你要找到目标值 target 最后一次出现的位置。
示例：
输入: nums = [5,7,7,8,8,10], target = 8
输出: 4
解释: 8 最后一次出现在索引 4 处。
*/
int test11() {
	int nums[6] = { 5,7,7,8,8,10 };
	int target = 8;
	int len = sizeof(nums) / sizeof(nums[0]);
	int left = 0;
	int right = len - 1;
	int target_index = -1;
	while (left <= right) {
		int half_num = left + (right - left) / 2;
		if (nums[half_num] == target) {
			target_index = half_num;
			left = half_num + 1;
		}
		else if (nums[half_num] > target) {
			right = half_num - 1;
		}
		else if (nums[half_num] < target) {
			left = half_num + 1;
		}
	}
	return target_index;
}

/*
练习 4: 搜索插入位置
给定一个排序数组和一个目标值，如果目标值存在于此数组中，则返回其索引。如果不存在，则返回它将会被按顺序插入的位置。
示例：
输入: nums = [1,3,5,6], target = 5
输出: 2
解释: 5 应该插入到索引 2 处。
*/
//这个还有点问题
int test12() {
	int nums[8] = { 1,3,5,6,8,10,16,18 };
	int target = 8;
	int len = sizeof(nums) / sizeof(nums[0]);

	int left_index, left = 0;
	int right_index,right = len;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}
	return left;
}

/*
练习 5: 寻找旋转排序数组中的最小值
问题描述：
假设一个升序排列的数组在某个未知的索引处进行了旋转（例如 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2]）。请编写一个函数来找到这个旋转排序数组中的最小值。
提示：
数组中没有重复元素。
你可以假设数组中至少有一个元素。
示例：
输入: nums = [3,4,5,1,2]
输出: 1
解释: 原始数组是 [1,2,3,4,5]，在索引 3 处进行了旋转。
*/
//本题目的关键是比较中值和右值
int test13() {
	int nums[7] = { 4,5,6,7,0,1,2 };
	//int nums[8] = { 7,0,1,2,3,4,5,6 };
	int len = sizeof(nums) / sizeof(nums[0]);

	int left = 0;
	int right = len - 1;
	//nums[left] > nums[right]，如果不满足，说明旋转点有问题or只有一位数
	if (nums[left] <= nums[right]) {
		return nums[0];
	}
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < nums[right]) {
			right = mid;
		}
		else if (nums[mid] > nums[right]) {
			left = mid + 1;
		}
	}
	return nums[left];
	/*
	while (left <= right) {
		int mid = (left + right) % 2 > 0 ? (left + right + 1)/2 : (left + right) / 2;
		if (nums[left] == nums[mid] || nums[right] == nums[mid]) {
			return nums[mid];
		}
		else if (nums[left] < nums[mid] ) {
			if (nums[right] < nums[mid]) {
				left = mid + 1;
			}
			else if (nums[right] > nums[mid]) {
				right = mid - 1;
			}
		}
		else if (nums[left] > nums[mid]) {
			right = mid;
		}
	}*/
}
//↑这不是最好的解法，明天注释掉重写一个

/*


练习 6: 搜索二维矩阵
问题描述：
编写一个高效的算法，判断 m x n 矩阵中是否包含目标值。这个矩阵具有以下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例：

输入: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出: true

*/
bool test14() {
	int matrix[3][4] = { {1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 60} };
	int target = 8;

	//题目交代了是矩阵，可以认为里层每个数组长度一致
	int len = sizeof(matrix) / sizeof(matrix[0]);
	int len_1 = sizeof(matrix[0]) / sizeof(matrix[0][0]);

	if (target < matrix[0][0] || target > matrix[len - 1][len_1 - 1]) {
		return false;
	}
	int left = 0;
	int right = len - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (matrix[mid][0] > target) {
			right = mid - 1;
		}
		else if (matrix[mid][0] == target || matrix[mid][len_1 - 1] == target) {
			return true;
		}
		else if (matrix[mid][0] < target && matrix[mid][len_1 - 1] > target) {
			left = right = mid;
			break;
		}
		else if (matrix[mid][len_1 - 1] < target) {
			left = mid + 1;
		}
	}
	int left1 = 0;
	int right1 = len_1 - 1;
	while (left1< right1) {
		int mid1 = (left1 + right1) / 2;
		if (matrix[left][mid1] == target) {
			return true;
		}
		else if (matrix[left][mid1]>target) {
			right1 = mid1 - 1;
		}
		else if (matrix[left][mid1] < target) {
			left1 = mid1 + 1;
		}
	}
	return false;
}


/*
练习 7: 查找平方根
问题描述：
实现 int sqrt(int x) 函数。计算并返回 x 的平方根，其中 x 是非负整数。由于返回类型是整数，结果只保留整数部分，小数部分将被舍去。

示例：

输入: 4
输出: 2
输入: 8
输出: 2
解释: 平方根为 2.82842..., 因为返回类型是整数，小数部分将被舍去。

*/
int test15(int x) {
	//检查特殊情况
	if (x == 0) {
		return 0;
	}
	if (x == 1) {
		return 1;
	}
	//这道题不用建立数组
	int left = 1;
	int right = x  / 2 + 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		long result = static_cast<long>( mid* mid);
		if (result > x) {
			right = mid - 1;
		}
		else if (result < x) {
			left = mid + 1;
		}
		else if (result == x) {
			return mid;
		}
	}
	return right;
}


/*
练习 8: 查找峰值元素
问题描述：
峰值元素是指其值严格大于左右相邻值的元素。给你一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到任意一个峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回任何一个即可。
提示：
你可以假设 nums[-1] = nums[n] = -∞。
示例：
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是一个峰值元素，你的函数应该返回其索引 2。
*/
int test16() {
	int n[7] = { 1, 2, 1, 3, 5, 6, 4 };
	int len = sizeof(n) / sizeof(n[0]);
	int l = 0;
	int r = len - 1;
	int bigindex = 0;
	while (l < r) {
		int m = l + (r - l)/2;
		if (m < len - 1) {
			if(n[m] > n[m + 1]) {
				r = m;
				bigindex = m;
			}
			else{
				l = m + 1;
				bigindex = m + 1;
			}
		}
	}
	return bigindex;
}


/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false
*/

bool test17() {
	int i = 1180811;
	std::string str_i = std::to_string(i);
	int len = str_i.size();
	int l = 0;
	int r = len - 1;
	while (l < r) {
		if (str_i[l] == str_i[r]) {
			l++;
			r--;
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。
示例 1:
输入: s = "III"
输出: 3
示例 2:
输入: s = "IV"
输出: 4
示例 3:
输入: s = "IX"
输出: 9
示例 4:
输入: s = "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:
输入: s = "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/
void test18() {
	/*认为罗马数字通常是从大到小的，如果中途出现从小到大，例如CM，说明它是一个整体表示*/
	std::string str = "III";

	std::unordered_map<char, int> map;
	
	map.insert(std::make_pair('M', 1000));
	map.insert(std::make_pair('D', 500));
	map.insert(std::make_pair('C', 100));
	map.insert(std::make_pair('L', 50));
	map.insert(std::make_pair('X', 10));
	map.insert(std::make_pair('V', 5));
	map.insert(std::make_pair('I', 1));
	int big = map['M'];
	int i = 0;
	int data = 0;
	while (i < str.size()) {
		if (map[str[i]] == big) {
			data += map[str[i]];
			++i;
		}
		else if (map[str[i]] < big) {
			if (i < (str.size() - 1) && map[str[i]] < map[str[i + 1]]) {
				data += (map[str[i + 1]] - map[str[i]]);
				big = map[str[i + 1]];
				i = i + 2;
				continue;
			}
			data += map[str[i]];
			++i;
		}
	}
	std::cout << data << std::endl;
}

/*
给你一个字符串 s，找到 s 中最长的回文子串
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：
输入：s = "cbbd"
输出："bb"
*/
//中心扩展法，尝试从回文的中心向两边检查，如果是两个中心则一定是相等的，否则无需考虑
std::string test19(std::string s) {
	auto start = std::chrono::high_resolution_clock::now();

	size_t len = s.size();
	size_t checklen = s.size() - 1;
	std::string result = "";
	std::string check = "";

	int i = 1;
	for (size_t i = 0; i < len; i++)
	{
		check = help1(s,len,i);
		if (check.size() > result.size()) {
			result = check;
		}
		if (s[i] == s[i + 1]) {
			check = help2(s, len, i);
			if (check.size() > result.size()) {
				result = check;
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> _time = end - start;
	std::cout << "用时：" << _time.count() << " s" << std::endl;
	return result;
}

std::string help1(std::string& s,size_t len,size_t index) {
	std::string result;
	result += s[index];

	int left = index - 1;
	int right = index + 1;
	while (left >= 0 && right < len && s[left] == s[right]) {
		result = std::string(1, s[left]).append(result).append(std::string(1, s[right]));
		--left;
		++right;
	}
	return result;
}
std::string help2(std::string& s, size_t len, size_t index) {
	std::string result = std::string(1, s[index]).append(std::string(1, s[index + 1]));
	int left = index - 1;
	int right = index + 2;
	while (left >= 0 && right < len && s[left] == s[right]) {
		result = std::string(1, s[left]).append(result).append(std::string(1, s[right]));
		--left;
		++right;
	}
	return result;
}

/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：

*/
std::string test20(std::string s, int numRows) {
	int size = s.size();
	if (numRows == 1 || numRows >=s.size() ) {
		return s;
	}
	std::vector<char> v;
	int check = numRows - 1;
	for (size_t i = 0; i < numRows; i++)
	{
		if (i == 0 || i == check) {
			int index = i;
			while (index < size) {
				v.push_back(s[index]);
				index = index + (numRows * 2) - 2;
			}
		}
		else {
			int temp_1 = (check - i) * 2;
			int temp_2 = i * 2;
			int index = i;

			bool in = false;
			while (index < size) {
				v.push_back(s[index]);
				if (in) {
					index = index + temp_2;
					in = false;
				}
				else {
					index = index + temp_1;
					in = true;
				}
			}
		}
	}
	std::string result(v.begin(), v.end());
	return result;
}


/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。

示例 1：
输入：x = 123
输出：321
示例 2：
输入：x = -123
输出：-321
示例 3：
输入：x = 120
输出：21
示例 4：
输入：x = 0
输出：0
*/

int test21(int x) {
	std::string data = std::to_string(x);
	int checklen = data.size();
	int result = 0;
	int nowdata = 1;
	int startdata = 0;
	if(data[0] == '-'){
		startdata = 1;
	}
	while (startdata < checklen)
	{
		int c_int = data[startdata] - '0';

		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && c_int > 7)) {
			return 0;
		}
		if (result < INT_MIN / 10 || (result == INT_MIN / 10 && c_int < -8)) {
			return 0;
		}

		result = result + nowdata* c_int;
		++startdata;
		nowdata = nowdata * 10;
	}
	if (data[0] == '-') {
		result = result * -1;
	}
	return result;
}

/*
盛水
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
输入：[1,8,6,2,5,4,8,3,7]
输出：49
*/	
int test22(std::vector<int>& height) {
	int l = 0;
	int r = height.size() - 1;
	int water = 0;
	while (l < r) {
		int l1 = height[l];
		int r1 = height[r];
		int thiswater = 0;
		if (l1 > r1) {
			thiswater = r1* (r - l);
			--r;
		}
		else {
			thiswater = l1 * (r - l);
			++l;
		}
		if (thiswater > water) {
			water = thiswater;
		}
	}
	return water;
}
/*
七个不同的符号代表罗马数字，其值如下：
符号	值
I	1
V	5
X	10
L	50
C	100
D	500
M	1000

罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：
如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
给定一个整数，将其转换为罗马数字。
示例 1：
输入：num = 3749
输出： "MMMDCCXLIX"
解释：
3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
  40 = XL 由于 50 (L) 减 10 (X)
   9 = IX 由于 10 (X) 减 1 (I)
注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位
示例 2：
输入：num = 58
输出："LVIII"
解释：
50 = L
 8 = VIII
示例 3：
输入：num = 1994
输出："MCMXCIV"
解释：
1000 = M
 900 = CM
  90 = XC
   4 = IV
*/
std::string test23(int num) {
	std::unordered_map<int, char> map;

	map[1000] = 'M';
	map[500] = 'D';
	map[100] = 'C';
	map[50] = 'L';
	map[10] = 'X';
	map[5] = 'V';
	map[1] = 'I';

	int num_ = num;
	std::vector<char> v;
	
	int data1 = 0;
	int data2 = 0;
	while (num_ > 0) {
		std::pair<int,int> p = help3(num_);

		data1 = p.first;
		data2 = p.second;
		num_ = num_ - pow(10, (data2 - 1)) * data1;

		char c1 = map[pow(10, (data2 - 1))];
		char c2 = map[pow(10, (data2 - 1)) * 5];
		char c3 = map[pow(10, (data2))];
		if (data1 < 4) {
			for (size_t i = 0; i < data1; i++)
			{
				v.push_back(c1);
			}
		}
		else if (data1 == 4 || data1 == 9) {
			v.push_back(c1);
			v.push_back(data1==4?c2:c3);
		}
		else {
			v.push_back(c2);
			for (size_t i = 0; i < (data1 - 5); i++)
			{
				v.push_back(c1);
			}
		}
	}
	return std::string(v.begin(),v.end());
}

//这个函数会返回数字的 最高位 和 位数
std::pair<int, int> help3(int num) {
	int data = 1;
	int num_ = 0;
	num = abs(num);
	while (num > 9) {
		num = num / 10;
		num_ = num % 10;
		++data;
	}
	return std::make_pair(num,data);
}


/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2： 
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/
std::string test24(std::vector<std::string>& strs) {
	std::string result = strs[0];
	size_t s = strs.size();
	size_t check = result.size();
	if (s > 1) {
		for (size_t i = 1; i < s; i++)
		{
			size_t s1 = strs[i].size();
			if (s1 < check) {
				check = s1;
				result.resize(check);
			}
			for (size_t j = 0; j < check; j++)
			{
				if (result[j] != strs[i][j]) {
					if (j == 0) {
						return "";
					}
					check = j;
					result.resize(j);
				}
				
			}
		}
	}
	return result;
}

/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/
std::vector<std::vector<int>> test25(std::vector<int>& nums) {
	
}























