#include<iostream>

using namespace std;

string auxiliar(string c,int a,int k){
    string b="";
    for(int i=a;i<k;i++){
            b+=c[i];
    }
    return b;
}
string pigLatinify(string swor){
    string b="";
    char c;
    int k=swor.size();
    if(swor[0]=='a' or swor[0] =='e' or swor[0]=='i' or swor[0]=='o' or swor[0]=='u'){
        b=auxiliar(swor,1,k);
        b+=("-way");
        return b;
    }
    if(swor[0]=='q'){
        b=auxiliar(swor,2,k);
        b+=("-quay");
        return b;
    }
    b=auxiliar(swor,1,k);
    b+=('-');
    b+=(swor[0]);
    b+="ay";
    return b;
}
int main(){
cout<<pigLatinify("happy")<<endl;
return 0;
}
