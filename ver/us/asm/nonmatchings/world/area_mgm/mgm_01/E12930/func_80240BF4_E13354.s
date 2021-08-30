.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BF4_E13354
/* E13354 80240BF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13358 80240BF8 AFB00010 */  sw        $s0, 0x10($sp)
/* E1335C 80240BFC 0080802D */  daddu     $s0, $a0, $zero
/* E13360 80240C00 AFBF0014 */  sw        $ra, 0x14($sp)
/* E13364 80240C04 0C00FB3A */  jal       get_enemy
/* E13368 80240C08 0000202D */   daddu    $a0, $zero, $zero
/* E1336C 80240C0C 8E03000C */  lw        $v1, 0xc($s0)
/* E13370 80240C10 0200202D */  daddu     $a0, $s0, $zero
/* E13374 80240C14 8C650000 */  lw        $a1, ($v1)
/* E13378 80240C18 0C0B1EAF */  jal       evt_get_variable
/* E1337C 80240C1C 8C500080 */   lw       $s0, 0x80($v0)
/* E13380 80240C20 0040202D */  daddu     $a0, $v0, $zero
/* E13384 80240C24 24020002 */  addiu     $v0, $zero, 2
/* E13388 80240C28 00041840 */  sll       $v1, $a0, 1
/* E1338C 80240C2C 00641821 */  addu      $v1, $v1, $a0
/* E13390 80240C30 000318C0 */  sll       $v1, $v1, 3
/* E13394 80240C34 00641823 */  subu      $v1, $v1, $a0
/* E13398 80240C38 00431804 */  sllv      $v1, $v1, $v0
/* E1339C 80240C3C 02038021 */  addu      $s0, $s0, $v1
/* E133A0 80240C40 AE0000B8 */  sw        $zero, 0xb8($s0)
/* E133A4 80240C44 8FBF0014 */  lw        $ra, 0x14($sp)
/* E133A8 80240C48 8FB00010 */  lw        $s0, 0x10($sp)
/* E133AC 80240C4C 03E00008 */  jr        $ra
/* E133B0 80240C50 27BD0018 */   addiu    $sp, $sp, 0x18
