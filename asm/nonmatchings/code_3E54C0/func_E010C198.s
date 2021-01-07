.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010C198
/* 3E5658 E010C198 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3E565C E010C19C AFBF0028 */  sw        $ra, 0x28($sp)
/* 3E5660 E010C1A0 AFB50024 */  sw        $s5, 0x24($sp)
/* 3E5664 E010C1A4 AFB40020 */  sw        $s4, 0x20($sp)
/* 3E5668 E010C1A8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3E566C E010C1AC AFB20018 */  sw        $s2, 0x18($sp)
/* 3E5670 E010C1B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 3E5674 E010C1B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 3E5678 E010C1B8 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 3E567C E010C1BC F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 3E5680 E010C1C0 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 3E5684 E010C1C4 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 3E5688 E010C1C8 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 3E568C E010C1CC F7B40030 */  sdc1      $f20, 0x30($sp)
/* 3E5690 E010C1D0 8C830000 */  lw        $v1, ($a0)
/* 3E5694 E010C1D4 8C91000C */  lw        $s1, 0xc($a0)
/* 3E5698 E010C1D8 30620010 */  andi      $v0, $v1, 0x10
/* 3E569C E010C1DC 10400005 */  beqz      $v0, .LE010C1F4
/* 3E56A0 E010C1E0 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3E56A4 E010C1E4 00621024 */  and       $v0, $v1, $v0
/* 3E56A8 E010C1E8 AC820000 */  sw        $v0, ($a0)
/* 3E56AC E010C1EC 24020010 */  addiu     $v0, $zero, 0x10
/* 3E56B0 E010C1F0 AE220010 */  sw        $v0, 0x10($s1)
.LE010C1F4:
/* 3E56B4 E010C1F4 8E230010 */  lw        $v1, 0x10($s1)
/* 3E56B8 E010C1F8 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3E56BC E010C1FC 10400002 */  beqz      $v0, .LE010C208
/* 3E56C0 E010C200 2462FFFF */   addiu    $v0, $v1, -1
/* 3E56C4 E010C204 AE220010 */  sw        $v0, 0x10($s1)
.LE010C208:
/* 3E56C8 E010C208 8E220014 */  lw        $v0, 0x14($s1)
/* 3E56CC E010C20C 8E230010 */  lw        $v1, 0x10($s1)
/* 3E56D0 E010C210 24420001 */  addiu     $v0, $v0, 1
/* 3E56D4 E010C214 04610005 */  bgez      $v1, .LE010C22C
/* 3E56D8 E010C218 AE220014 */   sw       $v0, 0x14($s1)
/* 3E56DC E010C21C 0C080128 */  jal       func_E02004A0
/* 3E56E0 E010C220 00000000 */   nop      
/* 3E56E4 E010C224 080430C6 */  j         .LE010C318
/* 3E56E8 E010C228 00000000 */   nop      
.LE010C22C:
/* 3E56EC E010C22C 0000982D */  daddu     $s3, $zero, $zero
/* 3E56F0 E010C230 3C159249 */  lui       $s5, 0x9249
/* 3E56F4 E010C234 36B52493 */  ori       $s5, $s5, 0x2493
/* 3E56F8 E010C238 2412FE98 */  addiu     $s2, $zero, -0x168
/* 3E56FC E010C23C 2414005C */  addiu     $s4, $zero, 0x5c
/* 3E5700 E010C240 C63C0048 */  lwc1      $f28, 0x48($s1)
/* 3E5704 E010C244 C6200044 */  lwc1      $f0, 0x44($s1)
/* 3E5708 E010C248 C6220040 */  lwc1      $f2, 0x40($s1)
/* 3E570C E010C24C C63A004C */  lwc1      $f26, 0x4c($s1)
/* 3E5710 E010C250 46020000 */  add.s     $f0, $f0, $f2
/* 3E5714 E010C254 C6380050 */  lwc1      $f24, 0x50($s1)
/* 3E5718 E010C258 C6360054 */  lwc1      $f22, 0x54($s1)
/* 3E571C E010C25C 46000786 */  mov.s     $f30, $f0
/* 3E5720 E010C260 E63E0044 */  swc1      $f30, 0x44($s1)
.LE010C264:
/* 3E5724 E010C264 16600007 */  bnez      $s3, .LE010C284
/* 3E5728 E010C268 02348021 */   addu     $s0, $s1, $s4
/* 3E572C E010C26C E61A0004 */  swc1      $f26, 4($s0)
/* 3E5730 E010C270 C6200058 */  lwc1      $f0, 0x58($s1)
/* 3E5734 E010C274 4600C000 */  add.s     $f0, $f24, $f0
/* 3E5738 E010C278 E616000C */  swc1      $f22, 0xc($s0)
/* 3E573C E010C27C 080430B8 */  j         .LE010C2E0
/* 3E5740 E010C280 E6000008 */   swc1     $f0, 8($s0)
.LE010C284:
/* 3E5744 E010C284 02550018 */  mult      $s2, $s5
/* 3E5748 E010C288 00121FC3 */  sra       $v1, $s2, 0x1f
/* 3E574C E010C28C 00002810 */  mfhi      $a1
/* 3E5750 E010C290 00B21021 */  addu      $v0, $a1, $s2
/* 3E5754 E010C294 00021083 */  sra       $v0, $v0, 2
/* 3E5758 E010C298 00431023 */  subu      $v0, $v0, $v1
/* 3E575C E010C29C 4482A000 */  mtc1      $v0, $f20
/* 3E5760 E010C2A0 00000000 */  nop       
/* 3E5764 E010C2A4 4680A520 */  cvt.s.w   $f20, $f20
/* 3E5768 E010C2A8 4614F500 */  add.s     $f20, $f30, $f20
/* 3E576C E010C2AC 0C080140 */  jal       func_E0200500
/* 3E5770 E010C2B0 4600A306 */   mov.s    $f12, $f20
/* 3E5774 E010C2B4 4600E002 */  mul.s     $f0, $f28, $f0
/* 3E5778 E010C2B8 00000000 */  nop       
/* 3E577C E010C2BC 4600D000 */  add.s     $f0, $f26, $f0
/* 3E5780 E010C2C0 4600A306 */  mov.s     $f12, $f20
/* 3E5784 E010C2C4 E6180008 */  swc1      $f24, 8($s0)
/* 3E5788 E010C2C8 0C080144 */  jal       func_E0200510
/* 3E578C E010C2CC E6000004 */   swc1     $f0, 4($s0)
/* 3E5790 E010C2D0 4600E002 */  mul.s     $f0, $f28, $f0
/* 3E5794 E010C2D4 00000000 */  nop       
/* 3E5798 E010C2D8 4600B000 */  add.s     $f0, $f22, $f0
/* 3E579C E010C2DC E600000C */  swc1      $f0, 0xc($s0)
.LE010C2E0:
/* 3E57A0 E010C2E0 8E020000 */  lw        $v0, ($s0)
/* 3E57A4 E010C2E4 30420002 */  andi      $v0, $v0, 2
/* 3E57A8 E010C2E8 14400007 */  bnez      $v0, .LE010C308
/* 3E57AC E010C2EC 26520168 */   addiu    $s2, $s2, 0x168
/* 3E57B0 E010C2F0 C6000004 */  lwc1      $f0, 4($s0)
/* 3E57B4 E010C2F4 C6020008 */  lwc1      $f2, 8($s0)
/* 3E57B8 E010C2F8 C604000C */  lwc1      $f4, 0xc($s0)
/* 3E57BC E010C2FC E6000010 */  swc1      $f0, 0x10($s0)
/* 3E57C0 E010C300 E6020014 */  swc1      $f2, 0x14($s0)
/* 3E57C4 E010C304 E6040018 */  swc1      $f4, 0x18($s0)
.LE010C308:
/* 3E57C8 E010C308 26730001 */  addiu     $s3, $s3, 1
/* 3E57CC E010C30C 2A620008 */  slti      $v0, $s3, 8
/* 3E57D0 E010C310 1440FFD4 */  bnez      $v0, .LE010C264
/* 3E57D4 E010C314 2694001C */   addiu    $s4, $s4, 0x1c
.LE010C318:
/* 3E57D8 E010C318 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3E57DC E010C31C 8FB50024 */  lw        $s5, 0x24($sp)
/* 3E57E0 E010C320 8FB40020 */  lw        $s4, 0x20($sp)
/* 3E57E4 E010C324 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3E57E8 E010C328 8FB20018 */  lw        $s2, 0x18($sp)
/* 3E57EC E010C32C 8FB10014 */  lw        $s1, 0x14($sp)
/* 3E57F0 E010C330 8FB00010 */  lw        $s0, 0x10($sp)
/* 3E57F4 E010C334 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 3E57F8 E010C338 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 3E57FC E010C33C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 3E5800 E010C340 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 3E5804 E010C344 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 3E5808 E010C348 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 3E580C E010C34C 03E00008 */  jr        $ra
/* 3E5810 E010C350 27BD0060 */   addiu    $sp, $sp, 0x60
