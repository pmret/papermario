.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CCC_C381FC
/* C381FC 80241CCC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C38200 80241CD0 AFB00010 */  sw        $s0, 0x10($sp)
/* C38204 80241CD4 0080802D */  daddu     $s0, $a0, $zero
/* C38208 80241CD8 AFBF0014 */  sw        $ra, 0x14($sp)
/* C3820C 80241CDC 8E020148 */  lw        $v0, 0x148($s0)
/* C38210 80241CE0 0C00EABB */  jal       get_npc_unsafe
/* C38214 80241CE4 84440008 */   lh       $a0, 8($v0)
/* C38218 80241CE8 9443008E */  lhu       $v1, 0x8e($v0)
/* C3821C 80241CEC 2463FFFF */  addiu     $v1, $v1, -1
/* C38220 80241CF0 A443008E */  sh        $v1, 0x8e($v0)
/* C38224 80241CF4 00031C00 */  sll       $v1, $v1, 0x10
/* C38228 80241CF8 1C600002 */  bgtz      $v1, .L80241D04
/* C3822C 80241CFC 2402001E */   addiu    $v0, $zero, 0x1e
/* C38230 80241D00 AE020070 */  sw        $v0, 0x70($s0)
.L80241D04:
/* C38234 80241D04 8FBF0014 */  lw        $ra, 0x14($sp)
/* C38238 80241D08 8FB00010 */  lw        $s0, 0x10($sp)
/* C3823C 80241D0C 03E00008 */  jr        $ra
/* C38240 80241D10 27BD0018 */   addiu    $sp, $sp, 0x18
