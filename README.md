Introduction
===

The aim of this project is to implement many state-of-the-art algorithms dealing with **simialrity join**. We will have a paper to be published in the **VLDB2014** conference, which is an experimental evaluation of these algorithms.

Similarity join and similarity metrics
===
*Notice: You are welcomed to read section 1-3 in our publication* (`papers/publication-vldb2014.pdf`) *for detailed description of these terms.*
###Similarity join
Similarity join is slightly different from the traditioinal join operator in database. Given two records set *R* and *S* and an attribute *a*, traditional join is to find out all the pairs *r, s* where *r is from R, s is from S and r.a = s.a*. In similarity join, *r.a = s.a* will be replaced by *r.a is similar to s.a*. And similarity metrics are used to define what is *similar*.

###Similairty metrics
Two kinds of metrics are often used:

1. character based, such as **edit distance**. Usually defined on strings.

2. token based, such as **jaccard**, **cosine** and **dice**. Usually defined on sets.

####[Edit distance](http://en.wikipedia.org/wiki/Edit_distance): The minimum number of edit operations required to transform one string to the other.(e.g. ED("hi", "hot")  =2).

####[Jaccard](http://en.wikipedia.org/wiki/Jaccard_index): Jac(R, S) = (R \cap S) / (R \cup S);

####[Cosine](http://en.wikipedia.org/wiki/Cosine_similarity): Cosine(R, S) = (R \cap S) / sqrt(|R||S|);

####[Dice](http://en.wikipedia.org/wiki/S%C3%B8rensen%E2%80%93Dice_coefficient): Dice(R, S) = 2(R \cap S) / (|R| + |S|);


How to build
===
Prerequisite
---
1. gcc >= 4.7(we used 4.8.2), since some `C++11 features` are used in our source codes.
2. boost >= 1.5(we used 1.5.1), we use the `functional/hash.hpp` in boost.
3. gnu make.

Build Procedure
---
Build this project is rather easy, just use the **makefile** in the **root** directory. Since there are many algorithms, we suggest to use multi-threads to speed up the **make** process(e.g. `make -j8` to use 8 threads). There are some commonly used tasks in the makefile:

1. `make` to build all the programs.
2. `make ed` to build all the algorithms which can be used for the **edit distance** similarity metric.
3. `make token` to build algorithms for **token-based** similairity metrics.

After the `make` command, you will find a `bin` directory and all the executables can be found in it. *This directory will be recreated at the beginning of every make process automatically so please do not use it to save your personal stuff*.

How to use
===
*Notice: we will add more detailed descriptions soon.*

1. For the algorithms designed for **edit distance**, usually the usage is `./PATH_TO_EXECUTABLE filename threshold`. If the algorithm requires more parameters such as **q**, it should be added in the last.
2. For the algorithms designed for **token-based metrics**, usually the usage is `./executable metric filename threshold`, where the **metric** is one of "jaccard", "cosine" or "dice".

TODOs
===
*Notice that we only list some TODOs here. We may fix them in the future but they are in low priority.*

- Add more comments.
- Add more algorithms.
- Add more aspects.
