.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241974
/* B2DDE4 80241974 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2DDE8 80241978 AFBF0014 */  sw        $ra, 0x14($sp)
/* B2DDEC 8024197C AFB00010 */  sw        $s0, 0x10($sp)
/* B2DDF0 80241980 0C00EABB */  jal       get_npc_unsafe
/* B2DDF4 80241984 8C84014C */   lw       $a0, 0x14c($a0)
/* B2DDF8 80241988 24040008 */  addiu     $a0, $zero, 8
/* B2DDFC 8024198C 0040802D */  daddu     $s0, $v0, $zero
/* B2DE00 80241990 3C028024 */  lui       $v0, 0x8024
/* B2DE04 80241994 244219E0 */  addiu     $v0, $v0, 0x19e0
/* B2DE08 80241998 0C00AB39 */  jal       heap_malloc
/* B2DE0C 8024199C AE020008 */   sw       $v0, 8($s0)
/* B2DE10 802419A0 0040182D */  daddu     $v1, $v0, $zero
/* B2DE14 802419A4 AE030020 */  sw        $v1, 0x20($s0)
/* B2DE18 802419A8 AC600000 */  sw        $zero, ($v1)
/* B2DE1C 802419AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* B2DE20 802419B0 8FB00010 */  lw        $s0, 0x10($sp)
/* B2DE24 802419B4 24020001 */  addiu     $v0, $zero, 1
/* B2DE28 802419B8 03E00008 */  jr        $ra
/* B2DE2C 802419BC 27BD0018 */   addiu    $sp, $sp, 0x18
