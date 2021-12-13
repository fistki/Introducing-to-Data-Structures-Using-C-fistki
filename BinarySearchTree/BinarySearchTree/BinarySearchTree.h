#pragma once
#include "AVLRebalance.h"
#include <memory>

template<typename BSTData>
using Node = BTreeNode<BSTData>;

template<typename BSTData>
using PrintFunction = std::function<void(const BSTData&)>;

struct DeleteBST {
	template<typename T>
	void operator()(T* p) const {
		deleteTree(p);
	}
};

enum class ETraverseMode{
	PREORDER,
	INORDER,
	POSTORDER
};

template<typename BSTData>
class BinarySearchTree {
public:
	BinarySearchTree(Node<BSTData>* pRoot = nullptr);
	BinarySearchTree(const BinarySearchTree& rhs);
	BinarySearchTree& operator=(const BinarySearchTree& rhs);
	~BinarySearchTree();

	// 루트 노드의 주소를 얻습니다.
	Node<BSTData>* GetRoot();

	// 루트 노드를 재설정 합니다.
	void SetRoot(Node<BSTData>* NewRoot);

	// Key를 BST에 삽입합니다.
	// 삽입에 성공하였을 경우, 해당 노드의 주소를 리턴하고, 실패 시 nullptr을 리턴합니다.
	Node<BSTData>* insert(const BSTData& Key);

	// Key를 BST에 삽입합니다.
	// 삽입에 성공하였을 경우, 해당 노드의 주소를 리턴하고, 실패 시 nullptr을 리턴합니다.
	// AVL 트리 구조를 사용하여 노드 간의 균형을 자동으로 맞춥니다.
	Node<BSTData>* insert_AVL(const BSTData& Key);

	// TargetKey와 대응되는 노드를 찾아서 그 주소를 리턴합니다. 
	Node<BSTData>* search(const BSTData& TargetKey);

	// TargetKey와 대응되는 노드를 찾아서 지웁니다. 이때 찾은 노드는 메모리에서 delete 됩니다.
	void erase(const BSTData& TargetKey);

	// TargetKey와 대응되는 노드를 찾아서 지웁니다. 이때 찾은 노드는 메모리에서 delete 됩니다.
	// AVL 트리 구조를 사용하여 노드 간의 균형을 자동으로 맞춥니다.
	void erase_AVL(const BSTData& TargetKey);

private:
	// 루트 노드
	std::shared_ptr<Node<BSTData>> root;
}; 

// BST의 모든 노드를 순회합니다. 이때 각 노드마다 void(const Type&)의 PrintFunc이 실행됩니다.
// Mode 0 : 전위 순회 / Mode 1 : 중위 순회 / Mode 2 : 후위 순회
template<typename BSTData>
void ShowAllBSTNode(BinarySearchTree<BSTData>* bst, PrintFunction<BSTData> PrintFunc, const ETraverseMode& Mode = ETraverseMode::INORDER);

template<typename BSTData>
BinarySearchTree<BSTData>::BinarySearchTree(Node<BSTData>* pRoot)
	: root(MakeBTreeNode<BSTData>(), DeleteBST())
{
	root.get()->ChangeRightSubTree(pRoot);
}

template<typename BSTData>
BinarySearchTree<BSTData>::BinarySearchTree(const BinarySearchTree& rhs)
	: root(rhs.root)
{
}

template<typename BSTData>
BinarySearchTree<BSTData>& BinarySearchTree<BSTData>::operator=(const BinarySearchTree& rhs)
{
	root = rhs.root;
	return *this;
}

template<typename BSTData>
BinarySearchTree<BSTData>::~BinarySearchTree()
{
}

template<typename BSTData>
inline Node<BSTData>* BinarySearchTree<BSTData>::GetRoot()
{
	return root.get()->GetRightSubTree();
}

template<typename BSTData>
void BinarySearchTree<BSTData>::SetRoot(Node<BSTData>* NewRoot)
{
	if (NewRoot != GetRoot())
		root.get()->ChangeRightSubTree(NewRoot);
}

template<typename BSTData>
Node<BSTData>* BinarySearchTree<BSTData>::insert(const BSTData& Key)
{
	Node<BSTData>* ParentNode = nullptr;
	Node<BSTData>* CurrentNode = GetRoot();

	// 새로운 노드가 추가될 위치를 찾는다.
	while (CurrentNode != nullptr)
	{
		if (Key == CurrentNode->GetData())
			return nullptr;

		ParentNode = CurrentNode;

		if (Key < CurrentNode->GetData())
			CurrentNode = CurrentNode->GetLeftSubTree();
		else
			CurrentNode = CurrentNode->GetRightSubTree();
	}

	// ParentNode의 자식 노드로 추가할 NewNode 생성
	Node<BSTData>* NewNode = MakeBTreeNode<BSTData>(Key);
	
	// ParentNode의 자식 노드로 NewNode 추가
	if (ParentNode != nullptr)		// 새 노드가 루트 노드가 아니라면,
	{
		if (Key < ParentNode->GetData())
			ParentNode->MakeLeftSubTree(NewNode);
		else
			ParentNode->MakeRightSubTree(NewNode);
	}
	else	// 새 노드가 루트 노드라면,
	{
		SetRoot(NewNode);
	}

	return NewNode;
}

