My thoughts:

For example, input index[1,2,3,4,5]values[2,4,5,1,3]

### Idea1
First of all, could I iterate from the beginning of the array?
For [1,2], the container must be [1,2].
Then [1,2,3], we don't know between [1,2][2,3][1,3], which one is better.
So we couldn't iterate from beginning.

### Idea2
The complexity of the simplest solution is O(n*n). There must be a better solution.
How about iterate from both beginning and end?

Let's define A(a,b) as the container volumn of a,b
M(a,b) as the maxest volumn between a,b

The quiz is to get M(1,n)
The fomula:

```
if (a1 <= an)
	M(1,n) = max( A(1,n), M(2,n) )
else if (a1 > an)
	M(1,n) = max( A(1,n), M(1,n-1) )
```
why?
We have the assumption that if a1 <= an, then all A(1,*) results are not optimum solution. 
Because a1 is less than an. A(1,\*) must be less than A(1,n)




