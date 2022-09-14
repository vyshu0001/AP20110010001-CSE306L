%{
  int v=0,c=0;
%}

%%
[aeiouAEIOU] ++v;
[a-zA-Z] ++c;
%%
main()
{
  yylex();
  printf("vowels are : %d",v);
  printf("consonants are :%d",c);
}
int yywrap()
{
 return 1;
}