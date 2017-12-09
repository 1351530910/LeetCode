#include "Solutions.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> arr;
	for (int i = 0; i < nums.size(); i++)
	{
		int temp = target - nums[i];
		if (arr.find(temp) != arr.end())
		{
			return { arr.at(temp) ,i };
		}
		else
		{
			arr.emplace(nums[i], i);
		}
	}
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *parser = new ListNode(0);
	ListNode *sum = parser;
	int c = 0;
	int temp;
	while (true)
	{
		temp = c;
		if (l1 != nullptr)
		{
			temp += l1->val;
			l1 = l1->next;
		}
		if (l2 != nullptr)
		{
			temp += l2->val;
			l2 = l2->next;
		}

		c = temp / 10;
		parser->next = new ListNode(temp % 10);
		parser = parser->next;
		if (l1 == nullptr && l2 == nullptr&&c == 0)
		{
			sum = sum->next;
			return sum;
		}
	}
}
