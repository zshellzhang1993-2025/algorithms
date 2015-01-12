#include <iostream>

class Matrix{
public:
	Matrix(int row,int col){
		this->content=new int*[row];
		for(int i=0;i<row;i++)
			*(content+i)=new int[col];
		this->row=row;
		this->col=col;
	}
	Matrix(int **content,int row,int col,char name){
		this->content=new int*[row];
		for(int i=0;i<row;i++)
			*(content+i)=new int[col];
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++){
				*(*(this->content + i) + j) = *(*(content + i) + j);
			}
		this->row=row;
		this->col=col;
		this->name=name;
	}
	~Matrix(){
		for(int i=0;i<row;i++)
			delete[] *(content + i);
	}
	int getRow(){
		return row;
	}
	int getCol(){
		return col;
	}
	std::string getName(){
		return name;
	}
	int** getContent(){
		return content;
	}
	void setContent(int i,int j,int value){
		content[i][j]=value;
	}
private:
	int **content;
	int row;
	int col;
	std::string name;
};

struct state{
	int former;	//mark the former matrix
	int latter;	//mark the latter matrix
	int cost;	//mark the cost of two matrices multipling
};

class MatrixLinkMultiply{
public:
	static int optimizeCompute(Matrix m[], int count, Matrix *result){
		state **instance=new state*[count];
		for(int i=0;i<count;i++)
			*(instance + i)=new state[count];
		for(int i=0;i<count;i++){
			instance[i][i].cost=0;
			instance[i][i].former=-1;
			instance[i][i].latter=-1;
		}

		//below are the core component of this algorithm
		for(int s = 1; s < count; s++)
			for(int i = 0; i < count - s; i++){
				int j = i + s;
				instance[i][j].cost = getCost(i, i, i + 1, j, instance, m);
				instance[i][j].former = i * count + i;
				instance[i][j].latter = (i + 1) * count + j;
				for(int k = i + 1; k < j; k++){
					int temp = getCost(i, k, k + 1, j, instance, m);
					if(temp < instance[i][j].cost){
						instance[i][j].cost = temp;
						instance[i][j].former = i * count + k;
						instance[i][j].latter = (k + 1) * count + j;
					}
				}
			}
		//above are the core component of this algorithm
		
		std::string str = getOrder(m, instance, count - 1, count);	//output the order of the matrices sequence to multiply
		str=str.substr(1,str.length()-2);
		std::cout << str;
		getResult(m, instance, 0, count - 1, result, count);
		return instance[0][count - 1].cost;
	}
private:
	static int getCost(int row1,int col1,int row2,int col2, state **instance, Matrix m[]){
		return instance[row1][col1].cost + instance[row2][col2].cost + m[row1].getRow() * m[col1].getCol() * m[col2].getCol();
	}
	static std::string getOrder(Matrix m[],state **instance,int number,int count){
		int row = number / count;
		int col = number % count;
		std::string pre = "",suf = "";
		if(instance[row][col].former == -1)
			return m[row].getName();
		else
			pre = getOrder(m, instance, instance[row][col].former, count);
			suf = getOrder(m, instance, instance[row][col].latter, count);
		return " ( " + pre + " * " + suf + " ) ";
	}
	static void Multiply(Matrix *former,Matrix *latter,Matrix *result){
		int row=result->getRow();
		int col=result->getCol();
		int n=former->getCol();
		int value=0;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++){
				for(int k=0;k<n;k++)
					value += former->getContent()[i][k]+latter->getContent()[k][j];
				result->setContent(i,j,value);
				value = 0;
			}
	}
	static void getResult(Matrix m[],state **instance,int row,int col,Matrix *result,int count){
		Matrix *pre=NULL,*suf=NULL;
		if(instance[row][col].former == -1){
			for(int i=0;i<result->getRow();i++)
				for(int j=0;j<result->getCol();j++)
					result->setContent(i,j,m[row].getContent()[i][j]);
		}
		else{
			int r=instance[row][col].former / count;
			int c=instance[row][col].former % count;
			pre=new Matrix(m[r].getRow(),m[c].getCol());
			getResult(m,instance,r,c,pre,count);
			r=instance[row][col].latter / count;
			c=instance[row][col].latter % count;
			suf=new Matrix(m[r].getRow(),m[c].getCol());
			getResult(m,instance,r,c,suf,count);
			Multiply(pre,suf,result);
		}
		if(pre)
			delete pre;
		if(suf)
			delete suf;
	}
};

int main()
{
	
	
    return 0;
}