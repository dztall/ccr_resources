// line 3923
#ifdef LEMONEX
#define LXCLASS_LETTER 1
#define LXCLASS_DIGIT 2
#define LXCLASS_WORD 3
#define LXCLASS_SPACE 4
#define LXCLASS_DOT 5
#define LXCLASS_LAST (LXCLASS_DOT)

#define MASKBITS   0x3F
#define MASK1BYTES 0x80
#define MASK2BYTES 0xC0
#define MASK3BYTES 0xE0
#define MASK4BYTES 0xF0
#define MASK5BYTES 0xF8
#define MASK6BYTES 0xFC

/* read one utf8 char */
int lxUtf8_nextchar(const char *p, int *offset) {
	int ch = 0;
	*offset = 0;

	if(*p == 0) {
		// error
	} else if((*p & MASK6BYTES) == MASK6BYTES) {
		// 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
		ch = ((*p & 0x01) << 30) | ( (*(p+1) & MASKBITS) << 24) | ( (*(p+2) & MASKBITS) << 18) | ( (*(p+3) & MASKBITS) << 12) | ( (*(p+4) & MASKBITS) << 6) | (*(p+5) & MASKBITS);
		*offset = 6;
	} else if((*p & MASK5BYTES) == MASK5BYTES) {
		// 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
		ch = ((*p & 0x03) << 24) | ( (*(p+1) & MASKBITS) << 18) | ( (*(p+2) & MASKBITS) << 12) | ( (*(p+3) & MASKBITS) << 6) | (*(p+4) & MASKBITS);
		*offset = 5;
	} else if((*p & MASK4BYTES) == MASK4BYTES) {
		// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		ch = ((*p & 0x07) << 18) | ( (*(p+1) & MASKBITS) << 12) | ( (*(p+2) & MASKBITS) << 6) | (*(p+3) & MASKBITS);
		*offset = 4;
	} else if((*p & MASK3BYTES) == MASK3BYTES) {
		// 1110xxxx 10xxxxxx 10xxxxxx
		ch = ((*p & 0x0F) << 12) | ( (*(p+1) & MASKBITS) << 6) | (*(p+2) & MASKBITS);
		*offset = 3;
	} else if((*p & MASK2BYTES) == MASK2BYTES) {
		// 110xxxxx 10xxxxxx
		ch = ((*p & 0x1F) << 6) | (*(p+1) & MASKBITS);
		*offset = 2;
	} else {
		// 0xxxxxxx
		ch = (*p & 0xff);
		*offset = 1;
	}

	return ch;
}

/* convert unicode to utf8 */
int lxUtf8_str(int ch, int display_mode, char *p) {
	// 0b1xxxxx
	if((display_mode == 1) && (ch < 0x20)) {
		*(p++) = '0';
		*(p++) = 'x';
		char c1;
		c1 = (ch >> 4) & 0x0f;
		if(c1 >= 10) {
			c1 += ('a' - 10);
		}else{
			c1 += '0';
		}
		*(p++) = c1;
		c1 = ch & 0x0f;
		if(c1 >= 10) {
			c1 += ('a' - 10);
		}else{
			c1 += '0';
		}
		*(p++) = c1;
		return 4;
	}
	// 0xxxxxxx
	else if(ch < 0x80) {
		*(p++) = (char)(ch);
		return 1;
	}
	// 110xxxxx 10xxxxxx
	else if(ch < 0x800) {
		*(p++) = (char)(MASK2BYTES | (ch >> 6));
		*(p++) = (char)(MASK1BYTES | (ch & MASKBITS));
		return 2;
	}
	// 1110xxxx 10xxxxxx 10xxxxxx
	else if(ch < 0x10000) {
		*(p++) = (char)(MASK3BYTES | (ch >> 12));
		*(p++) = (char)(MASK1BYTES | (ch >> 6 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch & MASKBITS));
		return 3;
	}
	// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
	else if(ch < 0x200000) {
		*(p++) = (char)(MASK4BYTES | (ch >> 18));
		*(p++) = (char)(MASK1BYTES | (ch >> 12 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch >> 6 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch & MASKBITS));
		return 4;
	}
	// 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
	else if(ch < 0x4000000) {
		*(p++) = (char)(MASK5BYTES | (ch >> 24));
		*(p++) = (char)(MASK1BYTES | (ch >> 18 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch >> 12 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch >> 6 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch & MASKBITS));
		return 5;
	}
	// 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
	else if(ch < 0x8000000) {
		*(p++) = (char)(MASK6BYTES | (ch >> 30));
		*(p++) = (char)(MASK1BYTES | (ch >> 18 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch >> 12 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch >> 6 & MASKBITS));
		*(p++) = (char)(MASK1BYTES | (ch & MASKBITS));
		return 6;
	}
	printf("INTERNAL ERROR: Malformed unicode character: %d\n", ch);
	exit(1);
}

int lx_lookahead(struct LxScanner *s){
// printf("LA:%d(%c)\n", *(s->p), *(s->p));
	if(s->ch == 0){
		s->ch = lxUtf8_nextchar(s->p, &(s->offset));
	}
	return s->ch;
}

void lx_advance(struct LxScanner *s){
// printf("CONSUME: %d(%c)\n", *(s->p), *(s->p));
	(s->p) += s->offset;
	s->ch = 0;
	s->offset = 0;
}

/* search for existing lexer mode */
struct LxMode *LxMode_find(struct lemon *lemp, const char *mode_name){
	struct LxMode *new_mode = 0;

	new_mode = lemp->headmode;
	while(new_mode != 0){
		if((new_mode->name == 0) && (mode_name == 0)){
			return new_mode;
		}
		if(strcmp(new_mode->name, mode_name) == 0){
			return new_mode;
		}
		new_mode = new_mode->next_mode;
	}

	return 0;
}
int is_current_state_a_variable = 0;
char * is_current_state_a_variable_name = NULL;
int is_current_state_a_variable_index = -1;
char * is_current_state_mode = NULL;

/* add new lexer mode */
struct LxState *LxState_create(struct pstate *psp){
	struct LxState *new_state = (struct LxState *)malloc(sizeof(struct LxState));
	new_state->state_id = ++(psp->next_lxstate_id);
	new_state->is_leaf = 0;
	new_state->is_loop_head = 0;
	new_state->is_loop_enter = 0;
	new_state->is_loop_return = 0;
	new_state->is_processed = 0;
	new_state->matchedsym = 0;
	new_state->init_mode = 0;
	new_state->next_mode = 0;
	new_state->code = 0;
	new_state->star_state = 0;
	new_state->drop_state = 0;
	new_state->goto_state = 0;
	new_state->not_transition = 0;
	new_state->dot_transition = 0;
	new_state->head_transition = 0;
	new_state->next_state = 0;
	if(psp->last_state == 0){
		psp->first_state = new_state;
	}else{
		psp->last_state->next_state = new_state;
	}
	psp->last_state = new_state;
	return new_state;
}

struct LxTransition *LxTransition_create(struct pstate *psp, int ch0, int ch1, int is_variable, char * variable_name, int idx, char * mode, int tx_type, int is_capturing, struct LxState *next_state){
	struct LxTransition *new_transition = (struct LxTransition *)malloc(sizeof(struct LxTransition));
	new_transition->ch0 = ch0;
	new_transition->ch1 = ch1;
	new_transition->is_variable = is_variable;
	new_transition->variable_name = variable_name;
	new_transition->idx = idx;
	new_transition->mode = mode;
	new_transition->tx_type = tx_type;
	new_transition->is_drop = 0;
	new_transition->is_capturing = is_capturing;
	new_transition->is_loop_set = 0;
	new_transition->next_state = next_state;
	new_transition->next_transition = 0;
	return new_transition;
}

struct LxMode *LxMode_new(struct pstate *psp, const char *mode_name){
	struct LxMode *new_mode = LxMode_find(psp->gp, mode_name);
	if(new_mode != 0){
		return new_mode;
	}

	/* if not found, create new mode */
	new_mode = (struct LxMode*)calloc(1, sizeof(struct LxMode) );
	if(new_mode == 0){
		ErrorMsg(psp->filename,psp->tokenlineno,
			"Out of memory allocating new lexer transition.");
		psp->errorcnt++;
		return 0;
	}
	MemoryCheck(new_mode);
	new_mode->name = mode_name;
	new_mode->init_state = LxState_create(psp);
	new_mode->is_nesting = 0;
	new_mode->next_mode = 0;

	/* add it to mode list */
	if(psp->first_mode == 0){
		psp->first_mode = new_mode;
		psp->last_mode = new_mode;
	}else{
		psp->last_mode->next_mode = new_mode;
		psp->last_mode = new_mode;
	}
	return new_mode;
}

struct LxAstNode *LxNode_create(int node_type, struct LxAstNode *lhs, struct LxAstNode *rhs, int ch0, int ch1){
#if LEMONEX_DBG>=2
	puts("creating node");
	pc(ch0);
	pi(ch1);
#endif
	struct LxAstNode *node = (struct LxAstNode *)malloc(sizeof(struct LxAstNode));
	node->node_type = node_type;
	node->lhs = lhs;
	node->rhs = rhs;
	node->ch0 = ch0;
	node->ch1 = ch1;
	node->is_variable = is_current_state_a_variable;
	node->variable_name = is_current_state_a_variable_name;
	node->idx = is_current_state_a_variable_index;
	node->mode = is_current_state_mode;
	return node;
}

#if LEMONEX_DBG>=1
static void lx_print_state(FILE* out, struct LxState *curr_state){
	fprintf(out, "  printf(\"state information:\\n\\tis_leaf:%d\\n\\tcode:%p\\n\\tis_loop_head:%d\\n\\tis_loop_enter:%d\\n\\tis_loop_return:%d\\n\\tstar_state:%d\\n\\tgoto_state:%d\\n\\tdrop_state:%d\\n\\tnot_transition:%d\\n\\tdot_transition:%d\\n\\tinit_state:%d\\n\");\n"
		,curr_state->is_leaf
		,curr_state->code
		,curr_state->is_loop_head
		,curr_state->is_loop_enter
		,curr_state->is_loop_return
		,(curr_state->star_state)?curr_state->star_state->state_id:0
		,(curr_state->goto_state)?curr_state->goto_state->state_id:0
		,(curr_state->drop_state)?curr_state->drop_state->state_id:0
		,(curr_state->not_transition)?curr_state->not_transition->next_state->state_id:0
		,(curr_state->dot_transition)?curr_state->dot_transition->next_state->state_id:0
		,(curr_state->init_mode)?curr_state->init_mode->init_state->state_id:0
	);
}

static void lx_print_transition(FILE* out, struct LxState *curr_state, struct LxTransition *tx){
	fprintf(out, "  /*%d[%d(%c)-%d(%c)]->%d:tx_type:%d, is_cap:%d*/"
		, curr_state->state_id
		, tx->ch0, ((tx->ch0 >= 32) && (tx->ch0 <= 127))?tx->ch0:' '
		, tx->ch1, ((tx->ch1 >= 32) && (tx->ch1 <= 127))?tx->ch1:' '
		, tx->next_state->state_id
		, tx->tx_type
		, tx->is_capturing
	);
}
#define LX_PRINT_STATE(out, curr_state) lx_print_state(out, curr_state)
#define LX_PRINT_TRANSITION(out, curr_state, tx) lx_print_transition(out, curr_state, tx)
#else
#define LX_PRINT_STATE(out, curr_state)
#define LX_PRINT_TRANSITION(out, curr_state, tx)
#endif

