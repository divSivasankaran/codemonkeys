#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class node
{
    public:
    int id;
    node* next;
    node(int n);
};
node::node(int n) {
    id=n;
    next=NULL;
}

class Graph {
    public:
        int number;
        vector<node*>alist;
        vector<node*>ptrlist;
        Graph(int n) {
            number=n;
            for (int i = 0 ; i < number ; i++) {
                alist.push_back(NULL);
                ptrlist.push_back(NULL);
            }
        }
    
        void add_edge(int u, int v) {
            if (alist[u]==NULL) {
                node *newNode = new node(v);
                alist[u]=newNode;
                ptrlist[u]=newNode;
                //cout<<"n"<<u<<"->"<<ptrlist[u]->id<<"\n";
            }
            else if ( ptrlist[u]!=NULL && ptrlist[u]->next==NULL) {
                node* newNode = new node(v);
                ptrlist[u]->next=newNode;
                //cout<<ptrlist[u]->id<<"->";
                ptrlist[u]=newNode;
                //cout<<ptrlist[u]->id<<"\n";
            }
            //cout<<"\n logical error somewhere";
            
        }
    
        vector<int> shortest_reach(int start) {
            std::queue<int> myqueue;
            vector<int>distance(number);
            int currentDistance=0;
            for (int i = 0 ; i<number ; i++) {
                distance[i]=-1;
            }
            bool startDone=false;
            myqueue.push(start);
            myqueue.push(-1);
            distance[start]=0;
            while (!myqueue.empty()) {
                int token=myqueue.front();
                myqueue.pop();
               // cout<<"\n popped "<<token;
                if ( token < 0 ) {
                    if (myqueue.empty()) break;
                    myqueue.push(token-1);
                    currentDistance=(-6)*(token);
                    //cout<<"\npushing "<<token-1;
                    continue;
                }
                //cout<<"\n distance is "<<distance[token];
                if (token==start && startDone) continue;
                if (token==start) startDone=true;
                if ( distance[token]>0) {
                    continue;
                }
                node* ptr=alist[token];
                while(ptr) {
                    myqueue.push(ptr->id);
                   // cout<<"\npushing "<<ptr->id;
                    ptr=ptr->next;
                }
                
                distance[token]=currentDistance; 
                //cout<<"\ndistance at the end is "<<distance[token];
            }
            return distance;
            
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
            graph.add_edge(v, u);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}