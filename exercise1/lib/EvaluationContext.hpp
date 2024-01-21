#ifndef H_lib_EvaluationContext
#define H_lib_EvaluationContext
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
namespace ast {

class EvaluationContext {
public:
    void pushParameter(double value);
    double getParameter(size_t index) const;

private:
    std::vector<double> parameters;
};

} // namespace ast
//---------------------------------------------------------------------------
#endif
