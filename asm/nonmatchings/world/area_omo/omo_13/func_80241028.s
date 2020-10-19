.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241028
/* DE34B8 80241028 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DE34BC 8024102C AFB20018 */  sw        $s2, 0x18($sp)
/* DE34C0 80241030 0080902D */  daddu     $s2, $a0, $zero
/* DE34C4 80241034 AFBF001C */  sw        $ra, 0x1c($sp)
/* DE34C8 80241038 AFB10014 */  sw        $s1, 0x14($sp)
/* DE34CC 8024103C AFB00010 */  sw        $s0, 0x10($sp)
/* DE34D0 80241040 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DE34D4 80241044 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DE34D8 80241048 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DE34DC 8024104C 0C00EAD2 */  jal       get_npc_safe
/* DE34E0 80241050 0000202D */   daddu    $a0, $zero, $zero
/* DE34E4 80241054 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* DE34E8 80241058 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* DE34EC 8024105C 0040802D */  daddu     $s0, $v0, $zero
/* DE34F0 80241060 8E260028 */  lw        $a2, 0x28($s1)
/* DE34F4 80241064 8E270030 */  lw        $a3, 0x30($s1)
/* DE34F8 80241068 3C0142DC */  lui       $at, 0x42dc
/* DE34FC 8024106C 4481A000 */  mtc1      $at, $f20
/* DE3500 80241070 3C01C234 */  lui       $at, 0xc234
/* DE3504 80241074 4481B000 */  mtc1      $at, $f22
/* DE3508 80241078 4600A306 */  mov.s     $f12, $f20
/* DE350C 8024107C 0C00A7B5 */  jal       dist2D
/* DE3510 80241080 4600B386 */   mov.s    $f14, $f22
/* DE3514 80241084 4600A306 */  mov.s     $f12, $f20
/* DE3518 80241088 8E260028 */  lw        $a2, 0x28($s1)
/* DE351C 8024108C 8E270030 */  lw        $a3, 0x30($s1)
/* DE3520 80241090 0C00A720 */  jal       atan2
/* DE3524 80241094 4600B386 */   mov.s    $f14, $f22
/* DE3528 80241098 0C00A6C9 */  jal       clamp_angle
/* DE352C 8024109C 46000306 */   mov.s    $f12, $f0
/* DE3530 802410A0 46000586 */  mov.s     $f22, $f0
/* DE3534 802410A4 0C00A8BB */  jal       sin_deg
/* DE3538 802410A8 4600B306 */   mov.s    $f12, $f22
/* DE353C 802410AC 3C0141F0 */  lui       $at, 0x41f0
/* DE3540 802410B0 44811000 */  mtc1      $at, $f2
/* DE3544 802410B4 00000000 */  nop       
/* DE3548 802410B8 46020002 */  mul.s     $f0, $f0, $f2
/* DE354C 802410BC 00000000 */  nop       
/* DE3550 802410C0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* DE3554 802410C4 10400009 */  beqz      $v0, .L802410EC
/* DE3558 802410C8 46140600 */   add.s    $f24, $f0, $f20
/* DE355C 802410CC C622002C */  lwc1      $f2, 0x2c($s1)
/* DE3560 802410D0 3C013F33 */  lui       $at, 0x3f33
/* DE3564 802410D4 34213333 */  ori       $at, $at, 0x3333
/* DE3568 802410D8 44810000 */  mtc1      $at, $f0
/* DE356C 802410DC 00000000 */  nop       
/* DE3570 802410E0 46001502 */  mul.s     $f20, $f2, $f0
/* DE3574 802410E4 0809043C */  j         .L802410F0
/* DE3578 802410E8 00000000 */   nop      
.L802410EC:
/* DE357C 802410EC C614003C */  lwc1      $f20, 0x3c($s0)
.L802410F0:
/* DE3580 802410F0 0C00A8D4 */  jal       cos_deg
/* DE3584 802410F4 4600B306 */   mov.s    $f12, $f22
/* DE3588 802410F8 3C0141F0 */  lui       $at, 0x41f0
/* DE358C 802410FC 44811000 */  mtc1      $at, $f2
/* DE3590 80241100 00000000 */  nop       
/* DE3594 80241104 46020002 */  mul.s     $f0, $f0, $f2
/* DE3598 80241108 00000000 */  nop       
/* DE359C 8024110C 3C01C234 */  lui       $at, 0xc234
/* DE35A0 80241110 44811000 */  mtc1      $at, $f2
/* DE35A4 80241114 8E4200B0 */  lw        $v0, 0xb0($s2)
/* DE35A8 80241118 10400008 */  beqz      $v0, .L8024113C
/* DE35AC 8024111C 46001101 */   sub.s    $f4, $f2, $f0
/* DE35B0 80241120 C602003C */  lwc1      $f2, 0x3c($s0)
/* DE35B4 80241124 44800000 */  mtc1      $zero, $f0
/* DE35B8 80241128 00000000 */  nop       
/* DE35BC 8024112C 46001032 */  c.eq.s    $f2, $f0
/* DE35C0 80241130 00000000 */  nop       
/* DE35C4 80241134 45030001 */  bc1tl     .L8024113C
/* DE35C8 80241138 AE4000B0 */   sw       $zero, 0xb0($s2)
.L8024113C:
/* DE35CC 8024113C C6000038 */  lwc1      $f0, 0x38($s0)
/* DE35D0 80241140 46180032 */  c.eq.s    $f0, $f24
/* DE35D4 80241144 00000000 */  nop       
/* DE35D8 80241148 4500000C */  bc1f      .L8024117C
/* DE35DC 8024114C 3C04003B */   lui      $a0, 0x3b
/* DE35E0 80241150 C600003C */  lwc1      $f0, 0x3c($s0)
/* DE35E4 80241154 46140032 */  c.eq.s    $f0, $f20
/* DE35E8 80241158 00000000 */  nop       
/* DE35EC 8024115C 45000007 */  bc1f      .L8024117C
/* DE35F0 80241160 00000000 */   nop      
/* DE35F4 80241164 C6000040 */  lwc1      $f0, 0x40($s0)
/* DE35F8 80241168 46040032 */  c.eq.s    $f0, $f4
/* DE35FC 8024116C 00000000 */  nop       
/* DE3600 80241170 4501001A */  bc1t      .L802411DC
/* DE3604 80241174 3C03003B */   lui      $v1, 0x3b
/* DE3608 80241178 3C04003B */  lui       $a0, 0x3b
.L8024117C:
/* DE360C 8024117C 8E020028 */  lw        $v0, 0x28($s0)
/* DE3610 80241180 34840502 */  ori       $a0, $a0, 0x502
/* DE3614 80241184 5044000A */  beql      $v0, $a0, .L802411B0
/* DE3618 80241188 E6180038 */   swc1     $f24, 0x38($s0)
/* DE361C 8024118C 8E4200AC */  lw        $v0, 0xac($s2)
/* DE3620 80241190 0040182D */  daddu     $v1, $v0, $zero
/* DE3624 80241194 24420001 */  addiu     $v0, $v0, 1
/* DE3628 80241198 28630006 */  slti      $v1, $v1, 6
/* DE362C 8024119C 14600003 */  bnez      $v1, .L802411AC
/* DE3630 802411A0 AE4200AC */   sw       $v0, 0xac($s2)
/* DE3634 802411A4 AE040028 */  sw        $a0, 0x28($s0)
/* DE3638 802411A8 AE4000AC */  sw        $zero, 0xac($s2)
.L802411AC:
/* DE363C 802411AC E6180038 */  swc1      $f24, 0x38($s0)
.L802411B0:
/* DE3640 802411B0 4600C006 */  mov.s     $f0, $f24
/* DE3644 802411B4 C602003C */  lwc1      $f2, 0x3c($s0)
/* DE3648 802411B8 8E020000 */  lw        $v0, ($s0)
/* DE364C 802411BC 3C030001 */  lui       $v1, 1
/* DE3650 802411C0 E6040040 */  swc1      $f4, 0x40($s0)
/* DE3654 802411C4 E600006C */  swc1      $f0, 0x6c($s0)
/* DE3658 802411C8 E6040074 */  swc1      $f4, 0x74($s0)
/* DE365C 802411CC 00431025 */  or        $v0, $v0, $v1
/* DE3660 802411D0 E6020070 */  swc1      $f2, 0x70($s0)
/* DE3664 802411D4 0809047B */  j         .L802411EC
/* DE3668 802411D8 AE020000 */   sw       $v0, ($s0)
.L802411DC:
/* DE366C 802411DC 8E020028 */  lw        $v0, 0x28($s0)
/* DE3670 802411E0 34630501 */  ori       $v1, $v1, 0x501
/* DE3674 802411E4 54430001 */  bnel      $v0, $v1, .L802411EC
/* DE3678 802411E8 AE030028 */   sw       $v1, 0x28($s0)
.L802411EC:
/* DE367C 802411EC C60C0038 */  lwc1      $f12, 0x38($s0)
/* DE3680 802411F0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DE3684 802411F4 8E260028 */  lw        $a2, 0x28($s1)
/* DE3688 802411F8 0C00A720 */  jal       atan2
/* DE368C 802411FC 8E270030 */   lw       $a3, 0x30($s1)
/* DE3690 80241200 E600000C */  swc1      $f0, 0xc($s0)
/* DE3694 80241204 8FBF001C */  lw        $ra, 0x1c($sp)
/* DE3698 80241208 8FB20018 */  lw        $s2, 0x18($sp)
/* DE369C 8024120C 8FB10014 */  lw        $s1, 0x14($sp)
/* DE36A0 80241210 8FB00010 */  lw        $s0, 0x10($sp)
/* DE36A4 80241214 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DE36A8 80241218 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DE36AC 8024121C D7B40020 */  ldc1      $f20, 0x20($sp)
/* DE36B0 80241220 24020002 */  addiu     $v0, $zero, 2
/* DE36B4 80241224 03E00008 */  jr        $ra
/* DE36B8 80241228 27BD0038 */   addiu    $sp, $sp, 0x38
/* DE36BC 8024122C 00000000 */  nop       
