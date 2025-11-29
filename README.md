# DSA

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    return accumulate(nums.begin(), nums.end(), 0) % k;
  }
};

class Solution {
 public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                              vector<int>& values, int k) {
    int ans = 0;
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, /*prev=*/-1, values, k, ans);
    return ans;
  }

 private:
  long dfs(const vector<vector<int>>& graph, int u, int prev,
           const vector<int>& values, int k, int& ans) {
    long treeSum = values[u];

    for (const int v : graph[u])
      if (v != prev)
        treeSum += dfs(graph, v, u, values, k, ans);

    if (treeSum % k == 0)
      ++ans;
    return treeSum;
  }
};

class Solution {
 public:
  long long maxSubarraySum(std::vector<int>& nums, int k) {
    long ans = LONG_MIN;
    long prefix = 0;
    // minPrefix[i % k] := the minimum prefix sum of the first i numbers
    vector<long> minPrefix(k, LONG_MAX / 2);
    minPrefix[k - 1] = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      ans = max(ans, prefix - minPrefix[i % k]);
      minPrefix[i % k] = min(minPrefix[i % k], prefix);
    }

    return ans;
  }
};

class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    if (k % 10 != 1 && k % 10 != 3 && k % 10 != 7 && k % 10 != 9)
      return -1;

    unordered_set<int> seen;
    int n = 0;

    for (int length = 1; length <= k; ++length) {
      n = (n * 10 + 1) % k;
      if (n == 0)
        return length;
      if (seen.contains(n))
        return -1;
      seen.insert(n);
    }

    return -1;
  }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1 << 30;  // Large negative value to represent impossible states
      
        // dp[i][j] represents the maximum sum using first i elements 
        // where the sum modulo 3 equals j
        int dp[n + 1][3];
      
        // Base case: with 0 elements, only sum 0 is possible
        dp[0][0] = 0;
        dp[0][1] = -INF;  // Impossible to get remainder 1 with no elements
        dp[0][2] = -INF;  // Impossible to get remainder 2 with no elements
      
        // Process each element
        for (int i = 1; i <= n; ++i) {
            int currentNum = nums[i - 1];
          
            // For each possible remainder when divided by 3
            for (int remainder = 0; remainder < 3; ++remainder) {
                // Option 1: Don't include current number
                int excludeCurrent = dp[i - 1][remainder];
              
                // Option 2: Include current number
                // We need previous sum with remainder that, when added to currentNum,
                // gives us the target remainder
                int prevRemainder = (remainder - currentNum % 3 + 3) % 3;
                int includeCurrent = dp[i - 1][prevRemainder] + currentNum;
              
                // Take maximum of both options
                dp[i][remainder] = max(excludeCurrent, includeCurrent);
            }
        }
      
        // Return maximum sum divisible by 3 (remainder = 0)
        return dp[n][0];
    }
};

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    return ranges::count_if(nums, [](int num) { return num % 3 != 0; });
  }
};

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;
      
        // Iterate through each possible character that could be at both ends of palindrome
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            // Find the first and last occurrence of current character
            int firstIndex = s.find_first_of(ch);
            int lastIndex = s.find_last_of(ch);
          
            // Skip if character doesn't exist or appears only once
            if (firstIndex == string::npos || firstIndex == lastIndex) {
                continue;
            }
          
            // Use bitmask to track unique characters between first and last occurrence
            int characterMask = 0;
          
            // Check all characters between first and last occurrence
            for (int i = firstIndex + 1; i < lastIndex; ++i) {
                // Convert character to 0-based index (a=0, b=1, ..., z=25)
                int charIndex = s[i] - 'a';
              
                // Check if this character hasn't been seen yet using bit manipulation
                // (mask >> charIndex) & 1 gets the bit at position charIndex
                // ^ 1 inverts it (0 becomes 1, 1 becomes 0)
                // So the condition is true when bit is 0 (character not seen)
                if (((characterMask >> charIndex) & 1) == 0) {
                    // Mark this character as seen by setting its bit to 1
                    characterMask |= (1 << charIndex);
                    // Each unique character forms a valid palindrome with ch at both ends
                    ++result;
                }
            }
        }
      
        return result;
    }
};

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals by ending point (ascending), 
        // if ending points are same, sort by starting point (descending)
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
      
        int result = 0;
        // Track the last two points in our intersection set
        // Initialize to invalid values
        int secondLastPoint = -1;
        int lastPoint = -1;
      
        // Process each interval
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
          
            // Case 1: Both tracked points are already in current interval
            // No new points needed
            if (start <= secondLastPoint) {
                continue;
            }
          
            // Case 2: No tracked points are in current interval
            // Need to add 2 new points (choose the rightmost two)
            if (start > lastPoint) {
                result += 2;
                secondLastPoint = end - 1;
                lastPoint = end;
            } 
            // Case 3: Only the last tracked point is in current interval
            // Need to add 1 new point (choose the rightmost)
            else {
                result += 1;
                secondLastPoint = lastPoint;
                lastPoint = end;
            }
        }
      
        return result;
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // Initialize pointer and get array size
        int i = 0;
        int n = bits.size();
      
        // Traverse through the bits array until we reach or pass the second-to-last position
        // If current bit is 0: it's a 1-bit character, move forward by 1 (0 + 1)
        // If current bit is 1: it's a 2-bit character, move forward by 2 (1 + 1)
        while (i < n - 1) {
            i += bits[i] + 1;
        }
      
        // If we landed exactly on the last position (n-1), 
        // it means the last character is a 1-bit character
        return i == n - 1;
    }
};

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // Initialize the index of the previous '1' to a value that ensures
        // the first '1' encountered will always satisfy the distance requirement
        // Setting it to -(k + 1) means the first '1' at index i will have 
        // distance i - (-(k + 1)) - 1 = i + k, which is always >= k for i >= 0
        int prevOneIndex = -(k + 1);
      
        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); ++i) {
            // Check if current element is 1
            if (nums[i] == 1) {
                // Calculate the distance between current '1' and previous '1'
                // The actual distance is (i - prevOneIndex - 1) which represents
                // the number of elements between the two 1's (excluding the 1's themselves)
                if (i - prevOneIndex - 1 < k) {
                    // If distance is less than k, the condition is violated
                    return false;
                }
                // Update the index of the most recent '1'
                prevOneIndex = i;
            }
        }
      
        // All pairs of 1's satisfy the distance requirement
        return true;
    }
};

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int ans = 0;

    // Iterate through all possible number of 0s.
    for (int zero =o + zero * zero <= s.length(); ++zero) {
      int lastInvalidPos = -1;
      vector<int> count(2);
      for (int l = 0, r = 0; r < s.length(); ++r) {
        ++count[s[r] - '0'];
        // Try to shrink the window to maintain the "minimum" length of the
        // valid substring.
        for (; l < r; ++l)
          if (s[l] == '0' && count[0] > zero) {
            --count[0];  // Remove an extra '0'.
            lastInvalidPos = l;
          } else if (s[l] == '1' && count[1] - 1 >= zero * zero) {
            --count[1];  // Remove an extra '1'.
          } else {
            break;  // Cannot remove more characters.
          }
        if (count[0] == zero && count[1] >= zero * zero)
          // Add valid substrings ending in s[r] to the answer. They are
          // s[lastInvalidPos + 1..r], s[lastInvalidPos + 2..r], ..., s[l..r].
          ans += l - lastInvalidPos;
      }
    }

    return ans;
  }
};

class Solution {
 public:
  int maxOperations(string s) {
    int ans = 0;
    int ones = 0;

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '1')
        ++ones;
      else if (i + 1 == s.length() || s[i + 1] == '1')
        ans += ones;

