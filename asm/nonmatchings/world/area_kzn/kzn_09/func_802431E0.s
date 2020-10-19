.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802431E0
/* C79EC0 802431E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C79EC4 802431E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C79EC8 802431E8 0C00EAD2 */  jal       get_npc_safe
/* C79ECC 802431EC 8C84014C */   lw       $a0, 0x14c($a0)
/* C79ED0 802431F0 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* C79ED4 802431F4 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* C79ED8 802431F8 C44C0038 */  lwc1      $f12, 0x38($v0)
/* C79EDC 802431FC C44E0040 */  lwc1      $f14, 0x40($v0)
/* C79EE0 80243200 8C660028 */  lw        $a2, 0x28($v1)
/* C79EE4 80243204 0C00A7B5 */  jal       dist2D
/* C79EE8 80243208 8C670030 */   lw       $a3, 0x30($v1)
/* C79EEC 8024320C 3C014248 */  lui       $at, 0x4248
/* C79EF0 80243210 44811000 */  mtc1      $at, $f2
/* C79EF4 80243214 00000000 */  nop       
/* C79EF8 80243218 4602003C */  c.lt.s    $f0, $f2
/* C79EFC 8024321C 00000000 */  nop       
/* C79F00 80243220 45010002 */  bc1t      .L8024322C
/* C79F04 80243224 24020002 */   addiu    $v0, $zero, 2
/* C79F08 80243228 0000102D */  daddu     $v0, $zero, $zero
.L8024322C:
/* C79F0C 8024322C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C79F10 80243230 03E00008 */  jr        $ra
/* C79F14 80243234 27BD0018 */   addiu    $sp, $sp, 0x18
