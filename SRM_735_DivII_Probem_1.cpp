// code_report
// https://youtu.be/dG6RdmnJSuw

int minimumSteps (int a, int b) 
{
   int c = 0;
   while (a != b) a += a < b ? 3 : -2, c++;
   return c;
}
