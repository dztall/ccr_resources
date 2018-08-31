#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/machine.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
struct cpu {
	cpu_type_t type;
	size_t typesize;
	cpu_subtype_t subtype;
	size_t subtypesize;
    cpu_threadtype_t threadtype;
	size_t threadtypesize;
} cpu;
void getCPUType(void)
{
    cpu.typesize = sizeof(cpu.type);
    sysctlbyname("hw.cputype", &cpu.type, &cpu.typesize, NULL, 0);

    cpu.subtypesize = sizeof(cpu.subtype);
    sysctlbyname("hw.cpusubtype", &cpu.subtype, &cpu.subtypesize, NULL, 0);
    
    cpu.threadtypesize = sizeof(cpu.threadtype);
    sysctlbyname("hw.cputhreadtype", &cpu.threadtype, &cpu.threadtypesize, NULL, 0);
}

void printCPUType(struct cpu cpu) {
    // values for cputype and cpusubtype defined in mach/machine.h
    printf("cpu type: ");
    if (cpu.type == CPU_TYPE_X86) {
    	 puts("x86");
    }
    else if (cpu.type == CPU_TYPE_ARM)
    {
            puts("ARM");
            printf("cpu subtype: ");
            switch(cpu.subtype)
            {
            	case CPU_SUBTYPE_ARM_ALL:
                    	puts("ALL");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V4T:
                    	puts("V4T");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V6:
                    	puts("V6");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V5TEJ:
                    	puts("V5TEJ");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_XSCALE:
                    	puts("XSCALE");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V7:
                    	puts("V7");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V7F:
                    	puts("V7F");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V7S:
                    	puts("V7S");
            			puts("cpu profile: A");
                    	break;
            	case CPU_SUBTYPE_ARM_V7K:
                    	puts("V7K");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V7M:
                    	puts("V7M");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V7EM:
                    	puts("V7EM");
            			puts("cpu profile: Unknown");
                    	break;
            	case CPU_SUBTYPE_ARM_V8:
                    	puts("V8");
            			puts("cpu profile: Unknown");
                    	break;
            	default:
            			puts("Unknown");
            			puts("cpu profile: Unknown");
            			break;
            }
    }
    else puts("Unknown");
}
