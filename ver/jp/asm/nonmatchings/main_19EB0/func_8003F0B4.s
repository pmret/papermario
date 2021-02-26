.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F0B4
/* 1A4B4 8003F0B4 AC800084 */  sw        $zero, 0x84($a0)
/* 1A4B8 8003F0B8 3C028011 */  lui       $v0, %hi(D_8010F6DA)
/* 1A4BC 8003F0BC 8042F6DA */  lb        $v0, %lo(D_8010F6DA)($v0)
/* 1A4C0 8003F0C0 18400002 */  blez      $v0, .L8003F0CC
/* 1A4C4 8003F0C4 24020001 */   addiu    $v0, $zero, 1
/* 1A4C8 8003F0C8 AC820084 */  sw        $v0, 0x84($a0)
.L8003F0CC:
/* 1A4CC 8003F0CC 03E00008 */  jr        $ra
/* 1A4D0 8003F0D0 24020002 */   addiu    $v0, $zero, 2
