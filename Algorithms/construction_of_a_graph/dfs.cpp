#include<iostream>

#define N 5

class Vertex{
public:
	Vertex(){}
	Vertex(char name){
		this->name=name;
	}
	char getName(){
		return name;
	}
	void Clock(int clock){
		this->postClock=clock;
	}
	int getClock(){
		return postClock;
	}
	void setConnector(int connector){    //just like the property in C#
		if(connector>0)
			this->connector=connector;
		else
			throw connector;
	}
	int getConnector(){
		return connector;
	}
private:
	int postClock;
	int connector;
	char name;
}

class Graph{
public:
	Graph(){}
	Graph(int arc[N][N]){
		clock=0;
		for(int i=0;i<N;i++){
			visited[i]=false;
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				this->arc[i][j]=arc[i][j];
			}
	}
	int DFS(){
		for(int i=0;i<N;i++)
			visited[i]=false;
		int count=0;
		for(int i=0;i<N;i++){
			if(visited[i]==false)
				connector++;
				explore(i);
		}
		std::cout<<endl;
	}
private:
	void explore(int v){
		std::cout<<' '<<vertex[v].getName();
		visited[v]=true;
		vertex[v].setConnector(connector);
		clock++;
		for(int i=0;i<N;i++){
			if(arc[v][i]==1 && visited[i]==false)
				explore(i);
		}
		clock++;
		postVisit(v);
	}
	void postVisit(int v){
		vertex[v].Clock(clock);
	}
	Vertex vertex[N];
	bool visited[N];
	int arc[N][N];
	int clock;
	int connector;
}

int main(){
	try{
		
	}catch(int connector){
		
	}
	return 0;
}