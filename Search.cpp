#include<iostream>
#include<string>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>


/**************************************************************
*Name		 : Abhishek Kumar Srivastava
*Student ID	 : 200203011
*unity ID	 : asrivas3
*Program Name: Search.cpp
*Description : To perform DFS and BFS on a graph
**************************************************************/

using namespace std;

//Structure for a node in graph
struct Node
{
	string city_name;
	list<string> adj_city;
};

class Graph
{
	private:
		list<struct Node> gnode;
	public:
		void addNode(string N);
		void addEdge(string a, string b);
		list<string> findAdj(string source);
		void print();
};

//function to add node in a graph
void Graph::addNode(string N)
{
	struct Node node;
	node.city_name = N;
	gnode.push_back(node);
}

//function to add edge to the graph
void Graph::addEdge(string a, string b)
{
	int flag=0;
	list<struct Node>::iterator check = gnode.begin();
	while(check != gnode.end())
	{
		if(b.compare(check->city_name) == 0)
			flag = 1;
		check++;
	}
	if(flag != 1)
	{cout<<"City name " << b <<" does not exist\n";
		return;
	}
	flag = 0;
	list<struct Node>::iterator itr = gnode.begin();
	while(itr != gnode.end())
	{
		if(a.compare(itr->city_name) == 0)
		{
			flag = 1;
			itr->adj_city.push_back(b);
		}
		itr++;
	}
	if(flag != 1)
	{cout<<"City name " << a <<" does not exist\n";}
}

//function to find adjacent nodes of a particular node
list<string> Graph::findAdj(string source)
{
	//cout<<"DEBUG: Entered findAdj\n";
	list<string> adjNodes;
	list<struct Node>::iterator itr=gnode.begin();
	while(itr != gnode.end())
	{
		if(source.compare(itr->city_name) == 0)
		{
			list<string>::iterator i = itr->adj_city.begin();
			while(i != itr->adj_city.end())
			{
				adjNodes.push_back(*i);
				i++;
			}
		}
		itr++;
	}
	return adjNodes;
}

//function to print graph in adjacency list form
void Graph::print()
{
	list<struct Node>::iterator itr = gnode.begin();
	while(itr != gnode.end())
	{
		cout<<itr->city_name;
		list<string>::iterator i=itr->adj_city.begin();
		while(i != itr->adj_city.end())
		{
			cout<<" -> ";
			cout<<*i;
			i++;
		}
		cout<<endl;
		itr++;
	}
}

class Search : public Graph
{	
	public:
		void create();
		void dfs(string start, string goal);
		void bfs(string start, string goal);
};

//function to create the graph as given in question
void Search::create()
{
		//Adding nodes in the graph
		addNode("dobreta");
		addNode("mehadia");
		addNode("lugoj");
		addNode("timisoara");
		addNode("arad");
		addNode("zerind");
		addNode("oradea");
		addNode("sibiu");
		addNode("rimnicu vilcea");
		addNode("craiova");
		addNode("pitesti");
		addNode("bucharest");
		addNode("giurgiu");
		addNode("fagaras");
		addNode("urziceni");
		addNode("hirsova");
		addNode("eforie");
		addNode("vaslui");
		addNode("iasi");
		addNode("nearnt");
		
		//Adding Edges in the graph
		
		addEdge("dobreta","mehadia");
		addEdge("dobreta","craiova");
		addEdge("mehadia","lugoj");
		addEdge("mehadia","dobreta");
		addEdge("lugoj","timisoara");
		addEdge("lugoj","mehadia");
		addEdge("timisoara","arad");
		addEdge("timisoara","lugoj");
		addEdge("arad","sibiu");
		addEdge("arad","zerind");
		addEdge("arad","timisoara");
		addEdge("zerind","oradea");
		addEdge("zerind","arad");
		addEdge("oradea","sibiu");
		addEdge("oradea","zerind");
		addEdge("sibiu","oradea");
		addEdge("sibiu","arad");
		addEdge("sibiu","fagaras");
		addEdge("sibiu","rimnicu vilcea");
		addEdge("rimnicu vilcea","sibiu");
		addEdge("rimnicu vilcea","pitesti");
		addEdge("rimnicu vilcea","craiova");
		addEdge("craiova","dobreta");
		addEdge("craiova","rimnicu vilcea");
		addEdge("craiova","pitesti");
		addEdge("pitesti","rimnicu vilcea");
		addEdge("pitesti","bucharest");
		addEdge("pitesti","craiova");
		addEdge("fagaras","sibiu");
		addEdge("fagaras","bucharest");
		addEdge("bucharest","pitesti");
		addEdge("bucharest","fagaras");
		addEdge("bucharest","giurgiu");
		addEdge("bucharest","urziceni");
		addEdge("giurgiu","bucharest");
		addEdge("urziceni","bucharest");
		addEdge("urziceni","vaslui");
		addEdge("urziceni","hirsova");
		addEdge("hirsova","eforie");
		addEdge("hirsova","urziceni");
		addEdge("eforie","hirsova");
		addEdge("vaslui","urziceni");
		addEdge("vaslui","iasi");
		addEdge("iasi","vaslui");
		addEdge("iasi","nearnt");
		addEdge("nearnt","iasi");
		
		//cout<<"DEBUG: Graph Created\n";
}

