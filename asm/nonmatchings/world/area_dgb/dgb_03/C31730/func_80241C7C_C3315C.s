.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C7C_C3315C
/* C3315C 80241C7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C33160 80241C80 AFB10014 */  sw        $s1, 0x14($sp)
/* C33164 80241C84 0080882D */  daddu     $s1, $a0, $zero
/* C33168 80241C88 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3316C 80241C8C AFB00010 */  sw        $s0, 0x10($sp)
/* C33170 80241C90 8E300148 */  lw        $s0, 0x148($s1)
/* C33174 80241C94 0C00EABB */  jal       get_npc_unsafe
/* C33178 80241C98 86040008 */   lh       $a0, 8($s0)
/* C3317C 80241C9C 0040202D */  daddu     $a0, $v0, $zero
/* C33180 80241CA0 8482008E */  lh        $v0, 0x8e($a0)
/* C33184 80241CA4 9483008E */  lhu       $v1, 0x8e($a0)
/* C33188 80241CA8 18400002 */  blez      $v0, .L80241CB4
/* C3318C 80241CAC 2462FFFF */   addiu    $v0, $v1, -1
/* C33190 80241CB0 A482008E */  sh        $v0, 0x8e($a0)
.L80241CB4:
/* C33194 80241CB4 8482008E */  lh        $v0, 0x8e($a0)
/* C33198 80241CB8 24030001 */  addiu     $v1, $zero, 1
/* C3319C 80241CBC 14430005 */  bne       $v0, $v1, .L80241CD4
/* C331A0 80241CC0 00000000 */   nop      
/* C331A4 80241CC4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C331A8 80241CC8 8C420030 */  lw        $v0, 0x30($v0)
/* C331AC 80241CCC 0809073C */  j         .L80241CF0
/* C331B0 80241CD0 AC820028 */   sw       $v0, 0x28($a0)
.L80241CD4:
/* C331B4 80241CD4 1C400006 */  bgtz      $v0, .L80241CF0
/* C331B8 80241CD8 00000000 */   nop      
/* C331BC 80241CDC 8E0200CC */  lw        $v0, 0xcc($s0)
/* C331C0 80241CE0 8C420028 */  lw        $v0, 0x28($v0)
/* C331C4 80241CE4 A480008E */  sh        $zero, 0x8e($a0)
/* C331C8 80241CE8 AC820028 */  sw        $v0, 0x28($a0)
/* C331CC 80241CEC AE230070 */  sw        $v1, 0x70($s1)
.L80241CF0:
/* C331D0 80241CF0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C331D4 80241CF4 8FB10014 */  lw        $s1, 0x14($sp)
/* C331D8 80241CF8 8FB00010 */  lw        $s0, 0x10($sp)
/* C331DC 80241CFC 03E00008 */  jr        $ra
/* C331E0 80241D00 27BD0020 */   addiu    $sp, $sp, 0x20
