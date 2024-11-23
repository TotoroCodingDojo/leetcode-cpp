---
template: leetcode
title: Champagne Tower
number: 799
link: https://leetcode.com/problems/champagne-tower
tags: 
    - arrays
---

This is simple problem. You do as is described in the problem.
First you pour all amount in one glass.
Now you put 1 in this glass and half in one glass, and half in other.
This problem is similar to pascal triangle problem in sense that
you have to use nearly same iterative process.
But in this case it is much easier if you generate new row while iterating previous row,
rather than generating new row items while iterating them.

Here is a naive solution:

```py
{{ include_file("solution2.py")}}
```

Here is space optimized approach:

```py
{{ include_file("solution1.py")}}
```
