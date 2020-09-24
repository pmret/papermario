.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EBB40
/* 84FF0 800EBB40 3C028007 */  lui       $v0, 0x8007
/* 84FF4 800EBB44 8C42419C */  lw        $v0, 0x419c($v0)
/* 84FF8 800EBB48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 84FFC 800EBB4C AFB00010 */  sw        $s0, 0x10($sp)
/* 85000 800EBB50 AFB20018 */  sw        $s2, 0x18($sp)
/* 85004 800EBB54 3C128011 */  lui       $s2, 0x8011
/* 85008 800EBB58 2652EFC8 */  addiu     $s2, $s2, -0x1038
/* 8500C 800EBB5C AFBF001C */  sw        $ra, 0x1c($sp)
/* 85010 800EBB60 AFB10014 */  sw        $s1, 0x14($sp)
/* 85014 800EBB64 80420081 */  lb        $v0, 0x81($v0)
/* 85018 800EBB68 3C118011 */  lui       $s1, 0x8011
/* 8501C 800EBB6C 2631EBB0 */  addiu     $s1, $s1, -0x1450
/* 85020 800EBB70 1040000B */  beqz      $v0, .L800EBBA0
/* 85024 800EBB74 0080802D */   daddu    $s0, $a0, $zero
/* 85028 800EBB78 8E420000 */  lw        $v0, ($s2)
/* 8502C 800EBB7C 30423000 */  andi      $v0, $v0, 0x3000
/* 85030 800EBB80 14400007 */  bnez      $v0, .L800EBBA0
/* 85034 800EBB84 00000000 */   nop      
/* 85038 800EBB88 82220014 */  lb        $v0, 0x14($s1)
/* 8503C 800EBB8C 14400004 */  bnez      $v0, .L800EBBA0
/* 85040 800EBB90 00000000 */   nop      
/* 85044 800EBB94 82220002 */  lb        $v0, 2($s1)
/* 85048 800EBB98 1040000B */  beqz      $v0, .L800EBBC8
/* 8504C 800EBB9C 00000000 */   nop      
.L800EBBA0:
/* 85050 800EBBA0 8E420004 */  lw        $v0, 4($s2)
/* 85054 800EBBA4 30420800 */  andi      $v0, $v0, 0x800
/* 85058 800EBBA8 14400003 */  bnez      $v0, .L800EBBB8
/* 8505C 800EBBAC 00000000 */   nop      
/* 85060 800EBBB0 0C03AF1D */  jal       func_800EBC74
/* 85064 800EBBB4 0200202D */   daddu    $a0, $s0, $zero
.L800EBBB8:
/* 85068 800EBBB8 8E22000C */  lw        $v0, 0xc($s1)
/* 8506C 800EBBBC 30426006 */  andi      $v0, $v0, 0x6006
/* 85070 800EBBC0 54400001 */  bnel      $v0, $zero, .L800EBBC8
/* 85074 800EBBC4 A2200002 */   sb       $zero, 2($s1)
.L800EBBC8:
/* 85078 800EBBC8 3C038011 */  lui       $v1, 0x8011
/* 8507C 800EBBCC 8463CFC8 */  lh        $v1, -0x3038($v1)
/* 85080 800EBBD0 24020032 */  addiu     $v0, $zero, 0x32
/* 85084 800EBBD4 10620016 */  beq       $v1, $v0, .L800EBC30
/* 85088 800EBBD8 00000000 */   nop      
/* 8508C 800EBBDC C600003C */  lwc1      $f0, 0x3c($s0)
/* 85090 800EBBE0 C642002C */  lwc1      $f2, 0x2c($s2)
/* 85094 800EBBE4 46020001 */  sub.s     $f0, $f0, $f2
/* 85098 800EBBE8 3C01447A */  lui       $at, 0x447a
/* 8509C 800EBBEC 44811000 */  mtc1      $at, $f2
/* 850A0 800EBBF0 46000005 */  abs.s     $f0, $f0
/* 850A4 800EBBF4 4600103C */  c.lt.s    $f2, $f0
/* 850A8 800EBBF8 00000000 */  nop       
/* 850AC 800EBBFC 4500000C */  bc1f      .L800EBC30
/* 850B0 800EBC00 2403F7FF */   addiu    $v1, $zero, -0x801
/* 850B4 800EBC04 C6400028 */  lwc1      $f0, 0x28($s2)
/* 850B8 800EBC08 8E020000 */  lw        $v0, ($s0)
/* 850BC 800EBC0C E6000038 */  swc1      $f0, 0x38($s0)
/* 850C0 800EBC10 C640002C */  lwc1      $f0, 0x2c($s2)
/* 850C4 800EBC14 E600003C */  swc1      $f0, 0x3c($s0)
/* 850C8 800EBC18 C6400030 */  lwc1      $f0, 0x30($s2)
/* 850CC 800EBC1C 00431024 */  and       $v0, $v0, $v1
/* 850D0 800EBC20 AE00001C */  sw        $zero, 0x1c($s0)
/* 850D4 800EBC24 AE000014 */  sw        $zero, 0x14($s0)
/* 850D8 800EBC28 AE020000 */  sw        $v0, ($s0)
/* 850DC 800EBC2C E6000040 */  swc1      $f0, 0x40($s0)
.L800EBC30:
/* 850E0 800EBC30 0C03BD90 */  jal       func_800EF640
/* 850E4 800EBC34 0200202D */   daddu    $a0, $s0, $zero
/* 850E8 800EBC38 C6000038 */  lwc1      $f0, 0x38($s0)
/* 850EC 800EBC3C C602003C */  lwc1      $f2, 0x3c($s0)
/* 850F0 800EBC40 C6040040 */  lwc1      $f4, 0x40($s0)
/* 850F4 800EBC44 8FBF001C */  lw        $ra, 0x1c($sp)
/* 850F8 800EBC48 8FB20018 */  lw        $s2, 0x18($sp)
/* 850FC 800EBC4C 8FB10014 */  lw        $s1, 0x14($sp)
/* 85100 800EBC50 8FB00010 */  lw        $s0, 0x10($sp)
/* 85104 800EBC54 3C018010 */  lui       $at, 0x8010
/* 85108 800EBC58 E420833C */  swc1      $f0, -0x7cc4($at)
/* 8510C 800EBC5C 3C018010 */  lui       $at, 0x8010
/* 85110 800EBC60 E4228340 */  swc1      $f2, -0x7cc0($at)
/* 85114 800EBC64 3C018010 */  lui       $at, 0x8010
/* 85118 800EBC68 E4248344 */  swc1      $f4, -0x7cbc($at)
/* 8511C 800EBC6C 03E00008 */  jr        $ra
/* 85120 800EBC70 27BD0020 */   addiu    $sp, $sp, 0x20
