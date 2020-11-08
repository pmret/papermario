.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011E438
/* B4B38 8011E438 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B4B3C 8011E43C AFB00010 */  sw        $s0, 0x10($sp)
/* B4B40 8011E440 0080802D */  daddu     $s0, $a0, $zero
/* B4B44 8011E444 AFBF0014 */  sw        $ra, 0x14($sp)
/* B4B48 8011E448 8E040010 */  lw        $a0, 0x10($s0)
/* B4B4C 8011E44C 10800016 */  beqz      $a0, .L8011E4A8
/* B4B50 8011E450 A2000014 */   sb       $zero, 0x14($s0)
/* B4B54 8011E454 0C0478E6 */  jal       func_8011E398
/* B4B58 8011E458 00000000 */   nop      
/* B4B5C 8011E45C 3C038015 */  lui       $v1, %hi(gCurrentAnimMeshListPtr)
/* B4B60 8011E460 8C633A40 */  lw        $v1, %lo(gCurrentAnimMeshListPtr)($v1)
/* B4B64 8011E464 0000202D */  daddu     $a0, $zero, $zero
/* B4B68 8011E468 AE000010 */  sw        $zero, 0x10($s0)
.L8011E46C:
/* B4B6C 8011E46C 8C620000 */  lw        $v0, ($v1)
/* B4B70 8011E470 14500003 */  bne       $v0, $s0, .L8011E480
/* B4B74 8011E474 24840001 */   addiu    $a0, $a0, 1
/* B4B78 8011E478 08047923 */  j         .L8011E48C
/* B4B7C 8011E47C AC600000 */   sw       $zero, ($v1)
.L8011E480:
/* B4B80 8011E480 28820010 */  slti      $v0, $a0, 0x10
/* B4B84 8011E484 1440FFF9 */  bnez      $v0, .L8011E46C
/* B4B88 8011E488 24630004 */   addiu    $v1, $v1, 4
.L8011E48C:
/* B4B8C 8011E48C 0C00AB4B */  jal       heap_free
/* B4B90 8011E490 0200202D */   daddu    $a0, $s0, $zero
/* B4B94 8011E494 3C038015 */  lui       $v1, 0x8015
/* B4B98 8011E498 246312D4 */  addiu     $v1, $v1, 0x12d4
/* B4B9C 8011E49C 8C620000 */  lw        $v0, ($v1)
/* B4BA0 8011E4A0 2442FFFF */  addiu     $v0, $v0, -1
/* B4BA4 8011E4A4 AC620000 */  sw        $v0, ($v1)
.L8011E4A8:
/* B4BA8 8011E4A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4BAC 8011E4AC 8FB00010 */  lw        $s0, 0x10($sp)
/* B4BB0 8011E4B0 03E00008 */  jr        $ra
/* B4BB4 8011E4B4 27BD0018 */   addiu    $sp, $sp, 0x18
