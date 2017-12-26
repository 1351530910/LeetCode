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

int lengthOfLongestSubstring(string s) {
	const char *arr = s.c_str();

	int length = 0;
	int i = 0;
	int j = 0;
	while (arr[i])
	{
		bool letter[256] = {};
		j = i;
		while (arr[j])
		{
			if (letter[arr[j]])
			{
				break;
			}
			else
			{
				letter[arr[j]] = true;
				j++;
				length = fmax(j - i, length);
			}
		}
		i++;
	}
	return length;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int length = nums1.size() + nums2.size();
	int mid = length / 2;
	int med = 0;
	int i = 0;
	int j = 0;

	int *arr = new int[length];

	for (int k = 0; k < mid + 1; k++)
	{
		if (i == nums1.size())
		{
			arr[k] = nums2[j++];
		}
		else if (j == nums2.size())
		{
			arr[k] = nums1[i++];
		}
		else if (nums1[i]>nums2[j])
		{
			arr[k] = nums2[j++];
		}
		else
		{
			arr[k] = nums1[i++];
		}
	}
	if (length % 2 == 0)
	{
		return (arr[mid] + arr[mid - 1]) / 2.0;
	}
	else
	{
		return arr[mid];
	}

	return 0;
}

string longestPalindrome(string s) {
	if (s.length()<1)
	{
		return "";
	}
	if (s.length()==1)
	{
		return s;
	}
	

	int length = s.length() * 2;
	vector<char> arr(length,0);
	int center = 0;
	int currentcount = 1;
	int longestcenter = 0;
	int longestcount = 0;
	string temp = "";
	

	for (int i = 0; i < s.length(); i++)
	{
		arr[i * 2] = 0;
		arr[i * 2 + 1] = s[i];
	}
	arr[length] = 0;

	for (int i = 0; i < length; i++)
	{
		center = i;
		while (center - currentcount>=0&&arr[center - currentcount] == arr[center + currentcount]) {
			currentcount++;
		}
		if (currentcount>longestcount)
		{
			longestcenter = center;
			longestcount = currentcount;
		}
		currentcount = 1;
	}
	longestcount--;
	for (int i = longestcenter-longestcount; i <= longestcenter+longestcount; i++)
	{
		if (arr[i]!=0)
		{
			temp += (char)arr[i];
		}
	}
	free(&arr);
	return temp;
}