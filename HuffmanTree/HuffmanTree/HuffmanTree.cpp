#include"HuffmanTree.h"
#include <iostream>
using namespace std;

template<class T>
HuffTree<T>::HuffTree(T nodeInfo[], int w[], int n)
{
	int i, k, i1, i2;

	if (n > maxTreeNode) throw "叶子结点大于最大30个，要修改程序才得行吆！";
	else if (n == 0) throw "叶子结点个数为0，光秃秃的没有树吆！";
	else numLeafNode = n;

	for (i = 0; i < 2 * n - 1; i++)
	{
		hNode[i].parent = -1;
		hNode[i].lchild = -1;
		hNode[i].rchild = -1;
		hNode[i].weight = -1;
	}


	for (i = 0; i < n; i++)
	{
		hNode[i].data = nodeInfo[i];
		hNode[i].weight = w[i];
	}


	for (k = n; k < 2 * n - 1; k++)
	{
		selectMinWeight(i1, i2);
		cout << "第" << k - n + 1 << "次构建哈夫曼树，选择的结点是:" << "i1 = " << i1 << ", i2 = " << i2 << endl;
		hNode[k].weight = hNode[i1].weight + hNode[i2].weight;
		hNode[i1].parent = k; hNode[i2].parent = k;
		hNode[k].lchild = i1; hNode[k].rchild = i2;
	}
	cout << endl;


	cout << "*************************************************" << endl << "哈夫曼树结点信息:" << endl << "*************************************************" << endl;
	cout << "id" << "\tdata" << "\tweight"
		<< "\tleft" << "\tright" << "\tparent" << endl;
	for (i = 0; i < 2 * numLeafNode - 1; i++)
	{
		cout << i << "\t"<< hNode[i].data
			<< "\t" << hNode[i].weight << "\t" << hNode[i].lchild
			<< "\t" << hNode[i].rchild << "\t" << hNode[i].parent << endl;
	}
	cout << endl;
}


template<class T>
HFNode<T>* HuffTree<T>::getHaffumanRoot()
{
	if (numLeafNode == 0) throw "叶子结点个数为0，光秃秃的没有树吆！";
	return &hNode[numLeafNode * 2 - 1 - 1];
}


template<class T>
void HuffTree<T>::selectMinWeight(int& i1, int& i2)
{
	int i, j;

	HFNode<T> tempNode;

	for (i = 0; i < 2 * numLeafNode - 1; i++)
	{
		
		if (hNode[i].weight != -1 && hNode[i].parent == -1)
		{
			tempNode = hNode[i];
			i1 = i;
			break;
		}
	}

	
	for (j = i + 1; j < 2 * numLeafNode - 1; j++)
	{
		if (hNode[j].weight != -1 && hNode[j].parent == -1 && hNode[j].weight < tempNode.weight)
		{
			tempNode = hNode[j];
			i1 = j;
		}
	}


	for (i = 0; i < 2 * numLeafNode - 1; i++)
	{
		
		if (i != i1 && hNode[i].weight != -1 && hNode[i].parent == -1)
		{
			tempNode = hNode[i];
			i2 = i;
			break;
		}
	}

	
	for (j = i + 1; j < 2 * numLeafNode - 1; j++)
	{
		if (j != i1 && hNode[j].weight != -1 && hNode[j].parent == -1 && hNode[j].weight < tempNode.weight)
		{
			tempNode = hNode[j];
			i2 = j;
		}
	}

}



template<class T>
void HuffTree<T>::hfCoding(HFNode<T>* node, int len)
{
	static int codingString[10];

	if (numLeafNode == 0) throw "叶子结点个数为0，光秃秃的没有树吆！";

	if (node->lchild == -1 && node->rchild == -1)
	{
		cout << "叶子结点" << node->data << "，权值为" << node->weight << "，其哈夫曼编码为：";
		for (int i = 0; i < len; i++)
			cout << codingString[i] << ' ';
		cout << endl;
	}
	else
	{
		codingString[len] = 0; hfCoding(&hNode[node->lchild], len + 1);
		codingString[len] = 1; hfCoding(&hNode[node->rchild], len + 1);
	}
}