    return ans;
  }
};

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();
    const int ones = ranges::count(nums, 1);
    if (ones > 0)
      return n - ones;

    // the minimum operations to make the shortest subarray with a gcd == 1
    int minOps = INT_MAX;

    for (int i = 0; i < n; ++i) {
      int g = nums[i];
      for (int j = i + 1; j < n; ++j) {
        g = __gcd(g, nums[j]);
        if (g == 1) {  // gcd(nums[i..j]) == 1
          minOps = min(minOps, j - i);
          break;
        }
      }
    }

    // After making the shortest subarray with `minOps`, need additional n - 1
    // operations to make the other numbers to 1.
    return minOps == INT_MAX ? -1 : minOps + n - 1;
  }
};
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    // dp[i][j] := the maximum size of the subset given i 0s and j 1s are
    // available
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (const string& s : strs) {
      const int zeros = ranges::count(s, '0');
      const int ones = s.length() - zeros;
      for (int i = m; i >= zeros; --i)
        for (int j = n; j >= ones; --j)
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
    }

    return dp[m][n];
  }
};

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    stack<int> stack;
    stack.push(0);

    for (const int num : nums) {
      while (!stack.empty() && stack.top() > num)
        stack.pop();
      if (stack.empty() || stack.top() < num) {
        ++ans;
        stack.push(num);
      }
    }

    return ans;
  }
};

class Solution {
 public:
  int countOperations(int num1, int num2) {
    int ans = 0;

    while (num1 && num2) {
      if (num1 < num2)
        swap(num1, num2);
      ans += num1 / num2;
      num1 %= num2;
    }

    return ans;
  }
};

class Solution {
 public:
  int minimumOneBitOperations(int n) {
    // Observation: e.g. n = 2^2
    //        100 (2^2 needs 2^3 - 1 ops)
    // op1 -> 101
    // op2 -> 111
    // op1 -> 110
    // op2 -> 010 (2^1 needs 2^2 - 1 ops)
    // op1 -> 011
    // op2 -> 001 (2^0 needs 2^1 - 1 ops)
    // op1 -> 000
    //
    // So 2^k needs 2^(k + 1) - 1 ops. Note this is reversible, i.e., 0 -> 2^k
    // also takes 2^(k + 1) - 1 ops.

    // e.g. n = 1XXX, our first goal is to change 1XXX -> 1100.
    //   - If the second bit is 1, you only need to consider the cost of turning
    //     the last 2 bits to 0.
    //   - If the second bit is 0, you need to add up the cost of flipping the
    //     second bit from 0 to 1.
    // XOR determines the cost minimumOneBitOperations(1XXX^1100) accordingly.
    // Then, 1100 -> 0100 needs 1 op. Finally, 0100 -> 0 needs 2^3 - 1 ops.
    if (n == 0)
      return 0;
    // x is the largest 2^k <= n.
    // x | x >> 1 -> x >> 1 needs 1 op.
    //     x >> 1 -> 0      needs x = 2^k - 1 ops.
    int x = 1;
    while (x * 2 <= n)
      x <<= 1;
    return minimumOneBitOperations(n ^ (x | x >> 1)) + 1 + x - 1;
  }
};

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
      
        // Step 1: Calculate initial power coverage using difference array technique
        // diff[i] represents the change in power at position i
        long diff[n + 1];
        memset(diff, 0, sizeof diff);
      
        // For each station, add its contribution to all cities in its range
        for (int i = 0; i < n; ++i) {
            int leftBound = max(0, i - r);
            int rightBound = min(i + r, n - 1);
            diff[leftBound] += stations[i];
            diff[rightBound + 1] -= stations[i];
        }
      
        // Step 2: Build prefix sum array to get actual power at each city
        long prefixPower[n + 1];
        prefixPower[0] = diff[0];
        for (int i = 1; i < n + 1; ++i) {
            prefixPower[i] = prefixPower[i - 1] + diff[i];
        }
      
        // Step 3: Binary search helper - check if minimum power targetPower is achievable
        auto canAchieveMinPower = [&](long targetPower, int availableStations) {
            // Use difference array to track additional stations placed
            long additionalDiff[n + 1];
            memset(additionalDiff, 0, sizeof additionalDiff);
            long additionalPower = 0;
          
            // Check each city from left to right
            for (int i = 0; i < n; ++i) {
                // Update additional power from previously placed stations
                additionalPower += additionalDiff[i];
              
                // Calculate power deficit at current city
                long currentPower = prefixPower[i] + additionalPower;
                long deficit = targetPower - currentPower;
              
                if (deficit > 0) {
                    // Need to place stations to cover deficit
                    if (availableStations < deficit) {
                        return false;  // Not enough stations available
                    }
                  
                    // Place stations at the rightmost position that can cover city i
                    // This greedy placement maximizes coverage for future cities
                    availableStations -= deficit;
                    int placementPos = min(i + r, n - 1);
                    int coverageLeft = max(0, placementPos - r);
                    int coverageRight = min(placementPos + r, n - 1);
                  
                    // Update difference array for the new stations' coverage
                    additionalDiff[coverageLeft] += deficit;
                    additionalDiff[coverageRight + 1] -= deficit;
                    additionalPower += deficit;
                }
            }
            return true;
        };
      
        // Step 4: Binary search for maximum achievable minimum power
        long left = 0;
        long right = 1e12;  // Upper bound for power value
      
        while (left < right) {
            long mid = (left + right + 1) >> 1;  // Ceiling division to avoid infinite loop
          
            if (canAchieveMinPower(mid, k)) {
                left = mid;  // Can achieve mid, try for higher
            } else {
                right = mid - 1;  // Cannot achieve mid, try lower
            }
        }
      
        return left;
    }
};

class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c + 1);
        for (auto& e : connections) {
            uf.unite(e[0], e[1]);
        }

        vector<set<int>> st(c + 1);
        for (int i = 1; i <= c; i++) {
            st[uf.find(i)].insert(i);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int a = q[0], x = q[1];
            int root = uf.find(x);
            if (a == 1) {
                if (st[root].count(x)) {
                    ans.push_back(x);
                } else if (!st[root].empty()) {
                    ans.push_back(*st[root].begin());
                } else {
                    ans.push_back(-1);
                }
            } else {
                st[root].erase(x);
            }
        }
        return ans;
    }
};

class Solution {
 public:
  // Same as 3318. Find X-Sum of All K-Long Subarrays I
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    vector<long long> ans;
    long windowSum = 0;
    unordered_map<int, int> count;
    multiset<pair<int, int>> top;  // the top x elements
    multiset<pair<int, int>> bot;  // the rest of the elements

    // Updates the count of num by freq and the window sum accordingly.
    auto update = [&count, &top, &bot, &windowSum](int num, int freq) -> void {
      if (count[num] > 0) {  // Clean up the old count.
        if (auto it = bot.find({count[num], num}); it != bot.end()) {
          bot.erase(it);
        } else {
          it = top.find({count[num], num});
          top.erase(it);
          windowSum -= static_cast<long>(num) * count[num];
        }
      }
      count[num] += freq;
      if (count[num] > 0)
        bot.insert({count[num], num});
    };

    for (int i = 0; i < nums.size(); ++i) {
      update(nums[i], 1);
      if (i >= k)
        update(nums[i - k], -1);
      // Move the bottom elements to the top if needed.
      while (!bot.empty() && top.size() < x) {
        const auto [countB, b] = *bot.rbegin();
        bot.erase(--bot.end());
        top.insert({countB, b});
        windowSum += static_cast<long>(b) * countB;
      }
      // Swap the bottom and top elements if needed.
      while (!bot.empty() && *bot.rbegin() > *top.begin()) {
        const auto [countB, b] = *bot.rbegin();
        const auto [countT, t] = *top.begin();
        bot.erase(--bot.end());
        top.erase(top.begin());
        bot.insert({countT, t});
        top.insert({countB, b});
        windowSum += static_cast<long>(b) * countB;
        windowSum -= static_cast<long>(t) * countT;
      }
      if (i >= k - 1)
        ans.push_back(windowSum);
    }

    return ans;
  }
};





