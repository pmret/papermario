.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241860
/* A3AD40 80241860 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3AD44 80241864 AFBF0010 */  sw        $ra, 0x10($sp)
/* A3AD48 80241868 8C82000C */  lw        $v0, 0xc($a0)
/* A3AD4C 8024186C 0C0B1EAF */  jal       get_variable
/* A3AD50 80241870 8C450000 */   lw       $a1, ($v0)
/* A3AD54 80241874 3C058011 */  lui       $a1, %hi(gPlayerData)
/* A3AD58 80241878 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* A3AD5C 8024187C 3C048024 */  lui       $a0, 0x8024
/* A3AD60 80241880 00822021 */  addu      $a0, $a0, $v0
/* A3AD64 80241884 908447D0 */  lbu       $a0, 0x47d0($a0)
/* A3AD68 80241888 94A3000C */  lhu       $v1, 0xc($a1)
/* A3AD6C 8024188C 00641823 */  subu      $v1, $v1, $a0
/* A3AD70 80241890 A4A3000C */  sh        $v1, 0xc($a1)
/* A3AD74 80241894 8FBF0010 */  lw        $ra, 0x10($sp)
/* A3AD78 80241898 24020002 */  addiu     $v0, $zero, 2
/* A3AD7C 8024189C 03E00008 */  jr        $ra
/* A3AD80 802418A0 27BD0018 */   addiu    $sp, $sp, 0x18
