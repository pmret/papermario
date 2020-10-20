.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241068_BE8C48
/* BE8C48 80241068 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BE8C4C 8024106C AFB10014 */  sw        $s1, 0x14($sp)
/* BE8C50 80241070 0080882D */  daddu     $s1, $a0, $zero
/* BE8C54 80241074 AFBF0020 */  sw        $ra, 0x20($sp)
/* BE8C58 80241078 AFB3001C */  sw        $s3, 0x1c($sp)
/* BE8C5C 8024107C AFB20018 */  sw        $s2, 0x18($sp)
/* BE8C60 80241080 AFB00010 */  sw        $s0, 0x10($sp)
/* BE8C64 80241084 8E320148 */  lw        $s2, 0x148($s1)
/* BE8C68 80241088 86440008 */  lh        $a0, 8($s2)
/* BE8C6C 8024108C 0C00EABB */  jal       get_npc_unsafe
/* BE8C70 80241090 00A0982D */   daddu    $s3, $a1, $zero
/* BE8C74 80241094 0040802D */  daddu     $s0, $v0, $zero
/* BE8C78 80241098 9602008E */  lhu       $v0, 0x8e($s0)
/* BE8C7C 8024109C 2442FFFF */  addiu     $v0, $v0, -1
/* BE8C80 802410A0 A602008E */  sh        $v0, 0x8e($s0)
/* BE8C84 802410A4 00021400 */  sll       $v0, $v0, 0x10
/* BE8C88 802410A8 0441001D */  bgez      $v0, .L80241120
/* BE8C8C 802410AC 00000000 */   nop      
/* BE8C90 802410B0 8E220074 */  lw        $v0, 0x74($s1)
/* BE8C94 802410B4 2442FFFF */  addiu     $v0, $v0, -1
/* BE8C98 802410B8 04400014 */  bltz      $v0, .L8024110C
/* BE8C9C 802410BC AE220074 */   sw       $v0, 0x74($s1)
/* BE8CA0 802410C0 C600000C */  lwc1      $f0, 0xc($s0)
/* BE8CA4 802410C4 3C014334 */  lui       $at, 0x4334
/* BE8CA8 802410C8 44816000 */  mtc1      $at, $f12
/* BE8CAC 802410CC 0C00A6C9 */  jal       clamp_angle
/* BE8CB0 802410D0 460C0300 */   add.s    $f12, $f0, $f12
/* BE8CB4 802410D4 E600000C */  swc1      $f0, 0xc($s0)
/* BE8CB8 802410D8 8E640008 */  lw        $a0, 8($s3)
/* BE8CBC 802410DC 000417C2 */  srl       $v0, $a0, 0x1f
/* BE8CC0 802410E0 00822021 */  addu      $a0, $a0, $v0
/* BE8CC4 802410E4 00042043 */  sra       $a0, $a0, 1
/* BE8CC8 802410E8 0C00A67F */  jal       rand_int
/* BE8CCC 802410EC 24840001 */   addiu    $a0, $a0, 1
/* BE8CD0 802410F0 8E630008 */  lw        $v1, 8($s3)
/* BE8CD4 802410F4 000327C2 */  srl       $a0, $v1, 0x1f
/* BE8CD8 802410F8 00641821 */  addu      $v1, $v1, $a0
/* BE8CDC 802410FC 00031843 */  sra       $v1, $v1, 1
/* BE8CE0 80241100 00621821 */  addu      $v1, $v1, $v0
/* BE8CE4 80241104 08090448 */  j         .L80241120
/* BE8CE8 80241108 A603008E */   sh       $v1, 0x8e($s0)
.L8024110C:
/* BE8CEC 8024110C 24020004 */  addiu     $v0, $zero, 4
/* BE8CF0 80241110 AE220070 */  sw        $v0, 0x70($s1)
/* BE8CF4 80241114 8E4200CC */  lw        $v0, 0xcc($s2)
/* BE8CF8 80241118 8C420000 */  lw        $v0, ($v0)
/* BE8CFC 8024111C AE020028 */  sw        $v0, 0x28($s0)
.L80241120:
/* BE8D00 80241120 8FBF0020 */  lw        $ra, 0x20($sp)
/* BE8D04 80241124 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE8D08 80241128 8FB20018 */  lw        $s2, 0x18($sp)
/* BE8D0C 8024112C 8FB10014 */  lw        $s1, 0x14($sp)
/* BE8D10 80241130 8FB00010 */  lw        $s0, 0x10($sp)
/* BE8D14 80241134 03E00008 */  jr        $ra
/* BE8D18 80241138 27BD0028 */   addiu    $sp, $sp, 0x28