class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int n = colors.size();
      
        // Process groups of consecutive balloons with the same color
        for (int groupStart = 0, groupEnd = 0; groupStart < n; groupStart = groupEnd) {
            groupEnd = groupStart;
            int groupSum = 0;      // Sum of removal times for current group
            int maxTime = 0;       // Maximum removal time in current group
          
            // Find all consecutive balloons with the same color
            while (groupEnd < n && colors[groupEnd] == colors[groupStart]) {
                groupSum += neededTime[groupEnd];
                maxTime = max(maxTime, neededTime[groupEnd]);
                ++groupEnd;
            }
          
            // If group has more than 1 balloon, remove all except the one with max time
            // Cost = sum of all times - maximum time (keep the most expensive one)
            if (groupEnd - groupStart > 1) {
                totalCost += groupSum - maxTime;
            }
        }
      
        return totalCost;
    }
};

class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    int ans = 0;
    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<char>> left(m, vector<char>(n));
    vector<vector<char>> right(m, vector<char>(n));
    vector<vector<char>> up(m, vector<char>(n));
    vector<vector<char>> down(m, vector<char>(n));

    for (const vector<int>& guard : guards)
      grid[guard[0]][guard[1]] = 'G';

    for (const vector<int>& wall : walls)
      grid[wall[0]][wall[1]] = 'W';

    for (int i = 0; i < m; ++i) {
      char lastCell = 0;
      for (int j = 0; j < n; ++j)
        recordOrFill(grid[i][j], lastCell, left[i][j]);
      lastCell = 0;
      for (int j = n - 1; j >= 0; --j)
        recordOrFill(grid[i][j], lastCell, right[i][j]);
    }

    for (int j = 0; j < n; ++j) {
      char lastCell = 0;
      for (int i = 0; i < m; ++i)
        recordOrFill(grid[i][j], lastCell, up[i][j]);
      lastCell = 0;
      for (int i = m - 1; i >= 0; --i)
        recordOrFill(grid[i][j], lastCell, down[i][j]);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0 && left[i][j] != 'G' && right[i][j] != 'G' &&
            up[i][j] != 'G' && down[i][j] != 'G')
          ++ans;

    return ans;
  }

 private:
  void recordOrFill(char currCell, char& lastCell, char& infoCell) {
    if (currCell == 'G' || currCell == 'W')
      lastCell = currCell;
    else
      infoCell = lastCell;
  }
};

class Solution {
 public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    ListNode dummy(0, head);
    unordered_set<int> numsSet{nums.begin(), nums.end()};

    for (ListNode* curr = &dummy; curr->next != nullptr;)
      if (numsSet.contains(curr->next->val))
        curr->next = curr->next->next;
      else
        curr = curr->next;

    return dummy.next;
  }
};

class Solution {
 public:
  int minNumberOperations(vector<int>& target) {
    int ans = target.front();

    for (int i = 1; i < target.size(); ++i)
      if (target[i] > target[i - 1])
        ans += target[i] - target[i - 1];

    return ans;
  }
};

class Solution {
 public:
  int smallestNumber(int n) {
    return (1 << bitLength(n)) - 1;
  }

 private:
  int bitLength(int n) {
    return 32 - __builtin_clz(n);
  }
};

class Solution {
 public:
  int countValidSelections(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    vector<int> prefix(n);  // sum(nums[0..i - 1])
    vector<int> suffix(n);  // sum(nums[i + 1..n - 1])

    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] + nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] + nums[i + 1];

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        continue;
      if (prefix[i] == suffix[i])
        ans += 2;  // Go to either direction.
      if (abs(prefix[i] - suffix[i]) == 1)
        ans += 1;  // Go to the direction with the larger sum.
    }

    return ans;
  }
};

class Bank {
 public:
  Bank(vector<long long>& balance) : balance(std::move(balance)) {}

  bool transfer(int account1, int account2, long long money) {
    if (!isValid(account2))
      return false;
    return withdraw(account1, money) && deposit(account2, money);
  }

  bool deposit(int account, long long money) {
    if (!isValid(account))
      return false;
    balance[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (!isValid(account))
      return false;
    if (balance[account - 1] < money)
      return false;
    balance[account - 1] -= money;
    return true;
  }

 private:
  vector<long long> balance;

  bool isValid(int account) {
    return 1 <= account && account <= balance.size();
  }
};

class Solution {
 public:
  int totalMoney(int n) {
    const int weeks = n / 7;
    const int firstWeek = trapezoid(1, 7);
    const int lastFullWeek = trapezoid(1 + weeks - 1, 7 + weeks - 1);
    const int remainingDays = trapezoid(1 + weeks, n % 7 + weeks);
    return (firstWeek + lastFullWeek) * weeks / 2 + remainingDays;
  }

  // Returns sum(a..b).
  int trapezoid(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
  }
};

class Solution {
 public:
  int nextBeautifulNumber(int n) {
    while (!isBalance(++n))
      ;
    return n;
  }

 private:
  bool isBalance(int num) {
    vector<int> count(10);
    while (num > 0) {
      if (num % 10 == 0)
        return false;
      ++count[num % 10];
      num /= 10;
    }
    for (int i = 1; i < 10; ++i)
      if (count[i] && count[i] != i)
        return false;
    return true;
  }
};

class Solution {
 public:
  bool hasSameDigits(const string& s) {
    const int n = s.length();
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i + 1 < n; ++i) {
      const int coefficient = nCkMod10(n - 2, i);
      num1 += (coefficient * (s[i] - '0')) % 10;
      num1 %= 10;
      num2 += (coefficient * (s[i + 1] - '0')) % 10;
      num2 %= 10;
    }

    return num1 == num2;
  }

 private:
  // Returns (n, k) % 10.
  int nCkMod10(int n, int k) {
    const int mod2 = lucasTheorem(n, k, 2);
    const int mod5 = lucasTheorem(n, k, 5);
    static constexpr int lookup[2][5] = {
        {0, 6, 2, 8, 4},  // mod2 == 0
        {5, 1, 7, 3, 9}   // mod2 == 1
    };
    return lookup[mod2][mod5];
  }

  // Returns (n, k) % prime.
  int lucasTheorem(int n, int k, int prime) {
    int res = 1;
    while (n > 0 || k > 0) {
      const int nMod = n % prime;
      const int kMod = k % prime;
      res *= nCk(nMod, kMod);
      res %= prime;
      n /= prime;
      k /= prime;
    }
    return res;
  }

  // Returns (n, k).
  int nCk(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; ++i) {
      res *= (n - i);
      res /= (i + 1);
    }
    return res;
  }
};
class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;

    for (const string& op : operations)
      ans += op[1] == '+' ? 1 : -1;

    return ans;
  }
};

class Solution {
 public:
  string findLexSmallestString(string s, int a, int b) {
    string ans = s;

    dfs(s, a, b, {}, ans);

    return ans;
  }

 private:
  void dfs(string s, int a, int b, unordered_set<string>&& seen, string& ans) {
    if (seen.contains(s))
      return;

    seen.insert(s);
    ans = min(ans, s);

    dfs(add(s, a), a, b, std::move(seen), ans);
    dfs(rotate(s, b), a, b, std::move(seen), ans);
  }

  string add(string& s, int a) {
    for (int i = 1; i < s.length(); i += 2)
      s[i] = '0' + (s[i] - '0' + a) % 10;
    return s;
  }

  string rotate(const string& s, int b) {
    const int n = s.length();
    return s.substr(n - b, n) + s.substr(0, n - b);
  }
};

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Sort the array to process elements in ascending order
        ranges::sort(nums);
      
        // Initialize result counter and previous selected value
        int distinctCount = 0;
        int previousValue = INT_MIN;
      
        // Process each element in sorted order
        for (int currentNum : nums) {
            // Calculate the valid range for current element: [currentNum - k, currentNum + k]
            // We want to pick the smallest valid value that is greater than previousValue
          
            // Lower bound of valid range
            int lowerBound = currentNum - k;
          
            // The minimum valid value we can pick (must be > previousValue)
            int minValidValue = max(lowerBound, previousValue + 1);
          
            // Upper bound of valid range
            int upperBound = currentNum + k;
          
            // The actual value we pick (constrained by upper bound)
            int selectedValue = min(upperBound, minValidValue);
          
            // Check if we can select a valid distinct value
            if (selectedValue > previousValue) {
                // We found a valid distinct value
                distinctCount++;
                previousValue = selectedValue;
            }
        }
      
        return distinctCount;
    }
};

