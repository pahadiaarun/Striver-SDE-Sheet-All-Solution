// https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h> 

 

struct Node {

  Node * links[26];

 

  bool containsKey(char ch) {

    return (links[ch - 'a'] != NULL);

  }

 

  Node * get(char ch) {

    return links[ch - 'a'];

  }

 

  void put(char ch, Node * node) {

    links[ch - 'a'] = node;

  }

};

 

int distinctSubstring(string & s) {

  Node * root = new Node();

  int count = 0;

  int n = s.size();

  for (int i = 0; i < n; i++) {

    Node * node = root;

 

    for (int j = i; j < n; j++) {

      if (!node -> containsKey(s[j])) {

        node -> put(s[j], new Node());

        count++;

      }

      node = node -> get(s[j]);

    }

 

  }

  return count ;

}

