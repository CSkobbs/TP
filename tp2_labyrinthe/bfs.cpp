int BFS(int s)
{
    int visited[V]={0};
    queue<int> Q;
    visited[s]=1;
    Q.push(s);
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop(); // pop here. we have x now

        vector<list<int> >::iterator it1=a.begin()+x;
        list<int> it2=*it1;
        list<int>::iterator iter=it2.begin();
        while(iter!=it2.end())
        {
            if(visited[*iter]==0)
            {
                visited[*iter]=1;
                Q.push(*iter);
            }
            ++iter;
        }

        visited[x]=2; // set visited here.
    }
    return 0;
}