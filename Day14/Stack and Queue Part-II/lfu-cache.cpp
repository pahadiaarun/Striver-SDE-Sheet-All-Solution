// https://leetcode.com/problems/lfu-cache/

class LFUCache {
public:
    int time,n;
    map<int,set<pair<int,int>>> mp;
    map<int,int> freq;
    map<int,int> intime;
    map<int,int> val,cnt;
    LFUCache(int capacity) {
        n=capacity;
        time=1;
        mp.clear();
        freq.clear();
        intime.clear();
        val.clear();
    }
    
    int get(int key) {
        if(freq.find(key)!=freq.end()){
            mp[cnt[key]+1].insert({cnt[key]+1,time});
            mp[cnt[key]].erase({cnt[key],intime[key]});
            if(mp[cnt[key]].empty()) mp.erase(cnt[key]);
            intime[key]=time;
            val[time]=key;
            time++;cnt[key]++;
            return freq[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cnt.size()<n && cnt.find(key)==cnt.end()){
            mp[1].insert({1,time});
            intime[key]=time;
            cnt[key]=1;
            val[time]=key;
            freq[key]=value;
            time++;
        }
        else if(cnt.find(key)!=cnt.end()){
           mp[cnt[key]].erase({cnt[key],intime[key]});
           if(!mp[cnt[key]].size()) mp.erase(cnt[key]);
           freq[key]=value;
           intime[key]=time;
           cnt[key]++;
           val[time]=key;
           mp[cnt[key]].insert({cnt[key],time});
           time++;
        }
        else if(n){
            auto it=mp.begin();
            pair<int,int> ele=*(it->second).begin();
            mp[it->first].erase(it->second.begin());
            if(mp[it->first].empty()) mp.erase(it->first);
            freq.erase(val[ele.second]);
            cnt.erase(val[ele.second]);
            mp[cnt[key]+1].insert({cnt[key]+1,time});
            intime[key]=time;
            cnt[key]++;
            val[time]=key;
            freq[key]=value;
            time++;
        }
    }
};

