#include <bits/stdc++.h>

int main()
{

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> sm(N, std::vector(N, 0));
    std::vector<std::vector<int>> dist(N, std::vector<int>(N, INT_MAX));
    
    for (int v = 0; v < N; v++){
        dist[v][v] = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        int x, y, l;
        std::cin >> x >> y >> l;
        x--;
        y--;
        dist[x][y] = std::min(dist[x][y], l);
        dist[y][x] = std::min(dist[y][x], l);
    }

    for (int v = 0; v < N; v++){
        for (int a = 0; a < N; a++){
            if (dist[a][v] != INT_MAX){
                for (int b = 0; b < N; b++){
                    if (dist[v][b] != INT_MAX && dist[a][b] > dist[a][v] + dist[v][b]){
                        dist[a][b] = dist[a][v] + dist[v][b];
                        dist[b][a] = dist[a][v] + dist[v][b];
                    }
                }
            }
        }
    }
    std::vector<int> ext(N, 0);
    for(int v = 0; v < N; ++v) {
        int maxx = -INT_MAX;
        for(int a = 0; a < N; ++a) {
            //std::cout << dist[v][a] << " ";
            maxx = std::max(maxx, dist[v][a]);
        }
        //std::cout << "\n";
        ext[v] = maxx;
    }

    std::cout << "Max ext is: " << *std::max_element(ext.begin(), ext.end()) << "\n";
    std::cout << "Min ext is: " << *std::min_element(ext.begin(), ext.end()) << "\n";

    int minn = *std::min_element(ext.begin(), ext.end());

    // Printing the centers
    for(int v = 0; v < N; ++v) {
        if(ext[v] == minn) {
            std::cout << v + 1 << "\n";
            return 0;
        }
    }

    
}