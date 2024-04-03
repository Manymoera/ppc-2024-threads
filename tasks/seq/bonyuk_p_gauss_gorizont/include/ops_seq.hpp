// Copyright 2024 Bonyuk Peter
#pragma once

#include <cmath>
#include <string>
#include <vector>

#include "core/task/include/task.hpp"

std::vector<int> getImage(int n, int m, uint8_t min, uint8_t max);

class LinearGaussianFiltering : public ppc::core::Task {
 public:
  explicit LinearGaussianFiltering(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processingc() override;
  bool examination() override;
  bool run() override;
  bool post_processing() override;
  int getPixel(int x, int y) { return input[x * width + y]; }
  void setPixel(int x, int y, int value) { res[x * width + y] = value; }

 private:
  std::vector<int> input = {};
  std::vector<int> res = {};
  int height{}, width{};
  int min{}, max{};
};