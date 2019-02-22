#include <iostream>
#include <vector>

using namespace std;

using vector1D = vector<double>;
using vector2D =  vector<vector1D>;
using vector3D = vector<vector2D>;


vector2D rank2TensorMult(vector2D A, vector2D B){

 
 auto n = A.size();
 auto C = vector2D{};

 for(int i = 0; i < n; i++){
    
  
    auto tempVector = vector<double>{};

    for(int j = 0; j < n; j++){
           
	    auto tempSum =0;
    
	    for(int k = 0; k < n; k++){
        	
		    tempSum += (A[i]).at(k)*(B[k]).at(j);

	    }

	  tempVector.push_back(tempSum);
     } 
    C.push_back(tempVector);
 }


return C;
}


//For Validating

void display(vector2D x){

	auto n = x.size();

	for(int i = 0; i <n; i ++){
	
		for(int j = 0; j <n; j++){
		
		cout << x[i][j] << " | ";
		}
	     cout << endl;
	}


}


int main(){


	auto A = vector2D{ vector1D{2,-5,1},
		           vector1D{-3,6,2},
		           vector1D{1,0,-1}};
				
        auto B = vector2D{vector1D{0,-1,1},
			  vector1D{-2,2,2},
	                  vector1D{4,5,-1}};
        display(A);

	cout << " X "<< endl;
	display(B);
	cout<< " = " << endl;
        
	auto C = rank2TensorMult(A,B);

        display(C);

return 0;}

