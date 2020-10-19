.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240834_BDD9E4
/* BDD9E4 80240834 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BDD9E8 80240838 AFB3003C */  sw        $s3, 0x3c($sp)
/* BDD9EC 8024083C 0080982D */  daddu     $s3, $a0, $zero
/* BDD9F0 80240840 AFBF0040 */  sw        $ra, 0x40($sp)
/* BDD9F4 80240844 AFB20038 */  sw        $s2, 0x38($sp)
/* BDD9F8 80240848 AFB10034 */  sw        $s1, 0x34($sp)
/* BDD9FC 8024084C AFB00030 */  sw        $s0, 0x30($sp)
/* BDDA00 80240850 8E720148 */  lw        $s2, 0x148($s3)
/* BDDA04 80240854 0C00EABB */  jal       get_npc_unsafe
/* BDDA08 80240858 86440008 */   lh       $a0, 8($s2)
/* BDDA0C 8024085C 0040802D */  daddu     $s0, $v0, $zero
/* BDDA10 80240860 0200202D */  daddu     $a0, $s0, $zero
/* BDDA14 80240864 0C00F598 */  jal       func_8003D660
/* BDDA18 80240868 24050001 */   addiu    $a1, $zero, 1
/* BDDA1C 8024086C 8E050018 */  lw        $a1, 0x18($s0)
/* BDDA20 80240870 8E06000C */  lw        $a2, 0xc($s0)
/* BDDA24 80240874 0C00EA95 */  jal       npc_move_heading
/* BDDA28 80240878 0200202D */   daddu    $a0, $s0, $zero
/* BDDA2C 8024087C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BDDA30 80240880 C6000040 */  lwc1      $f0, 0x40($s0)
/* BDDA34 80240884 C462001C */  lwc1      $f2, 0x1c($v1)
/* BDDA38 80240888 468010A0 */  cvt.s.w   $f2, $f2
/* BDDA3C 8024088C C4640024 */  lwc1      $f4, 0x24($v1)
/* BDDA40 80240890 46802120 */  cvt.s.w   $f4, $f4
/* BDDA44 80240894 E7A00010 */  swc1      $f0, 0x10($sp)
/* BDDA48 80240898 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDA4C 8024089C 44051000 */  mfc1      $a1, $f2
/* BDDA50 802408A0 C4400028 */  lwc1      $f0, 0x28($v0)
/* BDDA54 802408A4 46800020 */  cvt.s.w   $f0, $f0
/* BDDA58 802408A8 E7A00014 */  swc1      $f0, 0x14($sp)
/* BDDA5C 802408AC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDA60 802408B0 44062000 */  mfc1      $a2, $f4
/* BDDA64 802408B4 C440002C */  lwc1      $f0, 0x2c($v0)
/* BDDA68 802408B8 46800020 */  cvt.s.w   $f0, $f0
/* BDDA6C 802408BC E7A00018 */  swc1      $f0, 0x18($sp)
/* BDDA70 802408C0 8C640030 */  lw        $a0, 0x30($v1)
/* BDDA74 802408C4 0C0123F5 */  jal       is_point_within_region
/* BDDA78 802408C8 8E070038 */   lw       $a3, 0x38($s0)
/* BDDA7C 802408CC C6000038 */  lwc1      $f0, 0x38($s0)
/* BDDA80 802408D0 C602003C */  lwc1      $f2, 0x3c($s0)
/* BDDA84 802408D4 C6040040 */  lwc1      $f4, 0x40($s0)
/* BDDA88 802408D8 3C013F80 */  lui       $at, 0x3f80
/* BDDA8C 802408DC 44813000 */  mtc1      $at, $f6
/* BDDA90 802408E0 E7A00020 */  swc1      $f0, 0x20($sp)
/* BDDA94 802408E4 E7A20024 */  swc1      $f2, 0x24($sp)
/* BDDA98 802408E8 E7A40028 */  swc1      $f4, 0x28($sp)
/* BDDA9C 802408EC E7A60010 */  swc1      $f6, 0x10($sp)
/* BDDAA0 802408F0 C600000C */  lwc1      $f0, 0xc($s0)
/* BDDAA4 802408F4 0002882B */  sltu      $s1, $zero, $v0
/* BDDAA8 802408F8 E7A00014 */  swc1      $f0, 0x14($sp)
/* BDDAAC 802408FC 860200A8 */  lh        $v0, 0xa8($s0)
/* BDDAB0 80240900 27A50020 */  addiu     $a1, $sp, 0x20
/* BDDAB4 80240904 44820000 */  mtc1      $v0, $f0
/* BDDAB8 80240908 00000000 */  nop       
/* BDDABC 8024090C 46800020 */  cvt.s.w   $f0, $f0
/* BDDAC0 80240910 E7A00018 */  swc1      $f0, 0x18($sp)
/* BDDAC4 80240914 860200A6 */  lh        $v0, 0xa6($s0)
/* BDDAC8 80240918 27A60024 */  addiu     $a2, $sp, 0x24
/* BDDACC 8024091C 44820000 */  mtc1      $v0, $f0
/* BDDAD0 80240920 00000000 */  nop       
/* BDDAD4 80240924 46800020 */  cvt.s.w   $f0, $f0
/* BDDAD8 80240928 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BDDADC 8024092C 8E040080 */  lw        $a0, 0x80($s0)
/* BDDAE0 80240930 0C037711 */  jal       func_800DDC44
/* BDDAE4 80240934 27A70028 */   addiu    $a3, $sp, 0x28
/* BDDAE8 80240938 54400001 */  bnel      $v0, $zero, .L80240940
/* BDDAEC 8024093C 24110001 */   addiu    $s1, $zero, 1
.L80240940:
/* BDDAF0 80240940 9602008E */  lhu       $v0, 0x8e($s0)
/* BDDAF4 80240944 2442FFFF */  addiu     $v0, $v0, -1
/* BDDAF8 80240948 A602008E */  sh        $v0, 0x8e($s0)
/* BDDAFC 8024094C 00021400 */  sll       $v0, $v0, 0x10
/* BDDB00 80240950 58400001 */  blezl     $v0, .L80240958
/* BDDB04 80240954 24110001 */   addiu    $s1, $zero, 1
.L80240958:
/* BDDB08 80240958 12200003 */  beqz      $s1, .L80240968
/* BDDB0C 8024095C 24020004 */   addiu    $v0, $zero, 4
/* BDDB10 80240960 AE620070 */  sw        $v0, 0x70($s3)
/* BDDB14 80240964 A2400007 */  sb        $zero, 7($s2)
.L80240968:
/* BDDB18 80240968 8FBF0040 */  lw        $ra, 0x40($sp)
/* BDDB1C 8024096C 8FB3003C */  lw        $s3, 0x3c($sp)
/* BDDB20 80240970 8FB20038 */  lw        $s2, 0x38($sp)
/* BDDB24 80240974 8FB10034 */  lw        $s1, 0x34($sp)
/* BDDB28 80240978 8FB00030 */  lw        $s0, 0x30($sp)
/* BDDB2C 8024097C 03E00008 */  jr        $ra
/* BDDB30 80240980 27BD0048 */   addiu    $sp, $sp, 0x48
