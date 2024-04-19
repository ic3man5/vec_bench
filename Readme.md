AMD Ryzen 7 5800X3D
6.8.7-zen1-1-zen (64-bit)

clang 17.0.6 -O3
```bash
2024-04-19T15:17:09-04:00
Running /home/drebbe/dev/vec_bench/build/vec_bench
Run on (16 X 4548.83 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 512 KiB (x8)
  L3 Unified 98304 KiB (x1)
Load Average: 1.11, 0.86, 0.67
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
bench_vec_push_back/1048576        493825 ns       491457 ns         1340
bench_vec_emplace_back/1048576     528721 ns       526775 ns         1000
bench_vec_prealloc/1048576         305916 ns       304818 ns         2354
bench_deque_prealloc/1048576      1008287 ns      1001360 ns          697
bench_array/1048576                248813 ns       247982 ns         2841
```

clang 17.0.6 -O2
```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
bench_vec_push_back/1048576        490637 ns       488539 ns         1436
bench_vec_emplace_back/1048576     490539 ns       489002 ns         1438
bench_vec_prealloc/1048576         287192 ns       286194 ns         2499
bench_deque_prealloc/1048576       966708 ns       963792 ns          725
bench_array/1048576                238519 ns       237630 ns         2950
```

gcc 13.2.1 -O3
```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
bench_vec_push_back/1048576        493052 ns       490948 ns         1370
bench_vec_emplace_back/1048576     486270 ns       484852 ns         1443
bench_vec_prealloc/1048576         206121 ns       205542 ns         3405
bench_deque_prealloc/1048576      1112892 ns      1109746 ns          636
bench_array/1048576                183218 ns       182640 ns         3911
```

gcc 13.2.1 -O2

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
bench_vec_push_back/1048576        497764 ns       496051 ns         1354
bench_vec_emplace_back/1048576     489577 ns       488213 ns         1427
bench_vec_prealloc/1048576         284978 ns       284069 ns         2439
bench_deque_prealloc/1048576      1101080 ns      1097951 ns          642
bench_array/1048576                472827 ns       471489 ns         1475
```
