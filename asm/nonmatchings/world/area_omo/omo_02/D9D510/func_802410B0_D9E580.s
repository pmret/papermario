.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410B0_D9E580
/* D9E580 802410B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D9E584 802410B4 AFB00010 */  sw        $s0, 0x10($sp)
/* D9E588 802410B8 0080802D */  daddu     $s0, $a0, $zero
/* D9E58C 802410BC AFBF0014 */  sw        $ra, 0x14($sp)
/* D9E590 802410C0 8E020148 */  lw        $v0, 0x148($s0)
/* D9E594 802410C4 0C00EABB */  jal       get_npc_unsafe
/* D9E598 802410C8 84440008 */   lh       $a0, 8($v0)
/* D9E59C 802410CC 3C014120 */  lui       $at, 0x4120
/* D9E5A0 802410D0 44810000 */  mtc1      $at, $f0
/* D9E5A4 802410D4 3C014000 */  lui       $at, 0x4000
/* D9E5A8 802410D8 44811000 */  mtc1      $at, $f2
/* D9E5AC 802410DC 8C430000 */  lw        $v1, ($v0)
/* D9E5B0 802410E0 C444003C */  lwc1      $f4, 0x3c($v0)
/* D9E5B4 802410E4 34630800 */  ori       $v1, $v1, 0x800
/* D9E5B8 802410E8 E440001C */  swc1      $f0, 0x1c($v0)
/* D9E5BC 802410EC E4420014 */  swc1      $f2, 0x14($v0)
/* D9E5C0 802410F0 E4440064 */  swc1      $f4, 0x64($v0)
/* D9E5C4 802410F4 AC430000 */  sw        $v1, ($v0)
/* D9E5C8 802410F8 2402000B */  addiu     $v0, $zero, 0xb
/* D9E5CC 802410FC AE020070 */  sw        $v0, 0x70($s0)
/* D9E5D0 80241100 8FBF0014 */  lw        $ra, 0x14($sp)
/* D9E5D4 80241104 8FB00010 */  lw        $s0, 0x10($sp)
/* D9E5D8 80241108 03E00008 */  jr        $ra
/* D9E5DC 8024110C 27BD0018 */   addiu    $sp, $sp, 0x18
