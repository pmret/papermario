.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FB1C
/* 2AF1C 8004FB1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2AF20 8004FB20 0080102D */  daddu     $v0, $a0, $zero
/* 2AF24 8004FB24 AFB00010 */  sw        $s0, 0x10($sp)
/* 2AF28 8004FB28 00A0802D */  daddu     $s0, $a1, $zero
/* 2AF2C 8004FB2C AFBF0014 */  sw        $ra, 0x14($sp)
/* 2AF30 8004FB30 904300D5 */  lbu       $v1, 0xd5($v0)
/* 2AF34 8004FB34 26070010 */  addiu     $a3, $s0, 0x10
/* 2AF38 8004FB38 A6030044 */  sh        $v1, 0x44($s0)
/* 2AF3C 8004FB3C 8C440000 */  lw        $a0, ($v0)
/* 2AF40 8004FB40 904500D4 */  lbu       $a1, 0xd4($v0)
/* 2AF44 8004FB44 0C014E26 */  jal       func_80053898
/* 2AF48 8004FB48 3066FFFF */   andi     $a2, $v1, 0xffff
/* 2AF4C 8004FB4C AE02000C */  sw        $v0, 0xc($s0)
/* 2AF50 8004FB50 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2AF54 8004FB54 8FB00010 */  lw        $s0, 0x10($sp)
/* 2AF58 8004FB58 03E00008 */  jr        $ra
/* 2AF5C 8004FB5C 27BD0018 */   addiu    $sp, $sp, 0x18
