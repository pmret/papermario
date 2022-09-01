.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel bcmp
/* 46C70 8006B870 00851026 */  xor       $v0, $a0, $a1
/* 46C74 8006B874 28C10010 */  slti      $at, $a2, 0x10
/* 46C78 8006B878 14200034 */  bnez      $at, .L8006B94C
/* 46C7C 8006B87C 00000000 */   nop
/* 46C80 8006B880 30420003 */  andi      $v0, $v0, 3
/* 46C84 8006B884 14400018 */  bnez      $v0, .L8006B8E8
/* 46C88 8006B888 0004C023 */   negu     $t8, $a0
/* 46C8C 8006B88C 33180003 */  andi      $t8, $t8, 3
/* 46C90 8006B890 13000007 */  beqz      $t8, .L8006B8B0
/* 46C94 8006B894 00D83023 */   subu     $a2, $a2, $t8
/* 46C98 8006B898 00601021 */  addu      $v0, $v1, $zero
/* 46C9C 8006B89C 88820000 */  lwl       $v0, ($a0)
/* 46CA0 8006B8A0 88A30000 */  lwl       $v1, ($a1)
/* 46CA4 8006B8A4 00982021 */  addu      $a0, $a0, $t8
/* 46CA8 8006B8A8 14430033 */  bne       $v0, $v1, .L8006B978
/* 46CAC 8006B8AC 00B82821 */   addu     $a1, $a1, $t8
.L8006B8B0:
/* 46CB0 8006B8B0 2401FFFC */  addiu     $at, $zero, -4
/* 46CB4 8006B8B4 00C13824 */  and       $a3, $a2, $at
/* 46CB8 8006B8B8 10E00024 */  beqz      $a3, .L8006B94C
/* 46CBC 8006B8BC 00C73023 */   subu     $a2, $a2, $a3
/* 46CC0 8006B8C0 00E43821 */  addu      $a3, $a3, $a0
.L8006B8C4:
/* 46CC4 8006B8C4 8C820000 */  lw        $v0, ($a0)
/* 46CC8 8006B8C8 8CA30000 */  lw        $v1, ($a1)
/* 46CCC 8006B8CC 24840004 */  addiu     $a0, $a0, 4
/* 46CD0 8006B8D0 14430029 */  bne       $v0, $v1, .L8006B978
/* 46CD4 8006B8D4 24A50004 */   addiu    $a1, $a1, 4
/* 46CD8 8006B8D8 1487FFFA */  bne       $a0, $a3, .L8006B8C4
/* 46CDC 8006B8DC 00000000 */   nop
/* 46CE0 8006B8E0 1000001A */  b         .L8006B94C
/* 46CE4 8006B8E4 00000000 */   nop
.L8006B8E8:
/* 46CE8 8006B8E8 00053823 */  negu      $a3, $a1
/* 46CEC 8006B8EC 30E70003 */  andi      $a3, $a3, 3
/* 46CF0 8006B8F0 10E00009 */  beqz      $a3, .L8006B918
/* 46CF4 8006B8F4 00C73023 */   subu     $a2, $a2, $a3
/* 46CF8 8006B8F8 00E43821 */  addu      $a3, $a3, $a0
.L8006B8FC:
/* 46CFC 8006B8FC 90820000 */  lbu       $v0, ($a0)
/* 46D00 8006B900 90A30000 */  lbu       $v1, ($a1)
/* 46D04 8006B904 24840001 */  addiu     $a0, $a0, 1
/* 46D08 8006B908 1443001B */  bne       $v0, $v1, .L8006B978
/* 46D0C 8006B90C 24A50001 */   addiu    $a1, $a1, 1
/* 46D10 8006B910 1487FFFA */  bne       $a0, $a3, .L8006B8FC
/* 46D14 8006B914 00000000 */   nop
.L8006B918:
/* 46D18 8006B918 2401FFFC */  addiu     $at, $zero, -4
/* 46D1C 8006B91C 00C13824 */  and       $a3, $a2, $at
/* 46D20 8006B920 10E0000A */  beqz      $a3, .L8006B94C
/* 46D24 8006B924 00C73023 */   subu     $a2, $a2, $a3
/* 46D28 8006B928 00E43821 */  addu      $a3, $a3, $a0
.L8006B92C:
/* 46D2C 8006B92C 88820000 */  lwl       $v0, ($a0)
/* 46D30 8006B930 98820003 */  lwr       $v0, 3($a0)
/* 46D34 8006B934 8CA30000 */  lw        $v1, ($a1)
/* 46D38 8006B938 24840004 */  addiu     $a0, $a0, 4
/* 46D3C 8006B93C 1443000E */  bne       $v0, $v1, .L8006B978
/* 46D40 8006B940 24A50004 */   addiu    $a1, $a1, 4
/* 46D44 8006B944 1487FFF9 */  bne       $a0, $a3, .L8006B92C
/* 46D48 8006B948 00000000 */   nop
.L8006B94C:
/* 46D4C 8006B94C 18C00008 */  blez      $a2, .L8006B970
/* 46D50 8006B950 00C43821 */   addu     $a3, $a2, $a0
.L8006B954:
/* 46D54 8006B954 90820000 */  lbu       $v0, ($a0)
/* 46D58 8006B958 90A30000 */  lbu       $v1, ($a1)
/* 46D5C 8006B95C 24840001 */  addiu     $a0, $a0, 1
/* 46D60 8006B960 14430005 */  bne       $v0, $v1, .L8006B978
/* 46D64 8006B964 24A50001 */   addiu    $a1, $a1, 1
/* 46D68 8006B968 1487FFFA */  bne       $a0, $a3, .L8006B954
/* 46D6C 8006B96C 00000000 */   nop
.L8006B970:
/* 46D70 8006B970 03E00008 */  jr        $ra
/* 46D74 8006B974 00001021 */   addu     $v0, $zero, $zero
.L8006B978:
/* 46D78 8006B978 03E00008 */  jr        $ra
/* 46D7C 8006B97C 24020001 */   addiu    $v0, $zero, 1
