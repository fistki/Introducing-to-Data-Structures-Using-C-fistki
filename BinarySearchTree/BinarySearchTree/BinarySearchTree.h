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

	// ��Ʈ ����� �ּҸ� ����ϴ�.
	Node<BSTData>* GetRoot();

	// ��Ʈ ��带 �缳�� �մϴ�.
	void SetRoot(Node<BSTData>* NewRoot);

	// Key�� BST�� �����մϴ�.
	// ���Կ� �����Ͽ��� ���, �ش� ����� �ּҸ� �����ϰ�, ���� �� nullptr�� �����մϴ�.
	Node<BSTData>* insert(const BSTData& Key);

	// Key�� BST�� �����մϴ�.
	// ���Կ� �����Ͽ��� ���, �ش� ����� �ּҸ� �����ϰ�, ���� �� nullptr�� �����մϴ�.
	// AVL Ʈ�� ������ ����Ͽ� ��� ���� ������ �ڵ����� ����ϴ�.
	Node<BSTData>* insert_AVL(const BSTData& Key);

	// TargetKey�� �����Ǵ� ��带 ã�Ƽ� �� �ּҸ� �����մϴ�. 
	Node<BSTData>* search(const BSTData& TargetKey);

	// TargetKey�� �����Ǵ� ��带 ã�Ƽ� ����ϴ�. �̶� ã�� ���� �޸𸮿��� delete �˴ϴ�.
	void erase(const BSTData& TargetKey);

	// TargetKey�� �����Ǵ� ��带 ã�Ƽ� ����ϴ�. �̶� ã�� ���� �޸𸮿��� delete �˴ϴ�.
	// AVL Ʈ�� ������ ����Ͽ� ��� ���� ������ �ڵ����� ����ϴ�.
	void erase_AVL(const BSTData& TargetKey);

private:
	// ��Ʈ ���
	std::shared_ptr<Node<BSTData>> root;
}; 

// BST�� ��� ��带 ��ȸ�մϴ�. �̶� �� ��帶�� void(const Type&)�� PrintFunc�� ����˴ϴ�.
// Mode 0 : ���� ��ȸ / Mode 1 : ���� ��ȸ / Mode 2 : ���� ��ȸ
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

	// ���ο� ��尡 �߰��� ��ġ�� ã�´�.
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

	// ParentNode�� �ڽ� ���� �߰��� NewNode ����
	Node<BSTData>* NewNode = MakeBTreeNode<BSTData>(Key);
	
	// ParentNode�� �ڽ� ���� NewNode �߰�
	if (ParentNode != nullptr)		// �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if (Key < ParentNode->GetData())
			ParentNode->MakeLeftSubTree(NewNode);
		else
			ParentNode->MakeRightSubTree(NewNode);
	}
	else	// �� ��尡 ��Ʈ �����,
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
	// ������ ��� 
	Node<BSTData>* DeleteNode = nullptr;
	// ���� ����� �θ� ���
	Node<BSTData>* ParentNode = root.get();
	// ���� ���
	Node<BSTData>* CurrentNode = GetRoot();

	// ���� ����� ��带 �˻�
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

	// ���� ����� ����
	DeleteNode = CurrentNode;

	/* 1. ������ ��尡 �ܸ� ����� ��� */
	if (DeleteNode->GetLeftSubTree() == nullptr && DeleteNode->GetRightSubTree() == nullptr)
	{
		// ������ ��尡 ���� �ڽ� ����̸�, ���� �ڽ� ��� ����
		if (ParentNode->GetLeftSubTree() == DeleteNode)
			ParentNode->ChangeLeftSubTree(nullptr);
		// ������ ��尡 ������ �ڽ� ����̸�, ������ �ڽ� ��� ����
		else
			ParentNode->ChangeRightSubTree(nullptr);
	}
	/* 2. ������ ��尡 �ϳ��� �ڽ� ��带 ���� ��� */
	else if (DeleteNode->GetLeftSubTree() == nullptr || DeleteNode->GetRightSubTree() == nullptr)
	{
		// ���� ����� �ڽ� ���
		Node<BSTData>* ChildNode;

		// ���� ����� �ڽ� ��带 ã�´�.
		if (DeleteNode->GetLeftSubTree() != nullptr)
			ChildNode = DeleteNode->GetLeftSubTree();
		else
			ChildNode = DeleteNode->GetRightSubTree();

		// ���� ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (ParentNode->GetLeftSubTree() == DeleteNode)
			ParentNode->ChangeLeftSubTree(ChildNode);
		else
			ParentNode->ChangeRightSubTree(ChildNode);
	}
	/* 3. ������ ��尡 �� ���� �ڽ� ��带 ���� ��� */
	else
	{
		// ��ü ���
		Node<BSTData>* ReplaceNode = DeleteNode->GetRightSubTree();
		// ��ü ����� �θ� ���
		Node<BSTData>* pReplaceNode = DeleteNode;
		BSTData DeleteData;

		// ���� ����� ��ü ��带 ã���ϴ�.
		while(ReplaceNode->GetLeftSubTree() != nullptr)
		{
			pReplaceNode = ReplaceNode;
			ReplaceNode = ReplaceNode->GetLeftSubTree();
		}

		// ��ü�� ��忡 ����� ���� ������ ��忡 �����մϴ�.
		DeleteData = DeleteNode->GetData();
		DeleteNode->SetData(ReplaceNode->GetData());

		// ��ü�� ����� �θ� ���� �ڽ� ��带 �����մϴ�.
		if (pReplaceNode->GetLeftSubTree() == ReplaceNode)
			pReplaceNode->ChangeLeftSubTree(ReplaceNode->GetRightSubTree());
		else
			pReplaceNode->ChangeRightSubTree(ReplaceNode->GetRightSubTree());
		
		// �� ���, ������ ���� ���������� ��ü ���� �ٲ��� �Ѵ�.
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
