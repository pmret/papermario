.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006D49C
/* 4889C 8006D49C 27BDFFF0 */  addiu     $sp, $sp, -0x10
/* 488A0 8006D4A0 3C05800A */  lui       $a1, %hi(D_8009A5E6)
/* 488A4 8006D4A4 90A5A5E6 */  lbu       $a1, %lo(D_8009A5E6)($a1)
/* 488A8 8006D4A8 3C07800E */  lui       $a3, %hi(D_800D9FE0)
/* 488AC 8006D4AC 24E79FE0 */  addiu     $a3, $a3, %lo(D_800D9FE0)
/* 488B0 8006D4B0 00003021 */  addu      $a2, $zero, $zero
/* 488B4 8006D4B4 24020001 */  addiu     $v0, $zero, 1
/* 488B8 8006D4B8 240300FF */  addiu     $v1, $zero, 0xff
/* 488BC 8006D4BC 3C01800E */  lui       $at, %hi(D_800DA01C)
/* 488C0 8006D4C0 AC22A01C */  sw        $v0, %lo(D_800DA01C)($at)
/* 488C4 8006D4C4 24020001 */  addiu     $v0, $zero, 1
/* 488C8 8006D4C8 A3A20001 */  sb        $v0, 1($sp)
/* 488CC 8006D4CC 24020003 */  addiu     $v0, $zero, 3
/* 488D0 8006D4D0 3C01800A */  lui       $at, %hi(D_8009A5FC)
/* 488D4 8006D4D4 A024A5FC */  sb        $a0, %lo(D_8009A5FC)($at)
/* 488D8 8006D4D8 A3A30000 */  sb        $v1, ($sp)
/* 488DC 8006D4DC A3A20002 */  sb        $v0, 2($sp)
/* 488E0 8006D4E0 A3A40003 */  sb        $a0, 3($sp)
/* 488E4 8006D4E4 A3A30004 */  sb        $v1, 4($sp)
/* 488E8 8006D4E8 A3A30005 */  sb        $v1, 5($sp)
/* 488EC 8006D4EC A3A30006 */  sb        $v1, 6($sp)
/* 488F0 8006D4F0 18A0000F */  blez      $a1, .L8006D530
/* 488F4 8006D4F4 A3A30007 */   sb       $v1, 7($sp)
.L8006D4F8:
/* 488F8 8006D4F8 8BA20000 */  lwl       $v0, ($sp)
/* 488FC 8006D4FC 9BA20003 */  lwr       $v0, 3($sp)
/* 48900 8006D500 8BA30004 */  lwl       $v1, 4($sp)
/* 48904 8006D504 9BA30007 */  lwr       $v1, 7($sp)
/* 48908 8006D508 A8E20000 */  swl       $v0, ($a3)
/* 4890C 8006D50C B8E20003 */  swr       $v0, 3($a3)
/* 48910 8006D510 A8E30004 */  swl       $v1, 4($a3)
/* 48914 8006D514 B8E30007 */  swr       $v1, 7($a3)
/* 48918 8006D518 3C02800A */  lui       $v0, %hi(D_8009A5E6)
/* 4891C 8006D51C 9042A5E6 */  lbu       $v0, %lo(D_8009A5E6)($v0)
/* 48920 8006D520 24C60001 */  addiu     $a2, $a2, 1
/* 48924 8006D524 00C2102A */  slt       $v0, $a2, $v0
/* 48928 8006D528 1440FFF3 */  bnez      $v0, .L8006D4F8
/* 4892C 8006D52C 24E70008 */   addiu    $a3, $a3, 8
.L8006D530:
/* 48930 8006D530 240200FE */  addiu     $v0, $zero, 0xfe
/* 48934 8006D534 A0E20000 */  sb        $v0, ($a3)
/* 48938 8006D538 03E00008 */  jr        $ra
/* 4893C 8006D53C 27BD0010 */   addiu    $sp, $sp, 0x10
