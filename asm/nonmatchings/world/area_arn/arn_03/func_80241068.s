.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241068
/* BDFDF8 80241068 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BDFDFC 8024106C AFB10014 */  sw        $s1, 0x14($sp)
/* BDFE00 80241070 0080882D */  daddu     $s1, $a0, $zero
/* BDFE04 80241074 AFBF0020 */  sw        $ra, 0x20($sp)
/* BDFE08 80241078 AFB3001C */  sw        $s3, 0x1c($sp)
/* BDFE0C 8024107C AFB20018 */  sw        $s2, 0x18($sp)
/* BDFE10 80241080 AFB00010 */  sw        $s0, 0x10($sp)
/* BDFE14 80241084 8E320148 */  lw        $s2, 0x148($s1)
/* BDFE18 80241088 86440008 */  lh        $a0, 8($s2)
/* BDFE1C 8024108C 0C00EABB */  jal       get_npc_unsafe
/* BDFE20 80241090 00A0982D */   daddu    $s3, $a1, $zero
/* BDFE24 80241094 0040802D */  daddu     $s0, $v0, $zero
/* BDFE28 80241098 9602008E */  lhu       $v0, 0x8e($s0)
/* BDFE2C 8024109C 2442FFFF */  addiu     $v0, $v0, -1
/* BDFE30 802410A0 A602008E */  sh        $v0, 0x8e($s0)
/* BDFE34 802410A4 00021400 */  sll       $v0, $v0, 0x10
/* BDFE38 802410A8 0441001D */  bgez      $v0, .L80241120
/* BDFE3C 802410AC 00000000 */   nop      
/* BDFE40 802410B0 8E220074 */  lw        $v0, 0x74($s1)
/* BDFE44 802410B4 2442FFFF */  addiu     $v0, $v0, -1
/* BDFE48 802410B8 04400014 */  bltz      $v0, .L8024110C
/* BDFE4C 802410BC AE220074 */   sw       $v0, 0x74($s1)
/* BDFE50 802410C0 C600000C */  lwc1      $f0, 0xc($s0)
/* BDFE54 802410C4 3C014334 */  lui       $at, 0x4334
/* BDFE58 802410C8 44816000 */  mtc1      $at, $f12
/* BDFE5C 802410CC 0C00A6C9 */  jal       clamp_angle
/* BDFE60 802410D0 460C0300 */   add.s    $f12, $f0, $f12
/* BDFE64 802410D4 E600000C */  swc1      $f0, 0xc($s0)
/* BDFE68 802410D8 8E640008 */  lw        $a0, 8($s3)
/* BDFE6C 802410DC 000417C2 */  srl       $v0, $a0, 0x1f
/* BDFE70 802410E0 00822021 */  addu      $a0, $a0, $v0
/* BDFE74 802410E4 00042043 */  sra       $a0, $a0, 1
/* BDFE78 802410E8 0C00A67F */  jal       rand_int
/* BDFE7C 802410EC 24840001 */   addiu    $a0, $a0, 1
/* BDFE80 802410F0 8E630008 */  lw        $v1, 8($s3)
/* BDFE84 802410F4 000327C2 */  srl       $a0, $v1, 0x1f
/* BDFE88 802410F8 00641821 */  addu      $v1, $v1, $a0
/* BDFE8C 802410FC 00031843 */  sra       $v1, $v1, 1
/* BDFE90 80241100 00621821 */  addu      $v1, $v1, $v0
/* BDFE94 80241104 08090448 */  j         .L80241120
/* BDFE98 80241108 A603008E */   sh       $v1, 0x8e($s0)
.L8024110C:
/* BDFE9C 8024110C 24020004 */  addiu     $v0, $zero, 4
/* BDFEA0 80241110 AE220070 */  sw        $v0, 0x70($s1)
/* BDFEA4 80241114 8E4200CC */  lw        $v0, 0xcc($s2)
/* BDFEA8 80241118 8C420000 */  lw        $v0, ($v0)
/* BDFEAC 8024111C AE020028 */  sw        $v0, 0x28($s0)
.L80241120:
/* BDFEB0 80241120 8FBF0020 */  lw        $ra, 0x20($sp)
/* BDFEB4 80241124 8FB3001C */  lw        $s3, 0x1c($sp)
/* BDFEB8 80241128 8FB20018 */  lw        $s2, 0x18($sp)
/* BDFEBC 8024112C 8FB10014 */  lw        $s1, 0x14($sp)
/* BDFEC0 80241130 8FB00010 */  lw        $s0, 0x10($sp)
/* BDFEC4 80241134 03E00008 */  jr        $ra
/* BDFEC8 80241138 27BD0028 */   addiu    $sp, $sp, 0x28
