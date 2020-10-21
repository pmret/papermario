.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242400_9D9420
/* 9D9420 80242400 3C028025 */  lui       $v0, 0x8025
/* 9D9424 80242404 8C4249C8 */  lw        $v0, 0x49c8($v0)
/* 9D9428 80242408 8C42000C */  lw        $v0, 0xc($v0)
/* 9D942C 8024240C AC40001C */  sw        $zero, 0x1c($v0)
/* 9D9430 80242410 03E00008 */  jr        $ra
/* 9D9434 80242414 24020002 */   addiu    $v0, $zero, 2
