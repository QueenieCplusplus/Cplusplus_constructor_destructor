// 2019, 11/24, 15:00, by Queenie
// destructor

class Vec {
    private:
     // pattern called elem{double}
        int* elem; // elem 指向含有浮點型別元素的變數容器
        int sz;
       
        

    public:
        // 建構式
        // 取得資源
        // new 會複製 int 元素型別的陣列
        // 建構式利用成員初值列來初始化型別的成員
        // 系統保證建構式的功用
        Vec(int i) :elem{new int[i]}, sz{i}

        {
            // 對元素初始化
            for (int a=0; a!=i; ++a) elem[i] = 0;
        }

        // 解構式
        // 釋放資源
        // delete 是關鍵字
        ~Vec(){
            delete[] elem;
        }
        

}; // 類別需要以 ; 結尾

void fv(int n)
{
    Vec v1(n); //建構v1


    {
        Vec v2(n+1);

    } // 解構 v2 已經完成

}// 解構 v1 已經完成

// _main implicits entry/ start for main executable for arch x86_64
int main() {
    fv(3);
    return 0;
}
