.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osUnmapTLBAll
/* 041D60 80066960 40085000 */  mfc0  $t0, $10
/* 041D64 80066964 2409001E */  addiu $t1, $zero, 0x1e
/* 041D68 80066968 3C0A8000 */  lui   $t2, 0x8000
/* 041D6C 8006696C 408A5000 */  mtc0  $t2, $10
/* 041D70 80066970 40801000 */  mtc0  $zero, $2
/* 041D74 80066974 40801800 */  mtc0  $zero, $3
.L80066978:
/* 041D78 80066978 40890000 */  mtc0  $t1, $0
/* 041D7C 8006697C 00000000 */  nop   
/* 041D80 80066980 42000002 */  tlbwi 
/* 041D84 80066984 00000000 */  nop   
/* 041D88 80066988 00000000 */  nop   
/* 041D8C 8006698C 2129FFFF */  addi  $t1, $t1, -1
/* 041D90 80066990 0521FFF9 */  bgez  $t1, .L80066978
/* 041D94 80066994 00000000 */   nop   
/* 041D98 80066998 40885000 */  mtc0  $t0, $10
/* 041D9C 8006699C 03E00008 */  jr    $ra
/* 041DA0 800669A0 00000000 */   nop   

/* 041DA4 800669A4 00000000 */  nop   
/* 041DA8 800669A8 00000000 */  nop   
/* 041DAC 800669AC 00000000 */  nop   


