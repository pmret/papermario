.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E554
/* 17CE34 8024E554 3C03800B */  lui       $v1, 0x800b
/* 17CE38 8024E558 246322D8 */  addiu     $v1, $v1, 0x22d8
/* 17CE3C 8024E55C 3C028028 */  lui       $v0, 0x8028
/* 17CE40 8024E560 80420CE0 */  lb        $v0, 0xce0($v0)
/* 17CE44 8024E564 44860000 */  mtc1      $a2, $f0
/* 17CE48 8024E568 14400004 */  bnez      $v0, .L8024E57C
/* 17CE4C 8024E56C 00000000 */   nop      
/* 17CE50 8024E570 E46C0054 */  swc1      $f12, 0x54($v1)
/* 17CE54 8024E574 E46E0058 */  swc1      $f14, 0x58($v1)
/* 17CE58 8024E578 E460005C */  swc1      $f0, 0x5c($v1)
.L8024E57C:
/* 17CE5C 8024E57C 03E00008 */  jr        $ra
/* 17CE60 8024E580 00000000 */   nop      
