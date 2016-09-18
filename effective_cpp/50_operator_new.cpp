#include <iostream>
using namespace std;

//void * operator new (std::size_t sz) { // will cause a warning
void * operator new (std::size_t sz) throw(std::bad_alloc){
	cout<<"malloc sz="<<sz<<endl;
	return malloc(sz);
}
void operator delete (void* ptr) throw(){
	cout<<"hehe"<<endl;
	free(ptr);
}


#include <iostream>
#include <string>
using namespace std;

char data[1000];
class X
{
public:
    X() { num=-1;cout<<"constructor of X"<<endl; }
    X(int input){num=input;}
    ~X() { cout<<"destructor of X"<<endl;}
    // static void* operator new(size_t size,string str)
    // {
    //     cout<<"operator new size "<<size<<" with string "<<str<<endl;
    //     return ::operator new(size);
    // }
    static void operator delete(void* pointer)
    {
        cout<<"operator delete, val="<<((X*) pointer)->num<<endl;
        ::operator delete(pointer);
    }
    int num;
private:
    
};

int main()
{
    //X *px = new("wtf") X;
    X *px = new X;
    cout<<px<<endl;
    cout<<(void*)data<<endl;

    X *py = new((void*)px) X;
    //int *py=new((void*)px) int;
    py->num=3;
    delete px;

    return 0;
}
