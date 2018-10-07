// line 5570
// inside static void parseonetoken(struct pstate *psp)
// inside   switch( psp->state ){
// inside     case WAITING_FOR_CLASS_TOKEN:
#ifdef LEMONEX
    case WAITING_FOR_INTEGRATIONMODE_1:
      if( strcmp(x, "ON") == 0 ){
        psp->gp->lxintegration = 1;
        psp->state = WAITING_FOR_INTEGRATIONMODE_2;
      } else if( strcmp(x, "OFF") == 0 ){
        psp->gp->lxintegration = 0;
        psp->state = WAITING_FOR_INTEGRATIONMODE_2;
      }else{
        ErrorMsg(psp->filename, psp->tokenlineno,
          "Integration mode value must be ON or OFF, received \"%s\".",x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_DECL_ERROR;
      }
      break;
    case WAITING_FOR_INTEGRATIONMODE_2:
      if( x[0] == '.' ){
        psp->state = WAITING_FOR_DECL_OR_RULE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \".\" following integration mode, saw '%s'.", x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_DECL_ERROR;
      }
      break;
    case WAITING_FOR_NESTINGDEPTH_1:
      if( (x[0] > 0) && (x[0] <= 9) ){
        psp->gp->lxnestingdepth = atol(x);
        psp->state = WAITING_FOR_NESTINGDEPTH_2;
      }else{
        ErrorMsg(psp->filename, psp->tokenlineno,
          "Nesting depth value must be a non-zero positive integer, received \"%s\".",x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_DECL_ERROR;
      }
      break;
    case WAITING_FOR_NESTINGDEPTH_2:
      if( x[0] == '.' ){
        psp->state = WAITING_FOR_DECL_OR_RULE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \".\" following nesting depth, saw '%s'.", x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_DECL_ERROR;
      }
      break;
    case WAITING_FOR_ENCODING_ID_1:
      if( isupper(x[0]) ){
        psp->gp->lxencoding = x;
        psp->state = WAITING_FOR_ENCODING_ID_2;
      }else{
        ErrorMsg(psp->filename, psp->tokenlineno,
          "Encoding name must be an uppercase ID \"%s\".",x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_DECL_ERROR;
      }
      break;
    case WAITING_FOR_ENCODING_ID_2:
      if( x[0] == '.' ){
        psp->state = WAITING_FOR_DECL_OR_RULE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \".\" following encoding name, saw '%s'.", x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_DECL_ERROR;
      }
      break;
    case WAITING_FOR_ARROW_LEX:
      if( x[0]==':' && x[1]==':' && x[2]=='=' ){
        if(psp->first_mode == 0){
          psp->first_mode = LxMode_new(psp, "INITMODE");
        }
        psp->curr_state = psp->last_mode->init_state;
        psp->is_capturing = 1;
        psp->nstarcount = 0;
        psp->state = IN_REGEX;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \":\" following the LHS symbol \"%s\".",
          psp->lhs->name);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case IN_REGEX:
      if( x[0]=='!' ){
        psp->is_capturing = 0;
      }else if( x[0]=='"' ){
        Lexer_process_regex(psp, x+1);
        psp->is_capturing = (psp->lastlxsym==0)?0:1;
      }else if( x[0]=='.' ){
#if 0
        if(psp->nstarcount == 0){
          ErrorMsg(psp->filename,psp->tokenlineno,
            "Regular expression matches empty string.",
            psp->lhs->name);
          psp->errorcnt++;
          psp->state = RESYNC_AFTER_RULE_ERROR;
        }else
#endif
        if(psp->curr_state != 0){
          if(psp->curr_state->is_leaf != 0){
            printf("INTERNAL-ERROR:multiple final-states at state: %d\n", psp->curr_state->state_id);
            exit(1);
          }
          if(psp->lastlxsym != 0) {
            psp->lastlxsym->defined = 1;
          }
          psp->curr_state->is_leaf = 1;
          psp->curr_state->matchedsym = psp->lastlxsym;
          psp->curr_state->init_mode = psp->last_mode;
          if(psp->curr_state->star_state != 0){
            if(psp->curr_state->star_state->is_leaf == 1){
              ErrorMsg(psp->filename,psp->tokenlineno,
                "Overlapping symbols defined, second definition at: '%s'.", x);
              psp->errorcnt++;
              psp->state = RESYNC_AFTER_RULE_ERROR;
            }
            psp->curr_state->star_state->is_leaf = 1;
            psp->curr_state->star_state->matchedsym = psp->curr_state->matchedsym;
            psp->curr_state->star_state->init_mode = psp->curr_state->init_mode;
          }
          psp->state = WAITING_FOR_DECL_OR_RULE;
        }else{
          psp->state = WAITING_FOR_DECL_OR_RULE;
        }
      }else if( x[0]=='$' ){
          psp->state = WAITING_FOR_VARIABLE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \"$\" or \"\"\" or \"!\" or \".\" following \"::=\", saw '%s'.", x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case WAITING_FOR_VARIABLE:
	  // $var shall be inserted into variables the same as text, but shall compare against the specified variable name or literal string
	  // if x starts with ", prepend " to the end
	  if( x[0]=='"') {
		strcat(x, "\"");
	  }
      if( x[0]=='!' ){
        psp->is_capturing = 0;
      }else if( x[0]=='"' || isalpha(x[0]) ){
#if LEMONEX_DBG>=2
		printf("x = %s\n", x);
#endif
		str_new(ss);
		str_new(ss2);
		str_insert_string(ss, x);
		str_insert_string(ss2, "\"");
		str_insert_string(ss2, ss.string);
#warning str_insert_string(ss2, ss.string) should use ss.json.string here but is incompatible due to bashes \c escape needing to be properly detected and escaped, and thus is not included in json as it is a bash escape character, thereby omiting all occurences of the letter 'c' from json strings
		str_insert_string(ss2, "\"");
		x_e = env__add2(x_e, ss.string);
		x_e = env__add2(x_e, ss2.string);
#if LEMONEX_DBG>=2
// 		str_info(ss);
// 		str_info(ss2);
// 		pi(env__getposition(x_e, ss.string));
// 		pi(env__getposition(x_e, ss2.string));
#endif
		str_free(ss2);
		str_free(ss);
        Lexer_process_variable(psp, x_e[x_e_idx], x_e[x_e_idx+1]);
		x_e_idx++;
		x_e_idx++;
        psp->is_capturing = (psp->lastlxsym==0)?0:1;
      }else if( x[0]=='.' ){
#if 0
        if(psp->nstarcount == 0){
          ErrorMsg(psp->filename,psp->tokenlineno,
            "Regular expression matches empty string.",
            psp->lhs->name);
          psp->errorcnt++;
          psp->state = RESYNC_AFTER_RULE_ERROR;
        }else
#endif
        if(psp->curr_state != 0){
          if(psp->curr_state->is_leaf != 0){
            printf("INTERNAL-ERROR:multiple final-states at state: %d\n", psp->curr_state->state_id);
            exit(1);
          }
          if(psp->lastlxsym != 0) {
            psp->lastlxsym->defined = 1;
          }
          psp->curr_state->is_leaf = 1;
          psp->curr_state->matchedsym = psp->lastlxsym;
          psp->curr_state->init_mode = psp->last_mode;
          if(psp->curr_state->star_state != 0){
            if(psp->curr_state->star_state->is_leaf == 1){
              ErrorMsg(psp->filename,psp->tokenlineno,
                "Overlapping symbols defined, second definition at: '%s'.", x);
              psp->errorcnt++;
              psp->state = RESYNC_AFTER_RULE_ERROR;
            }
            psp->curr_state->star_state->is_leaf = 1;
            psp->curr_state->star_state->matchedsym = psp->curr_state->matchedsym;
            psp->curr_state->star_state->init_mode = psp->curr_state->init_mode;
          }
          psp->state = WAITING_FOR_DECL_OR_RULE;
        }else{
          psp->state = WAITING_FOR_DECL_OR_RULE;
        }
      }else if( x[0]=='$' ){
          psp->state = WAITING_FOR_VARIABLE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \"$\" or \"\"\" or \"!\" or \".\" following \"::=\", saw '%s'.", x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case IN_NEXTMODE:
      if( isupper(x[0]) || (x[0] == '<')){
        psp->last_state->next_mode = x;
        psp->state = NEXT_MODE_1;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Mode name must be an uppercase ID \"%s\".",x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case NEXT_MODE_1:
      if( x[0]==']' ){
        psp->state = WAITING_FOR_DECL_OR_RULE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \"]\" following the next lexer mode symbol \"%s\".",
          psp->last_state->next_mode);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case WAITING_FOR_MODE_ID_1:
      if( isupper(x[0]) ){
        LxMode_new(psp, x);
        psp->state = WAITING_FOR_MODE_ID_2;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Mode name must be an uppercase ID \"%s\".",x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case WAITING_FOR_MODE_ID_2:
      if( x[0] == '.' ){
        psp->state = WAITING_FOR_DECL_OR_RULE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \".\" following mode name, saw '%s'.", x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case WAITING_FOR_DEBUG_LEVEL_1:
      if (strcmp(x, "LOW") == 0) {
        psp->gp->lxdebuglevel = 1;
        psp->state = WAITING_FOR_DEBUG_LEVEL_2;
      }else if (strcmp(x, "MEDIUM") == 0) {
        psp->gp->lxdebuglevel = 2;
        psp->state = WAITING_FOR_DEBUG_LEVEL_2;
      }else if (strcmp(x, "HIGH") == 0) {
        psp->gp->lxdebuglevel = 3;
        psp->state = WAITING_FOR_DEBUG_LEVEL_2;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Debug level must be LOW, MEDIUM or HIGH: \"%s\".",x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
    case WAITING_FOR_DEBUG_LEVEL_2:
      if( x[0] == '.' ){
        psp->state = WAITING_FOR_DECL_OR_RULE;
      }else{
        ErrorMsg(psp->filename,psp->tokenlineno,
          "Expected to see a \".\" following debug level, saw '%s'.", x);
        psp->errorcnt++;
        psp->state = RESYNC_AFTER_RULE_ERROR;
      }
      break;
#endif
