.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413C4_A4DDE4
/* A4DDE4 802413C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4DDE8 802413C8 AFB10014 */  sw        $s1, 0x14($sp)
/* A4DDEC 802413CC 0080882D */  daddu     $s1, $a0, $zero
/* A4DDF0 802413D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4DDF4 802413D4 AFB00010 */  sw        $s0, 0x10($sp)
/* A4DDF8 802413D8 8E300148 */  lw        $s0, 0x148($s1)
/* A4DDFC 802413DC 0C00EABB */  jal       get_npc_unsafe
/* A4DE00 802413E0 86040008 */   lh       $a0, 8($s0)
/* A4DE04 802413E4 0040182D */  daddu     $v1, $v0, $zero
/* A4DE08 802413E8 240200FF */  addiu     $v0, $zero, 0xff
/* A4DE0C 802413EC A06200AC */  sb        $v0, 0xac($v1)
/* A4DE10 802413F0 8E0200CC */  lw        $v0, 0xcc($s0)
/* A4DE14 802413F4 8C440008 */  lw        $a0, 8($v0)
/* A4DE18 802413F8 A460008E */  sh        $zero, 0x8e($v1)
/* A4DE1C 802413FC AC640028 */  sw        $a0, 0x28($v1)
/* A4DE20 80241400 AE200070 */  sw        $zero, 0x70($s1)
/* A4DE24 80241404 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4DE28 80241408 8FB10014 */  lw        $s1, 0x14($sp)
/* A4DE2C 8024140C 8FB00010 */  lw        $s0, 0x10($sp)
/* A4DE30 80241410 24020002 */  addiu     $v0, $zero, 2
/* A4DE34 80241414 03E00008 */  jr        $ra
/* A4DE38 80241418 27BD0020 */   addiu    $sp, $sp, 0x20
