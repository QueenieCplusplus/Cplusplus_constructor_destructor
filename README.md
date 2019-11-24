# Cplusplus_destructor
解構式能保證釋放記憶體資源後，仍被系統有效利用！(GC機制僅能釋放資源。)

# 建構資源

        Vec(int i) :elem{new int[i]}, sz{i}

        {
            // 對元素初始化
            for (int a=0; a!=i; ++a) elem[i] = 0;
        }
        
# 解構資源

        ~Vec(){
            delete[] elem;
        }
