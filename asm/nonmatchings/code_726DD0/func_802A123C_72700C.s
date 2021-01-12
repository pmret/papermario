.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_72700C
/* 72700C 802A123C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 727010 802A1240 AFB00010 */  sw        $s0, 0x10($sp)
/* 727014 802A1244 0080802D */  daddu     $s0, $a0, $zero
/* 727018 802A1248 10A0000E */  beqz      $a1, .L802A1284
/* 72701C 802A124C AFBF0014 */   sw       $ra, 0x14($sp)
/* 727020 802A1250 0C04760B */  jal       func_8011D82C
/* 727024 802A1254 24040001 */   addiu    $a0, $zero, 1
/* 727028 802A1258 0000202D */  daddu     $a0, $zero, $zero
/* 72702C 802A125C 0080282D */  daddu     $a1, $a0, $zero
/* 727030 802A1260 0080302D */  daddu     $a2, $a0, $zero
/* 727034 802A1264 0080382D */  daddu     $a3, $a0, $zero
/* 727038 802A1268 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 72703C 802A126C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 727040 802A1270 24030001 */  addiu     $v1, $zero, 1
/* 727044 802A1274 0C046F97 */  jal       set_background_color_blend
/* 727048 802A1278 A0430000 */   sb       $v1, ($v0)
/* 72704C 802A127C 24020014 */  addiu     $v0, $zero, 0x14
/* 727050 802A1280 AE020070 */  sw        $v0, 0x70($s0)
.L802A1284:
/* 727054 802A1284 0000202D */  daddu     $a0, $zero, $zero
/* 727058 802A1288 0080282D */  daddu     $a1, $a0, $zero
/* 72705C 802A128C 0080302D */  daddu     $a2, $a0, $zero
/* 727060 802A1290 8E030070 */  lw        $v1, 0x70($s0)
/* 727064 802A1294 24020014 */  addiu     $v0, $zero, 0x14
/* 727068 802A1298 00431023 */  subu      $v0, $v0, $v1
/* 72706C 802A129C 00023880 */  sll       $a3, $v0, 2
/* 727070 802A12A0 00E23821 */  addu      $a3, $a3, $v0
/* 727074 802A12A4 00073840 */  sll       $a3, $a3, 1
/* 727078 802A12A8 0C046F97 */  jal       set_background_color_blend
/* 72707C 802A12AC 30E700FE */   andi     $a3, $a3, 0xfe
/* 727080 802A12B0 8E020070 */  lw        $v0, 0x70($s0)
/* 727084 802A12B4 2442FFFF */  addiu     $v0, $v0, -1
/* 727088 802A12B8 AE020070 */  sw        $v0, 0x70($s0)
/* 72708C 802A12BC 2C420001 */  sltiu     $v0, $v0, 1
/* 727090 802A12C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 727094 802A12C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 727098 802A12C8 00021040 */  sll       $v0, $v0, 1
/* 72709C 802A12CC 03E00008 */  jr        $ra
/* 7270A0 802A12D0 27BD0018 */   addiu    $sp, $sp, 0x18
