//
// Created by sultan on 1/29/19.
//

#ifndef VMRENTSYS_WITHOUT_DISCOUNT_H
#define VMRENTSYS_WITHOUT_DISCOUNT_H

#include "affiliative_discount.h"

class without_discount : public affiliative_discount{
public:
    without_discount();

    double getDiscount_percent() const override;

    void setDiscount_percent(double discount_percent) override;
    static shared_ptr<affiliative_discount> getInstance();

private:
    static bool instanceFlag;
    static shared_ptr<affiliative_discount> af_disc;
};

#endif //VMRENTSYS_WITHOUT_DISCOUNT_H
