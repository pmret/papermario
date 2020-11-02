.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_ACAB54
/* ACAB54 80240034 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ACAB58 80240038 AFBF0010 */  sw        $ra, 0x10($sp)
/* ACAB5C 8024003C 8C82000C */  lw        $v0, 0xc($a0)
/* ACAB60 80240040 0C0B210B */  jal       get_float_variable
/* ACAB64 80240044 8C450000 */   lw       $a1, ($v0)
/* ACAB68 80240048 8FBF0010 */  lw        $ra, 0x10($sp)
/* ACAB6C 8024004C 4600008D */  trunc.w.s $f2, $f0
/* ACAB70 80240050 44021000 */  mfc1      $v0, $f2
/* ACAB74 80240054 00000000 */  nop       
/* ACAB78 80240058 3C018011 */  lui       $at, %hi(gPlayerStatus+0xD)
/* ACAB7C 8024005C A022EFD5 */  sb        $v0, %lo(gPlayerStatus+0xD)($at)
/* ACAB80 80240060 24020002 */  addiu     $v0, $zero, 2
/* ACAB84 80240064 03E00008 */  jr        $ra
/* ACAB88 80240068 27BD0018 */   addiu    $sp, $sp, 0x18
/* ACAB8C 8024006C 00000000 */  nop       
