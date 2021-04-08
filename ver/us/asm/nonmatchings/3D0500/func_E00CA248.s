.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00CA248
/* 3D0748 E00CA248 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D074C E00CA24C AFBF0018 */  sw        $ra, 0x18($sp)
/* 3D0750 E00CA250 AFB10014 */  sw        $s1, 0x14($sp)
/* 3D0754 E00CA254 AFB00010 */  sw        $s0, 0x10($sp)
/* 3D0758 E00CA258 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 3D075C E00CA25C 8C830000 */  lw        $v1, ($a0)
/* 3D0760 E00CA260 8C90000C */  lw        $s0, 0xc($a0)
/* 3D0764 E00CA264 30620010 */  andi      $v0, $v1, 0x10
/* 3D0768 E00CA268 8E050000 */  lw        $a1, ($s0)
/* 3D076C E00CA26C 10400005 */  beqz      $v0, .LE00CA284
/* 3D0770 E00CA270 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D0774 E00CA274 00621024 */  and       $v0, $v1, $v0
/* 3D0778 E00CA278 AC820000 */  sw        $v0, ($a0)
/* 3D077C E00CA27C 24020010 */  addiu     $v0, $zero, 0x10
/* 3D0780 E00CA280 AE020010 */  sw        $v0, 0x10($s0)
.LE00CA284:
/* 3D0784 E00CA284 8E030010 */  lw        $v1, 0x10($s0)
/* 3D0788 E00CA288 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3D078C E00CA28C 10400002 */  beqz      $v0, .LE00CA298
/* 3D0790 E00CA290 2462FFFF */   addiu    $v0, $v1, -1
/* 3D0794 E00CA294 AE020010 */  sw        $v0, 0x10($s0)
.LE00CA298:
/* 3D0798 E00CA298 8E020014 */  lw        $v0, 0x14($s0)
/* 3D079C E00CA29C 8E030010 */  lw        $v1, 0x10($s0)
/* 3D07A0 E00CA2A0 24420001 */  addiu     $v0, $v0, 1
/* 3D07A4 E00CA2A4 04610005 */  bgez      $v1, .LE00CA2BC
/* 3D07A8 E00CA2A8 AE020014 */   sw       $v0, 0x14($s0)
/* 3D07AC E00CA2AC 0C080128 */  jal       func_E02004A0
/* 3D07B0 E00CA2B0 00000000 */   nop
/* 3D07B4 E00CA2B4 0803291B */  j         .LE00CA46C
/* 3D07B8 E00CA2B8 00000000 */   nop
.LE00CA2BC:
/* 3D07BC E00CA2BC 0040882D */  daddu     $s1, $v0, $zero
/* 3D07C0 E00CA2C0 28620010 */  slti      $v0, $v1, 0x10
/* 3D07C4 E00CA2C4 10400002 */  beqz      $v0, .LE00CA2D0
/* 3D07C8 E00CA2C8 00031100 */   sll      $v0, $v1, 4
/* 3D07CC E00CA2CC AE020024 */  sw        $v0, 0x24($s0)
.LE00CA2D0:
/* 3D07D0 E00CA2D0 24020003 */  addiu     $v0, $zero, 3
/* 3D07D4 E00CA2D4 14A20020 */  bne       $a1, $v0, .LE00CA358
/* 3D07D8 E00CA2D8 3C028888 */   lui      $v0, %hi(D_8887FFFB)
/* 3D07DC E00CA2DC 0C080138 */  jal       func_E02004E0
/* 3D07E0 E00CA2E0 2404000A */   addiu    $a0, $zero, 0xa
/* 3D07E4 E00CA2E4 2442FFFB */  addiu     $v0, $v0, %lo(D_8887FFFB)
/* 3D07E8 E00CA2E8 C6000044 */  lwc1      $f0, 0x44($s0)
/* 3D07EC E00CA2EC 44821000 */  mtc1      $v0, $f2
/* 3D07F0 E00CA2F0 00000000 */  nop
/* 3D07F4 E00CA2F4 468010A0 */  cvt.s.w   $f2, $f2
/* 3D07F8 E00CA2F8 46020000 */  add.s     $f0, $f0, $f2
/* 3D07FC E00CA2FC 2404000A */  addiu     $a0, $zero, 0xa
/* 3D0800 E00CA300 0C080138 */  jal       func_E02004E0
/* 3D0804 E00CA304 E6000044 */   swc1     $f0, 0x44($s0)
/* 3D0808 E00CA308 2442FFFB */  addiu     $v0, $v0, -5
/* 3D080C E00CA30C 44820000 */  mtc1      $v0, $f0
/* 3D0810 E00CA310 00000000 */  nop
/* 3D0814 E00CA314 46800020 */  cvt.s.w   $f0, $f0
/* 3D0818 E00CA318 C6020048 */  lwc1      $f2, 0x48($s0)
/* 3D081C E00CA31C C6060038 */  lwc1      $f6, 0x38($s0)
/* 3D0820 E00CA320 46001080 */  add.s     $f2, $f2, $f0
/* 3D0824 E00CA324 C6000044 */  lwc1      $f0, 0x44($s0)
/* 3D0828 E00CA328 C6040040 */  lwc1      $f4, 0x40($s0)
/* 3D082C E00CA32C 46003180 */  add.s     $f6, $f6, $f0
/* 3D0830 E00CA330 C600004C */  lwc1      $f0, 0x4c($s0)
/* 3D0834 E00CA334 46002100 */  add.s     $f4, $f4, $f0
/* 3D0838 E00CA338 E6020048 */  swc1      $f2, 0x48($s0)
/* 3D083C E00CA33C C602003C */  lwc1      $f2, 0x3c($s0)
/* 3D0840 E00CA340 C6000048 */  lwc1      $f0, 0x48($s0)
/* 3D0844 E00CA344 46001080 */  add.s     $f2, $f2, $f0
/* 3D0848 E00CA348 E6060038 */  swc1      $f6, 0x38($s0)
/* 3D084C E00CA34C E6040040 */  swc1      $f4, 0x40($s0)
/* 3D0850 E00CA350 E602003C */  swc1      $f2, 0x3c($s0)
/* 3D0854 E00CA354 3C028888 */  lui       $v0, 0x8888
.LE00CA358:
/* 3D0858 E00CA358 8E0402A8 */  lw        $a0, 0x2a8($s0)
/* 3D085C E00CA35C 34428889 */  ori       $v0, $v0, 0x8889
/* 3D0860 E00CA360 00820018 */  mult      $a0, $v0
/* 3D0864 E00CA364 C6080038 */  lwc1      $f8, 0x38($s0)
/* 3D0868 E00CA368 C606003C */  lwc1      $f6, 0x3c($s0)
/* 3D086C E00CA36C C60A0040 */  lwc1      $f10, 0x40($s0)
/* 3D0870 E00CA370 00041FC3 */  sra       $v1, $a0, 0x1f
/* 3D0874 E00CA374 00003010 */  mfhi      $a2
/* 3D0878 E00CA378 00C41021 */  addu      $v0, $a2, $a0
/* 3D087C E00CA37C 00021103 */  sra       $v0, $v0, 4
/* 3D0880 E00CA380 00431823 */  subu      $v1, $v0, $v1
/* 3D0884 E00CA384 00031100 */  sll       $v0, $v1, 4
/* 3D0888 E00CA388 00431023 */  subu      $v0, $v0, $v1
/* 3D088C E00CA38C 00021040 */  sll       $v0, $v0, 1
/* 3D0890 E00CA390 00821823 */  subu      $v1, $a0, $v0
/* 3D0894 E00CA394 00031080 */  sll       $v0, $v1, 2
/* 3D0898 E00CA398 02021021 */  addu      $v0, $s0, $v0
/* 3D089C E00CA39C C4420050 */  lwc1      $f2, 0x50($v0)
/* 3D08A0 E00CA3A0 C44000C8 */  lwc1      $f0, 0xc8($v0)
/* 3D08A4 E00CA3A4 C44C0140 */  lwc1      $f12, 0x140($v0)
/* 3D08A8 E00CA3A8 46024032 */  c.eq.s    $f8, $f2
/* 3D08AC E00CA3AC 00000000 */  nop
/* 3D08B0 E00CA3B0 45000009 */  bc1f      .LE00CA3D8
/* 3D08B4 E00CA3B4 00031880 */   sll      $v1, $v1, 2
/* 3D08B8 E00CA3B8 46003032 */  c.eq.s    $f6, $f0
/* 3D08BC E00CA3BC 00000000 */  nop
/* 3D08C0 E00CA3C0 45000005 */  bc1f      .LE00CA3D8
/* 3D08C4 E00CA3C4 00000000 */   nop
/* 3D08C8 E00CA3C8 460C5032 */  c.eq.s    $f10, $f12
/* 3D08CC E00CA3CC 00000000 */  nop
/* 3D08D0 E00CA3D0 45010026 */  bc1t      .LE00CA46C
/* 3D08D4 E00CA3D4 00000000 */   nop
.LE00CA3D8:
/* 3D08D8 E00CA3D8 02031821 */  addu      $v1, $s0, $v1
/* 3D08DC E00CA3DC 8E0202A8 */  lw        $v0, 0x2a8($s0)
/* 3D08E0 E00CA3E0 C47402AC */  lwc1      $f20, 0x2ac($v1)
/* 3D08E4 E00CA3E4 24420001 */  addiu     $v0, $v0, 1
/* 3D08E8 E00CA3E8 AE0202A8 */  sw        $v0, 0x2a8($s0)
/* 3D08EC E00CA3EC 2842001E */  slti      $v0, $v0, 0x1e
/* 3D08F0 E00CA3F0 50400001 */  beql      $v0, $zero, .LE00CA3F8
/* 3D08F4 E00CA3F4 AE0002A8 */   sw       $zero, 0x2a8($s0)
.LE00CA3F8:
/* 3D08F8 E00CA3F8 46024101 */  sub.s     $f4, $f8, $f2
/* 3D08FC E00CA3FC 46042102 */  mul.s     $f4, $f4, $f4
/* 3D0900 E00CA400 00000000 */  nop
/* 3D0904 E00CA404 46003001 */  sub.s     $f0, $f6, $f0
/* 3D0908 E00CA408 46000002 */  mul.s     $f0, $f0, $f0
/* 3D090C E00CA40C 00000000 */  nop
/* 3D0910 E00CA410 8E0302A8 */  lw        $v1, 0x2a8($s0)
/* 3D0914 E00CA414 460C5081 */  sub.s     $f2, $f10, $f12
/* 3D0918 E00CA418 00031080 */  sll       $v0, $v1, 2
/* 3D091C E00CA41C 46021082 */  mul.s     $f2, $f2, $f2
/* 3D0920 E00CA420 00000000 */  nop
/* 3D0924 E00CA424 02028021 */  addu      $s0, $s0, $v0
/* 3D0928 E00CA428 24020001 */  addiu     $v0, $zero, 1
/* 3D092C E00CA42C AE020230 */  sw        $v0, 0x230($s0)
/* 3D0930 E00CA430 E6080050 */  swc1      $f8, 0x50($s0)
/* 3D0934 E00CA434 46002100 */  add.s     $f4, $f4, $f0
/* 3D0938 E00CA438 E60600C8 */  swc1      $f6, 0xc8($s0)
/* 3D093C E00CA43C 44800000 */  mtc1      $zero, $f0
/* 3D0940 E00CA440 46022300 */  add.s     $f12, $f4, $f2
/* 3D0944 E00CA444 E60A0140 */  swc1      $f10, 0x140($s0)
/* 3D0948 E00CA448 46006032 */  c.eq.s    $f12, $f0
/* 3D094C E00CA44C 00000000 */  nop
/* 3D0950 E00CA450 45010004 */  bc1t      .LE00CA464
/* 3D0954 E00CA454 AE1101B8 */   sw       $s1, 0x1b8($s0)
/* 3D0958 E00CA458 0C080154 */  jal       func_E0200550
/* 3D095C E00CA45C 00000000 */   nop
/* 3D0960 E00CA460 46000306 */  mov.s     $f12, $f0
.LE00CA464:
/* 3D0964 E00CA464 460CA000 */  add.s     $f0, $f20, $f12
/* 3D0968 E00CA468 E60002AC */  swc1      $f0, 0x2ac($s0)
.LE00CA46C:
/* 3D096C E00CA46C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3D0970 E00CA470 8FB10014 */  lw        $s1, 0x14($sp)
/* 3D0974 E00CA474 8FB00010 */  lw        $s0, 0x10($sp)
/* 3D0978 E00CA478 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 3D097C E00CA47C 03E00008 */  jr        $ra
/* 3D0980 E00CA480 27BD0028 */   addiu    $sp, $sp, 0x28
