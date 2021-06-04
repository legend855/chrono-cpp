#pragma once

#include "refiner.hpp"


class OverlapRemover : public refiners::Refiner {
protected:
    // Result results;
    // std::string text;
public:
    OverlapRemover()  = default;

    Result refine(Result r, std::string) override {
        // can't have overlaps in 1 result
        if(r.size() < 2) {
            return r;
        }

        Result filteredResults;
        parse::ParsedResult prevResult{r[0]};

        for(unsigned i=1; i<r.size(); i++) {
            parse::ParsedResult tmpRes{r[i]};
            if (tmpRes.getIndex() < prevResult.getIndex() + prevResult.textLength()) {
                if (tmpRes.textLength() > prevResult.textLength())
                    prevResult = tmpRes;
            }
            else {
                filteredResults.push_back(prevResult);
                prevResult = tmpRes;
            }
        }
        if (!prevResult.isEmpty())
            filteredResults.push_back(prevResult);

        return filteredResults;
    }
};

