# Sorting out Sorting: 3-way Quicksort

## Lab #10

This week you will implement a version of QuickSort that splits the array into 3 subarrays before recursing. Then you will experiment with some other sorts to be familiar with their performance characteristics.

### Overview of QuickSort

QuickSort was invented by C.A.R. Hoare in 1960 and has been thoroughly studied and modified since then. In general, it is easy to implement, works well in a variety of situations and often consumes fewer resources than other sorts. This is an in-place sort that can run in O( N log N ) on average to sort N items.

The basic idea is to use divide-and-conquer, that is to partition the input into parts or partitions, then sort the partitions recursively. The partitions are determined by scanning once through the input and putting all the data less than some pivot value in one partition, and all the data greater than the pivot in another. Selecting a good pivot, optimizing the recursion (or finding a place to stop), and changing the number of partitions have all been areas of improvement to the basic algorithm.  In this lab, we will use three partitions.

E. Dijkstra also made an improvement to QuickSort and this is the one you will code. The idea is to make 3 partitions, one with items **less** than the key, one with items **equal** to the key, and one with items **greater* than the key. 

At each single pass through the array, three partitions are made. As _i_ makes it way through the array the following properties hold:

1. an index `lt` such that `a[lo .. lt-1] < v` 

2. an index ‘gt’ such that `a[gt+1 .. hi] > v`

3. an index `i` such that `a[lt .. i-1] = v`

4. and `a[i .. gt]` are not yet examined


Here is some pseudocode for the algorithm:

```
procedure sort( array, lo, hi ) is

if (hi <= lo) then
  exit
end if

lt = lo
gt = hi
v = a[lo]  —- set pivot

i = lo

while ( i <= gt ) loop

  if a[i] < v then
    exchange( a[lt], a[i] )
    increment lt
    increment i
   
  elseif a[i] > v then
    exchange( a[i], a[gt] )
    decrement gt

  else
    increment i

  end if

  —-now i has passed through the array, so
  —-a[lo .. lt-1] < v
  —-a[lt .. gt] = v
  —-a[gt+1 .. hi] > v
  
  sort( a, lo, lt-1 )
  sort( a, gt+1, hi )

end sort
```


### In the Repository

You will find a c++ file with all the sorts and a driver program, `sorting.cpp`. This is the file you will modify and run in this lab.

There is also a python script `gen-numbers.py` that you will use to generate random numbers on which to sort. You will **NOT** need to modify this script, only to use it.


### Using the Script

The python script will generate lists of numbers for your program to sort. You use it by passing it the number of numbers you want, and a second parameter to indicate the upper limit of the range of numbers. Here are two examples:

I want to get 100 numbers from 0-9: (and write it to a file called `input.txt`)
python gen-numbers.py 100 10 > input.txt

I want to get 10000 numbers from 0 to 135:
python gen-numbers.py 10000 136 > input.txt


### Using the Main Program

If you compiled your program to an executable called `sorting` then you can write:
./sorting < input.txt
and the numbers you generated will be applied to the program.

### What Must You Do

You must fill in the empty function `qsort3` to perform the 3-way QuickSort routine.

Then, when it is working, run it several times on data you create to be able to discuss the following:

Compare the empirical performance of MergeSort, QuickSort and 3-way QuickSort. Is there a time when the conditions are better to use one over another?

### Minimum Expectation for Credit

You must complete the `qsort3` function and take part in the discussion during the last 10 minutes of class.

