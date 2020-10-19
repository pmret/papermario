.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410A4_A4DAC4
/* A4DAC4 802410A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4DAC8 802410A8 AFB10014 */  sw        $s1, 0x14($sp)
/* A4DACC 802410AC 0080882D */  daddu     $s1, $a0, $zero
/* A4DAD0 802410B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4DAD4 802410B4 AFB00010 */  sw        $s0, 0x10($sp)
/* A4DAD8 802410B8 8E300148 */  lw        $s0, 0x148($s1)
/* A4DADC 802410BC 0C00EABB */  jal       get_npc_unsafe
/* A4DAE0 802410C0 86040008 */   lh       $a0, 8($s0)
/* A4DAE4 802410C4 0040202D */  daddu     $a0, $v0, $zero
/* A4DAE8 802410C8 9482008E */  lhu       $v0, 0x8e($a0)
/* A4DAEC 802410CC 2442FFFF */  addiu     $v0, $v0, -1
/* A4DAF0 802410D0 A482008E */  sh        $v0, 0x8e($a0)
/* A4DAF4 802410D4 00021400 */  sll       $v0, $v0, 0x10
/* A4DAF8 802410D8 1C400007 */  bgtz      $v0, .L802410F8
/* A4DAFC 802410DC 00000000 */   nop      
/* A4DB00 802410E0 8E0200CC */  lw        $v0, 0xcc($s0)
/* A4DB04 802410E4 8C430000 */  lw        $v1, ($v0)
/* A4DB08 802410E8 24020003 */  addiu     $v0, $zero, 3
/* A4DB0C 802410EC A482008E */  sh        $v0, 0x8e($a0)
/* A4DB10 802410F0 AC830028 */  sw        $v1, 0x28($a0)
/* A4DB14 802410F4 AE200070 */  sw        $zero, 0x70($s1)
.L802410F8:
/* A4DB18 802410F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4DB1C 802410FC 8FB10014 */  lw        $s1, 0x14($sp)
/* A4DB20 80241100 8FB00010 */  lw        $s0, 0x10($sp)
/* A4DB24 80241104 03E00008 */  jr        $ra
/* A4DB28 80241108 27BD0020 */   addiu    $sp, $sp, 0x20
