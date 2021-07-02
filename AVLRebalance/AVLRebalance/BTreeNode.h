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

	// 노드가 가지고 있는 데이터를 리턴합니다.
	Data GetData(void) const { return data; };

	// 노드에 데이터를 세팅합니다.
	void SetData(const Data& _data) { data = _data; }

	// 왼쪽 서브 트리를 대체합니다. 기존의 서브 트리는 메모리에서 delete 됩니다.
	void MakeLeftSubTree(BTreeNode* sub);

	// 오른쪽 서브 트리를 대체합니다. 기존의 서브 트리는 메모리에서 delete 됩니다.
	void MakeRightSubTree(BTreeNode* sub);

	BTreeNode* GetLeftSubTree(void) { return left; }
	BTreeNode* GetRightSubTree(void) { return right; }

	// 왼쪽 서브 트리를 제거합니다. 제거된 서브 트리는 메모리에서 delete 되지 않습니다.
	BTreeNode* RemoveLeftSubTree(void);

	// 오른쪽 서브 트리를 제거합니다. 제거된 서브 트리는 메모리에서 delete 되지 않습니다.
	BTreeNode* RemoveRightSubTree(void);

	// 왼쪽 서브 트리를 대체합니다. 기존의 서브 트리는 메모리에서 delete 되지 않습니다.
	void ChangeLeftSubTree(BTreeNode<Data>* sub) { left = sub; }

	// 오른쪽 서브 트리를 대체합니다. 기존의 서브 트리는 메모리에서 delete 되지 않습니다.
	void ChangeRightSubTree(BTreeNode<Data>* sub) { right = sub; }

private:

	Data data;
	BTreeNode* left;
	BTreeNode* right;

	// BinaryTree는 복사 금지
	BTreeNode(const BTreeNode& rhs);

	// BinaryTree는 복사 금지
	BTreeNode& operator=(const BTreeNode& rhs);
};
template<typename Data>
BTreeNode<Data>* MakeBTreeNode();
template<typename Data>
BTreeNode<Data>* MakeBTreeNode(Data data, BTreeNode<Data>* left = nullptr, BTreeNode<Data>* right = nullptr);

// bt의 상위 노드에서 Dangling Pointer 발생 주의
// 함수 호출 후 삭제한 노드를 상위 노드에서 nullptr로 설정해야 함
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