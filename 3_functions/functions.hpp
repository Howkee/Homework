int max(int a, int b);

int factorialRec(int x);
inline int factorial(int x){
    int rez = x;
    if(x < 1)
        return 1;
    while(x > 1){
        rez *= x - 1;
        x--;
    }
    return rez;
}

long double MyPow(double x, int y);

int compare(const void * x1, const void * x2);

void myPrint(int a);
void myPrint(double a);
void myPrint(char* a);

int* myRealloc(int *masMemory, int &size, int newSize);