#include "cpu/exec/template-start.h"
#define instr movsx

static void do_execute (){
	DATA_TYPE_S signExtend = 0;
	if(DATA_BYTE == 1)
		signExtend = (DATA_TYPE_S)((int8_t) op_src->val);
	else if(DATA_BYTE == 2)
		signExtend = (DATA_TYPE_S)((int16_t) op_src->val);
	OPERAND_W(op_dest , signExtend);
	print_asm_template2();
}

make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"