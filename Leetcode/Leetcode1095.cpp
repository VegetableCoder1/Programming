/*
1095. 山脉数组中查找目标值
给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。
只能通过题目提供的接口访问数组 而且查找过程只允许访问100次 数据规模为 3<=n<=10000

[思路]很明显，这题要用二分查找的思路去做题
给定的山脉数组，可以分成左边有序和右边有序两个部分，左右有序均可以二分查找
那么如何在尽可能短的时间内找到山脉的顶峰？  二分查找
*/
#include <bits/stdc++.h>
using namespace std;
class MountainArray
{
public:
    int get(int index);
    int length();
};
int findInMountainArray(int target, MountainArray &mountainArr);
int main()
{
}
int findInMountainArray(int target, MountainArray &mountainArr)
{
    if (!mountainArr.length())
        return -1;
    int highpos = findHighPos(mountainArr);
    int pos = findInLeft(mountainArr, 0, highpos, target);
    if (-1 != pos)
        return pos;
    return findInRight(mountainArr, highpos + 1, mountainArr.length() - 1, target);
}

int findHighPos(MountainArray &mountainArr)
{
    int left = 0, right = mountainArr.length() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int findInLeft(MountainArray &mountainArr, int l, int r, int target) //升序
{
    int left = l, right = r;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mountainArr.get(mid) > target)
        {
            right = mid - 1;
        }
        else if (mountainArr.get(mid) < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    if (mountainArr.get(left) == target)
        return left;
    return -1;
}

int findInRight(MountainArray &mountainArr, int l, int r, int target) // 降序
{
    int left = l, right = r;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mountainArr.get(mid) > target)
        {
            left = mid + 1;
        }
        else if (mountainArr.get(mid) < target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    if (mountainArr.get(right) == target)
        return left;
    return -1;
}
;
