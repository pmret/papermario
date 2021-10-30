.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002ACEC
/* 60EC 8002ACEC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 60F0 8002ACF0 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 60F4 8002ACF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 60F8 8002ACF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 60FC 8002ACFC 80420070 */  lb        $v0, 0x70($v0)
/* 6100 8002AD00 14400005 */  bnez      $v0, .L8002AD18
/* 6104 8002AD04 0080282D */   daddu    $a1, $a0, $zero
/* 6108 8002AD08 0C00AB0E */  jal       func_8002AC38
/* 610C 8002AD0C 00000000 */   nop
/* 6110 8002AD10 0800AB4A */  j         .L8002AD28
/* 6114 8002AD14 00000000 */   nop
.L8002AD18:
/* 6118 8002AD18 3C04803E */  lui       $a0, %hi(D_803DA800)
/* 611C 8002AD1C 2484A800 */  addiu     $a0, $a0, %lo(D_803DA800)
/* 6120 8002AD20 0C00A477 */  jal       func_800291DC
/* 6124 8002AD24 00000000 */   nop
.L8002AD28:
/* 6128 8002AD28 8FBF0010 */  lw        $ra, 0x10($sp)
/* 612C 8002AD2C 03E00008 */  jr        $ra
/* 6130 8002AD30 27BD0018 */   addiu    $sp, $sp, 0x18
