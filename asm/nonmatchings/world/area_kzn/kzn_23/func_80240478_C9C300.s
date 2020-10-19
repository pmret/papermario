.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240478_C9C778
/* C9C778 80240478 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C9C77C 8024047C AFB10014 */  sw        $s1, 0x14($sp)
/* C9C780 80240480 0080882D */  daddu     $s1, $a0, $zero
/* C9C784 80240484 AFBF0018 */  sw        $ra, 0x18($sp)
/* C9C788 80240488 AFB00010 */  sw        $s0, 0x10($sp)
/* C9C78C 8024048C F7B60028 */  sdc1      $f22, 0x28($sp)
/* C9C790 80240490 F7B40020 */  sdc1      $f20, 0x20($sp)
/* C9C794 80240494 8E30000C */  lw        $s0, 0xc($s1)
/* C9C798 80240498 8E050000 */  lw        $a1, ($s0)
/* C9C79C 8024049C 0C0B210B */  jal       get_float_variable
/* C9C7A0 802404A0 26100004 */   addiu    $s0, $s0, 4
/* C9C7A4 802404A4 8E050000 */  lw        $a1, ($s0)
/* C9C7A8 802404A8 26100004 */  addiu     $s0, $s0, 4
/* C9C7AC 802404AC 0220202D */  daddu     $a0, $s1, $zero
/* C9C7B0 802404B0 0C0B210B */  jal       get_float_variable
/* C9C7B4 802404B4 46000586 */   mov.s    $f22, $f0
/* C9C7B8 802404B8 0220202D */  daddu     $a0, $s1, $zero
/* C9C7BC 802404BC 8E050000 */  lw        $a1, ($s0)
/* C9C7C0 802404C0 0C0B210B */  jal       get_float_variable
/* C9C7C4 802404C4 46000506 */   mov.s    $f20, $f0
/* C9C7C8 802404C8 8E2300BC */  lw        $v1, 0xbc($s1)
/* C9C7CC 802404CC 8C62000C */  lw        $v0, 0xc($v1)
/* C9C7D0 802404D0 E4560038 */  swc1      $f22, 0x38($v0)
/* C9C7D4 802404D4 8C62000C */  lw        $v0, 0xc($v1)
/* C9C7D8 802404D8 E454003C */  swc1      $f20, 0x3c($v0)
/* C9C7DC 802404DC 8C62000C */  lw        $v0, 0xc($v1)
/* C9C7E0 802404E0 E4400040 */  swc1      $f0, 0x40($v0)
/* C9C7E4 802404E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C9C7E8 802404E8 8FB10014 */  lw        $s1, 0x14($sp)
/* C9C7EC 802404EC 8FB00010 */  lw        $s0, 0x10($sp)
/* C9C7F0 802404F0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* C9C7F4 802404F4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* C9C7F8 802404F8 24020002 */  addiu     $v0, $zero, 2
/* C9C7FC 802404FC 03E00008 */  jr        $ra
/* C9C800 80240500 27BD0030 */   addiu    $sp, $sp, 0x30
