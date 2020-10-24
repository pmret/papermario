.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024047C_8525EC
/* 8525EC 8024047C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8525F0 80240480 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8525F4 80240484 AC400094 */  sw        $zero, 0x94($v0)
/* 8525F8 80240488 03E00008 */  jr        $ra
/* 8525FC 8024048C 0000102D */   daddu    $v0, $zero, $zero
