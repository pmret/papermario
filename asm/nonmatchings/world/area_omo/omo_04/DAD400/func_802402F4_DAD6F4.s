.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F4_DAD6F4
/* DAD6F4 802402F4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DAD6F8 802402F8 AFB00010 */  sw        $s0, 0x10($sp)
/* DAD6FC 802402FC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* DAD700 80240300 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* DAD704 80240304 AFBF0018 */  sw        $ra, 0x18($sp)
/* DAD708 80240308 AFB10014 */  sw        $s1, 0x14($sp)
/* DAD70C 8024030C F7B60028 */  sdc1      $f22, 0x28($sp)
/* DAD710 80240310 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DAD714 80240314 C60C0080 */  lwc1      $f12, 0x80($s0)
/* DAD718 80240318 0C00A8BB */  jal       sin_deg
/* DAD71C 8024031C 0080882D */   daddu    $s1, $a0, $zero
/* DAD720 80240320 C6140054 */  lwc1      $f20, 0x54($s0)
/* DAD724 80240324 3C0140A0 */  lui       $at, 0x40a0
/* DAD728 80240328 4481B000 */  mtc1      $at, $f22
/* DAD72C 8024032C 00000000 */  nop
/* DAD730 80240330 4616A502 */  mul.s     $f20, $f20, $f22
/* DAD734 80240334 00000000 */  nop
/* DAD738 80240338 C60C0080 */  lwc1      $f12, 0x80($s0)
/* DAD73C 8024033C 4600A502 */  mul.s     $f20, $f20, $f0
/* DAD740 80240340 0C00A8D4 */  jal       cos_deg
/* DAD744 80240344 00000000 */   nop
/* DAD748 80240348 C6040054 */  lwc1      $f4, 0x54($s0)
/* DAD74C 8024034C 46162102 */  mul.s     $f4, $f4, $f22
/* DAD750 80240350 00000000 */  nop
/* DAD754 80240354 C6020028 */  lwc1      $f2, 0x28($s0)
/* DAD758 80240358 46141080 */  add.s     $f2, $f2, $f20
/* DAD75C 8024035C 46000007 */  neg.s     $f0, $f0
/* DAD760 80240360 46002102 */  mul.s     $f4, $f4, $f0
/* DAD764 80240364 00000000 */  nop
/* DAD768 80240368 4600118D */  trunc.w.s $f6, $f2
/* DAD76C 8024036C E6260084 */  swc1      $f6, 0x84($s1)
/* DAD770 80240370 C6000030 */  lwc1      $f0, 0x30($s0)
/* DAD774 80240374 46040000 */  add.s     $f0, $f0, $f4
/* DAD778 80240378 4600018D */  trunc.w.s $f6, $f0
/* DAD77C 8024037C E6260088 */  swc1      $f6, 0x88($s1)
/* DAD780 80240380 8FBF0018 */  lw        $ra, 0x18($sp)
/* DAD784 80240384 8FB10014 */  lw        $s1, 0x14($sp)
/* DAD788 80240388 8FB00010 */  lw        $s0, 0x10($sp)
/* DAD78C 8024038C D7B60028 */  ldc1      $f22, 0x28($sp)
/* DAD790 80240390 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DAD794 80240394 24020002 */  addiu     $v0, $zero, 2
/* DAD798 80240398 03E00008 */  jr        $ra
/* DAD79C 8024039C 27BD0030 */   addiu    $sp, $sp, 0x30
