class Movie{
    
    public:
    
    // vector will be of size 2
    // v[0] = price
    // v[1] = shop
    set<vector<int>> shops;
    
    //key = shop
    //value = iterator pointing to shop in shops
    unordered_map<int,set<vector<int>>::iterator> map;
    
    //key = shop
    //value = price
    unordered_map<int,int> rentedMoviesPrice;
    
    Movie()
    {
        
    }
    
    vector<int> CheapestFiveShops(){
        
        vector<int> ans;
        
        int i = 0;
        for(vector<int> v : shops){
            
            ans.push_back(v[1]);
            
            if(++i == 5)
                break;
        }
        
        return ans;
    }
    
    void AddShop(int shop, int price){
        
        pair<set<vector<int>>::iterator,bool> ret;
        
        ret = shops.insert({price, shop});
        
        map[shop] = ret.first;
    }
    
    void RemoveShop(int shop){
        
        auto itr = map[shop];
        rentedMoviesPrice[shop] = (*itr).front();
        
        shops.erase(itr);
        
        
    }
    
    int Price(int shop){
        
        return rentedMoviesPrice[shop];
    }
};


class MovieRentingSystem 
{
    
    unordered_map<int,Movie> movieMap;
    
    // vector is of size 3
    // v[0] = price , v[1] = shop, v[2] = movie
    set<vector<int>> rentedMovies;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
          
        for(vector<int> &v : entries){
            
            if(!movieMap.count(v[1])){
                movieMap[v[1]] = Movie();
            }
            
            movieMap[v[1]].AddShop(v[0], v[2]);
        }
    }
    
    vector<int> search(int movie) {
        
        return movieMap[movie].CheapestFiveShops();
    }
    
    void rent(int shop, int movie) {
        
        movieMap[movie].RemoveShop(shop);
        
        int price = movieMap[movie].Price(shop);
        rentedMovies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        
        int price = movieMap[movie].Price(shop);
        
        movieMap[movie].AddShop(shop, price);
        
        vector<int> v = {price, shop, movie};
        
        rentedMovies.erase(v);
    }
    
    vector<vector<int>> report() {
        
        vector<vector<int>> ans;
        
        int i = 0;
        
        for(const vector<int> &v : rentedMovies){
            
            ans.push_back({v[1], v[2]});
            
            if(++i == 5)
                break;
        }
        
        return ans;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */