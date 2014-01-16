//DT_SSE LIB.h

#include "DTSSELIB.h"
#include <memory.h> 

void SSE_memcpy(void* dest, void* src, unsigned long SizeInBytes)
{
	unsigned long Loop = SizeInBytes>>7;//Divid 128
	unsigned long BlockSize =  Loop<<7;

	_asm
	{
		pusha;
		mov ecx,BlockSize    ; ecx = # of bytes to copy from x[] to y[]
		mov eax,1    ; eax = number of times to perform "rep movsd" copy
			mov esi,src  ;// esi = ->"x"
		mov edi,dest    ;// edi = ->"y"
		add esi,ecx         ; //esi ->the end of the last element of x to be copied
		add edi,ecx         ; //edi ->the end of the last element of y to be copied
		shr ecx,3           ; //divide the number of bytes to copy by 8 to figure
		//  ;    out how many quad words are to be copied from
		//   ;    x[] to y[]
		neg ecx             ;
		align 16            ; //align instructions to 16 byte boundary
		//===================================================================================================
repeat_measurement: //; loop over the vector copy by "num_times_to_repeat" times
		pushad          //; push all the 32 bit registers onto the stack
			// ================================================================================================
			align 16             ; //align instructions to 16 byte boundary
bytecopyloop:                  //   ; copy 128 bytes of x[] to y[] with each pass through the code below
		movdqa xmm0,[esi+8*ecx]       ; //xmm0 = [x(3),x(2),x(1),x(0)]
		movdqa xmm1,[esi+8*ecx+16]    ; //xmm1 = [x(7),x(6),x(5),x(4)]
		movdqa xmm2,[esi+8*ecx+32]    ; //xmm2 = [x(11),x(10),x(9),x(8)]
		movdqa xmm3,[esi+8*ecx+48]    ; //xmm3 = [x(15),x(14),x(13),x(12)]
		movntdq [edi+8*ecx],xmm0      ; //[y(3),y(2),y(1),y(0)] = [x(3),x(2),x(1),x(0)]
		movntdq [edi+8*ecx+16],xmm1   ; //[y(7),y(6),y(3),y(2)] = [x(7),x(6),x(5),x(4)]
		movntdq [edi+8*ecx+32],xmm2   ; //[y(11),y(10),y(5),x(4)] = [x(11),x(10),x(9),x(8)]
		movntdq [edi+8*ecx+48],xmm3   ; //[y(15),y(14),y(7),y(6)] = [x(15),x(14),x(13),x(12)]
		movdqa xmm4,[esi+8*ecx+64]    ; //xmm4 = [x(19),x(18),x(17),x(16)]
		movdqa xmm5,[esi+8*ecx+80]    ; //xmm5 = [x(23),x(22),x(21),x(20)]
		movdqa xmm6,[esi+8*ecx+96]    ; //xmm6 = [x(27),x(26),x(25),x(24)]
		movdqa xmm7,[esi+8*ecx+112]   ; //xmm7 = [x(31),x(30),x(29),x(28)]
		movntdq [edi+8*ecx+64],xmm4   ; //[y(19),y(18),y(17),y(16)] = [x(19),x(18),x(17),x(16)]
		movntdq [edi+8*ecx+80],xmm5   ; //[y(23),y(22),y(21),y(20)] = [x(23),x(22),x(21),x(20)]
		movntdq [edi+8*ecx+96],xmm6   ; //[y(27),y(26),y(25),y(24)] = [x(27),x(26),x(25),x(24)]
		movntdq [edi+8*ecx+112],xmm7  ; //[y(31),y(30),y(29),y(28)] = [x(31),x(30),x(29),x(28)]
		add ecx,16                    ;
		js bytecopyloop                   ;
		//	;===============================================================================================
		popad              ; //pop old 32 bit register values off the stack
		dec eax            ; //decrement the # of times to repeat copy test
			//	;    if eax =0 then the zero flags bit is set. 
		jnz repeat_measurement ; //if the bit is not set then loop back above to 
		//             ;    "repeating:" address and repeat instructions between
		//               ;    "repeating:" and "jnz repeating"
		popa
	}
	
	int Left = SizeInBytes-BlockSize;
	memcpy(dest+offset,src,Left);
}
