.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C94C
/* 7D4C 8002C94C AFA60008 */  sw        $a2, 8($sp)
/* 7D50 8002C950 AFA7000C */  sw        $a3, 0xc($sp)
/* 7D54 8002C954 27BDFED0 */  addiu     $sp, $sp, -0x130
/* 7D58 8002C958 AFB20118 */  sw        $s2, 0x118($sp)
/* 7D5C 8002C95C 0080902D */  daddu     $s2, $a0, $zero
/* 7D60 8002C960 AFB00110 */  sw        $s0, 0x110($sp)
/* 7D64 8002C964 00A0802D */  daddu     $s0, $a1, $zero
/* 7D68 8002C968 AFB3011C */  sw        $s3, 0x11c($sp)
/* 7D6C 8002C96C 0240982D */  daddu     $s3, $s2, $zero
/* 7D70 8002C970 3C048003 */  lui       $a0, %hi(func_8002C1D4)
/* 7D74 8002C974 2484C1D4 */  addiu     $a0, $a0, %lo(func_8002C1D4)
/* 7D78 8002C978 27A50010 */  addiu     $a1, $sp, 0x10
/* 7D7C 8002C97C 27A7013C */  addiu     $a3, $sp, 0x13c
/* 7D80 8002C980 AFBF0128 */  sw        $ra, 0x128($sp)
/* 7D84 8002C984 AFB50124 */  sw        $s5, 0x124($sp)
/* 7D88 8002C988 AFB40120 */  sw        $s4, 0x120($sp)
/* 7D8C 8002C98C 0C0192A8 */  jal       _Printf
/* 7D90 8002C990 AFB10114 */   sw       $s1, 0x114($sp)
/* 7D94 8002C994 0040882D */  daddu     $s1, $v0, $zero
/* 7D98 8002C998 1A20001D */  blez      $s1, .L8002CA10
/* 7D9C 8002C99C 00122400 */   sll      $a0, $s2, 0x10
/* 7DA0 8002C9A0 00042403 */  sra       $a0, $a0, 0x10
/* 7DA4 8002C9A4 2484FFFA */  addiu     $a0, $a0, -6
/* 7DA8 8002C9A8 00108400 */  sll       $s0, $s0, 0x10
/* 7DAC 8002C9AC 00102C03 */  sra       $a1, $s0, 0x10
/* 7DB0 8002C9B0 24A5FFFA */  addiu     $a1, $a1, -6
/* 7DB4 8002C9B4 26220002 */  addiu     $v0, $s1, 2
/* 7DB8 8002C9B8 00023040 */  sll       $a2, $v0, 1
/* 7DBC 8002C9BC 00C23021 */  addu      $a2, $a2, $v0
/* 7DC0 8002C9C0 00063040 */  sll       $a2, $a2, 1
/* 7DC4 8002C9C4 0C00AFEC */  jal       func_8002BFB0
/* 7DC8 8002C9C8 24070013 */   addiu    $a3, $zero, 0x13
/* 7DCC 8002C9CC 27B20010 */  addiu     $s2, $sp, 0x10
/* 7DD0 8002C9D0 3C158007 */  lui       $s5, %hi(D_80077210)
/* 7DD4 8002C9D4 26B57210 */  addiu     $s5, $s5, %lo(D_80077210)
/* 7DD8 8002C9D8 241400FF */  addiu     $s4, $zero, 0xff
.L8002C9DC:
/* 7DDC 8002C9DC 92420000 */  lbu       $v0, ($s2)
/* 7DE0 8002C9E0 3042007F */  andi      $v0, $v0, 0x7f
/* 7DE4 8002C9E4 00551021 */  addu      $v0, $v0, $s5
/* 7DE8 8002C9E8 90460000 */  lbu       $a2, ($v0)
/* 7DEC 8002C9EC 10D40004 */  beq       $a2, $s4, .L8002CA00
/* 7DF0 8002C9F0 00132400 */   sll      $a0, $s3, 0x10
/* 7DF4 8002C9F4 00042403 */  sra       $a0, $a0, 0x10
/* 7DF8 8002C9F8 0C00B015 */  jal       func_8002C054
/* 7DFC 8002C9FC 00102C03 */   sra      $a1, $s0, 0x10
.L8002CA00:
/* 7E00 8002CA00 26730006 */  addiu     $s3, $s3, 6
/* 7E04 8002CA04 2631FFFF */  addiu     $s1, $s1, -1
/* 7E08 8002CA08 1E20FFF4 */  bgtz      $s1, .L8002C9DC
/* 7E0C 8002CA0C 26520001 */   addiu    $s2, $s2, 1
.L8002CA10:
/* 7E10 8002CA10 8FBF0128 */  lw        $ra, 0x128($sp)
/* 7E14 8002CA14 8FB50124 */  lw        $s5, 0x124($sp)
/* 7E18 8002CA18 8FB40120 */  lw        $s4, 0x120($sp)
/* 7E1C 8002CA1C 8FB3011C */  lw        $s3, 0x11c($sp)
/* 7E20 8002CA20 8FB20118 */  lw        $s2, 0x118($sp)
/* 7E24 8002CA24 8FB10114 */  lw        $s1, 0x114($sp)
/* 7E28 8002CA28 8FB00110 */  lw        $s0, 0x110($sp)
/* 7E2C 8002CA2C 03E00008 */  jr        $ra
/* 7E30 8002CA30 27BD0130 */   addiu    $sp, $sp, 0x130
/* 7E34 8002CA34 00000000 */  nop       
/* 7E38 8002CA38 00000000 */  nop       
/* 7E3C 8002CA3C 00000000 */  nop       
