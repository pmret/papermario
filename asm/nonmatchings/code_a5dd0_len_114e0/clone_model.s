.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clone_model
/* B1DF0 8011B6F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B1DF4 8011B6F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* B1DF8 8011B6F8 00A0982D */  daddu     $s3, $a1, $zero
/* B1DFC 8011B6FC 3084FFFF */  andi      $a0, $a0, 0xffff
/* B1E00 8011B700 AFBF0020 */  sw        $ra, 0x20($sp)
/* B1E04 8011B704 AFB20018 */  sw        $s2, 0x18($sp)
/* B1E08 8011B708 AFB10014 */  sw        $s1, 0x14($sp)
/* B1E0C 8011B70C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B1E10 8011B710 AFB00010 */   sw       $s0, 0x10($sp)
/* B1E14 8011B714 0C046B4C */  jal       get_model_from_list_index
/* B1E18 8011B718 0040202D */   daddu    $a0, $v0, $zero
/* B1E1C 8011B71C 0040882D */  daddu     $s1, $v0, $zero
/* B1E20 8011B720 0000802D */  daddu     $s0, $zero, $zero
/* B1E24 8011B724 3C128015 */  lui       $s2, %hi(gCurrentModelListPtr)
/* B1E28 8011B728 265212CC */  addiu     $s2, $s2, %lo(gCurrentModelListPtr)
/* B1E2C 8011B72C 8E430000 */  lw        $v1, ($s2)
.L8011B730:
/* B1E30 8011B730 8C620000 */  lw        $v0, ($v1)
/* B1E34 8011B734 10400005 */  beqz      $v0, .L8011B74C
/* B1E38 8011B738 00000000 */   nop
/* B1E3C 8011B73C 26100001 */  addiu     $s0, $s0, 1
/* B1E40 8011B740 2A020100 */  slti      $v0, $s0, 0x100
/* B1E44 8011B744 1440FFFA */  bnez      $v0, .L8011B730
/* B1E48 8011B748 24630004 */   addiu    $v1, $v1, 4
.L8011B74C:
/* B1E4C 8011B74C 0C00AB39 */  jal       heap_malloc
/* B1E50 8011B750 240400B0 */   addiu    $a0, $zero, 0xb0
/* B1E54 8011B754 0040302D */  daddu     $a2, $v0, $zero
/* B1E58 8011B758 00C0282D */  daddu     $a1, $a2, $zero
/* B1E5C 8011B75C 0220202D */  daddu     $a0, $s1, $zero
/* B1E60 8011B760 248700B0 */  addiu     $a3, $a0, 0xb0
/* B1E64 8011B764 8E430000 */  lw        $v1, ($s2)
/* B1E68 8011B768 00101080 */  sll       $v0, $s0, 2
/* B1E6C 8011B76C 00431021 */  addu      $v0, $v0, $v1
/* B1E70 8011B770 AC460000 */  sw        $a2, ($v0)
.L8011B774:
/* B1E74 8011B774 8C880000 */  lw        $t0, ($a0)
/* B1E78 8011B778 8C890004 */  lw        $t1, 4($a0)
/* B1E7C 8011B77C 8C8A0008 */  lw        $t2, 8($a0)
/* B1E80 8011B780 8C8B000C */  lw        $t3, 0xc($a0)
/* B1E84 8011B784 ACA80000 */  sw        $t0, ($a1)
/* B1E88 8011B788 ACA90004 */  sw        $t1, 4($a1)
/* B1E8C 8011B78C ACAA0008 */  sw        $t2, 8($a1)
/* B1E90 8011B790 ACAB000C */  sw        $t3, 0xc($a1)
/* B1E94 8011B794 24840010 */  addiu     $a0, $a0, 0x10
/* B1E98 8011B798 1487FFF6 */  bne       $a0, $a3, .L8011B774
/* B1E9C 8011B79C 24A50010 */   addiu    $a1, $a1, 0x10
/* B1EA0 8011B7A0 A4D30002 */  sh        $s3, 2($a2)
/* B1EA4 8011B7A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* B1EA8 8011B7A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* B1EAC 8011B7AC 8FB20018 */  lw        $s2, 0x18($sp)
/* B1EB0 8011B7B0 8FB10014 */  lw        $s1, 0x14($sp)
/* B1EB4 8011B7B4 8FB00010 */  lw        $s0, 0x10($sp)
/* B1EB8 8011B7B8 03E00008 */  jr        $ra
/* B1EBC 8011B7BC 27BD0028 */   addiu    $sp, $sp, 0x28
