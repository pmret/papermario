.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C1C_8897EC
/* 8897EC 80240C1C 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 8897F0 80240C20 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 8897F4 80240C24 8C620000 */  lw        $v0, ($v1)
/* 8897F8 80240C28 34420040 */  ori       $v0, $v0, 0x40
/* 8897FC 80240C2C AC620000 */  sw        $v0, ($v1)
/* 889800 80240C30 03E00008 */  jr        $ra
/* 889804 80240C34 24020002 */   addiu    $v0, $zero, 2
