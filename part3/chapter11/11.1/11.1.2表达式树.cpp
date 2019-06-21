/*
建立表达式树：
int build(int l, int r) 返回[l, r)区间内的根{
if(l + 1 == r) 只有一个字符，建立单字符结点{
  data[++cnt] = str[l];
  lc[cnt] = rc[cnt] = 0
  return cnt;
}  
从左到右找最后计算的operator：int op1 = 0, op2 = 0
  遇左括号，++flag
  遇右括号，--flag
  遇+ - 若flag!=0 不处理； 否则 op1 = this operator
  遇* / 若flag != 0  不处理； 否则 op2 = this operator
  if(!op1) op1 = op2; 若没有加减，则用乘除 
  if(!op1)  连乘除都没有，则整个表达式两端是括号，所以+-* /被忽略了，递归处理内层
  else {
    data[++cnt] = op1
    lc[cnt] = build(l, op1);
    rc[cnt] = build(op1+1, r);
    return cnt;
  }
*/
#include<cstdio>
#include<cstring>
#include<cctype>
#define maxn 10000
int cnt;
int lc[maxn], rc[maxn];
char data[maxn], str[maxn];
int build(int l, int r){
  int op1 = 0, op2 = 0, flag = 0;
  if(l + 1 == r) {
    int u = ++cnt;
    data[u] = str[l];
    lc[u] = rc[u] = 0;
    return u;
  }  
  for(int i = l; i < r; ++i) switch(str[i]){
    case '(': ++flag; break;
    case ')': --flag; break;
    case '+': case '-': if(!flag) op1 = i; break;
    case '*': case '/': if(!flag) op2 = i; break;
  }
  if(!op1) op1 = op2;
  if(!op1) return build(l+1, r-1);  
  int u = ++cnt;
  data[u] = str[op1];
  lc[u] = build(l, op1);
  rc[u] = build(op1+1, r);
  return u; //cnt是个全局变量，很危险的东西，如果这里return cnt就错了 ，不信试试 
}
void in_order_visit(int u){
  if(!u) return;
  if((data[u] == '*' || data[u] == '/') && (data[lc[u]]=='+' || data[lc[u]] == '-')) {
    printf("(");
    in_order_visit(lc[u]);
    printf(")");
  }
  else in_order_visit(lc[u]);  
  printf("%c", data[u]);
  if((data[u] == '*' || data[u] == '/') && (data[rc[u]]=='+' || data[rc[u]] == '-')) {
    printf("(");
    in_order_visit(rc[u]);
    printf(")");
  }
  else if(data[u] == '-' && (data[rc[u]] == '-' || data[rc[u]] == '+')){
    if(data[rc[u]] == '-') data[rc[u]] = '+';
    else data[rc[u]] = '-';
    in_order_visit(rc[u]);
  }  
  else in_order_visit(rc[u]); 
}  
double calc(int u){
  if(!u) return 0.;
  if(isdigit(data[u])) return data[u] - '0';
  double c1, c2, ans;
  c1 = calc(lc[u]);
  c2 = calc(rc[u]);
  const char& o = data[u];
  switch(o){
    case '+': ans = c1 + c2; break;
    case '-': ans = c1 - c2; break;
    case '*': ans = c1 * c2; break;
    case '/': ans = c1 / c2; break;
  }  
  return ans;
}  
int main(){
  scanf("%s", str);
  cnt = 0;
  memset(lc, 0, sizeof(lc));
  memset(rc, 0, sizeof(rc));
  int root = build(0, strlen(str)); //左开右闭区间 
  in_order_visit(root); //中序遍历 , 试了一下，发现这玩意还自带去除冗余括号的功能！！ (tyvj p1840) 
  //printf("\n");
  //for(int i = 1; i <= cnt; ++i) printf("%d: [%c] lc = %d, rc = %d\n",i, data[i], lc[i], rc[i]);
  printf(" = %.2lf\n", calc(root)); //只支持一位数的运算= = 
  return 0;
}  
/*
a+b*(c-d)-e/f
*/
