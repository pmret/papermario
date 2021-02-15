.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BFA0A0
/* BFA0A0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BFA0A4 80240004 3C04800E */  lui       $a0, %hi(D_800D9230)
/* BFA0A8 80240008 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* BFA0AC 8024000C 3C058024 */  lui       $a1, %hi(D_802437A0_BFD840)
/* BFA0B0 80240010 24A537A0 */  addiu     $a1, $a1, %lo(D_802437A0_BFD840)
/* BFA0B4 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* BFA0B8 80240018 0C01953C */  jal       sprintf
/* BFA0BC 8024001C 00000000 */   nop
/* BFA0C0 80240020 3C04800E */  lui       $a0, %hi(D_800D91E0)
/* BFA0C4 80240024 248491E0 */  addiu     $a0, $a0, %lo(D_800D91E0)
/* BFA0C8 80240028 3C058024 */  lui       $a1, %hi(D_802437B0_BFD850)
/* BFA0CC 8024002C 0C01953C */  jal       sprintf
/* BFA0D0 80240030 24A537B0 */   addiu    $a1, $a1, %lo(D_802437B0_BFD850)
/* BFA0D4 80240034 3C04800B */  lui       $a0, %hi(D_800B0CF0)
/* BFA0D8 80240038 24840CF0 */  addiu     $a0, $a0, %lo(D_800B0CF0)
/* BFA0DC 8024003C 3C058024 */  lui       $a1, %hi(D_802437BC_BFD85C)
/* BFA0E0 80240040 0C01953C */  jal       sprintf
/* BFA0E4 80240044 24A537BC */   addiu    $a1, $a1, %lo(D_802437BC_BFD85C)
/* BFA0E8 80240048 8FBF0010 */  lw        $ra, 0x10($sp)
/* BFA0EC 8024004C 0000102D */  daddu     $v0, $zero, $zero
/* BFA0F0 80240050 03E00008 */  jr        $ra
/* BFA0F4 80240054 27BD0018 */   addiu    $sp, $sp, 0x18
/* BFA0F8 80240058 00000000 */  nop
/* BFA0FC 8024005C 00000000 */  nop
