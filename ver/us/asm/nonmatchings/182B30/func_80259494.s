.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80259494
/* 187D74 80259494 8C8800C0 */  lw        $t0, 0xc0($a0)
/* 187D78 80259498 810206CD */  lb        $v0, 0x6cd($t0)
/* 187D7C 8025949C 18400019 */  blez      $v0, .L80259504
/* 187D80 802594A0 0000482D */   daddu    $t1, $zero, $zero
/* 187D84 802594A4 24070360 */  addiu     $a3, $zero, 0x360
/* 187D88 802594A8 0100302D */  daddu     $a2, $t0, $zero
.L802594AC:
/* 187D8C 802594AC 8CC206D4 */  lw        $v0, 0x6d4($a2)
/* 187D90 802594B0 5040000F */  beql      $v0, $zero, .L802594F0
/* 187D94 802594B4 24E70020 */   addiu    $a3, $a3, 0x20
/* 187D98 802594B8 0040282D */  daddu     $a1, $v0, $zero
/* 187D9C 802594BC 01072021 */  addu      $a0, $t0, $a3
/* 187DA0 802594C0 0000182D */  daddu     $v1, $zero, $zero
.L802594C4:
/* 187DA4 802594C4 94A20000 */  lhu       $v0, ($a1)
/* 187DA8 802594C8 24A50002 */  addiu     $a1, $a1, 2
/* 187DAC 802594CC 24630001 */  addiu     $v1, $v1, 1
/* 187DB0 802594D0 3442FFFE */  ori       $v0, $v0, 0xfffe
/* 187DB4 802594D4 A4820000 */  sh        $v0, ($a0)
/* 187DB8 802594D8 28620010 */  slti      $v0, $v1, 0x10
/* 187DBC 802594DC 1440FFF9 */  bnez      $v0, .L802594C4
/* 187DC0 802594E0 24840002 */   addiu    $a0, $a0, 2
/* 187DC4 802594E4 01071021 */  addu      $v0, $t0, $a3
/* 187DC8 802594E8 ACC2076C */  sw        $v0, 0x76c($a2)
/* 187DCC 802594EC 24E70020 */  addiu     $a3, $a3, 0x20
.L802594F0:
/* 187DD0 802594F0 810206CD */  lb        $v0, 0x6cd($t0)
/* 187DD4 802594F4 25290001 */  addiu     $t1, $t1, 1
/* 187DD8 802594F8 0122102A */  slt       $v0, $t1, $v0
/* 187DDC 802594FC 1440FFEB */  bnez      $v0, .L802594AC
/* 187DE0 80259500 24C60004 */   addiu    $a2, $a2, 4
.L80259504:
/* 187DE4 80259504 03E00008 */  jr        $ra
/* 187DE8 80259508 00000000 */   nop
