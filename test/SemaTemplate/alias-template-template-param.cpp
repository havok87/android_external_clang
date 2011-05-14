// RUN: %clang_cc1 -fsyntax-only -verify -std=c++0x %s

template<template<typename> class D> using C = D<int>;

// Substitution of the alias template transforms the TemplateSpecializationType
// 'D<int>' into the DependentTemplateSpecializationType 'T::template U<int>'.
template<typename T> void f(C<T::template U>);
