.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D7FC
/* 28BFC 8004D7FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 28C00 8004D800 AFB3001C */  sw        $s3, 0x1c($sp)
/* 28C04 8004D804 0080982D */  daddu     $s3, $a0, $zero
/* 28C08 8004D808 AFB20018 */  sw        $s2, 0x18($sp)
/* 28C0C 8004D80C AFBF0024 */  sw        $ra, 0x24($sp)
/* 28C10 8004D810 AFB40020 */  sw        $s4, 0x20($sp)
/* 28C14 8004D814 AFB10014 */  sw        $s1, 0x14($sp)
/* 28C18 8004D818 AFB00010 */  sw        $s0, 0x10($sp)
/* 28C1C 8004D81C 8E700000 */  lw        $s0, ($s3)
/* 28C20 8004D820 8E710004 */  lw        $s1, 4($s3)
/* 28C24 8004D824 9674000E */  lhu       $s4, 0xe($s3)
/* 28C28 8004D828 12000037 */  beqz      $s0, .L8004D908
/* 28C2C 8004D82C 0000902D */   daddu    $s2, $zero, $zero
/* 28C30 8004D830 2622FF06 */  addiu     $v0, $s1, -0xfa
/* 28C34 8004D834 2C422617 */  sltiu     $v0, $v0, 0x2617
/* 28C38 8004D838 50400034 */  beql      $v0, $zero, .L8004D90C
/* 28C3C 8004D83C 24120004 */   addiu    $s2, $zero, 4
/* 28C40 8004D840 0C013511 */  jal       func_8004D444
/* 28C44 8004D844 0200202D */   daddu    $a0, $s0, $zero
/* 28C48 8004D848 0040282D */  daddu     $a1, $v0, $zero
/* 28C4C 8004D84C 50A0002F */  beql      $a1, $zero, .L8004D90C
/* 28C50 8004D850 24120002 */   addiu    $s2, $zero, 2
/* 28C54 8004D854 8CA6001C */  lw        $a2, 0x1c($a1)
/* 28C58 8004D858 14D0002D */  bne       $a2, $s0, .L8004D910
/* 28C5C 8004D85C 0240102D */   daddu    $v0, $s2, $zero
/* 28C60 8004D860 90A20221 */  lbu       $v0, 0x221($a1)
/* 28C64 8004D864 1040002A */  beqz      $v0, .L8004D910
/* 28C68 8004D868 0240102D */   daddu    $v0, $s2, $zero
/* 28C6C 8004D86C 90A20220 */  lbu       $v0, 0x220($a1)
/* 28C70 8004D870 14400027 */  bnez      $v0, .L8004D910
/* 28C74 8004D874 0240102D */   daddu    $v0, $s2, $zero
/* 28C78 8004D878 00111140 */  sll       $v0, $s1, 5
/* 28C7C 8004D87C 00511023 */  subu      $v0, $v0, $s1
/* 28C80 8004D880 00021080 */  sll       $v0, $v0, 2
/* 28C84 8004D884 00511021 */  addu      $v0, $v0, $s1
/* 28C88 8004D888 000210C0 */  sll       $v0, $v0, 3
/* 28C8C 8004D88C 3C03B65C */  lui       $v1, 0xb65c
/* 28C90 8004D890 34636D59 */  ori       $v1, $v1, 0x6d59
/* 28C94 8004D894 00430019 */  multu     $v0, $v1
/* 28C98 8004D898 8CA2002C */  lw        $v0, 0x2c($a1)
/* 28C9C 8004D89C 00001810 */  mfhi      $v1
/* 28CA0 8004D8A0 00032302 */  srl       $a0, $v1, 0xc
/* 28CA4 8004D8A4 00141C00 */  sll       $v1, $s4, 0x10
/* 28CA8 8004D8A8 00621823 */  subu      $v1, $v1, $v0
/* 28CAC 8004D8AC 00041400 */  sll       $v0, $a0, 0x10
/* 28CB0 8004D8B0 00021403 */  sra       $v0, $v0, 0x10
/* 28CB4 8004D8B4 14400002 */  bnez      $v0, .L8004D8C0
/* 28CB8 8004D8B8 0062001A */   div      $zero, $v1, $v0
/* 28CBC 8004D8BC 0007000D */  break     7
.L8004D8C0:
/* 28CC0 8004D8C0 2401FFFF */   addiu    $at, $zero, -1
/* 28CC4 8004D8C4 14410004 */  bne       $v0, $at, .L8004D8D8
/* 28CC8 8004D8C8 3C018000 */   lui      $at, 0x8000
/* 28CCC 8004D8CC 14610002 */  bne       $v1, $at, .L8004D8D8
/* 28CD0 8004D8D0 00000000 */   nop
/* 28CD4 8004D8D4 0006000D */  break     6
.L8004D8D8:
/* 28CD8 8004D8D8 00001812 */   mflo     $v1
/* 28CDC 8004D8DC A4B40034 */  sh        $s4, 0x34($a1)
/* 28CE0 8004D8E0 A4A40036 */  sh        $a0, 0x36($a1)
/* 28CE4 8004D8E4 ACA30030 */  sw        $v1, 0x30($a1)
/* 28CE8 8004D8E8 8E620010 */  lw        $v0, 0x10($s3)
/* 28CEC 8004D8EC ACA20038 */  sw        $v0, 0x38($a1)
/* 28CF0 8004D8F0 8E630014 */  lw        $v1, 0x14($s3)
/* 28CF4 8004D8F4 24020001 */  addiu     $v0, $zero, 1
/* 28CF8 8004D8F8 50620004 */  beql      $v1, $v0, .L8004D90C
/* 28CFC 8004D8FC ACA60020 */   sw       $a2, 0x20($a1)
/* 28D00 8004D900 08013644 */  j         .L8004D910
/* 28D04 8004D904 0240102D */   daddu    $v0, $s2, $zero
.L8004D908:
/* 28D08 8004D908 24120003 */  addiu     $s2, $zero, 3
.L8004D90C:
/* 28D0C 8004D90C 0240102D */  daddu     $v0, $s2, $zero
.L8004D910:
/* 28D10 8004D910 8FBF0024 */  lw        $ra, 0x24($sp)
/* 28D14 8004D914 8FB40020 */  lw        $s4, 0x20($sp)
/* 28D18 8004D918 8FB3001C */  lw        $s3, 0x1c($sp)
/* 28D1C 8004D91C 8FB20018 */  lw        $s2, 0x18($sp)
/* 28D20 8004D920 8FB10014 */  lw        $s1, 0x14($sp)
/* 28D24 8004D924 8FB00010 */  lw        $s0, 0x10($sp)
/* 28D28 8004D928 03E00008 */  jr        $ra
/* 28D2C 8004D92C 27BD0028 */   addiu    $sp, $sp, 0x28
