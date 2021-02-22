.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244030
/* 164890 80244030 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 164894 80244034 AFB10014 */  sw        $s1, 0x14($sp)
/* 164898 80244038 00A0882D */  daddu     $s1, $a1, $zero
/* 16489C 8024403C AFB20018 */  sw        $s2, 0x18($sp)
/* 1648A0 80244040 00C0902D */  daddu     $s2, $a2, $zero
/* 1648A4 80244044 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1648A8 80244048 0C090BDA */  jal       func_80242F68
/* 1648AC 8024404C AFB00010 */   sw       $s0, 0x10($sp)
/* 1648B0 80244050 3C058025 */  lui       $a1, %hi(D_80249B9C)
/* 1648B4 80244054 8CA59B9C */  lw        $a1, %lo(D_80249B9C)($a1)
/* 1648B8 80244058 18A00012 */  blez      $a1, .L802440A4
/* 1648BC 8024405C 28A20100 */   slti     $v0, $a1, 0x100
/* 1648C0 80244060 50400001 */  beql      $v0, $zero, .L80244068
/* 1648C4 80244064 240500FF */   addiu    $a1, $zero, 0xff
.L80244068:
/* 1648C8 80244068 3C108025 */  lui       $s0, %hi(pause_partners_draw_movelist_flower)
/* 1648CC 8024406C 2610C0A0 */  addiu     $s0, $s0, %lo(pause_partners_draw_movelist_flower)
/* 1648D0 80244070 0C0513AC */  jal       icon_set_opacity
/* 1648D4 80244074 8E040000 */   lw       $a0, ($s0)
/* 1648D8 80244078 8E040000 */  lw        $a0, ($s0)
/* 1648DC 8024407C 3C058025 */  lui       $a1, %hi(D_80249B94)
/* 1648E0 80244080 8CA59B94 */  lw        $a1, %lo(D_80249B94)($a1)
/* 1648E4 80244084 3C068025 */  lui       $a2, %hi(D_80249B98)
/* 1648E8 80244088 8CC69B98 */  lw        $a2, %lo(D_80249B98)($a2)
/* 1648EC 8024408C 02252821 */  addu      $a1, $s1, $a1
/* 1648F0 80244090 0C051261 */  jal       set_icon_render_pos
/* 1648F4 80244094 02463021 */   addu     $a2, $s2, $a2
/* 1648F8 80244098 8E040000 */  lw        $a0, ($s0)
/* 1648FC 8024409C 0C0511F8 */  jal       draw_icon_2
/* 164900 802440A0 00000000 */   nop
.L802440A4:
/* 164904 802440A4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 164908 802440A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 16490C 802440AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 164910 802440B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 164914 802440B4 03E00008 */  jr        $ra
/* 164918 802440B8 27BD0020 */   addiu    $sp, $sp, 0x20