static void LX_PRINT_STATE_bt(FILE* out, struct LxState *curr_state){
	fprintf(out, "  state information:\n\tis_leaf:%d\n\tcode:%p\n\tis_loop_head:%d\n\tis_loop_enter:%d\n\tis_loop_return:%d\n\tstar_state:%d\n\tgoto_state:%d\n\tdrop_state:%d\n\tnot_transition:%d\n\tdot_transition:%d\n\tinit_state:%d\n"
		,curr_state->is_leaf
		,curr_state->code
		,curr_state->is_loop_head
		,curr_state->is_loop_enter
		,curr_state->is_loop_return
		,(curr_state->star_state)?curr_state->star_state->state_id:0
		,(curr_state->goto_state)?curr_state->goto_state->state_id:0
		,(curr_state->drop_state)?curr_state->drop_state->state_id:0
		,(curr_state->not_transition)?curr_state->not_transition->next_state->state_id:0
		,(curr_state->dot_transition)?curr_state->dot_transition->next_state->state_id:0
		,(curr_state->init_mode)?curr_state->init_mode->init_state->state_id:0
	);
}

static int LxTransition_cmp(int lch0, int lch1, int ltx_type, int rch0, int rch1, int rtx_type){
	/* all DOT transitions are always at the tail of the transition list */
	if((lch0 == 0) && (lch1 == LXCLASS_DOT) && ((rch0 == 0) && (rch1 == LXCLASS_DOT))){
		return 0;
	}

	if((lch0 == 0) && (lch1 == LXCLASS_DOT)){
		return 1;
	}

	if((rch0 == 0) && (rch1 == LXCLASS_DOT)){
		return -1;
	}

	if(ltx_type < rtx_type){
		return -1;
	}
	if(ltx_type > rtx_type){
		return 1;
	}
	assert(ltx_type == rtx_type);

	/* all loop transitions are always at the head of the transition list */
	if(((lch0 != 0) || (lch1 != 0)) && ((rch0 == 0) && (rch1 == 0))){
		return -1;
	}

	/* all loop transitions are always at the head of the transition list */
	if(((lch0 == 0) && (lch1 == 0)) && ((rch0 != 0) || (rch1 != 0))){
		return 1;
	}

	/* all loop transitions are always at the head of the transition list */
	if(((lch0 == 0) && (lch1 == 0)) && ((rch0 == 0) && (rch1 == 0))){
		return 1;
	}

	assert(((lch0 != 0) || (lch1 != 0)) && ((rch0 != 0) || (rch1 != 0)));

	/* char transition is less than special-range transition */
	if((lch0 != 0) && (rch0 == 0)){
		return -1;
	}

	/* special-range transition is greater than char transition */
	if((lch0 == 0) && (rch0 != 0)){
		return 1;
	}

	/* compare special-range transition to special-range transition */
	if((lch0 == 0) && (rch0 == 0)){
		if(lch1 < rch1){
			return -1;
		}
		if(lch1 > rch1){
			return 1;
		}
		assert(lch1 == rch1);
		return 0;
	}

	/* compare range or char transition to range or char transition */
	assert((lch0 != 0) && (rch0 != 0));
	if((lch1 == 0) && (rch1 != 0)){
		return -1;
	}
	if((lch1 != 0) && (rch1 == 0)){
		return 1;
	}

	/* compare range transition to range transition */
	if((lch1 != 0) && (rch1 != 0)){
		assert(lch0 <= lch1);
		assert(rch0 <= rch1);

		/* left range is disjoint and less than right range */
		if(lch1 < rch0){
			return -1;
		}

		/* left range is disjoint and greater than right range */
		if(lch0 > rch1){
			return 1;
		}

		assert(((lch0 <= rch0) && (lch1 >= rch1)) || ((lch0 >= rch0) && (lch1 <= rch1)));
		if((lch1 - lch0) < (rch1 - rch0)){
			return -1;
		}
		if((lch1 - lch0) > (rch1 - rch0)){
			return 1;
		}
		assert((lch1 - lch0) == (rch1 - rch0));
		// fall-thru
	}
	if(lch0 < rch0){
		return -1;
	}
	if(lch0 > rch0){
		return 1;
	}
	assert(lch0 == rch0);
	assert(lch1 == rch1);
	assert(ltx_type == rtx_type);
	return 0;
}

#if LEMONEX_DBG>=2
static int LxTransition_xcmp(int lch0, int lch1, int ltx_type, int rch0, int rch1, int rtx_type){
	int rv = LxTransition_cmp(lch0, lch1, ltx_type, rch0, rch1, rtx_type);
	printf("CMP:[%d(%c)-%d(%c)/%d]:[%d(%c)-%d(%c)/%d]:%d\n"
		,lch0, lch0, lch1, lch1, ltx_type
		,rch0, rch0, rch1, rch1, rtx_type
		,rv
	);
	return rv;
}

#define LxTransition_cmp LxTransition_xcmp
#endif

static struct LxTransition *LxState_find_transition(struct LxState *curr_state, int ch0, int ch1, int tx_type){
	for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
		int cmp = LxTransition_cmp(tx->ch0, tx->ch1, tx->tx_type, ch0, ch1, tx_type);
		if(cmp == 0){
			is_current_state_a_variable_index++;
			return tx;
		}
	}
	return 0;
}

static void LxTransition_insert_at(struct LxState *curr_state, struct LxTransition *new_transition){
#if LEMONEX_DBG>=1
	printf("INSERT_TX:%d[%d(%c)-%d(%c)/%d]->%d\n"
		, curr_state->state_id
		, new_transition->ch0
		, new_transition->ch0
		, new_transition->ch1
		, new_transition->ch1
		, new_transition->tx_type
		, new_transition->next_state->state_id
	);
	printf("is_current_state_a_variable_index TX:%d\n", is_current_state_a_variable_index);
#endif
	assert(new_transition->next_state != curr_state);
	struct LxTransition* insert_tx_after = 0;
	for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
		int cmp = LxTransition_cmp(tx->ch0, tx->ch1, tx->tx_type, new_transition->ch0, new_transition->ch1, new_transition->tx_type);
		if(cmp == 0){
			printf("Internal error:inserting duplicate transition\n");
			exit(1);
		}
		if(cmp == -1){
			insert_tx_after = tx;
		}
	}

	if(insert_tx_after != 0){
		new_transition->next_transition = insert_tx_after->next_transition;
		insert_tx_after->next_transition = new_transition;
	}else{
		new_transition->next_transition = curr_state->head_transition;
		curr_state->head_transition = new_transition;
	}
}

struct LxTransition *LxTransition_insert(struct pstate *psp, struct LxAstNode *curr_node, int tx_type, struct LxState *curr_state, struct LxState *new_state){
	is_current_state_a_variable_index++;
	struct LxTransition *new_transition = LxTransition_create(psp, curr_node->ch0, curr_node->ch1, curr_node->is_variable, curr_node->variable_name, is_current_state_a_variable_index, curr_node->mode, tx_type, psp->is_capturing, new_state);
	LxTransition_insert_at(curr_state, new_transition);
	return new_transition;
}

static int LxRange_contains(struct lemon *lemp, int rch0, int rch1, int cch0, int cch1, int is_cleaf){
	/* cch is a range, skip */
	if(cch1 != 0){
		return 0;
	}

	/* cch is a special range, skip */
	if(cch0 == 0){
		return 0;
	}

	/* rch is a char, skip */
	if(rch1 == 0){
		return 0;
	}

	/* rch is a loop transition, skip */
	if((rch0 == 0) && (rch1 == 0)){
		return 0;
	}

	/* if rch is a special range */
	if(rch0 == 0){
		int cls = 0;
		switch(rch1){
			case LXCLASS_LETTER:
				cls = 'l';
				break;
			case LXCLASS_DIGIT:
				cls = 'd';
				break;
			case LXCLASS_WORD:
				cls = 'w';
				break;
			case LXCLASS_SPACE:
				cls = 's';
				break;
			case LXCLASS_DOT:
				return (is_cleaf == 1)?0:1;
			default:
				printf("Internal error(1): unknown range(%d)\n", rch1);
				exit(1);
		}
		int i = 0;
		while(lemp->lxclasslist[i+1] != 0) {
			if((lemp->lxclasslist[i] == 0) && (lemp->lxclasslist[i+1] == cls)) {
				break;
			}
			i += 2;
		}
		if(lemp->lxclasslist[i+1] == 0) {
			printf("INTERNAL-ERROR:unhandled classtype:%d(%c)\n", cls, cls);
			exit(1);
		}

		i+=2;
		while(lemp->lxclasslist[i] != 0) {
			if((lemp->lxclasslist[i] <= cch0) && (cch0 <= lemp->lxclasslist[i+1])) {
				return 1;
			}
			i += 2;
		}
		return 0;
	}

	/* if rch is a regular range */
	assert((rch0 > 0) && (rch1 > 0));
	if((rch0 >= cch0) && (cch0 <= rch1)){
		return 1;
	}
	return 0;
}

static int LxState_find_transition_by_next(struct pstate *psp, struct LxTransition* except_transition){
	for(struct LxState* curr_state = psp->first_state; curr_state != 0; curr_state = curr_state->next_state){
		for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
			if((tx == except_transition) || (tx->next_state != except_transition->next_state)){
				continue;
			}
			int cmp = LxTransition_cmp(tx->ch0, tx->ch1, tx->tx_type, except_transition->ch0, except_transition->ch1, REGULAR_TX);
			if(cmp == 0){
				continue;
			}
#if LEMONEX_DBG>=2
			printf("has_tx:%d[%d-%d]->%d\n"
				, curr_state->state_id
				, tx->ch0, tx->ch1
				, tx->next_state->state_id
			);
#endif
			return 1;
		}
	}
	return 0;
}

static void LxState_set_drop(struct LxState *curr_state, struct LxState *drop_state){
	assert(curr_state->drop_state == 0);
	curr_state->drop_state = drop_state;
}

static void LxState_set_goto(struct LxState *curr_state, struct LxState *goto_state){
	assert(curr_state->goto_state == 0);
	curr_state->goto_state = goto_state;
}

static struct LxState *LxNode_process_charnode(struct pstate *psp, struct LxAstNode *curr_node, struct LxState *curr_state, int is_chk){
	assert(curr_node->lhs == 0);
	assert(curr_node->rhs == 0);

#if LEMONEX_DBG>=2
	printf("proc-char:%d[%d-%d]\n", curr_state->state_id, curr_node->ch0, curr_node->ch1);
	printf("is_current_state_a_variable_index:%d\n", is_current_state_a_variable_index);
#endif

	struct LxTransition* tx1 = LxState_find_transition(curr_state, curr_node->ch0, curr_node->ch1, REGULAR_TX);
	if(tx1 != 0){
		if(tx1->next_state->is_loop_return == 1){
			/// \todo should do this only if this is a child of a star node
			assert(tx1->is_capturing == psp->is_capturing);
			return tx1->next_state->goto_state;
		}
		return tx1->next_state;
	}
	if(is_chk == 1){
		return 0;
	}

	struct LxState *new_state = LxState_create(psp);
	LxTransition_insert(psp, curr_node, REGULAR_TX, curr_state, new_state);

	if(curr_state->star_state != 0){
		struct LxTransition* tx2 = LxState_find_transition(curr_state->star_state, curr_node->ch0, curr_node->ch1, REGULAR_TX);
		if(tx2 != 0){
			if(tx2->next_state->goto_state != 0){
				printf("Internal error(2): inconsistent state\n");
				exit(1);
			}
			LxState_set_goto(tx2->next_state, new_state);
		}else{
			LxTransition_insert(psp, curr_node, REGULAR_TX, curr_state->star_state, new_state);
		}
	}

