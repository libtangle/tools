#include "ast.h"
#include <iostream>

extern RootNode* root_node;
extern int yyparse();

void print_tree(RootNode* root_node)
{
    std::cout << &root_node->statements << std::endl;
}

int main(int argc, char** argv)
{
    yyparse();
    print_tree(root_node);
    return 0;
}