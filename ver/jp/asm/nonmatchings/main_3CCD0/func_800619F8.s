.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800619F8
/* 3CDF8 800619F8 27BDFFF0 */  addiu     $sp, $sp, -0x10
/* 3CDFC 800619FC 00804821 */  addu      $t1, $a0, $zero
/* 3CE00 80061A00 3C02800A */  lui       $v0, %hi(D_8009A5E6)
/* 3CE04 80061A04 9042A5E6 */  lbu       $v0, %lo(D_8009A5E6)($v0)
/* 3CE08 80061A08 3C08800B */  lui       $t0, %hi(D_800B0EB0)
/* 3CE0C 80061A0C 25080EB0 */  addiu     $t0, $t0, %lo(D_800B0EB0)
/* 3CE10 80061A10 1840001D */  blez      $v0, .L80061A88
/* 3CE14 80061A14 00003821 */   addu     $a3, $zero, $zero
/* 3CE18 80061A18 24860003 */  addiu     $a2, $a0, 3
.L80061A1C:
/* 3CE1C 80061A1C 89020000 */  lwl       $v0, ($t0)
/* 3CE20 80061A20 99020003 */  lwr       $v0, 3($t0)
/* 3CE24 80061A24 89030004 */  lwl       $v1, 4($t0)
/* 3CE28 80061A28 99030007 */  lwr       $v1, 7($t0)
/* 3CE2C 80061A2C ABA20000 */  swl       $v0, ($sp)
/* 3CE30 80061A30 BBA20003 */  swr       $v0, 3($sp)
/* 3CE34 80061A34 ABA30004 */  swl       $v1, 4($sp)
/* 3CE38 80061A38 BBA30007 */  swr       $v1, 7($sp)
/* 3CE3C 80061A3C 93A20002 */  lbu       $v0, 2($sp)
/* 3CE40 80061A40 304200C0 */  andi      $v0, $v0, 0xc0
/* 3CE44 80061A44 00021102 */  srl       $v0, $v0, 4
/* 3CE48 80061A48 14400007 */  bnez      $v0, .L80061A68
/* 3CE4C 80061A4C A0C20001 */   sb       $v0, 1($a2)
/* 3CE50 80061A50 97A20004 */  lhu       $v0, 4($sp)
/* 3CE54 80061A54 A5220000 */  sh        $v0, ($t1)
/* 3CE58 80061A58 93A20006 */  lbu       $v0, 6($sp)
/* 3CE5C 80061A5C A0C2FFFF */  sb        $v0, -1($a2)
/* 3CE60 80061A60 93A20007 */  lbu       $v0, 7($sp)
/* 3CE64 80061A64 A0C20000 */  sb        $v0, ($a2)
.L80061A68:
/* 3CE68 80061A68 24E70001 */  addiu     $a3, $a3, 1
/* 3CE6C 80061A6C 25080008 */  addiu     $t0, $t0, 8
/* 3CE70 80061A70 3C02800A */  lui       $v0, %hi(D_8009A5E6)
/* 3CE74 80061A74 9042A5E6 */  lbu       $v0, %lo(D_8009A5E6)($v0)
/* 3CE78 80061A78 24C60006 */  addiu     $a2, $a2, 6
/* 3CE7C 80061A7C 00E2102A */  slt       $v0, $a3, $v0
/* 3CE80 80061A80 1440FFE6 */  bnez      $v0, .L80061A1C
/* 3CE84 80061A84 25290006 */   addiu    $t1, $t1, 6
.L80061A88:
/* 3CE88 80061A88 27BD0010 */  addiu     $sp, $sp, 0x10
/* 3CE8C 80061A8C 03E00008 */  jr        $ra
/* 3CE90 80061A90 00000000 */   nop