	return new_state;
}

static struct LxState *LxNode_process_classnode(struct pstate *psp, struct LxAstNode *curr_node, struct LxState *curr_state, int tx_type, int is_chk){
	struct LxState *new_state = 0;
	assert(curr_node->lhs == 0);
	assert(curr_node->rhs != 0);

	/* search for existing dst state for each item in this class*/
	for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
		for(struct LxAstNode* node = curr_node->rhs; node != 0; node = node->rhs){
			int cmp = LxTransition_cmp(tx->ch0, tx->ch1, tx->tx_type, node->ch0, node->ch1, tx_type);
			if(cmp == 0){
				if(new_state == 0){
					new_state = tx->next_state;
				}else if(new_state != tx->next_state){
					printf("Overlapping class in regex\n");
					exit(1);
				}
				if(tx->tx_type != tx_type){
					printf("Negative class mismatch\n");
					exit(1);
				}
			}
		}
	}
	if(new_state != 0){
		return new_state;
	}

	if(is_chk == 1){
		return 0;
	}

	new_state = LxState_create(psp);
	for(struct LxAstNode* node = curr_node->rhs; node != 0; node = node->rhs){
		struct LxTransition *dtx = LxTransition_insert(psp, node, tx_type, curr_state, new_state);
		dtx->tx_type = tx_type;
	}

	return new_state;
}

static struct LxState *LxNode_process(struct pstate *psp, int lvl, char pos, struct LxAstNode *curr_node, struct LxState *curr_state, int is_chk);

static struct LxState *LxNode_process_loopnode(struct pstate *psp, int lvl, struct LxAstNode *curr_node, struct LxState *curr_state, int is_chk, int is_star){
	struct LxState *lhs = 0;
	struct LxState *new_state = 0;
	assert(curr_node->lhs != 0);
	assert(curr_node->rhs == 0);

	/* process all 0-0 transitions out of this state */
	for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
		if((tx->ch0 != 0) || (tx->ch1 != 0)){
			continue;
		}
		assert((tx->ch0 == 0) && (tx->ch1 == 0));
		lhs = LxNode_process(psp, lvl+1, 'L', curr_node->lhs, tx->next_state, 1);
		if(lhs != 0){
			assert((lhs->is_loop_head == 1) || (lhs->is_loop_return == 1));
			if(lhs->is_loop_return == 1){
				lhs = lhs->goto_state;
			}
			assert(lhs->is_loop_head == 1);
			return lhs;
		}
	}
	if(is_chk == 1){
		return 0;
	}

	new_state = LxState_create(psp);
	new_state->is_loop_head = 1;
	lhs = LxNode_process(psp, lvl+1, 'L', curr_node->lhs, new_state, is_chk);
	assert(lhs != 0);
	for(struct LxTransition* tx = new_state->head_transition; tx != 0; tx = tx->next_transition){
		tx->is_loop_set = 0;
	}
	for(struct LxTransition* tx = new_state->head_transition; tx != 0; tx = tx->next_transition){
		if(tx->is_loop_set == 1){
			continue;
		}
		tx->is_loop_set = 1;
		struct LxTransition* tx1 = LxState_find_transition(curr_state, tx->ch0, tx->ch1, tx->tx_type);
		if(tx1 != 0){
			struct LxState *dup_state = tx1->next_state;
#if LEMONEX_DBG>=2
			printf("%d[%d-%d]-> dup_state:%d, goto:%d, gotoing:%d\n"
				, curr_state->state_id
				, tx->ch0, tx->ch1
				, dup_state->state_id
				, (dup_state->goto_state != 0)?dup_state->goto_state->state_id:0
				, tx->next_state->state_id
			);
#endif
			assert(tx1->is_capturing == psp->is_capturing);
			dup_state->is_loop_enter = 1;
			if(dup_state->goto_state == 0){
				LxState_set_goto(dup_state, tx->next_state);
			}
		}else{
			struct LxState *dup_state = LxState_create(psp);
			dup_state->is_loop_enter = 1;
			LxState_set_goto(dup_state, tx->next_state);
			struct LxTransition *dup_transition = LxTransition_create(psp, tx->ch0, tx->ch1, tx->is_variable, tx->variable_name, tx->idx, tx->mode, tx->tx_type, tx->is_capturing, dup_state);
			LxTransition_insert_at(curr_state, dup_transition);
			for(struct LxTransition* tx2 = new_state->head_transition; tx2 != 0; tx2 = tx2->next_transition){
				if(tx2->is_loop_set == 1){
					continue;
				}
				if(tx->next_state == tx2->next_state){
					dup_transition = LxTransition_create(psp, tx2->ch0, tx2->ch1, tx2->is_variable, tx2->variable_name, tx2->idx, tx2->mode, tx2->tx_type, tx2->is_capturing, dup_state);
					LxTransition_insert_at(curr_state, dup_transition);
					tx2->is_loop_set = 1;
				}
			}
		}
	}

	LxState_set_goto(lhs, new_state);
	lhs->is_loop_return = 1;
	struct LxTransition *loop_transition = LxTransition_create(psp, 0, 0, 0, NULL, 0, NULL, LOOP_TX, 0, new_state);
	LxTransition_insert_at(curr_state, loop_transition);
	if(is_star == 1){
		new_state->star_state = curr_state;
	}
	return new_state;
}

static struct LxState *LxNode_process(struct pstate *psp, int lvl, char pos, struct LxAstNode *curr_node, struct LxState *curr_state, int is_chk){
	assert(curr_state);
	struct LxState *lhs = 0;
	struct LxState *rhs = 0;
	struct LxState *new_state = 0;
	switch(curr_node->node_type){
		case CHAR_NODE:
			return LxNode_process_charnode(psp, curr_node, curr_state, is_chk);
		case CLASS_NODE:
			return LxNode_process_classnode(psp, curr_node, curr_state, REGULAR_TX, is_chk);
		case NCLASS_NODE:
			return LxNode_process_classnode(psp, curr_node, curr_state, NOT_TX, is_chk);
		case STAR_NODE:
			return LxNode_process_loopnode(psp, lvl, curr_node, curr_state, is_chk, 1);
		case PLUS_NODE:
			return LxNode_process_loopnode(psp, lvl, curr_node, curr_state, is_chk, 0);
		case OPT_NODE:
			assert(curr_node->lhs != 0);
			assert(curr_node->rhs == 0);
			lhs = LxNode_process(psp, lvl+1, 'L', curr_node->lhs, curr_state, is_chk);
			assert(lhs != 0);
			LxState_set_goto(curr_state, lhs);
			return lhs;
		case OR_NODE:
			assert(curr_node->lhs != 0);
			assert(curr_node->rhs != 0);
			lhs = LxNode_process(psp, lvl+1, 'L', curr_node->lhs, curr_state, is_chk);
			rhs = LxNode_process(psp, lvl+1, 'R', curr_node->rhs, curr_state, is_chk);
			assert(lhs != 0);
			assert(rhs != 0);
			LxState_set_goto(rhs, lhs);
			return lhs;
		case AND_NODE:
			assert(curr_node->lhs != 0);
			assert(curr_node->rhs != 0);
			lhs = LxNode_process(psp, lvl+1, 'L', curr_node->lhs, curr_state, is_chk);
			rhs = LxNode_process(psp, lvl+1, 'R', curr_node->rhs, lhs, is_chk);
			assert(lhs != 0);
			assert(rhs != 0);
			return rhs;
	}
	assert(0);
	return 0;
}

struct LxAstNode *lx_expr(struct LxScanner *s);

struct LxAstNode *lx_primary_expr(struct LxScanner *s, int chk_range){
	int ch0 = lx_lookahead(s);
	if(ch0 == 0){
		return 0;
	}
	if(ch0 == ')'){
		return 0;
	}
	lx_advance(s);
	if(ch0 == '.'){
		return LxNode_create(CHAR_NODE, 0, 0, 0, LXCLASS_DOT);
	}
	if(ch0 == '\\'){
		ch0 = lx_lookahead(s);
		if(ch0 == 0){
			return 0;
		}
		lx_advance(s);
		switch(ch0){
			case 'l':
				return LxNode_create(CHAR_NODE, 0, 0, 0, LXCLASS_LETTER);
			case 'd':
				return LxNode_create(CHAR_NODE, 0, 0, 0, LXCLASS_DIGIT);
			case 'w':
				return LxNode_create(CHAR_NODE, 0, 0, 0, LXCLASS_WORD);
			case 's':
				return LxNode_create(CHAR_NODE, 0, 0, 0, LXCLASS_SPACE);
			case 't':
				return LxNode_create(CHAR_NODE, 0, 0, '\t', 0);
			case 'r':
				return LxNode_create(CHAR_NODE, 0, 0, '\r', 0);
			case 'n':
				return LxNode_create(CHAR_NODE, 0, 0, '\n', 0);
		}
	}
	if(chk_range && (lx_lookahead(s) == '-')){
		lx_advance(s);
		int ch1 = lx_lookahead(s);
		if(ch1 == 0){
			return 0;
		}
		lx_advance(s);
		return LxNode_create(CHAR_NODE, 0, 0, ch0, ch1);
	}
	return LxNode_create(CHAR_NODE, 0, 0, ch0, 0);
}

struct LxAstNode *lx_range_expr(struct LxScanner *s){
	return lx_primary_expr(s, 1);
}

struct LxAstNode *lx_inner_expr(struct LxScanner *s){
	struct LxAstNode *lhs = 0;
	struct LxAstNode *rhs = 0;
	int tx_type = REGULAR_TX;
	// if regex is a variable, do not attempt to process an expression, leave it as is
	if (!is_current_state_a_variable) switch(lx_lookahead(s)){
		case '(':
			lx_advance(s);
			lhs = lx_expr(s);
			if(lx_lookahead(s) != ')'){
				printf("syntax error in regex while looking for ')'\n");
				exit(1);
			}
			lx_advance(s);
			return lhs;
		case '[':
			lx_advance(s);
			if(lx_lookahead(s) == '^'){
				lx_advance(s);
				tx_type = NOT_TX;
			}
			lhs = lx_range_expr(s);
			rhs = lhs;
			while(lx_lookahead(s) != ']'){
				assert(rhs != 0);
				rhs->rhs = lx_range_expr(s);
				rhs = rhs->rhs;
			}
			if(lx_lookahead(s) != ']'){
				printf("syntax error in regex while looking for ']'\n");
				exit(1);
			}
			lx_advance(s);
			if(tx_type == NOT_TX){
				return LxNode_create(NCLASS_NODE, 0, lhs, 0, 0);
			}
			return LxNode_create(CLASS_NODE, 0, lhs, 0, 0);
		case '?':
			lx_advance(s);
			return LxNode_create(OPT_NODE, lhs, 0, 0, 0);
	}
	return lx_primary_expr(s, 0);
}

struct LxAstNode *lx_unary_expr(struct LxScanner *s){
	struct LxAstNode *lhs = lx_inner_expr(s);
	if(lhs == 0){
		return 0;
	}
	int node_type = 0;
	switch(lx_lookahead(s)){
		case '*':
			node_type = STAR_NODE;
			break;
		case '+':
			node_type = PLUS_NODE;
			break;
		case '?':
			node_type = OPT_NODE;
			break;
		default:
			return lhs;
	}
	lx_advance(s);
	return LxNode_create(node_type, lhs, 0, 0, 0);
}

