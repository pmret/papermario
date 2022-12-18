.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241790_BD0380
/* BD0380 80241790 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD0384 80241794 AFB00010 */  sw        $s0, 0x10($sp)
/* BD0388 80241798 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD038C 8024179C 0C090150 */  jal       obk_07_GetPhonographData
/* BD0390 802417A0 0080802D */   daddu    $s0, $a0, $zero
/* BD0394 802417A4 0040282D */  daddu     $a1, $v0, $zero
/* BD0398 802417A8 8CA20004 */  lw        $v0, 4($a1)
/* BD039C 802417AC 2442FFCE */  addiu     $v0, $v0, -0x32
/* BD03A0 802417B0 04410002 */  bgez      $v0, .L802417BC
/* BD03A4 802417B4 0040202D */   daddu    $a0, $v0, $zero
/* BD03A8 802417B8 00042023 */  negu      $a0, $a0
.L802417BC:
/* BD03AC 802417BC 2882000A */  slti      $v0, $a0, 0xa
/* BD03B0 802417C0 14400016 */  bnez      $v0, .L8024181C
/* BD03B4 802417C4 00041823 */   negu     $v1, $a0
/* BD03B8 802417C8 00031080 */  sll       $v0, $v1, 2
.L802417CC:
/* BD03BC 802417CC 00431021 */  addu      $v0, $v0, $v1
/* BD03C0 802417D0 00022040 */  sll       $a0, $v0, 1
/* BD03C4 802417D4 8CA201D4 */  lw        $v0, 0x1d4($a1)
/* BD03C8 802417D8 8CA30004 */  lw        $v1, 4($a1)
/* BD03CC 802417DC 00441021 */  addu      $v0, $v0, $a0
/* BD03D0 802417E0 10600003 */  beqz      $v1, .L802417F0
/* BD03D4 802417E4 ACA201D4 */   sw       $v0, 0x1d4($a1)
/* BD03D8 802417E8 24020001 */  addiu     $v0, $zero, 1
/* BD03DC 802417EC A0A201DC */  sb        $v0, 0x1dc($a1)
.L802417F0:
/* BD03E0 802417F0 80A301DC */  lb        $v1, 0x1dc($a1)
/* BD03E4 802417F4 24020001 */  addiu     $v0, $zero, 1
/* BD03E8 802417F8 1462000E */  bne       $v1, $v0, .L80241834
/* BD03EC 802417FC 00000000 */   nop
/* BD03F0 80241800 8CA20004 */  lw        $v0, 4($a1)
/* BD03F4 80241804 5C40000B */  bgtzl     $v0, .L80241834
/* BD03F8 80241808 ACA001D8 */   sw       $zero, 0x1d8($a1)
/* BD03FC 8024180C 8CA201D8 */  lw        $v0, 0x1d8($a1)
/* BD0400 80241810 24420001 */  addiu     $v0, $v0, 1
/* BD0404 80241814 0809060D */  j         .L80241834
/* BD0408 80241818 ACA201D8 */   sw       $v0, 0x1d8($a1)
.L8024181C:
/* BD040C 8024181C 2403000A */  addiu     $v1, $zero, 0xa
/* BD0410 80241820 00641823 */  subu      $v1, $v1, $a0
/* BD0414 80241824 00031040 */  sll       $v0, $v1, 1
/* BD0418 80241828 00431021 */  addu      $v0, $v0, $v1
/* BD041C 8024182C 080905F3 */  j         .L802417CC
/* BD0420 80241830 000210C0 */   sll      $v0, $v0, 3
.L80241834:
/* BD0424 80241834 8CA201D4 */  lw        $v0, 0x1d4($a1)
/* BD0428 80241838 28422711 */  slti      $v0, $v0, 0x2711
/* BD042C 8024183C 14400002 */  bnez      $v0, .L80241848
/* BD0430 80241840 24022710 */   addiu    $v0, $zero, 0x2710
/* BD0434 80241844 ACA201D4 */  sw        $v0, 0x1d4($a1)
.L80241848:
/* BD0438 80241848 8CA201D4 */  lw        $v0, 0x1d4($a1)
/* BD043C 8024184C 04420001 */  bltzl     $v0, .L80241854
/* BD0440 80241850 ACA001D4 */   sw       $zero, 0x1d4($a1)
.L80241854:
/* BD0444 80241854 AE000084 */  sw        $zero, 0x84($s0)
/* BD0448 80241858 8CA201D8 */  lw        $v0, 0x1d8($a1)
/* BD044C 8024185C 2842002E */  slti      $v0, $v0, 0x2e
/* BD0450 80241860 10400007 */  beqz      $v0, .L80241880
/* BD0454 80241864 24020001 */   addiu    $v0, $zero, 1
/* BD0458 80241868 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BD045C 8024186C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BD0460 80241870 8C420010 */  lw        $v0, 0x10($v0)
/* BD0464 80241874 30424000 */  andi      $v0, $v0, 0x4000
/* BD0468 80241878 10400002 */  beqz      $v0, .L80241884
/* BD046C 8024187C 24020001 */   addiu    $v0, $zero, 1
.L80241880:
/* BD0470 80241880 AE020084 */  sw        $v0, 0x84($s0)
.L80241884:
/* BD0474 80241884 24020002 */  addiu     $v0, $zero, 2
/* BD0478 80241888 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD047C 8024188C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0480 80241890 03E00008 */  jr        $ra
/* BD0484 80241894 27BD0018 */   addiu    $sp, $sp, 0x18
