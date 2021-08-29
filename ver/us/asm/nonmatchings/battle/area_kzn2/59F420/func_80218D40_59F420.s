.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D40_59F420
/* 59F420 80218D40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 59F424 80218D44 AFB10014 */  sw        $s1, 0x14($sp)
/* 59F428 80218D48 0080882D */  daddu     $s1, $a0, $zero
/* 59F42C 80218D4C AFBF0018 */  sw        $ra, 0x18($sp)
/* 59F430 80218D50 AFB00010 */  sw        $s0, 0x10($sp)
/* 59F434 80218D54 8E30000C */  lw        $s0, 0xc($s1)
/* 59F438 80218D58 8E050000 */  lw        $a1, ($s0)
/* 59F43C 80218D5C 0C0B1EAF */  jal       get_variable
/* 59F440 80218D60 26100004 */   addiu    $s0, $s0, 4
/* 59F444 80218D64 8E050000 */  lw        $a1, ($s0)
/* 59F448 80218D68 8C50000C */  lw        $s0, 0xc($v0)
/* 59F44C 80218D6C 0C0B210B */  jal       evt_get_float_variable
/* 59F450 80218D70 0220202D */   daddu    $a0, $s1, $zero
/* 59F454 80218D74 E600002C */  swc1      $f0, 0x2c($s0)
/* 59F458 80218D78 8FBF0018 */  lw        $ra, 0x18($sp)
/* 59F45C 80218D7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 59F460 80218D80 8FB00010 */  lw        $s0, 0x10($sp)
/* 59F464 80218D84 24020002 */  addiu     $v0, $zero, 2
/* 59F468 80218D88 03E00008 */  jr        $ra
/* 59F46C 80218D8C 27BD0020 */   addiu    $sp, $sp, 0x20
