#include <iostream>
#include <stack>
using namespace  std;

class Tree
{
public:
	Tree* Left = nullptr; 
	Tree* Right = nullptr;
	int Data = 0;
	static Tree* MakeTree(int NewData)
	{
		Tree* ReturnVal = new Tree;
		ReturnVal->Data = NewData;
		 return ReturnVal; 
	}
};


Tree* MakeExpTree(std::string Expression)
{
	PUBLIC:
	
	stack<Tree*>StackTree;

	for (const auto& Element : Expression)
	{
		Tree* CurRoot; 
		if (Element == '+' || Element == '-' || Element == '*' || Element == '/')
		{
			CurRoot = Tree::MakeTree(Element);
			CurRoot->Left = StackTree.top();
			StackTree.pop();
			CurRoot->Right = StackTree.top();
			StackTree.pop();
		}
		else
		{
			CurRoot = Tree::MakeTree(Element);
		}
		StackTree.push(CurRoot);
	}
	return StackTree.top(); 
}
int Calculate(Tree* Target)
{
	if (Target->Left ==   nullptr && Target->Right == nullptr) return Target->Data;

	/*if(Target->Right==nullptr)*/
	int Left = Calculate(Target->Left);
	/*if (Target->Left== nullptr)*/
	int Right = Calculate(Target->Right);
	
	int ReturnVal;
	
	switch (Target->Data)
	{
	case '+':
		ReturnVal = Left + Right; 
		break;
	case '-':
		ReturnVal = Left  - Right;
		break;
	case '/':
		ReturnVal = Left / Right;
		break;
	case '*':
		ReturnVal = Left  * Right;
		break;
	}
	Target->Data = ReturnVal;
	return Target->Data;
}
void Print(Tree* Target)
{
	if (!Target) return;
	
		 // cout << " ( ";
	cout << Target->Data;
		Print(Target->Left);
		
		Print(Target->Right);
		// cout << " ) ";
	
}
int main()
{
	auto Root = MakeExpTree(std::string("13/5+7777"));
	Calculate(Root);
	
	Print(Root);
	
} 