.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_72A98C
/* 72A98C 802A123C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 72A990 802A1240 AFB00010 */  sw        $s0, 0x10($sp)
/* 72A994 802A1244 0080802D */  daddu     $s0, $a0, $zero
/* 72A998 802A1248 AFBF0014 */  sw        $ra, 0x14($sp)
/* 72A99C 802A124C 0C09A75B */  jal       get_actor
/* 72A9A0 802A1250 8E040148 */   lw       $a0, 0x148($s0)
/* 72A9A4 802A1254 0C09A75B */  jal       get_actor
/* 72A9A8 802A1258 84440428 */   lh       $a0, 0x428($v0)
/* 72A9AC 802A125C 90430136 */  lbu       $v1, 0x136($v0)
/* 72A9B0 802A1260 38630031 */  xori      $v1, $v1, 0x31
/* 72A9B4 802A1264 2C630001 */  sltiu     $v1, $v1, 1
/* 72A9B8 802A1268 AE0300A8 */  sw        $v1, 0xa8($s0)
/* 72A9BC 802A126C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 72A9C0 802A1270 8FB00010 */  lw        $s0, 0x10($sp)
/* 72A9C4 802A1274 24020002 */  addiu     $v0, $zero, 2
/* 72A9C8 802A1278 03E00008 */  jr        $ra
/* 72A9CC 802A127C 27BD0018 */   addiu    $sp, $sp, 0x18
