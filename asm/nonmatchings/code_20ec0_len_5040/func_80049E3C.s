.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80049E3C
/* 2523C 80049E3C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 25240 80049E40 AFB20018 */  sw        $s2, 0x18($sp)
/* 25244 80049E44 0080902D */  daddu     $s2, $a0, $zero
/* 25248 80049E48 AFBF001C */  sw        $ra, 0x1c($sp)
/* 2524C 80049E4C AFB10014 */  sw        $s1, 0x14($sp)
/* 25250 80049E50 AFB00010 */  sw        $s0, 0x10($sp)
/* 25254 80049E54 8E510148 */  lw        $s1, 0x148($s2)
/* 25258 80049E58 0C00EABB */  jal       get_npc_unsafe
/* 2525C 80049E5C 86240008 */   lh       $a0, 8($s1)
/* 25260 80049E60 0040802D */  daddu     $s0, $v0, $zero
/* 25264 80049E64 0200202D */  daddu     $a0, $s0, $zero
/* 25268 80049E68 240503E1 */  addiu     $a1, $zero, 0x3e1
/* 2526C 80049E6C 0C012530 */  jal       func_800494C0
/* 25270 80049E70 0000302D */   daddu    $a2, $zero, $zero
/* 25274 80049E74 8E2200CC */  lw        $v0, 0xcc($s1)
/* 25278 80049E78 3C014120 */  lui       $at, 0x4120
/* 2527C 80049E7C 44812000 */  mtc1      $at, $f4
/* 25280 80049E80 3C014020 */  lui       $at, 0x4020
/* 25284 80049E84 44810000 */  mtc1      $at, $f0
/* 25288 80049E88 C602003C */  lwc1      $f2, 0x3c($s0)
/* 2528C 80049E8C 8C430010 */  lw        $v1, 0x10($v0)
/* 25290 80049E90 8E020000 */  lw        $v0, ($s0)
/* 25294 80049E94 E604001C */  swc1      $f4, 0x1c($s0)
/* 25298 80049E98 E6000014 */  swc1      $f0, 0x14($s0)
/* 2529C 80049E9C E6020064 */  swc1      $f2, 0x64($s0)
/* 252A0 80049EA0 34420800 */  ori       $v0, $v0, 0x800
/* 252A4 80049EA4 AE020000 */  sw        $v0, ($s0)
/* 252A8 80049EA8 2402000B */  addiu     $v0, $zero, 0xb
/* 252AC 80049EAC AE030028 */  sw        $v1, 0x28($s0)
/* 252B0 80049EB0 AE420070 */  sw        $v0, 0x70($s2)
/* 252B4 80049EB4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 252B8 80049EB8 8FB20018 */  lw        $s2, 0x18($sp)
/* 252BC 80049EBC 8FB10014 */  lw        $s1, 0x14($sp)
/* 252C0 80049EC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 252C4 80049EC4 03E00008 */  jr        $ra
/* 252C8 80049EC8 27BD0020 */   addiu    $sp, $sp, 0x20
