.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E664
/* 17CF44 8024E664 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17CF48 8024E668 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17CF4C 8024E66C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17CF50 8024E670 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17CF54 8024E674 8C85000C */  lw        $a1, 0xc($a0)
/* 17CF58 8024E678 1440000B */  bnez      $v0, .L8024E6A8
/* 17CF5C 8024E67C 24020002 */   addiu    $v0, $zero, 2
/* 17CF60 8024E680 8CA50000 */  lw        $a1, ($a1)
/* 17CF64 8024E684 0C0B1EAF */  jal       get_variable
/* 17CF68 8024E688 00000000 */   nop
/* 17CF6C 8024E68C 0040202D */  daddu     $a0, $v0, $zero
/* 17CF70 8024E690 24020001 */  addiu     $v0, $zero, 1
/* 17CF74 8024E694 3C01802A */  lui       $at, %hi(D_8029F2A4)
/* 17CF78 8024E698 A022F2A4 */  sb        $v0, %lo(D_8029F2A4)($at)
/* 17CF7C 8024E69C 0C0933CD */  jal       btl_cam_use_preset
/* 17CF80 8024E6A0 00000000 */   nop
/* 17CF84 8024E6A4 24020002 */  addiu     $v0, $zero, 2
.L8024E6A8:
/* 17CF88 8024E6A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17CF8C 8024E6AC 03E00008 */  jr        $ra
/* 17CF90 8024E6B0 27BD0018 */   addiu    $sp, $sp, 0x18
