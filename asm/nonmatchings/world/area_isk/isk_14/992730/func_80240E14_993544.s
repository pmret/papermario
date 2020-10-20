.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E14_993544
/* 993544 80240E14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 993548 80240E18 AFB00010 */  sw        $s0, 0x10($sp)
/* 99354C 80240E1C 0080802D */  daddu     $s0, $a0, $zero
/* 993550 80240E20 AFBF001C */  sw        $ra, 0x1c($sp)
/* 993554 80240E24 AFB20018 */  sw        $s2, 0x18($sp)
/* 993558 80240E28 AFB10014 */  sw        $s1, 0x14($sp)
/* 99355C 80240E2C 8E020148 */  lw        $v0, 0x148($s0)
/* 993560 80240E30 00A0882D */  daddu     $s1, $a1, $zero
/* 993564 80240E34 84440008 */  lh        $a0, 8($v0)
/* 993568 80240E38 0C00EABB */  jal       get_npc_unsafe
/* 99356C 80240E3C 00C0902D */   daddu    $s2, $a2, $zero
/* 993570 80240E40 0200202D */  daddu     $a0, $s0, $zero
/* 993574 80240E44 0040802D */  daddu     $s0, $v0, $zero
/* 993578 80240E48 0220282D */  daddu     $a1, $s1, $zero
/* 99357C 80240E4C 0C012568 */  jal       func_800495A0
/* 993580 80240E50 0240302D */   daddu    $a2, $s2, $zero
/* 993584 80240E54 0C00A67F */  jal       rand_int
/* 993588 80240E58 24040005 */   addiu    $a0, $zero, 5
/* 99358C 80240E5C 3C014020 */  lui       $at, 0x4020
/* 993590 80240E60 44811800 */  mtc1      $at, $f3
/* 993594 80240E64 44801000 */  mtc1      $zero, $f2
/* 993598 80240E68 44820000 */  mtc1      $v0, $f0
/* 99359C 80240E6C 00000000 */  nop       
/* 9935A0 80240E70 46800021 */  cvt.d.w   $f0, $f0
/* 9935A4 80240E74 46220000 */  add.d     $f0, $f0, $f2
/* 9935A8 80240E78 3C013FC0 */  lui       $at, 0x3fc0
/* 9935AC 80240E7C 44811000 */  mtc1      $at, $f2
/* 9935B0 80240E80 00000000 */  nop       
/* 9935B4 80240E84 E6020014 */  swc1      $f2, 0x14($s0)
/* 9935B8 80240E88 46200020 */  cvt.s.d   $f0, $f0
/* 9935BC 80240E8C E600001C */  swc1      $f0, 0x1c($s0)
/* 9935C0 80240E90 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9935C4 80240E94 8FB20018 */  lw        $s2, 0x18($sp)
/* 9935C8 80240E98 8FB10014 */  lw        $s1, 0x14($sp)
/* 9935CC 80240E9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9935D0 80240EA0 03E00008 */  jr        $ra
/* 9935D4 80240EA4 27BD0020 */   addiu    $sp, $sp, 0x20
