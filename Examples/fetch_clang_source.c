//Authors : Lee Jeong Seop

//This program checkouts clang/llvm/cxx repository to Mobile C local folder.

//Visit https://clang.llvm.org/get_started.html for more information.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Warning : It requires ~200MB storage and network traffic.\n");
	printf("Continue (Y/N)? ");
	char c;
	scanf("%c", &c);
	if(c != 'y' && c != 'Y')
		return 0;
	
	//Check out LLVM:
	//system("svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm");
	
	//Check out Clang:
	//system("cd llvm/tools");
	system("svn co http://llvm.org/svn/llvm-project/cfe/trunk clang");
	//system("cd ../..");
	
	//Check out extra Clang tools: (optional)
	//system("cd llvm/tools/clang/tools");
	//system("svn co http://llvm.org/svn/llvm-project/clang-tools-extra/trunk extra");
	//system("cd ../../../..");
	
	//Check out Compiler-RT (optional):
	//system("cd llvm/projects");
	//system("svn co http://llvm.org/svn/llvm-project/compiler-rt/trunk compiler-rt");
	//system("cd ../..");
	
	//Check out libcxx: (only required to build and run Compiler-RT tests on OS X, optional otherwise)
	//system("cd llvm/projects");
	//system("svn co http://llvm.org/svn/llvm-project/libcxx/trunk libcxx");
	//system("cd ../..");
	
	return 0;
}
