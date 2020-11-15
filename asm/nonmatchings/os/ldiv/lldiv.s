.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel lldiv
/* 48AA4 8006D6A4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 48AA8 8006D6A8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 48AAC 8006D6AC AFB20028 */  sw        $s2, 0x28($sp)
/* 48AB0 8006D6B0 8FB20048 */  lw        $s2, 0x48($sp)
/* 48AB4 8006D6B4 8FB3004C */  lw        $s3, 0x4c($sp)
/* 48AB8 8006D6B8 AFB40030 */  sw        $s4, 0x30($sp)
/* 48ABC 8006D6BC 0080A021 */  addu      $s4, $a0, $zero
/* 48AC0 8006D6C0 AFB10024 */  sw        $s1, 0x24($sp)
/* 48AC4 8006D6C4 AFB00020 */  sw        $s0, 0x20($sp)
/* 48AC8 8006D6C8 00C08021 */  addu      $s0, $a2, $zero
/* 48ACC 8006D6CC 00E08821 */  addu      $s1, $a3, $zero
/* 48AD0 8006D6D0 02002021 */  addu      $a0, $s0, $zero
/* 48AD4 8006D6D4 02202821 */  addu      $a1, $s1, $zero
/* 48AD8 8006D6D8 AFBF0034 */  sw        $ra, 0x34($sp)
/* 48ADC 8006D6DC 02403021 */  addu      $a2, $s2, $zero
/* 48AE0 8006D6E0 0C01B600 */  jal       func_8006D800
/* 48AE4 8006D6E4 02603821 */   addu     $a3, $s3, $zero
/* 48AE8 8006D6E8 00403021 */  addu      $a2, $v0, $zero
/* 48AEC 8006D6EC 00603821 */  addu      $a3, $v1, $zero
/* 48AF0 8006D6F0 02670019 */  multu     $s3, $a3
/* 48AF4 8006D6F4 00001010 */  mfhi      $v0
/* 48AF8 8006D6F8 00001812 */  mflo      $v1
/* 48AFC 8006D6FC 00000000 */  nop       
/* 48B00 8006D700 00000000 */  nop       
/* 48B04 8006D704 02660018 */  mult      $s3, $a2
/* 48B08 8006D708 00002012 */  mflo      $a0
/* 48B0C 8006D70C 00000000 */  nop       
/* 48B10 8006D710 00000000 */  nop       
/* 48B14 8006D714 00F20018 */  mult      $a3, $s2
/* 48B18 8006D718 00002812 */  mflo      $a1
/* 48B1C 8006D71C AFA60010 */  sw        $a2, 0x10($sp)
/* 48B20 8006D720 AFA70014 */  sw        $a3, 0x14($sp)
/* 48B24 8006D724 00441021 */  addu      $v0, $v0, $a0
/* 48B28 8006D728 8FA40010 */  lw        $a0, 0x10($sp)
/* 48B2C 8006D72C 00451021 */  addu      $v0, $v0, $a1
/* 48B30 8006D730 0223282B */  sltu      $a1, $s1, $v1
/* 48B34 8006D734 02234823 */  subu      $t1, $s1, $v1
/* 48B38 8006D738 02024023 */  subu      $t0, $s0, $v0
/* 48B3C 8006D73C 01054023 */  subu      $t0, $t0, $a1
/* 48B40 8006D740 AFA80018 */  sw        $t0, 0x18($sp)
/* 48B44 8006D744 04810013 */  bgez      $a0, .L8006D794
/* 48B48 8006D748 AFA9001C */   sw       $t1, 0x1c($sp)
/* 48B4C 8006D74C 8FA20018 */  lw        $v0, 0x18($sp)
/* 48B50 8006D750 5C400006 */  bgtzl     $v0, .L8006D76C
/* 48B54 8006D754 24E30001 */   addiu    $v1, $a3, 1
/* 48B58 8006D758 1440000E */  bnez      $v0, .L8006D794
/* 48B5C 8006D75C 00000000 */   nop      
/* 48B60 8006D760 8FA2001C */  lw        $v0, 0x1c($sp)
/* 48B64 8006D764 1040000B */  beqz      $v0, .L8006D794
/* 48B68 8006D768 24E30001 */   addiu    $v1, $a3, 1
.L8006D76C:
/* 48B6C 8006D76C 2C640001 */  sltiu     $a0, $v1, 1
/* 48B70 8006D770 00C41021 */  addu      $v0, $a2, $a0
/* 48B74 8006D774 AFA20010 */  sw        $v0, 0x10($sp)
/* 48B78 8006D778 AFA30014 */  sw        $v1, 0x14($sp)
/* 48B7C 8006D77C 0133202B */  sltu      $a0, $t1, $s3
/* 48B80 8006D780 01331823 */  subu      $v1, $t1, $s3
/* 48B84 8006D784 01121023 */  subu      $v0, $t0, $s2
/* 48B88 8006D788 00441023 */  subu      $v0, $v0, $a0
/* 48B8C 8006D78C AFA20018 */  sw        $v0, 0x18($sp)
/* 48B90 8006D790 AFA3001C */  sw        $v1, 0x1c($sp)
.L8006D794:
/* 48B94 8006D794 8FA20010 */  lw        $v0, 0x10($sp)
/* 48B98 8006D798 8FA30014 */  lw        $v1, 0x14($sp)
/* 48B9C 8006D79C 8FA40018 */  lw        $a0, 0x18($sp)
/* 48BA0 8006D7A0 8FA5001C */  lw        $a1, 0x1c($sp)
/* 48BA4 8006D7A4 AE820000 */  sw        $v0, ($s4)
/* 48BA8 8006D7A8 AE830004 */  sw        $v1, 4($s4)
/* 48BAC 8006D7AC AE840008 */  sw        $a0, 8($s4)
/* 48BB0 8006D7B0 AE85000C */  sw        $a1, 0xc($s4)
/* 48BB4 8006D7B4 02801021 */  addu      $v0, $s4, $zero
/* 48BB8 8006D7B8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 48BBC 8006D7BC 8FB40030 */  lw        $s4, 0x30($sp)
/* 48BC0 8006D7C0 8FB3002C */  lw        $s3, 0x2c($sp)
/* 48BC4 8006D7C4 8FB20028 */  lw        $s2, 0x28($sp)
/* 48BC8 8006D7C8 8FB10024 */  lw        $s1, 0x24($sp)
/* 48BCC 8006D7CC 8FB00020 */  lw        $s0, 0x20($sp)
/* 48BD0 8006D7D0 03E00008 */  jr        $ra
/* 48BD4 8006D7D4 27BD0038 */   addiu    $sp, $sp, 0x38
/* 48BD8 8006D7D8 00000000 */  nop       
/* 48BDC 8006D7DC 00000000 */  nop       
