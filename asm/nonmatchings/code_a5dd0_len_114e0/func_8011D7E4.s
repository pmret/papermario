.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011D7E4
/* B3EE4 8011D7E4 3C030002 */  lui       $v1, 2
/* B3EE8 8011D7E8 3C028015 */  lui       $v0, %hi(D_80153368)
/* B3EEC 8011D7EC 8C423368 */  lw        $v0, %lo(D_80153368)($v0)
/* B3EF0 8011D7F0 3C058015 */  lui       $a1, %hi(D_8014B748)
/* B3EF4 8011D7F4 8CA5B748 */  lw        $a1, %lo(D_8014B748)($a1)
/* B3EF8 8011D7F8 34638000 */  ori       $v1, $v1, 0x8000
/* B3EFC 8011D7FC 00451023 */  subu      $v0, $v0, $a1
/* B3F00 8011D800 2442003F */  addiu     $v0, $v0, 0x3f
/* B3F04 8011D804 00021182 */  srl       $v0, $v0, 6
/* B3F08 8011D808 00021180 */  sll       $v0, $v0, 6
/* B3F0C 8011D80C 00822021 */  addu      $a0, $a0, $v0
/* B3F10 8011D810 0064182B */  sltu      $v1, $v1, $a0
/* B3F14 8011D814 10600003 */  beqz      $v1, .L8011D824
/* B3F18 8011D818 00A21021 */   addu     $v0, $a1, $v0
/* B3F1C 8011D81C 03E00008 */  jr        $ra
/* B3F20 8011D820 0000102D */   daddu    $v0, $zero, $zero
.L8011D824:
/* B3F24 8011D824 03E00008 */  jr        $ra
/* B3F28 8011D828 00000000 */   nop
