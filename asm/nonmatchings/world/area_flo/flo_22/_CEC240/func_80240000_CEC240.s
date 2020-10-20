.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CEC240
/* CEC240 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CEC244 80240004 24040001 */  addiu     $a0, $zero, 1
/* CEC248 80240008 0000282D */  daddu     $a1, $zero, $zero
/* CEC24C 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* CEC250 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* CEC254 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CEC258 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CEC25C 8024001C 0C01CA54 */  jal       func_80072950
/* CEC260 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CEC264 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CEC268 80240028 24020002 */  addiu     $v0, $zero, 2
/* CEC26C 8024002C 03E00008 */  jr        $ra
/* CEC270 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CEC274 80240034 00000000 */  nop       
/* CEC278 80240038 00000000 */  nop       
/* CEC27C 8024003C 00000000 */  nop       
