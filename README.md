# Text_Predictor
Text predictor system using Trie data structure in C++.

## Problem description
Most machine learning algorithms in commercial products (like SwiftKeyon Android) use Markov chains. 
The example, below, illustrates a chain of words and probabilities based on previous texting.
For individual words we can use Markov chains of letters.

![alt text](https://scontent-mrs1-1.xx.fbcdn.net/v/t1.0-9/39558007_2332259600124120_2671139607055171584_n.jpg?_nc_cat=0&oh=f095c39587c1f0f4cd7a9632d925f1ae&oe=5BEE5BFE)

Idea: Implement a ‘Dictionary’ of Words as a Tree and use it to
provide a prediction of the possible next words. 
