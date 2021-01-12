.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013AF20
/* D1620 8013AF20 00041140 */  sll       $v0, $a0, 5
/* D1624 8013AF24 00441023 */  subu      $v0, $v0, $a0
/* D1628 8013AF28 3C038015 */  lui       $v1, %hi(D_80156954)
/* D162C 8013AF2C 8C636954 */  lw        $v1, %lo(D_80156954)($v1)
/* D1630 8013AF30 00021080 */  sll       $v0, $v0, 2
/* D1634 8013AF34 00432021 */  addu      $a0, $v0, $v1
/* D1638 8013AF38 8C830014 */  lw        $v1, 0x14($a0)
/* D163C 8013AF3C 30620001 */  andi      $v0, $v1, 1
/* D1640 8013AF40 10400009 */  beqz      $v0, .L8013AF68
/* D1644 8013AF44 00000000 */   nop
/* D1648 8013AF48 10C00004 */  beqz      $a2, .L8013AF5C
/* D164C 8013AF4C 30A2FFFF */   andi     $v0, $a1, 0xffff
/* D1650 8013AF50 00621025 */  or        $v0, $v1, $v0
/* D1654 8013AF54 03E00008 */  jr        $ra
/* D1658 8013AF58 AC820014 */   sw       $v0, 0x14($a0)
.L8013AF5C:
/* D165C 8013AF5C 00021027 */  nor       $v0, $zero, $v0
/* D1660 8013AF60 00621024 */  and       $v0, $v1, $v0
/* D1664 8013AF64 AC820014 */  sw        $v0, 0x14($a0)
.L8013AF68:
/* D1668 8013AF68 03E00008 */  jr        $ra
/* D166C 8013AF6C 00000000 */   nop
