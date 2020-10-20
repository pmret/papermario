.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A0BCF0
/* A0BCF0 80240000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A0BCF4 80240004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A0BCF8 80240008 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A0BCFC 8024000C AFBF0010 */  sw        $ra, 0x10($sp)
/* A0BD00 80240010 8443008E */  lh        $v1, 0x8e($v0)
/* A0BD04 80240014 24020003 */  addiu     $v0, $zero, 3
/* A0BD08 80240018 14620006 */  bne       $v1, $v0, .L80240034
/* A0BD0C 8024001C 00000000 */   nop      
/* A0BD10 80240020 3C04800E */  lui       $a0, 0x800e
/* A0BD14 80240024 24849668 */  addiu     $a0, $a0, -0x6998
/* A0BD18 80240028 3C058024 */  lui       $a1, 0x8024
/* A0BD1C 8024002C 0C01953C */  jal       sprintf
/* A0BD20 80240030 24A54B30 */   addiu    $a1, $a1, 0x4b30
.L80240034:
/* A0BD24 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A0BD28 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A0BD2C 8024003C 03E00008 */  jr        $ra
/* A0BD30 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A0BD34 80240044 00000000 */  nop       
/* A0BD38 80240048 00000000 */  nop       
/* A0BD3C 8024004C 00000000 */  nop       
