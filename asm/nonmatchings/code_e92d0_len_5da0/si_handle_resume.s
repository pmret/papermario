.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_resume
/* 0EB3FC 802C6A4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB400 802C6A50 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB404 802C6A54 8C82000C */  lw    $v0, 0xc($a0)
/* 0EB408 802C6A58 0C0B1EAF */  jal   get_variable
/* 0EB40C 802C6A5C 8C450000 */   lw    $a1, ($v0)
/* 0EB410 802C6A60 0C0B1123 */  jal   resume_all_script
/* 0EB414 802C6A64 0040202D */   daddu $a0, $v0, $zero
/* 0EB418 802C6A68 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB41C 802C6A6C 24020002 */  addiu $v0, $zero, 2
/* 0EB420 802C6A70 03E00008 */  jr    $ra
/* 0EB424 802C6A74 27BD0018 */   addiu $sp, $sp, 0x18