class Solution {
 public:
  int maxPartitionsAfterOperations(string s, int k) {
    unordered_map<long, int> mem;
    return maxPartitionsAfterOperations(s, 0, true, 0, k, mem) + 1;
  }

 private:
  // Returns the maximum number of partitions of s[i..n), where `canChange` is
  // true if we can still change a letter, and `mask` is the bitmask of the
  // letters we've seen.
  int maxPartitionsAfterOperations(const string& s, int i, bool canChange,
                                   int mask, int k,
                                   unordered_map<long, int>& mem) {
    if (i == s.length())
      return 0;

    long key = static_cast<long>(i) << 27 | (canChange ? 1 : 0) << 26 | mask;
    if (const auto it = mem.find(key); it != mem.end())
      return it->second;

    // Initialize the result based on the current letter.
    int res = getRes(s, i, canChange, mask, 1 << (s[i] - 'a'), k, mem);

    // If allowed, explore the option to change the current letter.
    if (canChange)
      for (int j = 0; j < 26; ++j)
        res = max(res, getRes(s, i, false, mask, 1 << j, k, mem));

    return mem[key] = res;
  }

  int getRes(const string& s, int i, bool nextCanChange, unsigned mask,
             int newBit, int k, unordered_map<long, int>& mem) {
    const unsigned newMask = mask | newBit;
    if (popcount(newMask) > k)  // fresh start
      return 1 + maxPartitionsAfterOperations(s, i + 1, nextCanChange, newBit,
                                              k, mem);
    return maxPartitionsAfterOperations(s, i + 1, nextCanChange, newMask, k,
                                        mem);
  }
};

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // Create an array to count occurrences of each remainder class modulo 'value'
        int remainderCount[value];
        memset(remainderCount, 0, sizeof(remainderCount));
      
        // Count how many numbers fall into each remainder class
        // Use ((x % value) + value) % value to handle negative numbers correctly
        for (int num : nums) {
            int remainder = ((num % value) + value) % value;
            ++remainderCount[remainder];
        }
      
        // Find the smallest non-negative integer that cannot be formed
        // by adding multiples of 'value' to elements in nums
        for (int i = 0; ; ++i) {
            int remainderClass = i % value;
          
            // If no number in this remainder class is available, return i
            if (remainderCount[remainderClass] == 0) {
                return i;
            }
          
            // Use one number from this remainder class
            --remainderCount[remainderClass];
        }
    }
};


class Solution {
 public:
  // Similar to 3349. Adjacent Increasing Subarrays Detection I
  int maxIncreasingSubarrays(vector<int>& nums) {
    int ans = 0;
    int increasing = 1;
    int prevIncreasing = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++increasing;
      } else {
        prevIncreasing = increasing;
        increasing = 1;
      }
      ans = max(ans, increasing / 2);
      ans = max(ans, min(prevIncreasing, increasing));
    }

    return ans;
  }
};

class Solution {
 public:
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int increasing = 1;
    int prevIncreasing = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++increasing;
      } else {
        prevIncreasing = increasing;
        increasing = 1;
      }
      if (increasing / 2 >= k || min(prevIncreasing, increasing) >= k)
        return true;
    }

    return false;
  }
};

  static constexpr int kMod = 1'000'000'007;

  int dp(int m, int k, int i, unsigned carry, const vector<int>& nums,
         vector<vector<vector<vector<int>>>>& mem,
         const vector<vector<int>>& comb) {
    if (m < 0 || k < 0 || (m + popcount(carry) < k))
      return 0;
    if (m == 0)
      return k == popcount(carry) ? 1 : 0;
    if (i == nums.size())
      return 0;
    if (mem[m][k][i][carry] != -1)
      return mem[m][k][i][carry];
    int res = 0;
    for (int count = 0; count <= m; ++count) {
      const long contribution = comb[m][count] * modPow(nums[i], count) % kMod;
      const int newCarry = carry + count;
      res = (res + static_cast<long>(dp(m - count, k - (newCarry % 2), i + 1,
                                        newCarry / 2, nums, mem, comb)) *
                       contribution) %
            kMod;
    }
    return mem[m][k][i][carry] = res;
  }

  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  vector<vector<int>> getComb(int n, int k) {
    vector<vector<int>> comb(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; ++i)
      comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    return comb;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Sort powers in ascending order for easier processing
        sort(power.begin(), power.end());
      
        // Store the sorted power array and its size
        this->powers = power;
        arraySize = power.size();
      
        // Initialize memoization array and next valid index array
        memo.resize(arraySize, 0);
        nextValidIndex.resize(arraySize);
      
        // Count frequency of each power value and precompute next valid indices
        for (int i = 0; i < arraySize; ++i) {
            // Count occurrences of each power value
            powerFrequency[powers[i]]++;
          
            // Find the next index where power[j] > power[i] + 2
            // This is the next index we can consider if we take power[i]
            nextValidIndex[i] = upper_bound(powers.begin() + i + 1, 
                                           powers.end(), 
                                           powers[i] + 2) - powers.begin();
        }
      
        // Start dynamic programming from index 0
        return calculateMaxDamage(0);
    }

private:
    // Map to store frequency of each power value
    unordered_map<int, int> powerFrequency;
  
    // Memoization array for dynamic programming
    vector<long long> memo;
  
    // Array to store sorted power values
    vector<int> powers;
  
    // Array to store next valid index for each position
    vector<int> nextValidIndex;
  
    // Size of the power array
    int arraySize;

    long long calculateMaxDamage(int index) {
        // Base case: if index is out of bounds, return 0
        if (index >= arraySize) {
            return 0;
        }
      
        // Return memoized result if already calculated
        if (memo[index] != 0) {
            return memo[index];
        }
      
        // Option 1: Skip the current power value entirely
        // Move to the next distinct power value
        long long skipCurrentPower = calculateMaxDamage(index + powerFrequency[powers[index]]);
      
        // Option 2: Take all occurrences of the current power value
        // Calculate damage from current power and continue from next valid index
        long long takeCurrentPower = static_cast<long long>(powers[index]) * powerFrequency[powers[index]] 
                                    + calculateMaxDamage(nextValidIndex[index]);
      
        // Store and return the maximum of both options
        memo[index] = max(skipCurrentPower, takeCurrentPower);
        return memo[index];
    }
};

