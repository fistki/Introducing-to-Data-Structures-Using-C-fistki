#include <functional>

template<typename Data>
using VisitFuncPtr = std::function<void(const Data&)>;

template<typename Data>
class BTreeNode {
public:
	//typedef void (*VisitFuncPtr)(Data data);
	
	BTreeNode();
	BTreeNode(const Data& _data, BTreeNode* _left = nullptr, BTreeNode* _right = nullptr);
	~BTreeNode();

	BTreeNode(const BTreeNode& rhs);
	BTreeNode& operator=(const BTreeNode& rhs);

	// ��尡 ������ �ִ� �����͸� �����մϴ�.
	Data GetData(void) const;

	// ��忡 �����͸� �����մϴ�.
	void SetData(const Data& _data);

	// ���� ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete �˴ϴ�.
	void MakeLeftSubTree(BTreeNode* sub);

	// ������ ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete �˴ϴ�.
	void MakeRightSubTree(BTreeNode* sub);

	// ���� ���� Ʈ���� ��Ʈ ����� �ּҸ� ����ϴ�.
	BTreeNode* GetLeftSubTree(void);

	// ������ ���� Ʈ���� ��Ʈ ����� �ּҸ� ����ϴ�.
	BTreeNode* GetRightSubTree(void);

	// ���� ���� Ʈ���� �����մϴ�. ���� Ʈ���� ��Ʈ ��带 ������ ������ ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	BTreeNode* RemoveLeftSubTree(void);

	// ������ ���� Ʈ���� �����մϴ�. ���� Ʈ���� ��Ʈ ��带 ������ ������ ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	BTreeNode* RemoveRightSubTree(void);

	// ���� ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	void ChangeLeftSubTree(BTreeNode<Data>* sub) { left = sub; }

	// ������ ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	void ChangeRightSubTree(BTreeNode<Data>* sub) { right = sub; }

private:
	Data data;
	BTreeNode* left;
	BTreeNode* right;
};

// bt�� ���� ��忡�� Dangling Pointer �߻� ����
// �Լ� ȣ�� �� ������ ��带 ���� ��忡�� nullptr�� �����ؾ� ��
template<typename Data>
void deleteTree(BTreeNode<Data>* bt);

template<typename Data>
BTreeNode<Data>* MakeBTreeNode();
template<typename Data>
BTreeNode<Data>* MakeBTreeNode(Data data, BTreeNode<Data>* left = nullptr, BTreeNode<Data>* right = nullptr);

template<typename Data>
void InorderTraverse(BTreeNode<Data>* bt, VisitFuncPtr<Data> action);
template<typename Data>
void PreorderTraverse(BTreeNode<Data>* bt, VisitFuncPtr<Data> action);
template<typename Data>
void PostorderTraverse(BTreeNode<Data>* bt, VisitFuncPtr<Data> action);

template<typename Data>
BTreeNode<Data>::BTreeNode()
	: data(), left(nullptr), right(nullptr) 
{
}

template<typename Data>
BTreeNode<Data>::BTreeNode(const Data& _data, BTreeNode* _left, BTreeNode* _right)
	: data(_data), left(_left), right(_right) 
{
}

template<typename Data>
BTreeNode<Data>::~BTreeNode()
{
}

template<typename Data>
BTreeNode<Data>::BTreeNode(const BTreeNode& rhs)
	: data(rhs.data), left(rhs.left), right(rhs.right)
{
}

template<typename Data>
BTreeNode<Data>& BTreeNode<Data>::operator=(const BTreeNode& rhs)
{
	data = rhs.data;
	left = rhs.left;
	right = rhs.right;
	return *this;
}

template<typename Data>
inline Data BTreeNode<Data>::GetData(void) const
{
	return data;
}

template<typename Data>
inline void BTreeNode<Data>::SetData(const Data& _data)
{
	data = _data;
}

template<typename Data>
void BTreeNode<Data>::MakeLeftSubTree(BTreeNode* sub)
{
	if (left != nullptr) deleteTree<Data>(sub);
	left = sub;
}

template<typename Data>
void BTreeNode<Data>::MakeRightSubTree(BTreeNode* sub)
{
	if (right != nullptr) deleteTree<Data>(sub);
	right = sub;
}

template<typename Data>
inline BTreeNode<Data>* BTreeNode<Data>::GetLeftSubTree(void)
{
	return left;
}

template<typename Data>
inline BTreeNode<Data>* BTreeNode<Data>::GetRightSubTree(void)
{
	return right;
}

template<typename Data>
BTreeNode<Data>* BTreeNode<Data>::RemoveLeftSubTree(void)
{
	if (this == nullptr) return nullptr;
	BTreeNode<Data>* delNode = left;
	left = nullptr;
	return delNode;
}

template<typename Data>
BTreeNode<Data>* BTreeNode<Data>::RemoveRightSubTree(void)
{
	if (this == nullptr) return nullptr;
	BTreeNode<Data>* delNode = right;
	right = nullptr;
	return delNode;
}

template<typename Data>
BTreeNode<Data>* MakeBTreeNode()
{
	return new BTreeNode<Data>;
}

template<typename Data>
BTreeNode<Data>* MakeBTreeNode(Data data, BTreeNode<Data>* left, BTreeNode<Data>* right)
{
	return new BTreeNode<Data>(data, left, right);
}

template<typename Data>
void deleteTree(BTreeNode<Data>* bt)
{
	if (bt == nullptr) return;
	deleteTree(bt->GetLeftSubTree());
	deleteTree(bt->GetRightSubTree());

	delete bt;
}

template<typename Data>
void InorderTraverse(BTreeNode<Data>* bt, VisitFuncPtr<Data> action)
{
	if (bt == nullptr) return;
	InorderTraverse(bt->GetLeftSubTree(), action);
	action(bt->GetData());
	InorderTraverse(bt->GetRightSubTree(), action);
}

template<typename Data>
void PreorderTraverse(BTreeNode<Data>* bt, VisitFuncPtr<Data> action)
{
	if (bt == nullptr) return;
	action(bt->GetData()); 
	PreorderTraverse(bt->GetLeftSubTree(), action);
	PreorderTraverse(bt->GetRightSubTree(), action);
}

template<typename Data>
void PostorderTraverse(BTreeNode<Data>* bt, VisitFuncPtr<Data> action)
{
	if (bt == nullptr) return;
	PostorderTraverse(bt->GetLeftSubTree(), action);
	PostorderTraverse(bt->GetRightSubTree(), action);
	action(bt->GetData());
}