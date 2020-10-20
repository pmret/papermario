.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419D0_B54200
/* B54200 802419D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B54204 802419D4 AFB10014 */  sw        $s1, 0x14($sp)
/* B54208 802419D8 0080882D */  daddu     $s1, $a0, $zero
/* B5420C 802419DC AFBF0018 */  sw        $ra, 0x18($sp)
/* B54210 802419E0 AFB00010 */  sw        $s0, 0x10($sp)
/* B54214 802419E4 8E300148 */  lw        $s0, 0x148($s1)
/* B54218 802419E8 0C00EABB */  jal       get_npc_unsafe
/* B5421C 802419EC 86040008 */   lh       $a0, 8($s0)
/* B54220 802419F0 9443008E */  lhu       $v1, 0x8e($v0)
/* B54224 802419F4 2463FFFF */  addiu     $v1, $v1, -1
/* B54228 802419F8 A443008E */  sh        $v1, 0x8e($v0)
/* B5422C 802419FC 00031C00 */  sll       $v1, $v1, 0x10
/* B54230 80241A00 1C600003 */  bgtz      $v1, .L80241A10
/* B54234 80241A04 2402000C */   addiu    $v0, $zero, 0xc
/* B54238 80241A08 AE00006C */  sw        $zero, 0x6c($s0)
/* B5423C 80241A0C AE220070 */  sw        $v0, 0x70($s1)
.L80241A10:
/* B54240 80241A10 8FBF0018 */  lw        $ra, 0x18($sp)
/* B54244 80241A14 8FB10014 */  lw        $s1, 0x14($sp)
/* B54248 80241A18 8FB00010 */  lw        $s0, 0x10($sp)
/* B5424C 80241A1C 03E00008 */  jr        $ra
/* B54250 80241A20 27BD0020 */   addiu    $sp, $sp, 0x20
