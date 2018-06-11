#include <cstdio>
#include <list>

const int Nmax = (int)1.01e5;
const int Qmax = (int)1.01e5;
const int Cmax = (int)1.01e6;
inline int read()
{
    int data=0;char ch;
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9')
    {
        data=data*10+ch-'0';
        ch=getchar();
    }
    return data;
}
struct list {
  struct node {
    int v;
    node*next;
  };
  node*f;
  unsigned int size_;
  list():f(0), size_(0u){};
  unsigned int size() { return size_;};
  int front() { return f->v;};
  void pop_front() {
    node*s = f;
    f = f->next;
    delete s;
    size_--;
  };
  void push_front(const int&v) {
    node*new_node = new node;
    new_node->v = v;
    new_node->next = f;
    f = new_node;
    size_++;
  };
  void clear() { f = (node*)0;
    size_ = 0u;}
};

int C[Cmax];
int A[Nmax];
list F[Cmax];
int N, Q;

int sum[Nmax];
bool isdifferent[Nmax];

int lowbit(const int&a)
{
  return a&(-a);
}

void add(int o, const int&v) 
{
  while(o <= N) {
    sum[o] += v;
    o += lowbit(o);
  }
}



int suffixsum(int o) 
{
  int ans = 0;
  while(o > 0) {
    ans += sum[o];
    o -= lowbit(o);
  }
  return ans;
}

void solve() 
{
  N=read();Q=read();
  for(int i = 1; i <= 1000000; ++i) F[i].clear();
  for(int i = 1; i <= 1000000; ++i) C[i] = i;
  for(int i = 1; i <= N; ++i) sum[i] = 0;

  for(int i = 1; i <= N; ++i) 
  {
    A[i]=read();
    F[C[A[i]]].push_front(i);
    if(isdifferent[i] = (A[i] != A[i-1])) add(i, 1);
  }

  for(int t = 1; t <= Q; ++t) 
  {
    int op, x, y;
    op=read();x=read();y=read();
    if(op == 1) 
    {
      if(x == y) continue;
      if(F[C[x]].size() <= F[C[y]].size()) 
      {
        while(F[C[x]].size() > 0u) 
        {
          const int o = F[C[x]].front(); 
          F[C[x]].pop_front(); 
          F[C[y]].push_front(o); 
          A[o] = C[y];
          if(A[o] == A[o-1] && isdifferent[o]) 
          {
            add(o, -1);
            isdifferent[o] = false;
          }
          if(A[o] == A[o+1] && isdifferent[o+1]) 
          {
            add(o+1, -1);
            isdifferent[o+1] = false;
          }
        }
      } else 
      {
        while(F[C[y]].size() > 0u) 
        {
          const int o = F[C[y]].front();
          F[C[y]].pop_front();
          F[C[x]].push_front(o);
          A[o] = C[x];
          if(A[o] == A[o-1] && isdifferent[o]) 
          {
            add(o, -1);
            isdifferent[o] = false;
          }
          if(A[o] == A[o+1] && isdifferent[o+1]) 
          {
            add(o+1, -1);
            isdifferent[o+1] = false;
          }
        }
        std::swap(C[x], C[y]);
      }
    }
     else 
    {
      printf("%d\n", suffixsum(y)-suffixsum(x)+1);
    }
  }
}

int main() 
{
  int T;
  T=read();
  while(T--) solve();
  return 0;
}