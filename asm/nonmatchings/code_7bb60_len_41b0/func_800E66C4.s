.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E66C4
/* 7FB74 800E66C4 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 7FB78 800E66C8 AFB20040 */  sw        $s2, 0x40($sp)
/* 7FB7C 800E66CC 3C128011 */  lui       $s2, 0x8011
/* 7FB80 800E66D0 2652EFC8 */  addiu     $s2, $s2, -0x1038
/* 7FB84 800E66D4 3C04800B */  lui       $a0, 0x800b
/* 7FB88 800E66D8 24841D80 */  addiu     $a0, $a0, 0x1d80
/* 7FB8C 800E66DC AFBF0048 */  sw        $ra, 0x48($sp)
/* 7FB90 800E66E0 AFB30044 */  sw        $s3, 0x44($sp)
/* 7FB94 800E66E4 AFB1003C */  sw        $s1, 0x3c($sp)
/* 7FB98 800E66E8 AFB00038 */  sw        $s0, 0x38($sp)
/* 7FB9C 800E66EC F7B60058 */  sdc1      $f22, 0x58($sp)
/* 7FBA0 800E66F0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 7FBA4 800E66F4 C64400A8 */  lwc1      $f4, 0xa8($s2)
/* 7FBA8 800E66F8 3C038007 */  lui       $v1, 0x8007
/* 7FBAC 800E66FC 8C637410 */  lw        $v1, 0x7410($v1)
/* 7FBB0 800E6700 3C0142B4 */  lui       $at, 0x42b4
/* 7FBB4 800E6704 44810000 */  mtc1      $at, $f0
/* 7FBB8 800E6708 00031080 */  sll       $v0, $v1, 2
/* 7FBBC 800E670C 00431021 */  addu      $v0, $v0, $v1
/* 7FBC0 800E6710 00021080 */  sll       $v0, $v0, 2
/* 7FBC4 800E6714 00431023 */  subu      $v0, $v0, $v1
/* 7FBC8 800E6718 000218C0 */  sll       $v1, $v0, 3
/* 7FBCC 800E671C 00431021 */  addu      $v0, $v0, $v1
/* 7FBD0 800E6720 000210C0 */  sll       $v0, $v0, 3
/* 7FBD4 800E6724 4604003E */  c.le.s    $f0, $f4
/* 7FBD8 800E6728 00000000 */  nop       
/* 7FBDC 800E672C 4500000B */  bc1f      .L800E675C
/* 7FBE0 800E6730 00441021 */   addu     $v0, $v0, $a0
/* 7FBE4 800E6734 3C014387 */  lui       $at, 0x4387
/* 7FBE8 800E6738 44811000 */  mtc1      $at, $f2
/* 7FBEC 800E673C 00000000 */  nop       
/* 7FBF0 800E6740 4602203C */  c.lt.s    $f4, $f2
/* 7FBF4 800E6744 00000000 */  nop       
/* 7FBF8 800E6748 45000004 */  bc1f      .L800E675C
/* 7FBFC 800E674C 00000000 */   nop      
/* 7FC00 800E6750 C440006C */  lwc1      $f0, 0x6c($v0)
/* 7FC04 800E6754 080399DC */  j         .L800E6770
/* 7FC08 800E6758 46020501 */   sub.s    $f20, $f0, $f2
.L800E675C:
/* 7FC0C 800E675C C442006C */  lwc1      $f2, 0x6c($v0)
/* 7FC10 800E6760 3C0142B4 */  lui       $at, 0x42b4
/* 7FC14 800E6764 44810000 */  mtc1      $at, $f0
/* 7FC18 800E6768 00000000 */  nop       
/* 7FC1C 800E676C 46001501 */  sub.s     $f20, $f2, $f0
.L800E6770:
/* 7FC20 800E6770 0C00A6C9 */  jal       clamp_angle
/* 7FC24 800E6774 4600A306 */   mov.s    $f12, $f20
/* 7FC28 800E6778 27A50020 */  addiu     $a1, $sp, 0x20
/* 7FC2C 800E677C 27A60024 */  addiu     $a2, $sp, 0x24
/* 7FC30 800E6780 3C0140C9 */  lui       $at, 0x40c9
/* 7FC34 800E6784 34210FD0 */  ori       $at, $at, 0xfd0
/* 7FC38 800E6788 44811000 */  mtc1      $at, $f2
/* 7FC3C 800E678C 24110002 */  addiu     $s1, $zero, 2
/* 7FC40 800E6790 46020002 */  mul.s     $f0, $f0, $f2
/* 7FC44 800E6794 00000000 */  nop       
/* 7FC48 800E6798 0220802D */  daddu     $s0, $s1, $zero
/* 7FC4C 800E679C 27B30030 */  addiu     $s3, $sp, 0x30
/* 7FC50 800E67A0 3C0143B4 */  lui       $at, 0x43b4
/* 7FC54 800E67A4 44816000 */  mtc1      $at, $f12
/* 7FC58 800E67A8 3C014080 */  lui       $at, 0x4080
/* 7FC5C 800E67AC 4481B000 */  mtc1      $at, $f22
/* 7FC60 800E67B0 0C00A82D */  jal       sin_cos_rad
/* 7FC64 800E67B4 460C0303 */   div.s    $f12, $f0, $f12
.L800E67B8:
/* 7FC68 800E67B8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7FC6C 800E67BC 44911000 */  mtc1      $s1, $f2
/* 7FC70 800E67C0 00000000 */  nop       
/* 7FC74 800E67C4 468010A0 */  cvt.s.w   $f2, $f2
/* 7FC78 800E67C8 46020002 */  mul.s     $f0, $f0, $f2
/* 7FC7C 800E67CC 00000000 */  nop       
/* 7FC80 800E67D0 C7A40024 */  lwc1      $f4, 0x24($sp)
/* 7FC84 800E67D4 46022102 */  mul.s     $f4, $f4, $f2
/* 7FC88 800E67D8 00000000 */  nop       
/* 7FC8C 800E67DC 0240282D */  daddu     $a1, $s2, $zero
/* 7FC90 800E67E0 C642002C */  lwc1      $f2, 0x2c($s2)
/* 7FC94 800E67E4 27A60028 */  addiu     $a2, $sp, 0x28
/* 7FC98 800E67E8 46161080 */  add.s     $f2, $f2, $f22
/* 7FC9C 800E67EC C6460028 */  lwc1      $f6, 0x28($s2)
/* 7FCA0 800E67F0 24040003 */  addiu     $a0, $zero, 3
/* 7FCA4 800E67F4 46003180 */  add.s     $f6, $f6, $f0
/* 7FCA8 800E67F8 C6400030 */  lwc1      $f0, 0x30($s2)
/* 7FCAC 800E67FC 27A7002C */  addiu     $a3, $sp, 0x2c
/* 7FCB0 800E6800 46040001 */  sub.s     $f0, $f0, $f4
/* 7FCB4 800E6804 E7A2002C */  swc1      $f2, 0x2c($sp)
/* 7FCB8 800E6808 E7A60028 */  swc1      $f6, 0x28($sp)
/* 7FCBC 800E680C E7A00030 */  swc1      $f0, 0x30($sp)
/* 7FCC0 800E6810 AFB30010 */  sw        $s3, 0x10($sp)
/* 7FCC4 800E6814 E7B60014 */  swc1      $f22, 0x14($sp)
/* 7FCC8 800E6818 0C037B01 */  jal       do_lateral_collision
/* 7FCCC 800E681C E7B40018 */   swc1     $f20, 0x18($sp)
/* 7FCD0 800E6820 04410003 */  bgez      $v0, .L800E6830
/* 7FCD4 800E6824 2610FFFF */   addiu    $s0, $s0, -1
/* 7FCD8 800E6828 1E00FFE3 */  bgtz      $s0, .L800E67B8
/* 7FCDC 800E682C 26310012 */   addiu    $s1, $s1, 0x12
.L800E6830:
/* 7FCE0 800E6830 8FBF0048 */  lw        $ra, 0x48($sp)
/* 7FCE4 800E6834 8FB30044 */  lw        $s3, 0x44($sp)
/* 7FCE8 800E6838 8FB20040 */  lw        $s2, 0x40($sp)
/* 7FCEC 800E683C 8FB1003C */  lw        $s1, 0x3c($sp)
/* 7FCF0 800E6840 8FB00038 */  lw        $s0, 0x38($sp)
/* 7FCF4 800E6844 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 7FCF8 800E6848 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 7FCFC 800E684C 03E00008 */  jr        $ra
/* 7FD00 800E6850 27BD0060 */   addiu    $sp, $sp, 0x60
/* 7FD04 800E6854 00000000 */  nop       
/* 7FD08 800E6858 00000000 */  nop       
/* 7FD0C 800E685C 00000000 */  nop       
