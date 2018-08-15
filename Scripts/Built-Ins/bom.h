#pragma once

#include "hex.h"

struct BOM {
	int is_BOM;
	int length;
	int type;
	char * type_as_string;
	char * BOM;
}

int matches(char * BOM_, char * string_, int length_) {
	char * b = BOM_+1;
	for(int i = 0; i < length_; i++) {
		if (string_[i] == b[i]) matches = 1;
		else {
			matches = 0;
			break;
		}
	}
	return matches;
}

#define ifbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_, string_) if (matches(BOM_, string_, length_)) { \
	bom_struct.is_BOM = is_BOM_; \
	bom_struct.length = length_; \
	bom_struct.type = type_; \
	bom_struct.type_as_string = type_as_string_; \
	bom_struct.BOM = BOM_+1 /* remove the ^ at the start */ ; \
}

#define elifbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_, string_) else ifbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_, string_)

#define elbom(bom_struct, is_BOM_, length_, type_, type_as_string_, BOM_) else { \
	bom_struct.is_BOM = is_BOM_; \
	bom_struct.length = length_; \
	bom_struct.type = type_; \
	bom_struct.type_as_string = type_as_string_; \
	bom_struct.BOM = BOM_; \
}

#define builtin__BOM_print(bom_struct) { \
	printf("%s.is_BOM = %s\n%s.length = %d\n%s.type = %d\n%s.type_as_string = %s\n%s.BOM = ", #bom_struct, bom_struct.is_BOM?"yes":"no", #bom_struct, bom_struct.length, #bom_struct, bom_struct.type, #bom_struct,bom_struct.type_as_string, #bom_struct); \
	mode = mode_both; \
	__hexdump_string(bom_struct.BOM, 0,bom_struct.length, 5); \
}


struct BOM builtin__BOM_get(char * string) {
	struct BOM bom;
	ifbom(bom, true, 3, 1, "UTF-8", "^\xef\xbb\xbf", string)
	elifbom(bom, true, 2, 2, "UTF-16 (BE)", "^\xfe\xff", string)
	elifbom(bom, true, 2, 3, "UTF-16 (LE)", "^\xff\xfe", string)
	elifbom(bom, true, 4, 4, "UTF-32 (BE)", "^\x00\x00\xfe\xff", string)
	elifbom(bom, true, 4, 5, "UTF-32 (LE)", "^\xff\xfe\x00\x00", string)
	elifbom(bom, true, 5, 6, "UTF-7", "^\x2b\x2f\x76\x38\x3d", string)
	elifbom(bom, true, 4, 7, "UTF-7", "^\x2b\x2f\x76\x38", string)
	elifbom(bom, true, 4, 8, "UTF-7", "^\x2b\x2f\x76\x39", string)
	elifbom(bom, true, 4, 9, "UTF-7", "^\x2b\x2f\x76\x2b", string)
	elifbom(bom, true, 4, 10, "UTF-7", "^\x2b\x2f\x76\x2f", string)
	elifbom(bom, true, 3, 11, "UTF-1", "^\xf7\x64\x4c", string)
	elifbom(bom, true, 4, 12, "UTF-EBCDIC", "^\xdd\x73\x66\x73", string)
	elifbom(bom, true, 3, 13, "SCSU", "^\x0e\xfe\xff", string)
	elifbom(bom, true, 3, 14, "BOCU-1", "^\xfb\xee\x28", string)
	elifbom(bom, true, 4, 15, "GB-18030", "^\x84\x31\x95\x33", string)
	elbom(bom, false, 0, 0, "Not present", "Not present")
	
	return (struct BOM) bom;
}
