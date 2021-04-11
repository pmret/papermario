.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_06_UnkFunc34
/* D21FA0 80242110 3C058011 */  lui       $a1, %hi(gPlayerData)
/* D21FA4 80242114 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* D21FA8 80242118 AC800088 */  sw        $zero, 0x88($a0)
/* D21FAC 8024211C 80A30003 */  lb        $v1, 3($a1)
/* D21FB0 80242120 80A20002 */  lb        $v0, 2($a1)
/* D21FB4 80242124 1462000B */  bne       $v1, $v0, .L80242154
/* D21FB8 80242128 00A0302D */   daddu    $a2, $a1, $zero
/* D21FBC 8024212C 80A30006 */  lb        $v1, 6($a1)
/* D21FC0 80242130 80A20005 */  lb        $v0, 5($a1)
/* D21FC4 80242134 14620007 */  bne       $v1, $v0, .L80242154
/* D21FC8 80242138 00000000 */   nop
/* D21FCC 8024213C 80C2028E */  lb        $v0, 0x28e($a2)
/* D21FD0 80242140 84C30290 */  lh        $v1, 0x290($a2)
/* D21FD4 80242144 00021200 */  sll       $v0, $v0, 8
/* D21FD8 80242148 14620004 */  bne       $v1, $v0, .L8024215C
/* D21FDC 8024214C 24020001 */   addiu    $v0, $zero, 1
/* D21FE0 80242150 AC820088 */  sw        $v0, 0x88($a0)
.L80242154:
/* D21FE4 80242154 03E00008 */  jr        $ra
/* D21FE8 80242158 24020002 */   addiu    $v0, $zero, 2
.L8024215C:
/* D21FEC 8024215C 03E00008 */  jr        $ra
/* D21FF0 80242160 24020002 */   addiu    $v0, $zero, 2