class Solution {
 public:
  long long minTime(vector<int>& skill, vector<int>& mana) {
    long sumSkill = accumulate(skill.begin(), skill.end(), 0L);
    long prevWizardDone = sumSkill * mana[0];

    for (int j = 1; j < mana.size(); ++j) {
      long prevPotionDone = prevWizardDone;
      for (int i = skill.size() - 2; i >= 0; --i) {
        // start time for wizard i brewing potion j
        // = max(end time for wizard i brewing potion j - 1,
        //       the earliest start time for wizard i + 1 brewing potion j
        //       (coming from previous iteration)
        //       - time for wizard i brewing potion j)
        prevPotionDone -= static_cast<long>(skill[i + 1]) * mana[j - 1];
        prevWizardDone =
            max(prevPotionDone,
                prevWizardDone - static_cast<long>(skill[i]) * mana[j]);
      }
      prevWizardDone += sumSkill * mana[j];
    }

    return prevWizardDone;
  }
};


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort potions array in ascending order for binary search
        sort(potions.begin(), potions.end());
      
        // Result vector to store count of successful pairs for each spell
        vector<int> result;
      
        // Get the total number of potions
        int potionCount = potions.size();
      
        // Iterate through each spell
        for (int& spellStrength : spells) {
            // Calculate minimum potion strength needed for this spell
            // Using ceiling division: (success + spellStrength - 1) / spellStrength
            // to avoid floating point arithmetic issues
            long long minPotionStrength = (success + spellStrength - 1) / spellStrength;
          
            // Find the first potion that meets the minimum strength requirement
            // using binary search (lower_bound)
            int firstValidIndex = lower_bound(potions.begin(), potions.end(), minPotionStrength) - potions.begin();
          
            // Calculate number of successful pairs (all potions from firstValidIndex to end)
            int successfulPairCount = potionCount - firstValidIndex;
          
            // Add the count to result vector
            result.push_back(successfulPairCount);
        }
      
        return result;
    }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n, -1);  // Initialize result array with -1 (default for rainy days)
      
        // Set to store indices of sunny days (when rains[i] == 0)
        set<int> sunnyDays;
      
        // Map to store the last occurrence index of each lake that got filled
        unordered_map<int, int> lastRainedLakes;
      
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
          
            if (lake > 0) {  // Rainy day - lake gets filled
                // Check if this lake was already filled before
                if (lastRainedLakes.count(lake)) {
                    // Find the first sunny day after the last time this lake was filled
                    auto sunnyDayIt = sunnyDays.upper_bound(lastRainedLakes[lake]);
                  
                    // If no sunny day available to dry this lake, flooding occurs
                    if (sunnyDayIt == sunnyDays.end()) {
                        return {};  // Return empty array indicating failure
                    }
                  
                    // Use this sunny day to dry the current lake
                    result[*sunnyDayIt] = lake;
                    sunnyDays.erase(sunnyDayIt);  // Remove used sunny day
                }
              
                // Update the last occurrence of this lake being filled
                lastRainedLakes[lake] = i;
            } else {  // Sunny day - can dry one lake
                sunnyDays.insert(i);  // Add this sunny day to available days
                result[i] = 1;  // Temporarily set to 1 (can be any valid lake number)
            }
        }
      
        return result;
    }
};

class Solution {
public:
    vector<int> parent;  // Union-Find parent array
  
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
      
        // Initialize Union-Find structure
        // Each cell is initially its own parent
        parent.resize(n * n);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
      
        // Create a mapping from elevation value to its position
        // heightToIndex[h] stores the flattened index of cell with elevation h
        vector<int> heightToIndex(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                heightToIndex[grid[i][j]] = i * n + j;
            }
        }
      
        // Direction vectors for exploring 4 adjacent cells (up, right, down, left)
        vector<int> directions = {-1, 0, 1, 0, -1};
      
        // Process cells in increasing order of elevation (time)
        for (int time = 0; time < n * n; ++time) {
            // Get the position of the cell with elevation equal to current time
            int currentIndex = heightToIndex[time];
            int row = currentIndex / n;
            int col = currentIndex % n;
          
            // Check all 4 adjacent cells
            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];
              
                // If adjacent cell is valid and has elevation <= current time,
                // union it with current cell
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && 
                    grid[newRow][newCol] <= time) {
                    int adjacentIndex = newRow * n + newCol;
                    parent[find(adjacentIndex)] = find(currentIndex);
                }
              
                // Check if start (0,0) and end (n-1,n-1) are connected
                if (find(0) == find(n * n - 1)) {
                    return time;
                }
            }
        }
      
        return -1;  // Should never reach here for valid input
    }
  
private:
    // Find operation with path compression for Union-Find
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
};

typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> heightsGrid;
    int rows;
    int cols;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Initialize dimensions and store the heights grid
        rows = heights.size();
        cols = heights[0].size();
        this->heightsGrid = heights;
      
        // Queues for BFS from Pacific and Atlantic oceans
        queue<pii> pacificQueue;
        queue<pii> atlanticQueue;
      
        // Sets to track visited cells for each ocean (using flattened indices)
        unordered_set<int> pacificVisited;
        unordered_set<int> atlanticVisited;
      
        // Initialize starting points for both oceans
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Pacific Ocean: top row and left column
                if (row == 0 || col == 0) {
                    int flatIndex = row * cols + col;
                    pacificVisited.insert(flatIndex);
                    pacificQueue.emplace(row, col);
                }
                // Atlantic Ocean: bottom row and right column
                if (row == rows - 1 || col == cols - 1) {
                    int flatIndex = row * cols + col;
                    atlanticVisited.insert(flatIndex);
                    atlanticQueue.emplace(row, col);
                }
            }
        }
      
        // Perform BFS from both oceans to find all reachable cells
        bfs(pacificQueue, pacificVisited);
        bfs(atlanticQueue, atlanticVisited);
      
        // Find cells that can reach both oceans
        vector<vector<int>> result;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int flatIndex = row * cols + col;
                // If cell is reachable from both oceans, add to result
                if (pacificVisited.count(flatIndex) && atlanticVisited.count(flatIndex)) {
                    result.push_back({row, col});
                }
            }
        }
      
        return result;
    }

    void bfs(queue<pii>& bfsQueue, unordered_set<int>& visited) {
        // Direction vectors for up, right, down, left movement
        vector<int> directions = {-1, 0, 1, 0, -1};
      
        while (!bfsQueue.empty()) {
            // Process all cells at current BFS level
            int levelSize = bfsQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                auto currentCell = bfsQueue.front();
                bfsQueue.pop();
              
                // Check all 4 adjacent cells
                for (int dir = 0; dir < 4; ++dir) {
                    int nextRow = currentCell.first + directions[dir];
                    int nextCol = currentCell.second + directions[dir + 1];
                    int flatIndex = nextRow * cols + nextCol;
                  
                    // Check if next cell is valid, unvisited, and water can flow from it to current cell
                    if (nextRow >= 0 && nextRow < rows && 
                        nextCol >= 0 && nextCol < cols && 
                        !visited.count(flatIndex) && 
                        heightsGrid[nextRow][nextCol] >= heightsGrid[currentCell.first][currentCell.second]) {
                      
                        visited.insert(flatIndex);
                        bfsQueue.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize two pointers: left at the beginning, right at the end
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
      
        // Use two-pointer technique to find maximum water container
        while (left < right) {
            // Calculate current water area: minimum height × width
            // Water level is limited by the shorter line
            int currentArea = min(height[left], height[right]) * (right - left);
          
            // Update maximum water area if current is larger
            maxWater = max(maxWater, currentArea);
          
            // Move the pointer pointing to the shorter line inward
            // This greedy approach works because:
            // - Moving the shorter line might find a taller line (potentially increasing area)
            // - Moving the taller line will definitely decrease width without guarantee of height increase
            if (height[left] < height[right]) {
                ++left;  // Move left pointer rightward if left line is shorter
            } else {
                --right;  // Move right pointer leftward if right line is shorter (or equal)
            }
        }
      
        return maxWater;
    }
};

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // Initialize total bottles drunk with initial full bottles
        int totalBottlesDrunk = numBottles;
      
        // Keep exchanging empty bottles for full ones while possible
        while (numBottles >= numExchange) {
            // Exchange empty bottles for one full bottle
            numBottles -= numExchange;  // Use empty bottles for exchange
            ++numExchange;               // Exchange rate increases by 1 each time
            ++totalBottlesDrunk;         // Drink the newly obtained full bottle
            ++numBottles;                // Add the empty bottle from drinking
        }
      
        return totalBottlesDrunk;
    }
};

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Initialize the answer with the initial number of full bottles (all can be drunk)
        int totalDrunk = numBottles;
      
        // Keep exchanging empty bottles for new full bottles while we have enough empties
        // Each iteration: we exchange 'numExchange' empty bottles for 1 full bottle
        // This means we effectively reduce empty bottles by (numExchange - 1)
        // The new full bottle gets drunk immediately, so we increment totalDrunk
        while (numBottles >= numExchange) {
            // Reduce empty bottles by (numExchange - 1) since we trade numExchange for 1
            numBottles -= (numExchange - 1);
            // Increment total drunk bottles by 1 (the new bottle we got from exchange)
            totalDrunk++;
        }
      
        return totalDrunk;
    }
};

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // Iterate through levels of the triangle from bottom to top
        // k represents the current size of the array we're processing
        for (int level_size = nums.size() - 1; level_size > 0; --level_size) {
            // For each level, calculate new values by summing adjacent pairs
            // Store the result in-place, overwriting the left element
            for (int i = 0; i < level_size; ++i) {
                // Add current element with next element and take modulo 10
                // This simulates the triangular sum operation
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
      
        // After all iterations, the result is stored in the first element
        return nums[0];
    }
};

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
      
        // dp[i][j] stores the minimum score for triangulating the polygon 
        // formed by vertices from index i to j
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
      
        // Recursive function with memoization to find minimum triangulation score
        // Parameters: i - starting vertex index, j - ending vertex index
        // Returns: minimum score for triangulating polygon from vertex i to j
        function<int(int, int)> calculateMinScore = [&](int i, int j) -> int {
            // Base case: if only two vertices, no triangle can be formed
            if (i + 1 == j) {
                return 0;
            }
          
            // Return memoized result if already calculated
            if (dp[i][j] != 0) {
                return dp[i][j];
            }
          
            // Initialize result with a large value
            int minScore = INT_MAX;
          
            // Try all possible vertices k between i and j to form a triangle (i, k, j)
            // The polygon is then divided into three parts:
            // 1. Polygon from i to k
            // 2. Triangle (i, k, j)
            // 3. Polygon from k to j
            for (int k = i + 1; k < j; ++k) {
                int currentScore = calculateMinScore(i, k) + 
                                  calculateMinScore(k, j) + 
                                  values[i] * values[k] * values[j];
                minScore = min(minScore, currentScore);
            }
          
            // Store and return the minimum score
            dp[i][j] = minScore;
            return minScore;
        };
      
        // Calculate minimum score for the entire polygon (from vertex 0 to n-1)
        return calculateMinScore(0, n - 1);
    }
};

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
      
        // Iterate from the largest elements to find valid triangle
        // Starting from the end ensures we get the maximum perimeter
        for (int i = nums.size() - 1; i >= 2; --i) {
            // For a valid triangle: sum of two smaller sides > largest side
            // Check if nums[i-2] + nums[i-1] > nums[i]
            int sumOfTwoSmallerSides = nums[i - 1] + nums[i - 2];
          
            if (sumOfTwoSmallerSides > nums[i]) {
                // Valid triangle found, return the perimeter
                return sumOfTwoSmallerSides + nums[i];
            }
        }
      
        // No valid triangle can be formed
        return 0;
    }
};

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
      
        // Iterate through all possible combinations of three points
        for (const auto& point1 : points) {
            int x1 = point1[0];
            int y1 = point1[1];
          
            for (const auto& point2 : points) {
                int x2 = point2[0];
                int y2 = point2[1];
              
                for (const auto& point3 : points) {
                    int x3 = point3[0];
                    int y3 = point3[1];
                  
                    // Calculate vectors from point1 to point2 and point1 to point3
                    int vector1X = x2 - x1;
                    int vector1Y = y2 - y1;
                    int vector2X = x3 - x1;
                    int vector2Y = y3 - y1;
                  
                    // Calculate triangle area using cross product formula
                    // Area = |cross product| / 2 = |v1x * v2y - v2x * v1y| / 2
                    double currentArea = abs(vector1X * vector2Y - vector2X * vector1Y) / 2.0;
                  
                    // Update maximum area if current area is larger
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
      
        return maxArea;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // Sort the array to enable binary search and ensure a <= b <= c
        sort(nums.begin(), nums.end());
      
        int count = 0;
        int n = nums.size();
      
        // Iterate through all possible pairs of first two sides
        for (int i = 0; i < n - 2; ++i) {
            // Skip if current element is 0 (cannot form valid triangle with 0)
            if (nums[i] == 0) {
                continue;
            }
          
            for (int j = i + 1; j < n - 1; ++j) {
                // For sides a = nums[i] and b = nums[j], find the largest valid c
                // Triangle inequality: a + b > c (other conditions automatically satisfied due to sorting)
                // Find the rightmost position where nums[k] < nums[i] + nums[j]
                int targetSum = nums[i] + nums[j];
              
                // Binary search for the first element >= targetSum
                int k = lower_bound(nums.begin() + j + 1, nums.end(), targetSum) - nums.begin();
              
                // All elements from index (j+1) to (k-1) can be the third side
                // k-1 is the last valid index, so count = (k-1) - j
                count += (k - 1) - j;
            }
        }
      
        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // Sort the array to enable binary search and ensure a <= b <= c
        sort(nums.begin(), nums.end());
      
        int count = 0;
        int n = nums.size();
      
        // Iterate through all possible pairs of first two sides
        for (int i = 0; i < n - 2; ++i) {
            // Skip if current element is 0 (cannot form valid triangle with 0)
            if (nums[i] == 0) {
                continue;
            }
          
            for (int j = i + 1; j < n - 1; ++j) {
                // For sides a = nums[i] and b = nums[j], find the largest valid c
                // Triangle inequality: a + b > c (other conditions automatically satisfied due to sorting)
                // Find the rightmost position where nums[k] < nums[i] + nums[j]
                int targetSum = nums[i] + nums[j];
              
                // Binary search for the first element >= targetSum
                int k = lower_bound(nums.begin() + j + 1, nums.end(), targetSum) - nums.begin();
              
                // All elements from index (j+1) to (k-1) can be the third side
                // k-1 is the last valid index, so count = (k-1) - j
                count += (k - 1) - j;
            }
        }
      
        return count;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
      
        // Dynamic programming array to store minimum path sums
        // Size is n+1 to avoid boundary checks, with the extra element initialized to 0
        vector<int> dp(n + 1, 0);
      
        // Process the triangle from bottom to top
        for (int row = n - 1; row >= 0; --row) {
            // For each element in the current row, update the minimum path sum
            for (int col = 0; col <= row; ++col) {
                // Choose the minimum of the two adjacent elements from the row below
                // and add the current element's value
                dp[col] = min(dp[col], dp[col + 1]) + triangle[row][col];
            }
        }
      
        // The minimum path sum from top to bottom is stored at dp[0]
        return dp[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
      
        // Dynamic programming array to store minimum path sums
        // Size is n+1 to avoid boundary checks, with the extra element initialized to 0
        vector<int> dp(n + 1, 0);
      
        // Process the triangle from bottom to top
        for (int row = n - 1; row >= 0; --row) {
            // For each element in the current row, update the minimum path sum
            for (int col = 0; col <= row; ++col) {
                // Choose the minimum of the two adjacent elements from the row below
                // and add the current element's value
                dp[col] = min(dp[col], dp[col + 1]) + triangle[row][col];
            }
        }
      
        // The minimum path sum from top to bottom is stored at dp[0]
        return dp[0];
    }
};

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Handle zero numerator case
        if (numerator == 0) {
            return "0";
        }
      
        string result;
      
        // Determine if result should be negative
        // XOR returns true when signs are different
        bool isNegative = (numerator > 0) ^ (denominator > 0);
        if (isNegative) {
            result += "-";
        }
      
        // Convert to long long to avoid overflow when taking absolute values
        long long dividend = abs(static_cast<long long>(numerator));
        long long divisor = abs(static_cast<long long>(denominator));
      
        // Add the integer part
        result += to_string(dividend / divisor);
      
        // Calculate remainder
        dividend %= divisor;
      
        // If no remainder, we have a terminating decimal
        if (dividend == 0) {
            return result;
        }
      
        // Add decimal point for fractional part
        result += ".";
      
        // Map to store remainder positions for detecting repeating patterns
        // Key: remainder value, Value: position in result string
        unordered_map<long long, int> remainderToPosition;
      
        // Process the fractional part
        while (dividend != 0) {
            // Record current remainder and its position in result
            remainderToPosition[dividend] = result.size();
          
            // Multiply remainder by 10 for next digit calculation
            dividend *= 10;
          
            // Append next digit to result
            result += to_string(dividend / divisor);
          
            // Update remainder for next iteration
            dividend %= divisor;
          
            // Check if we've seen this remainder before (indicates repeating pattern)
            if (remainderToPosition.count(dividend)) {
                // Insert opening parenthesis at the start of repeating sequence
                result.insert(remainderToPosition[dividend], "(");
                // Add closing parenthesis at the end
                result += ")";
                break;
            }
        }
      
        return result;
    }
};
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int version1Length = version1.size();
        int version2Length = version2.size();
      
        int index1 = 0;
        int index2 = 0;
      
        // Process both version strings until we reach the end of both
        while (index1 < version1Length || index2 < version2Length) {
            // Parse the next revision number from version1
            int revision1 = 0;
            while (index1 < version1Length && version1[index1] != '.') {
                revision1 = revision1 * 10 + (version1[index1] - '0');
                index1++;
            }
          
            // Parse the next revision number from version2
            int revision2 = 0;
            while (index2 < version2Length && version2[index2] != '.') {
                revision2 = revision2 * 10 + (version2[index2] - '0');
                index2++;
            }
          
            // Compare the current revision numbers
            if (revision1 < revision2) {
                return -1;
            }
            if (revision1 > revision2) {
                return 1;
            }
          
            // Skip the dot separator if present
            if (index1 < version1Length) {
                index1++;  // Skip '.'
            }
            if (index2 < version2Length) {
                index2++;  // Skip '.'
            }
        }
      
        // All revisions are equal
        return 0;
    }
};

