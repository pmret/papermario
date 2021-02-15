.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414C8_CB0208
/* CB0208 802414C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB020C 802414CC AFB00010 */  sw        $s0, 0x10($sp)
/* CB0210 802414D0 0080802D */  daddu     $s0, $a0, $zero
/* CB0214 802414D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* CB0218 802414D8 8E020148 */  lw        $v0, 0x148($s0)
/* CB021C 802414DC 0C00EABB */  jal       get_npc_unsafe
/* CB0220 802414E0 84440008 */   lh       $a0, 8($v0)
/* CB0224 802414E4 9443008E */  lhu       $v1, 0x8e($v0)
/* CB0228 802414E8 2463FFFF */  addiu     $v1, $v1, -1
/* CB022C 802414EC A443008E */  sh        $v1, 0x8e($v0)
/* CB0230 802414F0 00031C00 */  sll       $v1, $v1, 0x10
/* CB0234 802414F4 50600001 */  beql      $v1, $zero, .L802414FC
/* CB0238 802414F8 AE000070 */   sw       $zero, 0x70($s0)
.L802414FC:
/* CB023C 802414FC 8FBF0014 */  lw        $ra, 0x14($sp)
/* CB0240 80241500 8FB00010 */  lw        $s0, 0x10($sp)
/* CB0244 80241504 03E00008 */  jr        $ra
/* CB0248 80241508 27BD0018 */   addiu    $sp, $sp, 0x18
