.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B00_CE7200
/* CE7200 80240B00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CE7204 80240B04 24040001 */  addiu     $a0, $zero, 1
/* CE7208 80240B08 0000282D */  daddu     $a1, $zero, $zero
/* CE720C 80240B0C 00A0302D */  daddu     $a2, $a1, $zero
/* CE7210 80240B10 00A0382D */  daddu     $a3, $a1, $zero
/* CE7214 80240B14 AFBF0018 */  sw        $ra, 0x18($sp)
/* CE7218 80240B18 AFA00010 */  sw        $zero, 0x10($sp)
/* CE721C 80240B1C 0C01CA54 */  jal       func_80072950
/* CE7220 80240B20 AFA00014 */   sw       $zero, 0x14($sp)
/* CE7224 80240B24 8FBF0018 */  lw        $ra, 0x18($sp)
/* CE7228 80240B28 24020002 */  addiu     $v0, $zero, 2
/* CE722C 80240B2C 03E00008 */  jr        $ra
/* CE7230 80240B30 27BD0020 */   addiu    $sp, $sp, 0x20
/* CE7234 80240B34 00000000 */  nop       
/* CE7238 80240B38 00000000 */  nop       
/* CE723C 80240B3C 00000000 */  nop       
