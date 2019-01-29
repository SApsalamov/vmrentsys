
#include <big_fish_af_discount.h>




double big_fish_af_discount::getDiscount_percent() const {
    return discount_percent;
}

void big_fish_af_discount::setDiscount_percent(double dis_percent) {
    discount_percent = dis_percent;
}

big_fish_af_discount::big_fish_af_discount() {
    discount_percent = 0.25;
}

bool big_fish_af_discount::instanceFlag = false;
shared_ptr<affiliative_discount>  big_fish_af_discount::af_disc = NULL;

shared_ptr<affiliative_discount> big_fish_af_discount::getInstance() {

    if(! instanceFlag)
    {
        af_disc = shared_ptr<big_fish_af_discount>(new big_fish_af_discount());
        instanceFlag = true;
        return af_disc;
    }
    else
    {
        return af_disc;
    }
}
