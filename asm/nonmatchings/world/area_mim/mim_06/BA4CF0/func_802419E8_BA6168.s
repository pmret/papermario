.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419E8_BA6168
/* BA6168 802419E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA616C 802419EC AFB10014 */  sw        $s1, 0x14($sp)
/* BA6170 802419F0 0080882D */  daddu     $s1, $a0, $zero
/* BA6174 802419F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA6178 802419F8 AFB00010 */  sw        $s0, 0x10($sp)
/* BA617C 802419FC 8E300148 */  lw        $s0, 0x148($s1)
/* BA6180 80241A00 0C00EABB */  jal       get_npc_unsafe
/* BA6184 80241A04 86040008 */   lh       $a0, 8($s0)
/* BA6188 80241A08 0040202D */  daddu     $a0, $v0, $zero
/* BA618C 80241A0C 9482008E */  lhu       $v0, 0x8e($a0)
/* BA6190 80241A10 2442FFFF */  addiu     $v0, $v0, -1
/* BA6194 80241A14 A482008E */  sh        $v0, 0x8e($a0)
/* BA6198 80241A18 00021400 */  sll       $v0, $v0, 0x10
/* BA619C 80241A1C 8E030098 */  lw        $v1, 0x98($s0)
/* BA61A0 80241A20 00021403 */  sra       $v0, $v0, 0x10
/* BA61A4 80241A24 0062182A */  slt       $v1, $v1, $v0
/* BA61A8 80241A28 14600005 */  bnez      $v1, .L80241A40
/* BA61AC 80241A2C 3C03E0EF */   lui      $v1, 0xe0ef
/* BA61B0 80241A30 8E020000 */  lw        $v0, ($s0)
/* BA61B4 80241A34 3463FFFF */  ori       $v1, $v1, 0xffff
/* BA61B8 80241A38 00431024 */  and       $v0, $v0, $v1
/* BA61BC 80241A3C AE020000 */  sw        $v0, ($s0)
.L80241A40:
/* BA61C0 80241A40 8482008E */  lh        $v0, 0x8e($a0)
/* BA61C4 80241A44 14400007 */  bnez      $v0, .L80241A64
/* BA61C8 80241A48 00000000 */   nop
/* BA61CC 80241A4C 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA61D0 80241A50 8C420028 */  lw        $v0, 0x28($v0)
/* BA61D4 80241A54 A480008E */  sh        $zero, 0x8e($a0)
/* BA61D8 80241A58 AC820028 */  sw        $v0, 0x28($a0)
/* BA61DC 80241A5C 2402000C */  addiu     $v0, $zero, 0xc
/* BA61E0 80241A60 AE220070 */  sw        $v0, 0x70($s1)
.L80241A64:
/* BA61E4 80241A64 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA61E8 80241A68 8FB10014 */  lw        $s1, 0x14($sp)
/* BA61EC 80241A6C 8FB00010 */  lw        $s0, 0x10($sp)
/* BA61F0 80241A70 03E00008 */  jr        $ra
/* BA61F4 80241A74 27BD0020 */   addiu    $sp, $sp, 0x20
