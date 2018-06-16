#pragma once

#include <cmath>
#include <vector>
#include <algorithm>
#include <future>
#include <thread>
#include "core/motor.h"

namespace robust {
  class Robot {
  public:
    double Mass;
    std::vector< Motor > Motors;
    double Friction;
    Robot();
    ~Robot();
  };
}