//function to perform DFS
void Search::dfs(string start, string goal)
{
	//cout<<"DEBUG: Entered DFS\n";
	stack<list<string> > pathStk;
	list<string> visited;
	if(start.compare(goal) == 0)
	{
		cout<<"Source and Destination are same!!!\n So no path to print";
		return;
	}
	else
	{	
		list<string> source,temp,childs;
		source.push_back(start);
		pathStk.push(source);
		list<string>::iterator itr,i;
		int flag=0,flag2=0;
		while(!pathStk.empty())
		{
			temp=pathStk.top();
			pathStk.pop();
			i=find(visited.begin(),visited.end(),temp.back());
			if(i!=visited.end())
			{
				continue;
			}
			visited.push_back(temp.back());
			if((temp.back()).compare(goal) ==0)
			{
				flag2=1;
				break;
			}
			childs = findAdj(temp.back());
			childs.sort();
			childs.reverse();
			itr=childs.begin();
			while(itr != childs.end())
			{
					flag=0;
					list<string> temp_lst = temp;
					i=visited.begin();
					while(i!= visited.end())
					{
						if((*i).compare((*itr))==0)
						{flag=1;break;}
						i++;
					}
					if(flag != 1)
					{
						temp_lst.push_back((*itr));
						pathStk.push(temp_lst);
					}
				itr++;
			}
		}
		if(flag2 == 0)
			cout<<"\nGoal not found !!!\n";
		
		//Printing the path between source and destination
		cout<<"\nPath Between Source and Destination by DFS is: ";
		itr = temp.begin();
		while(itr!=temp.end())
		{
			cout<<*itr;
			itr++;
			if(itr!=temp.end())
				cout<<" -> ";
		}
		cout<<endl;
		//Printing all the visited nodes.
		cout<<"\nAll the visited nodes are as follows\n";
		itr = visited.begin();
		while(itr!=visited.end())
		{
			cout<<*itr;
			itr++;
			if(itr!=visited.end())
				cout<<", ";
		}
		cout<<"\n\nTotal Number of Nodes visited by DFS are: "<<visited.size()<<endl;
	}
}

//function to perform BFS
void Search::bfs(string start, string goal)
{
	//cout<<"DEBUG: Entered BFS\n";
	queue<list<string> > pathQ;
	list<string> visited;
	if(start.compare(goal) == 0)
	{
		cout<<"Source and Destination are same!!!\n So no path to print";
		return;
	}
	else
	{	
		list<string> source,temp,childs;
		source.push_back(start);
		pathQ.push(source);
		list<string>::iterator itr,i;
		int flag=0,flag2=0;
		while(!pathQ.empty())
		{
			temp=pathQ.front();
			pathQ.pop();
			i=find(visited.begin(),visited.end(),temp.back());
			if(i!=visited.end())
			{
				continue;
			}
			visited.push_back(temp.back());
			if((temp.back()).compare(goal) ==0)
			{
				flag2=1;
				break;
			}
			childs = findAdj(temp.back());
			childs.sort();
			itr=childs.begin();
			while(itr != childs.end())
			{
					flag=0;
					list<string> temp_lst = temp;
					i=visited.begin();
					while(i!= visited.end())
					{
						if((*i).compare((*itr))==0)
						{flag=1;break;}
						i++;
					}
					if(flag != 1)
					{
						temp_lst.push_back((*itr));
						pathQ.push(temp_lst);
					}
				itr++;
			}
		}
		if(flag2 == 0)
			cout<<"\nGoal not found !!!\n";
		
		//Printing the path between source and destination
		cout<<"\nPath Between Source and Destination by BFS is: ";
		itr = temp.begin();
		while(itr!=temp.end())
		{
			cout<<*itr;
			itr++;
			if(itr!=temp.end())
				cout<<" -> ";
		}
		cout<<endl;
		//Printing all the visited nodes
		cout<<"\nAll the visited nodes are as follows\n";
		itr = visited.begin();
		while(itr!=visited.end())
		{
			cout<<*itr;
			itr++;
			if(itr!=visited.end())
				cout<<", ";
		}
		cout<<"\n\nTotal Number of Nodes visited by BFS are: "<<visited.size()<<endl;
	}
}


int main(int argc, char *argv[])
{
	if(argc !=4)
	{
		cout<<"Please use this program in the format <program_name> <search_type> <starting_city> <ending_city>\n";
		return 0;
	}
	Search cg;
	cg.create();
	string algo(argv[1]);
	if(algo.compare("DFS")==0)
		cg.dfs(argv[2],argv[3]);
	else{
			if(algo.compare("BFS")==0)
				cg.bfs(argv[2],argv[3]);
			else
				cout<<"No such Searching Algorithm available\n";
		}
	return 0;
}