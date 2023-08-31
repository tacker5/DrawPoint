#include "Draw.hpp"

vpoint input(){
    vpoint p;
    int number;
A:
    std::cout << "how many points: ";
    std::cin >> number;
    if (number < 0)
        goto A;
    else if (!number)
        exit(0);
    point temp;
    for(int i = 1; i <= number; i++){
        do {
            std::cout << "enter " << i << " x: ";
            std::cin >> temp.second;
            std::cout << "enter " << i << " y: ";
            std::cin >> temp.first;
        } while (temp.first < 1 || temp.second < 1);
        p.push_back(temp);
    }
    sort(p);
    return p;
}

void draw(vpoint p){
    int Maxf = p.at(0).first;
    int Maxs = maxs(p);
    int *ha = hashs(p, Maxf);
    for (int i = -1, c = 0; i < Maxf; i++) {
        std::cout << Maxf-i << "|";
        for(int j = 0; j < Maxs && c < p.size() && ha[c] == i;){
            if(p.at(c).second == ++j){
                std::cout << " *";
                c++;
            } else
                std::cout << "  ";
        }
            std::cout << std::endl;
    }
    for(int j : {0, 1}){
        std::cout << "  ";
        for(int i = 1; i <= Maxs+1; i++)
            if(!j)
                std::cout << "__";
            else
                std::cout << " " << i;
        std::cout << std::endl;
    }
    delete [] ha;
}

int maxs(vpoint p){
    int max = p.at(0).second;
    for(int i = 1; i < p.size(); i++)
        if(p.at(i).second > max)
            max = p.at(i).second;
    return max;
}

void sort(vpoint &p){
    int n = p.size();
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < n-1; j++)
            if ((p.at(j).first == p.at(j+1).first && p.at(j).second > p.at(j+1).second) || (p.at(j).first < p.at(j+1).first))
                std::swap(p.at(j), p.at(j+1));
}

int *hashs(vpoint p, int maxf){
    int *Array = new int[p.size()];
    for(int i = 0; i < p.size(); i++)
        Array[i] = maxf - p.at(i).first;
    return Array;
}
