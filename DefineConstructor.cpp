 // 2019, 1126, 10:30, by Queenie
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

        void before(const char *com, int n, double pr);
        void buy(int shareAmount, double dealPrice);
        void sell(int shareAmount, double dealPrice);
        void after(double dealPrice);
        void show();
          
};