struct LxAstNode *lx_or_expr(struct LxScanner *s){
	struct LxAstNode *lhs = lx_unary_expr(s);
	if(lhs == 0){
		return 0;
	}

	while(lx_lookahead(s) == '|') {
		lx_advance(s);
		struct LxAstNode *rhs = lx_expr(s);
		lhs = LxNode_create(OR_NODE, lhs, rhs, 0, 0);
	}

	return lhs;
}

struct LxAstNode *lx_and_expr(struct LxScanner *s){
	struct LxAstNode *lhs = lx_or_expr(s);
	if(lhs == 0){
		return 0;
	}

	struct LxAstNode *rhs = 0;
	while((rhs = lx_expr(s)) != 0){
		lhs = LxNode_create(AND_NODE, lhs, rhs, 0, 0);
	}

	return lhs;
}

struct LxAstNode *lx_expr(struct LxScanner *s){
	return lx_and_expr(s);
}

static struct LxState *LxState_normalize(struct LxState *next_state){
	if(next_state->is_loop_enter == 1){
		assert(next_state->goto_state != 0);
		next_state = next_state->goto_state;
	}
	if(next_state->is_loop_return == 1){
		assert(next_state->goto_state != 0);
		next_state = next_state->goto_state;
	}
	return next_state;
}

static void LxState_setdrop_at(struct pstate *psp, struct LxState *next_state, struct LxState *drop_state){
	next_state = LxState_normalize(next_state);
	if(next_state->is_processed == 1){
		return;
	}

	drop_state = LxState_normalize(drop_state);
#if LEMONEX_DBG>=1
	printf("SETDROP_AT:%d->%d\n", next_state->state_id, drop_state->state_id);
#endif

	if(next_state->drop_state == 0){
		LxState_set_drop(next_state, drop_state);
	}else{
		assert((next_state->drop_state == drop_state) || (next_state->drop_state == drop_state->star_state));
	}

	/* possibly a join node after an OR */
	if(next_state->goto_state == 0){
		LxState_set_goto(next_state, next_state->drop_state);
	}
}

static void LxState_postprocess_setdrop(struct pstate *psp, int lvl, struct LxState *curr_state){
	if(curr_state->is_processed == 1){
		return;
	}
	curr_state->is_processed = 1;

	struct LxState *drop_state = curr_state->drop_state;
	if((drop_state != 0) && (drop_state->is_loop_return == 1)){
		assert(drop_state->goto_state != 0);
		drop_state = drop_state->goto_state;
	}
	for(struct LxTransition* ctx = curr_state->head_transition; ctx != 0; ctx = ctx->next_transition){
		int found = 0;
		for(struct LxTransition* rtx = curr_state->head_transition; rtx != 0; rtx = rtx->next_transition){
			if(LxRange_contains(psp->gp, rtx->ch0, rtx->ch1, ctx->ch0, ctx->ch1, ctx->next_state->is_leaf) == 1){
				LxState_setdrop_at(psp, ctx->next_state, rtx->next_state);
				found = 1;
			}
		}
		if((found == 0) && (drop_state != 0)){
			for(struct LxTransition* rtx = drop_state->head_transition; rtx != 0; rtx = rtx->next_transition){
				if(LxRange_contains(psp->gp, rtx->ch0, rtx->ch1, ctx->ch0, ctx->ch1, ctx->next_state->is_leaf) == 1){
					LxState_setdrop_at(psp, ctx->next_state, rtx->next_state);
					found = 1;
				}
			}
		}
	}

	/* recurse into each next state */
	for(struct LxTransition* ctx = curr_state->head_transition; ctx != 0; ctx = ctx->next_transition){
		LxState_postprocess_setdrop(psp, lvl+1, ctx->next_state);
	}
}

static void LxState_postprocess_duptransition(struct pstate *psp, struct LxState *curr_state, struct LxState *from_state, struct LxState *entry_state){
	for(struct LxTransition* tx = from_state->head_transition; tx != 0; tx = tx->next_transition){
		if(curr_state->state_id == tx->next_state->state_id){
			continue;
		}
		if(tx->next_state == entry_state){
			continue;
		}
		if((tx->ch0 == 0) && (tx->ch1 == 0)){
			continue;
		}
		if((tx->ch0 == 0) && (tx->ch1 == LXCLASS_DOT)){
			continue;
		}
		struct LxTransition* tx1 = LxState_find_transition(curr_state, tx->ch0, tx->ch1, INIT_TX);
		if(tx1 != 0){
			continue;
		}
		struct LxTransition *dup_transition = LxTransition_create(psp, tx->ch0, tx->ch1, tx->is_variable, tx->variable_name, tx->idx, tx->mode, INIT_TX, tx->is_capturing, tx->next_state);
		LxTransition_insert_at(curr_state, dup_transition);
	}
}

static void LxState_postprocess_setinit(struct pstate *psp, int lvl, struct LxState *curr_state, struct LxState *entry_state){
	if(curr_state->is_processed == 1){
		return;
	}
	curr_state->is_processed = 1;

	for(struct LxTransition* ctx = curr_state->head_transition; ctx != 0; ctx = ctx->next_transition){
		/* set not_transition for each next state */
		if(ctx->tx_type == NOT_TX){
			if((curr_state->not_transition != 0) && (curr_state->not_transition->next_state != ctx->next_state)){
				printf("ERROR: Multiple overlapping not-transitions at the same state\n");
				exit(1);
			}
			if(curr_state->not_transition == 0){
				curr_state->not_transition = ctx;
			}
		}

		/* and dot_transition as well */
		if((ctx->ch0 == 0) && (ctx->ch1 == LXCLASS_DOT)){
			if(curr_state->dot_transition != 0){
				printf("ERROR: Multiple dot-transitions at the same state\n");
				exit(1);
			}
			curr_state->dot_transition = ctx;
		}
	}

	if(curr_state->is_leaf == 1){
		if(curr_state->drop_state != 0){
			LxState_postprocess_duptransition(psp, curr_state, curr_state->drop_state, entry_state);
		}

		if(curr_state->dot_transition != 0){
			assert(curr_state->init_mode);
			assert(curr_state->init_mode->init_state);
			LxState_postprocess_duptransition(psp, curr_state, curr_state->init_mode->init_state, entry_state);
		}
	}else{
		for(struct LxTransition* ctx = curr_state->head_transition; ctx != 0; ctx = ctx->next_transition){
			if((ctx->ch1 != 0) || (ctx->ch0 != 0)){
				continue;
			}
			if(ctx->next_state->is_leaf == 0){
				if(ctx->next_state->goto_state == 0){
					LxState_set_goto(ctx->next_state, curr_state->goto_state);
				}
			}
		}
	}

	/* recurse into each next state */
	for(struct LxTransition* ctx = curr_state->head_transition; ctx != 0; ctx = ctx->next_transition){
		struct LxState *es = entry_state;
		if(es == 0){
			es = ctx->next_state;
		}
		LxState_postprocess_setinit(psp, lvl+1, ctx->next_state, es);
	}
}

static void LxState_postprocess(struct pstate *psp){
	for(struct LxMode *curr_mode = psp->first_mode; curr_mode != 0; curr_mode = curr_mode->next_mode){
		LxState_postprocess_setdrop(psp, 0, curr_mode->init_state);
	}
	for(struct LxState* curr_state = psp->first_state; curr_state != 0; curr_state = curr_state->next_state){
		curr_state->is_processed = 0;
	}
	for(struct LxMode *curr_mode = psp->first_mode; curr_mode != 0; curr_mode = curr_mode->next_mode){
		LxState_postprocess_setinit(psp, 0, curr_mode->init_state, 0);
	}
}

int Lexer_process_regex(struct pstate *psp, const char *regex){
#if LEMONEX_DBG>=1
	printf("reading regex '%s' as symbol '%s' in mode '%s'\n", regex, (psp->lastlxsym)?psp->lastlxsym->name:"", psp->last_mode->name);
#endif
	is_current_state_a_variable = 0;
	is_current_state_mode = psp->last_mode->name;
	struct LxScanner s;
	s.p = regex;
	s.ch = 0;
	s.offset = 0;
	struct LxAstNode *root_node = lx_expr(&s);
	if(root_node->node_type != STAR_NODE){
		psp->nstarcount++;
	}
	psp->curr_state = LxNode_process(psp, 0, '*', root_node, psp->curr_state, 0);
	is_current_state_mode = NULL;
	return 0;
}

int Lexer_process_variable(struct pstate *psp, const char *regex, const char * regex_quoted){
#if LEMONEX_DBG>=1
	printf("reading var '%s' as symbol '%s' in mode '%s'\n", regex, (psp->lastlxsym)?psp->lastlxsym->name:"", psp->last_mode->name);
#endif
	is_current_state_a_variable = 1;
	is_current_state_a_variable_name = regex[0]=='\\'?regex_quoted:regex;
	is_current_state_a_variable_index = -1;
	is_current_state_mode = psp->last_mode->name;
	struct LxScanner s;
	s.p = regex;
	s.ch = 0;
	s.offset = 0;
	struct LxAstNode *root_node = lx_expr(&s);
	if(root_node->node_type != STAR_NODE){
		psp->nstarcount++;
	}
	psp->curr_state = LxNode_process(psp, 0, '*', root_node, psp->curr_state, 0);
	is_current_state_a_variable = 0;
	is_current_state_a_variable_name = NULL;
	is_current_state_a_variable_index = 0;
	is_current_state_mode = NULL;
	return 0;
}

#endif /* LEMONEX */

// line 6548
#ifdef LEMONEX
/*
** The following routine emits code for the token constructor
*/
void emit_lexer_actioncode(
	FILE *out,
	const char *code,
	struct lemon *lemp,
	int *lineno
){
const char *cp = code;
for(; *cp; cp++){
	if( *cp=='$' && cp[1]=='$' ){
		fprintf(out,"(lxpLexer->token)");
		cp++;
		continue;
	}
	if( *cp=='\n' ) (*lineno)++;
	fputc(*cp,out);
}
}

/*
** The following routine emits code for the token constructor
*/
void emit_constructor_code(
	FILE *out,
	const char *ctorcode,
	struct lemon *lemp,
	int *lineno
){
	emit_lexer_actioncode(out, ctorcode, lemp, lineno);
}
#endif

// line 7045
#ifdef LEMONEX
void Lexer_generate_class_list(struct lemon *lemp, FILE *fp, int *lineno){
	int i = 0;
	while(lemp->lxclasslist[i+1] != 0) {
		if(lemp->lxclasslist[i] == 0) {
			if(i > 0){
				fprintf(fp, "  0,0\n");(*lineno)++;
				fprintf(fp, "};\n");(*lineno)++;
			}
			fprintf(fp, "static int lxcls_%c[] = {\n", lemp->lxclasslist[i+1]);(*lineno)++;
		}else{
			fprintf(fp, "  0x%-6X,0x%-6X,", lemp->lxclasslist[i], lemp->lxclasslist[i+1]);(*lineno)++;
			if((i%8) == 0){
				fprintf(fp, "\n");
			}
		}
		i += 2;
	}
	fprintf(fp, "  0,0\n");(*lineno)++;
	fprintf(fp, "};\n");(*lineno)++;
}

