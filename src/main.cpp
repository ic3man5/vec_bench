#include <benchmark/benchmark.h>
#include <vector>
#include <array>
#include <memory>
#include <deque>

constexpr size_t rangeMin = 1<<20;
constexpr size_t rangeMax = rangeMin;
//constexpr size_t rangeMax = 1<<20;
constexpr size_t rangeMultiplier = 2;


static void bench_vec_push_back(benchmark::State& state) {
  const size_t howMany = state.range(0);
  for (auto _ : state) {
    std::vector<int> result;
    result.reserve(howMany);
    for (size_t ii = 0; ii < howMany; ++ii) {
        result.push_back(ii * ii);
    }
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(bench_vec_push_back)->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax);

static void bench_vec_emplace_back(benchmark::State& state) {
  const size_t howMany = state.range(0);
  for (auto _ : state) {
    std::vector<int> result;
    result.reserve(howMany);
    for (size_t ii = 0; ii < howMany; ++ii) {
        result.emplace_back(ii * ii);
    }
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(bench_vec_emplace_back)->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax);

static void bench_vec_prealloc(benchmark::State& state) {
  const size_t howMany = state.range(0);
  for (auto _ : state) {
    std::vector<int> result(howMany);
    for (size_t ii = 0; ii < howMany; ++ii) {
        result[ii] = ii * ii;
    }
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(bench_vec_prealloc)->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax);

static void bench_deque_prealloc(benchmark::State& state) {
  const size_t howMany = state.range(0);
  for (auto _ : state) {
    std::deque<int> result(howMany);
    for (size_t ii = 0; ii < howMany; ++ii) {
        result[ii] = ii * ii;
    }
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(bench_deque_prealloc)->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax);

struct IntArray {
    std::unique_ptr<int []> arr;
    size_t length;
};

static void bench_array(benchmark::State& state) {
  const size_t howMany = state.range(0);
  for (auto _ : state) {
    IntArray result = {std::unique_ptr<int[]>{new int[howMany]}, howMany};
    for (size_t ii = 0; ii < howMany; ++ii) {
        result.arr[ii] = ii * ii;
    }
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(bench_array)->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax);


BENCHMARK_MAIN();
