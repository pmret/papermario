.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContInit
/* 3AA10 8005F610 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AA14 8005F614 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3AA18 8005F618 0C00B38C */  jal       nuSiMgrInit
/* 3AA1C 8005F61C AFB00010 */   sw       $s0, 0x10($sp)
/* 3AA20 8005F620 0C018144 */  jal       nuContMgrInit
/* 3AA24 8005F624 0040802D */   daddu    $s0, $v0, $zero
/* 3AA28 8005F628 0C017DAC */  jal       nuContPakMgrInit
/* 3AA2C 8005F62C 00000000 */   nop      
/* 3AA30 8005F630 0C017F23 */  jal       nuContRmbMgrInit
/* 3AA34 8005F634 00000000 */   nop      
/* 3AA38 8005F638 320200FF */  andi      $v0, $s0, 0xff
/* 3AA3C 8005F63C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3AA40 8005F640 8FB00010 */  lw        $s0, 0x10($sp)
/* 3AA44 8005F644 03E00008 */  jr        $ra
/* 3AA48 8005F648 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3AA4C 8005F64C 00000000 */  nop       
