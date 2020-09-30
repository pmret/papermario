.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E31EC
/* 104A6C 802E31EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 104A70 802E31F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 104A74 802E31F4 0080802D */  daddu     $s0, $a0, $zero
/* 104A78 802E31F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 104A7C 802E31FC 0C0441A9 */  jal       get_entity_type
/* 104A80 802E3200 92040004 */   lbu      $a0, 4($s0)
/* 104A84 802E3204 2442FFE8 */  addiu     $v0, $v0, -0x18
/* 104A88 802E3208 2C420003 */  sltiu     $v0, $v0, 3
/* 104A8C 802E320C 1040000D */  beqz      $v0, .L802E3244
/* 104A90 802E3210 00000000 */   nop      
/* 104A94 802E3214 3C013E6B */  lui       $at, 0x3e6b
/* 104A98 802E3218 3421851F */  ori       $at, $at, 0x851f
/* 104A9C 802E321C 44810000 */  mtc1      $at, $f0
/* 104AA0 802E3220 3C014190 */  lui       $at, 0x4190
/* 104AA4 802E3224 44811000 */  mtc1      $at, $f2
/* 104AA8 802E3228 E6000058 */  swc1      $f0, 0x58($s0)
/* 104AAC 802E322C C600004C */  lwc1      $f0, 0x4c($s0)
/* 104AB0 802E3230 3C013F85 */  lui       $at, 0x3f85
/* 104AB4 802E3234 34211EB8 */  ori       $at, $at, 0x1eb8
/* 104AB8 802E3238 44812000 */  mtc1      $at, $f4
/* 104ABC 802E323C 080B8C9C */  j         .L802E3270
/* 104AC0 802E3240 46020000 */   add.s    $f0, $f0, $f2
.L802E3244:
/* 104AC4 802E3244 3C013EEB */  lui       $at, 0x3eeb
/* 104AC8 802E3248 3421851F */  ori       $at, $at, 0x851f
/* 104ACC 802E324C 44810000 */  mtc1      $at, $f0
/* 104AD0 802E3250 3C014190 */  lui       $at, 0x4190
/* 104AD4 802E3254 44811000 */  mtc1      $at, $f2
/* 104AD8 802E3258 E6000058 */  swc1      $f0, 0x58($s0)
/* 104ADC 802E325C C600004C */  lwc1      $f0, 0x4c($s0)
/* 104AE0 802E3260 3C014005 */  lui       $at, 0x4005
/* 104AE4 802E3264 34211EB8 */  ori       $at, $at, 0x1eb8
/* 104AE8 802E3268 44812000 */  mtc1      $at, $f4
/* 104AEC 802E326C 46020000 */  add.s     $f0, $f0, $f2
.L802E3270:
/* 104AF0 802E3270 E6040054 */  swc1      $f4, 0x54($s0)
/* 104AF4 802E3274 E604005C */  swc1      $f4, 0x5c($s0)
/* 104AF8 802E3278 E600004C */  swc1      $f0, 0x4c($s0)
/* 104AFC 802E327C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 104B00 802E3280 8FB00010 */  lw        $s0, 0x10($sp)
/* 104B04 802E3284 03E00008 */  jr        $ra
/* 104B08 802E3288 27BD0018 */   addiu    $sp, $sp, 0x18
