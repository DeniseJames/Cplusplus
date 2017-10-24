/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/
class NestedIterator {
private:
	int index;
	vector<int> vec;
public:

	void NestedIterator(vector<NestedInteger> &nestedList)
	{
		for (auto val : nestedList)
		{
			if (val.isInteger())
				vec.push_back(val.getInteger());
			else {
				vector<NestedInteger> temp = val.getList();
				NestedIterator(temp);
			}
		}
	}
	NestedIterator(vector<NestedInteger> &nestedList) {
		index = 0;
		NestedIterator(nestedList);
	}

	int next() {
		return vec[index++];
	}

	bool hasNext() {
		return index < vec.size();
	}


};