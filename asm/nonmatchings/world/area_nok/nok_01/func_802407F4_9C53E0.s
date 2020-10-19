.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F4_9C5BD4
/* 9C5BD4 802407F4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9C5BD8 802407F8 AFB40040 */  sw        $s4, 0x40($sp)
/* 9C5BDC 802407FC 0080A02D */  daddu     $s4, $a0, $zero
/* 9C5BE0 80240800 AFBF0048 */  sw        $ra, 0x48($sp)
/* 9C5BE4 80240804 AFB50044 */  sw        $s5, 0x44($sp)
/* 9C5BE8 80240808 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9C5BEC 8024080C AFB20038 */  sw        $s2, 0x38($sp)
/* 9C5BF0 80240810 AFB10034 */  sw        $s1, 0x34($sp)
/* 9C5BF4 80240814 AFB00030 */  sw        $s0, 0x30($sp)
/* 9C5BF8 80240818 8E920148 */  lw        $s2, 0x148($s4)
/* 9C5BFC 8024081C 86440008 */  lh        $a0, 8($s2)
/* 9C5C00 80240820 8E90000C */  lw        $s0, 0xc($s4)
/* 9C5C04 80240824 0C00EABB */  jal       get_npc_unsafe
/* 9C5C08 80240828 00A0882D */   daddu    $s1, $a1, $zero
/* 9C5C0C 8024082C 0280202D */  daddu     $a0, $s4, $zero
/* 9C5C10 80240830 8E050000 */  lw        $a1, ($s0)
/* 9C5C14 80240834 0C0B1EAF */  jal       get_variable
/* 9C5C18 80240838 0040802D */   daddu    $s0, $v0, $zero
/* 9C5C1C 8024083C AFA00010 */  sw        $zero, 0x10($sp)
/* 9C5C20 80240840 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9C5C24 80240844 8C630030 */  lw        $v1, 0x30($v1)
/* 9C5C28 80240848 AFA30014 */  sw        $v1, 0x14($sp)
/* 9C5C2C 8024084C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9C5C30 80240850 8C63001C */  lw        $v1, 0x1c($v1)
/* 9C5C34 80240854 AFA30018 */  sw        $v1, 0x18($sp)
/* 9C5C38 80240858 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9C5C3C 8024085C 8C630024 */  lw        $v1, 0x24($v1)
/* 9C5C40 80240860 AFA3001C */  sw        $v1, 0x1c($sp)
/* 9C5C44 80240864 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9C5C48 80240868 8C630028 */  lw        $v1, 0x28($v1)
/* 9C5C4C 8024086C 27B50010 */  addiu     $s5, $sp, 0x10
/* 9C5C50 80240870 AFA30020 */  sw        $v1, 0x20($sp)
/* 9C5C54 80240874 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9C5C58 80240878 3C014282 */  lui       $at, 0x4282
/* 9C5C5C 8024087C 44810000 */  mtc1      $at, $f0
/* 9C5C60 80240880 8C63002C */  lw        $v1, 0x2c($v1)
/* 9C5C64 80240884 0040982D */  daddu     $s3, $v0, $zero
/* 9C5C68 80240888 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9C5C6C 8024088C A7A0002C */  sh        $zero, 0x2c($sp)
/* 9C5C70 80240890 16200005 */  bnez      $s1, .L802408A8
/* 9C5C74 80240894 AFA30024 */   sw       $v1, 0x24($sp)
/* 9C5C78 80240898 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 9C5C7C 8024089C 30420004 */  andi      $v0, $v0, 4
/* 9C5C80 802408A0 1040002F */  beqz      $v0, .L80240960
/* 9C5C84 802408A4 00000000 */   nop      
.L802408A8:
/* 9C5C88 802408A8 AE800070 */  sw        $zero, 0x70($s4)
/* 9C5C8C 802408AC C600000C */  lwc1      $f0, 0xc($s0)
/* 9C5C90 802408B0 A600008E */  sh        $zero, 0x8e($s0)
/* 9C5C94 802408B4 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9C5C98 802408B8 4600008D */  trunc.w.s $f2, $f0
/* 9C5C9C 802408BC E642006C */  swc1      $f2, 0x6c($s2)
/* 9C5CA0 802408C0 8C420000 */  lw        $v0, ($v0)
/* 9C5CA4 802408C4 8E030000 */  lw        $v1, ($s0)
/* 9C5CA8 802408C8 AE020028 */  sw        $v0, 0x28($s0)
/* 9C5CAC 802408CC 2402F7FF */  addiu     $v0, $zero, -0x801
/* 9C5CB0 802408D0 00621824 */  and       $v1, $v1, $v0
/* 9C5CB4 802408D4 AE030000 */  sw        $v1, ($s0)
/* 9C5CB8 802408D8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9C5CBC 802408DC 8C420034 */  lw        $v0, 0x34($v0)
/* 9C5CC0 802408E0 54400005 */  bnel      $v0, $zero, .L802408F8
/* 9C5CC4 802408E4 2402FDFF */   addiu    $v0, $zero, -0x201
/* 9C5CC8 802408E8 34620200 */  ori       $v0, $v1, 0x200
/* 9C5CCC 802408EC 2403FFF7 */  addiu     $v1, $zero, -9
/* 9C5CD0 802408F0 08090240 */  j         .L80240900
/* 9C5CD4 802408F4 00431024 */   and      $v0, $v0, $v1
.L802408F8:
/* 9C5CD8 802408F8 00621024 */  and       $v0, $v1, $v0
/* 9C5CDC 802408FC 34420008 */  ori       $v0, $v0, 8
.L80240900:
/* 9C5CE0 80240900 AE020000 */  sw        $v0, ($s0)
/* 9C5CE4 80240904 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 9C5CE8 80240908 30420004 */  andi      $v0, $v0, 4
/* 9C5CEC 8024090C 10400009 */  beqz      $v0, .L80240934
/* 9C5CF0 80240910 24020063 */   addiu    $v0, $zero, 0x63
/* 9C5CF4 80240914 AE820070 */  sw        $v0, 0x70($s4)
/* 9C5CF8 80240918 2402000F */  addiu     $v0, $zero, 0xf
/* 9C5CFC 8024091C AE820074 */  sw        $v0, 0x74($s4)
/* 9C5D00 80240920 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 9C5D04 80240924 2403FFFB */  addiu     $v1, $zero, -5
/* 9C5D08 80240928 00431024 */  and       $v0, $v0, $v1
/* 9C5D0C 8024092C 08090258 */  j         .L80240960
/* 9C5D10 80240930 AE4200B0 */   sw       $v0, 0xb0($s2)
.L80240934:
/* 9C5D14 80240934 8E420000 */  lw        $v0, ($s2)
/* 9C5D18 80240938 3C034000 */  lui       $v1, 0x4000
/* 9C5D1C 8024093C 00431024 */  and       $v0, $v0, $v1
/* 9C5D20 80240940 10400007 */  beqz      $v0, .L80240960
/* 9C5D24 80240944 3C03BFFF */   lui      $v1, 0xbfff
/* 9C5D28 80240948 2402000C */  addiu     $v0, $zero, 0xc
/* 9C5D2C 8024094C AE820070 */  sw        $v0, 0x70($s4)
/* 9C5D30 80240950 8E420000 */  lw        $v0, ($s2)
/* 9C5D34 80240954 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9C5D38 80240958 00431024 */  and       $v0, $v0, $v1
/* 9C5D3C 8024095C AE420000 */  sw        $v0, ($s2)
.L80240960:
/* 9C5D40 80240960 8E830070 */  lw        $v1, 0x70($s4)
/* 9C5D44 80240964 2C620064 */  sltiu     $v0, $v1, 0x64
/* 9C5D48 80240968 10400036 */  beqz      $v0, .L80240A44
/* 9C5D4C 8024096C 00031080 */   sll      $v0, $v1, 2
/* 9C5D50 80240970 3C018025 */  lui       $at, 0x8025
/* 9C5D54 80240974 00220821 */  addu      $at, $at, $v0
/* 9C5D58 80240978 8C221AA8 */  lw        $v0, 0x1aa8($at)
/* 9C5D5C 8024097C 00400008 */  jr        $v0
/* 9C5D60 80240980 00000000 */   nop      
/* 9C5D64 80240984 0280202D */  daddu     $a0, $s4, $zero
/* 9C5D68 80240988 0260282D */  daddu     $a1, $s3, $zero
/* 9C5D6C 8024098C 0C090000 */  jal       func_80240000
/* 9C5D70 80240990 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5D74 80240994 0280202D */  daddu     $a0, $s4, $zero
/* 9C5D78 80240998 0260282D */  daddu     $a1, $s3, $zero
/* 9C5D7C 8024099C 0C09002D */  jal       func_802400B4
/* 9C5D80 802409A0 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5D84 802409A4 08090291 */  j         .L80240A44
/* 9C5D88 802409A8 00000000 */   nop      
/* 9C5D8C 802409AC 0280202D */  daddu     $a0, $s4, $zero
/* 9C5D90 802409B0 0260282D */  daddu     $a1, $s3, $zero
/* 9C5D94 802409B4 0C090075 */  jal       func_802401D4
/* 9C5D98 802409B8 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5D9C 802409BC 0280202D */  daddu     $a0, $s4, $zero
/* 9C5DA0 802409C0 0260282D */  daddu     $a1, $s3, $zero
/* 9C5DA4 802409C4 0C09008D */  jal       func_80240234
/* 9C5DA8 802409C8 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5DAC 802409CC 08090291 */  j         .L80240A44
/* 9C5DB0 802409D0 00000000 */   nop      
/* 9C5DB4 802409D4 0280202D */  daddu     $a0, $s4, $zero
/* 9C5DB8 802409D8 0260282D */  daddu     $a1, $s3, $zero
/* 9C5DBC 802409DC 0C0900AB */  jal       func_802402AC
/* 9C5DC0 802409E0 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5DC4 802409E4 0280202D */  daddu     $a0, $s4, $zero
/* 9C5DC8 802409E8 0260282D */  daddu     $a1, $s3, $zero
/* 9C5DCC 802409EC 0C0900F7 */  jal       func_802403DC
/* 9C5DD0 802409F0 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5DD4 802409F4 08090291 */  j         .L80240A44
/* 9C5DD8 802409F8 00000000 */   nop      
/* 9C5DDC 802409FC 0280202D */  daddu     $a0, $s4, $zero
/* 9C5DE0 80240A00 0260282D */  daddu     $a1, $s3, $zero
/* 9C5DE4 80240A04 0C09013E */  jal       func_802404F8
/* 9C5DE8 80240A08 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5DEC 80240A0C 08090291 */  j         .L80240A44
/* 9C5DF0 80240A10 00000000 */   nop      
/* 9C5DF4 80240A14 0280202D */  daddu     $a0, $s4, $zero
/* 9C5DF8 80240A18 0260282D */  daddu     $a1, $s3, $zero
/* 9C5DFC 80240A1C 0C090150 */  jal       func_80240540
/* 9C5E00 80240A20 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5E04 80240A24 0280202D */  daddu     $a0, $s4, $zero
/* 9C5E08 80240A28 0260282D */  daddu     $a1, $s3, $zero
/* 9C5E0C 80240A2C 0C09017B */  jal       func_802405EC
/* 9C5E10 80240A30 02A0302D */   daddu    $a2, $s5, $zero
/* 9C5E14 80240A34 08090291 */  j         .L80240A44
/* 9C5E18 80240A38 00000000 */   nop      
/* 9C5E1C 80240A3C 0C0129CF */  jal       func_8004A73C
/* 9C5E20 80240A40 0280202D */   daddu    $a0, $s4, $zero
.L80240A44:
/* 9C5E24 80240A44 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9C5E28 80240A48 8FB50044 */  lw        $s5, 0x44($sp)
/* 9C5E2C 80240A4C 8FB40040 */  lw        $s4, 0x40($sp)
/* 9C5E30 80240A50 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9C5E34 80240A54 8FB20038 */  lw        $s2, 0x38($sp)
/* 9C5E38 80240A58 8FB10034 */  lw        $s1, 0x34($sp)
/* 9C5E3C 80240A5C 8FB00030 */  lw        $s0, 0x30($sp)
/* 9C5E40 80240A60 0000102D */  daddu     $v0, $zero, $zero
/* 9C5E44 80240A64 03E00008 */  jr        $ra
/* 9C5E48 80240A68 27BD0050 */   addiu    $sp, $sp, 0x50
