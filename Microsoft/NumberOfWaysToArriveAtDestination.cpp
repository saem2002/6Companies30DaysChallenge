class Solution {
public:  

    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<long long> ans;
        unordered_map<long long,list<pair<long long,long long>>> mp;
        vector<bool> visited(n,false);
        for(auto i:roads)
        {
            mp[i[0]].push_back({i[1],i[2]});
            mp[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

        vector<long long> dist(n,LONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        long long mod = (long long )(1e9+7);
        while(!pq.empty())
        {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto it:mp[node])
            {
                long long adjNode = it.first;
                long long weight =  it.second;

                if(dis+weight< dist[adjNode])
                {
                    dist[adjNode]=dis+weight;
                    pq.push({dis+weight,adjNode});
                    ways[adjNode]=ways[node];
                }else if(dis+weight==dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }

            }
        }
        return ways[n-1]%mod;



    }
};