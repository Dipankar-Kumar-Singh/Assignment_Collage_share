
#include "bits/stdc++.h" 
using namespace std ;

const int N = 1e5 ;

vector<int> Graph [N] ;
vector<bool> vis ; 


void dfs(int node )
{
    if(vis[node]) return ;
    vis[node] = 1 ;

    cout << "\t" << node << "\n" ;

    for(auto &child : Graph[node])
    {
        dfs(child) ;
    }

}


void bfs(int node)
{
    queue<int> q ;
    q.push(node) ;
    
    while (!q.empty())
    {
        int ver = q.front() ; q.pop() ;
        cout << "\t" << ver << "\n" ;
        vis[ver] = 1 ;
        for(auto &child : Graph[ver])
        {   
            if(!vis[child])   q.push(child) ;
        }
    }
}

int main()
{

    while (1)
    {   
        cout << "\n-----------------------------\n" ;

        cout << "\n\nChose option : \n\n" ;
        cout << "1.Build Graph \n" 
             << "2.Traverse graph\n"           
             << "3.EXIT \n";

        int option {} ;

        cin >> option ;

        if(option == 1)
        {

            cout << "\nHow Much Node ? : " ; 
            int n ; cin >> n  ;
            cout << "\nHow much Edges ? : " ;
            int m ; cin >> m ; 

            cout << "\n" ;

            vis.resize(n,0) ;

            bool is_Bidirectional = 1 ;

            cout << "Is graph contains BiDirectional Edges ? :\n [ 1 ]  YES\n [ 0 ]   NO\n" ;
            cin >> is_Bidirectional ; 


            while (m--)
            {   
                int x , y ; 
                cout << "\nInput Node 1  " ;
                cin >> x ;
                cout << "\nInput Node 2  " ;
                cin >> y  ; 

                cout << "\n" ;
               
                if(!is_Bidirectional) 
                {
                    Graph[x].push_back(y) ;
                }
                else 
                {
                    Graph[x].push_back(y) ;
                    Graph[y].push_back(x) ; 
                }
            }


        }

        else if(option == 2)
        {   
            cout << "\n ENTER THE STARTING NODE : " ;
            int start_node ; cin >> start_node ;


            cout << "\n\tCHOSE METHOD : " ;
            cout << "\n\t[ 1 ]  DFS \n\t[ 2 ] BFS" ;

            int op ; cin >> op ;

            if(op==1)
            {   
                cout << "\n----------------- START ----------------\n\n" ;
                dfs(start_node) ;
                cout << "\n------------------ END -----------------\n" ;
            }

            else {
                cout << "\n----------------- START ----------------\n\n" ;
                bfs(start_node) ;
                cout << "\n------------------ END -----------------\n" ;
            }
        
        }

        else {
            break ;
            return 0 ;
        }

    }
    
}