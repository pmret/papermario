.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_return
/* 0E9348 802C4998 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E934C 802C499C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E9350 802C49A0 0C0B0FCF */  jal   kill_script
/* 0E9354 802C49A4 00000000 */   nop   
/* 0E9358 802C49A8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E935C 802C49AC 240200FF */  addiu $v0, $zero, 0xff
/* 0E9360 802C49B0 03E00008 */  jr    $ra
/* 0E9364 802C49B4 27BD0018 */   addiu $sp, $sp, 0x18

