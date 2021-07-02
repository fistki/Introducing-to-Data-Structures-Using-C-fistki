#include <functional>

template<typename Data>
class BTreeNode {
public:
	//typedef void (*VisitFuncPtr)(Data data);
	using VisitFuncPtr = std::function<void(const Data&)>;

	BTreeNode();
	BTreeNode(const Data& _data, BTreeNode* _left = nullptr, BTreeNode* _right = nullptr);
	~BTreeNode();

	static void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
	static void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
	static void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

	// ��尡 ������ �ִ� �����͸� �����մϴ�.
	Data GetData(void) const { return data; };

	// ��忡 �����͸� �����մϴ�.
	void SetData(const Data& _data) { data = _data; }

	// ���� ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete �˴ϴ�.
	void MakeLeftSubTree(BTreeNode* sub);

	// ������ ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete �˴ϴ�.
	void MakeRightSubTree(BTreeNode* sub);

	BTreeNode* GetLeftSubTree(void) { return left; }
	BTreeNode* GetRightSubTree(void) { return right; }

	// ���� ���� Ʈ���� �����մϴ�. ���ŵ� ���� Ʈ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	BTreeNode* RemoveLeftSubTree(void);

	// ������ ���� Ʈ���� �����մϴ�. ���ŵ� ���� Ʈ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	BTreeNode* RemoveRightSubTree(void);

	// ���� ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	void ChangeLeftSubTree(BTreeNode<Data>* sub) { left = sub; }

	// ������ ���� Ʈ���� ��ü�մϴ�. ������ ���� Ʈ���� �޸𸮿��� delete ���� �ʽ��ϴ�.
	void ChangeRightSubTree(BTreeNode<Data>* sub) { right = sub; }

private:

	Data data;
	BTreeNode* left;
	BTreeNode* right;

	// BinaryTree�� ���� ����
	BTreeNode(const BTreeNode& rhs);

	// BinaryTree�� ���� ����
	BTreeNode& operator=(const BTreeNode& rhs);
};
template<typename Data>
BTreeNode<Data>* MakeBTreeNode();
template<typename Data>
BTreeNode<Data>* MakeBTreeNode(Data data, BTreeNode<Data>* left = nullptr, BTreeNode<Data>* right = nullptr);

// bt�� ���� ��忡�� Dangling Pointer �߻� ����
// �Լ� ȣ�� �� ������ ��带 ���� ��忡�� nullptr�� �����ؾ� ��
template<typename Data>
void deleteTree(BTreeNode<Data>* bt);

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
void BTreeNode<Data>::InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr) return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

template<typename Data>
void BTreeNode<Data>::PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr) return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

template<typename Data>
void BTreeNode<Data>::PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr) return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
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