class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    constexpr int kMax = 100;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    const int maxFreq = ranges::max(count);
    return ranges::count(count, maxFreq) * maxFreq;
  }
};

class MovieRentingSystem {
 public:
  MovieRentingSystem(int n, vector<vector<int>>& entries) {
    for (const vector<int>& e : entries) {
      const int shop = e[0];
      const int movie = e[1];
      const int price = e[2];
      unrented[movie].insert({price, shop});
      shopAndMovieToPrice[{shop, movie}] = price;
    }
  }

  vector<int> search(int movie) {
    vector<int> ans;
    int i = 0;

    for (const auto& [price, shop] : unrented[movie]) {
      ans.push_back(shop);
      if (++i >= 5)
        break;
    }

    return ans;
  }

  void rent(int shop, int movie) {
    const int price = shopAndMovieToPrice[{shop, movie}];
    unrented[movie].erase({price, shop});
    rented.insert({price, {shop, movie}});
  }

  void drop(int shop, int movie) {
    const int price = shopAndMovieToPrice[{shop, movie}];
    unrented[movie].insert({price, shop});
    rented.erase({price, {shop, movie}});
  }

  vector<vector<int>> report() {
    vector<vector<int>> ans;
    int i = 0;

    for (const auto& [_, shopAndMovie] : rented) {
      ans.push_back({shopAndMovie.first, shopAndMovie.second});
      if (++i >= 5)
        break;
    }

    return ans;
  }

 private:
  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };

  // {movie: (price, shop)}
  unordered_map<int, set<pair<int, int>>> unrented;

  // {(shop, movie): price}
  unordered_map<pair<int, int>, int, PairHash> shopAndMovieToPrice;

  // (price, (shop, movie))
  set<pair<int, pair<int, int>>> rented;
};

struct Packet {
  int source;
  int destination;
  int timestamp;

  bool operator<(const Packet& other) const {
    return source < other.source ||
           (source == other.source && destination < other.destination) ||
           (source == other.source && destination == other.destination &&
            timestamp < other.timestamp);
  }
};

class Router {
 public:
  Router(int memoryLimit) : memoryLimit(memoryLimit) {}

  bool addPacket(int source, int destination, int timestamp) {
    const Packet packet{source, destination, timestamp};
    if (uniquePackets.find(packet) != uniquePackets.end())
      return false;
    if (packetQueue.size() == memoryLimit)
      forwardPacket();
    packetQueue.push(packet);
    uniquePackets.insert(packet);
    destinationTimestamps[destination].push_back(timestamp);
    return true;
  }

  vector<int> forwardPacket() {
    if (packetQueue.empty())
      return {};
    const Packet nextPacket = packetQueue.front();
    packetQueue.pop();
    uniquePackets.erase(nextPacket);
    ++processedPacketIndex[nextPacket.destination];
    return {nextPacket.source, nextPacket.destination, nextPacket.timestamp};
  }

  int getCount(int destination, int startTime, int endTime) {
    if (destinationTimestamps.find(destination) == destinationTimestamps.end())
      return 0;
    const vector<int>& timestamps = destinationTimestamps[destination];
    const int startIndex = processedPacketIndex[destination];
    const auto lowerBound = lower_bound(timestamps.begin() + startIndex,
                                        timestamps.end(), startTime);
    const auto upperBound =
        upper_bound(timestamps.begin() + startIndex, timestamps.end(), endTime);
    return upperBound - lowerBound;
  }

 private:
  const int memoryLimit;
  set<Packet> uniquePackets;
  queue<Packet> packetQueue;
  map<int, vector<int>> destinationTimestamps;
  map<int, int> processedPacketIndex;
};


Logic folder includes LazyLogics That are used to basic Logic Learning
DSA Practice file Contains multiple Logic together in file That are commented to form another one
Currently solving some leetcode question so no new update on lazyLogic


Currently studying strings

today I solved leetcode 3516 find the closest person problem


solved 2749

class Solution {
 public:
  int makeTheIntegerZero(int num1, int num2) {
    // If k operations are used, num1 - [(num2 + 2^{i_1}) + (num2 + 2^{i_2}) +
    // ... + (num2 + 2^{i_k})] = 0. So, num1 - k * num2 = (2^{i_1} + 2^{i_2} +
    // ... + 2^{i_k}), where i_1, i_2, ..., i_k are in the range [0, 60].
    // Note that for any number x, we can use "x's bit count" operations to make
    // x equal to 0. Additionally, we can also use x operations to deduct x by
    // 2^0 (x times), which also results in 0.

    for (long ops = 0; ops <= 60; ++ops) {
      const long target = num1 - ops * num2;
      if (__builtin_popcountl(target) <= ops && ops <= target)
        return ops;
    }

    return -1;
  }
};





today I solved 
3495. Minimum Operations to Make Aray Elements Zero




class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> ans(n);

    for (int i = 0; i < n; ++i)
      ans[i] = i * 2 - n + 1;

    return ans;
  }
};








class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    for (int A = 1; A < n; ++A) {
      int B = n - A;
      if (to_string(A).find('0') == string::npos &&
          to_string(B).find('0') == string::npos)
        return {A, B};
    }

    throw;
  }
};







lass Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    constexpr int kMod = 1'000'000'007;
    long share = 0;
    // dp[i] := the number of people know the secret at day i
    vector<int> dp(n);  // Maps day i to i + 1.
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (i - delay >= 0)
        share += dp[i - delay];
      if (i - forget >= 0)
        share -= dp[i - forget];
      share += kMod;
      share %= kMod;
      dp[i] = share;
    }

    // People before day `n - forget - 1` already forget the secret.
    return accumulate(dp.end() - forget, dp.end(), 0,
                      [&](int acc, int d) { return (acc + d) % kMod; });
  }
};





class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    vector<unordered_set<int>> languageSets;
    unordered_set<int> needTeach;
    unordered_map<int, int> languageCount;

    for (const vector<int>& language : languages)
      languageSets.push_back({language.begin(), language.end()});

    // Find friends that can't communicate.
    for (const vector<int>& friendship : friendships) {
      const int u = friendship[0] - 1;
      const int v = friendship[1] - 1;
      if (cantTalk(languageSets, u, v)) {
        needTeach.insert(u);
        needTeach.insert(v);
      }
    }

    // Find the most popular language.
    for (const int u : needTeach)
      for (const int language : languageSets[u])
        ++languageCount[language];

    // Teach the most popular language to people who don't understand.
    int maxCount = 0;
    for (const auto& [_, freq] : languageCount)
      maxCount = max(maxCount, freq);

    return needTeach.size() - maxCount;
  }

 private:
  // Returns true if u can't talk with v.
  bool cantTalk(const vector<unordered_set<int>>& languageSets, int u, int v) {
    for (const int language : languageSets[u])
      if (languageSets[v].contains(language))
        return false;
    return true;
  }
};







