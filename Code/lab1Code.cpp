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

//3D MULTIPLICATION

vector3D rank3TensorMult(vector3D a, vector3D b)
{
	        auto  n = a.size();
		auto C = vector3D{};

		for(auto i = 0; i < n; i++){
		
		       auto subC = vector2D{};
                       
                       subC = rank2TensorMult(a.at(i),b.at(i));
		       
		       C.push_back(subC);
                               
			}
		
		return C;
		 
}

//3D ADDITION

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


void print(vector3D x){

   auto n = x.size();
      
       	  cout << "===========\n" << endl;
       
	for(int i = 0; i < n; i++){

            print(x[i]);

          	 }

	  cout << "===========\n" << endl;
}





int main(){

        /*srand(time(0));
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
	*/


	auto A = vector2D{ vector1D{2,5,1},
		           vector1D{3,6,2},
		           vector1D{1,0,1}};
				
        auto B = vector2D{vector1D{0,1,1},
			  vector1D{2,2,2},
	                  vector1D{4,5,1}};
      
       	
	auto A3 = vector3D{A,B,A};
       	auto B3 = vector3D{B,A,B};

        print(A3);
        cout << " X \n\n\n ";
        print(B3);

        auto C3 = rank3TensorAdd(3,A3,B3);
        cout << "  =  " << "\n\n";
       	print(C3);
        
       


return 0;}

