.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_A834E0
/* A834E0 80240050 C4800084 */  lwc1      $f0, 0x84($a0)
/* A834E4 80240054 46800020 */  cvt.s.w   $f0, $f0
/* A834E8 80240058 3C018011 */  lui       $at, %hi(gPlayerStatus+0xA8)
/* A834EC 8024005C E420F070 */  swc1      $f0, %lo(gPlayerStatus+0xA8)($at)
/* A834F0 80240060 03E00008 */  jr        $ra
/* A834F4 80240064 24020002 */   addiu    $v0, $zero, 2
/* A834F8 80240068 00000000 */  nop       
/* A834FC 8024006C 00000000 */  nop       
