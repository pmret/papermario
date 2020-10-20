.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9357E0
/* 9357E0 80240000 44800000 */  mtc1      $zero, $f0
/* 9357E4 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9357E8 80240008 44050000 */  mfc1      $a1, $f0
/* 9357EC 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 9357F0 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9357F4 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 9357F8 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9357FC 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 935800 80240020 0C01CA54 */  jal       func_80072950
/* 935804 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 935808 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 93580C 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 935810 80240030 03E00008 */  jr        $ra
/* 935814 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 935818 80240038 00000000 */  nop       
/* 93581C 8024003C 00000000 */  nop       
