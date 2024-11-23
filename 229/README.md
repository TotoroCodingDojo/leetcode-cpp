---
template: leetcode
title: Majority Element II
number: 229
link: https://leetcode.com/problems/majority-element-ii
---

So this question can be easily solved by maintaining count of elements,
using a hashmap.

Time complexity of this approach would be $O(n)$ but space complexity is
also $O(n)$.

Now first thing you can notice is, there can be only two elements,
whose count can be greater than, $\lfloor n/2 \rfloor$.

If you solved majority element one, we know that if we add and subtract
for presence of another element, we will at last get the majority element.

Here we can apply a similar approach, but we have to take two elements
instead, and here is the final trick,

- both elements can be majority ii elements
- one of element is majority ii element
- none of them is majority ii element

How to solve this??

Just iterate again on array and count for the their occurrences
to check if they are valid answer.

## How it really works?

This is related to a algorithm called - Majority Voting algorithm.
<https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm>

Here is basic idea:

Given $n$ numbers and the $k$ counters, only less than $n/(k+1)$ times pair-out can happen.
Pair-out means one element remove count of other element from majority.

That is to say:

- given $n$ numbers and $1$ counter, at most $n/2$ times pair-out can happen,
  which will lead to the survival of the only element that appeared more than $n/2$ times.
- given $n$ numbers and $2$ counters, at most $n/3$ times pair-out can happen,
  which will lead to the survival of elements that appeared more than $n/3$ times.
- given $n$ numbers and $k$ counters, at most $(n/k+1)$ times of pair-out can happen,
  which will lead to the survival of elements that appeared more than $n/(k+1)$ times.

In algorithm you,

- decrease counter of all elements if no one matches
- if some counter is 0, you give a new element to it already don't have counter
