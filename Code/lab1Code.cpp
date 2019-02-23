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

//2D matrix addition
vector2D rank2TensorAdd(int n,vector2D A, vector2D B){
 
 vector1D temp(n,0);
 vector2D C(n,temp);
 
 for (auto i = 0;i < n; i++){
     for(auto j = 0; j<n; j++){
	C[i][j] = A[i][j]+B[i][j];
      }
 }
 
 return C;

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


vector3D rank3TensorMult(vector3D a, vector3D b)
{
	
		 auto C = vector3D{};
		
		auto Layer1 = vector<vector2D>{a.at(0),b.at(0)};
		auto Layer2 = vector<vector2D>{a.at(1),b.at(1)};
		auto Layer3 = vector<vector2D>{a.at(2),b.at(2)};
		
		auto First = rank2TensorMult(Layer1.at(0), Layer1.at(1));
		auto Second = rank2TensorMult(Layer2.at(0), Layer2.at(1));
		auto Third = rank2TensorMult(Layer3.at(0), Layer2.at(1));
		
		C.push_back(First);
		C.push_back(Second);
		C.push_back(Third);
		
		return C;
		 
}


int main(){

        srand(time(0));
	auto n = 0;
        cout << "Please input the size(n) of the matrix: ";
        cin>> n;
        cout << endl;
           
        auto A = gen2Dmatrix(n);
        auto B = gen2Dmatrix(n);
		auto C_one = gen2Dmatrix(n);

        cout << " Matrix A =  "<< endl;
        display(A);

	cout << " Matrix B =  "<< endl;
	display(B);
	
		cout << " Matrix C_one =  "<< endl;
	display(C_one);

	auto C = rank2TensorMult(A,B);
	auto C_1 = rank2TensorAdd(n,A,B);
        	
        cout << "2D MULTIPLICATION of A X B" << endl;
	cout <<" Matrix C =  "<< endl;
        display(C);

        cout << " ADDITION Result of A + B" << endl;
	cout <<" Matrix C_1 =  "<< endl;
        display(C_1);
			cout <<endl;
			cout <<endl;
		//3D MATRICES
			auto matrix3D1 = vector3D{A,B,C_one};
			cout << "FIRST 3D MATRIX is made of : " << " LAYER 1: MATRIX A, LAYER 2: MATRIX B, LAYER 3: MATRIX C_one " <<endl;
			auto matrix3D2 = vector3D{C_one,B,A};
			cout <<endl;
			cout <<endl;
			cout << "FIRST 3D MATRIX is made of : " << " LAYER 1: MATRIX C_one, LAYER 2: MATRIX B, LAYER 3: MATRIX A " <<endl;
			
		//3D MULTIPLICATION
			auto MultResult = rank3TensorMult(matrix3D1, matrix3D2);
			cout <<endl;
			cout <<endl;

			cout << "3DMULTIPLICATION RESULT" <<endl;
			cout <<endl;
			cout <<endl;
			cout << "LAYER 1 OF RESULT" <<endl;
			display(MultResult.at(0));
			cout <<endl;
			cout <<endl;
			cout << "LAYER 2 OF RESULT" <<endl;
			display(MultResult.at(1));
			cout <<endl;
			cout <<endl;
			cout << "LAYER 3 OF RESULT" <<endl;
			display(MultResult.at(2));

		//3D ADDITION

return 0;}

