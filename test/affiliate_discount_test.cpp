#include <boost/test/unit_test.hpp>
#include <memory>
#include "affiliative_discount.h"
#include "big_fish_af_discount.h"
#include "starter_discount.h"
#include "without_discount.h"


BOOST_AUTO_TEST_SUITE(affiliate_discount_test)
    BOOST_AUTO_TEST_CASE(testbigfish_ExpectedDiscount) {
        std::shared_ptr<affiliative_discount> ad = big_fish_af_discount::getInstance();
        BOOST_REQUIRE_EQUAL(ad->getDiscount_percent(), 0.25);
    }

    BOOST_AUTO_TEST_CASE(testAmplifier_PowerRating100_ExpectedPower) {
        std::shared_ptr<affiliative_discount> ad = starter_discount::getInstance();
        BOOST_REQUIRE_EQUAL(ad->getDiscount_percent(), 0.1);

    }

    BOOST_AUTO_TEST_CASE(testStage_CreateEmpty_WithDefaultValues) {
        std::shared_ptr<affiliative_discount> ad = without_discount::getInstance();
        BOOST_REQUIRE_EQUAL(ad->getDiscount_percent(), 0);
    }


BOOST_AUTO_TEST_SUITE_END()