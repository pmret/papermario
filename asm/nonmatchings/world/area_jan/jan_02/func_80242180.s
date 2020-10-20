.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242180
/* B2E5F0 80242180 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2E5F4 80242184 AFB10014 */  sw        $s1, 0x14($sp)
/* B2E5F8 80242188 0080882D */  daddu     $s1, $a0, $zero
/* B2E5FC 8024218C AFBF0018 */  sw        $ra, 0x18($sp)
/* B2E600 80242190 AFB00010 */  sw        $s0, 0x10($sp)
/* B2E604 80242194 8E30000C */  lw        $s0, 0xc($s1)
/* B2E608 80242198 8E050000 */  lw        $a1, ($s0)
/* B2E60C 8024219C 0C0B1EAF */  jal       get_variable
/* B2E610 802421A0 26100004 */   addiu    $s0, $s0, 4
/* B2E614 802421A4 0220202D */  daddu     $a0, $s1, $zero
/* B2E618 802421A8 8E050000 */  lw        $a1, ($s0)
/* B2E61C 802421AC 0C0B210B */  jal       get_float_variable
/* B2E620 802421B0 0040802D */   daddu    $s0, $v0, $zero
/* B2E624 802421B4 24020002 */  addiu     $v0, $zero, 2
/* B2E628 802421B8 00501804 */  sllv      $v1, $s0, $v0
/* B2E62C 802421BC 00701821 */  addu      $v1, $v1, $s0
/* B2E630 802421C0 00431804 */  sllv      $v1, $v1, $v0
/* B2E634 802421C4 00701823 */  subu      $v1, $v1, $s0
/* B2E638 802421C8 000320C0 */  sll       $a0, $v1, 3
/* B2E63C 802421CC 00641821 */  addu      $v1, $v1, $a0
/* B2E640 802421D0 000318C0 */  sll       $v1, $v1, 3
/* B2E644 802421D4 3C01800B */  lui       $at, 0x800b
/* B2E648 802421D8 00230821 */  addu      $at, $at, $v1
/* B2E64C 802421DC E4201D98 */  swc1      $f0, 0x1d98($at)
/* B2E650 802421E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2E654 802421E4 8FB10014 */  lw        $s1, 0x14($sp)
/* B2E658 802421E8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2E65C 802421EC 03E00008 */  jr        $ra
/* B2E660 802421F0 27BD0020 */   addiu    $sp, $sp, 0x20
