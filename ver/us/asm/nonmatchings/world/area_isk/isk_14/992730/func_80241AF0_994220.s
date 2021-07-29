.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AF0_994220
/* 994220 80241AF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 994224 80241AF4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 994228 80241AF8 AFB10024 */  sw        $s1, 0x24($sp)
/* 99422C 80241AFC AFB00020 */  sw        $s0, 0x20($sp)
/* 994230 80241B00 8C820148 */  lw        $v0, 0x148($a0)
/* 994234 80241B04 0C00EABB */  jal       get_npc_unsafe
/* 994238 80241B08 84440008 */   lh       $a0, 8($v0)
/* 99423C 80241B0C 27A40010 */  addiu     $a0, $sp, 0x10
/* 994240 80241B10 24050035 */  addiu     $a1, $zero, 0x35
/* 994244 80241B14 3C108024 */  lui       $s0, %hi(btl_state_draw_begin_player_turn)
/* 994248 80241B18 26102AC0 */  addiu     $s0, $s0, %lo(btl_state_draw_begin_player_turn)
/* 99424C 80241B1C 00A0182D */  daddu     $v1, $a1, $zero
/* 994250 80241B20 0040882D */  daddu     $s1, $v0, $zero
/* 994254 80241B24 0000302D */  daddu     $a2, $zero, $zero
/* 994258 80241B28 AE030008 */  sw        $v1, 8($s0)
/* 99425C 80241B2C 0C0B7A76 */  jal       spr_get_npc_raster_info
/* 994260 80241B30 AE00000C */   sw       $zero, 0xc($s0)
/* 994264 80241B34 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 994268 80241B38 46800020 */  cvt.s.w   $f0, $f0
/* 99426C 80241B3C E6000038 */  swc1      $f0, 0x38($s0)
/* 994270 80241B40 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 994274 80241B44 46800020 */  cvt.s.w   $f0, $f0
/* 994278 80241B48 E600003C */  swc1      $f0, 0x3c($s0)
/* 99427C 80241B4C C6200038 */  lwc1      $f0, 0x38($s1)
/* 994280 80241B50 3C014387 */  lui       $at, 0x4387
/* 994284 80241B54 44811000 */  mtc1      $at, $f2
/* 994288 80241B58 E6000010 */  swc1      $f0, 0x10($s0)
/* 99428C 80241B5C C620003C */  lwc1      $f0, 0x3c($s1)
/* 994290 80241B60 0000202D */  daddu     $a0, $zero, $zero
/* 994294 80241B64 E6000014 */  swc1      $f0, 0x14($s0)
/* 994298 80241B68 C6240040 */  lwc1      $f4, 0x40($s1)
/* 99429C 80241B6C 3C013F36 */  lui       $at, 0x3f36
/* 9942A0 80241B70 3421DB6E */  ori       $at, $at, 0xdb6e
/* 9942A4 80241B74 44810000 */  mtc1      $at, $f0
/* 9942A8 80241B78 3C058024 */  lui       $a1, %hi(func_80241610_993D40)
/* 9942AC 80241B7C 24A51610 */  addiu     $a1, $a1, %lo(func_80241610_993D40)
/* 9942B0 80241B80 AE00001C */  sw        $zero, 0x1c($s0)
/* 9942B4 80241B84 AE000020 */  sw        $zero, 0x20($s0)
/* 9942B8 80241B88 AE000024 */  sw        $zero, 0x24($s0)
/* 9942BC 80241B8C E6020034 */  swc1      $f2, 0x34($s0)
/* 9942C0 80241B90 AE000000 */  sw        $zero, ($s0)
/* 9942C4 80241B94 E6000028 */  swc1      $f0, 0x28($s0)
/* 9942C8 80241B98 E600002C */  swc1      $f0, 0x2c($s0)
/* 9942CC 80241B9C E6000030 */  swc1      $f0, 0x30($s0)
/* 9942D0 80241BA0 0C048C8F */  jal       create_generic_entity_frontUI
/* 9942D4 80241BA4 E6040018 */   swc1     $f4, 0x18($s0)
/* 9942D8 80241BA8 AE020004 */  sw        $v0, 4($s0)
/* 9942DC 80241BAC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 9942E0 80241BB0 8FB10024 */  lw        $s1, 0x24($sp)
/* 9942E4 80241BB4 8FB00020 */  lw        $s0, 0x20($sp)
/* 9942E8 80241BB8 24020002 */  addiu     $v0, $zero, 2
/* 9942EC 80241BBC 03E00008 */  jr        $ra
/* 9942F0 80241BC0 27BD0030 */   addiu    $sp, $sp, 0x30
