/******************************************************************************

Desarrollado por David Esteban Perdomo Cristancho

*******************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <iomanip>

using namespace std;



void printnumber(int array[]){
    for(int i=0; i< sizeof(array) ; i++){
        cout << array[i];
    }
    cout << endl;
}

int *readint(string s){
  int n = s.length();  
  char char_array[n+1];  
  int *int_array = new int[n+1];
  //cout << "int array with size: " << sizeof(int_array)/sizeof(*int_array) << endl;
  for (int i=0; i<sizeof(int_array); i++) int_array[i]=0; 

  strcpy(char_array, s.c_str());  
  for (int i=0; i<n; i++) {
      if(char_array[i]!=46){
        int_array[i]=char_array[i]-48; 
      }
  }
  //cout << "ret int array : " << endl;
  //printnumber(int_array);
  return int_array; 
}


class BigDecimal {
    std::vector<int> digitos;
    int floatpoint;

  public:
    BigDecimal(int r) { 
        digitos.push_back(r);
    }
    
    int *sum(int arr1[], int arr2[], int n){
        int sizearr = n;
        int *answer= new int[n+1];
        
        int chksum = 0;
        for(int i=0;i<n;i++)answer[i];
        for(int i=n;i>0;i--){
            answer[i]= (arr1[i-1]+arr2[i-1]+chksum)%10;
            chksum = (arr1[i-1]+arr2[i-1]+chksum)/10;
        }
        answer[0]=chksum;
        
        return answer;
    }
    
    int *rest(int arr1[], int arr2[], int n){
        int sizearr = n;
        int *answer = new int[n+1];
        
        int chkrus = 0;
        for(int i=0;i<n;i++)answer[i]=0;
        for(int i=n;i>0;i--){
            answer[i]= ((arr1[i-1]+10)-arr2[i-1]-chkrus)%10;
            if((arr1[i-1]-arr2[i-1])<0){
                chkrus =1;
            }else{
                chkrus=0;
            }
        //    cout << answer[i] ;
        }
        /*cout << "resta:: " ;
        for (int i=0;i<=n;i++){
            cout << answer[i];
        }*/
        return answer;
    }
    
    int *divi(int num[], int dvs, int n){
        /*
        int sizearr = n;
        int numone[sizearr];
        numone[0]=1
        */
        long double divs = 1/((double)dvs);
        std::stringstream ss;
        ss << std::fixed << std::setprecision(n*2) << divs;
        std::string toarr = ss.str();
        /*cout << endl; 
        cout << "double : " << divs << endl;
        cout << "arr : " << ss.str() << endl;;*/
        //cout << "arr alm : " << toarr << endl;
        
        int *divisor = readint(toarr);
        int sizediv = sizeof(divisor);
        //cout << " - denominador: with size " << sizediv << endl;
        //printnumber(divisor);
        //cout << "--sizedivbyte: " << sizediv << " -sizestr: " << toarr.size() << " -numsize: " << n << endl; 
        
        //if(sizediv > n){
        if(toarr.size() > n){
            int numer[sizediv];
            for(int i=0;i<sizediv;i++){
                if(i<(sizediv-n)){
                    numer[i]=0;
                }else{
                    numer[i]=num[i-(sizediv-n)];
                }
            }
            //cout << "division: " << endl;
            //cout << " - numerador: " << endl;
            //printnumber(numer);
            
            return mult(numer,divisor,sizediv);
        }else {
            //cout << "suporting .. n=" << n << endl;
            int ndivi[n];
            for(int i=0;i<n;i++){
                ndivi[i]=0;
            }
            
            //cout << "division: " << endl;
            //cout << " - divisor: " << endl;
            //printnumber(ndivi);
            return mult(num,ndivi,n);
        }

    }
//multiply array integer < 10
    int *mult(int arr1[], int arr2[], int n){
        /*cout << "In mulitiplication with size " << n << endl;
        printnumber(arr1);
        printnumber(arr2);*/
        
        int sizearr = n;
        std::vector<int> answers;
        int *respuesta = new int[sizearr*2];
        int hind[sizearr][sizearr];
        
        for(int i=0;i<sizearr*2;i++)respuesta[i];
        //Hindu matrix
        for(int i=0;i<sizearr;i++){
          for(int j=0;j<sizearr;j++){
              hind[j][i]=arr1[i]*arr2[j];
          }
        }
      
        //Adding hindu matrix diagonals
        int aux =0;
        int sum =0;
        for (int i=0;i<sizearr;i++) {
            sum = aux;
            aux = 0;
            for (int j=0;j<=i;j++) { 
                sum += hind[i-j][j]/10;
                aux += hind[i-j][j]%10;
            }
            answers.push_back(sum);
        }
        
        //adding bottom diagonal
        for (int i=0;i<sizearr;i++) {
            sum = aux;
            aux=0;
            for (int j=0;j<sizearr-i-1;j++) { 
                sum +=(hind[sizearr-j-1][j+i+1])/10;
                aux += (hind[sizearr-j-1][j+i+1])%10;
            }
            answers.push_back(sum);
        }
    
        //Adding answers array
        int prev = 0;
        for(int idx=answers.size()-1 ; idx >= 0; idx--){
            respuesta[idx]= ((answers[idx]%10) + prev)%10;
            prev = answers[idx]/10 + ((answers[idx]%10) + prev)/10;
        }
    
        //print answer
        /*cout << "multiplicacion:: " ;
        for (int i=0;i<sizearr*2;i++){
            cout << respuesta[i];
        }*/
        return respuesta;
    }
    
    double calcPi(int n){
        double suma;
     
        suma=0.0;
     
        for (int i=0; i<=n; i++){
            if ((i=2)||((i%2)==0)){
                suma=suma+(1/(2*i+1));
                //suma = sum(suma,1/(2*i+1),n);
            }
            else{ 
                suma=suma-(1/(2*i+1));
                //suma = sum(suma,1/(2*i+1,n);
            }
        }
     
    return 4*suma;
    }
};

void runtest(){
        
    cout << "       TEST " << endl;
    cout << endl;
    
    BigDecimal foo (0);   
    //El tamaño de los arreglos debe ser igual

    string ip1 = "010074";
    string ip2 = "010852";
    
    int *intarr1 = readint(ip1);
    int *intarr2 = readint(ip2);
    
    cout << ip1 << "," << ip2 << endl << endl;
    cout << "Multiplicación: ";
    int *multiarra = foo.mult(intarr1,intarr2,ip1.size());
    printnumber(multiarra);
    cout << endl;
    cout << "Suma: ";
    int *sumarra = foo.sum(intarr1,intarr2,ip1.size());
    printnumber(sumarra); 
    cout << endl;
    cout << "Resta: ";
    int *restarra = foo.rest(intarr2,intarr1,ip1.size());
    printnumber(restarra);
    cout << endl;
    cout << "Division: ";
    int *diviarra = foo.divi(intarr1,3,ip1.size());
    printnumber(diviarra);
}

int main () {
    runtest();
    return 0;
}