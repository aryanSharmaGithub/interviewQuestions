#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

// Although iterator in itself is not a good topic, but here we can clearly see the difference b/w map and unordered map
// While map has everything in order (even if user input unordered data), unordered map does not have any order at all.
// In map, iterator is pointed to specific starting index (here, a) while in unordered map nothing like this is present (like at the time of writing, first element was h)
int main()
{
    unordered_map<string,int> map1;
    unordered_map<string,int> :: iterator it1;
    map1["a"]=1;
    map1["b"]=2;
    map1["c"]=3;
    map1["d"]=4;  
    map1["e"]=5;    
    map1["f"]=6;    
    map1["g"]=7;    
    map1["h"]=8;
    map<string,int> map2;
    map2["a"]=1;
    map2["b"]=2;
    map2["d"]=3;
    map2["c"]=4;  
    map2["e"]=5;    
    map2["f"]=6;    
    map2["g"]=7;    
    map2["h"]=8;

    map<string,int> :: iterator it2;

    for(it1 = map1.begin();it1!=map1.end();it1++){
        cout<<it1->first<<" ";
    }
    cout<<endl;
    for(it2 = map2.begin();it2!=map2.end();it2++){
        cout<<it2->first<<" ";
    }
    cout<<endl;

    //Iterators can be used in ordered things a lot. Like in maps and vectors. Below are some uses with maps rn (can be used similarly for vector as well)

    //Find (ig only for hash, unordered or ordered both)

    unordered_map<string,int> :: iterator itFind = map1.find("g");
    cout<<"Element at key '"<<itFind->first<<"' is "<<itFind->second<<endl; // This must return 7 as I know;

    map<string,int> :: iterator it2Find = map2.find("b");
    cout<<"Element at key '"<<it2Find->first<<"' is "<<it2Find->second<<endl; // This must return 2 as I know;

    // Erasing an element (this is for vector also)
    map2.erase(map2.begin(),it2Find); // Maybe c++17 does not support iterators and int together now so we need two iterator for a range. but it will be in the
    // form of [a,b) 
    for(it2 = map2.begin();it2!=map2.end();it2++){
        cout<<it2->first<<" ";
    }
    cout<<endl;
    // Removing single element
    map2.erase(map2.begin());
    for(it2 = map2.begin();it2!=map2.end();it2++){
        cout<<it2->first<<" ";
    }
    cout<<endl;
}