.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BFD880
/* BFD880 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BFD884 80240004 3C0400C2 */  lui       $a0, 0xc2
/* BFD888 80240008 24840F40 */  addiu     $a0, $a0, 0xf40
/* BFD88C 8024000C 3C0500C3 */  lui       $a1, 0xc3
/* BFD890 80240010 24A5EBA0 */  addiu     $a1, $a1, -0x1460
/* BFD894 80240014 3C068020 */  lui       $a2, %hi(gBackgroundImage)
/* BFD898 80240018 24C60000 */  addiu     $a2, $a2, %lo(gBackgroundImage)
/* BFD89C 8024001C AFBF0010 */  sw        $ra, 0x10($sp)
/* BFD8A0 80240020 0C00A5CF */  jal       dma_copy
/* BFD8A4 80240024 00000000 */   nop      
/* BFD8A8 80240028 8FBF0010 */  lw        $ra, 0x10($sp)
/* BFD8AC 8024002C 24020002 */  addiu     $v0, $zero, 2
/* BFD8B0 80240030 03E00008 */  jr        $ra
/* BFD8B4 80240034 27BD0018 */   addiu    $sp, $sp, 0x18
/* BFD8B8 80240038 00000000 */  nop       
/* BFD8BC 8024003C 00000000 */  nop       
