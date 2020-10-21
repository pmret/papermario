.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB8_7EBCC8
/* 7EBCC8 80240FB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EBCCC 80240FBC 10A0000B */  beqz      $a1, .L80240FEC
/* 7EBCD0 80240FC0 AFBF0010 */   sw       $ra, 0x10($sp)
/* 7EBCD4 80240FC4 3C038025 */  lui       $v1, 0x8025
/* 7EBCD8 80240FC8 8C635B94 */  lw        $v1, 0x5b94($v1)
/* 7EBCDC 80240FCC 8C620000 */  lw        $v0, ($v1)
/* 7EBCE0 80240FD0 3C048025 */  lui       $a0, 0x8025
/* 7EBCE4 80240FD4 8C845B98 */  lw        $a0, 0x5b98($a0)
/* 7EBCE8 80240FD8 34420010 */  ori       $v0, $v0, 0x10
/* 7EBCEC 80240FDC AC620000 */  sw        $v0, ($v1)
/* 7EBCF0 80240FE0 8C820000 */  lw        $v0, ($a0)
/* 7EBCF4 80240FE4 34420010 */  ori       $v0, $v0, 0x10
/* 7EBCF8 80240FE8 AC820000 */  sw        $v0, ($a0)
.L80240FEC:
/* 7EBCFC 80240FEC 3C048025 */  lui       $a0, 0x8025
/* 7EBD00 80240FF0 8C845B90 */  lw        $a0, 0x5b90($a0)
/* 7EBD04 80240FF4 8C85000C */  lw        $a1, 0xc($a0)
/* 7EBD08 80240FF8 8CA20018 */  lw        $v0, 0x18($a1)
/* 7EBD0C 80240FFC 8CA30020 */  lw        $v1, 0x20($a1)
/* 7EBD10 80241000 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 7EBD14 80241004 ACA20018 */  sw        $v0, 0x18($a1)
/* 7EBD18 80241008 8CA20024 */  lw        $v0, 0x24($a1)
/* 7EBD1C 8024100C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 7EBD20 80241010 ACA30020 */  sw        $v1, 0x20($a1)
/* 7EBD24 80241014 8CA30028 */  lw        $v1, 0x28($a1)
/* 7EBD28 80241018 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 7EBD2C 8024101C ACA20024 */  sw        $v0, 0x24($a1)
/* 7EBD30 80241020 8CA2001C */  lw        $v0, 0x1c($a1)
/* 7EBD34 80241024 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 7EBD38 80241028 ACA30028 */  sw        $v1, 0x28($a1)
/* 7EBD3C 8024102C 8CA30018 */  lw        $v1, 0x18($a1)
/* 7EBD40 80241030 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 7EBD44 80241034 18600003 */  blez      $v1, .L80241044
/* 7EBD48 80241038 ACA2001C */   sw       $v0, 0x1c($a1)
/* 7EBD4C 8024103C 08090418 */  j         .L80241060
/* 7EBD50 80241040 0000102D */   daddu    $v0, $zero, $zero
.L80241044:
/* 7EBD54 80241044 0C016914 */  jal       remove_effect
/* 7EBD58 80241048 ACA00018 */   sw       $zero, 0x18($a1)
/* 7EBD5C 8024104C 3C048025 */  lui       $a0, 0x8025
/* 7EBD60 80241050 8C845B70 */  lw        $a0, 0x5b70($a0)
/* 7EBD64 80241054 0C048D70 */  jal       func_801235C0
/* 7EBD68 80241058 00000000 */   nop      
/* 7EBD6C 8024105C 24020002 */  addiu     $v0, $zero, 2
.L80241060:
/* 7EBD70 80241060 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EBD74 80241064 03E00008 */  jr        $ra
/* 7EBD78 80241068 27BD0018 */   addiu    $sp, $sp, 0x18
