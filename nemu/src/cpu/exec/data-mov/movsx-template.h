#include "cpu/exec/template-start.h"
#define instr movsx

static void do_execute (){
	if(DATA_BYTE ==2){
		int16_t signExtend = (int16_t)((int8_t) op_src->val);
		OPERAND_W(op_dest , signExtend);
	}else{
		if(ops_decoded.opcode == (0xbf | 0x100)){
			int32_t signExtend = (int32_t)((int16_t) op_src->val);
			OPERAND_W(op_dest , signExtend);
		}else{
			int32_t signExtend = (int32_t)((int8_t) op_src->val);
			OPERAND_W(op_dest , signExtend);
		}
	}
	
	print_asm_template2();
}

make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"