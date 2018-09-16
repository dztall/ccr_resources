// for if cond passed see page 287
// the APSR is described on page 49
struct APSR {
	char N;
	char Z;
	char C;
	char V;
	
	char Q;
	char RAZ_SBZP[3];
	
	char Reserved_UNK_SBZP[4];
	
	char GE[4];
	
	char Reserved_unknown_SBZP[16]; 
	
} * APSR;

void APSR_info(struct APSR * APSR) {
	puts("APSR information:");
	pc(APSR->N);
	pc(APSR->Z);
	pc(APSR->C);
	pc(APSR->V);
	pc(APSR->Q);
	psi(APSR->RAZ_SBZP,3);
	psi(APSR->Reserved_UNK_SBZP,4);
	psi(APSR->GE,4);
	psi(APSR->Reserved_unknown_SBZP,16);
}

// the CPSR is described on page 1148
struct CPSR {
	char N;
	char Z;
	char C;
	char V;
	
	char Q;
	char IT_1[2];
	char J;
	
	char Reserved_RAZ_SBZP[4];
	
	char GE[4];
	
	char IT_2[6];
	char E;
	char A;
	
	char I;
	char F;
	char T;
	char M[5];
	
} * CPSR;

void CPSR_info(struct CPSR * CPSR) {
	puts("CPSR information:");
	pc(CPSR->N);
	pc(CPSR->Z);
	pc(CPSR->C);
	pc(CPSR->V);
	pc(CPSR->Q);
	psi(CPSR->IT_1,2);
	pc(CPSR->J);
	psi(CPSR->Reserved_RAZ_SBZP,4);
	psi(CPSR->GE,4);
	psi(CPSR->IT_2,6);
	pc(CPSR->E);
	pc(CPSR->A);
	pc(CPSR->I);
	pc(CPSR->F);
	pc(CPSR->T);
	psi(CPSR->M,5);
}
