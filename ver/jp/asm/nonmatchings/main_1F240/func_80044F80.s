.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044F80
/* 20380 80044F80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20384 80044F84 AFB20018 */  sw        $s2, 0x18($sp)
/* 20388 80044F88 0080902D */  daddu     $s2, $a0, $zero
/* 2038C 80044F8C AFBF001C */  sw        $ra, 0x1c($sp)
/* 20390 80044F90 AFB10014 */  sw        $s1, 0x14($sp)
/* 20394 80044F94 AFB00010 */  sw        $s0, 0x10($sp)
/* 20398 80044F98 8E51000C */  lw        $s1, 0xc($s2)
/* 2039C 80044F9C 8E500148 */  lw        $s0, 0x148($s2)
/* 203A0 80044FA0 8E250000 */  lw        $a1, ($s1)
/* 203A4 80044FA4 0C0B1EAF */  jal       func_802C7ABC
/* 203A8 80044FA8 26310004 */   addiu    $s1, $s1, 4
/* 203AC 80044FAC 00021080 */  sll       $v0, $v0, 2
/* 203B0 80044FB0 02028021 */  addu      $s0, $s0, $v0
/* 203B4 80044FB4 8E250000 */  lw        $a1, ($s1)
/* 203B8 80044FB8 8E06006C */  lw        $a2, 0x6c($s0)
/* 203BC 80044FBC 0C0B2026 */  jal       func_802C8098
/* 203C0 80044FC0 0240202D */   daddu    $a0, $s2, $zero
/* 203C4 80044FC4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 203C8 80044FC8 8FB20018 */  lw        $s2, 0x18($sp)
/* 203CC 80044FCC 8FB10014 */  lw        $s1, 0x14($sp)
/* 203D0 80044FD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 203D4 80044FD4 24020002 */  addiu     $v0, $zero, 2
/* 203D8 80044FD8 03E00008 */  jr        $ra
/* 203DC 80044FDC 27BD0020 */   addiu    $sp, $sp, 0x20
