.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel crash_create_monitor
/* 007CB0 8002C8B0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 007CB4 8002C8B4 3C07FFFD */  lui   $a3, 0xfffd
/* 007CB8 8002C8B8 34E7A800 */  ori   $a3, $a3, 0xa800
/* 007CBC 8002C8BC AFB00018 */  sw    $s0, 0x18($sp)
/* 007CC0 8002C8C0 3C10800A */  lui   $s0, 0x800a
/* 007CC4 8002C8C4 2610BB30 */  addiu $s0, $s0, -0x44d0
/* 007CC8 8002C8C8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 007CCC 8002C8CC 261109B0 */  addiu $s1, $s0, 0x9b0
/* 007CD0 8002C8D0 0220202D */  daddu $a0, $s1, $zero
/* 007CD4 8002C8D4 260509C8 */  addiu $a1, $s0, 0x9c8
/* 007CD8 8002C8D8 24060001 */  addiu $a2, $zero, 1
/* 007CDC 8002C8DC 24020140 */  addiu $v0, $zero, 0x140
/* 007CE0 8002C8E0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 007CE4 8002C8E4 A60209D0 */  sh    $v0, 0x9d0($s0)
/* 007CE8 8002C8E8 24020010 */  addiu $v0, $zero, 0x10
/* 007CEC 8002C8EC A60209D2 */  sh    $v0, 0x9d2($s0)
/* 007CF0 8002C8F0 3C028000 */  lui   $v0, 0x8000
/* 007CF4 8002C8F4 8C420318 */  lw    $v0, 0x318($v0)
/* 007CF8 8002C8F8 3C03A000 */  lui   $v1, 0xa000
/* 007CFC 8002C8FC 00431025 */  or    $v0, $v0, $v1
/* 007D00 8002C900 00471021 */  addu  $v0, $v0, $a3
/* 007D04 8002C904 0C019560 */  jal   osCreateMesgQueue
/* 007D08 8002C908 AE0209CC */   sw    $v0, 0x9cc($s0)
/* 007D0C 8002C90C 0200202D */  daddu $a0, $s0, $zero
/* 007D10 8002C910 24050002 */  addiu $a1, $zero, 2
/* 007D14 8002C914 3C068003 */  lui   $a2, 0x8003
/* 007D18 8002C918 24C6C81C */  addiu $a2, $a2, -0x37e4
/* 007D1C 8002C91C 24020080 */  addiu $v0, $zero, 0x80
/* 007D20 8002C920 0000382D */  daddu $a3, $zero, $zero
/* 007D24 8002C924 AFB10010 */  sw    $s1, 0x10($sp)
/* 007D28 8002C928 0C019798 */  jal   osCreateThread
/* 007D2C 8002C92C AFA20014 */   sw    $v0, 0x14($sp)
/* 007D30 8002C930 0C019808 */  jal   osStartThread
/* 007D34 8002C934 0200202D */   daddu $a0, $s0, $zero
/* 007D38 8002C938 8FBF0020 */  lw    $ra, 0x20($sp)
/* 007D3C 8002C93C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 007D40 8002C940 8FB00018 */  lw    $s0, 0x18($sp)
/* 007D44 8002C944 03E00008 */  jr    $ra
/* 007D48 8002C948 27BD0028 */   addiu $sp, $sp, 0x28