class Solution {
 public:
  string sortVowels(string s) {
    string ans;
    vector<char> vowels;

    for (const char c : s)
      if (isVowel(c))
        vowels.push_back(c);

    ranges::sort(vowels);

    int i = 0;  // vowels' index
    for (const char c : s)
      ans += isVowel(c) ? vowels[i++] : c;

    return ans;
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }
};




class Solution {
public:
    bool doesAliceWin(string s) {
        // Define the set of vowels to check against
        const string VOWELS = "aeiou";
      
        // Iterate through each character in the input string
        for (char c : s) {
            // Check if the current character is a vowel
            // find() returns npos if the character is not found
            if (VOWELS.find(c) != string::npos) {
                // If any vowel is found, Alice wins
                return true;
            }
        }
      
        // If no vowels are found in the string, Alice doesn't win
        return false;
    }
};








class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;
        
        for (string word : wordlist) {
            string lower = toLower(word);
            if (!caseInsensitive.count(lower)) {
                caseInsensitive[lower] = word;
            }
            string masked = maskVowels(lower);
            if (!vowelInsensitive.count(masked)) {
                vowelInsensitive[masked] = word;
            }
        }
        
        vector<string> result;
        for (string query : queries) {
            if (exactWords.count(query)) {
                result.push_back(query);
                continue;
            }
            
            string lower = toLower(query);
            if (caseInsensitive.count(lower)) {
                result.push_back(caseInsensitive[lower]);
                continue;
            }
            
            string masked = maskVowels(lower);
            if (vowelInsensitive.count(masked)) {
                result.push_back(vowelInsensitive[masked]);
                continue;
            }
            
            result.push_back("");
        }
        return result;
    }
    
private:
    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }
    
    string maskVowels(string s) {
        for (char &c : s) {
            if (isVowel(c)) c = '*';
        }
        return s;
    }
    
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};





class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    int ans = 0;
    istringstream iss(text);
    vector<bool> broken(26);

    for (const char c : brokenLetters)
      broken[c - 'a'] = true;

    for (string word; iss >> word;)
      ans += canBeTyped(word, broken);

    return ans;
  }

 private:
  bool canBeTyped(const string& word, const vector<bool>& broken) {
    for (const char c : word)
      if (broken[c - 'a'])
        return false;
    return true;
  }
};






class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        // Initialize the food rating system with the given arrays
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
          
            // Store food-rating pairs for each cuisine in a sorted set
            // Use negative rating for descending order, food name for lexicographic tiebreaker
            cuisineToFoodSet[cuisine].insert({-rating, food});
          
            // Store the rating and cuisine for each food for quick lookup
            foodInfo[food] = {rating, cuisine};
        }
    }
  
    void changeRating(string food, int newRating) {
        // Retrieve the current rating and cuisine of the food
        auto [oldRating, cuisine] = foodInfo[food];
      
        // Update the food's rating in the lookup map
        foodInfo[food] = {newRating, cuisine};
      
        // Remove the old entry from the cuisine's sorted set
        cuisineToFoodSet[cuisine].erase({-oldRating, food});
      
        // Insert the new entry with updated rating
        cuisineToFoodSet[cuisine].insert({-newRating, food});
    }
  
    string highestRated(string cuisine) {
        // Return the food with highest rating for the given cuisine
        // The set is sorted by rating (descending) and food name (ascending)
        return cuisineToFoodSet[cuisine].begin()->second;
    }
  
private:
    // Map from cuisine to a set of (negative rating, food name) pairs
    // Set automatically maintains sorted order: highest rating first, then lexicographically
    unordered_map<string, set<pair<int, string>>> cuisineToFoodSet;
  
    // Map from food name to its (rating, cuisine) information
    unordered_map<string, pair<int, string>> foodInfo;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */



class TaskManager {
private:
    // Map: taskId -> (userId, priority)
    unordered_map<int, pair<int, int>> taskMap;
  
    // Set to maintain tasks sorted by priority (descending) and taskId (descending)
    // Stores pairs of (-priority, -taskId) for automatic sorting
    set<pair<int, int>> prioritySet;

public:
    /**
     * Constructor: Initialize the task manager with initial tasks
     * @param tasks: Vector of tasks where each task is [userId, taskId, priority]
     */
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    /**
     * Add a new task to the system
     * @param userId: The user who owns the task
     * @param taskId: Unique identifier for the task
     * @param priority: Priority level of the task
     */
    void add(int userId, int taskId, int priority) {
        // Store task information in the map
        taskMap[taskId] = {userId, priority};
      
        // Insert into set with negative values for descending order
        // Higher priority and higher taskId will come first
        prioritySet.insert({-priority, -taskId});
    }

    /**
     * Edit the priority of an existing task
     * @param taskId: The task to edit
     * @param newPriority: The new priority value
     */
    void edit(int taskId, int newPriority) {
        // Get current task information
        auto [userId, oldPriority] = taskMap[taskId];
      
        // Remove old entry from the priority set
        prioritySet.erase({-oldPriority, -taskId});
      
        // Insert new entry with updated priority
        prioritySet.insert({-newPriority, -taskId});
      
        // Update the task map with new priority
        taskMap[taskId] = {userId, newPriority};
    }

    /**
     * Remove a task from the system
     * @param taskId: The task to remove
     */
    void rmv(int taskId) {
        // Get task information before removal
        auto [userId, priority] = taskMap[taskId];
      
        // Remove from priority set
        prioritySet.erase({-priority, -taskId});
      
        // Remove from task map
        taskMap.erase(taskId);
    }

    /**
     * Execute the highest priority task
     * @return: The userId of the executed task, or -1 if no tasks exist
     */
    int execTop() {
        // Check if there are any tasks to execute
        if (prioritySet.empty()) {
            return -1;
        }
      
        // Get the highest priority task (first element in set)
        auto topTask = *prioritySet.begin();
        prioritySet.erase(prioritySet.begin());
      
        // Extract taskId (negate to get original value)
        int taskId = -topTask.second;
      
        // Get userId from the task map
        int userId = taskMap[taskId].first;
      
        // Remove task from map
        taskMap.erase(taskId);
      
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */__
 


class Spreadsheet {
private:
    // Hash map to store cell values with cell name as key
    unordered_map<string, int> cellValues;

public:
    // Constructor: Initialize spreadsheet with given number of rows
    // Note: rows parameter is not used in this implementation
    Spreadsheet(int rows) {
        // No initialization needed for the hash map
    }

    // Set the value of a specific cell
    void setCell(string cell, int value) {
        cellValues[cell] = value;
    }

    // Reset a cell by removing it from the spreadsheet
    void resetCell(string cell) {
        cellValues.erase(cell);
    }

    // Calculate and return the value based on the given formula
    // Formula format: "=cell1+cell2+...+celln" or "=value1+value2+...+valuen"
    // Can also be a mix of cells and numeric values
    int getValue(string formula) {
        int result = 0;
      
        // Remove the '=' prefix and create a string stream for parsing
        stringstream formulaStream(formula.substr(1));
        string token;
      
        // Parse the formula by splitting on '+' delimiter
        while (getline(formulaStream, token, '+')) {
            // Check if token is a numeric value
            if (isdigit(token[0])) {
                // Convert string to integer and add to result
                result += stoi(token);
            } else {
                // Token is a cell reference
                // Add cell value if it exists, otherwise add 0
                result += cellValues.count(token) ? cellValues[token] : 0;
            }
        }
      
        return result;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */





