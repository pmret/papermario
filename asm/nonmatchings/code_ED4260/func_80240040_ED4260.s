.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_ED4260
/* ED4260 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ED4264 80240044 24040001 */  addiu     $a0, $zero, 1
/* ED4268 80240048 0000282D */  daddu     $a1, $zero, $zero
/* ED426C 8024004C 00A0302D */  daddu     $a2, $a1, $zero
/* ED4270 80240050 00A0382D */  daddu     $a3, $a1, $zero
/* ED4274 80240054 AFBF0018 */  sw        $ra, 0x18($sp)
/* ED4278 80240058 AFA00010 */  sw        $zero, 0x10($sp)
/* ED427C 8024005C 0C01DEF4 */  jal       func_80077BD0
/* ED4280 80240060 AFA00014 */   sw       $zero, 0x14($sp)
/* ED4284 80240064 8FBF0018 */  lw        $ra, 0x18($sp)
/* ED4288 80240068 24020002 */  addiu     $v0, $zero, 2
/* ED428C 8024006C 03E00008 */  jr        $ra
/* ED4290 80240070 27BD0020 */   addiu    $sp, $sp, 0x20
/* ED4294 80240074 00000000 */  nop       
/* ED4298 80240078 00000000 */  nop       
/* ED429C 8024007C 00000000 */  nop       
