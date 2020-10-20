.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C5C_C004DC
/* C004DC 80242C5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C004E0 80242C60 AFB10014 */  sw        $s1, 0x14($sp)
/* C004E4 80242C64 0080882D */  daddu     $s1, $a0, $zero
/* C004E8 80242C68 AFBF0018 */  sw        $ra, 0x18($sp)
/* C004EC 80242C6C AFB00010 */  sw        $s0, 0x10($sp)
/* C004F0 80242C70 8E300148 */  lw        $s0, 0x148($s1)
/* C004F4 80242C74 0C00EABB */  jal       get_npc_unsafe
/* C004F8 80242C78 86040008 */   lh       $a0, 8($s0)
/* C004FC 80242C7C 8E0300CC */  lw        $v1, 0xcc($s0)
/* C00500 80242C80 3C014120 */  lui       $at, 0x4120
/* C00504 80242C84 44812000 */  mtc1      $at, $f4
/* C00508 80242C88 3C014000 */  lui       $at, 0x4000
/* C0050C 80242C8C 44810000 */  mtc1      $at, $f0
/* C00510 80242C90 C442003C */  lwc1      $f2, 0x3c($v0)
/* C00514 80242C94 8C640010 */  lw        $a0, 0x10($v1)
/* C00518 80242C98 8C430000 */  lw        $v1, ($v0)
/* C0051C 80242C9C E444001C */  swc1      $f4, 0x1c($v0)
/* C00520 80242CA0 E4400014 */  swc1      $f0, 0x14($v0)
/* C00524 80242CA4 E4420064 */  swc1      $f2, 0x64($v0)
/* C00528 80242CA8 34630800 */  ori       $v1, $v1, 0x800
/* C0052C 80242CAC AC430000 */  sw        $v1, ($v0)
/* C00530 80242CB0 AC440028 */  sw        $a0, 0x28($v0)
/* C00534 80242CB4 2402000B */  addiu     $v0, $zero, 0xb
/* C00538 80242CB8 AE220070 */  sw        $v0, 0x70($s1)
/* C0053C 80242CBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C00540 80242CC0 8FB10014 */  lw        $s1, 0x14($sp)
/* C00544 80242CC4 8FB00010 */  lw        $s0, 0x10($sp)
/* C00548 80242CC8 03E00008 */  jr        $ra
/* C0054C 80242CCC 27BD0020 */   addiu    $sp, $sp, 0x20
