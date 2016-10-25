#include<iostream>
/*Implementar clase Vector.Array Vector*/

using namespace std;

class punto{
    private:
        int x,y;
    public:
        punto(int _x=0){
            this->x=_x;
            this->y=_x;
        }
        void setx(const int _x){
            this->x=_x;
        }
        void sety(const int _y){
            this->y=_y;
        }
        int getx() const{
            return x;
        }
        int gety() const{
            return y;
        }
};

class Array{
    private:
        int tam;
        punto *point;
        void _resize(){
            this->tam-=1;
        }
    public:
        Array(){
            this->tam=0;
            this->point=NULL;
        }
        Array(const punto points[],int _size){
            this->tam=_size;
            this->point=new punto[this->tam];
            for(int i=0;i<this->tam;++i){
                this->point[i]=points[i];
            }
        }
        Array(const Array &uv){
            point=new punto[uv.tam];
            tam=uv.tam;
            for(int i=0;i<tam;++i){
                point[i]=uv.point[i];
            }
        }
        ~Array(){
            delete[] point;
        }
        int _getsize(){
            return this->tam;
        }
        void _pushback(punto elemento){
            punto q;
            q=new punto[this->tam+1];
            for(int i=0;i<this->tam;++i){
                q[i]=point[i];
            }
            q[this->tam]=elemento;
            point=q;
        }
};

int main(){
    Array vec;
}
