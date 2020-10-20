.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240030_C3AA40
/* C3AA40 80240030 3C018011 */  lui       $at, 0x8011
/* C3AA44 80240034 C422EFF4 */  lwc1      $f2, -0x100c($at)
/* C3AA48 80240038 3C01C387 */  lui       $at, 0xc387
/* C3AA4C 8024003C 44810000 */  mtc1      $at, $f0
/* C3AA50 80240040 00000000 */  nop       
/* C3AA54 80240044 4602003C */  c.lt.s    $f0, $f2
/* C3AA58 80240048 00000000 */  nop       
/* C3AA5C 8024004C 45010002 */  bc1t      .L80240058
/* C3AA60 80240050 0000102D */   daddu    $v0, $zero, $zero
/* C3AA64 80240054 24020002 */  addiu     $v0, $zero, 2
.L80240058:
/* C3AA68 80240058 03E00008 */  jr        $ra
/* C3AA6C 8024005C 00000000 */   nop      
