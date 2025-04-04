#include <iostream>
#include <vector>
using namespace std;


main(){
	std::vector<int> v;
	int res,num,i=0;
	 	cout<<"Convertidor de decimal a binario"<<endl;
		cout<<"Ingresa el numero en decimal "<<endl;
		cin>>num;
		cout<<"-----------------------------"<<endl;
	
		while(num>0){
		 if(num%2==0){
		 	v.push_back(0);
		 }else 
		 {
		 	v.push_back(1);
		 }
		num/=2;
		
		
			
		}
		
		for(int i=v.size()-1;i>=0;i--){
			
			cout<<v[i];
		}
	
};
