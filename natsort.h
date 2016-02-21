#include <ctype.h>
#include <string>
#include <algorithm>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 16

namespace natsort
{
	static bool cstrcmp(const char* a, const char* b)
	{
		int ai, bi, shifta, shiftb, conva, convb;
		ai = bi = shifta = shiftb = 0;

		while (a[ai] && b[bi]){
			if (!isdigit(a[ai]) && !isdigit(b[bi])){
				// case: comparosn of two characters
				if (a[ai] != b[bi])
					return (a[ai] < b[bi]);
				
 				++ai;
				++bi;
			}
			else{
				// case: comparison of number with character: numbers before characters
				if (isdigit(a[ai]) != isdigit(b[bi]))
					return (isdigit(a[ai]));

				char buffera[MAX_BUFFER_SIZE];
				char bufferb[MAX_BUFFER_SIZE];
				for (unsigned int i = 0; i < MAX_BUFFER_SIZE; ++i){ buffera[i] = bufferb[i] = 0; }

				shifta = ai;
				while (a[shifta] && isdigit(a[shifta])){
					buffera[shifta - ai] = a[shifta];
					++shifta;
				}

				shiftb = bi;
				while (b[shiftb] && isdigit(b[shiftb])){
					bufferb[shiftb - bi] = b[shiftb];
					++shiftb;
				}

				conva = atoi(buffera);
				convb = atoi(bufferb);

				if (conva != convb)
					return (conva < convb);

				// set new index, respect bounds
				ai += shifta? (shifta + 1) : shifta;
				bi += shiftb? (shiftb + 1) : shiftb;
			}
		}
		return !a[ai];
	}

	static bool stringcmp(const std::string& a, const std::string& b){
		return cstrcmp(a.c_str(), b.c_str());
	}
}
