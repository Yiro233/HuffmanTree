#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
const int maxLeafNode = 10;  
const int maxTreeNode = maxLeafNode * 2 - 1;

template <class T>
struct HFNode   
{
	T data;     
	int weight; 
	int lchild, rchild, parent; 
};

template <class T>                        
class HuffTree
{
public:
	HuffTree() { numLeafNode = 0; }           
	HuffTree(T node[], int w[], int n);    
	~HuffTree() {}                         
	HFNode<T>* getHaffumanRoot();        
	void hfCoding(HFNode<T>*, int);       
private:
	HFNode<T>  hNode[maxTreeNode];        
	void selectMinWeight(int&, int&);      
	int numLeafNode;               
};
#endif

