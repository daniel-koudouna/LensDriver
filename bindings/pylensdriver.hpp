#pragma once
#include "lensdriver.h"
#include <functional>

class PyLensDriver {
  int fd = 0;
  uint32_t mA = 200;   /* 200 mA */
  uint32_t mHz = 1000; /* 1 Hz */
  uint16_t ucurrent = 4000;  /* upper current for sinusoidal */
  uint16_t lcurrent = 0;     /* lower current for sinusoidal */
public:
  PyLensDriver(std::string device_file);
  ~PyLensDriver();
  int command(std::function<int(int)> fn) const;
  int command_i(std::function<int(int, int)> fn, int i) const;
};
