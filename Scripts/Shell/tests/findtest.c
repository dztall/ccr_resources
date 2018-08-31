#include "../builtins/find.h"
#include "../builtins/printfmacro.h"

int main() {
    //find("Git/test");
    pi(find("-type f -name find.c"));
    pi(find("-type f -name find.c ../gnu"));
    pi(find("-type f ../gnu -name find.c "));
    pi(find("../gnu -type f -name find.c"));
    pi(find("-name find.c"));
    pi(find("-type f"));
    pi(find("-type d"));
    pi(find("-type d -name ./"));
    pi(find("../"));
    return 0;
}
