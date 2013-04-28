/*
2
1 1 2
C1 D1
D1 C1
1 2 4
C1 D1
C1 D1
C1 D2
D2 C1
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//hungarian
bool match(int v, vector< vector< int > > &g, vector< bool > &visited, vector< int > &link){
    for(int i=0;i<g[v].size();i++) {
        int k=g[v][i];
        if( !visited[k] ) {
            visited[k]=true;
            if( link[k]==-1 || match(link[k], g, visited, link) ) {
                link[k]=v;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    for( int i=0; i<n; i++ ){
        int c,d,v;
        cin>>c>>d>>v;

        //read the votes
        vector< pair< string,string > > votes(v);

        for( int j=0; j<v; j++ ){
            string like,hate;
            cin>>like>>hate;
            votes[j]=make_pair(like,hate);
        }
        
        //the adj of G'
        vector< vector< int > > g(v);
        vector<bool> like_cat(v);
        for( int j=0; j<v; j++ ){
            if( votes[j].first[0]=='C' ){
                like_cat[j]=true;
            }
            for( int k=0; k<v; k++ ){
                if( votes[j].first.compare(votes[k].second)==0 || votes[j].second.compare(votes[k].first)==0 ){
                    g[j].push_back(k);
                }
            }
        }

        //get the max match for G'
        int max_match=0;
        vector<int> link(v,-1);

        for( int j=0; j<v; j++ ){
            if( like_cat[j] ){
                vector<bool> visited(v);
                if( match(j, g, visited, link) ){
                    max_match++;
                }
            }
        }
        
        //ok answer is v-max_match
        cout<<v-max_match<<endl;
    }
}
