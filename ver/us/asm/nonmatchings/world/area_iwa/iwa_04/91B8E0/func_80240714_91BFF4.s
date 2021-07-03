.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242BA8_91E488
.double 0.9

.section .text

glabel func_80240714_91BFF4
/* 91BFF4 80240714 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 91BFF8 80240718 AFB30024 */  sw        $s3, 0x24($sp)
/* 91BFFC 8024071C 0080982D */  daddu     $s3, $a0, $zero
/* 91C000 80240720 AFBF002C */  sw        $ra, 0x2c($sp)
/* 91C004 80240724 AFB40028 */  sw        $s4, 0x28($sp)
/* 91C008 80240728 AFB20020 */  sw        $s2, 0x20($sp)
/* 91C00C 8024072C AFB1001C */  sw        $s1, 0x1c($sp)
/* 91C010 80240730 AFB00018 */  sw        $s0, 0x18($sp)
/* 91C014 80240734 8E710148 */  lw        $s1, 0x148($s3)
/* 91C018 80240738 86240008 */  lh        $a0, 8($s1)
/* 91C01C 8024073C 0C00EABB */  jal       get_npc_unsafe
/* 91C020 80240740 00A0A02D */   daddu    $s4, $a1, $zero
/* 91C024 80240744 0040802D */  daddu     $s0, $v0, $zero
/* 91C028 80240748 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* 91C02C 8024074C 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* 91C030 80240750 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91C034 80240754 8E420000 */  lw        $v0, ($s2)
/* 91C038 80240758 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91C03C 8024075C 8C460028 */  lw        $a2, 0x28($v0)
/* 91C040 80240760 0C00A720 */  jal       atan2
/* 91C044 80240764 8C470030 */   lw       $a3, 0x30($v0)
/* 91C048 80240768 3C025555 */  lui       $v0, 0x5555
/* 91C04C 8024076C 9603008E */  lhu       $v1, 0x8e($s0)
/* 91C050 80240770 34425556 */  ori       $v0, $v0, 0x5556
/* 91C054 80240774 00031C00 */  sll       $v1, $v1, 0x10
/* 91C058 80240778 00032403 */  sra       $a0, $v1, 0x10
/* 91C05C 8024077C 00820018 */  mult      $a0, $v0
/* 91C060 80240780 00031FC3 */  sra       $v1, $v1, 0x1f
/* 91C064 80240784 00004010 */  mfhi      $t0
/* 91C068 80240788 01031823 */  subu      $v1, $t0, $v1
/* 91C06C 8024078C 00031040 */  sll       $v0, $v1, 1
/* 91C070 80240790 00431021 */  addu      $v0, $v0, $v1
/* 91C074 80240794 00822023 */  subu      $a0, $a0, $v0
/* 91C078 80240798 00042400 */  sll       $a0, $a0, 0x10
/* 91C07C 8024079C 1480000C */  bnez      $a0, .L802407D0
/* 91C080 802407A0 E600000C */   swc1     $f0, 0xc($s0)
/* 91C084 802407A4 C6020040 */  lwc1      $f2, 0x40($s0)
/* 91C088 802407A8 3C014000 */  lui       $at, 0x4000
/* 91C08C 802407AC 44810000 */  mtc1      $at, $f0
/* 91C090 802407B0 AFA00010 */  sw        $zero, 0x10($sp)
/* 91C094 802407B4 AFA00014 */  sw        $zero, 0x14($sp)
/* 91C098 802407B8 46001080 */  add.s     $f2, $f2, $f0
/* 91C09C 802407BC 8E06003C */  lw        $a2, 0x3c($s0)
/* 91C0A0 802407C0 8E050038 */  lw        $a1, 0x38($s0)
/* 91C0A4 802407C4 44071000 */  mfc1      $a3, $f2
/* 91C0A8 802407C8 0C01BECC */  jal       fx_walk
/* 91C0AC 802407CC 24040002 */   addiu    $a0, $zero, 2
.L802407D0:
/* 91C0B0 802407D0 9602008E */  lhu       $v0, 0x8e($s0)
/* 91C0B4 802407D4 2442FFFF */  addiu     $v0, $v0, -1
/* 91C0B8 802407D8 A602008E */  sh        $v0, 0x8e($s0)
/* 91C0BC 802407DC 00021400 */  sll       $v0, $v0, 0x10
/* 91C0C0 802407E0 1C40002C */  bgtz      $v0, .L80240894
/* 91C0C4 802407E4 00000000 */   nop
/* 91C0C8 802407E8 C6000038 */  lwc1      $f0, 0x38($s0)
/* 91C0CC 802407EC 4600010D */  trunc.w.s $f4, $f0
/* 91C0D0 802407F0 44022000 */  mfc1      $v0, $f4
/* 91C0D4 802407F4 00000000 */  nop
/* 91C0D8 802407F8 A6220010 */  sh        $v0, 0x10($s1)
/* 91C0DC 802407FC C600003C */  lwc1      $f0, 0x3c($s0)
/* 91C0E0 80240800 4600010D */  trunc.w.s $f4, $f0
/* 91C0E4 80240804 44022000 */  mfc1      $v0, $f4
/* 91C0E8 80240808 00000000 */  nop
/* 91C0EC 8024080C A6220012 */  sh        $v0, 0x12($s1)
/* 91C0F0 80240810 C6000040 */  lwc1      $f0, 0x40($s0)
/* 91C0F4 80240814 24020001 */  addiu     $v0, $zero, 1
/* 91C0F8 80240818 A2220007 */  sb        $v0, 7($s1)
/* 91C0FC 8024081C 4600010D */  trunc.w.s $f4, $f0
/* 91C100 80240820 44022000 */  mfc1      $v0, $f4
/* 91C104 80240824 00000000 */  nop
/* 91C108 80240828 A6220014 */  sh        $v0, 0x14($s1)
/* 91C10C 8024082C C6800018 */  lwc1      $f0, 0x18($s4)
/* 91C110 80240830 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91C114 80240834 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91C118 80240838 8E420000 */  lw        $v0, ($s2)
/* 91C11C 8024083C E6000018 */  swc1      $f0, 0x18($s0)
/* 91C120 80240840 8C460028 */  lw        $a2, 0x28($v0)
/* 91C124 80240844 0C00A7B5 */  jal       dist2D
/* 91C128 80240848 8C470030 */   lw       $a3, 0x30($v0)
/* 91C12C 8024084C C6020018 */  lwc1      $f2, 0x18($s0)
/* 91C130 80240850 46020003 */  div.s     $f0, $f0, $f2
/* 91C134 80240854 3C018024 */  lui       $at, %hi(D_80242BA8_91E488)
/* 91C138 80240858 D4222BA8 */  ldc1      $f2, %lo(D_80242BA8_91E488)($at)
/* 91C13C 8024085C 46000021 */  cvt.d.s   $f0, $f0
/* 91C140 80240860 46220000 */  add.d     $f0, $f0, $f2
/* 91C144 80240864 4620010D */  trunc.w.d $f4, $f0
/* 91C148 80240868 44022000 */  mfc1      $v0, $f4
/* 91C14C 8024086C 00000000 */  nop
/* 91C150 80240870 A602008E */  sh        $v0, 0x8e($s0)
/* 91C154 80240874 00021400 */  sll       $v0, $v0, 0x10
/* 91C158 80240878 00021403 */  sra       $v0, $v0, 0x10
/* 91C15C 8024087C 2842000F */  slti      $v0, $v0, 0xf
/* 91C160 80240880 10400002 */  beqz      $v0, .L8024088C
/* 91C164 80240884 2402000F */   addiu    $v0, $zero, 0xf
/* 91C168 80240888 A602008E */  sh        $v0, 0x8e($s0)
.L8024088C:
/* 91C16C 8024088C 24020016 */  addiu     $v0, $zero, 0x16
/* 91C170 80240890 AE620070 */  sw        $v0, 0x70($s3)
.L80240894:
/* 91C174 80240894 8FBF002C */  lw        $ra, 0x2c($sp)
/* 91C178 80240898 8FB40028 */  lw        $s4, 0x28($sp)
/* 91C17C 8024089C 8FB30024 */  lw        $s3, 0x24($sp)
/* 91C180 802408A0 8FB20020 */  lw        $s2, 0x20($sp)
/* 91C184 802408A4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 91C188 802408A8 8FB00018 */  lw        $s0, 0x18($sp)
/* 91C18C 802408AC 03E00008 */  jr        $ra
/* 91C190 802408B0 27BD0030 */   addiu    $sp, $sp, 0x30
