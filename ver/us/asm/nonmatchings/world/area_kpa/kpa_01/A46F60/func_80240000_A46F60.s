.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A46F60
/* A46F60 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A46F64 80240004 AFB00018 */  sw        $s0, 0x18($sp)
/* A46F68 80240008 0080802D */  daddu     $s0, $a0, $zero
/* A46F6C 8024000C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* A46F70 80240010 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* A46F74 80240014 AFB1001C */  sw        $s1, 0x1c($sp)
/* A46F78 80240018 3C118011 */  lui       $s1, %hi(gPlayerData)
/* A46F7C 8024001C 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* A46F80 80240020 AFB20020 */  sw        $s2, 0x20($sp)
/* A46F84 80240024 0220902D */  daddu     $s2, $s1, $zero
/* A46F88 80240028 10A00004 */  beqz      $a1, .L8024003C
/* A46F8C 8024002C AFBF0024 */   sw       $ra, 0x24($sp)
/* A46F90 80240030 240200FF */  addiu     $v0, $zero, 0xff
/* A46F94 80240034 AE020070 */  sw        $v0, 0x70($s0)
/* A46F98 80240038 AE000074 */  sw        $zero, 0x74($s0)
.L8024003C:
/* A46F9C 8024003C 24040001 */  addiu     $a0, $zero, 1
/* A46FA0 80240040 C460002C */  lwc1      $f0, 0x2c($v1)
/* A46FA4 80240044 3C014100 */  lui       $at, 0x4100
/* A46FA8 80240048 44811000 */  mtc1      $at, $f2
/* A46FAC 8024004C 00000000 */  nop
/* A46FB0 80240050 46020000 */  add.s     $f0, $f0, $f2
/* A46FB4 80240054 C4620030 */  lwc1      $f2, 0x30($v1)
/* A46FB8 80240058 C4640028 */  lwc1      $f4, 0x28($v1)
/* A46FBC 8024005C 4600118D */  trunc.w.s $f6, $f2
/* A46FC0 80240060 E7A60010 */  swc1      $f6, 0x10($sp)
/* A46FC4 80240064 4600218D */  trunc.w.s $f6, $f4
/* A46FC8 80240068 44063000 */  mfc1      $a2, $f6
/* A46FCC 8024006C 4600018D */  trunc.w.s $f6, $f0
/* A46FD0 80240070 44073000 */  mfc1      $a3, $f6
/* A46FD4 80240074 0C04DFB0 */  jal       set_screen_overlay_center_worldpos
/* A46FD8 80240078 0080282D */   daddu    $a1, $a0, $zero
/* A46FDC 8024007C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* A46FE0 80240080 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* A46FE4 80240084 10400012 */  beqz      $v0, .L802400D0
/* A46FE8 80240088 24020006 */   addiu    $v0, $zero, 6
/* A46FEC 8024008C 82230012 */  lb        $v1, 0x12($s1)
/* A46FF0 80240090 14620022 */  bne       $v1, $v0, .L8024011C
/* A46FF4 80240094 00000000 */   nop
/* A46FF8 80240098 8E020074 */  lw        $v0, 0x74($s0)
/* A46FFC 8024009C 14400004 */  bnez      $v0, .L802400B0
/* A47000 802400A0 24020001 */   addiu    $v0, $zero, 1
/* A47004 802400A4 AE020074 */  sw        $v0, 0x74($s0)
/* A47008 802400A8 0C05272D */  jal       sfx_play_sound
/* A4700C 802400AC 24042011 */   addiu    $a0, $zero, 0x2011
.L802400B0:
/* A47010 802400B0 8E020070 */  lw        $v0, 0x70($s0)
/* A47014 802400B4 2442FFF8 */  addiu     $v0, $v0, -8
/* A47018 802400B8 AE020070 */  sw        $v0, 0x70($s0)
/* A4701C 802400BC 2842005A */  slti      $v0, $v0, 0x5a
/* A47020 802400C0 10400016 */  beqz      $v0, .L8024011C
/* A47024 802400C4 2402005A */   addiu    $v0, $zero, 0x5a
/* A47028 802400C8 08090047 */  j         .L8024011C
/* A4702C 802400CC AE020070 */   sw       $v0, 0x70($s0)
.L802400D0:
/* A47030 802400D0 82430012 */  lb        $v1, 0x12($s2)
/* A47034 802400D4 14620010 */  bne       $v1, $v0, .L80240118
/* A47038 802400D8 240200FF */   addiu    $v0, $zero, 0xff
/* A4703C 802400DC 8E020074 */  lw        $v0, 0x74($s0)
/* A47040 802400E0 10400007 */  beqz      $v0, .L80240100
/* A47044 802400E4 00000000 */   nop
/* A47048 802400E8 8E020070 */  lw        $v0, 0x70($s0)
/* A4704C 802400EC 284200FF */  slti      $v0, $v0, 0xff
/* A47050 802400F0 10400003 */  beqz      $v0, .L80240100
/* A47054 802400F4 AE000074 */   sw       $zero, 0x74($s0)
/* A47058 802400F8 0C05272D */  jal       sfx_play_sound
/* A4705C 802400FC 24042012 */   addiu    $a0, $zero, 0x2012
.L80240100:
/* A47060 80240100 8E020070 */  lw        $v0, 0x70($s0)
/* A47064 80240104 24420008 */  addiu     $v0, $v0, 8
/* A47068 80240108 AE020070 */  sw        $v0, 0x70($s0)
/* A4706C 8024010C 284200FF */  slti      $v0, $v0, 0xff
/* A47070 80240110 14400002 */  bnez      $v0, .L8024011C
/* A47074 80240114 240200FF */   addiu    $v0, $zero, 0xff
.L80240118:
/* A47078 80240118 AE020070 */  sw        $v0, 0x70($s0)
.L8024011C:
/* A4707C 8024011C C6060070 */  lwc1      $f6, 0x70($s0)
/* A47080 80240120 468031A0 */  cvt.s.w   $f6, $f6
/* A47084 80240124 44053000 */  mfc1      $a1, $f6
/* A47088 80240128 0C04E035 */  jal       set_screen_overlay_alpha
/* A4708C 8024012C 24040001 */   addiu    $a0, $zero, 1
/* A47090 80240130 3C05437F */  lui       $a1, 0x437f
/* A47094 80240134 0C04DF69 */  jal       set_screen_overlay_params_back
/* A47098 80240138 2404000B */   addiu    $a0, $zero, 0xb
/* A4709C 8024013C 8FBF0024 */  lw        $ra, 0x24($sp)
/* A470A0 80240140 8FB20020 */  lw        $s2, 0x20($sp)
/* A470A4 80240144 8FB1001C */  lw        $s1, 0x1c($sp)
/* A470A8 80240148 8FB00018 */  lw        $s0, 0x18($sp)
/* A470AC 8024014C 0000102D */  daddu     $v0, $zero, $zero
/* A470B0 80240150 03E00008 */  jr        $ra
/* A470B4 80240154 27BD0028 */   addiu    $sp, $sp, 0x28
/* A470B8 80240158 00000000 */  nop
/* A470BC 8024015C 00000000 */  nop
