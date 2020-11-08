.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD348
/* F1CF8 802CD348 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F1CFC 802CD34C AFB10014 */  sw        $s1, 0x14($sp)
/* F1D00 802CD350 0080882D */  daddu     $s1, $a0, $zero
/* F1D04 802CD354 AFBF0018 */  sw        $ra, 0x18($sp)
/* F1D08 802CD358 AFB00010 */  sw        $s0, 0x10($sp)
/* F1D0C 802CD35C 8E30000C */  lw        $s0, 0xc($s1)
/* F1D10 802CD360 8E050000 */  lw        $a1, ($s0)
/* F1D14 802CD364 0C0B1EAF */  jal       get_variable
/* F1D18 802CD368 26100004 */   addiu    $s0, $s0, 4
/* F1D1C 802CD36C 0220202D */  daddu     $a0, $s1, $zero
/* F1D20 802CD370 8E050000 */  lw        $a1, ($s0)
/* F1D24 802CD374 0C0B210B */  jal       get_float_variable
/* F1D28 802CD378 0040802D */   daddu    $s0, $v0, $zero
/* F1D2C 802CD37C 3C02802E */  lui       $v0, %hi(gMeshAnimationsPtr)
/* F1D30 802CD380 8C42AE30 */  lw        $v0, %lo(gMeshAnimationsPtr)($v0)
/* F1D34 802CD384 00108080 */  sll       $s0, $s0, 2
/* F1D38 802CD388 02028021 */  addu      $s0, $s0, $v0
/* F1D3C 802CD38C 8E020000 */  lw        $v0, ($s0)
/* F1D40 802CD390 8C440000 */  lw        $a0, ($v0)
/* F1D44 802CD394 4600008D */  trunc.w.s $f2, $f0
/* F1D48 802CD398 44101000 */  mfc1      $s0, $f2
/* F1D4C 802CD39C 0C047FF8 */  jal       func_8011FFE0
/* F1D50 802CD3A0 00000000 */   nop      
/* F1D54 802CD3A4 A0500004 */  sb        $s0, 4($v0)
/* F1D58 802CD3A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* F1D5C 802CD3AC 8FB10014 */  lw        $s1, 0x14($sp)
/* F1D60 802CD3B0 8FB00010 */  lw        $s0, 0x10($sp)
/* F1D64 802CD3B4 24020002 */  addiu     $v0, $zero, 2
/* F1D68 802CD3B8 03E00008 */  jr        $ra
/* F1D6C 802CD3BC 27BD0020 */   addiu    $sp, $sp, 0x20
