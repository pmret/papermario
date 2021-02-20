.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E484
/* 17CD64 8024E484 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17CD68 8024E488 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17CD6C 8024E48C 3C03800B */  lui       $v1, %hi(gCameras+0x558)
/* 17CD70 8024E490 246322D8 */  addiu     $v1, $v1, %lo(gCameras+0x558)
/* 17CD74 8024E494 1440000E */  bnez      $v0, .L8024E4D0
/* 17CD78 8024E498 00000000 */   nop
/* 17CD7C 8024E49C A464001C */  sh        $a0, 0x1c($v1)
/* 17CD80 8024E4A0 A465001E */  sh        $a1, 0x1e($v1)
/* 17CD84 8024E4A4 A4660020 */  sh        $a2, 0x20($v1)
/* 17CD88 8024E4A8 A4670022 */  sh        $a3, 0x22($v1)
/* 17CD8C 8024E4AC 8FA20010 */  lw        $v0, 0x10($sp)
/* 17CD90 8024E4B0 A4620024 */  sh        $v0, 0x24($v1)
/* 17CD94 8024E4B4 8FA20014 */  lw        $v0, 0x14($sp)
/* 17CD98 8024E4B8 00021200 */  sll       $v0, $v0, 8
/* 17CD9C 8024E4BC A4620026 */  sh        $v0, 0x26($v1)
/* 17CDA0 8024E4C0 8FA20018 */  lw        $v0, 0x18($sp)
/* 17CDA4 8024E4C4 A4620028 */  sh        $v0, 0x28($v1)
/* 17CDA8 8024E4C8 8FA2001C */  lw        $v0, 0x1c($sp)
/* 17CDAC 8024E4CC A462002A */  sh        $v0, 0x2a($v1)
.L8024E4D0:
/* 17CDB0 8024E4D0 03E00008 */  jr        $ra
/* 17CDB4 8024E4D4 00000000 */   nop
