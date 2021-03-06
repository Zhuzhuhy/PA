#include "cpu/exec/helper.h"
#include "cpu/decode/modrm.h"

make_helper(nop) {
	print_asm("nop");
	return 1;
}

make_helper(int3) {
	void do_int3();
	do_int3();
	print_asm("int3");

	return 1;
}

make_helper(lea) {
	ModR_M m;
	m.val = instr_fetch(eip + 1, 1);
	int len = load_addr(eip + 1, &m, op_src);
	reg_l(m.reg) = op_src->addr;

	print_asm("leal %s,%%%s", op_src->str, regsl[m.reg]);
	return 1 + len;
}

make_helper(leave){
	cpu.esp = cpu.ebp; //stackaddrsize == 32

	//if(DATA_BYTE == 2){
	//	reg_w(R_BP) = swaddr_read(cpu.esp,2);
	//	cpu.esp += 2;
	//}else if(DATA_BYTE == 4){
		reg_l(R_EBP) = swaddr_read(cpu.esp, 4);
		cpu.esp += 4;
	//}
	print_asm("leave");
	return 1;
}

make_helper(ret){
	cpu.eip = swaddr_read(cpu.esp, 4);
	cpu.esp += 4;
	print_asm("ret");
	return 0;
}

make_helper(ctd_v){
	if(ops_decoded.is_data_size_16){
		if( (reg_w(R_AX) & 0x8000 ) == 0) reg_w(R_DX) = 0x0;
		else reg_w(R_DX) = 0xffff;
	}else{
		if( (reg_l(R_EAX) & 0x80000000 ) == 0) reg_l(R_EDX) = 0x0;
		else reg_l(R_EDX) = 0xffffffff;
	}
	return 1;
}

make_helper(cld){
	unset_EFLAGS(E_DF);
	print_asm("cld");
	return 1;
}