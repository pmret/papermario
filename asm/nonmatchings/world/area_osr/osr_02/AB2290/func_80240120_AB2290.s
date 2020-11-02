.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240120_AB2290
/* AB2290 80240120 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB2294 80240124 AFBF0010 */  sw        $ra, 0x10($sp)
/* AB2298 80240128 8C82000C */  lw        $v0, 0xc($a0)
/* AB229C 8024012C 3C068011 */  lui       $a2, %hi(gPlayerStatus+0xC)
/* AB22A0 80240130 80C6EFD4 */  lb        $a2, %lo(gPlayerStatus+0xC)($a2)
/* AB22A4 80240134 0C0B2026 */  jal       set_variable
/* AB22A8 80240138 8C450000 */   lw       $a1, ($v0)
/* AB22AC 8024013C 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB22B0 80240140 24020002 */  addiu     $v0, $zero, 2
/* AB22B4 80240144 03E00008 */  jr        $ra
/* AB22B8 80240148 27BD0018 */   addiu    $sp, $sp, 0x18
/* AB22BC 8024014C 00000000 */  nop       
