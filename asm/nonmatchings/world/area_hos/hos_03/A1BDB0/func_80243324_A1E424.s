.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243324_A1E424
/* A1E424 80243324 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1E428 80243328 AFB10014 */  sw        $s1, 0x14($sp)
/* A1E42C 8024332C 0080882D */  daddu     $s1, $a0, $zero
/* A1E430 80243330 AFB00010 */  sw        $s0, 0x10($sp)
/* A1E434 80243334 00A0802D */  daddu     $s0, $a1, $zero
/* A1E438 80243338 AFBF0018 */  sw        $ra, 0x18($sp)
/* A1E43C 8024333C 0C00EABB */  jal       get_npc_unsafe
/* A1E440 80243340 2404FFFC */   addiu    $a0, $zero, -4
/* A1E444 80243344 12000003 */  beqz      $s0, .L80243354
/* A1E448 80243348 0040182D */   daddu    $v1, $v0, $zero
/* A1E44C 8024334C 2402003C */  addiu     $v0, $zero, 0x3c
/* A1E450 80243350 AE220070 */  sw        $v0, 0x70($s1)
.L80243354:
/* A1E454 80243354 C462000C */  lwc1      $f2, 0xc($v1)
/* A1E458 80243358 3C0141F0 */  lui       $at, 0x41f0
/* A1E45C 8024335C 44810000 */  mtc1      $at, $f0
/* A1E460 80243360 00000000 */  nop       
/* A1E464 80243364 46001000 */  add.s     $f0, $f2, $f0
/* A1E468 80243368 3C0143B4 */  lui       $at, 0x43b4
/* A1E46C 8024336C 44811000 */  mtc1      $at, $f2
/* A1E470 80243370 00000000 */  nop       
/* A1E474 80243374 4600103E */  c.le.s    $f2, $f0
/* A1E478 80243378 00000000 */  nop       
/* A1E47C 8024337C 45000003 */  bc1f      .L8024338C
/* A1E480 80243380 E460000C */   swc1     $f0, 0xc($v1)
/* A1E484 80243384 46020001 */  sub.s     $f0, $f0, $f2
/* A1E488 80243388 E460000C */  swc1      $f0, 0xc($v1)
.L8024338C:
/* A1E48C 8024338C 8E230070 */  lw        $v1, 0x70($s1)
/* A1E490 80243390 2463FFFF */  addiu     $v1, $v1, -1
/* A1E494 80243394 000317C3 */  sra       $v0, $v1, 0x1f
/* A1E498 80243398 AE230070 */  sw        $v1, 0x70($s1)
/* A1E49C 8024339C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1E4A0 802433A0 8FB10014 */  lw        $s1, 0x14($sp)
/* A1E4A4 802433A4 8FB00010 */  lw        $s0, 0x10($sp)
/* A1E4A8 802433A8 30420002 */  andi      $v0, $v0, 2
/* A1E4AC 802433AC 03E00008 */  jr        $ra
/* A1E4B0 802433B0 27BD0020 */   addiu    $sp, $sp, 0x20
