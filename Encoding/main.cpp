#include "Huffman.cpp"
#include <unordered_map>
#include <iostream>

int main()
{
  Huffman compressor;
  std::unordered_map<char, int> frequencyTable;

  frequencyTable['Z'] = 2;
  frequencyTable['K'] = 7;
  frequencyTable['M'] = 24;
  frequencyTable['C'] = 32;
  frequencyTable['U'] = 37;
  frequencyTable['D'] = 42;
  frequencyTable['L'] = 42;
  frequencyTable['E'] = 120;

  auto codes = compressor.Encode(frequencyTable);

  for (auto &x : codes)
    std::cout << x.first << ": " << x.second << '\n';
}