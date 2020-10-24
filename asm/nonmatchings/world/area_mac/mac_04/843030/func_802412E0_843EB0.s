.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412E0_843EB0
/* 843EB0 802412E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 843EB4 802412E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 843EB8 802412E8 0080882D */  daddu     $s1, $a0, $zero
/* 843EBC 802412EC AFB00010 */  sw        $s0, 0x10($sp)
/* 843EC0 802412F0 00A0802D */  daddu     $s0, $a1, $zero
/* 843EC4 802412F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 843EC8 802412F8 0C00EABB */  jal       get_npc_unsafe
/* 843ECC 802412FC 2404FFFC */   addiu    $a0, $zero, -4
/* 843ED0 80241300 12000003 */  beqz      $s0, .L80241310
/* 843ED4 80241304 0040182D */   daddu    $v1, $v0, $zero
/* 843ED8 80241308 2402003C */  addiu     $v0, $zero, 0x3c
/* 843EDC 8024130C AE220070 */  sw        $v0, 0x70($s1)
.L80241310:
/* 843EE0 80241310 C462000C */  lwc1      $f2, 0xc($v1)
/* 843EE4 80241314 3C0141F0 */  lui       $at, 0x41f0
/* 843EE8 80241318 44810000 */  mtc1      $at, $f0
/* 843EEC 8024131C 00000000 */  nop       
/* 843EF0 80241320 46001000 */  add.s     $f0, $f2, $f0
/* 843EF4 80241324 3C0143B4 */  lui       $at, 0x43b4
/* 843EF8 80241328 44811000 */  mtc1      $at, $f2
/* 843EFC 8024132C 00000000 */  nop       
/* 843F00 80241330 4600103E */  c.le.s    $f2, $f0
/* 843F04 80241334 00000000 */  nop       
/* 843F08 80241338 45000003 */  bc1f      .L80241348
/* 843F0C 8024133C E460000C */   swc1     $f0, 0xc($v1)
/* 843F10 80241340 46020001 */  sub.s     $f0, $f0, $f2
/* 843F14 80241344 E460000C */  swc1      $f0, 0xc($v1)
.L80241348:
/* 843F18 80241348 8E230070 */  lw        $v1, 0x70($s1)
/* 843F1C 8024134C 2463FFFF */  addiu     $v1, $v1, -1
/* 843F20 80241350 000317C3 */  sra       $v0, $v1, 0x1f
/* 843F24 80241354 AE230070 */  sw        $v1, 0x70($s1)
/* 843F28 80241358 8FBF0018 */  lw        $ra, 0x18($sp)
/* 843F2C 8024135C 8FB10014 */  lw        $s1, 0x14($sp)
/* 843F30 80241360 8FB00010 */  lw        $s0, 0x10($sp)
/* 843F34 80241364 30420002 */  andi      $v0, $v0, 2
/* 843F38 80241368 03E00008 */  jr        $ra
/* 843F3C 8024136C 27BD0020 */   addiu    $sp, $sp, 0x20
