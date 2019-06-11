#include <stdio.h>
#include <vector>

// 额外空间
bool find_repeat_number_v1(const std::vector<int> &array) {
    auto length = array.size();
    if (length <= 1) {
        return false;
    }
    // 校验数据准确性
    for (auto i : array) {
        if (i < 0 || i > length) {
            printf("Illegal Num: %d\n", i);
            return false;
        }
    }
    // 中介容器
    std::vector<int> temp(length);
    for (auto i : array) {
        if (temp[i] == 0) {
            ++temp[i];
        } else {
            printf("Diff_Num: %d\n", i);
            return true;
        }
    }
    return false;
}

// 非额外空间
bool find_repeat_number_v2(std::vector<int> &array) {
    auto length = array.size();
    if (length <= 1) {
        return false;
    }
    // 校验数据准确性
    for (auto i : array) {
        if (i < 0 || i > length) {
            printf("Illegal Num: %d\n", i);
            return false;
        }
    }
    for (int i = 0; i < length; ++i) {
        while (array[i] != i) {
            if (array[array[i]] == array[i]) {
                printf("Diff_Num: %d\n", array[i]);
                return true;
            } else {
                array[i] = array[array[i]] + array[i];
                array[array[i]] = array[i] - array[array[i]];
                array[i] = array[i] - array[array[i]];
            }
        }
    }
    return false;
}

int Test_v1() {
    std::vector<int> test_1 = {1, 2, 3, 4, 7};
    printf("===== Test 1 ====\n");
    printf("Except: %d, Actual:%d\n", true, find_repeat_number_v1(test_1));

    std::vector<int> test_2 = {1, 1, 2, 1, 3};
    printf("===== Test 2 ====\n");
    printf("Except: %d, Actual:%d\n", true, find_repeat_number_v1(test_2));

    std::vector<int> test_3;
    printf("===== Test 3 ====\n");
    printf("Except: %d, Actual:%d\n", false, find_repeat_number_v1(test_3));

    std::vector<int> test_4 = {0, 1, 2, 3};
    printf("===== Test 4 ====\n");
    printf("Except: %d, Actual:%d\n", false, find_repeat_number_v1(test_4));

    return 0;
}

int Test_v2() {
    std::vector<int> test_1 = {1, 2, 3, 4, 7};
    printf("===== Test 1 ====\n");
    printf("Except: %d, Actual:%d\n", true, find_repeat_number_v2(test_1));

    std::vector<int> test_2 = {1, 1, 2, 1, 3};
    printf("===== Test 2 ====\n");
    printf("Except: %d, Actual:%d\n", true, find_repeat_number_v2(test_2));

    std::vector<int> test_3;
    printf("===== Test 3 ====\n");
    printf("Except: %d, Actual:%d\n", false, find_repeat_number_v2(test_3));

    std::vector<int> test_4 = {0, 1, 2, 3};
    printf("===== Test 4 ====\n");
    printf("Except: %d, Actual:%d\n", false, find_repeat_number_v2(test_4));

    return 0;
}


int main() {
    Test_v1();
    Test_v2();
    return 0;
}