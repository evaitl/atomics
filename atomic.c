#include <stdio.h>
#include <stdatomic.h>
#include <stdbool.h>
atomic_int g;

int  load_aquire(){
    return atomic_load_explicit(&g, memory_order_acquire);
}

void store_release(int val) {
    atomic_store_explicit(&g,val,memory_order_release);
}

int load_sc() {
    return atomic_load_explicit(&g,memory_order_seq_cst);
}

void store_sc(int val) {
    atomic_store_explicit(&g,val,memory_order_seq_cst);
}

int ae_sc(int val) {
    return atomic_exchange_explicit(&g, 45, memory_order_seq_cst);
}

int ae_ar(int val) {
    return atomic_exchange_explicit(&g, 45, memory_order_acq_rel);
}
// atomic_compare_exchange_strong, 
bool aces_sc(int *expected, int desired) {
    return atomic_compare_exchange_strong_explicit(&g, expected, desired, memory_order_seq_cst, memory_order_relaxed);
}
bool aces_ar(int *expected, int desired) {
    return atomic_compare_exchange_strong_explicit(&g, expected, desired, memory_order_acq_rel, memory_order_relaxed);
}

bool acew_sc(int *expected, int desired) {
    return atomic_compare_exchange_weak_explicit(&g, expected, desired, memory_order_seq_cst, memory_order_relaxed);
}
bool acew_ar(int *expected, int desired) {
    return atomic_compare_exchange_weak_explicit(&g, expected, desired, memory_order_acq_rel, memory_order_relaxed);
}


