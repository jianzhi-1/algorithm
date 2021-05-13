ll n, memo[300005], m[300009], c[300009];
//memo[] stores the DP array
//m[] stores the gradient array
//c[] stores the y-intercept array
deque<pair<long double,ll> > dq;

ll query(ll x){
    while(sz(dq) > 1){
        if(x>=dq[1].first) dq.pop_front();//remove useless lines
        else break;
    }
    return m[dq.front().second]*x+c[dq.front().second];
}

long double intersection(ll x,ll y){//intersection of line x and y
    return (long double)(c[y]-c[x])/(m[x]-m[y]);
}

void insert(ll x){//insert line with id of x
    while(sz(dq)){
        if(intersection(dq.back().second,x) <= dq.back().first) dq.pop_back();//removes useless lines
        else break;
    }
    dq.PB(MP(intersection(dq.back().second, x),x));
}

ll dp(ll x){
    ll answer = p(x) + query(f(x));
    m[x] = m(x);   //gradient of the line must be increasing
    c[x] = c(x);   //y intercept
    insert(x);   //inserts this line
    return memo[x] = answer;
}

int main(){
    memset(memo, -1, sizeof(memo));
    REP(i, 0, n){
        if (i == 0){
            //sets up your base case
            m[i] = m(0);
            c[i] = c(0);
            dq.PB(MP(-inf, 0));
            memo[i] = dp(0); //calculate manually the value of dp(0)
            continue;
        }
        memo[i] = dp(i);
    }
}
