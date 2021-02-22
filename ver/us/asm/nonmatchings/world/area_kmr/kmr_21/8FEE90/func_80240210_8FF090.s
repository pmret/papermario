.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240210_8FF090
/* 8FF090 80240210 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8FF094 80240214 3C048024 */  lui       $a0, %hi(D_802407D0_8FF650)
/* 8FF098 80240218 248407D0 */  addiu     $a0, $a0, %lo(D_802407D0_8FF650)
/* 8FF09C 8024021C 27A50010 */  addiu     $a1, $sp, 0x10
/* 8FF0A0 80240220 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8FF0A4 80240224 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8FF0A8 80240228 0C016B3A */  jal       load_asset_by_name
/* 8FF0AC 8024022C AFB00018 */   sw       $s0, 0x18($sp)
/* 8FF0B0 80240230 8FA40010 */  lw        $a0, 0x10($sp)
/* 8FF0B4 80240234 0C00AB39 */  jal       heap_malloc
/* 8FF0B8 80240238 0040882D */   daddu    $s1, $v0, $zero
/* 8FF0BC 8024023C 0220202D */  daddu     $a0, $s1, $zero
/* 8FF0C0 80240240 0040282D */  daddu     $a1, $v0, $zero
/* 8FF0C4 80240244 3C108024 */  lui       $s0, %hi(func_802407F0_87A3D0)
/* 8FF0C8 80240248 261007F0 */  addiu     $s0, $s0, %lo(func_802407F0_87A3D0)
/* 8FF0CC 8024024C 0C01BB7C */  jal       decode_yay0
/* 8FF0D0 80240250 AE050000 */   sw       $a1, ($s0)
/* 8FF0D4 80240254 0C00AB1E */  jal       general_heap_free
/* 8FF0D8 80240258 0220202D */   daddu    $a0, $s1, $zero
/* 8FF0DC 8024025C 8E030000 */  lw        $v1, ($s0)
/* 8FF0E0 80240260 8C620000 */  lw        $v0, ($v1)
/* 8FF0E4 80240264 3C058024 */  lui       $a1, %hi(func_80240010_8FEE90)
/* 8FF0E8 80240268 24A50010 */  addiu     $a1, $a1, %lo(func_80240010_8FEE90)
/* 8FF0EC 8024026C 00431021 */  addu      $v0, $v0, $v1
/* 8FF0F0 80240270 3C018024 */  lui       $at, %hi(func_802407F4_8D45B4)
/* 8FF0F4 80240274 AC2207F4 */  sw        $v0, %lo(func_802407F4_8D45B4)($at)
/* 8FF0F8 80240278 0C048C8F */  jal       bind_dynamic_entity_7
/* 8FF0FC 8024027C 0000202D */   daddu    $a0, $zero, $zero
/* 8FF100 80240280 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8FF104 80240284 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8FF108 80240288 8FB00018 */  lw        $s0, 0x18($sp)
/* 8FF10C 8024028C 24020002 */  addiu     $v0, $zero, 2
/* 8FF110 80240290 03E00008 */  jr        $ra
/* 8FF114 80240294 27BD0028 */   addiu    $sp, $sp, 0x28
