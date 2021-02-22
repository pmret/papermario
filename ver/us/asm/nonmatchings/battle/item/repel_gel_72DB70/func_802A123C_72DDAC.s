.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_72DDAC
/* 72DDAC 802A123C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 72DDB0 802A1240 0080102D */  daddu     $v0, $a0, $zero
/* 72DDB4 802A1244 AFB00010 */  sw        $s0, 0x10($sp)
/* 72DDB8 802A1248 3C10800E */  lui       $s0, %hi(gBattleStatus+0xD8)
/* 72DDBC 802A124C 8E10C148 */  lw        $s0, %lo(gBattleStatus+0xD8)($s0)
/* 72DDC0 802A1250 2405000E */  addiu     $a1, $zero, 0xe
/* 72DDC4 802A1254 AFBF0018 */  sw        $ra, 0x18($sp)
/* 72DDC8 802A1258 AFB10014 */  sw        $s1, 0x14($sp)
/* 72DDCC 802A125C 8C460084 */  lw        $a2, 0x84($v0)
/* 72DDD0 802A1260 8E1101F4 */  lw        $s1, 0x1f4($s0)
/* 72DDD4 802A1264 0C0997D0 */  jal       inflict_status
/* 72DDD8 802A1268 0200202D */   daddu    $a0, $s0, $zero
/* 72DDDC 802A126C A200021C */  sb        $zero, 0x21c($s0)
/* 72DDE0 802A1270 8E230000 */  lw        $v1, ($s1)
/* 72DDE4 802A1274 34630100 */  ori       $v1, $v1, 0x100
/* 72DDE8 802A1278 AE230000 */  sw        $v1, ($s1)
/* 72DDEC 802A127C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 72DDF0 802A1280 8FB10014 */  lw        $s1, 0x14($sp)
/* 72DDF4 802A1284 8FB00010 */  lw        $s0, 0x10($sp)
/* 72DDF8 802A1288 24020002 */  addiu     $v0, $zero, 2
/* 72DDFC 802A128C 03E00008 */  jr        $ra
