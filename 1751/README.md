---
template: leetcode
title: Maximum Number of Events That Can Be Attended II
number: 1751
link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
---

## Intuition

This problem could be solved with a greedy algorithm but

- what should we do greedily
    - greedily select intervals with maximum value
    - greedily try to increase number of intervals

This concludes that this is not a greedy problem, if it were there would be only one greedy way.

Now it is clear we have to check all the cases, and this can be solved recursively.

```cpp
solve(index, items_remaining){
    if(items_remaining == 0 || index > items_size) 
        return 0;
    return 
        maximum(
            solve(index + 1, items_remaining), // don't take this item
            solve(index + 1, items_remaining - 1) + value_of_current_item // take current item
        )
}
```

But there is a problem, how can we know that the item we are currently at,
can be taken without knowing what items we already took. What if this
interval is overlapping with previous interval we took.

This can be solved in two ways:

We maintain a data structure which helps us to tell if we can take current element.
This data structure can be a map.
This additional data structure will cause our recursive functions to have many more states
so applying dynamic programming on this will not work.

So what if we change our items array in such a way that we don't have to see what we took earlier.
This can be achieved by sorting our array by start time, and when we pick a element the
next element after that would have it's start value greater than current end value.

We can linearly search for the next element or even better we can apply binary search.

Now all we have to do is, apply dynamic programming by utilizing state of our
recursive function.
