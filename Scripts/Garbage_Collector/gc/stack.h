#ifndef __APPLE__
#warning unsupported OS, this currently only supports Apple ios/macosx, full stack scanning will be disabled
#else
#include <stdio.h>
#include <stdlib.h>
#include <mach/mach.h>
#include <unistd.h>

void * stack_start = NULL;
void * find_stack(void * taddr) {
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
	void * diff = NULL;
	void * diff_last = NULL;
	while (kret == KERN_SUCCESS)
   	{
   		memcpy (&pinfo, &info, sizeof (vm_region_basic_info_data_t));
   		kret = vm_region(task, &address, &size, VM_REGION_BASIC_INFO, (vm_region_info_t) &info, &count, &object_name);
   		address += size;
   		addr = address;
   		diff_last = diff;
	   	if (addr > taddr) diff = addr - taddr;
   		else diff = taddr - addr;
   		if (diff < diff_last) stack_start = paddr;
   		paddr = address;
   	}
   	printf("stack_start = %014p\n", stack_start);
   	return stack_start;
}

#endif
