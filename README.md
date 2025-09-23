# DSA

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





