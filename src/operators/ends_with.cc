/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2021 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "src/operators/ends_with.h"

#include <string>

#include "src/operators/operator.h"

namespace modsecurity {
namespace operators {


bool EndsWith::evaluate(Transaction *transaction, RuleWithActions *rule,
    const std::string &str, RuleMessage &ruleMessage) {
    bool ret = false;
    std::string p(m_string->evaluate(transaction));

    if (str.length() >= p.length()) {
        ret = (0 == str.compare(str.length() - p.length(),
            p.length(), p));
        if (ret) {
            logOffset(ruleMessage, str.length() - p.length(),
                      p.size());
        }
    }

    return ret;
}


}  // namespace operators
}  // namespace modsecurity
