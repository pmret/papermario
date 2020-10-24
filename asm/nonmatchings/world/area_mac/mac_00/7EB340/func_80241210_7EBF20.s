.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241210_7EBF20
/* 7EBF20 80241210 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EBF24 80241214 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EBF28 80241218 0080882D */  daddu     $s1, $a0, $zero
/* 7EBF2C 8024121C AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EBF30 80241220 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EBF34 80241224 8E30000C */  lw        $s0, 0xc($s1)
/* 7EBF38 80241228 8E050000 */  lw        $a1, ($s0)
/* 7EBF3C 8024122C 0C0B1EAF */  jal       get_variable
/* 7EBF40 80241230 26100004 */   addiu    $s0, $s0, 4
/* 7EBF44 80241234 00021880 */  sll       $v1, $v0, 2
/* 7EBF48 80241238 00621821 */  addu      $v1, $v1, $v0
/* 7EBF4C 8024123C 00031880 */  sll       $v1, $v1, 2
/* 7EBF50 80241240 00621823 */  subu      $v1, $v1, $v0
/* 7EBF54 80241244 000310C0 */  sll       $v0, $v1, 3
/* 7EBF58 80241248 00621821 */  addu      $v1, $v1, $v0
/* 7EBF5C 8024124C 000318C0 */  sll       $v1, $v1, 3
/* 7EBF60 80241250 3C01800B */  lui       $at, 0x800b
/* 7EBF64 80241254 00230821 */  addu      $at, $at, $v1
/* 7EBF68 80241258 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* 7EBF6C 8024125C 3C014480 */  lui       $at, 0x4480
/* 7EBF70 80241260 44810000 */  mtc1      $at, $f0
/* 7EBF74 80241264 00000000 */  nop       
/* 7EBF78 80241268 46001082 */  mul.s     $f2, $f2, $f0
/* 7EBF7C 8024126C 00000000 */  nop       
/* 7EBF80 80241270 3C01CD5B */  lui       $at, 0xcd5b
/* 7EBF84 80241274 34215858 */  ori       $at, $at, 0x5858
/* 7EBF88 80241278 44810000 */  mtc1      $at, $f0
/* 7EBF8C 8024127C 00000000 */  nop       
/* 7EBF90 80241280 46001080 */  add.s     $f2, $f2, $f0
/* 7EBF94 80241284 8E050000 */  lw        $a1, ($s0)
/* 7EBF98 80241288 4600110D */  trunc.w.s $f4, $f2
/* 7EBF9C 8024128C 44062000 */  mfc1      $a2, $f4
/* 7EBFA0 80241290 0C0B2026 */  jal       set_variable
/* 7EBFA4 80241294 0220202D */   daddu    $a0, $s1, $zero
/* 7EBFA8 80241298 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EBFAC 8024129C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EBFB0 802412A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EBFB4 802412A4 24020002 */  addiu     $v0, $zero, 2
/* 7EBFB8 802412A8 03E00008 */  jr        $ra
/* 7EBFBC 802412AC 27BD0020 */   addiu    $sp, $sp, 0x20
