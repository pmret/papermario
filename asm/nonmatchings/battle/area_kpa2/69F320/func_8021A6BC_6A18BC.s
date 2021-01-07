.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A6BC_6A18BC
/* 6A18BC 8021A6BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A18C0 8021A6C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A18C4 8021A6C4 0080802D */  daddu     $s0, $a0, $zero
/* 6A18C8 8021A6C8 10A0000E */  beqz      $a1, .L8021A704
/* 6A18CC 8021A6CC AFBF0014 */   sw       $ra, 0x14($sp)
/* 6A18D0 8021A6D0 0C04760B */  jal       func_8011D82C
/* 6A18D4 8021A6D4 24040001 */   addiu    $a0, $zero, 1
/* 6A18D8 8021A6D8 0000202D */  daddu     $a0, $zero, $zero
/* 6A18DC 8021A6DC 0080282D */  daddu     $a1, $a0, $zero
/* 6A18E0 8021A6E0 0080302D */  daddu     $a2, $a0, $zero
/* 6A18E4 8021A6E4 0080382D */  daddu     $a3, $a0, $zero
/* 6A18E8 8021A6E8 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 6A18EC 8021A6EC 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 6A18F0 8021A6F0 24030001 */  addiu     $v1, $zero, 1
/* 6A18F4 8021A6F4 0C046F97 */  jal       set_background_color_blend
/* 6A18F8 8021A6F8 A0430000 */   sb       $v1, ($v0)
/* 6A18FC 8021A6FC 24020014 */  addiu     $v0, $zero, 0x14
/* 6A1900 8021A700 AE020070 */  sw        $v0, 0x70($s0)
.L8021A704:
/* 6A1904 8021A704 0000202D */  daddu     $a0, $zero, $zero
/* 6A1908 8021A708 0080282D */  daddu     $a1, $a0, $zero
/* 6A190C 8021A70C 0080302D */  daddu     $a2, $a0, $zero
/* 6A1910 8021A710 8E030070 */  lw        $v1, 0x70($s0)
/* 6A1914 8021A714 24020014 */  addiu     $v0, $zero, 0x14
/* 6A1918 8021A718 00431023 */  subu      $v0, $v0, $v1
/* 6A191C 8021A71C 00023880 */  sll       $a3, $v0, 2
/* 6A1920 8021A720 00E23821 */  addu      $a3, $a3, $v0
/* 6A1924 8021A724 00073840 */  sll       $a3, $a3, 1
/* 6A1928 8021A728 0C046F97 */  jal       set_background_color_blend
/* 6A192C 8021A72C 30E700FE */   andi     $a3, $a3, 0xfe
/* 6A1930 8021A730 8E020070 */  lw        $v0, 0x70($s0)
/* 6A1934 8021A734 2442FFFF */  addiu     $v0, $v0, -1
/* 6A1938 8021A738 AE020070 */  sw        $v0, 0x70($s0)
/* 6A193C 8021A73C 2C420001 */  sltiu     $v0, $v0, 1
/* 6A1940 8021A740 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6A1944 8021A744 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A1948 8021A748 00021040 */  sll       $v0, $v0, 1
/* 6A194C 8021A74C 03E00008 */  jr        $ra
/* 6A1950 8021A750 27BD0018 */   addiu    $sp, $sp, 0x18
