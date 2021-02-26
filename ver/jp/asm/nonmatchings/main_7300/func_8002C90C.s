.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C90C
/* 7D0C 8002C90C AFA60008 */  sw        $a2, 8($sp)
/* 7D10 8002C910 AFA7000C */  sw        $a3, 0xc($sp)
/* 7D14 8002C914 27BDFED0 */  addiu     $sp, $sp, -0x130
/* 7D18 8002C918 AFB20118 */  sw        $s2, 0x118($sp)
/* 7D1C 8002C91C 0080902D */  daddu     $s2, $a0, $zero
/* 7D20 8002C920 AFB00110 */  sw        $s0, 0x110($sp)
/* 7D24 8002C924 00A0802D */  daddu     $s0, $a1, $zero
/* 7D28 8002C928 AFB3011C */  sw        $s3, 0x11c($sp)
/* 7D2C 8002C92C 0240982D */  daddu     $s3, $s2, $zero
/* 7D30 8002C930 3C048003 */  lui       $a0, %hi(func_8002C194)
/* 7D34 8002C934 2484C194 */  addiu     $a0, $a0, %lo(func_8002C194)
/* 7D38 8002C938 27A50010 */  addiu     $a1, $sp, 0x10
/* 7D3C 8002C93C 27A7013C */  addiu     $a3, $sp, 0x13c
/* 7D40 8002C940 AFBF0128 */  sw        $ra, 0x128($sp)
/* 7D44 8002C944 AFB50124 */  sw        $s5, 0x124($sp)
/* 7D48 8002C948 AFB40120 */  sw        $s4, 0x120($sp)
/* 7D4C 8002C94C 0C01929C */  jal       func_80064A70
/* 7D50 8002C950 AFB10114 */   sw       $s1, 0x114($sp)
/* 7D54 8002C954 0040882D */  daddu     $s1, $v0, $zero
/* 7D58 8002C958 1A20001D */  blez      $s1, .L8002C9D0
/* 7D5C 8002C95C 00122400 */   sll      $a0, $s2, 0x10
/* 7D60 8002C960 00042403 */  sra       $a0, $a0, 0x10
/* 7D64 8002C964 2484FFFA */  addiu     $a0, $a0, -6
/* 7D68 8002C968 00108400 */  sll       $s0, $s0, 0x10
/* 7D6C 8002C96C 00102C03 */  sra       $a1, $s0, 0x10
/* 7D70 8002C970 24A5FFFA */  addiu     $a1, $a1, -6
/* 7D74 8002C974 26220002 */  addiu     $v0, $s1, 2
/* 7D78 8002C978 00023040 */  sll       $a2, $v0, 1
/* 7D7C 8002C97C 00C23021 */  addu      $a2, $a2, $v0
/* 7D80 8002C980 00063040 */  sll       $a2, $a2, 1
/* 7D84 8002C984 0C00AFDC */  jal       func_8002BF70
/* 7D88 8002C988 24070013 */   addiu    $a3, $zero, 0x13
/* 7D8C 8002C98C 27B20010 */  addiu     $s2, $sp, 0x10
/* 7D90 8002C990 3C158007 */  lui       $s5, %hi(D_800771F0)
/* 7D94 8002C994 26B571F0 */  addiu     $s5, $s5, %lo(D_800771F0)
/* 7D98 8002C998 241400FF */  addiu     $s4, $zero, 0xff
.L8002C99C:
/* 7D9C 8002C99C 92420000 */  lbu       $v0, ($s2)
/* 7DA0 8002C9A0 3042007F */  andi      $v0, $v0, 0x7f
/* 7DA4 8002C9A4 00551021 */  addu      $v0, $v0, $s5
/* 7DA8 8002C9A8 90460000 */  lbu       $a2, ($v0)
/* 7DAC 8002C9AC 10D40004 */  beq       $a2, $s4, .L8002C9C0
/* 7DB0 8002C9B0 00132400 */   sll      $a0, $s3, 0x10
/* 7DB4 8002C9B4 00042403 */  sra       $a0, $a0, 0x10
/* 7DB8 8002C9B8 0C00B005 */  jal       func_8002C014
/* 7DBC 8002C9BC 00102C03 */   sra      $a1, $s0, 0x10
.L8002C9C0:
/* 7DC0 8002C9C0 26730006 */  addiu     $s3, $s3, 6
/* 7DC4 8002C9C4 2631FFFF */  addiu     $s1, $s1, -1
/* 7DC8 8002C9C8 1E20FFF4 */  bgtz      $s1, .L8002C99C
/* 7DCC 8002C9CC 26520001 */   addiu    $s2, $s2, 1
.L8002C9D0:
/* 7DD0 8002C9D0 8FBF0128 */  lw        $ra, 0x128($sp)
/* 7DD4 8002C9D4 8FB50124 */  lw        $s5, 0x124($sp)
/* 7DD8 8002C9D8 8FB40120 */  lw        $s4, 0x120($sp)
/* 7DDC 8002C9DC 8FB3011C */  lw        $s3, 0x11c($sp)
/* 7DE0 8002C9E0 8FB20118 */  lw        $s2, 0x118($sp)
/* 7DE4 8002C9E4 8FB10114 */  lw        $s1, 0x114($sp)
/* 7DE8 8002C9E8 8FB00110 */  lw        $s0, 0x110($sp)
/* 7DEC 8002C9EC 03E00008 */  jr        $ra
/* 7DF0 8002C9F0 27BD0130 */   addiu    $sp, $sp, 0x130
/* 7DF4 8002C9F4 00000000 */  nop
/* 7DF8 8002C9F8 00000000 */  nop
/* 7DFC 8002C9FC 00000000 */  nop
