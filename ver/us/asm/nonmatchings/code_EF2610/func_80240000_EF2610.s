.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EF2610
/* EF2610 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EF2614 80240004 24040001 */  addiu     $a0, $zero, 1
/* EF2618 80240008 0000282D */  daddu     $a1, $zero, $zero
/* EF261C 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* EF2620 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* EF2624 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* EF2628 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* EF262C 8024001C 0C01DEF4 */  jal       func_80077BD0
/* EF2630 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* EF2634 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* EF2638 80240028 24020002 */  addiu     $v0, $zero, 2
/* EF263C 8024002C 03E00008 */  jr        $ra
/* EF2640 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* EF2644 80240034 00000000 */  nop
/* EF2648 80240038 00000000 */  nop
/* EF264C 8024003C 00000000 */  nop
