.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241378_A4DD98
/* A4DD98 80241378 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A4DD9C 8024137C AFBF0020 */  sw        $ra, 0x20($sp)
/* A4DDA0 80241380 8C820148 */  lw        $v0, 0x148($a0)
/* A4DDA4 80241384 0C00EABB */  jal       get_npc_unsafe
/* A4DDA8 80241388 84440008 */   lh       $a0, 8($v0)
/* A4DDAC 8024138C 240300FF */  addiu     $v1, $zero, 0xff
/* A4DDB0 80241390 0000282D */  daddu     $a1, $zero, $zero
/* A4DDB4 80241394 00A0302D */  daddu     $a2, $a1, $zero
/* A4DDB8 80241398 A04300AC */  sb        $v1, 0xac($v0)
/* A4DDBC 8024139C AFA00010 */  sw        $zero, 0x10($sp)
/* A4DDC0 802413A0 AFA00014 */  sw        $zero, 0x14($sp)
/* A4DDC4 802413A4 AFA00018 */  sw        $zero, 0x18($sp)
/* A4DDC8 802413A8 8C440024 */  lw        $a0, 0x24($v0)
/* A4DDCC 802413AC 0C0B7A25 */  jal       func_802DE894
/* A4DDD0 802413B0 00A0382D */   daddu    $a3, $a1, $zero
/* A4DDD4 802413B4 8FBF0020 */  lw        $ra, 0x20($sp)
/* A4DDD8 802413B8 24020002 */  addiu     $v0, $zero, 2
/* A4DDDC 802413BC 03E00008 */  jr        $ra
/* A4DDE0 802413C0 27BD0028 */   addiu    $sp, $sp, 0x28
