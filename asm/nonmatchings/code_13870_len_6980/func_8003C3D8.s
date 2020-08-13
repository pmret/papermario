.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8003C3D8
/* 0177D8 8003C3D8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0177DC 8003C3DC AFB00010 */  sw    $s0, 0x10($sp)
/* 0177E0 8003C3E0 0080802D */  daddu $s0, $a0, $zero
/* 0177E4 8003C3E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0177E8 8003C3E8 00A0882D */  daddu $s1, $a1, $zero
/* 0177EC 8003C3EC AFB20018 */  sw    $s2, 0x18($sp)
/* 0177F0 8003C3F0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0177F4 8003C3F4 0C00F14F */  jal   func_8003C53C
/* 0177F8 8003C3F8 00C0902D */   daddu $s2, $a2, $zero
/* 0177FC 8003C3FC 02118021 */  addu  $s0, $s0, $s1
/* 017800 8003C400 24020001 */  addiu $v0, $zero, 1
/* 017804 8003C404 A212032C */  sb    $s2, 0x32c($s0)
/* 017808 8003C408 A202032E */  sb    $v0, 0x32e($s0)
/* 01780C 8003C40C A2000330 */  sb    $zero, 0x330($s0)
/* 017810 8003C410 8FBF001C */  lw    $ra, 0x1c($sp)
/* 017814 8003C414 8FB20018 */  lw    $s2, 0x18($sp)
/* 017818 8003C418 8FB10014 */  lw    $s1, 0x14($sp)
/* 01781C 8003C41C 8FB00010 */  lw    $s0, 0x10($sp)
/* 017820 8003C420 03E00008 */  jr    $ra
/* 017824 8003C424 27BD0020 */   addiu $sp, $sp, 0x20

