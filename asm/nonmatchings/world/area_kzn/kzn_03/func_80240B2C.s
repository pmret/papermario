.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B2C
/* C6183C 80240B2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C61840 80240B30 AFBF0010 */  sw        $ra, 0x10($sp)
/* C61844 80240B34 0C00EAD2 */  jal       get_npc_safe
/* C61848 80240B38 8C84014C */   lw       $a0, 0x14c($a0)
/* C6184C 80240B3C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* C61850 80240B40 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* C61854 80240B44 C44C0038 */  lwc1      $f12, 0x38($v0)
/* C61858 80240B48 C44E0040 */  lwc1      $f14, 0x40($v0)
/* C6185C 80240B4C 8C660028 */  lw        $a2, 0x28($v1)
/* C61860 80240B50 0C00A7B5 */  jal       dist2D
/* C61864 80240B54 8C670030 */   lw       $a3, 0x30($v1)
/* C61868 80240B58 3C014248 */  lui       $at, 0x4248
/* C6186C 80240B5C 44811000 */  mtc1      $at, $f2
/* C61870 80240B60 00000000 */  nop       
/* C61874 80240B64 4602003C */  c.lt.s    $f0, $f2
/* C61878 80240B68 00000000 */  nop       
/* C6187C 80240B6C 45010002 */  bc1t      .L80240B78
/* C61880 80240B70 24020002 */   addiu    $v0, $zero, 2
/* C61884 80240B74 0000102D */  daddu     $v0, $zero, $zero
.L80240B78:
/* C61888 80240B78 8FBF0010 */  lw        $ra, 0x10($sp)
/* C6188C 80240B7C 03E00008 */  jr        $ra
/* C61890 80240B80 27BD0018 */   addiu    $sp, $sp, 0x18
