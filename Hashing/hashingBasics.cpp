#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    // Map is implemented using Red-Black Trees so their time complexity of insert,delete,search is logN ig
    // Unordered Map is implement using HashTable (will learn maybe) which has time complexity of O(1)
    // The first value in our map is the key which can be compared to the index in our array. Diff is that here pretty much anything can be a key but in arr only
    // int was allowed. So if we want to access something, we need to pass the key for it.
    unordered_map<string,int> tempMap;

    //Insert
    // Now, map stores the values in something called pairs, so we need to declare the pair and then insert it in map
    pair<string,int> p("abc",1); // This will make a pair p of string abc and key 1. Alternatively, we can access each element as p.first = "abc"; p.second = 1;
    tempMap.insert(p); // By this, we inserted our pair in our map. So we can say that map is nothing but collection of pairs.
    // Alternatively part 2, we can directly insert string in our tempMap using this method
    tempMap["LOL"] = 2; //This will create the string itself in our map and assign value 2 to its int part. This is like we do in array only here datatype can be anything

    // Access
    cout<<"Key abc contains "<<tempMap["abc"]<<endl;
    // cout<<tempMap[1]<<endl; // This will result in error because our key is in type string, so we can access int from string but not string from int (here).

    //Check presence (or find)
    if(tempMap.count("abc")>0){ //This will give the count in of the key in map. Note this will give ans in 0 or 1 (cuz it just sees if key is present once or not)
        cout<<"abc is present in map"<<endl;
    }

    //Check size
    cout<<"Map size is "<<tempMap.size()<<endl;
    
    //Delete Element
    tempMap.erase("LOL");
    cout<<"Updated map size is: "<<tempMap.size()<<endl;

}