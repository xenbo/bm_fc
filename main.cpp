//
// Created by dongbo on 2020/2/7.
//

#include <fc/variant_object.hpp>
#include <fc/exception/exception.hpp>

#include <string>

using namespace fc;

int main(){
    // no BOOST_CHECK / BOOST_REQUIRE, just see that this compiles on all supported platforms
    try {
        variant v(42);
        variant_object vo;
        mutable_variant_object mvo;
        variants vs;
        vs.push_back(mutable_variant_object("level", "debug")("color", v));
        vs.push_back(mutable_variant_object()("level", "debug")("color", v));
        vs.push_back(mutable_variant_object("level", "debug")("color", "green"));
        vs.push_back(mutable_variant_object()("level", "debug")("color", "green"));
        vs.push_back(mutable_variant_object("level", "debug")(vo));
        vs.push_back(mutable_variant_object()("level", "debug")(mvo));
        vs.push_back(mutable_variant_object("level", "debug").set("color", v));
        vs.push_back(mutable_variant_object()("level", "debug").set("color", v));
        vs.push_back(mutable_variant_object("level", "debug").set("color", "green"));
        vs.push_back(mutable_variant_object()("level", "debug").set("color", "green"));

    }catch (...){

    }

    return 0;
}

