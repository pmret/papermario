.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011800C
/* AE70C 8011800C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AE710 80118010 0080282D */  daddu     $a1, $a0, $zero
/* AE714 80118014 AFB10014 */  sw        $s1, 0x14($sp)
/* AE718 80118018 00A0882D */  daddu     $s1, $a1, $zero
/* AE71C 8011801C AFB00010 */  sw        $s0, 0x10($sp)
/* AE720 80118020 3C10800A */  lui       $s0, %hi(D_8009A66C)
/* AE724 80118024 2610A66C */  addiu     $s0, $s0, %lo(D_8009A66C)
/* AE728 80118028 AFBF001C */  sw        $ra, 0x1c($sp)
/* AE72C 8011802C AFB20018 */  sw        $s2, 0x18($sp)
/* AE730 80118030 94A20000 */  lhu       $v0, ($a1)
/* AE734 80118034 30420004 */  andi      $v0, $v0, 4
/* AE738 80118038 14400025 */  bnez      $v0, .L801180D0
/* AE73C 8011803C 0200902D */   daddu    $s2, $s0, $zero
/* AE740 80118040 94A20000 */  lhu       $v0, ($a1)
/* AE744 80118044 90A3009C */  lbu       $v1, 0x9c($a1)
/* AE748 80118048 30422000 */  andi      $v0, $v0, 0x2000
/* AE74C 8011804C 3C018015 */  lui       $at, %hi(D_8015336C)
/* AE750 80118050 A423336C */  sh        $v1, %lo(D_8015336C)($at)
/* AE754 80118054 14400009 */  bnez      $v0, .L8011807C
/* AE758 80118058 3C03DA38 */   lui      $v1, 0xda38
/* AE75C 8011805C 8E020000 */  lw        $v0, ($s0)
/* AE760 80118060 34630002 */  ori       $v1, $v1, 2
/* AE764 80118064 0040202D */  daddu     $a0, $v0, $zero
/* AE768 80118068 AC830000 */  sw        $v1, ($a0)
/* AE76C 8011806C 8CA3000C */  lw        $v1, 0xc($a1)
/* AE770 80118070 24420008 */  addiu     $v0, $v0, 8
/* AE774 80118074 AE020000 */  sw        $v0, ($s0)
/* AE778 80118078 AC830004 */  sw        $v1, 4($a0)
.L8011807C:
/* AE77C 8011807C 0C045F9D */  jal       func_80117E74
/* AE780 80118080 8E240008 */   lw       $a0, 8($s1)
/* AE784 80118084 96220000 */  lhu       $v0, ($s1)
/* AE788 80118088 30422000 */  andi      $v0, $v0, 0x2000
/* AE78C 8011808C 14400009 */  bnez      $v0, .L801180B4
/* AE790 80118090 3C04D838 */   lui      $a0, 0xd838
/* AE794 80118094 8E020000 */  lw        $v0, ($s0)
/* AE798 80118098 34840002 */  ori       $a0, $a0, 2
/* AE79C 8011809C 0040182D */  daddu     $v1, $v0, $zero
/* AE7A0 801180A0 24420008 */  addiu     $v0, $v0, 8
/* AE7A4 801180A4 AE020000 */  sw        $v0, ($s0)
/* AE7A8 801180A8 24020040 */  addiu     $v0, $zero, 0x40
/* AE7AC 801180AC AC640000 */  sw        $a0, ($v1)
/* AE7B0 801180B0 AC620004 */  sw        $v0, 4($v1)
.L801180B4:
/* AE7B4 801180B4 8E420000 */  lw        $v0, ($s2)
/* AE7B8 801180B8 0040182D */  daddu     $v1, $v0, $zero
/* AE7BC 801180BC 24420008 */  addiu     $v0, $v0, 8
/* AE7C0 801180C0 AE420000 */  sw        $v0, ($s2)
/* AE7C4 801180C4 3C02E700 */  lui       $v0, 0xe700
/* AE7C8 801180C8 AC620000 */  sw        $v0, ($v1)
/* AE7CC 801180CC AC600004 */  sw        $zero, 4($v1)
.L801180D0:
/* AE7D0 801180D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* AE7D4 801180D4 8FB20018 */  lw        $s2, 0x18($sp)
/* AE7D8 801180D8 8FB10014 */  lw        $s1, 0x14($sp)
/* AE7DC 801180DC 8FB00010 */  lw        $s0, 0x10($sp)
/* AE7E0 801180E0 03E00008 */  jr        $ra
/* AE7E4 801180E4 27BD0020 */   addiu    $sp, $sp, 0x20
