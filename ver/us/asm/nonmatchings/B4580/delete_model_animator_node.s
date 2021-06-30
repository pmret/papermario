.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel delete_model_animator_node
/* B4A98 8011E398 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4A9C 8011E39C AFB20018 */  sw        $s2, 0x18($sp)
/* B4AA0 8011E3A0 0080902D */  daddu     $s2, $a0, $zero
/* B4AA4 8011E3A4 AFB10014 */  sw        $s1, 0x14($sp)
/* B4AA8 8011E3A8 0000882D */  daddu     $s1, $zero, $zero
/* B4AAC 8011E3AC AFB00010 */  sw        $s0, 0x10($sp)
/* B4AB0 8011E3B0 0240802D */  daddu     $s0, $s2, $zero
/* B4AB4 8011E3B4 AFBF001C */  sw        $ra, 0x1c($sp)
/* B4AB8 8011E3B8 A64000F4 */  sh        $zero, 0xf4($s2)
.L8011E3BC:
/* B4ABC 8011E3BC 8E040004 */  lw        $a0, 4($s0)
/* B4AC0 8011E3C0 10800004 */  beqz      $a0, .L8011E3D4
/* B4AC4 8011E3C4 26310001 */   addiu    $s1, $s1, 1
/* B4AC8 8011E3C8 0C0478E6 */  jal       delete_model_animator_node
/* B4ACC 8011E3CC 00000000 */   nop
/* B4AD0 8011E3D0 AE000004 */  sw        $zero, 4($s0)
.L8011E3D4:
/* B4AD4 8011E3D4 2A220020 */  slti      $v0, $s1, 0x20
/* B4AD8 8011E3D8 1440FFF8 */  bnez      $v0, .L8011E3BC
/* B4ADC 8011E3DC 26100004 */   addiu    $s0, $s0, 4
/* B4AE0 8011E3E0 0C00AB4B */  jal       heap_free
/* B4AE4 8011E3E4 0240202D */   daddu    $a0, $s2, $zero
/* B4AE8 8011E3E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* B4AEC 8011E3EC 8FB20018 */  lw        $s2, 0x18($sp)
/* B4AF0 8011E3F0 8FB10014 */  lw        $s1, 0x14($sp)
/* B4AF4 8011E3F4 8FB00010 */  lw        $s0, 0x10($sp)
/* B4AF8 8011E3F8 03E00008 */  jr        $ra
/* B4AFC 8011E3FC 27BD0020 */   addiu    $sp, $sp, 0x20
