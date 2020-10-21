.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F9C_B2E40C
/* B2E40C 80241F9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2E410 80241FA0 10A0000B */  beqz      $a1, .L80241FD0
/* B2E414 80241FA4 AFBF0010 */   sw       $ra, 0x10($sp)
/* B2E418 80241FA8 3C038025 */  lui       $v1, 0x8025
/* B2E41C 80241FAC 8C638944 */  lw        $v1, -0x76bc($v1)
/* B2E420 80241FB0 8C620000 */  lw        $v0, ($v1)
/* B2E424 80241FB4 3C048025 */  lui       $a0, 0x8025
/* B2E428 80241FB8 8C848948 */  lw        $a0, -0x76b8($a0)
/* B2E42C 80241FBC 34420010 */  ori       $v0, $v0, 0x10
/* B2E430 80241FC0 AC620000 */  sw        $v0, ($v1)
/* B2E434 80241FC4 8C820000 */  lw        $v0, ($a0)
/* B2E438 80241FC8 34420010 */  ori       $v0, $v0, 0x10
/* B2E43C 80241FCC AC820000 */  sw        $v0, ($a0)
.L80241FD0:
/* B2E440 80241FD0 3C048025 */  lui       $a0, 0x8025
/* B2E444 80241FD4 8C848940 */  lw        $a0, -0x76c0($a0)
/* B2E448 80241FD8 8C85000C */  lw        $a1, 0xc($a0)
/* B2E44C 80241FDC 8CA20018 */  lw        $v0, 0x18($a1)
/* B2E450 80241FE0 8CA30020 */  lw        $v1, 0x20($a1)
/* B2E454 80241FE4 2442FFF6 */  addiu     $v0, $v0, -0xa
/* B2E458 80241FE8 ACA20018 */  sw        $v0, 0x18($a1)
/* B2E45C 80241FEC 8CA20024 */  lw        $v0, 0x24($a1)
/* B2E460 80241FF0 2463FFF6 */  addiu     $v1, $v1, -0xa
/* B2E464 80241FF4 ACA30020 */  sw        $v1, 0x20($a1)
/* B2E468 80241FF8 8CA30028 */  lw        $v1, 0x28($a1)
/* B2E46C 80241FFC 2442FFF6 */  addiu     $v0, $v0, -0xa
/* B2E470 80242000 ACA20024 */  sw        $v0, 0x24($a1)
/* B2E474 80242004 8CA2001C */  lw        $v0, 0x1c($a1)
/* B2E478 80242008 2463FFF6 */  addiu     $v1, $v1, -0xa
/* B2E47C 8024200C ACA30028 */  sw        $v1, 0x28($a1)
/* B2E480 80242010 8CA30018 */  lw        $v1, 0x18($a1)
/* B2E484 80242014 2442FFF6 */  addiu     $v0, $v0, -0xa
/* B2E488 80242018 18600003 */  blez      $v1, .L80242028
/* B2E48C 8024201C ACA2001C */   sw       $v0, 0x1c($a1)
/* B2E490 80242020 08090811 */  j         .L80242044
/* B2E494 80242024 0000102D */   daddu    $v0, $zero, $zero
.L80242028:
/* B2E498 80242028 0C016914 */  jal       remove_effect
/* B2E49C 8024202C ACA00018 */   sw       $zero, 0x18($a1)
/* B2E4A0 80242030 3C048025 */  lui       $a0, 0x8025
/* B2E4A4 80242034 8C848924 */  lw        $a0, -0x76dc($a0)
/* B2E4A8 80242038 0C048D70 */  jal       func_801235C0
/* B2E4AC 8024203C 00000000 */   nop      
/* B2E4B0 80242040 24020002 */  addiu     $v0, $zero, 2
.L80242044:
/* B2E4B4 80242044 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2E4B8 80242048 03E00008 */  jr        $ra
/* B2E4BC 8024204C 27BD0018 */   addiu    $sp, $sp, 0x18