static void lx_generate_send(struct lemon* lemp, FILE* out, struct LxState *curr_state, char * name){
	/* generate user action code if specified */
	if(curr_state->code != 0){
		fprintf(out, "  LX_ACTION(%d);", curr_state->state_id);
	}else{
		fprintf(out, "  ");
	}

	/* send token, if set */
	if(curr_state->matchedsym > 0){
		const char *prefix;
		if( lemp->tokenprefix ) prefix = lemp->tokenprefix;
		else                    prefix = "";
		fprintf(out, "LX_SEND(%s%s);"
			, prefix
			, lemp->symbols[curr_state->matchedsym->index]->name
		);
	}else{
		fprintf(out, "/*NO_SEND*/");
	}

	/* reset current capture */
	if (name == NULL) fprintf(out, "LX_RESET;");
}

static void lx_generate_conditions(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, struct LxTransition *tx){
	if(tx->ch0 == 0){
		switch(tx->ch1){
			case LXCLASS_LETTER:
				fprintf(out, "  if(LX_ISLETTER(ch)==1)");
				break;
			case LXCLASS_DIGIT:
				fprintf(out, "  if(LX_ISDIGIT(ch)==1)");
				break;
			case LXCLASS_WORD:
				fprintf(out, "  if(LX_ISWORD(ch)==1)");
				break;
			case LXCLASS_SPACE:
				fprintf(out, "  if(LX_ISSPACE(ch)==1)");
				break;
			case LXCLASS_DOT:
				/* DOT transition should always be the last one */
				assert(tx->next_transition == 0);
				assert(curr_state->dot_transition == tx);
				fprintf(out, "  if(ch != 0)");
				break;
			default:
				printf("Internal error: unknown range\n");
				exit(1);
		}
	}else if(tx->ch1 == 0){
		if (tx->is_variable) if (tx->idx != 0) fprintf(out, "//");
	str_new(q);
	str_new(ch);
	str_insert_char(ch, tx->ch0);
	str_insert_char(ch, '\0');
	str_insert_string(q, ch.string);
	str_free(ch);
	fprintf(out, " if(ch == ");
	if (tx->is_variable) {
		fprintf(out, "%s[%d]", tx->variable_name, tx->idx);
	} else fprintf(out, "%d /* decimal is required for full unicode support, printable character is '%s' */ ", tx->ch0, q.escaped.string);
	str_free(q);
	fprintf(out, ")");
	}else{
		fprintf(out, "  if((ch >= %d) && (ch <= %d))", tx->ch0, tx->ch1);
	}
}

static void lx_generate_leaf(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, int tx_type){
	if(tx_type == NOT_TX){
		if(curr_state->dot_transition == 0){
			lx_generate_send(lemp, out, curr_state, NULL);
		}
		return;
	}
	assert(tx_type == REGULAR_TX);

	/* if this is not a leaf state */
	if(curr_state->is_leaf == 0) {
		if(curr_state->dot_transition != 0){
			fprintf(out, "  lxpLexer->lxstate=%d;", curr_state->state_id);
			fprintf(out, "return 0;\n");(*lineno)++;
		}else if(curr_state->head_transition != 0){
			fprintf(out, "  if(ch == 0){");
			fprintf(out, "lxpLexer->lxstate=%d;", curr_state->state_id);
			fprintf(out, "return 0;");
			fprintf(out, "}\n");(*lineno)++;
		}
		return;
	}

	/* if this is a leaf state */
	assert(curr_state->is_leaf == 1);

	if(curr_state->dot_transition != 0){
		fprintf(out, "  if(is_final == 0) {");
	}else{
		fprintf(out, "  if((ch == 0) && (is_final == 0)) {");
	}
	fprintf(out, "lxpLexer->lxstate=%d;", curr_state->state_id);
	fprintf(out, "return 0;");
	fprintf(out, "}\n");(*lineno)++;

	if((curr_state->not_transition == 0) && (curr_state->dot_transition == 0)){
		lx_generate_send(lemp, out, curr_state, NULL);
		fprintf(out, "\n");(*lineno)++;
	}

	/* if ch is 0 here, is_final will be 1, so send EOF marker */
	if(curr_state->dot_transition == 0){
		fprintf(out, "  if(ch == 0) {");
	}else{
		fprintf(out, "  ");
	}
	fprintf(out, "LX_SEND(0);");
	fprintf(out, "return 0;");
	if(curr_state->dot_transition == 0){
		fprintf(out, "}");
	}
	fprintf(out, "\n");(*lineno)++;
}

static void lx_generate_jump(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, int tx_type){
	if(tx_type == REGULAR_TX){
		fprintf(out, "  ");
	}
	if(curr_state->is_leaf == 1) {
		/* if curr_state transitions to another mode, go to that mode's init state */
		if(curr_state->next_mode != 0){
			if(strcmp(curr_state->next_mode, "<") != 0){
				struct LxMode* next_mode = LxMode_find(lemp, curr_state->next_mode);
				if(next_mode == 0) {
					printf("INTERNAL-ERROR:invalid next-mode in state: %s\n", curr_state->next_mode);
					exit(1);
				}
				if(next_mode->init_state != curr_state->init_mode->init_state){
					fprintf(out, "LX_ENTER_NESTING(%d);", curr_state->init_mode->init_state->state_id);
				}else{
					fprintf(out, "LX_RENEW_NESTING;");
				}
				if(tx_type == REGULAR_TX){
					fprintf(out, "\n  ");(*lineno)++;
				}
				fprintf(out, "goto S%d; /* by retn_state */", next_mode->init_state->state_id);
			}else{
				/* if next mode is <, return to calling mode */
				fprintf(out, "if(LX_LEAVE_NESTING() == 1){goto L0;}");
				if(tx_type == REGULAR_TX){
					fprintf(out, "\n  ");(*lineno)++;
				}
				fprintf(out, "goto S%d; /* by next_state */", curr_state->init_mode->init_state->state_id);
			}
		}else{
			if(curr_state->dot_transition == 0){
				fprintf(out, "goto S%d; /* by init_state */", curr_state->init_mode->init_state->state_id);
			}
		}
	}else if(curr_state->goto_state != 0){
		if(curr_state->dot_transition == 0){
			fprintf(out, "goto S%d; /* by goto_state */", curr_state->goto_state->state_id);
		}
	}else{
		if(curr_state->dot_transition == 0){
#if LEMONEX_DBG>=1
			fprintf(out, "printf(\"(%%d,%%d):Error in state %d on %%u(%%c)###########\\n\", lxpLexer->lxrow, lxpLexer->lxcol, ch, ch);",
				curr_state->state_id);
			if(tx_type == REGULAR_TX){
				fprintf(out, "\n  ");(*lineno)++;
			}
#endif
			fprintf(out, "LX_SENDERR(%d);return -1;", lemp->errsym->index);
		}
	}
	if(tx_type == REGULAR_TX){
		fprintf(out, "\n");(*lineno)++;
	}
}

int nsp = 12;
char * nspS = "\n/*\n";
char * nspE = "\n*/  ";

#define txp(s) if (tx_type == s) fprintf(out, "%-*s", nsp, #s);

void txd(FILE* out, int tx_type) {
	txp(REGULAR_TX);
	txp(NOT_TX);
	txp(INIT_TX);
	txp(DROP_TX);
	txp(LOOP_TX);
}

static void lx_generate_send_trace(struct lemon* lemp, FILE* out, struct LxState *curr_state){
	/* generate user action code if specified */
	if(curr_state->code != 0){
		fprintf(out, "ACTION:LX_ACTION(%d):", curr_state->state_id);
	}
}

static void lx_generate_conditions_trace(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, struct LxTransition *tx) {
	if(tx->ch0 == 0){
		switch(tx->ch1){
			case LXCLASS_LETTER:
				fprintf(out, "  if(LX_ISLETTER(ch)==1):");
				break;
			case LXCLASS_DIGIT:
				fprintf(out, "  if(LX_ISDIGIT(ch)==1):");
				break;
			case LXCLASS_WORD:
				fprintf(out, "  if(LX_ISWORD(ch)==1):");
				break;
			case LXCLASS_SPACE:
				fprintf(out, "  if(LX_ISSPACE(ch)==1):");
				break;
			case LXCLASS_DOT:
				/* DOT transition should always be the last one */
				assert(tx->next_transition == 0);
				assert(curr_state->dot_transition == tx);
				fprintf(out, "if(ch != 0):");
				break;
			default:
				printf("Internal error: unknown range\n");
				exit(1);
		}
	}else if(tx->ch1 == 0){
		str_new(q);
		str_new(ch);
		str_insert_char(ch, tx->ch0);
		str_insert_char(ch, '\0');
		str_insert_string(q, ch.string);
		str_free(ch);
		if (tx->is_variable) {
			fprintf(out, "%s[%d]", tx->variable_name, tx->idx);
		} else fprintf(out, "'%s'", q.escaped.string);
		str_free(q);
		fprintf(out, ":%s:", tx->mode);
	}
}

static void lx_generate_leaf_trace(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, int tx_type){
	if(tx_type == NOT_TX){
		if(curr_state->dot_transition == 0){
			lx_generate_send_trace(lemp, out, curr_state);
		}
		return;
	}
	assert(tx_type == REGULAR_TX);

	/* if this is not a leaf state */
	if(curr_state->is_leaf == 0) {
		return;
	}

	/* if this is a leaf state */
	assert(curr_state->is_leaf == 1);

	if((curr_state->not_transition == 0) && (curr_state->dot_transition == 0)){
		lx_generate_send_trace(lemp, out, curr_state);
	}
}

static void lx_generate_jump_trace(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, int tx_type){
	if(curr_state->is_leaf == 1) {
		/* if curr_state transitions to another mode, go to that mode's init state */
		if(curr_state->next_mode != 0){
			if(strcmp(curr_state->next_mode, "<") != 0){
				struct LxMode* next_mode = LxMode_find(lemp, curr_state->next_mode);
				if(next_mode == 0) {
					printf("INTERNAL-ERROR:invalid next-mode in state: %s\n", curr_state->next_mode);
					exit(1);
				}
				if(next_mode->init_state != curr_state->init_mode->init_state){
					fprintf(out, "LX_ENTER_NESTING(%d):", curr_state->init_mode->init_state->state_id);
				}else{
					fprintf(out, "LX_RENEW_NESTING:");
				}
				if(tx_type == REGULAR_TX){
					fprintf(out, "\n  ");(*lineno)++;
				}
				fprintf(out, "goto &STATE%d\n", next_mode->init_state->state_id);
			}else{
				/* if next mode is <, return to calling mode */
				fprintf(out, "if(LX_LEAVE_NESTING() == 1):goto L0");
				if(tx_type == REGULAR_TX){
					fprintf(out, "\n  ");(*lineno)++;
				}
				fprintf(out, "goto &STATE%d\n", curr_state->init_mode->init_state->state_id);
			}
		}else{
			if(curr_state->dot_transition == 0){
				fprintf(out, "goto &STATE%d\n", curr_state->init_mode->init_state->state_id);
			}
		}
	}else if(curr_state->goto_state != 0){
		if(curr_state->dot_transition == 0){
			fprintf(out, "goto &STATE%d\n", curr_state->goto_state->state_id);
		}
	}
}

