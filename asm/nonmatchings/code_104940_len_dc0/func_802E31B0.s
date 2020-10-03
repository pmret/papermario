.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E31B0
/* 104A30 802E31B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 104A34 802E31B4 3C013F80 */  lui       $at, 0x3f80
/* 104A38 802E31B8 44810000 */  mtc1      $at, $f0
/* 104A3C 802E31BC 2402003C */  addiu     $v0, $zero, 0x3c
/* 104A40 802E31C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 104A44 802E31C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 104A48 802E31C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 104A4C 802E31CC 8C850048 */  lw        $a1, 0x48($a0)
/* 104A50 802E31D0 8C86004C */  lw        $a2, 0x4c($a0)
/* 104A54 802E31D4 8C870050 */  lw        $a3, 0x50($a0)
/* 104A58 802E31D8 0C01C88C */  jal       func_80072230
/* 104A5C 802E31DC 0000202D */   daddu    $a0, $zero, $zero
/* 104A60 802E31E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 104A64 802E31E4 03E00008 */  jr        $ra
/* 104A68 802E31E8 27BD0020 */   addiu    $sp, $sp, 0x20
