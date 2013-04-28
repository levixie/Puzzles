#include<iostream>
#include<map>

using namespace std;

struct classcomp {
        bool operator() (const double& lhs, const double& rhs) const {
                return lhs>rhs;
        }
};

int main(){
        int n,m;
        cin>>n>>m;
        multimap<double,string,classcomp> songs;

        for( double i=1; i<=n; i++ ){
                double f;
                string name;
                cin>>f>>name;
                double q=f*i/n;
                songs.insert(make_pair(q,name));
                if( songs.size()>m ){
                        multimap<double,string>::iterator it = songs.end();
                        it--;
                        songs.erase(it);
                }
        }

        for( multimap<double,string>::iterator it=songs.begin(); it!=songs.end(); it++ ){
                cout<<it->second<<endl;
        }
}

