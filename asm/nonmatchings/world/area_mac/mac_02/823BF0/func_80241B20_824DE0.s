.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B20_824DE0
/* 824DE0 80241B20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 824DE4 80241B24 AFBF0014 */  sw        $ra, 0x14($sp)
/* 824DE8 80241B28 AFB00010 */  sw        $s0, 0x10($sp)
/* 824DEC 80241B2C 0C00EABB */  jal       get_npc_unsafe
/* 824DF0 80241B30 8C84014C */   lw       $a0, 0x14c($a0)
/* 824DF4 80241B34 24040008 */  addiu     $a0, $zero, 8
/* 824DF8 80241B38 0040802D */  daddu     $s0, $v0, $zero
/* 824DFC 80241B3C 3C028024 */  lui       $v0, %hi(D_80241B8C)
/* 824E00 80241B40 24421B8C */  addiu     $v0, $v0, %lo(D_80241B8C)
/* 824E04 80241B44 0C00AB39 */  jal       heap_malloc
/* 824E08 80241B48 AE020008 */   sw       $v0, 8($s0)
/* 824E0C 80241B4C 0040182D */  daddu     $v1, $v0, $zero
/* 824E10 80241B50 AE030020 */  sw        $v1, 0x20($s0)
/* 824E14 80241B54 AC600000 */  sw        $zero, ($v1)
/* 824E18 80241B58 8FBF0014 */  lw        $ra, 0x14($sp)
/* 824E1C 80241B5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 824E20 80241B60 24020001 */  addiu     $v0, $zero, 1
/* 824E24 80241B64 03E00008 */  jr        $ra
/* 824E28 80241B68 27BD0018 */   addiu    $sp, $sp, 0x18
