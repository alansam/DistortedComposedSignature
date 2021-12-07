
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <cmath>

int main() {
  auto is_lt = [](auto const & lhs, auto const & rhs) {
    auto tr = lhs < rhs;
    return tr;
  };
  auto is_ge = [](auto const & lhs, auto const & rhs) {
    auto tr = !(lhs < rhs);
    return tr;
  };
  auto is_gt = [](auto const & lhs, auto const & rhs) {
    auto tr = (rhs < lhs);
    return tr;
  };
  auto is_le = [](auto const & lhs, auto const & rhs) {
    auto tr = !(rhs < lhs);
    return tr;
  };
  auto is_eq = [](auto const & lhs, auto const & rhs) {
    auto tr = (!(lhs < rhs) && !(rhs < lhs));
    return tr;
  };
  auto is_nq = [](auto const & lhs, auto const & rhs) {
    auto tr = !(!(lhs < rhs) && !(rhs < lhs));
    return tr;
  };

  auto play = [](auto & prs, auto & fn, auto const & cc) {
    for (auto const & va : prs) {
      auto const lhs = va.first;
      auto const rhs = va.second;
      std::cout << lhs << cc << rhs << " = "
                << std::boolalpha
                <<  fn(lhs, rhs)
                << std::endl;
    }
  };

  std::vector<std::pair<int const, int const>> prs {
    { 1, 2 }, { 2, 1 }, { 1, 1 }, { 2, 2 },
  };

  play(prs, is_lt, " <  ");
  std::cout << std::endl;

  play(prs, is_gt, " >  ");
  std::cout << std::endl;

  play(prs, is_le, " <= ");
  std::cout << std::endl;

  play(prs, is_ge, " >= ");
  std::cout << std::endl;

  play(prs, is_eq, " == ");
  std::cout << std::endl;

  play(prs, is_nq, " != ");
  std::cout << std::endl;

  return 0;
}
