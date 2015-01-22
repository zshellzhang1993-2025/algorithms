int extend_Euclid(int a,int b,int &x,int &y){ 
    if(!b){
	   x = 1;
	   y = 0; 
	   return a; 
    } 
    int r = extendGcd(b,a % b,x,y); 
    int t = x;
    x = y; 
    y = t - a / b * y; 
    return r; 
} 
int Euclid(int a,int b){
    if(!b)
	   return a;
    else if(a % b != 0)
	   return b;
    else
	   return Gcd(b,a % b);
}
