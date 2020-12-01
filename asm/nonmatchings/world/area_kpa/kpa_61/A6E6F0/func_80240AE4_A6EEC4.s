.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE4_A6EEC4
/* A6EEC4 80240AE4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A6EEC8 80240AE8 AFB00018 */  sw        $s0, 0x18($sp)
/* A6EECC 80240AEC AFBF0024 */  sw        $ra, 0x24($sp)
/* A6EED0 80240AF0 AFB20020 */  sw        $s2, 0x20($sp)
/* A6EED4 80240AF4 AFB1001C */  sw        $s1, 0x1c($sp)
/* A6EED8 80240AF8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A6EEDC 80240AFC F7B40028 */  sdc1      $f20, 0x28($sp)
/* A6EEE0 80240B00 8C920148 */  lw        $s2, 0x148($a0)
/* A6EEE4 80240B04 4485A000 */  mtc1      $a1, $f20
/* A6EEE8 80240B08 86440008 */  lh        $a0, 8($s2)
/* A6EEEC 80240B0C 4486B000 */  mtc1      $a2, $f22
/* A6EEF0 80240B10 0C00EABB */  jal       get_npc_unsafe
/* A6EEF4 80240B14 00E0802D */   daddu    $s0, $a3, $zero
/* A6EEF8 80240B18 0200202D */  daddu     $a0, $s0, $zero
/* A6EEFC 80240B1C 0040882D */  daddu     $s1, $v0, $zero
/* A6EF00 80240B20 4406A000 */  mfc1      $a2, $f20
/* A6EF04 80240B24 4407B000 */  mfc1      $a3, $f22
/* A6EF08 80240B28 3C03800A */  lui       $v1, %hi(D_8009A634)
/* A6EF0C 80240B2C 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* A6EF10 80240B30 3C05800B */  lui       $a1, %hi(gCameras)
/* A6EF14 80240B34 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A6EF18 80240B38 AFA00010 */  sw        $zero, 0x10($sp)
/* A6EF1C 80240B3C 00031080 */  sll       $v0, $v1, 2
/* A6EF20 80240B40 00431021 */  addu      $v0, $v0, $v1
/* A6EF24 80240B44 00021080 */  sll       $v0, $v0, 2
/* A6EF28 80240B48 00431023 */  subu      $v0, $v0, $v1
/* A6EF2C 80240B4C 000218C0 */  sll       $v1, $v0, 3
/* A6EF30 80240B50 00431021 */  addu      $v0, $v0, $v1
/* A6EF34 80240B54 000210C0 */  sll       $v0, $v0, 3
/* A6EF38 80240B58 00458021 */  addu      $s0, $v0, $a1
/* A6EF3C 80240B5C 0C01242D */  jal       func_800490B4
/* A6EF40 80240B60 0240282D */   daddu    $a1, $s2, $zero
/* A6EF44 80240B64 1040004B */  beqz      $v0, .L80240C94
/* A6EF48 80240B68 2402FFFF */   addiu    $v0, $zero, -1
/* A6EF4C 80240B6C C60C006C */  lwc1      $f12, 0x6c($s0)
/* A6EF50 80240B70 C62E000C */  lwc1      $f14, 0xc($s1)
/* A6EF54 80240B74 3C014387 */  lui       $at, 0x4387
/* A6EF58 80240B78 4481A000 */  mtc1      $at, $f20
/* A6EF5C 80240B7C 0C00A70A */  jal       get_clamped_angle_diff
/* A6EF60 80240B80 00000000 */   nop      
/* A6EF64 80240B84 0C00A6C9 */  jal       clamp_angle
/* A6EF68 80240B88 46000306 */   mov.s    $f12, $f0
/* A6EF6C 80240B8C 3C018024 */  lui       $at, %hi(D_80243D30)
/* A6EF70 80240B90 D4223D30 */  ldc1      $f2, %lo(D_80243D30)($at)
/* A6EF74 80240B94 46000021 */  cvt.d.s   $f0, $f0
/* A6EF78 80240B98 4622003C */  c.lt.d    $f0, $f2
/* A6EF7C 80240B9C 00000000 */  nop       
/* A6EF80 80240BA0 45000003 */  bc1f      .L80240BB0
/* A6EF84 80240BA4 00000000 */   nop      
/* A6EF88 80240BA8 3C0142B4 */  lui       $at, 0x42b4
/* A6EF8C 80240BAC 4481A000 */  mtc1      $at, $f20
.L80240BB0:
/* A6EF90 80240BB0 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* A6EF94 80240BB4 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* A6EF98 80240BB8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A6EF9C 80240BBC 8E020000 */  lw        $v0, ($s0)
/* A6EFA0 80240BC0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A6EFA4 80240BC4 8C460028 */  lw        $a2, 0x28($v0)
/* A6EFA8 80240BC8 0C00A720 */  jal       atan2
/* A6EFAC 80240BCC 8C470030 */   lw       $a3, 0x30($v0)
/* A6EFB0 80240BD0 4600A306 */  mov.s     $f12, $f20
/* A6EFB4 80240BD4 0C00A70A */  jal       get_clamped_angle_diff
/* A6EFB8 80240BD8 46000386 */   mov.s    $f14, $f0
/* A6EFBC 80240BDC 46000005 */  abs.s     $f0, $f0
/* A6EFC0 80240BE0 3C018024 */  lui       $at, %hi(D_80243D38)
/* A6EFC4 80240BE4 D4223D38 */  ldc1      $f2, %lo(D_80243D38)($at)
/* A6EFC8 80240BE8 46000021 */  cvt.d.s   $f0, $f0
/* A6EFCC 80240BEC 4620103C */  c.lt.d    $f2, $f0
/* A6EFD0 80240BF0 00000000 */  nop       
/* A6EFD4 80240BF4 45010027 */  bc1t      .L80240C94
/* A6EFD8 80240BF8 2402FFFF */   addiu    $v0, $zero, -1
/* A6EFDC 80240BFC 8E020000 */  lw        $v0, ($s0)
/* A6EFE0 80240C00 C6200038 */  lwc1      $f0, 0x38($s1)
/* A6EFE4 80240C04 C4420028 */  lwc1      $f2, 0x28($v0)
/* A6EFE8 80240C08 44806000 */  mtc1      $zero, $f12
/* A6EFEC 80240C0C 46020001 */  sub.s     $f0, $f0, $f2
/* A6EFF0 80240C10 C62E003C */  lwc1      $f14, 0x3c($s1)
/* A6EFF4 80240C14 8C47002C */  lw        $a3, 0x2c($v0)
/* A6EFF8 80240C18 46000005 */  abs.s     $f0, $f0
/* A6EFFC 80240C1C 44060000 */  mfc1      $a2, $f0
/* A6F000 80240C20 0C00A720 */  jal       atan2
/* A6F004 80240C24 00000000 */   nop      
/* A6F008 80240C28 3C018024 */  lui       $at, %hi(D_80243D40)
/* A6F00C 80240C2C D4223D40 */  ldc1      $f2, %lo(D_80243D40)($at)
/* A6F010 80240C30 46000021 */  cvt.d.s   $f0, $f0
/* A6F014 80240C34 46220001 */  sub.d     $f0, $f0, $f2
/* A6F018 80240C38 3C018024 */  lui       $at, %hi(D_80243D48)
/* A6F01C 80240C3C D4223D48 */  ldc1      $f2, %lo(D_80243D48)($at)
/* A6F020 80240C40 46200020 */  cvt.s.d   $f0, $f0
/* A6F024 80240C44 46000005 */  abs.s     $f0, $f0
/* A6F028 80240C48 46000021 */  cvt.d.s   $f0, $f0
/* A6F02C 80240C4C 4620103C */  c.lt.d    $f2, $f0
/* A6F030 80240C50 00000000 */  nop       
/* A6F034 80240C54 4501000F */  bc1t      .L80240C94
/* A6F038 80240C58 2402FFFF */   addiu    $v0, $zero, -1
/* A6F03C 80240C5C 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* A6F040 80240C60 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* A6F044 80240C64 24020009 */  addiu     $v0, $zero, 9
/* A6F048 80240C68 10620009 */  beq       $v1, $v0, .L80240C90
/* A6F04C 80240C6C 24020007 */   addiu    $v0, $zero, 7
/* A6F050 80240C70 50620008 */  beql      $v1, $v0, .L80240C94
/* A6F054 80240C74 2402FFFF */   addiu    $v0, $zero, -1
/* A6F058 80240C78 86440008 */  lh        $a0, 8($s2)
/* A6F05C 80240C7C 0C00FB3A */  jal       get_enemy
/* A6F060 80240C80 24840001 */   addiu    $a0, $a0, 1
/* A6F064 80240C84 8C43006C */  lw        $v1, 0x6c($v0)
/* A6F068 80240C88 10600002 */  beqz      $v1, .L80240C94
/* A6F06C 80240C8C 24020001 */   addiu    $v0, $zero, 1
.L80240C90:
/* A6F070 80240C90 2402FFFF */  addiu     $v0, $zero, -1
.L80240C94:
/* A6F074 80240C94 8FBF0024 */  lw        $ra, 0x24($sp)
/* A6F078 80240C98 8FB20020 */  lw        $s2, 0x20($sp)
/* A6F07C 80240C9C 8FB1001C */  lw        $s1, 0x1c($sp)
/* A6F080 80240CA0 8FB00018 */  lw        $s0, 0x18($sp)
/* A6F084 80240CA4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A6F088 80240CA8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A6F08C 80240CAC 03E00008 */  jr        $ra
/* A6F090 80240CB0 27BD0038 */   addiu    $sp, $sp, 0x38
