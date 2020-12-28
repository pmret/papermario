.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218258_608D08
/* 608D08 80218258 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 608D0C 8021825C AFB00010 */  sw        $s0, 0x10($sp)
/* 608D10 80218260 0080802D */  daddu     $s0, $a0, $zero
/* 608D14 80218264 AFBF0018 */  sw        $ra, 0x18($sp)
/* 608D18 80218268 AFB10014 */  sw        $s1, 0x14($sp)
/* 608D1C 8021826C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 608D20 80218270 8E02000C */  lw        $v0, 0xc($s0)
/* 608D24 80218274 8C450004 */  lw        $a1, 4($v0)
/* 608D28 80218278 0C0B210B */  jal       get_float_variable
/* 608D2C 8021827C 8C510000 */   lw       $s1, ($v0)
/* 608D30 80218280 46000506 */  mov.s     $f20, $f0
/* 608D34 80218284 0200202D */  daddu     $a0, $s0, $zero
/* 608D38 80218288 0C0B210B */  jal       get_float_variable
/* 608D3C 8021828C 0220282D */   daddu    $a1, $s1, $zero
/* 608D40 80218290 3C0140C9 */  lui       $at, 0x40c9
/* 608D44 80218294 34210FD0 */  ori       $at, $at, 0xfd0
/* 608D48 80218298 44811000 */  mtc1      $at, $f2
/* 608D4C 8021829C 00000000 */  nop       
/* 608D50 802182A0 46020002 */  mul.s     $f0, $f0, $f2
/* 608D54 802182A4 00000000 */  nop       
/* 608D58 802182A8 3C0143B4 */  lui       $at, 0x43b4
/* 608D5C 802182AC 44816000 */  mtc1      $at, $f12
/* 608D60 802182B0 0C00A85B */  jal       sin_rad
/* 608D64 802182B4 460C0303 */   div.s    $f12, $f0, $f12
/* 608D68 802182B8 4600A502 */  mul.s     $f20, $f20, $f0
/* 608D6C 802182BC 00000000 */  nop       
/* 608D70 802182C0 0200202D */  daddu     $a0, $s0, $zero
/* 608D74 802182C4 4406A000 */  mfc1      $a2, $f20
/* 608D78 802182C8 0C0B2190 */  jal       set_float_variable
/* 608D7C 802182CC 0220282D */   daddu    $a1, $s1, $zero
/* 608D80 802182D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 608D84 802182D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 608D88 802182D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 608D8C 802182DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* 608D90 802182E0 24020002 */  addiu     $v0, $zero, 2
/* 608D94 802182E4 03E00008 */  jr        $ra
/* 608D98 802182E8 27BD0028 */   addiu    $sp, $sp, 0x28
