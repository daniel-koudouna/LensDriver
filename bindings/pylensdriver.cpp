#include "pylensdriver.hpp"

PyLensDriver::PyLensDriver(std::string device_file) {
  (*this).fd = dev_open_setup(device_file.data());
  if (command(cmd_start) == -1) {
    (*this).fd = 0;
  }
}

PyLensDriver::~PyLensDriver() {
  command(clear_recv_buffer);
  command(cmd_start);
  command(clear_recv_buffer);
  command(close);
}

int PyLensDriver::command(std::function<int(int)> fn) const {
  if (this->fd != 0) {
    return fn(this->fd);
  }
  return -1;
}

int PyLensDriver::command_i(std::function<int(int, int)> fn, int i) const {
  if (this->fd != 0) {
    return fn(this->fd, i);
  }
  return -1;
};
