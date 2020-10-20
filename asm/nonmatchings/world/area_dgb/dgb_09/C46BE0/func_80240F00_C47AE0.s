.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F00_C47AE0
/* C47AE0 80240F00 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C47AE4 80240F04 AFB3002C */  sw        $s3, 0x2c($sp)
/* C47AE8 80240F08 0080982D */  daddu     $s3, $a0, $zero
/* C47AEC 80240F0C AFBF0030 */  sw        $ra, 0x30($sp)
/* C47AF0 80240F10 AFB20028 */  sw        $s2, 0x28($sp)
/* C47AF4 80240F14 AFB10024 */  sw        $s1, 0x24($sp)
/* C47AF8 80240F18 AFB00020 */  sw        $s0, 0x20($sp)
/* C47AFC 80240F1C 8E720148 */  lw        $s2, 0x148($s3)
/* C47B00 80240F20 00A0882D */  daddu     $s1, $a1, $zero
/* C47B04 80240F24 86440008 */  lh        $a0, 8($s2)
/* C47B08 80240F28 0C00EABB */  jal       get_npc_unsafe
/* C47B0C 80240F2C 00C0802D */   daddu    $s0, $a2, $zero
/* C47B10 80240F30 0200202D */  daddu     $a0, $s0, $zero
/* C47B14 80240F34 0240282D */  daddu     $a1, $s2, $zero
/* C47B18 80240F38 AFA00010 */  sw        $zero, 0x10($sp)
/* C47B1C 80240F3C 8E260024 */  lw        $a2, 0x24($s1)
/* C47B20 80240F40 8E270028 */  lw        $a3, 0x28($s1)
/* C47B24 80240F44 0C01242D */  jal       func_800490B4
/* C47B28 80240F48 0040802D */   daddu    $s0, $v0, $zero
/* C47B2C 80240F4C 1040000C */  beqz      $v0, .L80240F80
/* C47B30 80240F50 00000000 */   nop      
/* C47B34 80240F54 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C47B38 80240F58 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C47B3C 80240F5C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C47B40 80240F60 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C47B44 80240F64 8C460028 */  lw        $a2, 0x28($v0)
/* C47B48 80240F68 0C00A720 */  jal       atan2
/* C47B4C 80240F6C 8C470030 */   lw       $a3, 0x30($v0)
/* C47B50 80240F70 2402000C */  addiu     $v0, $zero, 0xc
/* C47B54 80240F74 E600000C */  swc1      $f0, 0xc($s0)
/* C47B58 80240F78 08090417 */  j         .L8024105C
/* C47B5C 80240F7C AE620070 */   sw       $v0, 0x70($s3)
.L80240F80:
/* C47B60 80240F80 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C47B64 80240F84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C47B68 80240F88 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C47B6C 80240F8C C4440000 */  lwc1      $f4, ($v0)
/* C47B70 80240F90 46802120 */  cvt.s.w   $f4, $f4
/* C47B74 80240F94 44062000 */  mfc1      $a2, $f4
/* C47B78 80240F98 C4440008 */  lwc1      $f4, 8($v0)
/* C47B7C 80240F9C 46802120 */  cvt.s.w   $f4, $f4
/* C47B80 80240FA0 44072000 */  mfc1      $a3, $f4
/* C47B84 80240FA4 0C00A7B5 */  jal       dist2D
/* C47B88 80240FA8 00000000 */   nop      
/* C47B8C 80240FAC C6020018 */  lwc1      $f2, 0x18($s0)
/* C47B90 80240FB0 4602003E */  c.le.s    $f0, $f2
/* C47B94 80240FB4 00000000 */  nop       
/* C47B98 80240FB8 4500000B */  bc1f      .L80240FE8
/* C47B9C 80240FBC 00000000 */   nop      
/* C47BA0 80240FC0 8E4200CC */  lw        $v0, 0xcc($s2)
/* C47BA4 80240FC4 8C430000 */  lw        $v1, ($v0)
/* C47BA8 80240FC8 2402000F */  addiu     $v0, $zero, 0xf
/* C47BAC 80240FCC A602008E */  sh        $v0, 0x8e($s0)
/* C47BB0 80240FD0 24020032 */  addiu     $v0, $zero, 0x32
/* C47BB4 80240FD4 AE030028 */  sw        $v1, 0x28($s0)
/* C47BB8 80240FD8 AE420088 */  sw        $v0, 0x88($s2)
/* C47BBC 80240FDC 24020003 */  addiu     $v0, $zero, 3
/* C47BC0 80240FE0 08090417 */  j         .L8024105C
/* C47BC4 80240FE4 AE620070 */   sw       $v0, 0x70($s3)
.L80240FE8:
/* C47BC8 80240FE8 8602008C */  lh        $v0, 0x8c($s0)
/* C47BCC 80240FEC 1440001B */  bnez      $v0, .L8024105C
/* C47BD0 80240FF0 0200202D */   daddu    $a0, $s0, $zero
/* C47BD4 80240FF4 27A60018 */  addiu     $a2, $sp, 0x18
/* C47BD8 80240FF8 3C0540A0 */  lui       $a1, 0x40a0
/* C47BDC 80240FFC C600000C */  lwc1      $f0, 0xc($s0)
/* C47BE0 80241000 0000382D */  daddu     $a3, $zero, $zero
/* C47BE4 80241004 E7A00018 */  swc1      $f0, 0x18($sp)
/* C47BE8 80241008 AFA00010 */  sw        $zero, 0x10($sp)
/* C47BEC 8024100C 0C0129E1 */  jal       func_8004A784
/* C47BF0 80241010 AFA00014 */   sw       $zero, 0x14($sp)
/* C47BF4 80241014 C7A00018 */  lwc1      $f0, 0x18($sp)
/* C47BF8 80241018 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C47BFC 8024101C E600000C */  swc1      $f0, 0xc($s0)
/* C47C00 80241020 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C47C04 80241024 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C47C08 80241028 C4440000 */  lwc1      $f4, ($v0)
/* C47C0C 8024102C 46802120 */  cvt.s.w   $f4, $f4
/* C47C10 80241030 44062000 */  mfc1      $a2, $f4
/* C47C14 80241034 C4440008 */  lwc1      $f4, 8($v0)
/* C47C18 80241038 46802120 */  cvt.s.w   $f4, $f4
/* C47C1C 8024103C 44072000 */  mfc1      $a3, $f4
/* C47C20 80241040 0C00A720 */  jal       atan2
/* C47C24 80241044 00000000 */   nop      
/* C47C28 80241048 8E050018 */  lw        $a1, 0x18($s0)
/* C47C2C 8024104C 44060000 */  mfc1      $a2, $f0
/* C47C30 80241050 0200202D */  daddu     $a0, $s0, $zero
/* C47C34 80241054 0C00EA95 */  jal       npc_move_heading
/* C47C38 80241058 AC86000C */   sw       $a2, 0xc($a0)
.L8024105C:
/* C47C3C 8024105C 8FBF0030 */  lw        $ra, 0x30($sp)
/* C47C40 80241060 8FB3002C */  lw        $s3, 0x2c($sp)
/* C47C44 80241064 8FB20028 */  lw        $s2, 0x28($sp)
/* C47C48 80241068 8FB10024 */  lw        $s1, 0x24($sp)
/* C47C4C 8024106C 8FB00020 */  lw        $s0, 0x20($sp)
/* C47C50 80241070 03E00008 */  jr        $ra
/* C47C54 80241074 27BD0038 */   addiu    $sp, $sp, 0x38
