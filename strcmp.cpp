#include <cstddef>
#include <iostream>
#include <utility>

int main(int argc, const char** argv) {
  std::size_t char_idx {0};
  char ch {'x'};

  while (ch) {
    std::size_t arg_idx {1};
    ch = argv[arg_idx][char_idx];

    while (std::cmp_less(++arg_idx, argc)) {
      if (argv[arg_idx][char_idx] != ch) {
        std::string suffix {"th"};
        if ((arg_idx <= 3 || arg_idx >= 20) && arg_idx % 10 < 3 && arg_idx % 10) {
          switch (arg_idx % 10) {
            case 1: suffix = "st"; break;
            case 2: suffix = "nd"; break;
            case 3: suffix = "rd"; break;
            default: std::unreachable();
          }
        }

        std::cout << "Mismatch found at position " << char_idx << "! (\x1b[31m" << ch
                  << "\x1b[0m"
                  << " vs. \x1b[31m" << argv[arg_idx][char_idx] << "\x1b[0m from "
                  << arg_idx << suffix << " arg" << ")\n";
        return 0;
      }
    }

    ++char_idx;
  }

  std::cout << "No mismatch found!" << '\n';

  return 0;
}
