.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240208_8FF878
/* 8FF878 80240208 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8FF87C 8024020C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8FF880 80240210 8C430010 */  lw        $v1, 0x10($v0)
/* 8FF884 80240214 30621000 */  andi      $v0, $v1, 0x1000
/* 8FF888 80240218 0002102B */  sltu      $v0, $zero, $v0
/* 8FF88C 8024021C 30638000 */  andi      $v1, $v1, 0x8000
/* 8FF890 80240220 10600004 */  beqz      $v1, .L80240234
/* 8FF894 80240224 00022840 */   sll      $a1, $v0, 1
/* 8FF898 80240228 24050002 */  addiu     $a1, $zero, 2
/* 8FF89C 8024022C 2402FFFF */  addiu     $v0, $zero, -1
/* 8FF8A0 80240230 AC820084 */  sw        $v0, 0x84($a0)
.L80240234:
/* 8FF8A4 80240234 03E00008 */  jr        $ra
/* 8FF8A8 80240238 00A0102D */   daddu    $v0, $a1, $zero
/* 8FF8AC 8024023C 00000000 */  nop
