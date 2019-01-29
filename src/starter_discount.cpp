#include "starter_discount.h"


starter_discount::starter_discount() {
    discount_percent = 0.1;
}

double starter_discount::getDiscount_percent() const {
    return discount_percent;
}

void starter_discount::setDiscount_percent(double dis_percent) {
    discount_percent = dis_percent;
}

bool starter_discount::instanceFlag = false;
shared_ptr<affiliative_discount>  starter_discount::af_disc = NULL;

shared_ptr<affiliative_discount> starter_discount::getInstance() {

    if(! instanceFlag)
    {
        af_disc = shared_ptr<starter_discount>(new starter_discount());
        instanceFlag = true;
        return af_disc;
    }
    else
    {
        return af_disc;
    }
}
