#include "lib/EvaluationContext.hpp"
//---------------------------------------------------------------------------
namespace ast {


    void EvaluationContext::pushParameter(double value) {
    parameters.push_back(value);
}

double EvaluationContext::getParameter(size_t index) const {
    // Assuming that parameters are identified by zero-based indexes
    if (index < parameters.size()) {
        return parameters[index];
    }
    // Handle error - you may want to throw an exception or provide a default value
    return 0.0;
}
} // namespace ast
//---------------------------------------------------------------------------
