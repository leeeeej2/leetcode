/*
*uijin.lee
*https://leetcode.com/problems/largest-time-for-given-digits/
*/

class Solution {
public:
	string largestTimeFromDigits(vector<int>& arr) {

		std::string result;
		result.clear();

		std::vector<int> getArr = arr;
		std::sort(getArr.begin(), getArr.end());

		int hour = 0;
		int min = 0;
		int maxT = -1;

		do
		{
			hour = getArr.at(0) * 10 + getArr.at(1);
			min = getArr.at(2) * 10 + getArr.at(3);

			if (0 <= hour && hour <= 23 &&
				0 <= min && min <= 59)
			{
				int newT = hour * 60 + min;

				if (newT >= maxT)
				{
					result.clear();
					maxT = newT;
					result += ((hour / 10) + 48);
					result += ((hour % 10) + 48);
					result += ':';
					result += ((min / 10) + 48);
					result += ((min % 10) + 48);
				}
			}
		} while (std::next_permutation(getArr.begin(), getArr.end()));

		return result;
	}
};