#include<iostream>
#include<string>
using namespace std;
class btree
{
	private:
		class tnode
		{
			public:
				int nodevalue;
				tnode*left,right;
				tnode()
				{
					nodevalue=0;
					left=NULL;
					right=NULL;
				}
				tnode(const int*item),tnode*lptr=NULL,
				tnode*rptr=NULL):
					nodevalue(item),left(lptr),right(rptr)
					{}
		};
		tnode* myroot;
		void inorderAux(osteam & out,btree::tnode* subtreePtr)const
		{
			if(subtreePtr != 0)
			{
				inorderAux(out,subtreePtr->left);//L²Ù×÷
				out<<subtreePtr->nodevalue<<" ";//v²Ù×÷
				inorderAux(out,subtreePtr->right);//R²Ù×÷
			}
		}
		void graphAux(ostream & out,int indent,btree::tnode* subtreeRoot)const
		{
			if(subtreeRoot != 0)
			{
				graphAux(out,indent + 8 ,subtreeRoot->right);
				out<<string(indent,' ')<<subtreeRoot->nodevalue<<endl;
				graphAux(out,indent + 8 ,subtreeRoot->left);
			}
		}
	public:
		btree();
		bool empty()const;
		void inorder(ostream & out)const;
		void graph(ostream & out)const;
		bool search(const int&item)const;
		void insert(const int&item);
};
inline btree::btree():myroot(0)
{}

inline bool btree::empty() const
{
	return myroot==0;
}

inline void btree::inorder(ostream & out)const
{
	inorderAux(out,myroot);
}

inline void btree::graph(ostream & out)const
{
	graphAux(out,0,myRoot);
}
bool btree::search(const int & item)const
{
	btree::tnode *locptr=myroot;
	bool found = false;
	while(!found && locptr !=0)
	{
		if(item<locptr->nodevalue)
		locptr=locptr->left;
		else if(locptr->nodevalue<item)
		locptr=locptr->right;
		else
		found = true;
	}
}
void btree::insert(const int& item)
{
	btree::tnode*locptr=myroot,
				*parent = 0;
	bool found = false;
	while(!found && locptr !=0)
	{
		parent = locptr;
		if(item<locptr->nodevalue)
		locptr = locptr->left;
		else if(locptr->nodevalue<item)
		locptr = locptr->right;
		else
		found = true;
	}
	if(!found)
	{
		locptr = new btree::tnode(item);
		if(parent==0)
		myroot = locptr;
		else if(item<parent->nodevalue)
		parent->left=locptr;
		else
		parent->right=locptr;
	}
	else
	cout<<"item has already in the tree.\n";
}
