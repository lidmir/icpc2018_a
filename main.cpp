//icpc_a  
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int max_m=1e6;
int a[max_m],b[max_m];    
LL s[max_m],t[max_m];
double p[max_m];

typedef pair<LL,LL> NODE;
vector<NODE> node;   // node save <time,station> 
map<LL,double> p_node[max_m]; //vector p_node[i].second save the probability of catch the plane at station i at different time
map<LL,double>::iterator it;
vector<int> pos[max_m];   //pos save position of value in node

int main()
{
    int m,n;
    LL k;
    cin>>m>>n>>k;
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i]>>s[i]>>t[i]>>p[i];
        if(t[i]>k||a[i]==1)   //delete useless node
        {
            i--;
            m--;
            continue;
        }
        node.push_back(NODE(s[i],a[i]));   //add node
        node.push_back(NODE(t[i],b[i]));
    }
    node.push_back(NODE(k+1,1));   //push the successful point
    sort(node.begin(),node.end());
    node.erase(unique(node.begin(),node.end()),node.end());  //delete same node
    for(int i=0;i<m;i++)   //find position
    {
        int temp=find(node.begin(),node.end(),NODE(s[i],a[i])) - node.begin();  
        pos[temp].push_back(i);  //temp is the position of start station in line i after sort 
    }
    for(int i=node.size()-1;i>=0;i--)
    {
        LL n_time=node[i].first;     //time
        int n_st=node[i].second;    //bus stop
        double p_a2;     // p_a2:probability when no succeed at this node and after this there is bus
        if(n_st==1) p_a2=1;      
        else
        {
            p_a2=0;
            it=p_node[n_st].upper_bound(n_time);    //find next time 
            if(it!=p_node[n_st].end())            
                p_a2=(*it).second;                  //p_node[n_st]<-map(time,probability)
        }
        double p_a1=p_a2;
        for(int j=0;j<pos[i].size();j++)
        {
            int line=pos[i][j];
            it=p_node[b[line]].upper_bound(t[line]);   //find next time after arriving at destination
            if(it==p_node[b[line]].end()) continue;
            p_a1=max(p_a1,p[line]*(*it).second+(1-p[line])*p_a2);
        }
        p_node[n_st][n_time]=p_a1;
    }
    cout<<p_node[0][0];
    return 0;
}