/* 007D4C 8002C94C AFA60008 */  sw    $a2, 8($sp)
/* 007D50 8002C950 AFA7000C */  sw    $a3, 0xc($sp)
/* 007D54 8002C954 27BDFED0 */  addiu $sp, $sp, -0x130
/* 007D58 8002C958 AFB20118 */  sw    $s2, 0x118($sp)
/* 007D5C 8002C95C 0080902D */  daddu $s2, $a0, $zero
/* 007D60 8002C960 AFB00110 */  sw    $s0, 0x110($sp)
/* 007D64 8002C964 00A0802D */  daddu $s0, $a1, $zero
/* 007D68 8002C968 AFB3011C */  sw    $s3, 0x11c($sp)
/* 007D6C 8002C96C 0240982D */  daddu $s3, $s2, $zero
/* 007D70 8002C970 3C048003 */  lui   $a0, 0x8003
/* 007D74 8002C974 2484C1D4 */  addiu $a0, $a0, -0x3e2c
/* 007D78 8002C978 27A50010 */  addiu $a1, $sp, 0x10
/* 007D7C 8002C97C 27A7013C */  addiu $a3, $sp, 0x13c
/* 007D80 8002C980 AFBF0128 */  sw    $ra, 0x128($sp)
/* 007D84 8002C984 AFB50124 */  sw    $s5, 0x124($sp)
/* 007D88 8002C988 AFB40120 */  sw    $s4, 0x120($sp)
/* 007D8C 8002C98C 0C0192A8 */  jal   _Printf
/* 007D90 8002C990 AFB10114 */   sw    $s1, 0x114($sp)
/* 007D94 8002C994 0040882D */  daddu $s1, $v0, $zero
/* 007D98 8002C998 1A20001D */  blez  $s1, .L8002CA10
/* 007D9C 8002C99C 00122400 */   sll   $a0, $s2, 0x10
/* 007DA0 8002C9A0 00042403 */  sra   $a0, $a0, 0x10
/* 007DA4 8002C9A4 2484FFFA */  addiu $a0, $a0, -6
/* 007DA8 8002C9A8 00108400 */  sll   $s0, $s0, 0x10
/* 007DAC 8002C9AC 00102C03 */  sra   $a1, $s0, 0x10
/* 007DB0 8002C9B0 24A5FFFA */  addiu $a1, $a1, -6
/* 007DB4 8002C9B4 26220002 */  addiu $v0, $s1, 2
/* 007DB8 8002C9B8 00023040 */  sll   $a2, $v0, 1
/* 007DBC 8002C9BC 00C23021 */  addu  $a2, $a2, $v0
/* 007DC0 8002C9C0 00063040 */  sll   $a2, $a2, 1
/* 007DC4 8002C9C4 0C00AFEC */  jal   func_8002BFB0
/* 007DC8 8002C9C8 24070013 */   addiu $a3, $zero, 0x13
/* 007DCC 8002C9CC 27B20010 */  addiu $s2, $sp, 0x10
/* 007DD0 8002C9D0 3C158007 */  lui   $s5, 0x8007
/* 007DD4 8002C9D4 26B57210 */  addiu $s5, $s5, 0x7210
/* 007DD8 8002C9D8 241400FF */  addiu $s4, $zero, 0xff
.L8002C9DC:
/* 007DDC 8002C9DC 92420000 */  lbu   $v0, ($s2)
/* 007DE0 8002C9E0 3042007F */  andi  $v0, $v0, 0x7f
/* 007DE4 8002C9E4 00551021 */  addu  $v0, $v0, $s5
/* 007DE8 8002C9E8 90460000 */  lbu   $a2, ($v0)
/* 007DEC 8002C9EC 10D40004 */  beq   $a2, $s4, .L8002CA00
/* 007DF0 8002C9F0 00132400 */   sll   $a0, $s3, 0x10
/* 007DF4 8002C9F4 00042403 */  sra   $a0, $a0, 0x10
/* 007DF8 8002C9F8 0C00B015 */  jal   func_8002C054
/* 007DFC 8002C9FC 00102C03 */   sra   $a1, $s0, 0x10
.L8002CA00:
/* 007E00 8002CA00 26730006 */  addiu $s3, $s3, 6
/* 007E04 8002CA04 2631FFFF */  addiu $s1, $s1, -1
/* 007E08 8002CA08 1E20FFF4 */  bgtz  $s1, .L8002C9DC
/* 007E0C 8002CA0C 26520001 */   addiu $s2, $s2, 1
.L8002CA10:
/* 007E10 8002CA10 8FBF0128 */  lw    $ra, 0x128($sp)
/* 007E14 8002CA14 8FB50124 */  lw    $s5, 0x124($sp)
/* 007E18 8002CA18 8FB40120 */  lw    $s4, 0x120($sp)
/* 007E1C 8002CA1C 8FB3011C */  lw    $s3, 0x11c($sp)
/* 007E20 8002CA20 8FB20118 */  lw    $s2, 0x118($sp)
/* 007E24 8002CA24 8FB10114 */  lw    $s1, 0x114($sp)
/* 007E28 8002CA28 8FB00110 */  lw    $s0, 0x110($sp)
/* 007E2C 8002CA2C 03E00008 */  jr    $ra
/* 007E30 8002CA30 27BD0130 */   addiu $sp, $sp, 0x130

/* 007E34 8002CA34 00000000 */  nop   
/* 007E38 8002CA38 00000000 */  nop   
/* 007E3C 8002CA3C 00000000 */  nop   

.set reorder
