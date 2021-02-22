.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CB9240
/* CB9240 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CB9244 80240044 24040001 */  addiu     $a0, $zero, 1
/* CB9248 80240048 0000282D */  daddu     $a1, $zero, $zero
/* CB924C 8024004C 00A0302D */  daddu     $a2, $a1, $zero
/* CB9250 80240050 00A0382D */  daddu     $a3, $a1, $zero
/* CB9254 80240054 AFBF0018 */  sw        $ra, 0x18($sp)
/* CB9258 80240058 AFA00010 */  sw        $zero, 0x10($sp)
/* CB925C 8024005C 0C01CA54 */  jal       func_80072950
/* CB9260 80240060 AFA00014 */   sw       $zero, 0x14($sp)
/* CB9264 80240064 8FBF0018 */  lw        $ra, 0x18($sp)
/* CB9268 80240068 24020002 */  addiu     $v0, $zero, 2
/* CB926C 8024006C 03E00008 */  jr        $ra
/* CB9270 80240070 27BD0020 */   addiu    $sp, $sp, 0x20
/* CB9274 80240074 00000000 */  nop
/* CB9278 80240078 00000000 */  nop
/* CB927C 8024007C 00000000 */  nop
