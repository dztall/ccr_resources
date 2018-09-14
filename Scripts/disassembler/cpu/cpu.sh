rm testcpuwrite ; gcc cpu_language.c -o cpu_lang -g3 -w -lm && ./cpu_lang && xxd -b -c 8 testcpuwrite && ls -l testcpuwrite
