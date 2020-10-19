.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419B8
/* DCE688 802419B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCE68C 802419BC AFB10014 */  sw        $s1, 0x14($sp)
/* DCE690 802419C0 0080882D */  daddu     $s1, $a0, $zero
/* DCE694 802419C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCE698 802419C8 AFB00010 */  sw        $s0, 0x10($sp)
/* DCE69C 802419CC 8E300148 */  lw        $s0, 0x148($s1)
/* DCE6A0 802419D0 0C00EABB */  jal       get_npc_unsafe
/* DCE6A4 802419D4 86040008 */   lh       $a0, 8($s0)
/* DCE6A8 802419D8 9443008E */  lhu       $v1, 0x8e($v0)
/* DCE6AC 802419DC 2463FFFF */  addiu     $v1, $v1, -1
/* DCE6B0 802419E0 A443008E */  sh        $v1, 0x8e($v0)
/* DCE6B4 802419E4 00031C00 */  sll       $v1, $v1, 0x10
/* DCE6B8 802419E8 14600008 */  bnez      $v1, .L80241A0C
/* DCE6BC 802419EC 00000000 */   nop      
/* DCE6C0 802419F0 8E0200B0 */  lw        $v0, 0xb0($s0)
/* DCE6C4 802419F4 30420080 */  andi      $v0, $v0, 0x80
/* DCE6C8 802419F8 10400003 */  beqz      $v0, .L80241A08
/* DCE6CC 802419FC 2402000F */   addiu    $v0, $zero, 0xf
/* DCE6D0 80241A00 08090683 */  j         .L80241A0C
/* DCE6D4 80241A04 AE220070 */   sw       $v0, 0x70($s1)
.L80241A08:
/* DCE6D8 80241A08 AE200070 */  sw        $zero, 0x70($s1)
.L80241A0C:
/* DCE6DC 80241A0C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCE6E0 80241A10 8FB10014 */  lw        $s1, 0x14($sp)
/* DCE6E4 80241A14 8FB00010 */  lw        $s0, 0x10($sp)
/* DCE6E8 80241A18 03E00008 */  jr        $ra
/* DCE6EC 80241A1C 27BD0020 */   addiu    $sp, $sp, 0x20
