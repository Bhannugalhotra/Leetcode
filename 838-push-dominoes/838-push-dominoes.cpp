class Solution {
public:
    string pushDominoes(string dominoes)
    {
        dominoes = 'L' + dominoes + 'R';
        
        int prev_idx = 0;
        
        for(int i = 0; i < dominoes.size(); i++)
        {
            if(dominoes[i] == '.')
                continue;
            
            if(dominoes[i] == 'R' && dominoes[prev_idx] == 'L')
                prev_idx = i;
            
            else if(dominoes[i] == dominoes[prev_idx])
                for(int j = prev_idx + 1; j < i; j++)
                    dominoes[j] = dominoes[i];
            
            else
                for(int l = prev_idx+1, r = i - 1; l < r; l++,r--)
                    dominoes[l] = 'R' , dominoes[r] = 'L';
            
            prev_idx = i;
            
        }
        
        return {++dominoes.begin(),--dominoes.end()};
    }
};