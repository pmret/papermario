.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024234C_9D936C
/* 9D936C 8024234C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9370 80242350 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D9374 80242354 8C82000C */  lw        $v0, 0xc($a0)
/* 9D9378 80242358 0C0B1EAF */  jal       evt_get_variable
/* 9D937C 8024235C 8C450000 */   lw       $a1, ($v0)
/* 9D9380 80242360 3C038025 */  lui       $v1, %hi(func_802549C0)
/* 9D9384 80242364 8C6349C0 */  lw        $v1, %lo(func_802549C0)($v1)
/* 9D9388 80242368 8C63000C */  lw        $v1, 0xc($v1)
/* 9D938C 8024236C AC620034 */  sw        $v0, 0x34($v1)
/* 9D9390 80242370 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D9394 80242374 24020002 */  addiu     $v0, $zero, 2
/* 9D9398 80242378 03E00008 */  jr        $ra
/* 9D939C 8024237C 27BD0018 */   addiu    $sp, $sp, 0x18
