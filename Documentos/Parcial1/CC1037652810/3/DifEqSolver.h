#include <string>
#include <functional>

using namespace std;

class DifEqSolver
{
public:
  DifEqSolver(std::function<double(double, double)>);
  double ModifiedEuler();
  double RungeKutta4o(double);
  void integrationcomparison();

 private:
  double x0;
  double y0;
  double h;
  double xf;
  std::function<double(double, double)> f;
};
