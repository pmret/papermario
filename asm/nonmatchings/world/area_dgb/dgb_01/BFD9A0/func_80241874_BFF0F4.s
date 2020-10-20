.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241874_BFF0F4
/* BFF0F4 80241874 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BFF0F8 80241878 AFB30024 */  sw        $s3, 0x24($sp)
/* BFF0FC 8024187C 0080982D */  daddu     $s3, $a0, $zero
/* BFF100 80241880 AFBF0028 */  sw        $ra, 0x28($sp)
/* BFF104 80241884 AFB20020 */  sw        $s2, 0x20($sp)
/* BFF108 80241888 AFB1001C */  sw        $s1, 0x1c($sp)
/* BFF10C 8024188C AFB00018 */  sw        $s0, 0x18($sp)
/* BFF110 80241890 8E720148 */  lw        $s2, 0x148($s3)
/* BFF114 80241894 86440008 */  lh        $a0, 8($s2)
/* BFF118 80241898 0C00EABB */  jal       get_npc_unsafe
/* BFF11C 8024189C 0000802D */   daddu    $s0, $zero, $zero
/* BFF120 802418A0 0040882D */  daddu     $s1, $v0, $zero
.L802418A4:
/* BFF124 802418A4 822200A4 */  lb        $v0, 0xa4($s1)
/* BFF128 802418A8 52020007 */  beql      $s0, $v0, .L802418C8
/* BFF12C 802418AC 26100001 */   addiu    $s0, $s0, 1
/* BFF130 802418B0 0C00FB3A */  jal       get_enemy
/* BFF134 802418B4 0200202D */   daddu    $a0, $s0, $zero
/* BFF138 802418B8 8C42006C */  lw        $v0, 0x6c($v0)
/* BFF13C 802418BC 30420100 */  andi      $v0, $v0, 0x100
/* BFF140 802418C0 1440001D */  bnez      $v0, .L80241938
/* BFF144 802418C4 26100001 */   addiu    $s0, $s0, 1
.L802418C8:
/* BFF148 802418C8 2A020004 */  slti      $v0, $s0, 4
/* BFF14C 802418CC 1440FFF5 */  bnez      $v0, .L802418A4
/* BFF150 802418D0 00000000 */   nop      
/* BFF154 802418D4 8E42006C */  lw        $v0, 0x6c($s2)
/* BFF158 802418D8 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* BFF15C 802418DC 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* BFF160 802418E0 34420100 */  ori       $v0, $v0, 0x100
/* BFF164 802418E4 AE42006C */  sw        $v0, 0x6c($s2)
/* BFF168 802418E8 C4600028 */  lwc1      $f0, 0x28($v1)
/* BFF16C 802418EC E6200038 */  swc1      $f0, 0x38($s1)
/* BFF170 802418F0 C4600030 */  lwc1      $f0, 0x30($v1)
/* BFF174 802418F4 E6200040 */  swc1      $f0, 0x40($s1)
/* BFF178 802418F8 8E43006C */  lw        $v1, 0x6c($s2)
/* BFF17C 802418FC 30621000 */  andi      $v0, $v1, 0x1000
/* BFF180 80241900 14400003 */  bnez      $v0, .L80241910
/* BFF184 80241904 3C048000 */   lui      $a0, 0x8000
/* BFF188 80241908 34621000 */  ori       $v0, $v1, 0x1000
/* BFF18C 8024190C AE42006C */  sw        $v0, 0x6c($s2)
.L80241910:
/* BFF190 80241910 C6200040 */  lwc1      $f0, 0x40($s1)
/* BFF194 80241914 34840011 */  ori       $a0, $a0, 0x11
/* BFF198 80241918 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFF19C 8024191C 8E260038 */  lw        $a2, 0x38($s1)
/* BFF1A0 80241920 8E27003C */  lw        $a3, 0x3c($s1)
/* BFF1A4 80241924 0C052757 */  jal       play_sound_at_position
/* BFF1A8 80241928 24050002 */   addiu    $a1, $zero, 2
/* BFF1AC 8024192C 2402000F */  addiu     $v0, $zero, 0xf
/* BFF1B0 80241930 A620008E */  sh        $zero, 0x8e($s1)
/* BFF1B4 80241934 AE620070 */  sw        $v0, 0x70($s3)
.L80241938:
/* BFF1B8 80241938 8FBF0028 */  lw        $ra, 0x28($sp)
/* BFF1BC 8024193C 8FB30024 */  lw        $s3, 0x24($sp)
/* BFF1C0 80241940 8FB20020 */  lw        $s2, 0x20($sp)
/* BFF1C4 80241944 8FB1001C */  lw        $s1, 0x1c($sp)
/* BFF1C8 80241948 8FB00018 */  lw        $s0, 0x18($sp)
/* BFF1CC 8024194C 03E00008 */  jr        $ra
/* BFF1D0 80241950 27BD0030 */   addiu    $sp, $sp, 0x30
