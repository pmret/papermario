.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_72223C
/* 72223C 802A123C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 722240 802A1240 AFBF0018 */  sw        $ra, 0x18($sp)
/* 722244 802A1244 AFB10014 */  sw        $s1, 0x14($sp)
/* 722248 802A1248 AFB00010 */  sw        $s0, 0x10($sp)
/* 72224C 802A124C 8C82000C */  lw        $v0, 0xc($a0)
/* 722250 802A1250 0C0B1EAF */  jal       get_variable
/* 722254 802A1254 8C450000 */   lw       $a1, ($v0)
/* 722258 802A1258 0C09A75B */  jal       get_actor
/* 72225C 802A125C 0040202D */   daddu    $a0, $v0, $zero
/* 722260 802A1260 0040802D */  daddu     $s0, $v0, $zero
/* 722264 802A1264 96020192 */  lhu       $v0, 0x192($s0)
/* 722268 802A1268 82030210 */  lb        $v1, 0x210($s0)
/* 72226C 802A126C 10600005 */  beqz      $v1, .L802A1284
/* 722270 802A1270 30510700 */   andi     $s1, $v0, 0x700
/* 722274 802A1274 86040436 */  lh        $a0, 0x436($s0)
/* 722278 802A1278 A2000211 */  sb        $zero, 0x211($s0)
/* 72227C 802A127C 0C011E26 */  jal       func_80047898
/* 722280 802A1280 A2000210 */   sb       $zero, 0x210($s0)
.L802A1284:
/* 722284 802A1284 82020216 */  lb        $v0, 0x216($s0)
/* 722288 802A1288 1040000C */  beqz      $v0, .L802A12BC
/* 72228C 802A128C 00000000 */   nop
/* 722290 802A1290 A2000217 */  sb        $zero, 0x217($s0)
/* 722294 802A1294 12200006 */  beqz      $s1, .L802A12B0
/* 722298 802A1298 A2000216 */   sb       $zero, 0x216($s0)
/* 72229C 802A129C 24020100 */  addiu     $v0, $zero, 0x100
/* 7222A0 802A12A0 16220003 */  bne       $s1, $v0, .L802A12B0
/* 7222A4 802A12A4 00000000 */   nop
/* 7222A8 802A12A8 0C09F7A0 */  jal       dispatch_event_partner
/* 7222AC 802A12AC 24040031 */   addiu    $a0, $zero, 0x31
.L802A12B0:
/* 7222B0 802A12B0 8E020440 */  lw        $v0, 0x440($s0)
/* 7222B4 802A12B4 8C42000C */  lw        $v0, 0xc($v0)
/* 7222B8 802A12B8 AC40003C */  sw        $zero, 0x3c($v0)
.L802A12BC:
/* 7222BC 802A12BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7222C0 802A12C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 7222C4 802A12C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7222C8 802A12C8 24020002 */  addiu     $v0, $zero, 2
/* 7222CC 802A12CC 03E00008 */  jr        $ra