static void lx_generate_output_trace(struct lemon* lemp, FILE* out, int *lineno){
	puts("tracing state machine");
	// maybe i could use the existing structure instead of generating a new structure?
	for(struct LxState* curr_state = lemp->headstate; curr_state != 0; curr_state = curr_state->next_state){
		fprintf(out, "STATE_%d:\n", curr_state->state_id);(*lineno)++;
		assert((curr_state->code == 0) || (curr_state->is_leaf != 0));
// 	LX_PRINT_STATE_trace(out, curr_state);
		for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
			if (curr_state->dot_transition) txd(out, curr_state->dot_transition->tx_type);
			else fprintf(out, "%-*s", nsp, "none");
			txd(out, tx->tx_type);
			fprintf(out, ":");
			if((tx->ch0 == 0) && (tx->ch1 == 0)){
				fprintf(out, "\n  /*loop --> %d*/\n", tx->next_state->state_id);(*lineno)++;
			}else{
				lx_generate_conditions_trace(lemp, out, lineno, curr_state, tx);
				if(tx->tx_type == NOT_TX){
					lx_generate_leaf_trace(lemp, out, lineno, curr_state, 1);
					lx_generate_jump_trace(lemp, out, lineno, curr_state, 1);
				}else{
					if(curr_state->is_leaf == 1){
						if((curr_state->not_transition != 0) && (curr_state->not_transition != tx)){
							if(tx->tx_type == INIT_TX){
								lx_generate_send_trace(lemp, out, curr_state);
							}
						}else if((curr_state->dot_transition != 0) && (curr_state->dot_transition != tx)){
							if(tx->tx_type == INIT_TX){
								lx_generate_send_trace(lemp, out, curr_state);
							}
						}
					}
					fprintf(out, "goto &STATE%d", tx->next_state->state_id);
				}
				fprintf(out, "\n");(*lineno)++;
			}
		}
		if(curr_state->not_transition == 0){
			lx_generate_leaf_trace(lemp, out, lineno, curr_state, 0);
			lx_generate_jump_trace(lemp, out, lineno, curr_state, 0);
		}
	}
}

char * get_mode(struct LxTransition* tx) {
	return tx->mode;
}

int get_tran_num(struct LxState* curr_state) {
	int i = 0;
	for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition) i++;
	return i;
}

struct LxTransition* get_tx(struct LxState* curr_state, int stateid) {
	int i = 0;
	for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition) {
		i++;
		if (i == stateid) return tx;
	}
	return NULL;
}

char * get_name(struct LxState* curr_state, struct LxTransition* tx, int * nn) {
	char * n = NULL;
	*nn = false;
	FILE * out = stdout;
	if(tx->ch0 == 0){
		switch(tx->ch1){
			case LXCLASS_LETTER:
				fprintf(out, "  if(LX_ISLETTER(ch)==1):");
				break;
			case LXCLASS_DIGIT:
				fprintf(out, "  if(LX_ISDIGIT(ch)==1):");
				break;
			case LXCLASS_WORD:
				fprintf(out, "  if(LX_ISWORD(ch)==1):");
				break;
			case LXCLASS_SPACE:
				fprintf(out, "  if(LX_ISSPACE(ch)==1):");
				break;
			case LXCLASS_DOT:
				/* DOT transition should always be the last one */
				assert(tx->next_transition == 0);
				assert(curr_state->dot_transition == tx);
// 				fprintf(out, "if(ch != 0)\n");
				break;
			default:
				printf("Internal error: unknown range\n");
		}
	}else if(tx->ch1 == 0){
		str_new(q);
		str_new(ch);
		str_insert_char(ch, tx->ch0);
		str_insert_char(ch, '\0');
		str_insert_string(q, ch.string);
		str_free(ch);
		if (tx->is_variable) {
			return tx->variable_name;
		} else {
			n = strdup(q.escaped.string);
			*nn=true;
		}
		str_free(q);
	}
	if (n != NULL) return n;
	return NULL;
}

int get_goto(struct LxTransition* tx) {
	if (tx != 0) return tx->next_state->state_id;
	else return -1;
}

struct LxState* find_state(struct lemon* lemp, int stateno) {
	for(struct LxState* curr_state = lemp->headstate; curr_state != 0; curr_state = curr_state->next_state) if (curr_state->state_id == stateno) return curr_state;
	return NULL;
}

int state_count(struct lemon* lemp) {
	int i = 0;
	for(struct LxState* curr_state = lemp->headstate; curr_state != 0; curr_state = curr_state->next_state) i++;
	return i;
}

int get_nested_goto(struct lemon* lemp, struct LxState* state) {
	if(state->is_leaf == 1) {
		/* if state transitions to another mode, go to that mode's init state */
		if(state->next_mode != 0){
			if(strcmp(state->next_mode, "<") != 0){
				struct LxMode* next_mode = LxMode_find(lemp, state->next_mode);
				if(next_mode == 0) {
					printf("INTERNAL-ERROR:invalid next-mode in state: %s\n", state->next_mode);
					return -1;
				}
				if(next_mode->init_state != state->init_mode->init_state){
					if (lemp->lxdebuglevel >= 2)printf("LX_ENTER_NESTING(%d):", state->init_mode->init_state->state_id);
				}else{
					if (lemp->lxdebuglevel >= 2)printf("LX_RENEW_NESTING:");
				}
				return next_mode->init_state->state_id;
			}else{
				/* if next mode is <, return to calling mode */
				if (lemp->lxdebuglevel >= 2)printf("if(LX_LEAVE_NESTING() == 1){TAG2 goto L0;}:goto %d:", state->init_mode->init_state->state_id);
				return state->init_mode->init_state->state_id;
			}
		}else{
			if(state->dot_transition == 0){
				return state->init_mode->init_state->state_id;
			}
		}
	}
	return -1;
}

int * states_mode = NULL;

int * states_trace = NULL;

int * states_ne = NULL;
int * states_nl = NULL;

int nest_have = 0;

#define NEST_ENTER 1
#define NEST_LEAVE 2

int find_nested_goto(struct lemon* lemp, int stateno, int nest_type, int isvar, char * destname) {
	if (lemp->lxdebuglevel >= 2) pi(stateno);
	if (lemp->lxdebuglevel >= 2) pi(nest_type);
	int state_max = state_count(lemp);
	struct LxState* state = find_state(lemp, stateno);
	int g = get_nested_goto(lemp, state);
	if (g != -1) {
		if (lemp->lxdebuglevel >= 2) pi(g);
			 if (nest_type == NEST_ENTER) {
				 if (isvar == false) return stateno;
				 else return g;
			 }
		else if (nest_type == NEST_LEAVE) {
			// if current nest produces a leave, dont count it as it is a looped goto, get the nest after it
			if (nest_have) return stateno;
			if (!nest_have) nest_have = 1;
		}
	}
	if (state != NULL) {
		if (nest_type == NEST_ENTER) {
			if (states_ne == NULL) {
				states_ne = malloc(state_max*sizeof(int));
				memset(states_ne, 0, state_max*sizeof(int));
			}
			states_ne[stateno]++;
			if (states_ne[stateno] != 1)  {
				if (lemp->lxdebuglevel >= 2) printf("find_nested_goto: enter loop detected, ");
				return -1;
			}
		}
		else if (nest_type == NEST_LEAVE) {
			if (states_nl == NULL) {
				states_nl = malloc(state_max*sizeof(int));
				memset(states_nl, 0, state_max*sizeof(int));
			}
			states_nl[stateno]++;
			if (states_nl[stateno] != 1)  {
				if (lemp->lxdebuglevel >= 2) printf("find_nested_goto: leave loop detected, ");
				return -1;
			}
		}
		assert((state->code == 0) || (state->is_leaf != 0));
		int states = get_tran_num(state);
		if (states > 0) {
			for (int i = 1; i <= states; i++) {
				struct LxTransition* tx = get_tx(state, i);
				if (tx != NULL) {
					int needs_free = false;
					char * name = get_name(state, tx, &needs_free);
					if (name != NULL) {
						if (strcmp(name, destname) != 0) {
							if (needs_free == true) free(name);
							continue;
						}
					}
					if (needs_free == true) free(name);
					if((tx->ch0 == 0) && (tx->ch1 == 0)){
						if (lemp->lxdebuglevel >= 2) printf("/*loop --> %d*/, ", tx->next_state->state_id);
					}
					int gt = get_goto(tx);
					if (gt != -1) {
						if (lemp->lxdebuglevel >= 2) printf("NEST : tracing from %d to %d\n", stateno, gt);
						int m = find_nested_goto(lemp, gt, nest_type, isvar, destname);
						nest_have = 0; // reset variable back to 0
						if (m == -1) return -1;
						else return m;
					}
					else if (lemp->lxdebuglevel >= 2) printf("no goto for state %d\n", stateno);
				}
			}
		}
		else if(state->not_transition == 0){
			int gt = get_nested_goto(lemp, state);
			if (gt != -1) {
				if (lemp->lxdebuglevel >= 2) printf("NEST : tracing from %d to %d, ", stateno, gt);
				int m = find_nested_goto(lemp, gt, nest_type, isvar, destname);
				if (m == -1) return -1;
				else return m;
			}
		}
		else if (lemp->lxdebuglevel >= 2) printf("no states for state %d\n", stateno);
	}
	return -1;
}

int find_mode(struct lemon* lemp, int stateno, char * origmode) {
	int state_max = state_count(lemp);
	struct LxState* state = find_state(lemp, stateno);
	if (state != NULL) {
		if (states_mode == NULL) {
			states_mode = malloc(state_max*sizeof(int));
			memset(states_mode, 0, state_max*sizeof(int));
		}
		states_mode[stateno]++;
		if (states_mode[stateno] != 1)  {
			if (lemp->lxdebuglevel >= 2) printf("find_mode: loop detected, ");
			return -1;
		}
		assert((state->code == 0) || (state->is_leaf != 0));
		int states = get_tran_num(state);
		if (states > 0) {
			for (int i = 1; i <= states; i++) {
				struct LxTransition* tx = get_tx(state, i);
				if (tx != NULL) {
					int needs_free = false;
					char * mode = get_mode(tx);
					if (mode != NULL) {
						if (strcmp(mode, origmode) != 0) return state->state_id;
					}
					if((tx->ch0 == 0) && (tx->ch1 == 0)){
						if (lemp->lxdebuglevel >= 2) printf("/*loop --> %d*/, ", tx->next_state->state_id);
					}
					int gt = get_goto(tx);
					if (gt != -1) {
						int m = find_mode(lemp, gt, origmode);
						if (m == -1) return -1;
						else return m;
					}
					else if (lemp->lxdebuglevel >= 2) printf("no goto for state %d\n", stateno);
				}
			}
		}
		else if(state->not_transition == 0){
			int gt = get_nested_goto(lemp, state);
			if (gt != -1) {
				int m = find_mode(lemp, gt, origmode);
				if (m == -1) return -1;
				else return m;
			}
		}
		else if (lemp->lxdebuglevel >= 2) printf("no states for state %d\n", stateno);
	}
	return -1;
}

int find_action(struct lemon* lemp, int stateno, char * desired_name) {
	struct LxState* state = find_state(lemp, stateno);
	if (state == NULL) {
		if (lemp->lxdebuglevel >= 2) printf("state %d not found, ", stateno);
	} else {
		assert((state->code == 0) || (state->is_leaf != 0));
		int states = get_tran_num(state);
		if (states > 0) {
			for (int i = 1; i <= states; i++) {
				struct LxTransition* tx = get_tx(state, i);
				if (tx == NULL) {
				} else {
					int needs_free = false;
					if((tx->ch0 == 0) && (tx->ch1 == 0)){
						if (lemp->lxdebuglevel >= 2) printf("/*loop --> %d*/\n", tx->next_state->state_id);
					}else{
						char * name = get_name(state, tx, &needs_free);
						if (name != NULL) {
							if (strcmp(name, desired_name) == 0) {
								if (needs_free == true) free(name);
								int gt = get_goto(tx);
								if (gt != -1) {
									int act = find_action(lemp, gt, desired_name);
									if (act != -1) return act;
								}
								else if (lemp->lxdebuglevel >= 2) printf("no goto for state %d, ", stateno);
							}
						}
					}
				}
			}
		}
		else if(state->code != 0){
			return state->state_id;
		}
		else if (lemp->lxdebuglevel >= 2) printf("no states for state %d, ", stateno);
	}
	return -1;
}

