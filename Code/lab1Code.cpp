#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

using vector1D = vector<double>;
using vector2D =  vector<vector1D>;
using vector3D = vector<vector2D>;

//generate random 2D matrix with numbers between 0 and 20
vector2D gen2Dmatrix(int n){
 
 vector1D temp(n,0);
 vector2D matrix(n,temp);
 auto num = 0;
 
 for (auto i = 0; i< n; i++){ 
    for (auto j = 0 ; j< n ; j++){
	   	
           num = rand()%20;     
           matrix[i][j] = num;
     }
  }
  
 return matrix;

}

//2D matrix multiplication
vector2D rank2TensorMult(vector2D A, vector2D B){

 
 auto n = A.size();
 auto C = vector2D{};

 for(auto i = 0; i < n; i++){
    
  
    auto tempVector = vector<double>{};

    for(auto j = 0; j < n; j++){
           
	    auto tempSum =0;
    
	    for(auto k = 0; k < n; k++){
        	
		    tempSum += (A[i]).at(k)*(B[k]).at(j);

	    }

	  tempVector.push_back(tempSum);
     } 
    C.push_back(tempVector);
 }


return C;
}


//Display matrix

void display(vector2D x){

	auto n = x.size();

	for(auto i = 0; i <n; i ++){
	
		for(auto j = 0; j <n; j++){
		
		cout << x[i][j] << " | ";
		}
	     cout << endl;
	}

	cout << endl;
}


int main(){

        srand(time(0));
	auto n = 0;
        cout << "Please input the size(n) of the matrix: ";
        cin>> n;
        cout << endl;

        auto A = gen2Dmatrix(n);
        auto B = gen2Dmatrix(n);

        cout << " Matrix A =  "<< endl;
        display(A);

	cout << " Matrix B =  "<< endl;
	display(B);
	
        
	auto C = rank2TensorMult(A,B);

        cout <<" Matrix C =  "<< endl;
        display(C);

return 0;}

