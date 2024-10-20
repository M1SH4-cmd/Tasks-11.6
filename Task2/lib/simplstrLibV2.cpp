#include <iostream>
#include "pch.h"
#include "framework.h"
#include "simplstrLibV2.h"

using namespace std;

namespace simplstr {
	string reversed(string str) {
		int n = str.length() - 1;
		for (int i = 0; i < (str.length() / 2); i++) {
			swap(str[i], str[n]);
			n--;
		}
		return str;
	}

	bool is_match(string str, string substr, int startPos) {
		for (int i = 0; i < substr.length(); i++) {
			if (i + startPos >= str.length() || substr[i] != str[i + startPos]) {
				return false;
			}
		}
		return true;
	}


	int find_string(string str, string substr) {
		for (int i = 0; i < str.length(); i++) {
			if (is_match(str, substr, i)) {
				return i;
			}
		}
		return -1; // Add return value for cases when substr is not found
	}


	int rfind(string str, string substr) {
		for (int i = str.length() - substr.length(); i >= 0; --i) {
			bool equal = true;
			for (int j = 0; j < substr.length(); ++j) {
				if (str[i + j] != substr[j]) {
					equal = false;
				}
			}
			if (equal) {
				return i;
			}
		}
	}
}