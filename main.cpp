#include <algorithm>
#include <iostream>
#include <vector>

struct stc_Point{
    double d_X;
    double d_Y;

    double d_Dis;
    stc_Point(double d_X, double d_Y){
        this->d_X   = d_X;
        this->d_Y   = d_Y;
        d_Dis       = d_X * d_X + d_Y * d_Y;
    }
};

struct stc_Sort{
    bool operator()(stc_Point* op_Fir, stc_Point* op_Sec){
        if(op_Fir->d_Dis > op_Sec->d_Dis){
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){
    int i_Num       = 0;
    std::cin >> i_Num;
    std::vector<stc_Point*> o_Set;

    for(int i_Ct = 0 ; i_Ct< 2; i_Ct++){
        double d_X     = 0;
        double d_Y     = 0;
        std::cin >> d_X >> d_Y;
        stc_Point* op_Tmp   = new stc_Point(d_X, d_Y);
        o_Set.push_back(op_Tmp);
    }
    int i_K         = 1;
    std::cin >> i_K;

    stc_Sort o_Sort;
    std::sort(o_Set.begin(), o_Set.end(), o_Sort);

    int i_Ct        = 0;
    for(std::vector<stc_Point*>::iterator op_1L = o_Set.begin();
            op_1L != o_Set.end();
            op_1L++){

        if(i_Ct++ >= i_K){
            break;
        }
        std::cout<< (*op_1L)->d_X << " " << (*op_1L)->d_Y << " ";
    }


    for(std::vector<stc_Point*>::iterator op_1L = o_Set.begin();
            op_1L != o_Set.end();
            op_1L++){
        delete (*op_1L);
    }
    return 0;
}
