.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AAFFF0
/* AAFFF0 80240000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AAFFF4 80240004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AAFFF8 80240008 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AAFFFC 8024000C AFBF0010 */  sw        $ra, 0x10($sp)
/* AB0000 80240010 8443008E */  lh        $v1, 0x8e($v0)
/* AB0004 80240014 24020003 */  addiu     $v0, $zero, 3
/* AB0008 80240018 14620006 */  bne       $v1, $v0, .L80240034
/* AB000C 8024001C 00000000 */   nop      
/* AB0010 80240020 3C04800E */  lui       $a0, 0x800e
/* AB0014 80240024 24849668 */  addiu     $a0, $a0, -0x6998
/* AB0018 80240028 3C058024 */  lui       $a1, 0x8024
/* AB001C 8024002C 0C01953C */  jal       sprintf
/* AB0020 80240030 24A52160 */   addiu    $a1, $a1, 0x2160
.L80240034:
/* AB0024 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB0028 80240038 0000102D */  daddu     $v0, $zero, $zero
/* AB002C 8024003C 03E00008 */  jr        $ra
/* AB0030 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* AB0034 80240044 00000000 */  nop       
/* AB0038 80240048 00000000 */  nop       
/* AB003C 8024004C 00000000 */  nop       
