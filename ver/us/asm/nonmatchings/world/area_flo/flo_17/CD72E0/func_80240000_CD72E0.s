.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CD72E0
/* CD72E0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD72E4 80240004 24040001 */  addiu     $a0, $zero, 1
/* CD72E8 80240008 0000282D */  daddu     $a1, $zero, $zero
/* CD72EC 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* CD72F0 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* CD72F4 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD72F8 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CD72FC 8024001C 0C01CA54 */  jal       func_80072950
/* CD7300 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CD7304 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD7308 80240028 24020002 */  addiu     $v0, $zero, 2
/* CD730C 8024002C 03E00008 */  jr        $ra
/* CD7310 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CD7314 80240034 00000000 */  nop
/* CD7318 80240038 00000000 */  nop
/* CD731C 8024003C 00000000 */  nop
