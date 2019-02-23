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

//generate random 3D matrix with numbers between 0 and 20

vector3D gen3Dmatrix(int n){

  vector3D matrix;
   
  for(int i = 0; i< n ; i++){

  	matrix.push_back(gen2Dmatrix(n));
  }
 
  return matrix;

}


//Print 2D matrix

void print(vector2D x){

   auto n = x.size();

   for(auto i = 0; i <n; i ++){
	
	for(auto j = 0; j <n; j++){
		
	     cout << x[i][j] << " | ";
	}
	cout << endl;
    }

    cout << endl;
}

//3D Multiplication

vector3D rank3TensorMult(vector3D a, vector3D b){

   auto  n = a.size();
   auto C = vector3D{};

   for(auto i = 0; i < n; i++){
		
       auto subC = vector2D{};
                       
       subC = rank2TensorMult(a.at(i),b.at(i));
		       
       C.push_back(subC);
                               
    }
		
   return C;
		 
}

//3D Addition

vector3D rank3TensorAdd(int n,vector3D a, vector3D b)
{
	
   auto C = vector3D{};

   for(auto i = 0; i < n; i++){
		
        auto subC = vector2D{};
                       
        subC = rank2TensorAdd(n,a.at(i),b.at(i));
		       
        C.push_back(subC);
                               
    }

   return C;
}

//Print 3D matrix

void print(vector3D x){

   auto n = x.size();
      
   for(int i = 0; i < n; i++){

       print(x[i]);

    }
   
   cout << endl;
}

//Computations and display

void _2D_computations(int n){

   auto A = gen2Dmatrix(n);
   auto B = gen2Dmatrix(n);
   cout << "============2D Computations============" <<"\n" <<endl;
   cout << " Matrix A =  "<< endl;
   print(A);

   cout << " Matrix B =  "<< endl;
   print(B);
   
   cout << " ADDITION (A + B)" << endl;
   cout <<"  Matrix C =  "<< endl;
 
   auto C = rank2TensorAdd(n,A,B);
   auto C_1 = rank2TensorMult(A,B);
   print(C);
   cout << " MULTIPLICATION (A X B)" << endl;
   
   cout <<" Matrix C =  "<< endl;
   print(C_1);

}

void _3D_computations(int n){

   auto A = gen3Dmatrix(n);
   auto B = gen3Dmatrix(n);
  
   cout << "============3D Computations============" <<"\n" <<endl;
   cout << " Matrix A =  "<< endl;
   print(A);

   cout << " Matrix B =  "<< endl;
   print(B);
   
   cout << " ADDITION (A + B)" << endl;
   cout <<"  Matrix C =  "<< endl;
  
   auto C = rank3TensorAdd(n,A,B);
   auto C_1 = rank3TensorMult(A,B);
   print(C);

   cout << " MULTIPLICATION (A X B)" << endl;
   cout <<" Matrix C =  "<< endl;
   print(C_1);
  
}

int main(){

   srand(time(0));
   auto n = 0;
   cout << "Please input the size(n) of the matrix: ";
   cin>> n;
   cout << endl;
           
   _2D_computations(n);
   _3D_computations(n);


    return 0;
}

