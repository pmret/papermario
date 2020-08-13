.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_end_thread
/* 0EB6FC 802C6D4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB700 802C6D50 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB704 802C6D54 0C0B0FCF */  jal   kill_script
/* 0EB708 802C6D58 00000000 */   nop   
/* 0EB70C 802C6D5C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB710 802C6D60 240200FF */  addiu $v0, $zero, 0xff
/* 0EB714 802C6D64 03E00008 */  jr    $ra
/* 0EB718 802C6D68 27BD0018 */   addiu $sp, $sp, 0x18

