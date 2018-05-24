void Solve(LL n)    
{    
    p.clear();    
    for(LL i=2; i*i<=n; i++)    
    {    
        if(n%i==0)    
        {    
            p.push_back(i);    
            while(n%i==0) n/=i;    
        }    
    }    
    if(n>1)    
        p.push_back(n);  //这个不可以缺少  
}  