void trace(struct lemon* lemp, int stateno) {
	int state_max = state_count(lemp);
	struct LxState* state = find_state(lemp, stateno);
	if (state == NULL) printf("state %d not found\n", stateno);
	else {
		if (states_trace == NULL) {
			states_trace = malloc(state_max*sizeof(int));
			memset(states_trace, 0, state_max*sizeof(int));
		}
		states_trace[stateno]++;
		if (states_trace[stateno] != 1) {
			printf("trace: loop detected, ");
			return;
		}
		assert((state->code == 0) || (state->is_leaf != 0));
		int states = get_tran_num(state);
		if (states > 0) {
			printf("found %d sub states\n", states);
			for (int i = 1; i <= states; i++) {
				struct LxTransition* tx = get_tx(state, i);
				if (tx == NULL) {
					printf("tx not found for state sub state id %d\n", i);
				} else {
					int needs_free = false;
					if((tx->ch0 == 0) && (tx->ch1 == 0)){
						printf("/*loop --> %d*/, ", tx->next_state->state_id);
					}else{
						char * name = get_name(state, tx, &needs_free);
						printf("mode = %s, ", tx->mode);
						if (name == NULL) printf("no name for state sub state id %d\n", i);
						else {
							printf("name = %s, ", name);
							if (find_action(lemp, stateno, name) == -1) {
								printf("no associated action for %s, ", name);
							}
							int gt = get_goto(tx);
							if (gt != -1) {
								int m = find_mode(lemp, gt, get_mode(tx));
								if (m != -1) {
									printf("mode found: %d, ", m);
									printf("tracing from %d to %d\n", stateno, m);
									trace(lemp, m);
								}
								else printf("no mode pointer found, ");
								int n = find_nested_goto(lemp, gt, NEST_LEAVE, false, name);
								nest_have = 0;
								if (n != -1) {
									printf("nest leave found: %d, ", n);
									printf("tracing from %d to %d\n", stateno, n);
									trace(lemp, n);
								}
								else printf("no nest leave found, ");
								printf("tracing from %d to %d\n", stateno, gt);
								trace(lemp, gt);
							}
							else printf("no goto for state %d\n", stateno);
							if (needs_free == true) free(name);								
						}
					}
				}
			}
		}
		else if(state->not_transition == 0){
			int gt = get_nested_goto(lemp, state);
			if (gt != -1) {
				printf("tracing from %d to %d\n", stateno, gt);
				trace(lemp, gt);
			}
		}
		else printf("no states for state %d\n", stateno);
	}
}
// 		for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
// 			if((tx->ch0 == 0) && (tx->ch1 == 0)){
// 				fprintf(out, "\n  /*loop --> %d*/\n", tx->next_state->state_id);(*lineno)++;
// 			}else{
// 				lx_generate_conditions_trace(lemp, out, lineno, curr_state, tx);
// 				if(tx->tx_type == NOT_TX){
// 											puts("NOT_TXSTATE_START");
// 					lx_generate_leaf_trace(lemp, out, lineno, curr_state, 1);
// 					lx_generate_jump_trace(lemp, out, lineno, curr_state, 1);
// 											puts("NOT_TXSTATE_END");
// 				}else{
// 					if(curr_state->is_leaf == 1){
// 						if((curr_state->not_transition != 0) && (curr_state->not_transition != tx)){
// 							if(tx->tx_type == INIT_TX){
// 											puts("INIT_TXSTATE_START");
// 								lx_generate_send_trace(lemp, out, curr_state);
// 											puts("INIT_TXSTATE_END");
// 							}
// 						}
// 					}
// 				}
// 				fprintf(out, "goto &STATE%d\n", tx->next_state->state_id);
// 			}
// 		}
// 		if(curr_state->not_transition == 0){
// 			puts("ACTIONSTATE_START");
// 			lx_generate_leaf_trace(lemp, out, lineno, curr_state, 0);
// 			lx_generate_jump_trace(lemp, out, lineno, curr_state, 0);
// 			puts("ACTIONSTATE_END");
// 		}

void findtrace(struct lemon* lemp, FILE* out, int *lineno) {
	trace(lemp, 1);
	puts("");
}

static void lx_generate_send_bt(struct lemon* lemp, FILE* out, struct LxState *curr_state){
	/* generate user action code if specified */
	if(curr_state->code != 0){
		fprintf(out, "  LX_ACTION(%d);", curr_state->state_id);
	}
}

static void lx_generate_conditions_bt(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, struct LxTransition *tx) {
	if(tx->ch0 == 0){
		switch(tx->ch1){
			case LXCLASS_LETTER:
				fprintf(out, "  if(LX_ISLETTER(ch)==1)");
				break;
			case LXCLASS_DIGIT:
				fprintf(out, "  if(LX_ISDIGIT(ch)==1)");
				break;
			case LXCLASS_WORD:
				fprintf(out, "  if(LX_ISWORD(ch)==1)");
				break;
			case LXCLASS_SPACE:
				fprintf(out, "  if(LX_ISSPACE(ch)==1)");
				break;
			case LXCLASS_DOT:
				/* DOT transition should always be the last one */
				assert(tx->next_transition == 0);
				assert(curr_state->dot_transition == tx);
				fprintf(out, "  if(ch != 0)");
				break;
			default:
				printf("Internal error: unknown range\n");
				exit(1);
		}
	}else if(tx->ch1 == 0){
	str_new(q);
	str_new(ch);
	str_insert_char(ch, tx->ch0);
	str_insert_char(ch, '\0');
	str_insert_string(q, ch.string);
	str_free(ch);
	if (tx->is_variable) {
		if (tx->variable_name[0] == '"') fprintf(out, "%s[%d] ", tx->variable_name, tx->idx);
		else fprintf(out, "'%s' ", q.escaped.string);
	} else fprintf(out, "'%s' ", q.escaped.string);
	str_free(q);
	fprintf(out, "/* mode = %s */ ", tx->mode);
	fprintf(out, "-> ");
	}
}

static void lx_generate_leaf_bt(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, int tx_type){
	if(tx_type == NOT_TX){
		if(curr_state->dot_transition == 0){
			lx_generate_send_bt(lemp, out, curr_state);
		}
		return;
	}
	assert(tx_type == REGULAR_TX);

	/* if this is not a leaf state */
	if(curr_state->is_leaf == 0) {
		return;
	}

	/* if this is a leaf state */
	assert(curr_state->is_leaf == 1);

	if((curr_state->not_transition == 0) && (curr_state->dot_transition == 0)){
		lx_generate_send_bt(lemp, out, curr_state);
		fprintf(out, "\n");(*lineno)++;
	}

	fprintf(out, "\n");(*lineno)++;
}

static void lx_generate_jump_bt(struct lemon* lemp, FILE* out, int *lineno, struct LxState *curr_state, int tx_type){
	if(tx_type == REGULAR_TX){
		fprintf(out, "  ");
	}
	if(curr_state->is_leaf == 1) {
		/* if curr_state transitions to another mode, go to that mode's init state */
		if(curr_state->next_mode != 0){
			if(strcmp(curr_state->next_mode, "<") != 0){
				struct LxMode* next_mode = LxMode_find(lemp, curr_state->next_mode);
				if(next_mode == 0) {
					printf("INTERNAL-ERROR:invalid next-mode in state: %s\n", curr_state->next_mode);
					exit(1);
				}
				if(next_mode->init_state != curr_state->init_mode->init_state){
					fprintf(out, "LX_ENTER_NESTING(%d);", curr_state->init_mode->init_state->state_id);
				}else{
					fprintf(out, "LX_RENEW_NESTING;");
				}
				if(tx_type == REGULAR_TX){
					fprintf(out, "\n  ");(*lineno)++;
				}
				fprintf(out, "TAG2 goto S%d; /* by retn_state */", next_mode->init_state->state_id);
			}else{
				/* if next mode is <, return to calling mode */
				fprintf(out, "if(LX_LEAVE_NESTING() == 1){TAG2 goto L0;}");
				if(tx_type == REGULAR_TX){
					fprintf(out, "\n  ");(*lineno)++;
				}
				fprintf(out, "TAG2 goto S%d; /* by next_state */", curr_state->init_mode->init_state->state_id);
			}
		}else{
			if(curr_state->dot_transition == 0){
				fprintf(out, "TAG2 goto S%d; /* by init_state */", curr_state->init_mode->init_state->state_id);
			}
		}
	}else if(curr_state->goto_state != 0){
		if(curr_state->dot_transition == 0){
			fprintf(out, "TAG2 goto S%d; /* by goto_state */", curr_state->goto_state->state_id);
		}
	}
	if(tx_type == REGULAR_TX){
		fprintf(out, "\n");(*lineno)++;
	}
}

