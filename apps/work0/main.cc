#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <opencv2/opencv.hpp>

const double a = 1, b = 100, c = 0.5;
using PDD = std::pair<double, double>;

double rosenbrock(const PDD& X) {
  auto [x, y] = X;
  return std::pow(a - x, 2) + b * std::pow(y - x * x, 2);
}

PDD gradient(const PDD& X) {
  auto [x, y] = X;
  return {2 * (x - a) + 4 * b * (x * x - y) * x, 2 * b * (y - x * x)};
}

PDD operator+(const PDD& a, const PDD& b) {
  return {a.first + b.first, a.second + b.second};
}

PDD operator*(const PDD& a, const double x) {
  return {a.first * x, a.second * x};
}

double operator*(const PDD& a, const PDD& b) {
  return a.first * b.first + a.second * b.second;
}

bool operator<(const PDD& a, const PDD& b) {
  return a.first < b.first && a.second < b.second;
}

void print(const std::string& name, const PDD& x) {
  std::cout << name + ": [" << x.first << ", " << x.second << "]" << std::endl;
}

bool is_armijo_valid(const PDD& x, const PDD& d, const double tau) {
  return rosenbrock(x) - rosenbrock(x + (d * tau)) >=
         -1 * tau * c * (d * gradient(x));
}

int main() {
  auto img = cv::Mat(2000, 2000, CV_8UC3, cv::Scalar(255, 255, 255, 1));
  for (double x = 0; x < 2; x += 0.01) {
    for (double y = 0; y < 2; y += 0.01) {
      cv::circle(img, {int(x * 1000), int(y * 1000)}, 8,
                 cv::Scalar(255, rosenbrock({x, y}) * 2.5, 255, 0.5),
                 cv::FILLED, cv::LINE_8);
    }
  }

  const double threshold = 1e-4;
  PDD X{0, 0}, g = gradient(X), prev = X;
  int cnt{0};
  std::vector<double> xs{}, ys{}, zs{};
  while ((g * g) > threshold && cnt++ < 10000) {
    g = gradient(X);
    double tau = 1;
    auto x_new = X;
    while (rosenbrock(x_new) > rosenbrock(X) - tau * c * (g * g)) {
      tau /= 2;
      x_new = X + (g * -tau);
    }
    X = x_new;

    cv::line(img, {int(prev.first * 1000), int(prev.second * 1000)},
                  {int(X.first * 1000), X.second * 1000},
                  cv::Scalar(0, 255, 0, 0.8), 3);
    cv::circle(img, {int(X.first * 1000), X.second * 1000}, 5,
                    cv::Scalar(0, 0, 0), cv::FILLED, cv::LINE_8);
    prev = X;
    xs.push_back(X.first);
    ys.push_back(X.second);
    zs.push_back(rosenbrock(X));
  }

  /// output
  std::cout << "--> iterate cnt: " << cnt << std::endl;
  print("g", g);
  print("X", X);

  /// show image
  cv::namedWindow("g", cv::WINDOW_AUTOSIZE );
  cv::imshow("g", img);
  cv::imwrite("docs/images/work0.png", img);
  cv::waitKey(0);

}
