.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A83490
/* A83490 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A83494 80240004 3C04800E */  lui       $a0, %hi(D_800D9230)
/* A83498 80240008 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* A8349C 8024000C 3C058024 */  lui       $a1, %hi(D_802432F0)
/* A834A0 80240010 24A532F0 */  addiu     $a1, $a1, %lo(D_802432F0)
/* A834A4 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* A834A8 80240018 0C01953C */  jal       sprintf
/* A834AC 8024001C 00000000 */   nop      
/* A834B0 80240020 3C04800E */  lui       $a0, %hi(D_800D91E0)
/* A834B4 80240024 248491E0 */  addiu     $a0, $a0, %lo(D_800D91E0)
/* A834B8 80240028 3C058024 */  lui       $a1, %hi(D_80243300)
/* A834BC 8024002C 0C01953C */  jal       sprintf
/* A834C0 80240030 24A53300 */   addiu    $a1, $a1, %lo(D_80243300)
/* A834C4 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A834C8 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A834CC 8024003C 03E00008 */  jr        $ra
/* A834D0 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A834D4 80240044 00000000 */  nop       
/* A834D8 80240048 00000000 */  nop       
/* A834DC 8024004C 00000000 */  nop       
