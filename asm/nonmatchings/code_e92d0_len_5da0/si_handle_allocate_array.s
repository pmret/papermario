.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_allocate_array
/* 0EABC4 802C6214 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EABC8 802C6218 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EABCC 802C621C 0080882D */  daddu $s1, $a0, $zero
/* 0EABD0 802C6220 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EABD4 802C6224 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EABD8 802C6228 8E30000C */  lw    $s0, 0xc($s1)
/* 0EABDC 802C622C 8E050000 */  lw    $a1, ($s0)
/* 0EABE0 802C6230 0C0B1EAF */  jal   get_variable
/* 0EABE4 802C6234 26100004 */   addiu $s0, $s0, 4
/* 0EABE8 802C6238 8E100000 */  lw    $s0, ($s0)
/* 0EABEC 802C623C 0C00AB39 */  jal   heap_malloc
/* 0EABF0 802C6240 00022080 */   sll   $a0, $v0, 2
/* 0EABF4 802C6244 0220202D */  daddu $a0, $s1, $zero
/* 0EABF8 802C6248 0040302D */  daddu $a2, $v0, $zero
/* 0EABFC 802C624C AC82013C */  sw    $v0, 0x13c($a0)
/* 0EAC00 802C6250 0C0B2026 */  jal   set_variable
/* 0EAC04 802C6254 0200282D */   daddu $a1, $s0, $zero
/* 0EAC08 802C6258 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EAC0C 802C625C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAC10 802C6260 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAC14 802C6264 24020002 */  addiu $v0, $zero, 2
/* 0EAC18 802C6268 03E00008 */  jr    $ra
/* 0EAC1C 802C626C 27BD0020 */   addiu $sp, $sp, 0x20

