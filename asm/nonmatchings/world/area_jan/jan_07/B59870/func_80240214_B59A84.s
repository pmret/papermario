.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240214_B59A84
/* B59A84 80240214 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B59A88 80240218 AFB10014 */  sw        $s1, 0x14($sp)
/* B59A8C 8024021C 0080882D */  daddu     $s1, $a0, $zero
/* B59A90 80240220 AFBF0018 */  sw        $ra, 0x18($sp)
/* B59A94 80240224 AFB00010 */  sw        $s0, 0x10($sp)
/* B59A98 80240228 8E300148 */  lw        $s0, 0x148($s1)
/* B59A9C 8024022C 0C00EABB */  jal       get_npc_unsafe
/* B59AA0 80240230 86040008 */   lh       $a0, 8($s0)
/* B59AA4 80240234 24030001 */  addiu     $v1, $zero, 1
/* B59AA8 80240238 0040202D */  daddu     $a0, $v0, $zero
/* B59AAC 8024023C AE03006C */  sw        $v1, 0x6c($s0)
/* B59AB0 80240240 8482008C */  lh        $v0, 0x8c($a0)
/* B59AB4 80240244 14400009 */  bnez      $v0, .L8024026C
/* B59AB8 80240248 24020002 */   addiu    $v0, $zero, 2
/* B59ABC 8024024C 96030072 */  lhu       $v1, 0x72($s0)
/* B59AC0 80240250 AE02006C */  sw        $v0, 0x6c($s0)
/* B59AC4 80240254 A483008E */  sh        $v1, 0x8e($a0)
/* B59AC8 80240258 8E0200CC */  lw        $v0, 0xcc($s0)
/* B59ACC 8024025C 8C420020 */  lw        $v0, 0x20($v0)
/* B59AD0 80240260 AC820028 */  sw        $v0, 0x28($a0)
/* B59AD4 80240264 2402001F */  addiu     $v0, $zero, 0x1f
/* B59AD8 80240268 AE220070 */  sw        $v0, 0x70($s1)
.L8024026C:
/* B59ADC 8024026C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B59AE0 80240270 8FB10014 */  lw        $s1, 0x14($sp)
/* B59AE4 80240274 8FB00010 */  lw        $s0, 0x10($sp)
/* B59AE8 80240278 03E00008 */  jr        $ra
/* B59AEC 8024027C 27BD0020 */   addiu    $sp, $sp, 0x20
