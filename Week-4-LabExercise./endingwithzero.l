%%
[0-9]*00 {printf("String Aceepted");}
[0-9]* {printf("String Rejected");}
%%
main()
{
  yylex();
}
int yywrap()
{
 return 1;
}