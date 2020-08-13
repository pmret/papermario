.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel DeletePartner
/* 1AF088 802807A8 3C04800E */  lui   $a0, 0x800e
/* 1AF08C 802807AC 8C84C14C */  lw    $a0, -0x3eb4($a0)
/* 1AF090 802807B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1AF094 802807B4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1AF098 802807B8 0C0902EF */  jal   delete_actor
/* 1AF09C 802807BC 00000000 */   nop   
/* 1AF0A0 802807C0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1AF0A4 802807C4 24020002 */  addiu $v0, $zero, 2
/* 1AF0A8 802807C8 03E00008 */  jr    $ra
/* 1AF0AC 802807CC 27BD0018 */   addiu $sp, $sp, 0x18

/* 1AF0B0 802807D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1AF0B4 802807D4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1AF0B8 802807D8 8C82000C */  lw    $v0, 0xc($a0)
/* 1AF0BC 802807DC 3C03800E */  lui   $v1, 0x800e
/* 1AF0C0 802807E0 8063C0F1 */  lb    $v1, -0x3f0f($v1)
/* 1AF0C4 802807E4 8C450000 */  lw    $a1, ($v0)
/* 1AF0C8 802807E8 04610002 */  bgez  $v1, .L802807F4
/* 1AF0CC 802807EC 0000302D */   daddu $a2, $zero, $zero
/* 1AF0D0 802807F0 00C0182D */  daddu $v1, $a2, $zero
.L802807F4:
/* 1AF0D4 802807F4 00C3102A */  slt   $v0, $a2, $v1
/* 1AF0D8 802807F8 54400001 */  bnezl $v0, .L80280800
/* 1AF0DC 802807FC 0060302D */   daddu $a2, $v1, $zero
.L80280800:
/* 1AF0E0 80280800 0C0B2026 */  jal   set_variable
/* 1AF0E4 80280804 00000000 */   nop   
/* 1AF0E8 80280808 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1AF0EC 8028080C 24020002 */  addiu $v0, $zero, 2
/* 1AF0F0 80280810 03E00008 */  jr    $ra
/* 1AF0F4 80280814 27BD0018 */   addiu $sp, $sp, 0x18

/* 1AF0F8 80280818 3C02800E */  lui   $v0, 0x800e
/* 1AF0FC 8028081C 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AF100 80280820 8C430000 */  lw    $v1, ($v0)
/* 1AF104 80280824 3C040020 */  lui   $a0, 0x20
/* 1AF108 80280828 00641825 */  or    $v1, $v1, $a0
/* 1AF10C 8028082C AC430000 */  sw    $v1, ($v0)
/* 1AF110 80280830 03E00008 */  jr    $ra
/* 1AF114 80280834 24020002 */   addiu $v0, $zero, 2

/* 1AF118 80280838 00000000 */  nop   
/* 1AF11C 8028083C 00000000 */  nop   
