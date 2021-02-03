.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_ADAEA0
/* ADAEA0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ADAEA4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* ADAEA8 80240008 0000202D */  daddu     $a0, $zero, $zero
/* ADAEAC 8024000C 3C05F5DE */  lui       $a1, 0xf5de
/* ADAEB0 80240010 0C0B1EAF */  jal       get_variable
/* ADAEB4 80240014 34A50180 */   ori      $a1, $a1, 0x180
/* ADAEB8 80240018 2403FF80 */  addiu     $v1, $zero, -0x80
/* ADAEBC 8024001C 14430006 */  bne       $v0, $v1, .L80240038
/* ADAEC0 80240020 00000000 */   nop
/* ADAEC4 80240024 3C04800E */  lui       $a0, %hi(D_800D9668)
/* ADAEC8 80240028 24849668 */  addiu     $a0, $a0, %lo(D_800D9668)
/* ADAECC 8024002C 3C058025 */  lui       $a1, %hi(D_8024A6B0_AE5550)
/* ADAED0 80240030 0C01953C */  jal       sprintf
/* ADAED4 80240034 24A5A6B0 */   addiu    $a1, $a1, %lo(D_8024A6B0_AE5550)
.L80240038:
/* ADAED8 80240038 8FBF0010 */  lw        $ra, 0x10($sp)
/* ADAEDC 8024003C 0000102D */  daddu     $v0, $zero, $zero
/* ADAEE0 80240040 03E00008 */  jr        $ra
/* ADAEE4 80240044 27BD0018 */   addiu    $sp, $sp, 0x18
/* ADAEE8 80240048 00000000 */  nop
/* ADAEEC 8024004C 00000000 */  nop
