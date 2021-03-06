//JZ53 数字在升序数组中出现的次数
int GetNumberOfK(vector<int> data ,int k) {
    if (data.empty()) return 0;
    int l = 0, r = data.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (data[mid] < k) l = mid + 1;
        else r = mid;
    }
    if (data[l] != k) return 0;
    int left = l;
    l = 0, r = data.size() - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (data[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return r - left + 1;
}

//另一种写法
int GetNumberOfK(vector<int> data ,int k) {
    if (data.empty()) return 0;
    int left = 0, right = data.size()-1;
    int r = 0, l = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == k) {
            left = mid + 1;
        }
        if (data[mid] > k) right = mid - 1;
        if (data[mid] < k) left = mid + 1;
    }
    r = right;
    if (right < 0 || data[right] != k) return 0;
    left = 0, right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == k) {
            right = mid - 1;
        }
        if (data[mid] > k) right = mid - 1;
        if (data[mid] < k) left = mid + 1;
    }
    l = left;
    if (left >= data.size() || data[left] != k) return 0;
    return r - l + 1;
}

//python
def GetNumberOfK(self, data, k):
    return data.count(k)
//JZ4 二维数组中的查找
def Find(self, target, array):
    for i in range(len(array)):
        if target in array[i]:
            return True;
    return False;

//JZ11 旋转数组中的最小数字
int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty()) return 0;
    int n = rotateArray.size();
    int l = 0, r = n-1;
    while (rotateArray[l]==rotateArray[r]) --r;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (rotateArray[mid] < rotateArray[r]) r = mid;
        else l = mid + 1;
    }
    return rotateArray[r];
}

//改进
int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty()) return 0;
    int n = rotateArray.size();
    int l = 0, r = n-1;
    while (rotateArray[l]==rotateArray[r]) --r;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (rotateArray[mid] < rotateArray[r]) r = mid;
        else if (rotateArray[mid] > rotateArray[r]) l = mid + 1;
        else if (rotateArray[mid] == rotateArray[r]) r--;
    }
    return rotateArray[l];
}
//JZ38 字符串的排列
vector<string> Permutation(string str) {
    vector<string> res;
    int n = str.size();
    if (!n) return res;
    dfs(str, res, 0, n);
    return res;
    
}
void dfs(string str, vector<string> &res, int index, int n) {
    if (index == n) {
        res.push_back(str);
        return;
    }
    for (int i=index; i<n; ++i) {
        if (i != index && str[i] == str[index]) continue;
        swap(str[index], str[i]);
        dfs(str, res, index+1, n);
    }
}