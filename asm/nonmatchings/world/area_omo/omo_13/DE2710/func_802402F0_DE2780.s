.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_DE2780
/* DE2780 802402F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DE2784 802402F4 AFB20028 */  sw        $s2, 0x28($sp)
/* DE2788 802402F8 0080902D */  daddu     $s2, $a0, $zero
/* DE278C 802402FC AFBF002C */  sw        $ra, 0x2c($sp)
/* DE2790 80240300 AFB10024 */  sw        $s1, 0x24($sp)
/* DE2794 80240304 AFB00020 */  sw        $s0, 0x20($sp)
/* DE2798 80240308 8E510148 */  lw        $s1, 0x148($s2)
/* DE279C 8024030C 0C00EABB */  jal       get_npc_unsafe
/* DE27A0 80240310 86240008 */   lh       $a0, 8($s1)
/* DE27A4 80240314 0040802D */  daddu     $s0, $v0, $zero
/* DE27A8 80240318 0200202D */  daddu     $a0, $s0, $zero
/* DE27AC 8024031C C600000C */  lwc1      $f0, 0xc($s0)
/* DE27B0 80240320 27A60018 */  addiu     $a2, $sp, 0x18
/* DE27B4 80240324 E7A00018 */  swc1      $f0, 0x18($sp)
/* DE27B8 80240328 AFA00010 */  sw        $zero, 0x10($sp)
/* DE27BC 8024032C AFA00014 */  sw        $zero, 0x14($sp)
/* DE27C0 80240330 8E050018 */  lw        $a1, 0x18($s0)
/* DE27C4 80240334 0C0129E1 */  jal       func_8004A784
/* DE27C8 80240338 0000382D */   daddu    $a3, $zero, $zero
/* DE27CC 8024033C 14400005 */  bnez      $v0, .L80240354
/* DE27D0 80240340 00000000 */   nop      
/* DE27D4 80240344 8E050018 */  lw        $a1, 0x18($s0)
/* DE27D8 80240348 8E06000C */  lw        $a2, 0xc($s0)
/* DE27DC 8024034C 0C00EA95 */  jal       npc_move_heading
/* DE27E0 80240350 0200202D */   daddu    $a0, $s0, $zero
.L80240354:
/* DE27E4 80240354 9602008E */  lhu       $v0, 0x8e($s0)
/* DE27E8 80240358 2442FFFF */  addiu     $v0, $v0, -1
/* DE27EC 8024035C A602008E */  sh        $v0, 0x8e($s0)
/* DE27F0 80240360 00021400 */  sll       $v0, $v0, 0x10
/* DE27F4 80240364 14400010 */  bnez      $v0, .L802403A8
/* DE27F8 80240368 00000000 */   nop      
/* DE27FC 8024036C C6000018 */  lwc1      $f0, 0x18($s0)
/* DE2800 80240370 3C018024 */  lui       $at, %hi(D_80242EE8)
/* DE2804 80240374 D4222EE8 */  ldc1      $f2, %lo(D_80242EE8)($at)
/* DE2808 80240378 46000021 */  cvt.d.s   $f0, $f0
/* DE280C 8024037C 46220002 */  mul.d     $f0, $f0, $f2
/* DE2810 80240380 00000000 */  nop       
/* DE2814 80240384 46200020 */  cvt.s.d   $f0, $f0
/* DE2818 80240388 E6000018 */  swc1      $f0, 0x18($s0)
/* DE281C 8024038C 8E2200CC */  lw        $v0, 0xcc($s1)
/* DE2820 80240390 8C43002C */  lw        $v1, 0x2c($v0)
/* DE2824 80240394 2402000A */  addiu     $v0, $zero, 0xa
/* DE2828 80240398 A602008E */  sh        $v0, 0x8e($s0)
/* DE282C 8024039C 24020010 */  addiu     $v0, $zero, 0x10
/* DE2830 802403A0 AE030028 */  sw        $v1, 0x28($s0)
/* DE2834 802403A4 AE420070 */  sw        $v0, 0x70($s2)
.L802403A8:
/* DE2838 802403A8 8FBF002C */  lw        $ra, 0x2c($sp)
/* DE283C 802403AC 8FB20028 */  lw        $s2, 0x28($sp)
/* DE2840 802403B0 8FB10024 */  lw        $s1, 0x24($sp)
/* DE2844 802403B4 8FB00020 */  lw        $s0, 0x20($sp)
/* DE2848 802403B8 03E00008 */  jr        $ra
/* DE284C 802403BC 27BD0030 */   addiu    $sp, $sp, 0x30
