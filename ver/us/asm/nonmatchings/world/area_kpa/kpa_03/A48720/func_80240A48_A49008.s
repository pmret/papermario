.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A48_A49008
/* A49008 80240A48 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A4900C 80240A4C AFB00018 */  sw        $s0, 0x18($sp)
/* A49010 80240A50 AFBF0024 */  sw        $ra, 0x24($sp)
/* A49014 80240A54 AFB20020 */  sw        $s2, 0x20($sp)
/* A49018 80240A58 AFB1001C */  sw        $s1, 0x1c($sp)
/* A4901C 80240A5C F7B60030 */  sdc1      $f22, 0x30($sp)
/* A49020 80240A60 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A49024 80240A64 8C920148 */  lw        $s2, 0x148($a0)
/* A49028 80240A68 4485A000 */  mtc1      $a1, $f20
/* A4902C 80240A6C 86440008 */  lh        $a0, 8($s2)
/* A49030 80240A70 4486B000 */  mtc1      $a2, $f22
/* A49034 80240A74 0C00EABB */  jal       get_npc_unsafe
/* A49038 80240A78 00E0802D */   daddu    $s0, $a3, $zero
/* A4903C 80240A7C 0200202D */  daddu     $a0, $s0, $zero
/* A49040 80240A80 0040882D */  daddu     $s1, $v0, $zero
/* A49044 80240A84 4406A000 */  mfc1      $a2, $f20
/* A49048 80240A88 4407B000 */  mfc1      $a3, $f22
/* A4904C 80240A8C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* A49050 80240A90 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* A49054 80240A94 3C05800B */  lui       $a1, %hi(gCameras)
/* A49058 80240A98 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A4905C 80240A9C AFA00010 */  sw        $zero, 0x10($sp)
/* A49060 80240AA0 00031080 */  sll       $v0, $v1, 2
/* A49064 80240AA4 00431021 */  addu      $v0, $v0, $v1
/* A49068 80240AA8 00021080 */  sll       $v0, $v0, 2
/* A4906C 80240AAC 00431023 */  subu      $v0, $v0, $v1
/* A49070 80240AB0 000218C0 */  sll       $v1, $v0, 3
/* A49074 80240AB4 00431021 */  addu      $v0, $v0, $v1
/* A49078 80240AB8 000210C0 */  sll       $v0, $v0, 3
/* A4907C 80240ABC 00458021 */  addu      $s0, $v0, $a1
/* A49080 80240AC0 0C01242D */  jal       func_800490B4
/* A49084 80240AC4 0240282D */   daddu    $a1, $s2, $zero
/* A49088 80240AC8 1040004B */  beqz      $v0, .L80240BF8
/* A4908C 80240ACC 2402FFFF */   addiu    $v0, $zero, -1
/* A49090 80240AD0 C60C006C */  lwc1      $f12, 0x6c($s0)
/* A49094 80240AD4 C62E000C */  lwc1      $f14, 0xc($s1)
/* A49098 80240AD8 3C014387 */  lui       $at, 0x4387
/* A4909C 80240ADC 4481A000 */  mtc1      $at, $f20
/* A490A0 80240AE0 0C00A70A */  jal       get_clamped_angle_diff
/* A490A4 80240AE4 00000000 */   nop
/* A490A8 80240AE8 0C00A6C9 */  jal       clamp_angle
/* A490AC 80240AEC 46000306 */   mov.s    $f12, $f0
/* A490B0 80240AF0 3C018024 */  lui       $at, %hi(D_802438E0_A4BEA0)
/* A490B4 80240AF4 D42238E0 */  ldc1      $f2, %lo(D_802438E0_A4BEA0)($at)
/* A490B8 80240AF8 46000021 */  cvt.d.s   $f0, $f0
/* A490BC 80240AFC 4622003C */  c.lt.d    $f0, $f2
/* A490C0 80240B00 00000000 */  nop
/* A490C4 80240B04 45000003 */  bc1f      .L80240B14
/* A490C8 80240B08 00000000 */   nop
/* A490CC 80240B0C 3C0142B4 */  lui       $at, 0x42b4
/* A490D0 80240B10 4481A000 */  mtc1      $at, $f20
.L80240B14:
/* A490D4 80240B14 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* A490D8 80240B18 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* A490DC 80240B1C C62C0038 */  lwc1      $f12, 0x38($s1)
/* A490E0 80240B20 8E020000 */  lw        $v0, ($s0)
/* A490E4 80240B24 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A490E8 80240B28 8C460028 */  lw        $a2, 0x28($v0)
/* A490EC 80240B2C 0C00A720 */  jal       atan2
/* A490F0 80240B30 8C470030 */   lw       $a3, 0x30($v0)
/* A490F4 80240B34 4600A306 */  mov.s     $f12, $f20
/* A490F8 80240B38 0C00A70A */  jal       get_clamped_angle_diff
/* A490FC 80240B3C 46000386 */   mov.s    $f14, $f0
/* A49100 80240B40 46000005 */  abs.s     $f0, $f0
/* A49104 80240B44 3C018024 */  lui       $at, %hi(D_802438E8_A4BEA8)
/* A49108 80240B48 D42238E8 */  ldc1      $f2, %lo(D_802438E8_A4BEA8)($at)
/* A4910C 80240B4C 46000021 */  cvt.d.s   $f0, $f0
/* A49110 80240B50 4620103C */  c.lt.d    $f2, $f0
/* A49114 80240B54 00000000 */  nop
/* A49118 80240B58 45010027 */  bc1t      .L80240BF8
/* A4911C 80240B5C 2402FFFF */   addiu    $v0, $zero, -1
/* A49120 80240B60 8E020000 */  lw        $v0, ($s0)
/* A49124 80240B64 C6200038 */  lwc1      $f0, 0x38($s1)
/* A49128 80240B68 C4420028 */  lwc1      $f2, 0x28($v0)
/* A4912C 80240B6C 44806000 */  mtc1      $zero, $f12
/* A49130 80240B70 46020001 */  sub.s     $f0, $f0, $f2
/* A49134 80240B74 C62E003C */  lwc1      $f14, 0x3c($s1)
/* A49138 80240B78 8C47002C */  lw        $a3, 0x2c($v0)
/* A4913C 80240B7C 46000005 */  abs.s     $f0, $f0
/* A49140 80240B80 44060000 */  mfc1      $a2, $f0
/* A49144 80240B84 0C00A720 */  jal       atan2
/* A49148 80240B88 00000000 */   nop
/* A4914C 80240B8C 3C018024 */  lui       $at, %hi(D_802438F0_A4BEB0)
/* A49150 80240B90 D42238F0 */  ldc1      $f2, %lo(D_802438F0_A4BEB0)($at)
/* A49154 80240B94 46000021 */  cvt.d.s   $f0, $f0
/* A49158 80240B98 46220001 */  sub.d     $f0, $f0, $f2
/* A4915C 80240B9C 3C018024 */  lui       $at, %hi(D_802438F8_A4BEB8)
/* A49160 80240BA0 D42238F8 */  ldc1      $f2, %lo(D_802438F8_A4BEB8)($at)
/* A49164 80240BA4 46200020 */  cvt.s.d   $f0, $f0
/* A49168 80240BA8 46000005 */  abs.s     $f0, $f0
/* A4916C 80240BAC 46000021 */  cvt.d.s   $f0, $f0
/* A49170 80240BB0 4620103C */  c.lt.d    $f2, $f0
/* A49174 80240BB4 00000000 */  nop
/* A49178 80240BB8 4501000F */  bc1t      .L80240BF8
/* A4917C 80240BBC 2402FFFF */   addiu    $v0, $zero, -1
/* A49180 80240BC0 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* A49184 80240BC4 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* A49188 80240BC8 24020009 */  addiu     $v0, $zero, 9
/* A4918C 80240BCC 10620009 */  beq       $v1, $v0, .L80240BF4
/* A49190 80240BD0 24020007 */   addiu    $v0, $zero, 7
/* A49194 80240BD4 50620008 */  beql      $v1, $v0, .L80240BF8
/* A49198 80240BD8 2402FFFF */   addiu    $v0, $zero, -1
/* A4919C 80240BDC 86440008 */  lh        $a0, 8($s2)
/* A491A0 80240BE0 0C00FB3A */  jal       get_enemy
/* A491A4 80240BE4 24840001 */   addiu    $a0, $a0, 1
/* A491A8 80240BE8 8C43006C */  lw        $v1, 0x6c($v0)
/* A491AC 80240BEC 10600002 */  beqz      $v1, .L80240BF8
/* A491B0 80240BF0 24020001 */   addiu    $v0, $zero, 1
.L80240BF4:
/* A491B4 80240BF4 2402FFFF */  addiu     $v0, $zero, -1
.L80240BF8:
/* A491B8 80240BF8 8FBF0024 */  lw        $ra, 0x24($sp)
/* A491BC 80240BFC 8FB20020 */  lw        $s2, 0x20($sp)
/* A491C0 80240C00 8FB1001C */  lw        $s1, 0x1c($sp)
/* A491C4 80240C04 8FB00018 */  lw        $s0, 0x18($sp)
/* A491C8 80240C08 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A491CC 80240C0C D7B40028 */  ldc1      $f20, 0x28($sp)
/* A491D0 80240C10 03E00008 */  jr        $ra
/* A491D4 80240C14 27BD0038 */   addiu    $sp, $sp, 0x38
