.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407E4_E12F44
/* E12F44 802407E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E12F48 802407E8 AFB00010 */  sw        $s0, 0x10($sp)
/* E12F4C 802407EC 0080802D */  daddu     $s0, $a0, $zero
/* E12F50 802407F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* E12F54 802407F4 0C00FB3A */  jal       get_enemy
/* E12F58 802407F8 0000202D */   daddu    $a0, $zero, $zero
/* E12F5C 802407FC 8E03000C */  lw        $v1, 0xc($s0)
/* E12F60 80240800 0200202D */  daddu     $a0, $s0, $zero
/* E12F64 80240804 8C650000 */  lw        $a1, ($v1)
/* E12F68 80240808 0C0B1EAF */  jal       evt_get_variable
/* E12F6C 8024080C 8C500080 */   lw       $s0, 0x80($v0)
/* E12F70 80240810 0040202D */  daddu     $a0, $v0, $zero
/* E12F74 80240814 24020002 */  addiu     $v0, $zero, 2
/* E12F78 80240818 00041840 */  sll       $v1, $a0, 1
/* E12F7C 8024081C 00641821 */  addu      $v1, $v1, $a0
/* E12F80 80240820 000318C0 */  sll       $v1, $v1, 3
/* E12F84 80240824 00641823 */  subu      $v1, $v1, $a0
/* E12F88 80240828 00431804 */  sllv      $v1, $v1, $v0
/* E12F8C 8024082C 02038021 */  addu      $s0, $s0, $v1
/* E12F90 80240830 2403000A */  addiu     $v1, $zero, 0xa
/* E12F94 80240834 AE00008C */  sw        $zero, 0x8c($s0)
/* E12F98 80240838 AE030090 */  sw        $v1, 0x90($s0)
/* E12F9C 8024083C 8FBF0014 */  lw        $ra, 0x14($sp)
/* E12FA0 80240840 8FB00010 */  lw        $s0, 0x10($sp)
/* E12FA4 80240844 03E00008 */  jr        $ra
/* E12FA8 80240848 27BD0018 */   addiu    $sp, $sp, 0x18
