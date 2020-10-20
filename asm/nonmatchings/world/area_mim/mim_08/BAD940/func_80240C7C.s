.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C7C
/* BAE5BC 80240C7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BAE5C0 80240C80 AFB20018 */  sw        $s2, 0x18($sp)
/* BAE5C4 80240C84 0080902D */  daddu     $s2, $a0, $zero
/* BAE5C8 80240C88 AFBF001C */  sw        $ra, 0x1c($sp)
/* BAE5CC 80240C8C AFB10014 */  sw        $s1, 0x14($sp)
/* BAE5D0 80240C90 AFB00010 */  sw        $s0, 0x10($sp)
/* BAE5D4 80240C94 8E510148 */  lw        $s1, 0x148($s2)
/* BAE5D8 80240C98 0C00EABB */  jal       get_npc_unsafe
/* BAE5DC 80240C9C 86240008 */   lh       $a0, 8($s1)
/* BAE5E0 80240CA0 0040802D */  daddu     $s0, $v0, $zero
/* BAE5E4 80240CA4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAE5E8 80240CA8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAE5EC 80240CAC C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAE5F0 80240CB0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAE5F4 80240CB4 A600008E */  sh        $zero, 0x8e($s0)
/* BAE5F8 80240CB8 8C460028 */  lw        $a2, 0x28($v0)
/* BAE5FC 80240CBC 0C00A720 */  jal       atan2
/* BAE600 80240CC0 8C470030 */   lw       $a3, 0x30($v0)
/* BAE604 80240CC4 E600000C */  swc1      $f0, 0xc($s0)
/* BAE608 80240CC8 8E2200CC */  lw        $v0, 0xcc($s1)
/* BAE60C 80240CCC 8C420020 */  lw        $v0, 0x20($v0)
/* BAE610 80240CD0 AE020028 */  sw        $v0, 0x28($s0)
/* BAE614 80240CD4 2402000B */  addiu     $v0, $zero, 0xb
/* BAE618 80240CD8 AE420070 */  sw        $v0, 0x70($s2)
/* BAE61C 80240CDC 8FBF001C */  lw        $ra, 0x1c($sp)
/* BAE620 80240CE0 8FB20018 */  lw        $s2, 0x18($sp)
/* BAE624 80240CE4 8FB10014 */  lw        $s1, 0x14($sp)
/* BAE628 80240CE8 8FB00010 */  lw        $s0, 0x10($sp)
/* BAE62C 80240CEC 03E00008 */  jr        $ra
/* BAE630 80240CF0 27BD0020 */   addiu    $sp, $sp, 0x20
