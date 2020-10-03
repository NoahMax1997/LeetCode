#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int thou=num/1000,hun=num/100%10,ten=num/10%10,units=num%10; 
        string ret="";
        for(int i=0;i<thou;i++) ret+='M';
        if(hun<=3){
        	for(int i=0;i<hun;i++){
        		ret+='C';
			}
		}else if(hun==4){
			ret+="CD";
		}else if(hun==5){
			ret+='D';
		}else if(hun>5&&hun<9){
			ret+='D';
			for(int i=5;i<hun;i++){
				ret+='C';
			}
		}else if(hun==9){
			ret+="CM";
		}
		if(ten<=3){
			for(int i=0;i<ten;i++){
        		ret+='X';
			}
		}else if(ten==4){
			ret+="XL";
		}else if(ten==5){
			ret+='L';
		}else if(ten>5&&ten<9){
			ret+='L';
			for(int i=5;i<ten;i++){
				ret+='X';
			}
		}else if(ten==9){
			ret+="XC";
		}
		
		if(units<=3){
			for(int i=0;i<units;i++){
        		ret+='I';
			}
		}else if(units==4){
			ret+="IV";
		}else if(units==5){
			ret+='V';
		}else if(units>5&&units<9){
			ret+='V';
			for(int i=5;i<units;i++){
				ret+='I';
			}
		}else if(units==9){
			ret+="IX";
		}
		return ret;
    }
};
int main (){
	Solution a;
	
	return 0;
} 
