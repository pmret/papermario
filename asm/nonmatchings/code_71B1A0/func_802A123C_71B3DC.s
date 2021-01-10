.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_71B3DC
/* 71B3DC 802A123C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 71B3E0 802A1240 AFB00010 */  sw        $s0, 0x10($sp)
/* 71B3E4 802A1244 0080802D */  daddu     $s0, $a0, $zero
/* 71B3E8 802A1248 10A0000E */  beqz      $a1, .L802A1284
/* 71B3EC 802A124C AFBF0014 */   sw       $ra, 0x14($sp)
/* 71B3F0 802A1250 0C04760B */  jal       func_8011D82C
/* 71B3F4 802A1254 24040001 */   addiu    $a0, $zero, 1
/* 71B3F8 802A1258 0000202D */  daddu     $a0, $zero, $zero
/* 71B3FC 802A125C 0080282D */  daddu     $a1, $a0, $zero
/* 71B400 802A1260 0080302D */  daddu     $a2, $a0, $zero
/* 71B404 802A1264 0080382D */  daddu     $a3, $a0, $zero
/* 71B408 802A1268 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 71B40C 802A126C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 71B410 802A1270 24030001 */  addiu     $v1, $zero, 1
/* 71B414 802A1274 0C046F97 */  jal       set_background_color_blend
/* 71B418 802A1278 A0430000 */   sb       $v1, ($v0)
/* 71B41C 802A127C 24020014 */  addiu     $v0, $zero, 0x14
/* 71B420 802A1280 AE020070 */  sw        $v0, 0x70($s0)
.L802A1284:
/* 71B424 802A1284 0000202D */  daddu     $a0, $zero, $zero
/* 71B428 802A1288 0080282D */  daddu     $a1, $a0, $zero
/* 71B42C 802A128C 0080302D */  daddu     $a2, $a0, $zero
/* 71B430 802A1290 8E030070 */  lw        $v1, 0x70($s0)
/* 71B434 802A1294 24020014 */  addiu     $v0, $zero, 0x14
/* 71B438 802A1298 00431023 */  subu      $v0, $v0, $v1
/* 71B43C 802A129C 00023880 */  sll       $a3, $v0, 2
/* 71B440 802A12A0 00E23821 */  addu      $a3, $a3, $v0
/* 71B444 802A12A4 00073840 */  sll       $a3, $a3, 1
/* 71B448 802A12A8 0C046F97 */  jal       set_background_color_blend
/* 71B44C 802A12AC 30E700FE */   andi     $a3, $a3, 0xfe
/* 71B450 802A12B0 8E020070 */  lw        $v0, 0x70($s0)
/* 71B454 802A12B4 2442FFFF */  addiu     $v0, $v0, -1
/* 71B458 802A12B8 AE020070 */  sw        $v0, 0x70($s0)
/* 71B45C 802A12BC 2C420001 */  sltiu     $v0, $v0, 1
/* 71B460 802A12C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 71B464 802A12C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 71B468 802A12C8 00021040 */  sll       $v0, $v0, 1
/* 71B46C 802A12CC 03E00008 */  jr        $ra
/* 71B470 802A12D0 27BD0018 */   addiu    $sp, $sp, 0x18
