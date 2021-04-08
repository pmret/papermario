.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel iwa_04_UnkFunc9
/* 91C390 80240AB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 91C394 80240AB4 AFB30024 */  sw        $s3, 0x24($sp)
/* 91C398 80240AB8 0080982D */  daddu     $s3, $a0, $zero
/* 91C39C 80240ABC AFBF0028 */  sw        $ra, 0x28($sp)
/* 91C3A0 80240AC0 AFB20020 */  sw        $s2, 0x20($sp)
/* 91C3A4 80240AC4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 91C3A8 80240AC8 AFB00018 */  sw        $s0, 0x18($sp)
/* 91C3AC 80240ACC 8E720148 */  lw        $s2, 0x148($s3)
/* 91C3B0 80240AD0 00A0882D */  daddu     $s1, $a1, $zero
/* 91C3B4 80240AD4 86440008 */  lh        $a0, 8($s2)
/* 91C3B8 80240AD8 0C00EABB */  jal       get_npc_unsafe
/* 91C3BC 80240ADC 00C0802D */   daddu    $s0, $a2, $zero
/* 91C3C0 80240AE0 0200202D */  daddu     $a0, $s0, $zero
/* 91C3C4 80240AE4 0240282D */  daddu     $a1, $s2, $zero
/* 91C3C8 80240AE8 AFA00010 */  sw        $zero, 0x10($sp)
/* 91C3CC 80240AEC 8E260024 */  lw        $a2, 0x24($s1)
/* 91C3D0 80240AF0 8E270028 */  lw        $a3, 0x28($s1)
/* 91C3D4 80240AF4 0C01242D */  jal       func_800490B4
/* 91C3D8 80240AF8 0040802D */   daddu    $s0, $v0, $zero
/* 91C3DC 80240AFC 1040000C */  beqz      $v0, .L80240B30
/* 91C3E0 80240B00 00000000 */   nop
/* 91C3E4 80240B04 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91C3E8 80240B08 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 91C3EC 80240B0C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 91C3F0 80240B10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91C3F4 80240B14 8C460028 */  lw        $a2, 0x28($v0)
/* 91C3F8 80240B18 0C00A720 */  jal       atan2
/* 91C3FC 80240B1C 8C470030 */   lw       $a3, 0x30($v0)
/* 91C400 80240B20 2402000C */  addiu     $v0, $zero, 0xc
/* 91C404 80240B24 E600000C */  swc1      $f0, 0xc($s0)
/* 91C408 80240B28 080902F3 */  j         .L80240BCC
/* 91C40C 80240B2C AE620070 */   sw       $v0, 0x70($s3)
.L80240B30:
/* 91C410 80240B30 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91C414 80240B34 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C418 80240B38 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91C41C 80240B3C C4440000 */  lwc1      $f4, ($v0)
/* 91C420 80240B40 46802120 */  cvt.s.w   $f4, $f4
/* 91C424 80240B44 44062000 */  mfc1      $a2, $f4
/* 91C428 80240B48 C4440008 */  lwc1      $f4, 8($v0)
/* 91C42C 80240B4C 46802120 */  cvt.s.w   $f4, $f4
/* 91C430 80240B50 44072000 */  mfc1      $a3, $f4
/* 91C434 80240B54 0C00A7B5 */  jal       dist2D
/* 91C438 80240B58 00000000 */   nop
/* 91C43C 80240B5C C6020018 */  lwc1      $f2, 0x18($s0)
/* 91C440 80240B60 4602003E */  c.le.s    $f0, $f2
/* 91C444 80240B64 00000000 */  nop
/* 91C448 80240B68 45000005 */  bc1f      .L80240B80
/* 91C44C 80240B6C 2402000A */   addiu    $v0, $zero, 0xa
/* 91C450 80240B70 A602008E */  sh        $v0, 0x8e($s0)
/* 91C454 80240B74 24020032 */  addiu     $v0, $zero, 0x32
/* 91C458 80240B78 080902F3 */  j         .L80240BCC
/* 91C45C 80240B7C AE620070 */   sw       $v0, 0x70($s3)
.L80240B80:
/* 91C460 80240B80 8602008C */  lh        $v0, 0x8c($s0)
/* 91C464 80240B84 14400011 */  bnez      $v0, .L80240BCC
/* 91C468 80240B88 00000000 */   nop
/* 91C46C 80240B8C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91C470 80240B90 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C474 80240B94 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91C478 80240B98 C4440000 */  lwc1      $f4, ($v0)
/* 91C47C 80240B9C 46802120 */  cvt.s.w   $f4, $f4
/* 91C480 80240BA0 44062000 */  mfc1      $a2, $f4
/* 91C484 80240BA4 C4440008 */  lwc1      $f4, 8($v0)
/* 91C488 80240BA8 46802120 */  cvt.s.w   $f4, $f4
/* 91C48C 80240BAC 44072000 */  mfc1      $a3, $f4
/* 91C490 80240BB0 0C00A720 */  jal       atan2
/* 91C494 80240BB4 00000000 */   nop
/* 91C498 80240BB8 8E050018 */  lw        $a1, 0x18($s0)
/* 91C49C 80240BBC 44060000 */  mfc1      $a2, $f0
/* 91C4A0 80240BC0 0200202D */  daddu     $a0, $s0, $zero
/* 91C4A4 80240BC4 0C00EA95 */  jal       npc_move_heading
/* 91C4A8 80240BC8 AC86000C */   sw       $a2, 0xc($a0)
.L80240BCC:
/* 91C4AC 80240BCC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 91C4B0 80240BD0 8FB30024 */  lw        $s3, 0x24($sp)
/* 91C4B4 80240BD4 8FB20020 */  lw        $s2, 0x20($sp)
/* 91C4B8 80240BD8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 91C4BC 80240BDC 8FB00018 */  lw        $s0, 0x18($sp)
/* 91C4C0 80240BE0 03E00008 */  jr        $ra
/* 91C4C4 80240BE4 27BD0030 */   addiu    $sp, $sp, 0x30
