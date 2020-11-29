.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F0B3C
/* 89FEC 800F0B3C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 89FF0 800F0B40 AFB00020 */  sw        $s0, 0x20($sp)
/* 89FF4 800F0B44 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 89FF8 800F0B48 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 89FFC 800F0B4C AFBF0024 */  sw        $ra, 0x24($sp)
/* 8A000 800F0B50 920400B4 */  lbu       $a0, 0xb4($s0)
/* 8A004 800F0B54 2482FFFF */  addiu     $v0, $a0, -1
/* 8A008 800F0B58 2C420002 */  sltiu     $v0, $v0, 2
/* 8A00C 800F0B5C 14400013 */  bnez      $v0, .L800F0BAC
/* 8A010 800F0B60 3C02FF00 */   lui      $v0, 0xff00
/* 8A014 800F0B64 8E0300B4 */  lw        $v1, 0xb4($s0)
/* 8A018 800F0B68 3442FF00 */  ori       $v0, $v0, 0xff00
/* 8A01C 800F0B6C 00621824 */  and       $v1, $v1, $v0
/* 8A020 800F0B70 3C021A00 */  lui       $v0, 0x1a00
/* 8A024 800F0B74 1062000D */  beq       $v1, $v0, .L800F0BAC
/* 8A028 800F0B78 00041600 */   sll      $v0, $a0, 0x18
/* 8A02C 800F0B7C 00021E03 */  sra       $v1, $v0, 0x18
/* 8A030 800F0B80 2402000A */  addiu     $v0, $zero, 0xa
/* 8A034 800F0B84 10620003 */  beq       $v1, $v0, .L800F0B94
/* 8A038 800F0B88 00000000 */   nop      
/* 8A03C 800F0B8C 14600004 */  bnez      $v1, .L800F0BA0
/* 8A040 800F0B90 24020004 */   addiu    $v0, $zero, 4
.L800F0B94:
/* 8A044 800F0B94 8E020000 */  lw        $v0, ($s0)
/* 8A048 800F0B98 04400004 */  bltz      $v0, .L800F0BAC
/* 8A04C 800F0B9C 24020004 */   addiu    $v0, $zero, 4
.L800F0BA0:
/* 8A050 800F0BA0 3C018011 */  lui       $at, %hi(D_801094AE)
/* 8A054 800F0BA4 0803C323 */  j         .L800F0C8C
/* 8A058 800F0BA8 A42294AE */   sh       $v0, %lo(D_801094AE)($at)
.L800F0BAC:
/* 8A05C 800F0BAC 3C048011 */  lui       $a0, %hi(D_801094AE)
/* 8A060 800F0BB0 248494AE */  addiu     $a0, $a0, %lo(D_801094AE)
/* 8A064 800F0BB4 94820000 */  lhu       $v0, ($a0)
/* 8A068 800F0BB8 24430001 */  addiu     $v1, $v0, 1
/* 8A06C 800F0BBC 00021400 */  sll       $v0, $v0, 0x10
/* 8A070 800F0BC0 00021403 */  sra       $v0, $v0, 0x10
/* 8A074 800F0BC4 28420004 */  slti      $v0, $v0, 4
/* 8A078 800F0BC8 14400030 */  bnez      $v0, .L800F0C8C
/* 8A07C 800F0BCC A4830000 */   sh       $v1, ($a0)
/* 8A080 800F0BD0 C60C0084 */  lwc1      $f12, 0x84($s0)
/* 8A084 800F0BD4 A4800000 */  sh        $zero, ($a0)
/* 8A088 800F0BD8 0C00A6C9 */  jal       clamp_angle
/* 8A08C 800F0BDC 46006307 */   neg.s    $f12, $f12
/* 8A090 800F0BE0 3C0140C9 */  lui       $at, 0x40c9
/* 8A094 800F0BE4 34210FD0 */  ori       $at, $at, 0xfd0
/* 8A098 800F0BE8 44811000 */  mtc1      $at, $f2
/* 8A09C 800F0BEC 00000000 */  nop       
/* 8A0A0 800F0BF0 46020002 */  mul.s     $f0, $f0, $f2
/* 8A0A4 800F0BF4 00000000 */  nop       
/* 8A0A8 800F0BF8 27A50018 */  addiu     $a1, $sp, 0x18
/* 8A0AC 800F0BFC 3C0143B4 */  lui       $at, 0x43b4
/* 8A0B0 800F0C00 44816000 */  mtc1      $at, $f12
/* 8A0B4 800F0C04 27A6001C */  addiu     $a2, $sp, 0x1c
/* 8A0B8 800F0C08 0C00A82D */  jal       sin_cos_rad
/* 8A0BC 800F0C0C 460C0303 */   div.s    $f12, $f0, $f12
/* 8A0C0 800F0C10 860200B2 */  lh        $v0, 0xb2($s0)
/* 8A0C4 800F0C14 C7A40018 */  lwc1      $f4, 0x18($sp)
/* 8A0C8 800F0C18 44821000 */  mtc1      $v0, $f2
/* 8A0CC 800F0C1C 00000000 */  nop       
/* 8A0D0 800F0C20 468010A0 */  cvt.s.w   $f2, $f2
/* 8A0D4 800F0C24 46041102 */  mul.s     $f4, $f2, $f4
/* 8A0D8 800F0C28 00000000 */  nop       
/* 8A0DC 800F0C2C C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 8A0E0 800F0C30 46001082 */  mul.s     $f2, $f2, $f0
/* 8A0E4 800F0C34 00000000 */  nop       
/* 8A0E8 800F0C38 3C013E4C */  lui       $at, 0x3e4c
/* 8A0EC 800F0C3C 3421CCCD */  ori       $at, $at, 0xcccd
/* 8A0F0 800F0C40 44810000 */  mtc1      $at, $f0
/* 8A0F4 800F0C44 00000000 */  nop       
/* 8A0F8 800F0C48 46002102 */  mul.s     $f4, $f4, $f0
/* 8A0FC 800F0C4C 00000000 */  nop       
/* 8A100 800F0C50 46001082 */  mul.s     $f2, $f2, $f0
/* 8A104 800F0C54 00000000 */  nop       
/* 8A108 800F0C58 44803000 */  mtc1      $zero, $f6
/* 8A10C 800F0C5C C600002C */  lwc1      $f0, 0x2c($s0)
/* 8A110 800F0C60 46060000 */  add.s     $f0, $f0, $f6
/* 8A114 800F0C64 44060000 */  mfc1      $a2, $f0
/* 8A118 800F0C68 C6000028 */  lwc1      $f0, 0x28($s0)
/* 8A11C 800F0C6C 46040000 */  add.s     $f0, $f0, $f4
/* 8A120 800F0C70 44050000 */  mfc1      $a1, $f0
/* 8A124 800F0C74 C6000030 */  lwc1      $f0, 0x30($s0)
/* 8A128 800F0C78 46020000 */  add.s     $f0, $f0, $f2
/* 8A12C 800F0C7C 44070000 */  mfc1      $a3, $f0
/* 8A130 800F0C80 0000202D */  daddu     $a0, $zero, $zero
/* 8A134 800F0C84 0C01C16C */  jal       func_800705B0
/* 8A138 800F0C88 E7A60010 */   swc1     $f6, 0x10($sp)
.L800F0C8C:
/* 8A13C 800F0C8C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 8A140 800F0C90 8FB00020 */  lw        $s0, 0x20($sp)
/* 8A144 800F0C94 03E00008 */  jr        $ra
/* 8A148 800F0C98 27BD0028 */   addiu    $sp, $sp, 0x28
