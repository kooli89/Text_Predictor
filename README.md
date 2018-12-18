# Text_Predictor
Text predictor system using Trie data structure in C++.

## Problem description
Most machine learning algorithms in commercial products (like SwiftKeyon Android) use Markov chains. 
The example, below, illustrates a chain of words and probabilities based on previous texting.
For individual words we can use Markov chains of letters.

![alt text](https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/39558007_2332259600124120_2671139607055171584_n.jpg?_nc_cat=100&_nc_ht=scontent-cdg2-1.xx&oh=a33f28ad5fc191be1487cbe76a28d436&oe=5C8C8FFE)

Idea: Implement a ‘Dictionary’ of Words as a Tree and use it to
provide a prediction of the possible next words. 
