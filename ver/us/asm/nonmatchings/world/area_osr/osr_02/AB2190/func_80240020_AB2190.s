.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_AB2190
/* AB2190 80240020 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB2194 80240024 AFBF0010 */  sw        $ra, 0x10($sp)
/* AB2198 80240028 8C82000C */  lw        $v0, 0xc($a0)
/* AB219C 8024002C 0C0B210B */  jal       evt_get_float_variable
/* AB21A0 80240030 8C450000 */   lw       $a1, ($v0)
/* AB21A4 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB21A8 80240038 4600008D */  trunc.w.s $f2, $f0
/* AB21AC 8024003C 44021000 */  mfc1      $v0, $f2
/* AB21B0 80240040 00000000 */  nop
/* AB21B4 80240044 3C018011 */  lui       $at, %hi(gPlayerStatus+0xD)
/* AB21B8 80240048 A022EFD5 */  sb        $v0, %lo(gPlayerStatus+0xD)($at)
/* AB21BC 8024004C 24020002 */  addiu     $v0, $zero, 2
/* AB21C0 80240050 03E00008 */  jr        $ra
/* AB21C4 80240054 27BD0018 */   addiu    $sp, $sp, 0x18
/* AB21C8 80240058 00000000 */  nop
/* AB21CC 8024005C 00000000 */  nop