static void lx_generate_output_bt(struct lemon* lemp, FILE* out, int *lineno){
	puts("tracing state machine");
	// all output generated should be enough to produce a tracing structure, possibly via a linked list (queue) or via a environment based linked list tho this has not been tested
	
	// each item shall contain a trace and if it brances, a call to an external item and repeat for that item
	
	// function call map
	
	// this appears like a fairly simple structure design layout
	
	/*
	example:
	1> "\"PA\""[0] > 2
	2> > 3
	3> > 4
	4> > 5
	5> ACTION(5)
	
	1> INITMODE
	1> '<' > 13
	13> > 14
	14> loop -> 15 OR ch != 0 > 17
	loop->15
		15> '\n' || ' ' > 18 OR ch != 0 > 16
		'\n'||' '
			18> ACTION(18)  NEST_ENTER goto S22; //by retn_state
			22> HD
		ch!=0
			16> NULL (  goto S15;)
	ch!=0
		17> NULL (  goto S15; )
		
	a[0] = INITMODE=&b
		b[0] = "\"PA\""[0]=&c
			c[0] = 2
			c[1] = 3
			c[1] = 4
			c[1] = 5
			c[1] = ACTION(5)
		b[1] = "'<'" =&d
			d[0] = 14
			d[1] = "loop -> 15"=&e
				e[0] = "'\n' || ' '"=&f
					f[0] = "ACTION(18)  NEST_ENTER goto S22; //by retn_state"=&g
						g[0] = HD
				e[1] = "ch != 0"=&h
					h[0]="NULL"=&e
		b[2] = "ch != 0"=&i
			i[0] = "NULL"=&e
	a[1] = HD=&j
		j[0] = "L"

	
	*/
	
	// based upon looking at evalwrap.c from my modified eval11 library it SHOULD be possible, if used correctly, to store any variable type as a string in the environment
	// lets attempt to store the environment B in the environment A
	env_t A = env__new();
	A = env__add(A, "A");
	env_t B = env__new();
	B = env__add(B, "B");
	// according to evalwrap the first thing we need to do is construct a string, however we will instead modify its existing function to suit our purposes so the function does almost all the work for us
	A = env__add_env(A, "s", &B);
	env_t * C = env__get_env(A, "s");
	pi(env__size(B)); 	pi(env__size(*C));
	puts("adding C to B");
	B = env__add(B, "C");
	pi(env__size(B)); 	pi(env__size(*C));
	puts("adding D to C");
	*C = env__add(*C, "D");
	pi(env__size(B)); 	pi(env__size(*C));
	if (env__size(A)) ps(A[0]);
	if (env__size(B)) ps(B[0]);
	if (env__size(*C)) ps(*C[0]);
	C = NULL;
	env__free(B);
	env__free(A);
	
	// this is expected to fail but who knows, we might just succeed
	
	// INITMODE state var actions aswell as lexer mode changes can be found by following their goto's, eg
	/*
	1> "\"PA\""[0] > 2
	2> > 3
	3> > 4
	4> > 5
	5> ACTION(5)
	
	1> INITMODE
	1> '<' > 13
	13> > 14
	14> loop -> 15 OR ch != 0 > 17
	loop->15
		15> '\n' || ' ' > 18 OR ch != 0 > 16
		'\n'||' '
			18> ACTION(18)  NEST_ENTER goto S22; //by retn_state
			22> HD
		ch!=0
			16> NULL (  goto S15;)
	ch!=0
		17> NULL (  goto S15; )
	
	upon debugging the execution it is discovered that action code is stored in curr_state->code, this may eliminate the need for tracing all together... appears this is not the case as according to the following
	
	if(curr_state->code != 0){
		fprintf(out, "  LX_ACTION(%d);", curr_state->state_id);
	}else{
		fprintf(out, "  ");
	}
	
	we would still need to follow the states
	*/
	for(struct LxState* curr_state = lemp->headstate; curr_state != 0; curr_state = curr_state->next_state){
		fprintf(out, "S%d:\n", curr_state->state_id);(*lineno)++;
		assert((curr_state->code == 0) || (curr_state->is_leaf != 0));
// 	LX_PRINT_STATE_bt(out, curr_state);
		for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
			fprintf(out, nspS);
			if (curr_state->dot_transition) txd(out, curr_state->dot_transition->tx_type);
			else fprintf(out, "%-*s", nsp, "none");
			txd(out, tx->tx_type);
			fprintf(out, nspE);
			if((tx->ch0 == 0) && (tx->ch1 == 0)){
				fprintf(out, "  /*loop --> %d*/\n", tx->next_state->state_id);(*lineno)++;
			}else{
				lx_generate_conditions_bt(lemp, out, lineno, curr_state, tx);
				fprintf(out, "{");
				if(tx->tx_type == NOT_TX){
					lx_generate_leaf_bt(lemp, out, lineno, curr_state, 1);
					lx_generate_jump_bt(lemp, out, lineno, curr_state, 1);
				}else{
					if(curr_state->is_leaf == 1){
						if((curr_state->not_transition != 0) && (curr_state->not_transition != tx)){
							if(tx->tx_type == INIT_TX){
								lx_generate_send_bt(lemp, out, curr_state);
							}
						}else if((curr_state->dot_transition != 0) && (curr_state->dot_transition != tx)){
							if(tx->tx_type == INIT_TX){
								lx_generate_send_bt(lemp, out, curr_state);
							}
						}
					}
			fprintf(out, "TAG goto S%d;", tx->next_state->state_id);
				}
				fprintf(out, "}");
				fprintf(out, "\n");(*lineno)++;
			}
		}

		if(curr_state->not_transition == 0){
			lx_generate_leaf_bt(lemp, out, lineno, curr_state, 0);
			lx_generate_jump_bt(lemp, out, lineno, curr_state, 0);
		}
	}
}


static void lx_generate_output(struct lemon* lemp, FILE* out, int *lineno){
	fprintf(out, "  LX_ADVANCE(lxpLexer->lxstate);\n");(*lineno)++;
	fprintf(out, "L0:\n");(*lineno)++;
	if (lemp->lxdebuglevel >= 1) {
		fprintf(out, "  printf(\"L0:%%d\\n\", lxpLexer->lxstate);\n");(*lineno)++;
	}
	fprintf(out, "  switch(lxpLexer->lxstate) {\n");(*lineno)++;
	for(struct LxState* curr_state = lemp->headstate; curr_state != 0; curr_state = curr_state->next_state){
		fprintf(out, "    case %d:goto S%d;\n",
			curr_state->state_id, curr_state->state_id);(*lineno)++;
	}
	fprintf(out, "  }\n");(*lineno)++;

	int list_generated=0;
	env_t state_env = env__new();
	for(struct LxState* curr_state = lemp->headstate; curr_state != 0; curr_state = curr_state->next_state){
		fprintf(out, "S%d:\n", curr_state->state_id);(*lineno)++;
		assert((curr_state->code == 0) || (curr_state->is_leaf != 0));

		if (lemp->lxdebuglevel >= 1) {
			fprintf(out, "  printf(\"current state: %d: (row %%d, column %%d): char hex:0x%%X (%%c)\\n\", lxpLexer->lxrow, lxpLexer->lxcol, ch, ((ch>= 32) && (ch <= 127))?ch:' ');\n"
				,curr_state->state_id
			);(*lineno)++;
		}
		if (lemp->lxdebuglevel >= 2) {
//       LX_PRINT_STATE(out, curr_state);
		}
		for(struct LxTransition* tx = curr_state->head_transition; tx != 0; tx = tx->next_transition){
		if (lemp->lxdebuglevel >= 2) {
				fprintf(out, nspS);
				if (curr_state->dot_transition) txd(out, curr_state->dot_transition->tx_type);
				else fprintf(out, "%-*s", nsp, "none");
				txd(out, tx->tx_type);
				fprintf(out, nspE);
		}
			LX_PRINT_TRANSITION(out, curr_state, tx);
			if((tx->ch0 == 0) && (tx->ch1 == 0)){
				fprintf(out, "  /*loop --> %d*/\n", tx->next_state->state_id);(*lineno)++;
			}else{
				lx_generate_conditions(lemp, out, lineno, curr_state, tx);
				fprintf(out, "{");
				if(tx->tx_type == NOT_TX){
					lx_generate_leaf(lemp, out, lineno, curr_state, 1);
					lx_generate_jump(lemp, out, lineno, curr_state, 1);
				}else{
					if(curr_state->is_leaf == 1){
						if((curr_state->not_transition != 0) && (curr_state->not_transition != tx)){
							if(tx->tx_type == INIT_TX){
								lx_generate_send(lemp, out, curr_state, tx->variable_name);
							}
						}else if((curr_state->dot_transition != 0) && (curr_state->dot_transition != tx)){
							if(tx->tx_type == INIT_TX){
								lx_generate_send(lemp, out, curr_state, tx->variable_name);
							}
						}
					}
					if (!tx->is_variable) {
						if(tx->is_capturing == 1){
							fprintf(out, "LX_CAPTURE(curr_pos, curr_len);");
						}
					}
#define GENOUT char * envname = env__get_name(ep, *ep); int envnum = atoi(env__get(ep, *ep)); if (lemp->lxdebuglevel >= 2) { puts(""); pi(curr_state->state_id); if(tx->is_variable) ps(tx->variable_name); } if (states_ne != NULL) { memset(states_ne, 0, state_count(lemp)*sizeof(int));} int n = find_nested_goto(lemp, curr_state->state_id, NEST_ENTER, false, envname); nest_have = 0; memset(states_ne, 0, state_count(lemp)*sizeof(int)); if (lemp->lxdebuglevel >= 2) pi(n); int nn = find_nested_goto(lemp, curr_state->state_id, NEST_LEAVE, tx->is_variable, envname); nest_have = 0; memset(states_nl, 0, state_count(lemp)*sizeof(int)); if (lemp->lxdebuglevel >= 2) pi(nn); int nnn = find_action(lemp, envnum, envname); int nnnn = find_mode(lemp, curr_state->state_id, envname); memset(states_mode, 0, state_count(lemp)*sizeof(int)); int stateval = 0; if (n != -1 && nnnn != -1) stateval = n; else stateval = nnn; fprintf(out, "%sif (LX_LOOKAHEAD(%s) == -1) { LX_RESET; LX_CAPTURE(curr_pos, strlen(%s)); LX_LOOKAHEAD_ADVANCE(%s, %d); goto S%d /*nest enter goto %d, nest exit goto %d, action goto %d, find mode %d, goto %d*/;", loop==1?" else ":"", envname, envname, envname, stateval, stateval, n, nn, nnn, nnnn, get_goto(tx)); fprintf(out, "}%s", loop==1?" ":""); loop = 1;
			if (curr_state->state_id == 1 && list_generated == 0) {
				for(struct LxState* curr_state2 = lemp->headstate; curr_state2 != 0; curr_state2 = curr_state2->next_state){
					for(struct LxTransition* tx2 = curr_state2->head_transition; tx2 != 0; tx2 = tx2->next_transition){
						if (tx2->is_variable) {
							if (tx2->variable_name != NULL) {
								str_new(sint);
								str_insert_string(sint, tx2->variable_name);
								str_insert_string(sint, "=");
								str_insert_int(sint, curr_state2->state_id);
								state_env = env__add(state_env, sint.string);
								state_env = env__clean(state_env);
								str_free(sint);
							}
						}
					}
				}
				list_generated = 1;
			}
			int loop = 0;
			{
				if (tx->is_variable) {
					// search for similar names
					if (state_env) {
						env_t ep;
						for (ep = state_env; *ep; ep++) {
							if ((*ep)[1] == '\\') {
								if (bcmpcq__2(tx->variable_name+2, strlen((*ep)+2), (*ep)+2, strlen((*ep)+2)) != -1) {
									GENOUT
								}
							} else if ((*ep)[1] == '"') {
								if (bcmpcq__2(tx->variable_name+1, strlen((*ep)+1), (*ep)+1, strlen((*ep)+1)) != -1) {
									GENOUT
								}
							} else {
								if (bcmpcq__2(tx->variable_name, strlen(*ep), *ep, strlen(*ep)) != -1) {
									GENOUT
								}
							}
						}
					}
				}
			}
					if (loop == 1) {
						fprintf(out, "else { LX_CAPTURE(curr_pos, 1);");
					}
					fprintf(out, "LX_ADVANCE(%d);", tx->next_state->state_id);
					fprintf(out, "goto S%d; /*1*/", tx->next_state->state_id);
					if (loop == 1) {
						fprintf(out, "}");
					}
// 					if (!tx->is_variable) fprintf(out, "%sLX_ADVANCE(%d);goto S%d; /*1*/%s", loop==1?"else {":"", tx->next_state->state_id, tx->next_state->state_id, loop==1?"}":"");
				}
				fprintf(out, "}");
				fprintf(out, "\n");(*lineno)++;
			}
		}

		if(curr_state->not_transition != 0){
			lx_generate_leaf(lemp, out, lineno, curr_state, 0);
			fprintf(out, "  ");
			if(curr_state->not_transition->is_capturing == 1){
				fprintf(out, "LX_CAPTURE(curr_pos, curr_len);");
			}
			fprintf(out, "LX_ADVANCE(%d);goto S%d; /*2*/\n", curr_state->not_transition->next_state->state_id, curr_state->not_transition->next_state->state_id);(*lineno)++;
		}else{
			lx_generate_leaf(lemp, out, lineno, curr_state, 0);
			lx_generate_jump(lemp, out, lineno, curr_state, 0);
		}
	}
#if LEMONEX_DBG>=2
	puts("printing env");
	env__list(state_env);
#endif
	env__free(state_env);

	/* generate undefined warnings */
	for(int i=0; i<lemp->nsymbol; i++){
		if((lemp->symbols[i]->type == TERMINAL) && (lemp->symbols[i]->defined == 0)) {
			printf("WARNING:Symbol not defined in lexer:%s\n", lemp->symbols[i]->name);
		}
	}
}
#endif
