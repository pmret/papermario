.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411B0_9D81D0
/* 9D81D0 802411B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D81D4 802411B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D81D8 802411B8 0080882D */  daddu     $s1, $a0, $zero
/* 9D81DC 802411BC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D81E0 802411C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D81E4 802411C4 8E300148 */  lw        $s0, 0x148($s1)
/* 9D81E8 802411C8 0C00EABB */  jal       get_npc_unsafe
/* 9D81EC 802411CC 86040008 */   lh       $a0, 8($s0)
/* 9D81F0 802411D0 8E0300CC */  lw        $v1, 0xcc($s0)
/* 9D81F4 802411D4 3C014120 */  lui       $at, 0x4120
/* 9D81F8 802411D8 44812000 */  mtc1      $at, $f4
/* 9D81FC 802411DC 3C014000 */  lui       $at, 0x4000
/* 9D8200 802411E0 44810000 */  mtc1      $at, $f0
/* 9D8204 802411E4 C442003C */  lwc1      $f2, 0x3c($v0)
/* 9D8208 802411E8 8C640010 */  lw        $a0, 0x10($v1)
/* 9D820C 802411EC 8C430000 */  lw        $v1, ($v0)
/* 9D8210 802411F0 E444001C */  swc1      $f4, 0x1c($v0)
/* 9D8214 802411F4 E4400014 */  swc1      $f0, 0x14($v0)
/* 9D8218 802411F8 E4420064 */  swc1      $f2, 0x64($v0)
/* 9D821C 802411FC 34630800 */  ori       $v1, $v1, 0x800
/* 9D8220 80241200 AC430000 */  sw        $v1, ($v0)
/* 9D8224 80241204 AC440028 */  sw        $a0, 0x28($v0)
/* 9D8228 80241208 2402000B */  addiu     $v0, $zero, 0xb
/* 9D822C 8024120C AE220070 */  sw        $v0, 0x70($s1)
/* 9D8230 80241210 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D8234 80241214 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D8238 80241218 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D823C 8024121C 03E00008 */  jr        $ra
/* 9D8240 80241220 27BD0020 */   addiu    $sp, $sp, 0x20
