#include <vector>
#include <iostream>
#include <string>
#include <map>

#include "Algoritmos.hpp"

template <class T> void read_input(std::vector<T>& vec) {
  T val;
  while (std::cin >> val) {
    vec.push_back(val);
  }
}

template <class T> void print_input(std::vector<T>& vec) {
  // TODO
  int size = vec.size();
  int i = 0;
  for (T elem: vec){
    i++;
    std::cout << elem;
    if(i == size)
      std::cout << std::endl;
    else
      std::cout << ", ";
  }
}

template <class T> T get_max(std::vector<T>& vec) {
  if (vec.empty()) {
    std::cout << "Erro: vetor vazio.\n";
  }
  int size = vec.size();
  for (int i = 0; i < vec.size()-1; i++)
  {
    for (int j = 0; j < vec.size()-1; j++)
    {
      if(vec[i] > vec[j]){
        T temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }
  return vec[0];
}

template <class T> unsigned int count_duplicates(std::vector<T>& vec) {
  
  std::map<T, int> m;
  for (T elem: vec){
    if(m[elem])
      m[elem]++;
    else 
      m[elem] = 1; 
  }

  int sum = 0;
  for (auto it = m.begin(); it != m.end(); it++){
    sum += it->second - 1;
  }

  return sum;
}

template <class T> void test_print_input() {
  std::vector<T> vec;
  read_input(vec);
  print_input(vec);
}

template <class T> void test_get_max() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << get_max(vec) << std::endl;
}

template <class T> void test_count_dups() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << count_duplicates(vec) << std::endl;
}

int main() {
  int tipo_teste;
  std::cin >> tipo_teste;
  switch (tipo_teste) {
    case 0:
      test_print_input<std::string>();
      break;
    case 1:
      test_print_input<int>();
      break;
    case 2:
      test_get_max<double>();
      break;
    case 3:
      test_get_max<char>();
      break;
    case 4:
      test_count_dups<int>();
      break;
    case 5:
      test_count_dups<std::string>();
      break;
    default:
      std::cout << "Erro: teste invalido: " << tipo_teste << std::endl;
  }
  return 0;
}