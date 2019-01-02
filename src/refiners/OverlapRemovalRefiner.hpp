

#include "refiner.hpp"


class OverlapRemover : public Refiner {
protected:
    // Result results;
    // std::string text;
public:
    OverlapRemover() {

    }
    ~OverlapRemover() {}

    Result refine(Result r, std::string t) {
        Result filteredResults;
        parse::ParsedResult prevResult = r[0];

        if (r.size() < 2)
            return r;

        for(int i=1; i<r.size(); i++) {
            parse::ParsedResult tmpRes = r[i];
            if (tmpRes.getIndex() < prevResult.getIndex() + prevResult.textLength()) {
                if(tmpRes.textLength() > prevResult.textLength()) {
                    prevResult = tmpRes;
                }
                else {
                    filteredResults.push_back(prevResult);
                    prevResult = tmpRes;
                }
            }
        }
        if (!prevResult.isEmpty())
            filteredResults.push_back(prevResult);

        return filteredResults;
    }

};
