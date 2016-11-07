#include<iostream>
#include<math.h>

using namespace std;

double abs(double x,double y){
    if(x<y){
        return y-x;
    }
    return x-y;
}
double distancia(double w,double x,double y,double z){
    w=abs(w,y);
    x=abs(x,z);
    return sqrt(w*w+x*x);
}
class Point{
    private:
        double x,y;
    public:
        Point(double _x=0,double _y=0){
            this->x=_x;
            this->y=_y;
        }
        double getx() const {
            return x;
        }
        double gety() const {
            return y;
        }
        void insertx(double _X){
            this->x=_X;
        }
        void inserty(double _Y){
            this->y=_Y;
        }
};
class PointArray{
    private:
        int _size;
        Point *point;
        Point *vec;
        void incrementar(){
            this->_size++;
        }
        void decrementar(){
            this->_size--;
        }
    public:
        PointArray(double _Size=0){
            this->_size=_Size;
            this->point=NULL;
        }
        PointArray(const Point points[],int _size){
            this->_size=_size;
            this->point=new Point[this->_size];
            for(int i=0;i<this->_size;++i){
                this->point[i]=points[i];
            }
        }
        PointArray(const PointArray &v){
            point=new Point[v._size];
            this->_size=v._size;
            for(int i=0;i<this->_size;i++){
                this->point[i]=v.point[i];
            }
        }
        ~PointArray(){
            delete[] point;
        }
        void _PushBack(Point punto) {
            this->vec=new Point[this->_size+1];
            for(int i=0;i<this->_size;i++){
                this->vec[i]=this->point[i];
            }
            this->point=new Point[this->_size+1];
            incrementar();
            for(int i=0;i<this->_size;i++){
                this->point[i]=this->vec[i];
            }
            delete[] vec;
        }
        void posicion(Point punto,int n){
            this->vec=new Point[this->_size+1];
            n--;
            for(int i=0;i<n;i++){
                this->vec[i]=this->point[i];
            }
            this->vec[n]=punto;
            n++;
            incrementar();
            for(int i=n;i<this->_size;i++){
                this->vec[i]=this->point[i-1];
            }
            this->point=new Point[this->_size];
            for(int i=0;i<this->_size;i++){
                this->point[i]=this->vec[i];
            }
            delete[] vec;
        }
        int getsize() const {
            return this->_size;
        }
        double gettx(int n) const {
            return this->vec[n-1].getx();
        }
        double getty(int n) const {
            return this->vec[n-1].gety();
        }
        void remov(int pos){
            pos--;
            this->vec=new Point[this->_size-1];
            for(int i=0;i<pos;i++){
                this->vec[i]=this->point[i];
            }
            pos++;
            for(int i=pos;i<this->_size;i++){
                this->vec[i]=this->point[i];
            }
            decrementar();
            this->point=new Point[this->_size];
            for(int i=0;i<this->_size;i++){
                this->vec[i]=this->point[i];
            }
        }
        void getback(){
            this->vec=new Point[this->_size-1];
            decrementar();
            for(int i=0;i<this->_size;i++){
                this->vec[i]=this->point[i];
            }
            this->point=new Point[this->_size];
            for(int i=0;i<this->_size;i++){
                this->point[i]=this->vec[i];
            }
            delete[] vec;
        }
        void llenar(){
            for(int i=0;i<this->_size;i++){
                cout<<point[i].getx()<<endl;
                cout<<point[i].gety()<<endl;
            }
        }
};
class Polygon {
    protected:
        PointArray *vec;
        int key;
    public:
        Polygon(const PointArray Array[],int _size){
            this->key=_size;
            vec=new PointArray[this->key];
            for(int i=0;i<this->key;i++){
                this->vec[i]=Array[i];
            }
        }
        Polygon(const Polygon &u){
            vec=new PointArray[u.key];
            this->key=u.key;
            for(int i=0;i<this->key;i++){
                this->vec[i]=u.vec[i];
            }
        }
        ~Polygon(){
            delete[] vec;
        }
        int GetNumberofPolygons() const {
            return key;
        }
        int getsizes() const {
            return vec->getsize();
        }
        int getpoints() const {
            int suma=0;
            for(int i=0;i<this->key;i++){
                suma+=this->vec[i].getsize();
            }
            return suma;
        }
        double area() const{
            double area,Array[3];
            double area1;
            for(int i=0;i<this->key;i++){
                area1=0;
                for(int j=0,area=0;j<this->vec[i].getsize()-3;j++){
                    Array[0]=distancia(vec[i].gettx(j),vec[i].getty(j+1) ,vec[i].gettx(vec[i].getsize()-2),vec[i].getty(vec[i].getsize()-1));
                    Array[1]=distancia(vec[i].gettx(j+1),vec[i].getty(j+1) ,vec[i].gettx(vec[i].getsize()-2),vec[i].getty(vec[i].getsize()-1));
                    Array[2]=distancia(vec[i].gettx(j+1), vec[i].getty(j+1),vec[i].gettx(j),vec[i].getty(j));
                    area+=Array[0];
                    area+=Array[1];
                    area+=Array[2];
                    area/=2;
                    area1+=sqrt(area*(area-Array[0])*(area-Array[1])*(area-Array[2]));
                }
                cout<<area1<<endl;
            }
        }
};
class Rectangulo : public Polygon{
    private:
        Point points[4];
    public :
        Rectangulo(const Point pointss[]){
            for(int i=0;i<4;i++){
                this->points[i]=points[i];
            }
        }
        double area() const {
            return (abs(points[0].getx(),points[2].getx())*abs(points[0].gety(),points[2].getx()));
        }
};
class Triangulo : public Polygon{
    private:
        Point points[4];
    public:
        Triangulo(const Point pointss[]){
            for(int i=0;i<3;i++){
                this->points[i]=points[i];
            }
        }
        double area() const {
            double area=0,arr[3],elemento;
            for(int i=0;i<2;i++){
                arr[i]=distancia(points[i].getx(),points[i].gety(),points[i+1].getx(),points[i+1].gety());
                area+=(arr[i]);
            }
            arr[2]=distancia(points[0].getx(),points[0].gety(),points[2].getx(),points[2].gety());
            area+=arr[2];
            area/=2;
            return sqrt(area*(area-arr[0])*(area-arr[1])*(area-arr[2]));
        }
};
int main(){

return 0;
}
