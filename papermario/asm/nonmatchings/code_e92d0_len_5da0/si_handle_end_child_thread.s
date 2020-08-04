.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_end_child_thread
/* 0EB7A4 802C6DF4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB7A8 802C6DF8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB7AC 802C6DFC 0C0B0FCF */  jal   kill_script
/* 0EB7B0 802C6E00 00000000 */   nop   
/* 0EB7B4 802C6E04 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB7B8 802C6E08 0000102D */  daddu $v0, $zero, $zero
/* 0EB7BC 802C6E0C 03E00008 */  jr    $ra
/* 0EB7C0 802C6E10 27BD0018 */   addiu $sp, $sp, 0x18

