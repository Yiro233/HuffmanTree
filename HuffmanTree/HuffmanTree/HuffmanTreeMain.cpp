#include<string>
#include"huffmanTree.cpp"

void main()
{
	int i = 0;

	cout << "*************************************************" << endl << "1)����һ�ù�������:" << endl << "*************************************************" << endl;
	string studentArray[8] = { "A","B","C","D","E","F","G","H" };
	int    weightStudent[8] = { 1, 2 ,3, 4, 5, 6, 7, 8 };
	HuffTree<string> ht(studentArray, weightStudent, 8); 
	cout << "*************************************************" << endl << "2)��������Ҷ������:" << endl << "*************************************************" << endl;
	ht.hfCoding(ht.getHaffumanRoot(), 0);
	system("pause");
}