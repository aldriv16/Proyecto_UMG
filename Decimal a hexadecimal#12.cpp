//decimales a hexadecimales
#include<iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v;
	int numero,pu;
	cout<<"dame el numero que necesitas a hexadecimal"<<endl;
	cin>>numero;
	pu=numero;
	if(pu>0){
		
	 while(pu>0){
	 
	v.push_back(pu%16);
     
	pu/=16;
	
//	cout<<" "<<pu<<endl;
	
}   
	 for (int i = v.size() - 1; i >= 0; i--)
	 {
	 	if(v[i]>=0 && v[i]<=9){
	 		cout<<v[i];
		 } else {
	 	switch (v[i]){
	 		   case 10: cout<<"A"; break;
	 		   case 11: cout<<"B"; break;
	 		   case 12: cout<<"C"; break;
	 		   case 13: cout<<"D"; break;
	 		   case 14: cout<<"E"; break;
	 		   case 15: cout<<"F"; break;
	 		  
	 		   
	 		
		 }
		 }
	 	
	 }
  	  
    cout<<endl;
}
 return 0;	
	
}
