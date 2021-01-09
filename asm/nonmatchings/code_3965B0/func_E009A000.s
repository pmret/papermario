.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E009A000
/* 3965B0 E009A000 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3965B4 E009A004 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3965B8 E009A008 4485B000 */  mtc1      $a1, $f22
/* 3965BC E009A00C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3965C0 E009A010 4486C000 */  mtc1      $a2, $f24
/* 3965C4 E009A014 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 3965C8 E009A018 4487D000 */  mtc1      $a3, $f26
/* 3965CC E009A01C AFB30034 */  sw        $s3, 0x34($sp)
/* 3965D0 E009A020 0080982D */  daddu     $s3, $a0, $zero
/* 3965D4 E009A024 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3965D8 E009A028 C7B40070 */  lwc1      $f20, 0x70($sp)
/* 3965DC E009A02C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3965E0 E009A030 AFB20030 */  sw        $s2, 0x30($sp)
/* 3965E4 E009A034 8FB20074 */  lw        $s2, 0x74($sp)
/* 3965E8 E009A038 3C02E00A */  lui       $v0, %hi(func_E009A138)
/* 3965EC E009A03C 2442A138 */  addiu     $v0, $v0, %lo(func_E009A138)
/* 3965F0 E009A040 AFA20018 */  sw        $v0, 0x18($sp)
/* 3965F4 E009A044 3C02E00A */  lui       $v0, %hi(func_E009A140)
/* 3965F8 E009A048 2442A140 */  addiu     $v0, $v0, %lo(func_E009A140)
/* 3965FC E009A04C AFA2001C */  sw        $v0, 0x1c($sp)
/* 396600 E009A050 3C02E00A */  lui       $v0, %hi(func_E009A398)
/* 396604 E009A054 2442A398 */  addiu     $v0, $v0, %lo(func_E009A398)
/* 396608 E009A058 AFA20020 */  sw        $v0, 0x20($sp)
/* 39660C E009A05C 2402004D */  addiu     $v0, $zero, 0x4d
/* 396610 E009A060 AFBF0038 */  sw        $ra, 0x38($sp)
/* 396614 E009A064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 396618 E009A068 AFB00028 */  sw        $s0, 0x28($sp)
/* 39661C E009A06C AFA00010 */  sw        $zero, 0x10($sp)
/* 396620 E009A070 AFA00024 */  sw        $zero, 0x24($sp)
/* 396624 E009A074 0C080124 */  jal       func_E0200490
/* 396628 E009A078 AFA20014 */   sw       $v0, 0x14($sp)
/* 39662C E009A07C 24040048 */  addiu     $a0, $zero, 0x48
/* 396630 E009A080 24030001 */  addiu     $v1, $zero, 1
/* 396634 E009A084 0040882D */  daddu     $s1, $v0, $zero
/* 396638 E009A088 0C08012C */  jal       func_E02004B0
/* 39663C E009A08C AE230008 */   sw       $v1, 8($s1)
/* 396640 E009A090 0040802D */  daddu     $s0, $v0, $zero
/* 396644 E009A094 16000003 */  bnez      $s0, .LE009A0A4
/* 396648 E009A098 AE22000C */   sw       $v0, 0xc($s1)
.LE009A09C:
/* 39664C E009A09C 08026827 */  j         .LE009A09C
/* 396650 E009A0A0 00000000 */   nop      
.LE009A0A4:
/* 396654 E009A0A4 3C013F80 */  lui       $at, 0x3f80
/* 396658 E009A0A8 44811000 */  mtc1      $at, $f2
/* 39665C E009A0AC AE130000 */  sw        $s3, ($s0)
/* 396660 E009A0B0 E6160004 */  swc1      $f22, 4($s0)
/* 396664 E009A0B4 E6180008 */  swc1      $f24, 8($s0)
/* 396668 E009A0B8 E61A000C */  swc1      $f26, 0xc($s0)
/* 39666C E009A0BC C7A00080 */  lwc1      $f0, 0x80($sp)
/* 396670 E009A0C0 E6140014 */  swc1      $f20, 0x14($s0)
/* 396674 E009A0C4 AE12001C */  sw        $s2, 0x1c($s0)
/* 396678 E009A0C8 E6000028 */  swc1      $f0, 0x28($s0)
/* 39667C E009A0CC C7A00078 */  lwc1      $f0, 0x78($sp)
/* 396680 E009A0D0 E6000018 */  swc1      $f0, 0x18($s0)
/* 396684 E009A0D4 8FA2007C */  lw        $v0, 0x7c($sp)
/* 396688 E009A0D8 24040168 */  addiu     $a0, $zero, 0x168
/* 39668C E009A0DC E6020034 */  swc1      $f2, 0x34($s0)
/* 396690 E009A0E0 0C080138 */  jal       func_E02004E0
/* 396694 E009A0E4 AE020020 */   sw       $v0, 0x20($s0)
/* 396698 E009A0E8 AE020038 */  sw        $v0, 0x38($s0)
/* 39669C E009A0EC 8FA30084 */  lw        $v1, 0x84($sp)
/* 3966A0 E009A0F0 0220102D */  daddu     $v0, $s1, $zero
/* 3966A4 E009A0F4 AE000044 */  sw        $zero, 0x44($s0)
/* 3966A8 E009A0F8 AE12003C */  sw        $s2, 0x3c($s0)
/* 3966AC E009A0FC E6140024 */  swc1      $f20, 0x24($s0)
/* 3966B0 E009A100 AE000010 */  sw        $zero, 0x10($s0)
/* 3966B4 E009A104 AE00002C */  sw        $zero, 0x2c($s0)
/* 3966B8 E009A108 AE030040 */  sw        $v1, 0x40($s0)
/* 3966BC E009A10C 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3966C0 E009A110 8FB30034 */  lw        $s3, 0x34($sp)
/* 3966C4 E009A114 8FB20030 */  lw        $s2, 0x30($sp)
/* 3966C8 E009A118 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3966CC E009A11C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3966D0 E009A120 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 3966D4 E009A124 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3966D8 E009A128 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3966DC E009A12C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3966E0 E009A130 03E00008 */  jr        $ra
/* 3966E4 E009A134 27BD0060 */   addiu    $sp, $sp, 0x60
