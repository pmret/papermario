.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242270_802AF0
/* 802AF0 80242270 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 802AF4 80242274 AFBF0014 */  sw        $ra, 0x14($sp)
/* 802AF8 80242278 AFB00010 */  sw        $s0, 0x10($sp)
/* 802AFC 8024227C 0C00EABB */  jal       get_npc_unsafe
/* 802B00 80242280 8C84014C */   lw       $a0, 0x14c($a0)
/* 802B04 80242284 24040008 */  addiu     $a0, $zero, 8
/* 802B08 80242288 0040802D */  daddu     $s0, $v0, $zero
/* 802B0C 8024228C 3C028024 */  lui       $v0, %hi(func_802422DC_802B5C)
/* 802B10 80242290 244222DC */  addiu     $v0, $v0, %lo(func_802422DC_802B5C)
/* 802B14 80242294 0C00AB39 */  jal       heap_malloc
/* 802B18 80242298 AE020008 */   sw       $v0, 8($s0)
/* 802B1C 8024229C 0040182D */  daddu     $v1, $v0, $zero
/* 802B20 802422A0 AE030020 */  sw        $v1, 0x20($s0)
/* 802B24 802422A4 AC600000 */  sw        $zero, ($v1)
/* 802B28 802422A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 802B2C 802422AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 802B30 802422B0 24020001 */  addiu     $v0, $zero, 1
/* 802B34 802422B4 03E00008 */  jr        $ra
/* 802B38 802422B8 27BD0018 */   addiu    $sp, $sp, 0x18
