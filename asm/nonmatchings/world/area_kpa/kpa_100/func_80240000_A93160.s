.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A93160
/* A93160 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A93164 80240004 3C04800E */  lui       $a0, 0x800e
/* A93168 80240008 24849230 */  addiu     $a0, $a0, -0x6dd0
/* A9316C 8024000C 3C058024 */  lui       $a1, 0x8024
/* A93170 80240010 24A502B0 */  addiu     $a1, $a1, 0x2b0
/* A93174 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* A93178 80240018 0C01953C */  jal       sprintf
/* A9317C 8024001C 00000000 */   nop      
/* A93180 80240020 3C04800E */  lui       $a0, 0x800e
/* A93184 80240024 248491E0 */  addiu     $a0, $a0, -0x6e20
/* A93188 80240028 3C058024 */  lui       $a1, 0x8024
/* A9318C 8024002C 0C01953C */  jal       sprintf
/* A93190 80240030 24A502C0 */   addiu    $a1, $a1, 0x2c0
/* A93194 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A93198 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A9319C 8024003C 03E00008 */  jr        $ra
/* A931A0 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A931A4 80240044 00000000 */  nop       
/* A931A8 80240048 00000000 */  nop       
/* A931AC 8024004C 00000000 */  nop       
