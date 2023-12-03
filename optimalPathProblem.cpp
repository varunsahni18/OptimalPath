#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, int> travllingSalesmanProblem(vector<vector<int>> graph, int V, int s)
{
    vector<int> vertex;
    vector<int> shortestPath;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        if(current_pathweight < min_path){
            min_path = current_pathweight;
            shortestPath = vertex;
        }
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return {shortestPath, min_path};
}
 
// Driver Code
int main()
{
    freopen("input.txt", "r", stdin);
    //to get the output in a file, uncomment the below line
    // freopen("output.txt", "w", stdout);

    int numberOfCities;
    cin>>numberOfCities;
    string Source;
    cin>>Source;
    unordered_map<string, int> cityToIndex;
    unordered_map<int, string> indexToCity;
    cityToIndex[Source] = 0;
    indexToCity[0] = Source;
    for (int i = 1; i < numberOfCities; i++)
    {
        string city;
        cin>>city;
        cityToIndex[city] = i;
        indexToCity[i] = city;
    }
    int numberOfEdges;
    cin>>numberOfEdges;
    vector<vector<int>> graph(numberOfCities, vector<int>(numberOfCities, INT_MAX));
    for (int i = 0; i < numberOfEdges; i++)
    {
        string city1, city2;
        int distance;
        cin>>city1>>city2>>distance;
        graph[cityToIndex[city1]][cityToIndex[city2]] = distance;
        graph[cityToIndex[city2]][cityToIndex[city1]] = distance;
    }
    pair<vector<int>, int> result = travllingSalesmanProblem(graph, numberOfCities, 0);
    cout<<"Shortest Path: "<<Source<<" ";
    for (int i = 0; i < result.first.size(); i++)
    {
        cout<<indexToCity[result.first[i]]<<" ";
    }
    cout<<Source<<endl;
    cout<<"Shortest Distance: "<<result.second<<endl;    
    return 0;
}