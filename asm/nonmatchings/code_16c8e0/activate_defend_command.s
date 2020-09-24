.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel activate_defend_command
/* 18F3E4 80260B04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18F3E8 80260B08 AFB00010 */  sw        $s0, 0x10($sp)
/* 18F3EC 80260B0C 3C10800E */  lui       $s0, 0x800e
/* 18F3F0 80260B10 2610C070 */  addiu     $s0, $s0, -0x3f90
/* 18F3F4 80260B14 AFBF0018 */  sw        $ra, 0x18($sp)
/* 18F3F8 80260B18 AFB10014 */  sw        $s1, 0x14($sp)
/* 18F3FC 80260B1C 8E0200D8 */  lw        $v0, 0xd8($s0)
/* 18F400 80260B20 0C098EF2 */  jal       deduct_current_move_fp
/* 18F404 80260B24 8C5101F4 */   lw       $s1, 0x1f4($v0)
/* 18F408 80260B28 3C060001 */  lui       $a2, 1
/* 18F40C 80260B2C 34C60014 */  ori       $a2, $a2, 0x14
/* 18F410 80260B30 3C030040 */  lui       $v1, 0x40
/* 18F414 80260B34 0000202D */  daddu     $a0, $zero, $zero
/* 18F418 80260B38 8E020000 */  lw        $v0, ($s0)
/* 18F41C 80260B3C 0080282D */  daddu     $a1, $a0, $zero
/* 18F420 80260B40 00431025 */  or        $v0, $v0, $v1
/* 18F424 80260B44 AE020000 */  sw        $v0, ($s0)
/* 18F428 80260B48 3C028028 */  lui       $v0, 0x8028
/* 18F42C 80260B4C 244232D4 */  addiu     $v0, $v0, 0x32d4
/* 18F430 80260B50 0C098F3F */  jal       set_animation
/* 18F434 80260B54 AE220094 */   sw       $v0, 0x94($s1)
/* 18F438 80260B58 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18F43C 80260B5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 18F440 80260B60 8FB00010 */  lw        $s0, 0x10($sp)
/* 18F444 80260B64 24020002 */  addiu     $v0, $zero, 2
/* 18F448 80260B68 03E00008 */  jr        $ra
/* 18F44C 80260B6C 27BD0020 */   addiu    $sp, $sp, 0x20
