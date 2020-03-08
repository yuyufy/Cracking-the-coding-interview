#include <iostream>
#include <string>

using namespace std;

void all_parentheses(int count, int opened, int closed, string arangement)
{
    if(closed>opened) return;
    if(opened>count) return;
    else if(arangement.size()==2*count)
      cout<<arangement<<endl;
    all_parentheses(count, opened+1, closed, arangement+"(");
   all_parentheses(count, opened, closed+1, arangement+")");
}

void print_all_parentheses(int count){
  all_parentheses(count, 0, 0, "");
}

int main(int argc, const char* argv[]) {
  print_all_parentheses(3);
  return 0;
}
