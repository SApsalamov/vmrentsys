//
// Created by sultan on 1/22/19.
//

#ifndef VMRENTSYS_AFFILIATIVE_DISCOUNT_H
#define VMRENTSYS_AFFILIATIVE_DISCOUNT_H

#include <memory>
using namespace std;

class affiliative_discount {
protected:
    double discount_percent;

public:
    virtual double getDiscount_percent() const = 0;

    virtual void setDiscount_percent(double discount_percent) = 0;



};


#endif //VMRENTSYS_AFFILIATIVE_DISCOUNT_H
