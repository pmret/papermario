.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9FA7F0
/* 9FA7F0 80240000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9FA7F4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FA7F8 80240008 0080882D */  daddu     $s1, $a0, $zero
/* 9FA7FC 8024000C AFBF002C */  sw        $ra, 0x2c($sp)
/* 9FA800 80240010 AFB60028 */  sw        $s6, 0x28($sp)
/* 9FA804 80240014 AFB50024 */  sw        $s5, 0x24($sp)
/* 9FA808 80240018 AFB40020 */  sw        $s4, 0x20($sp)
/* 9FA80C 8024001C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9FA810 80240020 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FA814 80240024 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FA818 80240028 8E30000C */  lw        $s0, 0xc($s1)
/* 9FA81C 8024002C 8E050000 */  lw        $a1, ($s0)
/* 9FA820 80240030 0C0B1EAF */  jal       get_variable
/* 9FA824 80240034 26100004 */   addiu    $s0, $s0, 4
/* 9FA828 80240038 8E050000 */  lw        $a1, ($s0)
/* 9FA82C 8024003C 26100004 */  addiu     $s0, $s0, 4
/* 9FA830 80240040 0220202D */  daddu     $a0, $s1, $zero
/* 9FA834 80240044 0C0B1EAF */  jal       get_variable
/* 9FA838 80240048 0040902D */   daddu    $s2, $v0, $zero
/* 9FA83C 8024004C 8E050000 */  lw        $a1, ($s0)
/* 9FA840 80240050 26100004 */  addiu     $s0, $s0, 4
/* 9FA844 80240054 0220202D */  daddu     $a0, $s1, $zero
/* 9FA848 80240058 0C0B1EAF */  jal       get_variable
/* 9FA84C 8024005C 0040B02D */   daddu    $s6, $v0, $zero
/* 9FA850 80240060 8E050000 */  lw        $a1, ($s0)
/* 9FA854 80240064 26100004 */  addiu     $s0, $s0, 4
/* 9FA858 80240068 0220202D */  daddu     $a0, $s1, $zero
/* 9FA85C 8024006C 0C0B1EAF */  jal       get_variable
/* 9FA860 80240070 0040A82D */   daddu    $s5, $v0, $zero
/* 9FA864 80240074 8E050000 */  lw        $a1, ($s0)
/* 9FA868 80240078 26100004 */  addiu     $s0, $s0, 4
/* 9FA86C 8024007C 0220202D */  daddu     $a0, $s1, $zero
/* 9FA870 80240080 0C0B1EAF */  jal       get_variable
/* 9FA874 80240084 0040A02D */   daddu    $s4, $v0, $zero
/* 9FA878 80240088 0220202D */  daddu     $a0, $s1, $zero
/* 9FA87C 8024008C 8E050000 */  lw        $a1, ($s0)
/* 9FA880 80240090 0C0B1EAF */  jal       get_variable
/* 9FA884 80240094 0040802D */   daddu    $s0, $v0, $zero
/* 9FA888 80240098 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* 9FA88C 8024009C 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* 9FA890 802400A0 44920000 */  mtc1      $s2, $f0
/* 9FA894 802400A4 00000000 */  nop       
/* 9FA898 802400A8 46800020 */  cvt.s.w   $f0, $f0
/* 9FA89C 802400AC C6620028 */  lwc1      $f2, 0x28($s3)
/* 9FA8A0 802400B0 3C11800B */  lui       $s1, %hi(gCurrentEncounter)
/* 9FA8A4 802400B4 26310F10 */  addiu     $s1, $s1, %lo(gCurrentEncounter)
/* 9FA8A8 802400B8 4602003E */  c.le.s    $f0, $f2
/* 9FA8AC 802400BC 00000000 */  nop       
/* 9FA8B0 802400C0 45000017 */  bc1f      .L80240120
/* 9FA8B4 802400C4 00000000 */   nop      
/* 9FA8B8 802400C8 44960000 */  mtc1      $s6, $f0
/* 9FA8BC 802400CC 00000000 */  nop       
/* 9FA8C0 802400D0 46800020 */  cvt.s.w   $f0, $f0
/* 9FA8C4 802400D4 4600103E */  c.le.s    $f2, $f0
/* 9FA8C8 802400D8 00000000 */  nop       
/* 9FA8CC 802400DC 45000010 */  bc1f      .L80240120
/* 9FA8D0 802400E0 00000000 */   nop      
/* 9FA8D4 802400E4 C6620030 */  lwc1      $f2, 0x30($s3)
/* 9FA8D8 802400E8 44950000 */  mtc1      $s5, $f0
/* 9FA8DC 802400EC 00000000 */  nop       
/* 9FA8E0 802400F0 46800020 */  cvt.s.w   $f0, $f0
/* 9FA8E4 802400F4 4602003E */  c.le.s    $f0, $f2
/* 9FA8E8 802400F8 00000000 */  nop       
/* 9FA8EC 802400FC 45000008 */  bc1f      .L80240120
/* 9FA8F0 80240100 00000000 */   nop      
/* 9FA8F4 80240104 44940000 */  mtc1      $s4, $f0
/* 9FA8F8 80240108 00000000 */  nop       
/* 9FA8FC 8024010C 46800020 */  cvt.s.w   $f0, $f0
/* 9FA900 80240110 4600103E */  c.le.s    $f2, $f0
/* 9FA904 80240114 00000000 */  nop       
/* 9FA908 80240118 45030001 */  bc1tl     .L80240120
/* 9FA90C 8024011C 0040802D */   daddu    $s0, $v0, $zero
.L80240120:
/* 9FA910 80240120 8222001C */  lb        $v0, 0x1c($s1)
/* 9FA914 80240124 18400009 */  blez      $v0, .L8024014C
/* 9FA918 80240128 0000182D */   daddu    $v1, $zero, $zero
/* 9FA91C 8024012C 0220202D */  daddu     $a0, $s1, $zero
.L80240130:
/* 9FA920 80240130 8C820028 */  lw        $v0, 0x28($a0)
/* 9FA924 80240134 A4500046 */  sh        $s0, 0x46($v0)
/* 9FA928 80240138 8222001C */  lb        $v0, 0x1c($s1)
/* 9FA92C 8024013C 24630001 */  addiu     $v1, $v1, 1
/* 9FA930 80240140 0062102A */  slt       $v0, $v1, $v0
/* 9FA934 80240144 1440FFFA */  bnez      $v0, .L80240130
/* 9FA938 80240148 24840004 */   addiu    $a0, $a0, 4
.L8024014C:
/* 9FA93C 8024014C 8FBF002C */  lw        $ra, 0x2c($sp)
/* 9FA940 80240150 8FB60028 */  lw        $s6, 0x28($sp)
/* 9FA944 80240154 8FB50024 */  lw        $s5, 0x24($sp)
/* 9FA948 80240158 8FB40020 */  lw        $s4, 0x20($sp)
/* 9FA94C 8024015C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9FA950 80240160 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FA954 80240164 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FA958 80240168 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FA95C 8024016C 24020002 */  addiu     $v0, $zero, 2
/* 9FA960 80240170 03E00008 */  jr        $ra
/* 9FA964 80240174 27BD0030 */   addiu    $sp, $sp, 0x30
/* 9FA968 80240178 00000000 */  nop       
/* 9FA96C 8024017C 00000000 */  nop       
