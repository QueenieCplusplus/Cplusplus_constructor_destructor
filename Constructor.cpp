 // 2019, 1126, 10:30, by Queenie
 // Constructor
 // 初始化私有物件變數容器
 
 class ShareMarket{

   private:
        char target[10];
        int shares;
        float share_val;
        double total_val;
        void know_totoal(){
          total_val= shares * share_val;
        }

   public:
        ShareMarket(){}; // 建構函數 
        void before(const char *com, int n, double pr);
        void buy(int shareAmount, double dealPrice);
        void sell(int shareAmount, double dealPrice);
        void after(double dealPrice);
        void show();
          
};
