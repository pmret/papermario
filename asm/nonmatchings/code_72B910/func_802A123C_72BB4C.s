.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_72BB4C
/* 72BB4C 802A123C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 72BB50 802A1240 AFB00010 */  sw        $s0, 0x10($sp)
/* 72BB54 802A1244 0080802D */  daddu     $s0, $a0, $zero
/* 72BB58 802A1248 10A0000E */  beqz      $a1, .L802A1284
/* 72BB5C 802A124C AFBF0014 */   sw       $ra, 0x14($sp)
/* 72BB60 802A1250 0C04760B */  jal       func_8011D82C
/* 72BB64 802A1254 24040001 */   addiu    $a0, $zero, 1
/* 72BB68 802A1258 0000202D */  daddu     $a0, $zero, $zero
/* 72BB6C 802A125C 0080282D */  daddu     $a1, $a0, $zero
/* 72BB70 802A1260 0080302D */  daddu     $a2, $a0, $zero
/* 72BB74 802A1264 0080382D */  daddu     $a3, $a0, $zero
/* 72BB78 802A1268 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 72BB7C 802A126C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 72BB80 802A1270 24030001 */  addiu     $v1, $zero, 1
/* 72BB84 802A1274 0C046F97 */  jal       set_background_color_blend
/* 72BB88 802A1278 A0430000 */   sb       $v1, ($v0)
/* 72BB8C 802A127C 24020014 */  addiu     $v0, $zero, 0x14
/* 72BB90 802A1280 AE020070 */  sw        $v0, 0x70($s0)
.L802A1284:
/* 72BB94 802A1284 0000202D */  daddu     $a0, $zero, $zero
/* 72BB98 802A1288 0080282D */  daddu     $a1, $a0, $zero
/* 72BB9C 802A128C 0080302D */  daddu     $a2, $a0, $zero
/* 72BBA0 802A1290 8E030070 */  lw        $v1, 0x70($s0)
/* 72BBA4 802A1294 24020014 */  addiu     $v0, $zero, 0x14
/* 72BBA8 802A1298 00431023 */  subu      $v0, $v0, $v1
/* 72BBAC 802A129C 00023880 */  sll       $a3, $v0, 2
/* 72BBB0 802A12A0 00E23821 */  addu      $a3, $a3, $v0
/* 72BBB4 802A12A4 00073840 */  sll       $a3, $a3, 1
/* 72BBB8 802A12A8 0C046F97 */  jal       set_background_color_blend
/* 72BBBC 802A12AC 30E700FE */   andi     $a3, $a3, 0xfe
/* 72BBC0 802A12B0 8E020070 */  lw        $v0, 0x70($s0)
/* 72BBC4 802A12B4 2442FFFF */  addiu     $v0, $v0, -1
/* 72BBC8 802A12B8 AE020070 */  sw        $v0, 0x70($s0)
/* 72BBCC 802A12BC 2C420001 */  sltiu     $v0, $v0, 1
/* 72BBD0 802A12C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 72BBD4 802A12C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 72BBD8 802A12C8 00021040 */  sll       $v0, $v0, 1
/* 72BBDC 802A12CC 03E00008 */  jr        $ra
/* 72BBE0 802A12D0 27BD0018 */   addiu    $sp, $sp, 0x18
