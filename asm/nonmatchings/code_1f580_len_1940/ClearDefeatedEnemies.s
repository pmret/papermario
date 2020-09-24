.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ClearDefeatedEnemies
/* 20A40 80045640 3C07800B */  lui       $a3, 0x800b
/* 20A44 80045644 24E70F10 */  addiu     $a3, $a3, 0xf10
/* 20A48 80045648 0000302D */  daddu     $a2, $zero, $zero
/* 20A4C 8004564C 00C0282D */  daddu     $a1, $a2, $zero
.L80045650:
/* 20A50 80045650 0000202D */  daddu     $a0, $zero, $zero
/* 20A54 80045654 00A0182D */  daddu     $v1, $a1, $zero
.L80045658:
/* 20A58 80045658 00E31021 */  addu      $v0, $a3, $v1
/* 20A5C 8004565C AC4000B0 */  sw        $zero, 0xb0($v0)
/* 20A60 80045660 24840001 */  addiu     $a0, $a0, 1
/* 20A64 80045664 2882000C */  slti      $v0, $a0, 0xc
/* 20A68 80045668 1440FFFB */  bnez      $v0, .L80045658
/* 20A6C 8004566C 24630004 */   addiu    $v1, $v1, 4
/* 20A70 80045670 24C60001 */  addiu     $a2, $a2, 1
/* 20A74 80045674 28C2003C */  slti      $v0, $a2, 0x3c
/* 20A78 80045678 1440FFF5 */  bnez      $v0, .L80045650
/* 20A7C 8004567C 24A50030 */   addiu    $a1, $a1, 0x30
/* 20A80 80045680 03E00008 */  jr        $ra
/* 20A84 80045684 24020002 */   addiu    $v0, $zero, 2
