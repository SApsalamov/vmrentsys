//
// Created by sultan on 1/29/19.
//

#ifndef VMRENTSYS_BIG_FISH_AF_DISCOUNT_H
#define VMRENTSYS_BIG_FISH_AF_DISCOUNT_H

#include "affiliative_discount.h"
class big_fish_af_discount: public affiliative_discount{

private:
    big_fish_af_discount();
    static bool instanceFlag;
    static shared_ptr<affiliative_discount> af_disc;

public:



    double getDiscount_percent() const override;

    void setDiscount_percent(double discount_percent) override;

    static shared_ptr<affiliative_discount> getInstance();


};

#endif //VMRENTSYS_BIG_FISH_AF_DISCOUNT_H
