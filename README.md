# Cplusplus_destructor
解構式能保證釋放記憶體資源後，仍被系統有效利用！(GC機制僅能釋放資源。)

建構成員函數的意義是，如果實例沒有對類別的私有物件做指定值，則無法確保運用介面時，能讓值做真正的更新目的，而建構子就是作用在此，能自動初始化其所有私有物件的值。

# 建構函數（初始化私有物件）

         // Define a Constructor
         // 建構函數的定義
         // 初始化私有物件變數容器
 
         class ShareMarket{

           private:

                char target[10]; // company
                int shares;
                float share_val;

                // 不在初始化範圍
                double total_val;

                void know_totoal(){ 
                  total_val= shares * share_val;
                }

           public:

                // 建構函數的定義 
                // 建構函數與類別同名
                // 專門初始化物件（類別的私有物件）
                // 沒有回傳值
                ShareMarket(const char *com, int n, double pr){

                  target[9]='\0';

                  // 輸入值沒有通過驗證後的處理方式
                  if(n<0)
                  { 
                    std::cerr <<"想說的錯誤提醒" << target << "shares set to zero\n";
                    shares = 0;
                  }
                  else
                    // 輸入值正常地傳入
                    shares = n; 
                    share_val = pr;
                    know_totoal();
                }; 

                // 如下等待使用者實作方法細節
                void before(const char *com, int n, double pr);
                void buy(int shareAmount, double dealPrice);
                void sell(int shareAmount, double dealPrice);
                void after(double dealPrice);
                void show();

        };

# 建構子用 new 配置記憶體資源

建構幫助容器成為具有效約束條件且具有邊界檢驗能力存取功能的物件，其中 size() 方法能協助尋訪元素，但是建構的缺點是它會利用 new 方法來配置元素，然而卻沒有釋放它們，雖然系統有 GC 垃圾回收處理介面，但不能保證讓系統有效率的使用釋放的記憶體空間的資源。

建構式利用 new 運算子在 free store 自由空間（也稱為 dynamic store 動態空間或是 heap 堆積）中配置一記憶體空間。

        // 下行為帶有初值列的建構式。
        // , 符號代表序列
        Vec(int i) :elem{new int[i]}, sz{i}

        {
            // 對元素初始化
            for (int a=0; a!=i; ++a) elem[i] = 0;
        }

# 初始值列 (避免資源型別窄化，徒增日後煩惱)
   https://github.com/QueenieCplusplus/Cplusplus_Structure/blob/master/README.md#initializer_list-constructor-帶有初始值列的建構式
        
# 利用 ~ 解構資源

為了效能，推薦使用解構式，解構式利用補數運算子 ~ 後面加上類別名稱，它與建構式互補。

        ~Vec(){
            delete[] elem;
        }
