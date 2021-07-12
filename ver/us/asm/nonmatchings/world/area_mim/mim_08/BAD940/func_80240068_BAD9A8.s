.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240068_BAD9A8
/* BAD9A8 80240068 44806000 */  mtc1      $zero, $f12
/* BAD9AC 8024006C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BAD9B0 80240070 AFB00010 */  sw        $s0, 0x10($sp)
/* BAD9B4 80240074 0080802D */  daddu     $s0, $a0, $zero
/* BAD9B8 80240078 AFBF0014 */  sw        $ra, 0x14($sp)
/* BAD9BC 8024007C 0C038022 */  jal       get_xz_dist_to_player
/* BAD9C0 80240080 46006386 */   mov.s    $f14, $f12
/* BAD9C4 80240084 4600008D */  trunc.w.s $f2, $f0
/* BAD9C8 80240088 E6020084 */  swc1      $f2, 0x84($s0)
/* BAD9CC 8024008C 8FBF0014 */  lw        $ra, 0x14($sp)
/* BAD9D0 80240090 8FB00010 */  lw        $s0, 0x10($sp)
/* BAD9D4 80240094 24020002 */  addiu     $v0, $zero, 2
/* BAD9D8 80240098 03E00008 */  jr        $ra
/* BAD9DC 8024009C 27BD0018 */   addiu    $sp, $sp, 0x18
