.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011D72C
/* B3E2C 8011D72C 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* B3E30 8011D730 AFB200C8 */  sw        $s2, 0xc8($sp)
/* B3E34 8011D734 0080902D */  daddu     $s2, $a0, $zero
/* B3E38 8011D738 30A4FFFF */  andi      $a0, $a1, 0xffff
/* B3E3C 8011D73C AFBF00D0 */  sw        $ra, 0xd0($sp)
/* B3E40 8011D740 AFB300CC */  sw        $s3, 0xcc($sp)
/* B3E44 8011D744 AFB100C4 */  sw        $s1, 0xc4($sp)
/* B3E48 8011D748 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B3E4C 8011D74C AFB000C0 */   sw       $s0, 0xc0($sp)
/* B3E50 8011D750 0C046B4C */  jal       get_model_from_list_index
/* B3E54 8011D754 0040202D */   daddu    $a0, $v0, $zero
/* B3E58 8011D758 27A30010 */  addiu     $v1, $sp, 0x10
/* B3E5C 8011D75C 244400B0 */  addiu     $a0, $v0, 0xb0
.L8011D760:
/* B3E60 8011D760 8C460000 */  lw        $a2, ($v0)
/* B3E64 8011D764 8C470004 */  lw        $a3, 4($v0)
/* B3E68 8011D768 8C480008 */  lw        $t0, 8($v0)
/* B3E6C 8011D76C 8C49000C */  lw        $t1, 0xc($v0)
/* B3E70 8011D770 AC660000 */  sw        $a2, ($v1)
/* B3E74 8011D774 AC670004 */  sw        $a3, 4($v1)
/* B3E78 8011D778 AC680008 */  sw        $t0, 8($v1)
/* B3E7C 8011D77C AC69000C */  sw        $t1, 0xc($v1)
/* B3E80 8011D780 24420010 */  addiu     $v0, $v0, 0x10
/* B3E84 8011D784 1444FFF6 */  bne       $v0, $a0, .L8011D760
/* B3E88 8011D788 24630010 */   addiu    $v1, $v1, 0x10
/* B3E8C 8011D78C 3C10800A */  lui       $s0, %hi(D_8009A66C)
/* B3E90 8011D790 2610A66C */  addiu     $s0, $s0, %lo(D_8009A66C)
/* B3E94 8011D794 8E420000 */  lw        $v0, ($s2)
/* B3E98 8011D798 8E110000 */  lw        $s1, ($s0)
/* B3E9C 8011D79C 50510001 */  beql      $v0, $s1, .L8011D7A4
/* B3EA0 8011D7A0 24130001 */   addiu    $s3, $zero, 1
.L8011D7A4:
/* B3EA4 8011D7A4 27A40010 */  addiu     $a0, $sp, 0x10
/* B3EA8 8011D7A8 AE020000 */  sw        $v0, ($s0)
/* B3EAC 8011D7AC 24020081 */  addiu     $v0, $zero, 0x81
/* B3EB0 8011D7B0 0C044C24 */  jal       appendGfx_model
/* B3EB4 8011D7B4 A7A20010 */   sh       $v0, 0x10($sp)
/* B3EB8 8011D7B8 8E020000 */  lw        $v0, ($s0)
/* B3EBC 8011D7BC 16600002 */  bnez      $s3, .L8011D7C8
/* B3EC0 8011D7C0 AE420000 */   sw       $v0, ($s2)
/* B3EC4 8011D7C4 AE110000 */  sw        $s1, ($s0)
.L8011D7C8:
/* B3EC8 8011D7C8 8FBF00D0 */  lw        $ra, 0xd0($sp)
/* B3ECC 8011D7CC 8FB300CC */  lw        $s3, 0xcc($sp)
/* B3ED0 8011D7D0 8FB200C8 */  lw        $s2, 0xc8($sp)
/* B3ED4 8011D7D4 8FB100C4 */  lw        $s1, 0xc4($sp)
/* B3ED8 8011D7D8 8FB000C0 */  lw        $s0, 0xc0($sp)
/* B3EDC 8011D7DC 03E00008 */  jr        $ra
/* B3EE0 8011D7E0 27BD00D8 */   addiu    $sp, $sp, 0xd8
