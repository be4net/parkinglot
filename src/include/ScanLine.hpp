// Copyright [2021] <Stanislav Volkov>
#ifndef SRC_INCLUDE_SCANLINE_HPP_
#define SRC_INCLUDE_SCANLINE_HPP_

#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<u_int32_t, u_int32_t> timerange_t;

class point {
 public:
    enum class pointType:int8_t {END = -1, UNKNOWN = 0, START = 1};
    point(u_int32_t v, pointType t) : value(v), type(t) {}
    u_int32_t getValue() {return this->value;}
    pointType getType() {return this->type;}
    friend bool operator< (const point &p1, const point &p2) {
        return p1.value == p2.value?p1.type < p2.type:p1.value < p2.value;
    }
 private:
    ulong value;
    pointType type;
};

u_int32_t getInterceptionCount(const std::vector<timerange_t> &vi) {
    // Build Vector of Points in sorted manner
    std::vector<point> vr;
    for (auto x : vi) {
        auto p = point(x.first, point::pointType::START);
        auto it = std::upper_bound(vr.begin(), vr.end(), p);
        vr.insert(it, p);
        p = point(x.second, point::pointType::END);
        it = std::upper_bound(vr.begin(), vr.end(), p);
        vr.insert(it, p);
    }
    // Get the interceptions
    u_int32_t max = 0;
    int cnt = 0;
    for (auto i = 0ul; i < vr.size() && (vr.size()-i) > max; ++i) {
       cnt += static_cast<int>(vr.at(i).getType());
       max = std::max<u_int32_t>(max, cnt);;
    }
    return max;
}

#endif  // SRC_INCLUDE_SCANLINE_HPP_
