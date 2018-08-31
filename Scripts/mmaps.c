//Author: mgood7123 (Matthew James Good) http://github.com/mgood7123

#include "Garbage_Collector/gc.h"
#ifndef __APPLE__
#error unsupported OS, this currently only supports Apple ios/macosx
#endif
#include <stdio.h>
#include <stdlib.h>
#include <mach/mach.h>
#include <unistd.h>

char * csize(int *print_size) {
	// crappy implimentation
	char *print_size_unit = "B";
	if (*print_size > 1024) { *print_size /= 1024; print_size_unit = "K"; }
	if (*print_size > 1024) { *print_size /= 1024; print_size_unit = "M"; }
	if (*print_size > 1024) { *print_size /= 1024; print_size_unit = "G"; }
	return print_size_unit;
}

char * protection_bits_to_rwx (vm_prot_t p)
{

  // previous version of this somehow lost the "p&", always returning rwx..
  static char returned[4];

  returned[0] = (p &VM_PROT_READ    ? 'r' : '-');
  returned[1] = (p &VM_PROT_WRITE   ? 'w' : '-');
  returned[2] = (p & VM_PROT_EXECUTE ? 'x' : '-');
  returned[3] = '\0';

 // memory leak here. No biggy
  return (strdup(returned));
}

const char * unparse_inheritance (vm_inherit_t i)
{
  switch (i)
    {
    case VM_INHERIT_SHARE:
      return "share";
    case VM_INHERIT_COPY:
      return "copy";
    case VM_INHERIT_NONE:
      return "none";
    default:
      return "???";
    }
}

void maps_self() {
	mach_port_t task = mach_task_self();
	kern_return_t kret;
	
	vm_region_basic_info_data_t info, pinfo;
	vm_size_t size, psize, sizet, fullSize;
	mach_vm_address_t address = 1, paddress = 1;
	void * addr, *paddr;
	mach_port_t object_name;
	mach_msg_type_number_t count;
	vm_address_t firstRegionBegin, lastRegionEnd;
	count = VM_REGION_BASIC_INFO_COUNT_64;
	int regionCount, flag;
	kret = vm_region(task, &address, &psize, VM_REGION_BASIC_INFO, (vm_region_info_t) &info, &count, &object_name);
	paddr = address;
	while (kret == KERN_SUCCESS)
   	{
   		memcpy (&pinfo, &info, sizeof (vm_region_basic_info_data_t));
   		kret = vm_region(task, &address, &size, VM_REGION_BASIC_INFO, (vm_region_info_t) &info, &count, &object_name);
   		// vm_region(vm_map_t target_task, vm_address_t *address, vm_size_t *size, vm_region_flavor_t flavor, vm_region_info_t info, mach_msg_type_number_t *infoCnt, mach_port_t *object_name);
   		if (regionCount == 0)
   		{
   			firstRegionBegin = address;
   		}
   		fullSize += size;
   		address += size;
   		addr = address;
   		sizet += size;
   		int	print_size, tprint_size;
   		print_size = size;
   		tprint_size = sizet;
	    char *print_size_unit = csize(&print_size);
   		char *tprint_size_unit = csize(&tprint_size);
   		printf("region: %04d, %014p (prot: %s, max prot: %s, %8s, %8s, %8s) - \n              %014p (prot: %s, max prot: %s, %8s, %8s, %8s) (%4d%s) (%4d%s total) \n", regionCount, paddr, protection_bits_to_rwx (pinfo.protection), protection_bits_to_rwx (pinfo.max_protection), unparse_inheritance (pinfo.inheritance), pinfo.shared ? "shared" : "private", pinfo.reserved ? "reserved" : "not-reserved", addr,protection_bits_to_rwx (info.protection), protection_bits_to_rwx (info.max_protection), unparse_inheritance (info.inheritance), info.shared ? "shared" : "private", info.reserved ? "reserved" : "not-reserved", print_size, print_size_unit, tprint_size, tprint_size_unit);
   		/*
region: 2196, 0x000042c04000 (prot: rw-, max prot: rwx,     copy,  private, not-reserved) - 
              0x000042c06000 (prot: ---, max prot: rwx,     copy,  private, not-reserved) (   8K) (   1G total) 
lowest = 0x00004fbb9ffc
diff = 0x00000d001ffc
   		*/
   		regionCount++;
   		paddr = address;
   		psize = size;
   	}
   	lastRegionEnd = address;
   	int	print_size;
   	print_size = fullSize;
   	char *print_size_unit = csize(&print_size);
	
    printf("firstRegionBegin:  %014p\n", firstRegionBegin);
    printf("lastRegionEnd:     %014p\n", lastRegionEnd);
}

int main(void) {
	maps_self();
	printf("main =             %014p\n", main);
	printf("sbrk =             %014p\n", sbrk(0));
	Garbage_Collector_Shutdown();
	return 0;
}
