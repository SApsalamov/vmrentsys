
#include <without_discount.h>

#include "without_discount.h"

without_discount::without_discount() {
    discount_percent = 0;
}

double without_discount::getDiscount_percent() const {
    return discount_percent;
}

void without_discount::setDiscount_percent(double disc_percent) {
    discount_percent = disc_percent;
}

bool without_discount::instanceFlag = false;
shared_ptr<affiliative_discount>  without_discount::af_disc = NULL;

shared_ptr<affiliative_discount> without_discount::getInstance() {
    if(! instanceFlag)
    {
        af_disc = shared_ptr<without_discount>(new without_discount());
        instanceFlag = true;
        return af_disc;
    }
    else
    {
        return af_disc;
    }
}
