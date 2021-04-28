template<typename Data>
class BTreeNode {
public:
	typedef void (*VisitFuncPtr)(Data data);
	BTreeNode() : left(nullptr), right(nullptr) {}
	BTreeNode(const Data& _data, BTreeNode* _left = nullptr, BTreeNode* _right = nullptr) : data(_data), left(_left), right(_right) {}
	~BTreeNode()
	{

	}
	static void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
	{
		if (bt == nullptr) return;

		InorderTraverse(bt->left, action);
		action(bt->data);
		InorderTraverse(bt->right, action);
	}
	static void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
	{
		if (bt == nullptr) return;

		action(bt->data);
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
	}
	static void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
	{
		if (bt == nullptr) return;

		PostorderTraverse(bt->left, action);
		PostorderTraverse(bt->right, action);
		action(bt->data);
	}
	static void deleteTree(BTreeNode* bt)	// bt의 상위 노드에서 Dangling Pointer 발생 주의
	{										// 함수 호출 후 삭제한 노드를 상위 노드에서 nullptr로 설정해야 함
		if (bt == nullptr) return;
		deleteTree(bt->left);
		deleteTree(bt->right);

		delete bt;
	}

	Data& getData(void) const { return data; };
	void setData(const Data& _data) { data = _data; }

	void MakeLeftSubTree(BTreeNode* sub)
	{
		if (left != nullptr) deleteTree(sub);
		left = sub;
	}
	void MakeRightSubTree(BTreeNode* sub)
	{
		if (right != nullptr) deleteTree(sub);
		right = sub;
	}

	BTreeNode* getLeftSubTree(void) { return left; }
	BTreeNode* getRightSubTree(void) { return right; }

private:

	BTreeNode(const BTreeNode& rhs);
	BTreeNode& operator=(const BTreeNode& rhs);

	Data data;
	BTreeNode* left;
	BTreeNode* right;

};
template<typename Data>
BTreeNode<Data>* makeBTreeNode(Data data)
{
	return new BTreeNode(data);
}