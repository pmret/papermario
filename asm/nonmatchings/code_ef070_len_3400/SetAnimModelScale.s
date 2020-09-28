.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetAnimModelScale
/* F1C4C 802CD29C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F1C50 802CD2A0 AFB20018 */  sw        $s2, 0x18($sp)
/* F1C54 802CD2A4 0080902D */  daddu     $s2, $a0, $zero
/* F1C58 802CD2A8 AFBF001C */  sw        $ra, 0x1c($sp)
/* F1C5C 802CD2AC AFB10014 */  sw        $s1, 0x14($sp)
/* F1C60 802CD2B0 AFB00010 */  sw        $s0, 0x10($sp)
/* F1C64 802CD2B4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F1C68 802CD2B8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F1C6C 802CD2BC 8E50000C */  lw        $s0, 0xc($s2)
/* F1C70 802CD2C0 8E050000 */  lw        $a1, ($s0)
/* F1C74 802CD2C4 0C0B1EAF */  jal       get_variable
/* F1C78 802CD2C8 26100004 */   addiu    $s0, $s0, 4
/* F1C7C 802CD2CC 8E050000 */  lw        $a1, ($s0)
/* F1C80 802CD2D0 26100004 */  addiu     $s0, $s0, 4
/* F1C84 802CD2D4 0240202D */  daddu     $a0, $s2, $zero
/* F1C88 802CD2D8 0C0B210B */  jal       get_float_variable
/* F1C8C 802CD2DC 0040882D */   daddu    $s1, $v0, $zero
/* F1C90 802CD2E0 8E050000 */  lw        $a1, ($s0)
/* F1C94 802CD2E4 26100004 */  addiu     $s0, $s0, 4
/* F1C98 802CD2E8 0240202D */  daddu     $a0, $s2, $zero
/* F1C9C 802CD2EC 0C0B210B */  jal       get_float_variable
/* F1CA0 802CD2F0 46000586 */   mov.s    $f22, $f0
/* F1CA4 802CD2F4 0240202D */  daddu     $a0, $s2, $zero
/* F1CA8 802CD2F8 8E050000 */  lw        $a1, ($s0)
/* F1CAC 802CD2FC 0C0B210B */  jal       get_float_variable
/* F1CB0 802CD300 46000506 */   mov.s    $f20, $f0
/* F1CB4 802CD304 3C02802E */  lui       $v0, 0x802e
/* F1CB8 802CD308 8C42AE30 */  lw        $v0, -0x51d0($v0)
/* F1CBC 802CD30C 00118880 */  sll       $s1, $s1, 2
/* F1CC0 802CD310 02228821 */  addu      $s1, $s1, $v0
/* F1CC4 802CD314 8E230000 */  lw        $v1, ($s1)
/* F1CC8 802CD318 E476001C */  swc1      $f22, 0x1c($v1)
/* F1CCC 802CD31C E4740020 */  swc1      $f20, 0x20($v1)
/* F1CD0 802CD320 E4600024 */  swc1      $f0, 0x24($v1)
/* F1CD4 802CD324 8FBF001C */  lw        $ra, 0x1c($sp)
/* F1CD8 802CD328 8FB20018 */  lw        $s2, 0x18($sp)
/* F1CDC 802CD32C 8FB10014 */  lw        $s1, 0x14($sp)
/* F1CE0 802CD330 8FB00010 */  lw        $s0, 0x10($sp)
/* F1CE4 802CD334 D7B60028 */  ldc1      $f22, 0x28($sp)
/* F1CE8 802CD338 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F1CEC 802CD33C 24020002 */  addiu     $v0, $zero, 2
/* F1CF0 802CD340 03E00008 */  jr        $ra
/* F1CF4 802CD344 27BD0030 */   addiu    $sp, $sp, 0x30
