.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EEC
/* 8326EC 80240EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8326F0 80240EF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8326F4 80240EF4 8C82000C */  lw        $v0, 0xc($a0)
/* 8326F8 80240EF8 0C0B1EAF */  jal       get_variable
/* 8326FC 80240EFC 8C450000 */   lw       $a1, ($v0)
/* 832700 80240F00 3C038025 */  lui       $v1, %hi(ForceCloseMessageBox)
/* 832704 80240F04 8C6313F0 */  lw        $v1, %lo(ForceCloseMessageBox)($v1)
/* 832708 80240F08 8C63000C */  lw        $v1, 0xc($v1)
/* 83270C 80240F0C AC620034 */  sw        $v0, 0x34($v1)
/* 832710 80240F10 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832714 80240F14 24020002 */  addiu     $v0, $zero, 2
/* 832718 80240F18 03E00008 */  jr        $ra
/* 83271C 80240F1C 27BD0018 */   addiu    $sp, $sp, 0x18
