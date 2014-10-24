#include "utility/utilityString.h"

#include <cctype>
#include <string>

namespace utility
{
	std::deque<std::string> split(const std::string& str, char delimiter)
	{
		return split<std::deque<std::string>>(str, std::string(1, delimiter));
	}

	std::deque<std::string> split(const std::string& str, const std::string& delimiter)
	{
		return split<std::deque<std::string>>(str, delimiter);
	}

	std::vector<std::string> splitToVector(const std::string& str, char delimiter)
	{
		return split<std::vector<std::string>>(str, std::string(1, delimiter));
	}

	std::vector<std::string> splitToVector(const std::string& str, const std::string& delimiter)
	{
		return split<std::vector<std::string>>(str, delimiter);
	}

	std::string join(const std::deque<std::string>& list, char delimiter)
	{
		return join<std::deque<std::string> >(list, std::string(1, delimiter));
	}

	std::string join(const std::deque<std::string>& list, const std::string& delimiter)
	{
		return join<std::deque<std::string> >(list, delimiter);
	}

	std::string join(const std::vector<std::string>& list, char delimiter)
	{
		return join<std::vector<std::string> >(list, std::string(1, delimiter));
	}

	std::string join(const std::vector<std::string>& list, const std::string& delimiter)
	{
		return join<std::vector<std::string> >(list, delimiter);
	}

	std::deque<std::string> tokenize(const std::string& str, char delimiter)
	{
		return tokenize(str, std::string(1, delimiter));
	}

	std::deque<std::string> tokenize(const std::string& str, const std::string& delimiter)
	{
		size_t pos = 0;
		size_t oldPos = 0;
		std::deque<std::string> c;

		do
		{
			pos = str.find(delimiter, oldPos);

			if (pos != oldPos)
			{
				c.push_back(str.substr(oldPos, pos - oldPos));
			}

			if (pos != std::string::npos)
			{
				c.push_back(str.substr(pos, delimiter.size()));
			}

			oldPos = pos + delimiter.size();
		}
		while (pos != std::string::npos && oldPos < str.size());

		return c;
	}

	std::deque<std::string> tokenize(const std::deque<std::string>& list, char delimiter)
	{
		return tokenize(list, std::string(1, delimiter));
	}

	std::deque<std::string> tokenize(const std::deque<std::string>& list, const std::string& delimiter)
	{
		std::deque<std::string> c;

		for (std::string str : list)
		{
			if (str.size())
			{
				std::deque<std::string> c2 = tokenize(str, delimiter);
				c.insert(c.end(), c2.begin(), c2.end());
			}
		}

		return c;
	}

	std::string substrAfter(const std::string& str, char delimiter)
	{
		size_t pos = str.find(delimiter);
		if (pos != std::string::npos)
		{
			return str.substr(pos + 1, str.size());
		}
		return str;
	}

	bool isPrefix(const std::string& prefix, const std::string& text)
	{
		typedef std::pair<std::string::const_iterator, std::string::const_iterator> ResType;
		ResType res = std::mismatch(prefix.begin(), prefix.end(), text.begin());

		return res.first == prefix.end();
	}

	bool equalsCaseInsensitive(const std::string& a, const std::string& b)
	{
		if (a.size() == b.size())
		{
			for (int i = 0; i < a.size(); i++)
			{
				if (tolower(a[i]) != tolower(b[i]))
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
}
