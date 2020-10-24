.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DE8_8439B8
/* 8439B8 80240DE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8439BC 80240DEC 10A0000B */  beqz      $a1, .L80240E1C
/* 8439C0 80240DF0 AFBF0010 */   sw       $ra, 0x10($sp)
/* 8439C4 80240DF4 3C038025 */  lui       $v1, 0x8025
/* 8439C8 80240DF8 8C63F5C4 */  lw        $v1, -0xa3c($v1)
/* 8439CC 80240DFC 8C620000 */  lw        $v0, ($v1)
/* 8439D0 80240E00 3C048025 */  lui       $a0, 0x8025
/* 8439D4 80240E04 8C84F5C8 */  lw        $a0, -0xa38($a0)
/* 8439D8 80240E08 34420010 */  ori       $v0, $v0, 0x10
/* 8439DC 80240E0C AC620000 */  sw        $v0, ($v1)
/* 8439E0 80240E10 8C820000 */  lw        $v0, ($a0)
/* 8439E4 80240E14 34420010 */  ori       $v0, $v0, 0x10
/* 8439E8 80240E18 AC820000 */  sw        $v0, ($a0)
.L80240E1C:
/* 8439EC 80240E1C 3C048025 */  lui       $a0, 0x8025
/* 8439F0 80240E20 8C84F5C0 */  lw        $a0, -0xa40($a0)
/* 8439F4 80240E24 8C85000C */  lw        $a1, 0xc($a0)
/* 8439F8 80240E28 8CA20018 */  lw        $v0, 0x18($a1)
/* 8439FC 80240E2C 8CA30020 */  lw        $v1, 0x20($a1)
/* 843A00 80240E30 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 843A04 80240E34 ACA20018 */  sw        $v0, 0x18($a1)
/* 843A08 80240E38 8CA20024 */  lw        $v0, 0x24($a1)
/* 843A0C 80240E3C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 843A10 80240E40 ACA30020 */  sw        $v1, 0x20($a1)
/* 843A14 80240E44 8CA30028 */  lw        $v1, 0x28($a1)
/* 843A18 80240E48 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 843A1C 80240E4C ACA20024 */  sw        $v0, 0x24($a1)
/* 843A20 80240E50 8CA2001C */  lw        $v0, 0x1c($a1)
/* 843A24 80240E54 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 843A28 80240E58 ACA30028 */  sw        $v1, 0x28($a1)
/* 843A2C 80240E5C 8CA30018 */  lw        $v1, 0x18($a1)
/* 843A30 80240E60 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 843A34 80240E64 18600003 */  blez      $v1, .L80240E74
/* 843A38 80240E68 ACA2001C */   sw       $v0, 0x1c($a1)
/* 843A3C 80240E6C 080903A4 */  j         .L80240E90
/* 843A40 80240E70 0000102D */   daddu    $v0, $zero, $zero
.L80240E74:
/* 843A44 80240E74 0C016914 */  jal       remove_effect
/* 843A48 80240E78 ACA00018 */   sw       $zero, 0x18($a1)
/* 843A4C 80240E7C 3C048025 */  lui       $a0, 0x8025
/* 843A50 80240E80 8C84F5A0 */  lw        $a0, -0xa60($a0)
/* 843A54 80240E84 0C048D70 */  jal       func_801235C0
/* 843A58 80240E88 00000000 */   nop      
/* 843A5C 80240E8C 24020002 */  addiu     $v0, $zero, 2
.L80240E90:
/* 843A60 80240E90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 843A64 80240E94 03E00008 */  jr        $ra
/* 843A68 80240E98 27BD0018 */   addiu    $sp, $sp, 0x18