template<typename BSTData>
Node<BSTData>* BinarySearchTree<BSTData>::insert_AVL(const BSTData& Key)
{
	Node<BSTData>* retNode = insert(Key);
	SetRoot(Rebalance<BSTData>(GetRoot()));
	return retNode;
}

template<typename BSTData>
Node<BSTData>* BinarySearchTree<BSTData>::search(const BSTData& TargetKey)
{
	Node<BSTData>* CurrentNode = GetRoot();
	BSTData CurrentData;

	while (CurrentNode != nullptr)
	{
		CurrentData = CurrentNode->GetData();

		if (TargetKey == CurrentData)
			return CurrentNode;
		else if (TargetKey < CurrentData)
			CurrentNode = CurrentNode->GetLeftSubTree();
		else
			CurrentNode = CurrentNode->GetRightSubTree();
	}

	return nullptr;
}

template<typename BSTData>
void BinarySearchTree<BSTData>::erase(const BSTData& TargetKey)
{
	// 삭제할 노드 
	Node<BSTData>* DeleteNode = nullptr;
	// 삭제 대상의 부모 노드
	Node<BSTData>* ParentNode = root.get();
	// 현재 노드
	Node<BSTData>* CurrentNode = GetRoot();

	// 삭제 대상인 노드를 검색
	while (CurrentNode != nullptr && CurrentNode->GetData() != TargetKey)
	{
		ParentNode = CurrentNode;
		if (TargetKey < CurrentNode->GetData())
			CurrentNode = CurrentNode->GetLeftSubTree();
		else
			CurrentNode = CurrentNode->GetRightSubTree();
	}
	if (CurrentNode == nullptr)
		return;

	// 삭제 대상을 지정
	DeleteNode = CurrentNode;

	/* 1. 삭제할 노드가 단말 노드일 경우 */
	if (DeleteNode->GetLeftSubTree() == nullptr && DeleteNode->GetRightSubTree() == nullptr)
	{
		// 삭제할 노드가 왼쪽 자식 노드이면, 왼쪽 자식 노드 제거
		if (ParentNode->GetLeftSubTree() == DeleteNode)
			ParentNode->ChangeLeftSubTree(nullptr);
		// 삭제할 노드가 오른쪽 자식 노드이면, 오른쪽 자식 노드 제거
		else
			ParentNode->ChangeRightSubTree(nullptr);
	}
	/* 2. 삭제할 노드가 하나의 자식 노드를 가질 경우 */
	else if (DeleteNode->GetLeftSubTree() == nullptr || DeleteNode->GetRightSubTree() == nullptr)
	{
		// 삭제 대상의 자식 노드
		Node<BSTData>* ChildNode;

		// 삭제 대상의 자식 노드를 찾는다.
		if (DeleteNode->GetLeftSubTree() != nullptr)
			ChildNode = DeleteNode->GetLeftSubTree();
		else
			ChildNode = DeleteNode->GetRightSubTree();

		// 삭제 대상의 부모 노드와 자식 노드를 연결한다.
		if (ParentNode->GetLeftSubTree() == DeleteNode)
			ParentNode->ChangeLeftSubTree(ChildNode);
		else
			ParentNode->ChangeRightSubTree(ChildNode);
	}
	/* 3. 삭제할 노드가 두 개의 자식 노드를 가질 경우 */
	else
	{
		// 대체 노드
		Node<BSTData>* ReplaceNode = DeleteNode->GetRightSubTree();
		// 대체 노드의 부모 노드
		Node<BSTData>* pReplaceNode = DeleteNode;
		BSTData DeleteData;

		// 삭제 대상의 대체 노드를 찾습니다.
		while(ReplaceNode->GetLeftSubTree() != nullptr)
		{
			pReplaceNode = ReplaceNode;
			ReplaceNode = ReplaceNode->GetLeftSubTree();
		}

		// 대체할 노드에 저장된 값을 삭제할 노드에 대입합니다.
		DeleteData = DeleteNode->GetData();
		DeleteNode->SetData(ReplaceNode->GetData());

		// 대체할 노드의 부모 노드와 자식 노드를 연결합니다.
		if (pReplaceNode->GetLeftSubTree() == ReplaceNode)
			pReplaceNode->ChangeLeftSubTree(ReplaceNode->GetRightSubTree());
		else
			pReplaceNode->ChangeRightSubTree(ReplaceNode->GetRightSubTree());
		
		// 이 경우, 삭제할 노드는 실질적으로 대체 노드로 바뀌어야 한다.
		DeleteNode = ReplaceNode;
		DeleteNode->SetData(DeleteData);
	}

	delete DeleteNode;
}

template<typename BSTData>
void BinarySearchTree<BSTData>::erase_AVL(const BSTData& TargetKey)
{
	erase(TargetKey);
	SetRoot(Rebalance<BSTData>(GetRoot()));
}

template<typename BSTData>
void ShowAllBSTNode(BinarySearchTree<BSTData>* bst, PrintFunction<BSTData> PrintFunc, const ETraverseMode& Mode)
{
	switch (Mode)
	{

		case ETraverseMode::PREORDER:
			PreorderTraverse(bst->GetRoot(), PrintFunc);
			break;
		case ETraverseMode::INORDER:
			InorderTraverse(bst->GetRoot(), PrintFunc);
			break;
		case ETraverseMode::POSTORDER:
			PostorderTraverse(bst->GetRoot(), PrintFunc);
			break;
	}
}
